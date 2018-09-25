/*
Name: Amber Rivera
Chapter: 3
Exercise: 3

This program calculates 15! and approximates 15! using Stirling's formula. 
Then prints the results and the difference to the console.
*/

#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

// Declare and assign constants.
const double PI = 3.14159;
const double N = 15.0;

// Declare functions to calculate factorial.
double calculateFactorial();
double calculateStirlingsFactorial();

int main() {
	// Local variables to hold calculated factorials.
	double factorial = calculateFactorial();
	double factorial_stirlings = calculateStirlingsFactorial();

	// Print factorial, approximation, and difference.
	cout << fixed << setprecision(0);
	cout << N << "! = " << factorial << endl;
	cout << "Stirling's formula " << N << "! = " << factorial_stirlings << endl;
	cout << "Difference = " << factorial - factorial_stirlings << endl;

	cin.get();
}

// Returns N! calculated using Stirling's formula.
// Stirling's formula = e^-n * n^n * sqrt(2 * pi * n)
double calculateStirlingsFactorial() {
	return exp(-N) * pow(N, N) * sqrt(2 * PI * N);
}

// Returns N!.
double calculateFactorial() {
	return N * 14 * 13 * 12 * 11 * 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;
}