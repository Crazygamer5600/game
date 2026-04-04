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

void Deck::addToDeck(Card* cardPtr) {
	cardSet.insert(cardSet.begin() + 0, std::unique_ptr<Card>(cardPtr));
}

void Deck::makeDeck(int qtyOfEach) {
	if (qtyOfEach == 0) {
		return;
	}

	std::vector<int> normalVals = { 2,3,4,5,6,7 };
	int val;

	for (int x = 0; x<9; x++) {
		for (int i = 0; i < qtyOfEach; i++) {
			switch (x) {
				case 0:
					val = normalVals[i % normalVals.size()];
					this->addToDeck(new Cannon(val));
					break;
				case 1:
					val = normalVals[i % normalVals.size()];
					this->addToDeck(new Chest(val));
					break;
				case 2:
					val = normalVals[i % normalVals.size()];
					this->addToDeck(new Key(val));
					break;
				case 3:
					val = normalVals[i % normalVals.size()];
					this->addToDeck(new Sword(val));
					break;
				case 4:
					val = normalVals[i % normalVals.size()];
					this->addToDeck(new Hook(val));
					break;
				case 5:
					val = normalVals[i % normalVals.size()];
					this->addToDeck(new Oracle(val));
					break;
				case 6:
					val = normalVals[i % normalVals.size()];
					this->addToDeck(new Map(val));
					break;
				case 7:
					val = 2 + normalVals[i % normalVals.size()];
					this->addToDeck(new Mermaid(val));
					break;
				case 8:
					val = normalVals[i % normalVals.size()];
					this->addToDeck(new Kraken(val));
					break;
			}
		}
	}
}

void Deck::showDeckContents() {
	for (auto& card : this->cardSet) {
		std::cout << card->toString() << "\n";
	}
}

void Deck::shuffleDeck() {
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(this->cardSet.begin(), this->cardSet.end(), g);
}

Card* Deck::getHighestCard() {

	if (this->cardSet.empty()) {
		return nullptr;
	}

	Card* largestCard = this->cardSet.at(0).get();

	for (auto& card : this->cardSet) {
		if (card->getPointVal() > largestCard->getPointVal()) {
			largestCard = card.get();
		}
	}

	return largestCard;
}
