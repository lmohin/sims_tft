/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmohin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:01:58 by lmohin            #+#    #+#             */
/*   Updated: 2024/05/08 00:38:54 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "Game.hpp"
#include <ctime>

void	createGame(Player playerList[128], int startIndex)
{
	Game initGame(&playerList[startIndex], &playerList[startIndex + 1], &playerList[startIndex + 2],
			&playerList[startIndex + 3], &playerList[startIndex + 4], &playerList[startIndex + 5],
			&playerList[startIndex + 6], &playerList[startIndex + 7]);
	std::cout << "Lobby " << startIndex / 8 + 1 << ": " << std::endl << initGame << std::endl;
	initGame.playGame();
	std::cout << "-After the game-" << std::endl << initGame << std::endl;
}

void	orderPlayerList(Player playerList[128])
{
	int	i = 0;
	Player	tmp;

	while (i < 127)
	{
		if (playerList[i + 1].getPoints() > playerList[i].getPoints())
		{
			tmp = playerList[i + 1];
			playerList[i + 1] = playerList[i];
			playerList[i] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

int main(void)
{
	Player	playerList[128];

	srand(time(0));
	for (int nbrOfRounds = 0; nbrOfRounds < 5; nbrOfRounds++)
	{
		for (int gameIndex = 0; gameIndex < 16; gameIndex++)
			createGame(playerList, gameIndex * 8);
		orderPlayerList(playerList);
	}
	for (int playerIndex = 0; playerIndex < 128; playerIndex++)
		std::cout << playerIndex + 1 << ": " << playerList[playerIndex];
	return (0);
}
