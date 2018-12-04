#include <iostream>
#include "Time.h"

using namespace std;

// Default constructor
Time::Time()
{
	minutes = 0;
	seconds = 0;
}

// Overloaded constructor
Time::Time(int inputMinutes, int inputSeconds)
{
	minutes = inputMinutes;
	seconds = inputSeconds;
}

// Getters
int Time::GetMinutes() const
{
	return minutes;
}


int Time::GetSeconds() const
{
	return seconds;
}

int Time::GetTimeInSeconds() const
{
	int timeInSeconds = minutes * 60 + seconds;
	return timeInSeconds;
}


Time Time::AddTime(Time otherTime) const
{
	int totalTimeInSeconds = GetTimeInSeconds() + otherTime.GetTimeInSeconds();
	int totalMinutes = totalTimeInSeconds / 60;
	int totalSeconds = totalTimeInSeconds % 60;
	return Time(totalMinutes, totalSeconds);
}

Time Time::SubtractTime(Time otherTime) const
{
	int totalTimeInSeconds = GetTimeInSeconds() - otherTime.GetTimeInSeconds();
	int totalMinutes = totalTimeInSeconds / 60;
	int totalSeconds = totalTimeInSeconds % 60;
	if (totalSeconds < 0)
		return Time();
	else
	{
		return Time(totalMinutes, totalSeconds);
	}
}

RelationType Time::ComparedTo(Time otherTime)
{
	if (minutes < otherTime.minutes)
		return LESS;
	else if (minutes > otherTime.minutes)
		return GREATER;
	else if (seconds < otherTime.minutes)
		return LESS;
	else if (seconds > otherTime.minutes)
		return GREATER;
	else
		return EQUAL;
}