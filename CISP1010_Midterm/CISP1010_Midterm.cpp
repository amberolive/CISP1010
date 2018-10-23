/*
Name: Amber Rivera
Class: CISP 1010
Assignment: Midterm

This program:
1) Gets price of car from user.
2) Gets trade in value from user.
3) Gets down payment from user.
4) Gets annual interest rate from user.
5) Calculates and displays loan information.
6) Calculates and displays monthly payment information.
*/

#include <iomanip>
#include <iostream>

using namespace std;

int main() {
	float price;
	float downPayment;
	float tradeIn;
	float loanAmt;
	float annualIntRate;
	float annualIntPercent;
	float monIntRate;
	int	noMonths;
	float monPayment;
	// Used to escape while loops when input is valid.
	bool validInput = false;

	// Get Price
	cout << "The price of the car should be greater than $50.00 and less than $50,000.00 (ex. 45000)." << endl;
	cout << "Please enter the price of the car: ";

	while (!validInput) {
		cin >> price;
		if (50 < price && price < 50000) {
			validInput = true;
		}
		else {
			cout << fixed << setprecision(2);
			cout << "$" << price << " is invalid. Please enter a valid price: ";
		}
	}

	// Get Trade In Value
	cout << endl << endl << "The trade in value should be greater than or equal to 0 and less than $" << price << " (ex. 15000)." << endl;
	cout << "Please enter the trade in value of the car: ";
	// Reset valid input for trade in.
	validInput = false;

	while (!validInput) {
		cin >> tradeIn;
		if (0 <= tradeIn && tradeIn < price) {
			validInput = true;
		}
		else {
			cout << fixed << setprecision(2);
			cout << "$" << tradeIn << " is invalid. Please enter a valid trade in value: ";
		}
	}

	// Get Down Payment
	cout << endl << endl << "The down payment should be greater than or equal to 0 and less than $" << price - tradeIn << " (ex. 20000)." << endl;
	cout << "Please enter the down payment for the car: ";
	// Reset valid input for down payment.
	validInput = false;

	while (!validInput) {
		cin >> downPayment;
		if (0 <= downPayment && downPayment < (price - tradeIn)) {
			validInput = true;
		}
		else {
			cout << fixed << setprecision(2);
			cout << "$" << downPayment << " is invalid. Please enter a valid down payment: ";
		}
	}

	// Get Annual Interest Rate
	cout << endl << endl << "The annual interest rate should be entered as a nonnegative decimal and should be less than 0.50 (ex. 0.08)." << endl;
	cout << "Please enter the annual interest rate: ";
	// Reset valid input for annual interest rate.
	validInput = false;

	while (!validInput) {
		cin >> annualIntRate;
		if (0 <= annualIntRate && annualIntRate < 0.5) {
			validInput = true;
		}
		else {
			cout << annualIntRate << " is invalid. Please enter a valid annual interest rate: ";
		}
	}

	// Calculate Loan Information.
	monIntRate = annualIntRate / 12.0;
	annualIntPercent = annualIntRate * 100.0;
	loanAmt = price - downPayment - tradeIn;

	// Display Loan Information
	cout << endl << endl << setw(25) << fixed << setprecision(2);
	cout << setw(5) << "Affordable Used Car Lot" << endl << endl;
	cout << setw(25) << "Vehicle price: $" << price << endl;
	cout << setw(25) << "Trade in value: $" << tradeIn << endl;
	cout << setw(25) << "Down payment: $" << downPayment << endl;
	cout << setw(25) << "----------" << endl;
	cout << setw(25) << "Loan amount: $" << loanAmt << endl << endl;
	cout << setw(25) << "Annual interest rate: " << annualIntPercent << "%" << endl << endl;
	cout << setw(5) << "Monthly payment options" << endl << endl;
	cout << setw(10) << "Months" << setw(10) << "Payment" << endl;


	// Calculate and display Monthly Payments
	for (noMonths = 12; noMonths <= 60; noMonths += 12) {
		monPayment = (loanAmt * monIntRate) / (1.0 - pow((1 + monIntRate), -noMonths));
		cout << fixed << setprecision(2);
		cout << setw(7) << noMonths << setw(7) << " $" << monPayment << endl;
	}

	cin.get();
	cin.get();
	return 0;
}