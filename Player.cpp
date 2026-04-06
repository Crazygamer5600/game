#include "Player.h"
#include "Deck.h"

int Player::getScore(){
    return playerBank.sumHighestPerSuit();
}