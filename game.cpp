#include <iostream>
#include "game.h"
#include "Deck.h"
#include "Card.h"
#include "Player.h"

bool Game::draw() {
	Player* currPlayer = &player1;
	if (!isPlayer1Turn) {
		currPlayer = &player2;
	}
	drawPile.draw(currPlayer->playArea);
	currPlayer->playArea.showWithinRange(1);

	if (currPlayer->playArea.isBust()) {
		return false;
	}

	std::unique_ptr<Card>card = currPlayer->playArea.getTopCard();
	this->cardAbilityHelper(card.get());
	currPlayer->playArea.addToDeck(std::move(card));

	if (currPlayer->playArea.isBust()) {
		return false;
	}

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
	case Card::chest:
		std::cout << "No immediate effect. If banked with a key, draw as many bonus cards from the Discard pile as you moved into your Bank"<<std::endl;
		break;
	case Card::key:
		std::cout << "No immediate effect. If banked with a chest, draw as many bonus cards from the Discard pile as you moved into your Bank" << std::endl;
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
		if(currPlayer->playArea.cardSet.size() >= 3) {
			std::cout << "Draw 3 cards from the discard and pick one to add to the play area"<<std::endl;
			std::cout << "(1)" << currPlayer->playArea.cardSet.at(0).get()->toString() << std::endl;
			std::cout << "(2)" << currPlayer->playArea.cardSet.at(1).get()->toString() << std::endl;
			std::cout << "(3)" << currPlayer->playArea.cardSet.at(2).get()->toString() << std::endl;
			std::cout << "What do you pick? ";
			int choice;
			std::cin>>choice;
			std::cout << "\n";

			switch (choice) {
			case 1:
				discardPile.addToDeck(currPlayer->playArea.removeCard(2));
				discardPile.addToDeck(currPlayer->playArea.removeCard(1));
				cardAbilityHelper(currPlayer->playArea.cardSet.at(0).get());
				break;
			case 2:
				discardPile.addToDeck(currPlayer->playArea.removeCard(2));
				discardPile.addToDeck(currPlayer->playArea.removeCard(0));
				cardAbilityHelper(currPlayer->playArea.cardSet.at(0).get());
				break;
			case 3:
				discardPile.addToDeck(currPlayer->playArea.removeCard(1));
				discardPile.addToDeck(currPlayer->playArea.removeCard(0));
				cardAbilityHelper(currPlayer->playArea.cardSet.at(0).get());
				break;
			}
		}
		break;
	case Card::mermaid:
		break;
	case Card::kraken:
		card->useAbility(&currPlayer->playArea, &drawPile);
		if (currPlayer->playArea.cardSet.size() >= 3) {
			for (int i = 0; i < 3; i++) {
				if (currPlayer->playArea.cardSet.at(i)->getSuit() != Card::kraken && currPlayer->playArea.cardSet.at(i)->getSuit() != Card::map) {
					cardAbilityHelper(currPlayer->playArea.cardSet.at(i).get());
				}
			}
		}
		break;
	}
}

void Game::bank() {
	Player* currPlayer = &player1;
	if (!isPlayer1Turn) {
		currPlayer = &player2;
	}

	if (currPlayer->playArea.suitSearch(Card::key) && currPlayer->playArea.suitSearch(Card::chest)) {
		chestKeyBonus(currPlayer);
	}

	currPlayer->playArea.moveEntireDeck(currPlayer->playerBank);
}

void Game::chestKeyBonus(Player* currPlayer) {
	auto card = currPlayer->playArea.getFirstOfSuit(Card::chest);
	currPlayer->playArea.moveEntireDeck(currPlayer->playerBank);
	card->useAbility(&currPlayer->playerBank, &discardPile);
}
