#pragma once
#include <string>
#include "Deck.h"

class Player {
public:
	Player(const std::string playerName) : name(playerName), playerBank(0), playArea(0) {}

	Deck playerBank;
	Deck playArea;

	std::string name;

};