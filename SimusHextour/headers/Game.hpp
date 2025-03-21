#ifndef GAME_HPP
# define GAME_HPP

# include <string>
# include <iostream>
# include "Player.hpp"

class Game
{
	public :

		Game(void);
		Game(Game const &obj);
		~Game(void);
		Game(Player *a, Player *b, Player *c, Player *d, Player *e, Player *f, Player *g, Player *h);

		Game	&operator=(Game const &obj);

		Player	*getPlayer(int index) const;
		
		void	playGame(void);

	private :

		Player	*_playerList[8];
};

std::ostream	&operator<<(std::ostream &o, Game const &obj);

#endif
