#pragma once
#include "Card.h"
#include "Deck.h"

class Oracle : public Card {
public:
	using Card::Card;

	void useAbility(Deck* drawPile, Deck* blankPointer) override;

	std::string toString() override;

private:
	suit oracleSuit = Card::oracle;
};

