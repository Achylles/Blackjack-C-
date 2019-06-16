#include "Card.h"

class Hand
{
public:
	Hand();
	virtual ~Hand();

	//add a card to the hand

	void Add(Card* pCard);
	
	//clears the hand of all cards
	void Clear();

	//gets the value of a hand, treating Ace as 1 or 11.
	int GetTotal() const;
protected:
	std::vector<Card*> m_Cards;
};

