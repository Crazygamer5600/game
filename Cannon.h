#pragma once
#include "Card.h"
#include "Deck.h"

class Cannon : public Card {
public:
	using Card::Card;

	void useAbility(Deck* enemyBank) override;

	std::string toString() override;

private:
	suit cannonSuit = Card::cannon;
};

