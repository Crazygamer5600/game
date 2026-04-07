#include "Chest.h"
#include <iostream>

void Chest::useAbility(Deck* myBank, Deck* discardPile) {
    bool hasKey = false;
	for (auto card : myBank->lastPlayed) {
        // code to ensure that the player has a key in their last played cards, otherwise the chest cannot be used
        if (card->getSuit() == Card::key) {
            hasKey = true;
            break;
        }
    }

    if (!hasKey) {
        return;
    }

	for (size_t i = 0; i < myBank->lastPlayed.size(); ++i) {
        // code to move the top card of the discard pile to the player's bank, this is the chest's ability
        myBank->addToDeck(discardPile->getTopCard());
    }

}

std::string Chest::toString() {
	return suitString.at(chestSuit) + " value:" + std::to_string(pointVal);
}

Card::suit Chest::getSuit() {
	return chestSuit;
}