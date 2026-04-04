#include "Map.h"
#include <iostream>

void Map::useAbility(Deck* playArea, Deck* discardPile) {
	return;
}

std::string Map::toString() {
	return suitString.at(mapSuit) + " value:" + std::to_string(pointVal);
}