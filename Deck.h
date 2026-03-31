#pragma once
#include <vector>
#include <memory>
#include "Card.h"


class Deck {
public:
	Deck(int numOfEach) {
		this->makeDeck(numOfEach);
	}

	void makeDeck(int qtyOfEach);

	void showDeckContents();

	void addToDeck(Card* cardPtr);

	void shuffleDeck();

private:

	std::vector<std::unique_ptr<Card>> cardSet;
};