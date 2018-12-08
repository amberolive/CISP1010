/*
Name: Amber Rivera
Class: CISP 1010
Assignment: Final

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

float getPrice(); 
float getTradeIn(float);
float getDownPayment(float, float);
float calcLoanAmount(float, float, float);
float getInterestRate();
float calcMonPayment(float, float, float, float, int);
void displayLoanSchedule(float, float, float, float, float, float*, int*); 

int main() {
	float price = getPrice();
	float tradeIn = getTradeIn(price);
	float downPayment = getDownPayment(price, tradeIn);
	float loanAmt = calcLoanAmount(price, downPayment, tradeIn);
	float annualIntRate = getInterestRate();
	int	noMonths[5] = { 12, 24, 36, 48, 60 };
	float monPayments[5];

	for (int i = 0; i < 5; i++) {
		monPayments[i] = calcMonPayment(price, tradeIn, annualIntRate, loanAmt, noMonths[i]);
	}
	
	displayLoanSchedule(price, tradeIn, downPayment, loanAmt, annualIntRate, monPayments, noMonths);

	cin.get();
	cin.get();
	return 0;
} 

// Get price between 75 and 48,500
float getPrice() {
	float price;
	bool validInput = false;

	cout << "The price of the car should be greater than $75.00 and less than $48,500.00 (ex. 45000)." << endl;
	cout << "Please enter the price of the car: ";

	do { 
		cin >> price;
		if (75 < price && price < 48500) {
			validInput = true; 
		}
		else {
			cout << fixed << setprecision(2);
			cout << "$" << price << " is invalid. Please enter a valid price: ";
		}
	} while (!validInput);
	return price;
}

// Get trade in value. Must be between 0 and the price of the car.
float getTradeIn(float price) {
	float tradeIn;
	bool validInput = false;
	cout << endl << endl << "The trade in value should be greater than or equal to 0 and less than $" << price << " (ex. 15000)." << endl;
	cout << "Please enter the trade in value of the car: ";

	do {
		cin >> tradeIn;
		if (0 <= tradeIn && tradeIn < price) {
			validInput = true;
		}
		else {
			cout << fixed << setprecision(2);
			cout << "$" << tradeIn << " is invalid. Please enter a valid trade in value: ";
		}
	} while (!validInput);
	return tradeIn;
}

// Get down payment. Must be between 0 and the price minus the trade in value.
float getDownPayment(float price, float tradeIn) {
	float downPayment;
	bool validInput = false;

	cout << endl << endl << "The down payment should be greater than or equal to 0 and less than $" << price - tradeIn << " (ex. 20000)." << endl;
	cout << "Please enter the down payment for the car: ";

	do {
		cin >> downPayment;
		if (0 <= downPayment && downPayment < (price - tradeIn)) {
			validInput = true;
		}
		else {
			cout << fixed << setprecision(2);
			cout << "$" << downPayment << " is invalid. Please enter a valid down payment: ";
		}
	} while (!validInput);
	return downPayment;
}

float getInterestRate() {
	float annualIntRate;
	bool validInput = false;

	cout << endl << endl << "The annual interest rate should be entered as a nonnegative decimal and should be less than 0.19 (ex. 0.08)." << endl;
	cout << "Please enter the annual interest rate: ";

	do {
		cin >> annualIntRate;
		if (0 <= annualIntRate && annualIntRate < 0.19) {
			validInput = true;
		}
		else {
			cout << annualIntRate << " is invalid. Please enter a valid annual interest rate: ";
		}
	} while (!validInput);
	return annualIntRate;
}
 

float calcLoanAmount(float price, float downPayment, float tradeIn) {
	return price - downPayment - tradeIn;
}

float calcMonPayment(float price, float tradeIn, float annualIntRate, float loanAmt, int noMonths) {

	// Calculate Loan Information.
	float monIntRate = annualIntRate / 12.0;

    return (loanAmt * monIntRate) / (1.0 - pow((1 + monIntRate), -noMonths));
} 

void displayLoanSchedule(float price, float tradeIn, float downPayment, float loanAmt, float annualIntRate, float* monPayments, int*
	noMonths) {
	// Display Loan Information
	cout << endl << endl << setw(25) << fixed << setprecision(2);
	cout << setw(5) << "Honest Dave’s Used Cars" << endl << endl;
	cout << setw(25) << "Vehicle price: $" << price << endl;
	cout << setw(25) << "Trade in value: $" << tradeIn << endl;
	cout << setw(25) << "Down payment: $" << downPayment << endl;
	cout << setw(25) << "----------" << endl;
	cout << setw(25) << "Loan amount: $" << loanAmt << endl << endl;
	cout << setw(25) << "Annual interest rate: " << annualIntRate * 100 << "%" << endl << endl;
	cout << setw(5) << "Monthly payment options" << endl << endl;
	cout << setw(10) << "Months" << setw(10) << "Payment" << endl;

	for (int i = 0; i < 5; i++) {
		cout << fixed << setprecision(2);
		cout << setw(7) << *(noMonths + i) << setw(7) << " $" << monPayments[i] << endl;
	}
} 
