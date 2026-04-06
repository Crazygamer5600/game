#include "Chest.h"
#include <iostream>

void Chest::useAbility(Deck* myBank, Deck* discardPile) {
    bool hasKey = false;
    for (auto card : myBank->lastPlayed) {
        if (card->getSuit() == Card::key) {
            hasKey = true;
            break; // no need to check further
        }
    }

    if (!hasKey) {
        return;
    }

    for (size_t i = 0; i < myBank->lastPlayed.size(); ++i) {
        myBank->addToDeck(discardPile->getTopCard());
    }

}

std::string Chest::toString() {
	return suitString.at(chestSuit) + " value:" + std::to_string(pointVal);
}

Card::suit Chest::getSuit() {
	return chestSuit;
}