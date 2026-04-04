#pragma once
#include "Card.h"
#include "Deck.h"

class Kraken : public Card {
public:
	using Card::Card;

	void useAbility(Deck* playArea, Deck* discardPile) override;

	std::string toString() override;

private:
	suit krakenSuit = Card::kraken;
};

