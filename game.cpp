#include <iostream>
#include "game_title.h"
#include "cannon.h"
#include "Deck.h"

int main() {
	std::cout << GAME_TITLE;
	Deck draw(6);
	draw.showDeckContents();
};