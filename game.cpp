#include <iostream>
#include "game.h"
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

void Game::draw() {
	Player* currPlayer = &player1;
	if (!isPlayer1Turn) {
		currPlayer = &player2;
	}
	drawPile.draw(currPlayer->playArea);
	std::unique_ptr<Card> card = currPlayer->playArea.getTopCard();
	this->cardAbilityHelper(card.get());
	currPlayer->playArea.addToDeck(std::move(card));
}

void Game::cardAbilityHelper(Card* card) {
	Player* currPlayer = &player1;
	Player* enemyPlayer = &player2;
	if (!isPlayer1Turn) {
		currPlayer = &player2;
		enemyPlayer = &player1;
	}
	
	switch (card->getSuit()) {
	case Card::cannon:
		card->useAbility(&enemyPlayer->playerBank, &discardPile);
		break;
	
	}
	
}

