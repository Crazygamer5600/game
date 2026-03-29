#include <vector>
#include <memory>
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

	std::vector<std::unique_ptr<Card>> cardSet;
};