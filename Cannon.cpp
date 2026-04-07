#include "Cannon.h"
#include <iostream>

void Cannon::useAbility(Deck* enemyBank, Deck* discardPile) {
	discardPile->addToDeck(enemyBank->getHighestCard());
	//send highest valu card of enemy bank to discard pile
}

std::string Cannon::toString() {
	return suitString.at(cannonSuit) + " value:" + std::to_string(pointVal);
}

Card::suit Cannon::getSuit() {
	return cannonSuit;
}