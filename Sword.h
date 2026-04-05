#pragma once
#include "Card.h"
#include "Deck.h"

class Sword : public Card {
public:
	using Card::Card;

	void useAbility(Deck* enemyBank, Deck* playArea) override;

	std::string toString() override;

	Card::suit getSuit() override;

private:
	suit swordSuit = Card::sword;
};

