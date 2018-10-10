/*
Name: Amber Rivera
Chapter: 6
Exercise: 6

This program:
1. Prompts user for the path to songs.dat file.
2. Reads, calculates, and prints times for each song as well as total time.
3. Calculates and prints remaining time on an 80 minute CD.
*/

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

void printSongTimes(string filePath);
void printSongsTableHeader();
int convertSecondsToMinutes(int seconds);
int getRemainingSeconds(int seconds);
int calculateTimeRemaining(int seconds);

int main() {
	// Get file path to songs.dat
	string filePath;
	cout << "Please input the path to 'songs.dat' (ex. C:\\data): ";
	cin >> filePath;
	cout << endl << endl;
	// Print songs table
	printSongTimes(filePath);
	cin.get();
	cin.get();
	return 0;
}

void printSongTimes(string filePath) {
	// Initialize variables to track song, total, and remaining minutes and seconds.
	int minutes = 0;
	int seconds = 0;
	int totalTimeInSeconds = 0;
	int totalMinutes = 0;
	int totalSeconds = 0;
	int songMinutes = 0;
	int songSeconds = 0;
	int songNumber = 1;
	int remainingMinutes = 0;
	int remainingSeconds = 0;

	ifstream songsInFile;

	// Open songs.dat
	songsInFile.open(filePath + "\\songs.dat");

	// Exit if songs.dat is not found.
	if (songsInFile.fail()) {
		cout << "The file " << filePath << "songs.dat could not be found.";
		return;
	}

	// Print header for songs table.
	printSongsTableHeader();

	// Primer read
	songsInFile >> seconds;

	while (songsInFile) {
		// Track total time
		totalTimeInSeconds += seconds;
		// Calculate song minutes and seconds.
		songMinutes = convertSecondsToMinutes(seconds);
		songSeconds = getRemainingSeconds(seconds);
		// Calculate total minutes and seconds.
		totalMinutes = convertSecondsToMinutes(totalTimeInSeconds);
		totalSeconds = getRemainingSeconds(totalTimeInSeconds);
		// Print row for song.
		cout << setw(3) << songNumber << setw(10) << songMinutes << setw(10) << songSeconds << setw(10) << totalMinutes << setw(10) << totalSeconds << endl;
		// Increment song number.
		songNumber++;
		// Get next record.
		songsInFile >> seconds;
	}
	// Calculate and print remaining time.
	remainingSeconds = calculateTimeRemaining(totalTimeInSeconds);
	remainingMinutes = convertSecondsToMinutes(remainingSeconds);
	remainingSeconds = getRemainingSeconds(remainingSeconds);
	cout << "There are " << remainingMinutes << " minutes and " << remainingSeconds << " seconds of space left on the 80-minute CD." << endl;

	// Close songs.dat
	songsInFile.close();

}

int convertSecondsToMinutes(int seconds) {
	return seconds / 60;
}

int getRemainingSeconds(int seconds) {
	return seconds % 60;
}

int calculateTimeRemaining(int seconds) {
	return 4800 - seconds;
}

void printSongsTableHeader() {
	cout << setw(6) << "Song" << setw(18) << "Song Time" << setw(18) << "Total Time" << endl;
	cout << setw(6) << "Number" << setw(10) << "Minutes" << setw(10) << "Seconds" << setw(10) << "Minutes" << setw(10) << "Seconds" << endl;
	cout << setw(6) << "------" << setw(10) << "-------" << setw(10) << "-------" << setw(10) << "-------" << setw(10) << "-------" << endl;
}