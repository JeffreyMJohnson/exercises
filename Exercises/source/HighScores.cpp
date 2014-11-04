#include "..\include\HighScores.h"


HighScores::HighScores()
{
}


HighScores::~HighScores()
{
	for (HighScore* score : scores)
	{
		delete score;
	}
}

void HighScores::AddScore(HighScore* a_score)
{
	scores.push_back(a_score);

}

HighScore* HighScores::GetScore(const string a_name)
{
	for (HighScore* score : scores)
	{
		if (score->name == a_name)
			return score;
	}
	return nullptr;
}

HighScore* HighScores::GetHighScore()
{
	if (scores.size() == 0)
		return nullptr;
	else
		return *scores.begin();
}