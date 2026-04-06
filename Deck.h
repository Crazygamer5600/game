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

	void showWithinRange(int range);

	std::unique_ptr<Card> getHighestCard();

	std::unique_ptr<Card> getTopCard();

	void draw(Deck& depositDeck);

	void moveEntireDeck(Deck& targetDeck);

	bool suitSearch(Card::suit suitToFind);

	void showLastPlayed();

	bool isEmpty() const;

	int sumHighestPerSuit();

	bool isBust();

	std::vector<std::unique_ptr<Card>> getCardSet();

	std::vector<Card*> lastPlayed;
	std::vector<std::unique_ptr<Card>> cardSet;
};