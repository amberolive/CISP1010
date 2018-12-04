#include <iostream>
#include "Time.h"

using namespace std;

int main()
{
	Time time1(5, 23);
	Time time2(5, 20);
	Time time3;

	int result;

	cout << "Time 1: " << time1.GetMinutes() << ":" << time1.GetSeconds() << endl;
	cout << "Time 2: " << time2.GetMinutes() << ":" << time2.GetSeconds() << endl;
	cout << "Time 3: " << time3.GetMinutes() << ":" << time3.GetSeconds() << endl;

	switch (time1.ComparedTo(time2))
	{  
	case LESS: 
		cout << "Time 1 is less than Time 2." << endl << endl;
		break;
	case EQUAL: 
		cout << "The times are equal." << endl << endl;
		break;
	case GREATER: 
		cout << "Time 1 is greater than Time 2." << endl << endl;
		break;
	}

	Time addedTimes = time1.AddTime(time2);
	cout << "Time 1 + Time 2 = " << addedTimes.GetMinutes() << " minutes and " << addedTimes.GetSeconds() << " seconds." << endl << endl;

	Time subtractedTimes = time1.SubtractTime(time2);
	cout << "Time 1 - Time 2 = " << subtractedTimes.GetMinutes() << " minutes and " << subtractedTimes.GetSeconds() << " seconds." << endl << endl;

	cout << "Time 3: " << time3.GetMinutes() << " minutes and " << time3.GetSeconds() << " seconds." << endl;

	cin.get();
	cin.get();
	return 0;
}