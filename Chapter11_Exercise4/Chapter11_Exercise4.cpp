/*
Name: Amber Rivera
Chapter: 11
Exercise: 4

This program:
1. Takes a word as input from the user.
2. Displays the ICAO translation of that word.
*/

#include <cctype>
#include <iostream>
#include <string>

using namespace std;

void DisplayICAOTranslationOfWord();
string GetWordFromUser();
string GetICAOTranslationOfWord(string);
string GetICAOTranslationOfChar(char);

string icaoAlphabet[26] = { "Alpha", "Bravo", "Charlie", "Delta",
		"Echo", "Foxtrot", "Golf", "Hotel", "India", "Juliet", "Kilo", "Lima",
		"Mike", "November", "Oscar", "Papa", "Quebec", "Romeo", "Sierra",
		"Tango", "Uniform", "Victor", "Whiskey", "X-ray", "Yankee", "Zulu"};

int main() {
	DisplayICAOTranslationOfWord();
	return 0;
}

void DisplayICAOTranslationOfWord() {
	string word = GetWordFromUser();
	// Display ICAO translation.
	cout << "The ICAO translation of " << word << " is: " << GetICAOTranslationOfWord(word);
	cin.get();
	cin.get();
	return;
}

// Gets a word from the user.
string GetWordFromUser() {
	string word;
	cout << "This program will display the corresponding ICAO translation of a word." << endl << endl << endl;
	cout << "Please enter a word: ";
	cin >> word;
	return word;
}

// Returns the ICAO translation of a word.
string GetICAOTranslationOfWord(string word) {
	string phoneticVersion;
	char character;

	// Loop through characters in word.
	for (int i = 0; i < word.size(); i++) {
		character = word.at(i);

		// Make sure that the character is a letter before doing the translation.
		if (isalpha(character)) {
			phoneticVersion += GetICAOTranslationOfChar(character);
			phoneticVersion += " ";
		}

		// Display notification if not a letter.
		else {
			cout << character << " is not a letter and will not be included in the translation." << endl;
		}
	}
	return phoneticVersion;
}

// Returns the ICAO translation of a character.
string GetICAOTranslationOfChar(char character) {
	character = toupper(character);
	// Get ASCII value of uppercase character and subtract 65 to get index of ICAO word.
	int index = int(character) - 65;
	return icaoAlphabet[index];
}