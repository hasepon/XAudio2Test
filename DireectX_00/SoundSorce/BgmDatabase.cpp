#include "BgmDatabase.h"

#include "LoadWave.h"

CBgmDatabase::CBgmDatabase()
{
	CreateBgmVoice();
}


CBgmDatabase::~CBgmDatabase()
{
}

/////////////////////////////////////////////////////////////////
//
//	SouceVoice�̍쐬
//
void CBgmDatabase::CreateBgmVoice()
{
	// �SBGM��Load
	for (int loop = 0; loop < bgmdata::MAX_BGM; ++loop)
	{
		m_sourceWaveFormat[loop] = new CLoadWave( bgmdata::BGMName[loop] );
		m_BgmVoices[loop] = NULL;
	}

	// SouceVoice�̍쐬
	for (int loop = 0; loop < bgmdata::MAX_BGM; ++loop)
	{
		WAVEFORMATEX* waveformat = m_sourceWaveFormat[loop]->GetWaveFormat();
		GetXAudio2Mgr()->SetXAudio2SouceVoice(&m_BgmVoices[loop], *waveformat);
	}

	// �o�b�t�@�̐ݒ�
	for (int loop = 0; loop < bgmdata::MAX_BGM; ++loop)
	{
		m_BgmVoices[loop]->SubmitSourceBuffer(&m_sourceWaveFormat[loop]->PreparationBuffer());
	}

}

/////////////////////////////////////////////////////////////////
//
//	SouceVoice�̐ݒ�
//
void CBgmDatabase::Update()
{
	// �o�b�t�@�̍X�V
	for (int loop = 0; loop < bgmdata::MAX_BGM; ++loop)
	{
		XAUDIO2_BUFFER buffer = m_sourceWaveFormat[loop]->UpdateBuiffer(m_BgmVoices[loop]);
		if(buffer.pAudioData > 0)
			m_BgmVoices[loop]->SubmitSourceBuffer(&buffer);
	}
}

/////////////////////////////////////////////////////////////////
//
//	BGM�̍Đ�
//
void CBgmDatabase::Play(int BgmListNumb)
{
	HRESULT hr;

	if (FAILED(hr = m_BgmVoices[BgmListNumb]->Start() ))
	{
		
	}
}

/////////////////////////////////////////////////////////////////
//
//	BGM���ʂ̎擾
//
float CBgmDatabase::GetBgmVolume()
{
	return Volume;
}

/////////////////////////////////////////////////////////////////
//
//	BGM���ʂ̐ݒ�
//
void CBgmDatabase::SetBgmVolume(float vol)
{
	Volume = vol;

	for (int loop = 0; loop < bgmdata::MAX_BGM; ++loop)
	{
		m_BgmVoices[loop]->SetVolume(Volume);
	}
}