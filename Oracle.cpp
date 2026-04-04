#include "Oracle.h"
#include <iostream>

void Oracle::useAbility(Deck* playDeck, Deck* blankPointer) {
	playDeck->showWithinRange(1);
}

std::string Oracle::toString() {
	return suitString.at(oracleSuit) + " value:" + std::to_string(pointVal);
}