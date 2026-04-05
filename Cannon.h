#pragma once
#include "Card.h"
#include "Deck.h"

class Cannon : public Card {
public:
	using Card::Card;

	void useAbility(Deck* enemyBank, Deck* discardPile) override;

	std::string toString() override;

	Card::suit getSuit() override;

private:
	suit cannonSuit = Card::cannon;
};

