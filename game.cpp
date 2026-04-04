#include <iostream>
#include "game_title.h"
#include "cannon.h"
#include "Deck.h"

int main() {
	std::cout << GAME_TITLE;
	Deck draw(14);
	draw.showDeckContents();
	draw.shuffleDeck();

	std::cout << "\n";
	draw.showDeckContents();

	Deck emptyMove(0);

	Cannon testCannon(5);
	testCannon.useAbility(&draw, &emptyMove);

	std::cout << "\n";
	emptyMove.showDeckContents();
	
	std::cout << "\n";
	draw.showDeckContents();

};

//todo: impliment the chest, key,  and their abilities, then implement the game loop and win conditions.