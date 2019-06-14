#include "Player.h"
using namespace std;

Player::Player(const string & name) : GenericPlayer(name)
{
}

Player::~Player()
{
}

bool Player::isHitting() const
{
	cout << "Would you like to hit? (Y/N)";
	char response;
	//TODO: make a try/catch block with throw
	cin >> response;
	return (response == 'y' || 'Y');
}

void Player::msgWin() const
{
	cout << endl << m_Name << " wins." << endl;

}

void Player::msgLose() const
{
	cout << endl << m_Name << " loses." << endl;
}

void Player::msgPush() const
{
	cout << endl << m_Name << " pushes." << endl;
}
