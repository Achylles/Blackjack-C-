#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Hand.h"
using namespace std;
class GenericPlayer :
	public Hand
{
	friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);
public:
	GenericPlayer(const string& name = "");
	virtual ~GenericPlayer();

	//checks if the generic player wants to keep hitting

	virtual bool isHitting() const = 0;

	//checks if the player has got a score above 21
	bool isBusted() const;

	//announces that a player has busted

	void msgBusted() const;

protected:
	string m_Name;
};

