#pragma once
#include "SceneBase.h"
class EndingScene : public SceneBase {
private:
	int timer = 0;
public:
	EndingScene();
	~EndingScene();
	void Init() override;
	void Update() override;
	void Draw() override;
};

