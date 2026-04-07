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
#include "Game.h"


int main() {
	std::cout << GAME_TITLE;
	int roundNum = 0;
	int turnNum = 0;
	bool playAgain = true;
	Player player1("Sasha");
	Player player2("Marge");
	Deck discardPile(0);
	Deck drawPile(7);
	drawPile.shuffleDeck();

	Game game(std::move(discardPile), std::move(drawPile), std::move(player1), std::move(player2));

	std::cout << "Starting Dead Man's Draw++!" << std::endl;
	while (playAgain) {
		roundNum++;
		while (!game.drawPile.isEmpty())
		{
			Player* currPlayer = &game.player1;
			if (!game.isPlayer1Turn) {
				currPlayer = &game.player2;
			}
			turnNum++;

			std::cout << "--- Round " << roundNum << ", Turn " << turnNum << "---" << std::endl;
			std::cout << currPlayer->name + "'s turn." << std::endl;
			std::cout << currPlayer->name + "'s bank:" << std::endl;
			std::cout << "| score: " << currPlayer->getScore()<<std::endl;
			game.draw();
			char drawAgain = 'y';
			std::cout << "Draw again? (y/n) ";
			std::cin >> drawAgain;
			
			while (drawAgain == 'y') {
				if (!game.draw()) {
					break;
				}
				std::cout << "Draw again? (y/n) ";
				std::cin >> drawAgain;
			}
			if (drawAgain == 'n') {
				game.bank();
			} else {
				currPlayer->playArea.moveEntireDeck(game.discardPile);
			}

			if (game.isPlayer1Turn == true) {
				game.isPlayer1Turn = false;
			}
			else {
				game.isPlayer1Turn = true;
			}
			
		}
	}
};
