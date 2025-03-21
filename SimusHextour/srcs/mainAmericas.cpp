/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainAmericas.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmohin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:01:58 by lmohin            #+#    #+#             */
/*   Updated: 2024/06/22 22:34:24 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include <cstdlib>

void	playTournament(int playingPoints[38]);
void	orderPlayerList(int playerlist[38]);

int main(void)
{
	srand(time(0));
	int	stats[300];
	for (int i = 0; i < 300; i++)
		stats[i] = 0;
	for (int simNumber = 0; simNumber < 1000000; simNumber++)
	{
		int	playerPoints[38] = {1000, 23, 21, 19, 17, 
					16, 15, 14, 12, 12, 
					11, 11, 10, 10, 9, 
					9, 7, 7, 6, 6, 
					5, 5, 4, 4, 3, 
					3, 2, 2, 1, 1, 
					0, 0, 241, 213, 212,
					208, 208, 1000};

		playTournament(playerPoints);
		orderPlayerList(playerPoints);
		stats[playerPoints[16]]++;
		if (playerPoints[16] < 204)
		{
	//		std::cout << playerPoints[16] << std::endl;
			for (int k = 0; k < 38; k++)
				std::cout << k + 1 << ": " << playerPoints[k] << std::endl;
		}
	}
	for (int i = 150; i < 300; i++)
	{
		std::cout << "Tiebreak " << i << ": " << stats[i] << " " << stats[i] / 10000.0 << "%" << std::endl;
	}
	return (0);
}

void	playTournament(int playingPoints[38])
{
	int	pointsRepart[32] = {234, 233, 230, 229, 1000, 223, 222, 218, 213, 206, 204,
					199, 199, 198, 196, 192, 190, 184, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	for (int i = 0; i < 32; i++)
	{
		int j = i + rand() / (RAND_MAX / (32 - i) + 1);
		int tmp = pointsRepart[j];
		pointsRepart[j] = pointsRepart[i];
		pointsRepart[i] = tmp;
	}
	for (int i = 0; i < 32; i++)
	{
		(playingPoints)[i] += pointsRepart[i];
	}
}

void	orderPlayerList(int playerList[38])
{
	int	i = 0;
	int	tmp;
	
	while (i < 37)
	{
		if (playerList[i + 1] > playerList[i])
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
