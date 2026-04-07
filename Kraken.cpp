#include "Kraken.h"
#include <iostream>

void Kraken::useAbility(Deck* playArea, Deck* drawPile) {
    for (int i = 0; i < 3; i++) {
        if (drawPile->isEmpty()) {
            std::cout << "No cards left in the discard pile.\n";
            break;
        }
        drawPile->draw(*playArea);
		//adds 3 cards to the play area, if the draw pile is not empty. If the draw pile is empty, prints a message and does nothing else.
    }
}

std::string Kraken::toString() {
	return suitString.at(krakenSuit) + " value:" + std::to_string(pointVal);
}

Card::suit Kraken::getSuit() {
	return krakenSuit;
}