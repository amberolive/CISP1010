/*
Name: Amber Rivera
Chapter: 2
Exercise: 2

Program to print the six permiations of three sentences to the console.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	// Declare constants for three sentences.
	const string LINE1 = "I saw the big brown bear.";
	const string LINE2 = "The big brown bear saw me.";
	const string LINE3 = "Oh! What a frightening experience!";

	// Print six permiations to console.
	cout << LINE1 << endl << LINE2 << endl << LINE3 << endl << endl;
	cout << LINE1 << endl << LINE3 << endl << LINE2 << endl << endl;
	cout << LINE2 << endl << LINE1 << endl << LINE3 << endl << endl;
	cout << LINE2 << endl << LINE3 << endl << LINE1 << endl << endl;
	cout << LINE3 << endl << LINE1 << endl << LINE2 << endl << endl;
	cout << LINE3 << endl << LINE2 << endl << LINE1 << endl;

	// Keep console open until key is pressed.
	cin.get();
	return 0;
}