#pragma once
#include "Deck.h"
#include "Player.h"
#include "House.h"
class Game
{
private:
	Deck m_Deck;
	House m_House;
	vector<Player> m_Players;
public:
	Game(const vector<string>& names);
	~Game();

	void Play();

};

