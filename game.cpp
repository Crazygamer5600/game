#include <iostream>
#include "game.h"

void Game::draw() {
	Player* currPlayer = &player1;
	if (!isPlayer1Turn) {
		currPlayer = &player2;
	}
	drawPile.draw(currPlayer->playArea);
	this->cardAbilityHelper(currPlayer->playArea.lastPlayed.back()->getSuit());
}

void Game::cardAbilityHelper(Card::suit suit) {
	Player* currPlayer = &player1;
	Player* enemyPlayer = &player2;
	if (!isPlayer1Turn) {
		currPlayer = &player2;
		enemyPlayer = &player1;
	}
	
	if (suit == Card::suit::cannon) {
		
	}
}

