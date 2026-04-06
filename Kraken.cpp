#include "Kraken.h"
#include <iostream>

void Kraken::useAbility(Deck* playArea, Deck* discardPile) {
    for (int i = 0; i < 3; i++) {
        if (discardPile->isEmpty()) {
            std::cout << "No cards left in the discard pile.\n";
            break;
        }
        discardPile->draw(*playArea);
    }
}

std::string Kraken::toString() {
	return suitString.at(krakenSuit) + " value:" + std::to_string(pointVal);
}

Card::suit Kraken::getSuit() {
	return krakenSuit;
}