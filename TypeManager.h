#pragma once
#include <queue>
#include <string>

class TypeManager {
private:
	std::queue<std::string> typeQueue;
	std::string currentTypeWord;
public:
	TypeManager();
	~TypeManager();
	void nextWord();
	int getAmountWord() const {
		return static_cast<int>(typeQueue.size());
	}
	inline std::string getCurrentWord() const {
		return currentTypeWord;
	}
	static inline TypeManager& GetInstance() {
		static TypeManager instance;
		return instance;
	}
};