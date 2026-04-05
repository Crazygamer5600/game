#include "Kraken.h"
#include <iostream>

void Kraken::useAbility(Deck* playArea, Deck* discardPile) {
	return;
}

std::string Kraken::toString() {
	return suitString.at(krakenSuit) + " value:" + std::to_string(pointVal);
}

Card::suit Kraken::getSuit() {
	return krakenSuit;
}