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
	char playAgain = 'y';
	
	while (playAgain == 'y') {
		Player player1("Sasha");
		Player player2("Marge");
		Deck discardPile(0);
		Deck drawPile(7);
		drawPile.shuffleDeck();
		drawPile.shuffleDeck();
		int turnNum = 0;
		Game game(std::move(discardPile), std::move(drawPile), std::move(player1), std::move(player2));

		std::cout << "Starting Dead Man's Draw++!" << std::endl;

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
			std::cout << "| score: " << currPlayer->getScore() << std::endl;

			char drawAgain = 'n';
			if (game.draw()) {
				std::cout << "Draw again? (y/n) ";
				std::cin >> drawAgain;
			}

			while (drawAgain == 'y') {
				if (!game.draw()) {
					break;
				}
				else if (game.drawPile.isEmpty()) {
					drawAgain = 'n';
					break;
				}
				std::cout << "Draw again? (y/n) ";
				std::cin >> drawAgain;
			}
			if (drawAgain == 'n') {
				//reflect a banked hand in the player's bank and clear the play area
				game.bank();
			}
			else {
				//reflect a busted hand in the player's bank and clear the play area, then move the cards in play area to the discard pile
				currPlayer->playArea.moveEntireDeck(game.discardPile);
			}

			if (game.isPlayer1Turn == true) {
				game.isPlayer1Turn = false;
			}
			else {
				game.isPlayer1Turn = true;
			}

		}
		if (game.player1.getScore() > game.player2.getScore()) {
			std::cout << game.player1.name + " wins!" << std::endl;
		}
		else if (game.player2.getScore() > game.player1.getScore()) {
			std::cout << game.player2.name + " wins!" << std::endl;
		}
		else {
			std::cout << "It's a tie!" << std::endl;
		}
		std::cout << "Play again? (y/n) ";
		std::cin >> playAgain;

	};
	return 0;
}