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
	Deck bank(0);
	Deck discardPile(2);
	Deck playArea(7);

	playArea.showDeckContents();
	std::cout << "\n";


	playArea.moveEntireDeck(bank);

	bank.showDeckContents();

	Chest chestCard(5);
	chestCard.useAbility(&bank, &discardPile);

	std::cout << "\n";

	bank.showDeckContents();

};

//todo: impliment the map, kraken and their abilities, then implement the game loop and win conditions.