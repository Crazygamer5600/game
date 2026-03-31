#include "Kraken.h"
#include <iostream>

void Kraken::useAbility(Deck* enemyBank) {
	std::cout << "hi";
}

std::string Kraken::toString() {
	return suitString.at(krakenSuit) + " value:" + std::to_string(pointVal);
}