#pragma once
#include "Card.h"
#include "Deck.h"

class Chest : public Card {
public:
	using Card::Card;

	void useAbility(Deck* myBank, Deck* discardPile) override;

	std::string toString() override;

	Card::suit getSuit() override;

private:
	suit chestSuit = Card::chest;
};

