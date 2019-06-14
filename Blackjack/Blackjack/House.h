#pragma once
#include "GenericPlayer.h"
class House :
	public GenericPlayer
{
public:
	House(const string& name = "House");
	virtual ~House();

	virtual bool isHitting() const;
	void FlipFirstCard();
};

