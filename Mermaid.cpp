#include "Mermaid.h"
#include <iostream>

void Mermaid::useAbility(Deck* enemyBank) {
	std::cout << "hi";
}

std::string Mermaid::toString() {
	return suitString.at(mermaidSuit) + " value:" + std::to_string(pointVal);
}