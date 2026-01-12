#include "TypeManager.h"

TypeManager::TypeManager() {
	//タイピングする単語は現在は固定
	typeQueue.push(TypeData("zinzya", "じんじゃ"));
	typeQueue.push(TypeData("konnnichiwa", "こんにちわ"));
	typeQueue.push(TypeData("sayonara", "さよなら"));
	typeQueue.push(TypeData("arigatou", "ありがとう"));

	currentTypeWord = typeQueue.front();
}

TypeManager::~TypeManager() {
}

void TypeManager::nextWord() {
	if (!typeQueue.empty()) {
		typeQueue.pop();
		currentTypeWord = typeQueue.front();
	}
}
