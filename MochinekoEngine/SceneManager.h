#pragma once

#include <vector>
#include "SceneBase.h"
#include <string>

class SceneManager {
private:
	static SceneManager instance;

	std::vector<SceneBase*> sceneList;
	SceneBase* currentScene = nullptr;
	SceneManager();
	~SceneManager();
public:
	void ChangeScene(const std::string& name);
	void InitScene();
	void UpdateScene();
	void DrawScene();

	static inline SceneManager& GetInstance() {
		return instance;
	}
};