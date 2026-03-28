#include <iostream>
#include "game_title.h"
#include "Card.h"

int main() {
	std::cout << GAME_TITLE;
	Card newCard(Card::suit::Mermaid, 7);

	std::cout<<(newCard.toString());
};