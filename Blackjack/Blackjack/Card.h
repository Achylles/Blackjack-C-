#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
class Card
{
public:
	enum rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
	enum suit {DIAMONDS,CLUBS,SPADES,HEARTS};
	//overloading << so we can send a Card object to the standard output

	friend ostream& operator<<(ostream& os, const Card& card);
	Card(rank r = ACE, suit s = SPADES, bool ifu = true);
	int GetValue() const;
	void Flip();

protected:
	bool m_IsFaceUp;
private:
	rank m_Rank;
	suit m_Suit;
};

