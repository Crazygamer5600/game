class Card {
protected:
	enum suit
	{
		Kraken,
		Mermaid,
		Map,
		Oracle,
		Hook,
		Sword,
		Key,
		Chest,
		Caannon,
	};

public:
	const int pointVal;
	virtual void useAbility();
	void toString();
};