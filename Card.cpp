#include <string>
#include "Card.h"

std::string Card::toString() {
	return suitString[cardSuit];
}

