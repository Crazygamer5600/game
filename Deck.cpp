#include <list>
#include <cstdlib>
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
	std::vector<int> mermaidVals = { 4,5,6,7,8,9 };

	for (int x = 0; x<9; x++) {
		for (int i = 0; i < qtyOfEach; i++) {
			switch (x) {
				int val;
				case 0:
					val = normalVals[i % normalVals.size()];
					this->addToDeck(new Cannon(val));
					break;
					
				case 1:

					break;
				case 2:

					break;
				case 3:

					break;
				case 4:

					break;
				case 5:

					break;
				case 6:

					break;
				case 7:

					break;
				case 8:

					break;
			}
		}
	}


}