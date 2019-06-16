#include "Game.h"
using namespace std;


Game::Game(const vector<string>& names)
{
	vector<string>::const_iterator pName;
	for (pName = names.begin(); pName != names.end(); ++pName)
	{
		m_Players.push_back(Player(*pName));
	}
	srand((unsigned int)time(NULL)); //casting because time returns int64 and srand is an int32
	m_Deck.Populate();
	m_Deck.Shuffle();

}

Game::~Game()
{

}

void Game::Play()
{
	//deals the first two cards to each player
	vector<Player>::iterator pPlayer;
	for (int i = 0; i <= 2; i++)
	{
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
			m_Deck.Deal(*pPlayer);
		}
		m_Deck.Deal(m_House);
	}
	//hides House's first card
	m_House.FlipFirstCard();

	//Display everyone's hand
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
		cout << *pPlayer << endl;
	}
	cout << m_House << endl;

	//deal more cards to players
	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
	{
		m_Deck.DealToGeneric(*pPlayer);
	}

	//reveal house's first card
	m_House.FlipFirstCard();
	cout << endl << m_House;

	//Deal more cards to the House
	m_Deck.DealToGeneric(m_House);
	
	if (m_House.isBusted())
	{
		//everyone who is still playing wins
		for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		{
			if (!(pPlayer->isBusted())) pPlayer->msgWin();
		}
	}
	else
	{
		for(pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
			if (!(pPlayer->isBusted()))
			{
				if (pPlayer->GetTotal() > m_House.GetTotal())
				{
					pPlayer->msgWin();
				}
				else if (pPlayer->GetTotal() < m_House.GetTotal())
				{
					pPlayer->msgLose();
				}
				else
					pPlayer->msgPush();
			}
	}
	//removes everyone's cards

	for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
		pPlayer->Clear();
	m_House.Clear();
}
