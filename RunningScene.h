#pragma once
#include "SceneBase.h"
#include <string>
class RunningScene : public SceneBase {
private:
	int inputHandle = -1;
	int keySoundHandle = -1;
	char inputString[256];
public:
	RunningScene();
	~RunningScene();
	void Init() override;
	void Update() override;
	void Draw() override;
};

