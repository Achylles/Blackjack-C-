#pragma once
#include "GenericPlayer.h"
class Deck :
	public Hand
{
public:
	
	Deck();
	virtual ~Deck();
	
	//create a deck of 52 cards
	void Populate();
	//shuffle the deck
	void Shuffle();
	//deal one card to a hand
	void Deal(Hand& aHand);
	//deal  more cards to a generic player
	void DealToGeneric(GenericPlayer& aGeneric);
};

