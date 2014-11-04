#include "include\HighScores.h"
#include <iostream>

void main()
{
	HighScores myScores;
	myScores.AddScore(new HighScore("foo", 100));
	myScores.AddScore(new HighScore("bar", 10));

	HighScore* score1 = myScores.GetScore("foo");
	if (score1 == nullptr)
		std::cout << "none found";
	else
		std::cout << score1->ToString();

	system("pause");

}