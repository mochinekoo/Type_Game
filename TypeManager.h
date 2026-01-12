#pragma once
#include <queue>
#include <string>

struct TypeData {
	std::string typeWord;
	std::string viewWord;

	TypeData() {}

	TypeData(std::string typeWord, std::string viewWord)
		: typeWord(typeWord), viewWord(viewWord) {
	}
};

class TypeManager {
private:
	std::queue<TypeData> typeQueue;
	TypeData currentTypeWord;
public:
	TypeManager();
	~TypeManager();
	void nextWord();
	int getAmountWord() const {
		return static_cast<int>(typeQueue.size());
	}
	inline TypeData getCurrentWord() const {
		return currentTypeWord;
	}
	static inline TypeManager& GetInstance() {
		static TypeManager instance;
		return instance;
	}
};