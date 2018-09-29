/*
Name: Amber Rivera
Chapter: 5
Exercise: 7

This program gets the day of the year from the user and prints what month that day is in.
*/

#include <iostream>
#include <string>

using namespace std;

int getDay();
void printMonth(int day);

int main() {
	int day = getDay();
	printMonth(day);
	cin.get();
	cin.get();
	return 0;
}

// Get day of year from user.
int getDay()
{
	int day;
	cout << "Please enter the number of a day of the year (should be between 1 and 365): ";
	cin >> day;
	return day;
}

// Print month the day is in.
void printMonth(int day) {
	if ((day >= 1) && (day <= 365)) {
		// Is in January (1-31)
		if (day <= 31) {
			cout << "Day " << day << " of the year is in January.";
		}
		// Is in February (32-59)
		else if ((day >= 32) && (day <= 59)) {
			cout << "Day " << day << " of the year is in February.";
		}
		// Is in March (60-90)
		else if ((day >= 60) && (day <= 90)) {
			cout << "Day " << day << " of the year is in March.";
		}
		// Is in April (91-120)
		else if ((day >= 91) && (day <= 120)) {
			cout << "Day " << day << " of the year is in April.";
		}
		// Is in May (121-151)
		else if ((day >= 121) && (day <= 151)) {
			cout << "Day " << day << " of the year is in May.";
		}
		// Is in June (152-181)
		else if ((day >= 152) && (day <= 181)) {
			cout << "Day " << day << " of the year is in June.";
		}
		// Is in July (182-212)
		else if ((day >= 182) && (day <= 212)) {
			cout << "Day " << day << " of the year is in July.";
		}
		// Is in August (213-243)
		else if ((day >= 213) && (day <= 243)) {
			cout << "Day " << day << " of the year is in August.";
		}
		// Is in September (244-273)
		else if ((day >= 244) && (day <= 273)) {
			cout << "Day " << day << " of the year is in September.";
		}
		// Is in October (274-304)
		else if ((day >= 274) && (day <= 304)) {
			cout << "Day " << day << " of the year is in October.";
		}
		// Is in November (305-334)
		else if ((day >= 305) && (day <= 334)) {
			cout << "Day " << day << " of the year is in November.";
		}
		// Is in December (335-365)
		else if ((day >= 335) && (day <= 365)) {
			cout << "Day " << day << " of the year is in December.";
		}
	}
	else {
		cout << day << " is not a valid number for a day of the year. It should be between 1 and 365.";
	}
}