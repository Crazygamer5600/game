#include "Mermaid.h"
#include <iostream>

void Mermaid::useAbility(Deck* blankPointer1, Deck* blankPointer2) {
	return;
}

std::string Mermaid::toString() {
	return suitString.at(mermaidSuit) + " value:" + std::to_string(pointVal);
}