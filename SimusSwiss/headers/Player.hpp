#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <string>
# include <iostream>

class Player
{
	public :

		Player(void);
		Player(Player const &obj);
		~Player(void);

		Player	&operator=(Player const &obj);

		int		getPoints(void) const;
		void		addPoints(int rank);

	private :

		int			_points;
};

std::ostream	&operator<<(std::ostream &o, Player const &obj);

#endif
