#include "Cannon.h"
#include <iostream>

void Cannon::useAbility(Deck* enemyBank, Deck* discardPile) {
	discardPile->addToDeck(enemyBank->getHighestCard());
}

std::string Cannon::toString() {
	return suitString.at(cannonSuit) + " value:" + std::to_string(pointVal);
}