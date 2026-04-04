#include "Sword.h"
#include <iostream>

void Sword::useAbility(Deck* enemyBank, Deck* playArea) {
	playArea->addToDeck(enemyBank->getHighestCard());
}

std::string Sword::toString() {
	return suitString.at(swordSuit) + " value:" + std::to_string(pointVal);
}