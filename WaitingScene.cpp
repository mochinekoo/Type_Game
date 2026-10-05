#include "WaitingScene.h"
#include <DxLib.h>
#include <assert.h>
#include "MochinekoEngine/GameUtility.h"
#include "MochinekoEngine/framework.h"
#include "MochinekoEngine/SceneManager.h"
#include "MochinekoEngine/SceneBase.h"

WaitingScene::WaitingScene()
 : SceneBase("WaitingScene") {
}

WaitingScene::~WaitingScene()
{
}

void WaitingScene::Init() {
	backgroundImageHandle = LoadGraph("background_image.png");
}

void WaitingScene::Update() {
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		SceneManager::GetInstance().ChangeScene("RunningScene");
	}
}

void WaitingScene::Draw() {
	if (backgroundImageHandle != -1) {
		DrawGraph(0, 0, backgroundImageHandle, TRUE);
	}
	GameUtility::DrawFix2DText(CENTER, Screen::WIDTH / 2, (Screen::HEIGHT / 2)-30*1, 30, "タイピングゲーム", Color::WHITE, Color::BLACK);
	GameUtility::DrawFix2DText(CENTER, Screen::WIDTH / 2, Screen::HEIGHT / 2, 30, "～スペースキーを押してください～", Color::WHITE, Color::BLACK);
}
