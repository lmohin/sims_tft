#include "Game.hpp"

/* Constructors */

Game::Game(void)
{
	return ;
}

Game::Game(Game const &obj)
{
	for (int i = 0; i < 8; i++)
	{
		this->_playerList[i] = obj.getPlayer(i);
	}
	return ;
}

Game::Game(Player *a, Player *b, Player *c, Player *d, Player *e, Player *f, Player *g, Player *h)
{
	this->_playerList[0] = a;
	this->_playerList[1] = b;
	this->_playerList[2] = c;
	this->_playerList[3] = d;
	this->_playerList[4] = e;
	this->_playerList[5] = f;
	this->_playerList[6] = g;
	this->_playerList[7] = h;
}


/* Destructor */

Game::~Game(void)
{
	return ;
}


/* Copy Assignment Overload */

Game	&Game::operator=(Game const &obj)
{
	for (int i = 0; i < 8; i++)
	{
		this->_playerList[i] = obj.getPlayer(i);
	}
	return (*this);
}


/* Output Stream Insertion Overload */

std::ostream	&operator<<(std::ostream &o, Game const &obj)
{
	for (int i = 0; i < 8; i++)
	{
		std::cout << *obj.getPlayer(i);
	}
	return (o);
}


/* Getters */

Player	*Game::getPlayer(int index) const
{
	return (this->_playerList[index]);
}


/* Actions */

void	Game::playGame(void)
{
	int	results[8] = {1, 2, 3, 4, 5, 6, 7, 8};

	for (int i = 0; i < 7; i++)
	{
		int j = i + rand() / (RAND_MAX / (8 - i) + 1);
		int tmp = results[j];
		results[j] = results[i];
		results[i] = tmp;
	}
	for (int i = 0; i < 8; i++)
	{
		this->_playerList[i]->addPoints(results[i]);
	}
	return ;
}
