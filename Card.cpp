#include <string>
#include <map>
#include "Card.h"

const std::map<Card::suit, std::string> Card::suitString = { {Card::Kraken, "Kraken"},
	{Card::Mermaid, "Mermaid"},
	{Card::Map, "Map"},
	{Card::Oracle, "Oracle"},
	{Card::Hook, "Hook"},
	{Card::Sword, "Sword"},
	{Card::Key, "key"},
	{Card::Chest, "Chest"},
	{Card::Cannon, "Cannon" } 
};

std::string Card::toString() {
	return "Suit:" + Card::suitString.at(cardSuit) + ", value:" + std::to_string(Card::pointVal);
}

void Card::useAbility() {
	this->toString();
}