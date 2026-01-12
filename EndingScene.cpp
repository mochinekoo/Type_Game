#include "EndingScene.h"
#include <DxLib.h>
#include "SceneBase.h"
#include "GameUtility.h"
#include "framework.h"
#include "TypeManager.h"
#include "SceneManager.h"

namespace {
	TypeManager& typeManager = TypeManager::GetInstance();
}

EndingScene::EndingScene() 
 : SceneBase("EndingScene") {
}

EndingScene::~EndingScene()
{
}

void EndingScene::Init()
{
}

void EndingScene::Update() {
	if (timer > 300) {
		SceneManager::GetInstance().ChangeScene("WaitingScene");
		typeManager.correctCount = 0;
		timer = 0;
		typeManager.loadWord();
	}

	timer++;
}

void EndingScene::Draw() {
	GameUtility::DrawFix2DText(CENTER, Screen::WIDTH / 2, Screen::HEIGHT / 2, 40, "ÉQÅ[ÉÄèIóπ!", Color::WHITE, Color::BLACK);

	GameUtility::DrawFix2DText(CENTER, Screen::WIDTH / 2, (Screen::HEIGHT / 2) + 60, 30,
		"ê≥âêî: " + std::to_string(typeManager.getCorrectCount()) + "åÍ", Color::WHITE, Color::BLACK);
}
