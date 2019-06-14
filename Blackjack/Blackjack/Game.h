#pragma once
#include "Deck.h"
#include "GenericPlayer.h"
#include "Player.h"
#include "House.h"
#include <iostream>
class Game
{
	Deck m_Deck;
	House m_House;
	vector<Player> m_Players;
public:
	Game(const vector<string>& names);
	~Game();

	void Play();

};

