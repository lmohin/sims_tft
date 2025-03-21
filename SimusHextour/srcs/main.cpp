#include <ctime>
#include <iostream>
#include <cstdlib>

void	playTournament(int playingPoints[66]);
void	orderPlayerList(int playerlist[66]);

int main(void)
{
	srand(time(0));
	int	stats[300];
	for (int i = 0; i < 300; i++)
		stats[i] = 0;
	for (int simNumber = 0; simNumber < 1000000; simNumber++)
	{
		int	playerPoints[66] = {1000, 85, 83, 81, 79, 
					78, 77, 76, 74, 74, 
					73, 73, 72, 72, 71, 
					71, 69, 69, 68, 68, 
					67, 67, 66, 66, 65, 
					65, 64, 64, 63, 63, 
					62, 62, 59, 59, 58,
					58, 58, 57, 57, 57,
					56, 56, 56, 55, 55,
					55, 54, 54, 54, 53,
					53, 53, 52, 52, 52,
					51, 51, 51, 50, 50,
					50, 49, 49, 49, 123, 119};
		playTournament(playerPoints);
		orderPlayerList(playerPoints);
		int j = 0;
		while (playerPoints[j] > 500)
			j++;
		stats[playerPoints[13 + j]]++;
	}
	for (int i = 100; i < 200; i++)
	{
		std::cout << "Tiebreak at " << i << ": " << stats[i] << " " << stats[i] / 10000.0 << "%" << std::endl;
	}
	return (0);
}

void	playTournament(int playingPoints[66])
{
	int	pointsRepart[64] = {85, 79, 78, 77, 73,
					73, 71, 71, 65, 64,
					64, 63, 63, 46, 39,
					1000, 51, 0, 1000, 1000,
					44, 50, 39, 59, 64,
					42, 56, 51, 49, 42,
					46, 1000, 41, 1000, 43,
					1000, 54, 38, 37, 1000,
					1000, 42, 42, 39, 1000,
					1000, 1000, 0, 0, 0,
					0, 0, 0, 0, 0,
					0, 0, 0, 0, 0,
					0, 0, 0, 0};
	for (int i = 0; i < 64; i++)
	{
		int j = i + rand() / (RAND_MAX / (64 - i) + 1);
		int tmp = pointsRepart[j];
		pointsRepart[j] = pointsRepart[i];
		pointsRepart[i] = tmp;
	}
	for (int i = 0; i < 64; i++)
	{
		(playingPoints)[i] += pointsRepart[i];
	}
}

void	orderPlayerList(int playerList[66])
{
	int	i = 0;
	int	tmp;
	
	while (i < 65)
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
