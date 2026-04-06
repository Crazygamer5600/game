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

bool Game::draw() {
	Player* currPlayer = &player1;
	if (!isPlayer1Turn) {
		currPlayer = &player2;
	}
	drawPile.draw(currPlayer->playArea);
	std::unique_ptr<Card> card = currPlayer->playArea.getTopCard();
	if (currPlayer->playArea.suitSearch(card.get()->getSuit())) {
		currPlayer->playArea.addToDeck(std::move(card));
		return false;
	}
	currPlayer->playArea.addToDeck(std::move(card));
	card = currPlayer->playArea.getTopCard();
	this->cardAbilityHelper(card.get());
	currPlayer->playArea.addToDeck(std::move(card));
	return true;
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
	//case Card::chest:
	//	card->useAbility(&currPlayer->playerBank, &discardPile);
		break;
	case Card::key:
		std::cout << "No immediate effect. If banked with a chest, draw as many bonus cards from the Discard pile as you moved into your Bank";
		break;
	case Card::sword:
		card->useAbility(&enemyPlayer->playerBank, &currPlayer->playArea);
		break;
	case Card::hook:
		card->useAbility(&currPlayer->playerBank, &currPlayer->playArea);
		break;
	case Card::oracle:
		card->useAbility(&drawPile, nullptr);
		break;
	case Card::map:
		card->useAbility(&currPlayer->playArea, &discardPile);
		break;
	case Card::mermaid:
		card->useAbility(nullptr, nullptr);
		break;
	case Card::kraken:
		card->useAbility(&currPlayer->playArea, &drawPile);
		break;

	}
	
}

