#include "Map.h"
#include <iostream>

void Map::useAbility(Deck* playArea, Deck* discardPile) {
    for (int i = 0; i < 3; i++) {
        if (discardPile->isEmpty()) {
            std::cout << "No cards left in the discard pile.\n";
            break;
        }
        discardPile->draw(*playArea);
		//identical to kraken, but with discard pile instead of draw pile
    }
}

std::string Map::toString() {
	return suitString.at(mapSuit) + " value:" + std::to_string(pointVal);
}

Card::suit Map::getSuit() {
	return mapSuit;
}