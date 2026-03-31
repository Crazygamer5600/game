#include "Key.h"
#include <iostream>

void Key::useAbility(Deck* enemyBank) {
	std::cout << "hi";
}

std::string Key::toString() {
	return suitString.at(keySuit) + " value:" + std::to_string(pointVal);
}