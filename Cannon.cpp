#include "Cannon.h"
#include <iostream>

void Cannon::useAbility(Deck* enemyBank) {
	std::cout << "hi";
}

std::string Cannon::toString() {
	return suitString.at(cannonSuit) + " value:" + std::to_string(pointVal);
}