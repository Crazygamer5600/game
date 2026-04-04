#pragma once
#include "Card.h"
#include "Deck.h"

class Hook : public Card {
public:
	using Card::Card;

	void useAbility(Deck* myBank, Deck* playArea) override;

	std::string toString() override;

private:
	suit hookSuit = Card::hook;
};

