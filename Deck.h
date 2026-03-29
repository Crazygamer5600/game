#include <vector>
#include "Card.h"

#pragma once
class Deck {
public:
	Deck(int numOfEach) {
		QtyPerSuit = numOfEach;
		this->makeDeck();
	}

	void makeDeck() {
		
	}

private:
	int QtyPerSuit;
	std::vector<Card*> cardSet;
};