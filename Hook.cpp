#include "Hook.h"
#include <iostream>

void Hook::useAbility(Deck* enemyBank) {
	std::cout << "hi";
}

std::string Hook::toString() {
	return suitString.at(hookSuit) + " value:" + std::to_string(pointVal);
}
