#include <iostream>
#include "game_title.h"
#include "cannon.h"
#include "Deck.h"

int main() {
	std::cout << GAME_TITLE;
	Deck draw(1);
	draw.showDeckContents();
	draw.shuffleDeck();
	draw.showDeckContents();

};