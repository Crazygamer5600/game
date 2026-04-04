#include "Key.h"
#include <iostream>

void Key::useAbility(Deck* emptyPtr1, Deck* emptyPtr2) {
	return;
}

std::string Key::toString() {
	return suitString.at(keySuit) + " value:" + std::to_string(pointVal);
}