#include "Hook.h"
#include <iostream>

void Hook::useAbility(Deck* myBank, Deck* playArea) {
	return;
}

std::string Hook::toString() {
	return suitString.at(hookSuit) + " value:" + std::to_string(pointVal);
}
