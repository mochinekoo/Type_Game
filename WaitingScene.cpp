#include "WaitingScene.h"
#include <DxLib.h>
#include <assert.h>

WaitingScene::WaitingScene()
{
}

WaitingScene::~WaitingScene()
{
}

void WaitingScene::Init() {
	backgroundImageHandle = LoadGraph("background_image.png");
}

void WaitingScene::Update() {

}

void WaitingScene::Draw() {
	if (backgroundImageHandle != -1) {
		DrawGraph(0, 0, backgroundImageHandle, TRUE);
	}
}
