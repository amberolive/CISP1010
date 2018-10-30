/*
Name: Amber Rivera
Chapter: 8
Exercise: 10

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
	string phoneticVersion;

	// Switch based on the uppercase version of the character to reduce cases needed.
	switch (toupper(character)) {
	case 'A':
		phoneticVersion = "Alpha";
		break;
	case 'B':
		phoneticVersion = "Bravo";
		break;
	case 'C':
		phoneticVersion = "Charlie";
		break;
	case 'D':
		phoneticVersion = "Delta";
		break;
	case 'E':
		phoneticVersion = "Echo";
		break;
	case 'F':
		phoneticVersion = "Foxtrot";
		break;
	case 'G':
		phoneticVersion = "Golf";
		break;
	case 'H':
		phoneticVersion = "Hotel";
		break;
	case 'I':
		phoneticVersion = "India";
		break;
	case 'J':
		phoneticVersion = "Juliet";
		break;
	case 'K':
		phoneticVersion = "Kilo";
		break;
	case 'L':
		phoneticVersion = "Lima";
		break;
	case 'M':
		phoneticVersion = "Mike";
		break;
	case 'N':
		phoneticVersion = "November";
		break;
	case 'O':
		phoneticVersion = "Oscar";
		break;
	case 'P':
		phoneticVersion = "Papa";
		break;
	case 'Q':
		phoneticVersion = "Quebec";
		break;
	case 'R':
		phoneticVersion = "Romeo";
		break;
	case 'S':
		phoneticVersion = "Sierra";
		break;
	case 'T':
		phoneticVersion = "Tango";
    	break;
	case 'U':
		phoneticVersion = "Uniform";
		break;
	case 'V':
		phoneticVersion = "Victor";
		break;
	case 'W':
		phoneticVersion = "Whiskey";
		break;
	case 'X':
		phoneticVersion = "X-ray";
		break;
	case 'Y':
		phoneticVersion = "Yankee";
		break;
	case 'Z':
		phoneticVersion = "Zulu";
		break;
	default:
		break;
	}
	return phoneticVersion;
}