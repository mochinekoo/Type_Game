#pragma once
#include "SceneBase.h"
class WaitingScene :
    public SceneBase {
private:
    int backgroundImageHandle = -1;
public:
    WaitingScene();
    ~WaitingScene();
    void Init() override;
    void Update() override;
	void Draw() override;
};

