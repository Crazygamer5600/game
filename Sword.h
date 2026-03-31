#pragma once
#include "Card.h"
#include "Deck.h"

class Sword : public Card {
public:
	using Card::Card;

	void useAbility(Deck* enemyBank) override;

	std::string toString() override;

private:
	suit swordSuit = Card::sword;
};

