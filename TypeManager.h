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
	int correctCount = 0;
	TypeManager();
	~TypeManager();
	void nextWord();
	void loadWord();
	int getAmountWord() const {
		return static_cast<int>(typeQueue.size());
	}
	inline TypeData getCurrentWord() const {
		return currentTypeWord;
	}
	inline int getCorrectCount() const {
		return correctCount;
	}
	static inline TypeManager& GetInstance() {
		static TypeManager instance;
		return instance;
	}
};