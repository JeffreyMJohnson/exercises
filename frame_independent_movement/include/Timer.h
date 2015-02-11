#ifndef _TIMER_H_
#define _TIMER_H_
#include <chrono>

#include <iostream>

typedef std::chrono::time_point<std::chrono::high_resolution_clock> time_point;

class Timer
{
public:


	Timer()
	{

	}
	~Timer()
	{

	}

	void Update()
	{

	}
private:
	//time_point< currentTime;
	float elapsedTime;//time since last update
	float totalTime;//time since program started
};

#endif