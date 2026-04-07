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

	for (int x = 0; x < 9; x++) {
		// repeat for each suit
		for (int i = 0; i < qtyOfEach; i++) {
			// repeat for each card of that suit
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
					//adds 2 to the value of mermaid cards to make them more valueable than the other normal cards
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
		//loop to show the contents of the deck, used for testing
		std::cout << card->toString() << "\n";
	}
}

void Deck::showWithinRange(int range) {
	int i = 0;
	for (auto& card : this->cardSet) {
		//same as showDeckContents but only shows the first x cards, where x is the range parameter, used for testing and outputting the top cards of the deck
		if (i >= range) {
			break;
		}
		std::cout << card->toString() << "\n";
		i++;
	}
}

void Deck::shuffleDeck() {
	//uses the built in shuffle algorithm to shuffle the deck, used for shuffling the deck at the start of the game
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(this->cardSet.begin(), this->cardSet.end(), g);
}

std::unique_ptr<Card> Deck::getHighestCard() {

	if (this->cardSet.empty()) {
		//if the deck is empty, return nullptr
		return nullptr;
	}

	int highestIndex = 0;
	for (int i = 1; i < cardSet.size(); ++i) {
		if (cardSet[i]->getPointVal() > cardSet[highestIndex]->getPointVal()) {
			highestIndex = i;
		}
	}
	
	std::unique_ptr<Card> largestCard = std::move(cardSet[highestIndex]);
	cardSet.erase(cardSet.begin() + highestIndex);
	return largestCard;
	//returns the card with the highest point value in the deck
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
	// gets the literal top card of the deck, used for drawing cards and for the oracle card's ability
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
	//shows a vector of pointers to the last cards deposited into the bank.
	for (int i = 0; i < lastPlayed.size(); i++) {
		std::cout << i << ": " << lastPlayed[i]->toString() << "\n";
	}
}

int Deck::sumHighestPerSuit() {
	std::map<Card::suit, int> highest;
	// key value pairs of suit and the highest point value of that suit in the deck
	for (const auto& card : this->cardSet) {
		if (card->getPointVal() > highest[card->getSuit()])
			// if the point value of the card is higher than the current highest for that suit, update the highest for that suit
			highest[card->getSuit()] = card->getPointVal();
		//overwrite the current highest for that suit with the new highest if the new card is higher
	}
	int score = 0;
	for (const auto& pair : highest) {
		score += pair.second;
	} 
	//for each suit, add the highest point value of that suit to the score, then return the total score
	return score;
}

bool Deck::isBust() {
	for (int i = 0; i < cardSet.size(); i++) {
		for (int j = i + 1; j < cardSet.size(); j++) {
			//nested loop to compare each card in the deck to every other card in the deck, if any two cards have the same suit, return true for bust
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

Card* Deck::getFirstOfSuit(Card::suit suit) {
	//returns a pointer to the first card of the specified suit in the deck
	for (auto& card : cardSet) {
		if (card->getSuit() == suit) {
			return card.get();
		}
	}
	return nullptr;
}