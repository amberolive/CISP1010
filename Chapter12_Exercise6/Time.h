#include "RelationType.h"

class Time
{
public:
	// Constructors
	Time();
	Time(int inputMinutes, int inputSeconds);

	// Getters
	int GetMinutes() const;
	int GetSeconds() const;
	int GetTimeInSeconds() const;
	
	// Add and Subtract time
	Time AddTime(Time otherTime) const;
	Time SubtractTime(Time otherTime) const;

	// Compare two times
	RelationType ComparedTo(Time otherTime);

private:
	int minutes;
	int seconds;
};