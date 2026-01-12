#include "RunningScene.h"
#include "SceneBase.h"
#include <DxLib.h>
#include "GameUtility.h"
#include "framework.h"
#include "TypeManager.h"
#include "SceneManager.h"

namespace {
	TypeManager& typeManager = TypeManager::GetInstance();
}

RunningScene::RunningScene()
 : SceneBase("RunningScene"), inputString("") {
}

RunningScene::~RunningScene()
{
}

void RunningScene::Init() {
	inputHandle = MakeKeyInput(255, FALSE, FALSE, FALSE);
	keySoundHandle = LoadSoundMem("キーボード1.mp3");
	SetActiveKeyInput(inputHandle);
	if (inputHandle == -1) {
		MessageBox(NULL, "キー入力ハンドルの作成に失敗しました。", NULL, MB_OK | MB_ICONERROR);
	}
}

void RunningScene::Update() {
	static int before = GetNowCount();
	int after = GetNowCount();
	float delta = (after - before) / 1000.0f;
	before = after;
	timer -= delta;

	GetKeyInputString(inputString, inputHandle);
	if (typeManager.getAmountWord() <= 0) {
		SceneManager::GetInstance().ChangeScene("EndingScene");
	}

	if ((std::string(inputString)._Equal(typeManager.getCurrentWord().typeWord) && typeManager.getAmountWord() > 0) || timer <= 0) {
		typeManager.nextWord();
		timer = 100.0;
		typeManager.correctCount++;
		SetKeyInputString("", inputHandle);
	}

	static int beforeKeyAll = 0;
	if (CheckHitKeyAll() && keySoundHandle != -1 && beforeKeyAll == 0) {
		PlaySoundMem(keySoundHandle, DX_PLAYTYPE_BACK);
	}
	beforeKeyAll = CheckHitKeyAll();
}

void RunningScene::Draw() {
	GameUtility::DrawFix2DText(LEFT, 10, 10, 20, "残り時間: " + std::to_string(timer) + "秒", Color::WHITE, Color::BLACK);

	GameUtility::DrawFix2DText(CENTER, Screen::WIDTH / 2, Screen::HEIGHT / 2 - 50, 30, typeManager.getCurrentWord().viewWord, Color::WHITE, Color::BLACK);
	GameUtility::DrawFix2DText(CENTER, Screen::WIDTH / 2, Screen::HEIGHT / 2, 30, "(" + typeManager.getCurrentWord().typeWord + ")", Color::WHITE, Color::BLACK);
	GameUtility::DrawFix2DText(CENTER, Screen::WIDTH / 2, (Screen::HEIGHT / 2) + 50, 30, inputString, Color::WHITE, Color::BLACK);
}
