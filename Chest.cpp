#include "Chest.h"
#include <iostream>

void Chest::useAbility(Deck* myBank, Deck* discardPile) {
	std::cout << "hi";
}

std::string Chest::toString() {
	return suitString.at(chestSuit) + " value:" + std::to_string(pointVal);
}