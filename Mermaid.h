#pragma once
#include "Card.h"
#include "Deck.h"

class Mermaid : public Card {
public:
	using Card::Card;

	void useAbility(Deck* blankPointer1, Deck* blankPointer2) override;

	std::string toString() override;

private:
	suit mermaidSuit = Card::mermaid;
};

