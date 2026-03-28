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

	int pointVal;
	suit cardSuit;

	Card(suit suitVal, int pointValue) {
		pointVal = pointValue;
		cardSuit = suitVal;
	};
	
	virtual void useAbility();
	
	std::string toString();
};

#endif //CARD_H