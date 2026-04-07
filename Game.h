#include "Deck.h"
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
	void bank();
	void chestKeyBonus(Player* currPlayer);
};