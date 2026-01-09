#include "SceneManager.h"
#include "WaitingScene.h"
#include <Windows.h>
#include "RunningScene.h"

SceneManager SceneManager::instance;

SceneManager::SceneManager() {
	currentScene = new WaitingScene();
	sceneList.push_back(currentScene);
	sceneList.push_back(new RunningScene());
}

SceneManager::~SceneManager() {
	for (auto scene : sceneList) {
		delete scene;
	}
}

void SceneManager::ChangeScene(const std::string& name) {
	bool result = false;
	for (auto scene : sceneList) {
		if (scene->GetName()._Equal(name)) {
			currentScene = scene;
			currentScene->Init();
			result = true;
			break;
		}
	}

	if (!result) {
		MessageBox(NULL, "シーンの切り替えに失敗しました。指定された名前のシーンが存在しません。", NULL, MB_OK | MB_ICONERROR);
	}
}

void SceneManager::InitScene() {
	if (currentScene != nullptr) {
		currentScene->Init();
	}
}

void SceneManager::UpdateScene() {
	if (currentScene != nullptr) {
		currentScene->Update();
	}
}

void SceneManager::DrawScene() {
	if (currentScene != nullptr) {
		currentScene->Draw();
	}
}