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
#include "Player.h"

class Game {
public:
	Game(Deck discPile, Deck drwPile, Player p1, Player p2)
		: discardPile(std::move(discPile)), drawPile(std::move(drwPile)), player1(std::move(p1)), player2(std::move(p2)) {
	}

	Deck discardPile;
	Deck drawPile;
	Player player1;
	Player player2;

	bool isPlayer1Turn = true;

	bool draw();
	void cardAbilityHelper(Card* card);
};