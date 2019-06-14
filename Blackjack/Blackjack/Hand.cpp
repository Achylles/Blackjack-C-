#include "Hand.h"



Hand::Hand()
{
	//reserves 7 hands for 7 players.
	m_Cards.reserve(7);
}


Hand::~Hand()
{
	Clear();
}

void Hand::Add(Card* playerCard)
{
	m_Cards.push_back(playerCard);
}

void Hand::Clear()

{
	//vector iteration to free all heap memory
	std::vector<Card*>::iterator iter = m_Cards.begin();
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		//deletes the value that's being pointed to and nullifies the pointer so it's not dangling
		delete *iter;
		*iter = 0;
	}
	m_Cards.clear();
}

int Hand::GetTotal() const
{
	if (m_Cards.empty()) return 0;

	if (m_Cards[0]->GetValue() == 0) return 0;

	// sum up card values, treat aces as '1'
	int sum = 0;
	std::vector<Card*>::const_iterator iter;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		sum += (*iter)->GetValue();
	}
	//check if the hand has got an Ace
	bool hasAce = false;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		if ((*iter)->GetValue == Card::ACE)
			hasAce = true;
	}
	//treating Ace as '11' because wee already have treated it as '1'

	if (hasAce && sum <= 11)
		sum += 10;
	return sum;
}
