/*
Name: Amber Rivera
Chapter: 9
Exercise: 7

This program:
1. Get wood information from user.
2. Calculate price and display summary.
3. Continue until user enters T to see total.
4. Display total and exit.
*/

#include <cctype>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void DisplayItemSummary(int, int, int, int, float, char);
string GetWoodType(char);
char GetTransactionCode();
bool IsValidTransactionCode(char);
float CalculateBoardFeet(int, int, int, int);
float GetPriceOfWood(char, float);
int ConvertFeetToInches(int);

int main() {
	int numBoards;
	int width;
	int height;
	int length;
	float boardFeet;
	float price;
	float total = 0;
	// Initialize to bogus transaction code.
	char transactionCode = 'Z';

	cout << "Wood Type Codes:" << endl;
	cout << "P = Pine" << endl;
	cout << "F = Fire" << endl;
	cout << "C = Cedar" << endl;
	cout << "M = Maple" << endl;
	cout << "O = Oak" << endl << endl;

	// Will break loop when user requests total.
	while (transactionCode != 'T') {
		// Loop until valid transaction code is entered.
		while (!IsValidTransactionCode(transactionCode)) {
			transactionCode = toupper(GetTransactionCode());
		}
		// Get item information from user.
		cout << "Please enter the number of boards: ";
		cin >> numBoards;
		cout << "Please enter the width of the boards: ";
		cin >> width;
		cout << "Please enter the height of the boards: ";
		cin >> height;
		cout << "Please enter the length of the boards: ";
		cin >> length;
		cout << endl << endl;
		// Calculate board feet.
		boardFeet = CalculateBoardFeet(numBoards, width, height, length);
		// Calculate price of wood.
		price = GetPriceOfWood(transactionCode, boardFeet);
		// Add price to total.
		total += price;
		// Display item summary.
		DisplayItemSummary(numBoards, width, height, length, price, transactionCode);
		// Get next transaction code.
		transactionCode = toupper(GetTransactionCode());
	}
	// Display total.
	cout << fixed << setprecision(2);
	cout << "Total Cost: $" << total;
	cin.get();
	cin.get();
	return 0;
}

// Displays a summary of the item using information entered.
void DisplayItemSummary(int numBoards, int width, int height, int length, float price, char woodTypeCode) {
	string wood = GetWoodType(woodTypeCode);
	cout << fixed << setprecision(2);
	cout << "Item Summary:" << endl;
	cout << numBoards << " " << width << "x" << height << "x" << length << " " << wood << " cost: $" << price;
	cout << endl << endl;
}

// Return name of wood based on character code.
string GetWoodType(char woodTypeCode) {
	switch (woodTypeCode) {
	case 'P':
		return "Pine";
	case 'F':
		return "Fir";
	case 'C':
		return "Cedar";
	case 'M':
		return "Maple";
	case 'O':
		return "Oak";
	default:
		cout << "Invalid wood type code";
		break;
	}
}

// Get the transaction or wood code from the user.
char GetTransactionCode() {
	char transactionCode;
	cout << "Please enter the wood type code for your next item or T to view your total: ";
	cin >> transactionCode;
	return transactionCode;
}

// Returns true if the code is P, F, C, M, O, or T.
bool IsValidTransactionCode(char transactionCode) {
	return transactionCode == 'P' || transactionCode == 'F' || transactionCode == 'C' || transactionCode == 'M' || transactionCode == 'O';
}

// Calculates board feet using formula numberBoards * width * height * length all divided by 144 where measurements are in inches.
float CalculateBoardFeet(int numBoards, int width, int height, int length) {
	return (numBoards * width * height * ConvertFeetToInches(length)) / 144.0;
}

// Get's inch value of feet.
int ConvertFeetToInches(int feet) {
	return feet * 12;
}

// Returns the price of wood calculated per type and board feet.
float GetPriceOfWood(char woodTypeCode, float boardFeet) {
	float price;
	switch (woodTypeCode) {
	case 'P':
		price = 0.89;
		break;
	case 'F':
		price = 1.09;
		break;
	case 'C':
		price = 2.26;
		break;
	case 'M':
		price = 4.50;
		break;
	case 'O':
		price = 3.10;
		break;
	default:
		cout << "Invalid wood type code";
		break;
	}
	return price * boardFeet;
}

