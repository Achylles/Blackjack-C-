#include "GenericPlayer.h"



GenericPlayer::GenericPlayer(const string& name) : m_Name(name)
{

}


GenericPlayer::~GenericPlayer()
{
}

bool GenericPlayer::isBusted() const
{
	return GetTotal() > 21; //returns true if the player has more than 21 score
}

void GenericPlayer::msgBusted() const
{
	std::cout << "\n" << m_Name << " has busted.\n";
}


