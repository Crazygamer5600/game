#include "Map.h"
#include <iostream>

void Map::useAbility(Deck* enemyBank) {
	std::cout << "hi";
}

std::string Map::toString() {
	return suitString.at(mapSuit) + " value:" + std::to_string(pointVal);
}