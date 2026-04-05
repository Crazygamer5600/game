#ifndef CARD_H
#define CARD_H

#include <string>
#include <map>
class Deck;

class Card {
public:
	enum suit
	{
		kraken,
		mermaid,
		map,
		oracle,
		hook,
		sword,
		key,
		chest,
		cannon,
	};

	static const std::map<suit, std::string> suitString;

	Card(int pointValue) :pointVal(pointValue) {
	};

	virtual void useAbility(Deck* targetDeck1, Deck* targetDeck2) = 0;

	virtual std::string toString();

	virtual ~Card() = default;

	int getPointVal();

	virtual Card::suit getSuit() = 0;

protected:
	const int pointVal;
};

#endif //CARD_H