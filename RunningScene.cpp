#include "RunningScene.h"
#include "SceneBase.h"
#include <DxLib.h>
#include "GameUtility.h"
#include "framework.h"

RunningScene::RunningScene()
 : SceneBase("RunningScene"), inputString("") {
}

RunningScene::~RunningScene()
{
}

void RunningScene::Init() {
	inputHandle = MakeKeyInput(255, FALSE, FALSE, FALSE);
	SetActiveKeyInput(inputHandle);
	if (inputHandle == -1) {
		MessageBox(NULL, "キー入力ハンドルの作成に失敗しました。", NULL, MB_OK | MB_ICONERROR);
	}
}

void RunningScene::Update() {

}

void RunningScene::Draw() {
	GetKeyInputString(inputString, inputHandle);
	GameUtility::DrawFix2DText(CENTER, Screen::WIDTH / 2, Screen::HEIGHT / 2, 30, "タイピング中...", Color::WHITE, Color::BLACK);
	GameUtility::DrawFix2DText(CENTER, Screen::WIDTH / 2, (Screen::HEIGHT / 2) + 50, 30, inputString, Color::WHITE, Color::BLACK);
}
