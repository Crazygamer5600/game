#include "Oracle.h"
#include <iostream>

void Oracle::useAbility(Deck* enemyBank) {
	std::cout << "hi";
}

std::string Oracle::toString() {
	return suitString.at(oracleSuit) + " value:" + std::to_string(pointVal);
}