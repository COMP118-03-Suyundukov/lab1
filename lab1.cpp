// lab1.cpp : This file contains small drawing program
// Date: 28/02/2025
// Author: Nurlan Suyundukov
#include <iostream>

using namespace std;

// Global variables

// Function prototype
void drawHorizontalLine(int, char);
void drawVerticalLine(int, char);
void drawSquare(int, char);
void drawSquareFilled(int, char);
void drawRectangle(int, int, char);
void drawRectangleFilled(int, int, char);
void showMenu();

// Driver of the application
int main() {
	int choice;

	do {
		// Show menu
		showMenu();

		// Get user's choice
		cout << "Enter your choice: ";
		cin >> choice;

		// Handle user's choice
		if (choice == 1) {

		}
		else if (choice == 2) {

		}
		else if (choice == 3) {

		}
		else if (choice == 4) {

		}
		else if (choice == 5) {

		}
		else if (choice == 6) {

		}
		else if (choice == 7) {
			// No code is needed here
		}
		else {
			cerr << "Wrong choice, buddy!" << endl;
		}
	} while (choice != 7);

	cout << "Have a nice day, pal, ^^" << endl;

	return 0;
}

// Show the menu options to the user
void showMenu() {
	cout << "1) Draw a horizontal line" << endl;
	cout << "2) Draw a vertical line" << endl;
	cout << "3) Draw a square" << endl;
	cout << "4) Draw a square filled" << endl;
	cout << "5) Draw a rectangle" << endl;
	cout << "6) Draw a rectangle filled" << endl;
	cout << "7) Quit" << endl;
}
