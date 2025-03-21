#include "Player.hpp"

/* Constructors */

Player::Player(void)
: _points(0)
{
	return ;
}

Player::Player(Player const &obj)
: _points(obj.getPoints())
{
	return ;
}


/* Destructor */

Player::~Player(void)
{
	return ;
}


/* Copy Assignment Overload */

Player	&Player::operator=(Player const &obj)
{
	this->_points = obj.getPoints();
	return (*this);
}


/* Output Stream Insertion Overload */

std::ostream	&operator<<(std::ostream &o, Player const &obj)
{
	o << obj.getPoints() << std::endl;
	return (o);
}


/* Getters */

int	Player::getPoints(void) const
{
	return (this->_points);
}


/* Actions */

void	Player::addPoints(int rank)
{
	this->_points += 9 - rank;
	return ;
}
