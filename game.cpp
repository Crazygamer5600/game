#include <iostream>
#include "game_title.h"
#include "cannon.h"

int main() {
	std::cout << GAME_TITLE;
	Cannon cannon1(9);
	std::cout<<cannon1.toString();
};