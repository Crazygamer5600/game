#include <iostream>
#include "game_title.h"
#include "Deck.h"
#include "Cannon.h"
#include "Card.h"
#include "Chest.h"
#include "Hook.h"
#include "Key.h"
#include "Kraken.h"
#include "Map.h"
#include "Mermaid.h"
#include "Oracle.h"
#include "Sword.h"


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
	
	std::cout << "\n";

	Oracle testOracle(6);
	testOracle.useAbility(&draw, nullptr);

};

//todo: impliment the chest, map, kraken and their abilities, then implement the game loop and win conditions.