#include "Title.h"
#include"Input.h"
#include"GameMain.h"
#include"Camera.h"
#include"Title.h"
#include"TitleUI.h"
#include"Camera.h"

CTitle::CTitle() 
{
	CObjManager::Instance()->MonSter();

	CObjManager::Instance()->PushObj(new CTitleUI, ID_OTHER);

	CObjManager::Instance()->PushObj(new CCamera, ID_CAMERA);
}


CTitle::~CTitle() 
{

}

void CTitle::Init() {


	

}

void CTitle::Update() {


	CObjManager::Instance()->Update();

	if (CInput::GetKeyPress(DIK_SPACE))
	{
		CSceneMgr::Instance()->ChangeScene(new CGameMain);
	}


}

void CTitle::LateUpdate() {
	CObjManager::Instance()->LateUpdate();
}

void CTitle::Draw() {
	CObjManager::Instance()->Draw();
}

void CTitle::LateDraw() {
	CObjManager::Instance()->LateDraw();
}

void CTitle::UIDraw()
{
	CFPS::Instance()->Draw();
	CObjManager::Instance()->UIDraw();
}

void CTitle::Release() {
	CObjManager::Instance()->AllRelaseObj();
}

void CTitle::Pause() {
	// タイトルでポーズはないよ
}
