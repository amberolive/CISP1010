/*
Name: Amber Rivera
Chapter: 4
Exercise: 7

This program:
1) Acquires the percentage of the face of the moon that appears illuminated from the user.
2) Calculates the illuminated surface area.
3) Displays the result.
*/

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

const double PI = 3.14159;
const double MOON_RADIUS = 1738.3;

double convertIntToDecimalPercent(int percent);
double calculateSurfaceAreaOfSphere(int percentRadians);

int main() {
	int percentIlluminated;
	double surfaceAreaIlluminated;

	// Get percent illuminated from user.
	cout << "Please enter the percent of the moon face that appears illuminated: ";
	cin >> percentIlluminated;

	// Calculate surface area.
	surfaceAreaIlluminated = calculateSurfaceAreaOfSphere(percentIlluminated);

	//  Display surface area to 2 decimal places.
	cout << fixed << setprecision(2);
	cout << endl << endl << "The illuminated surface area of the moon to two decimal places is " << surfaceAreaIlluminated << " square kilometers.";

	// Keep console open until key is pressed.
	cin.get();
	cin.get();
	return 0;
}

// Convert integer percent to a decimal.
double convertIntToDecimalPercent(int percent) {
	return percent / 100.0;
}

// Calculate the surface area of a sphere
double calculateSurfaceAreaOfSphere(int percentRadians) {
	double decimalPercentRadians = convertIntToDecimalPercent(percentRadians);
	return 2 * pow(MOON_RADIUS, 2) * (PI * decimalPercentRadians);
}
