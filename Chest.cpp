#include "Chest.h"
#include <iostream>

void Chest::useAbility(Deck* myBank, Deck* discardPile) {
    if (!myBank->suitSearch(Card::key))
        return;

    // number of cards currently in bank
    int bonus = myBank->size();

    for (int i = 0; i < bonus; i++) {
        discardPile->draw(*myBank);
    }
}

std::string Chest::toString() {
	return suitString.at(chestSuit) + " value:" + std::to_string(pointVal);
}

Card::suit Chest::getSuit() {
	return chestSuit;
}