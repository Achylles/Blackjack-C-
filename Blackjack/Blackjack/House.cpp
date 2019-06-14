#include "House.h"




House::House(const string & name) : GenericPlayer(name)
{
}

House::~House()
{
}

bool House::isHitting() const
{
	return (GetTotal() <= 16); //returns true if the score is below 16.
}

void House::FlipFirstCard()
{
	if (!(m_Cards.empty()))
		m_Cards[0]->Flip();
	else cout << "\nNo cards to flip";
}
