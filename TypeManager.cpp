#include "TypeManager.h"

TypeManager::TypeManager() {
	//タイピングする単語は現在は固定
	typeQueue.push("zinzya");
	typeQueue.push("konnichiwa");
	typeQueue.push("sayonara");
	typeQueue.push("arigatou");

	currentTypeWord = typeQueue.front();
}

TypeManager::~TypeManager() {
}

void TypeManager::nextWord() {
	if (!typeQueue.empty()) {
		currentTypeWord = typeQueue.front();
		typeQueue.pop();
	}
}
