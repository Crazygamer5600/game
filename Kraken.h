#pragma once
#include "Card.h"
#include "Deck.h"

class Kraken : public Card {
public:
	using Card::Card;

	void useAbility(Deck* enemyBank) override;

	std::string toString() override;

private:
	suit krakenSuit = Card::kraken;
};

