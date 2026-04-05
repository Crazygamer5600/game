#pragma once
#include "Card.h"
#include "Deck.h"

class Map : public Card {
public:
	using Card::Card;

	void useAbility(Deck* playArea, Deck* discardPile) override;

	std::string toString() override;

	Card::suit getSuit() override;

private:
	suit mapSuit = Card::map;
};

