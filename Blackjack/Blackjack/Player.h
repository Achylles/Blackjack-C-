#pragma once
#include "GenericPlayer.h"
class Player :
	public GenericPlayer
{
public:
	Player(const string& name = "");
	virtual ~Player();
	virtual bool isHitting() const;
	void msgWin() const; //announces if a player wins
	void msgLose() const; //announces if a player loses
	void msgPush() const; //announces if a player pushes
};

