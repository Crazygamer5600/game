#include <list>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <random>
#include <vector>
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

using namespace std;

void Deck::addToDeck(std::unique_ptr<Card> cardPtr) {
	if (!cardPtr) {
		return;
	} 
	cardSet.insert(cardSet.begin(), std::move(cardPtr));
}

void Deck::makeDeck(int qtyOfEach) {
	if (qtyOfEach == 0) {
		return;
	}

	std::vector<int> normalVals = { 2,3,4,5,6,7 };
	int val;
	std::unique_ptr<Card> card;

	for (int x = 0; x<9; x++) {
		for (int i = 0; i < qtyOfEach; i++) {
			switch (x) {
				case 0:
					val = normalVals[i % normalVals.size()];
					card = std::make_unique<Cannon>(val);
					break;
				case 1:
					val = normalVals[i % normalVals.size()];
					card = std::make_unique<Chest>(val);
					break;
				case 2:
					val = normalVals[i % normalVals.size()];
					card = std::make_unique<Key>(val);
					break;
				case 3:
					val = normalVals[i % normalVals.size()];
					card = std::make_unique<Sword>(val);
					break;
				case 4:
					val = normalVals[i % normalVals.size()];
					card = std::make_unique<Hook>(val);
					break;
				case 5:
					val = normalVals[i % normalVals.size()];
					card = std::make_unique<Oracle>(val);
					break;
				case 6:
					val = normalVals[i % normalVals.size()];
					card = std::make_unique<Map>(val);
					break;
				case 7:
					val = 2 + normalVals[i % normalVals.size()];
					card = std::make_unique<Mermaid>(val);
					break;
				case 8:
					val = normalVals[i % normalVals.size()];
					card = std::make_unique<Kraken>(val);
					break;
			}
			this->addToDeck(std::move(card));
		}
	}
}

void Deck::showDeckContents() {
	for (auto& card : this->cardSet) {
		std::cout << card->toString() << "\n";
	}
}

void Deck::showWithinRange(int range) {
	int i = 0;
	for (auto& card : this->cardSet) {
		if (i >= range) {
			break;
		}
		std::cout << card->toString() << "\n";
		i++;
	}
}

void Deck::shuffleDeck() {
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(this->cardSet.begin(), this->cardSet.end(), g);
}

std::unique_ptr<Card> Deck::getHighestCard() {

	if (this->cardSet.empty()) {
		return nullptr;
	}

	size_t highestIndex = 0;
	for (size_t i = 1; i < cardSet.size(); ++i) {
		if (cardSet[i]->getPointVal() > cardSet[highestIndex]->getPointVal()) {
			highestIndex = i;
		}
	}
	
	std::unique_ptr<Card> largestCard = std::move(cardSet[highestIndex]);
	cardSet.erase(cardSet.begin() + highestIndex);
	return largestCard;
}

void Deck::draw(Deck& depositDeck) {
	if (this->cardSet.empty()) {
		return;
	} 

	depositDeck.lastPlayed.clear();
	depositDeck.lastPlayed.push_back(this->cardSet.front().get());

	depositDeck.addToDeck(std::move(this->cardSet.front()));
	this->cardSet.erase(this->cardSet.begin());
}

void Deck::moveEntireDeck(Deck& targetDeck) {
	targetDeck.lastPlayed.clear();

	for (auto& card : this->cardSet) {
		targetDeck.lastPlayed.push_back(card.get());
		targetDeck.addToDeck(std::move(card));
	}

	this->cardSet.clear();
}

bool Deck::suitSearch(Card::suit suitToFind) {
	for (const auto& card : cardSet) {
		if (card->getSuit() == suitToFind) {
			return true;
		}
	}
	return false;
}

std::unique_ptr<Card> Deck::getTopCard() {
	if (cardSet.empty()) {
		return nullptr;
	}

	std::unique_ptr<Card> topCard = std::move(cardSet.front());
	cardSet.erase(cardSet.begin());
	return topCard;
}

bool Deck::isEmpty() const {
	return cardSet.empty();
}

void Deck::showLastPlayed() {
	for (int i = 0; i < lastPlayed.size(); i++) {
		std::cout << i << ": " << lastPlayed[i]->toString() << "\n";
	}
}

int Deck::sumHighestPerSuit() {
	std::map<Card::suit, int> highest;
	for (const auto& card : this->cardSet) {
		if (card->getPointVal() > highest[card->getSuit()])
			highest[card->getSuit()] = card->getPointVal();
	}
	int score = 0;
	for (const auto& pair : highest) score += pair.second;
	return score;
}

bool Deck::isBust() {
	for (int i = 0; i < cardSet.size(); i++) {
		for (int j = i + 1; j < cardSet.size(); j++) {
			if (cardSet[i]->getSuit() == cardSet[j]->getSuit()) {
				return true;
			}
		}
	}
	return false;
}

std::unique_ptr<Card> Deck::removeCard(int index) {
	std::unique_ptr<Card> card = std::move(cardSet.at(index));
	cardSet.erase(cardSet.begin() + index);
	return card;
}