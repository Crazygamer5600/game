#ifndef CARD_H
#define CARD_H

#include <string>
#include <map>

class Card {
public:
	enum suit
	{
		Kraken,
		Mermaid,
		Map,
		Oracle,
		Hook,
		Sword,
		Key,
		Chest,
		Cannon,
	};

	static const std::map<suit, std::string> suitString;

	Card(suit suitVal, int pointValue) :pointVal(pointValue), cardSuit(suitVal) {
	};

	virtual void useAbility() = 0;

	std::string toString();

	virtual ~Card() = default;

private:
	const int pointVal;
	const suit cardSuit;
};

#endif //CARD_H