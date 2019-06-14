#include "Deck.h"



Deck::Deck()
{
	m_Cards.reserve(52);
	Populate();
}


Deck::~Deck()
{
}

void Deck::Populate()
{
	Clear();
	//create a standard deck
	for (int i = Card::DIAMONDS; i <= Card::HEARTS; ++i)
	{
		for (int j = Card::ACE; j <= Card::KING; ++j)
		{
			Add(new Card(static_cast<Card::rank>(j), static_cast<Card::suit(i)));
		}
	}
}

void Deck::Shuffle()
{
	random_shuffle(m_Cards.begin(), m_Cards.end());
}

void Deck::Deal(Hand& aHand)
{
	if (!m_Cards.empty())
	{
		aHand.Add(m_Cards.back());
		m_Cards.pop_back();
	}
	else cout << "Out of cards.\n";
}

void Deck::DealToGeneric(GenericPlayer& aGenericPlayer)
{
	cout << endl;

	while (!(aGenericPlayer.isBusted()) && aGenericPlayer.isHitting())
	{
		Deal(aGenericPlayer);
		cout << aGenericPlayer << endl;
		if (aGenericPlayer.isBusted())
			aGenericPlayer.msgBusted();
	}
}











