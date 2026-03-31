#include <string>
#include <map>
#include "Card.h"
#include "Deck.h"

const std::map<Card::suit, std::string> Card::suitString = { {Card::kraken, "Kraken"},
	{Card::mermaid, "Mermaid"},
	{Card::map, "Map"},
	{Card::oracle, "Oracle"},
	{Card::hook, "Hook"},
	{Card::sword, "Sword"},
	{Card::key, "key"},
	{Card::chest, "Chest"},
	{Card::cannon, "Cannon" } 
};

std::string Card::toString() {
	return "value:" + std::to_string(Card::pointVal);
}

void Card::useAbility(Deck* targetDeck) {
	this->toString();
}

int Card::getPointVal(){
	return Card::pointVal;
}