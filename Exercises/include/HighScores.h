#pragma once
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct HighScore
{
	string name;
	int score;

	HighScore()
	{
		name = "";
		score = 0;
	}

	HighScore(const string a_name)
	{
		name = a_name;
		score = 0;
	}

	HighScore(const string a_name, const int a_score)
	{
		name = a_name;
		score = a_score;
	}

	bool operator==(HighScore& other)
	{
		return name == other.name;
	}

	bool operator<(const HighScore& other)
	{
		return score < other.score;
	}

	bool operator>(const HighScore& other)
	{
		return score > other.score;
	}

	string ToString()
	{
		char buff[10];
		string result = "HighScore [name=" + name + " , score=" + itoa(score, buff, 10)  + "]\n";
		return result;
	}
};

class HighScores
{
public:
	HighScores();
	~HighScores();

	void AddScore(HighScore* a_score);
	HighScore* GetScore(const string a_name);
	HighScore* GetHighScore();


private:
	vector<HighScore*> scores;
};

