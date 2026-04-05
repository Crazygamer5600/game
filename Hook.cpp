#include "Hook.h"
#include <iostream>

void Hook::useAbility(Deck* myBank, Deck* playArea) {
	playArea->addToDeck(myBank->getHighestCard());
}

std::string Hook::toString() {
	return suitString.at(hookSuit) + " value:" + std::to_string(pointVal);
}

Card::suit Hook::getSuit() {
	return hookSuit;
}