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

	void addToDeck(std::unique_ptr<Card> cardPtr);

	void shuffleDeck();

	std::unique_ptr<Card> getHighestCard();

private:

	std::vector<std::unique_ptr<Card>> cardSet;
};