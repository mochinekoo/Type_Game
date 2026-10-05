#include "GameUtility.h"
#include <DxLib.h>

namespace KeyInput {
    const int KEYCOUNT = 256;
    char beforeKeyBuf[KEYCOUNT] = {};
    char afterKeyBuf[KEYCOUNT] = {};

    char fixDownKeyBuf[KEYCOUNT] = {};
    char fixUpKeyBuf[KEYCOUNT] = {};
}

void GameUtility::DrawFix2DText(DrawType type, int x, int y, int size, string text, unsigned int textColor, unsigned int edgeColor) {
    SetFontSize(size);
    int strWidth = GetDrawStringWidth(text.c_str(), strlen(text.c_str()));

    switch (type)
    {
    case LEFT:
        break;
    case CENTER:
        x -= strWidth / 2;
        y -= size / 2;
        break;
    case RIGHT:
        x -= strWidth;
        break;
    }

    DrawString(x, y, text.c_str(), textColor, edgeColor);
}

void GameUtility::UpdateKey() {
    memcpy_s(KeyInput::beforeKeyBuf, sizeof(char) * KeyInput::KEYCOUNT, KeyInput::afterKeyBuf, sizeof(char) * KeyInput::KEYCOUNT); //after（後フレーム）から before（前フレーム）にコピー
    GetHitKeyStateAll(KeyInput::afterKeyBuf); //後フレームに代入

    for (int n = 0; n < KeyInput::KEYCOUNT; n++) {
        int key_xor = KeyInput::beforeKeyBuf[n] ^ KeyInput::afterKeyBuf[n]; //前と後が0と1なら、1を返す（XOR）
        KeyInput::fixDownKeyBuf[n] = key_xor & KeyInput::afterKeyBuf[n]; //押された瞬間 = (XORと後フレームのANDを取る) 
		KeyInput::fixUpKeyBuf[n] = key_xor & KeyInput::beforeKeyBuf[n]; //離された瞬間 = (XORと前フレームのANDを取る)
    }
}

bool GameUtility::IsKeyDown(int keyCode) {
    return KeyInput::fixDownKeyBuf[keyCode];
}

bool GameUtility::IsKeyUp(int keyCode) {
	return KeyInput::fixUpKeyBuf[keyCode];
}
