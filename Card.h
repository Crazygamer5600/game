#ifndef CARD_H
#define CARD_H

#include <string>
#include <map>

class Card {
protected:
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

	suit cardSuit;

	std::map<suit, std::string> suitString = { {Kraken, "Kraken"}, 
		{Mermaid, "Mermaid"}, 
		{Map, "Map"}, 
		{Oracle, "Oracle"},
		{Hook, "Hook"}, 
		{Sword, "Sword"}, 
		{Key, "key"}, 
		{Chest, "Chest"}, 
		{Cannon, "Cannon" } };

public:
	const int pointVal;
	virtual void useAbility();
	std::string toString();
};

#endif //CARD_H