// main.cpp : This file contains small drawing program
// Date: 28/02/2025
// Author: Nurlan Suyundukov
#include <iostream>

using namespace std;

// Global variables
const char DEFAULT_SYMBOL = 'X';

// Function prototype
void drawHorizontalLine(int, char = DEFAULT_SYMBOL);
void drawVerticalLine(int, char = DEFAULT_SYMBOL);
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
            // Draw a horizontal line
            char symbol;
            int length;

            cout << "Give me the length of the line: ";
            cin >> length;
            cout << "Give me the symbol: ";
            cin >> symbol;

            drawHorizontalLine(length, symbol);
        } else if (choice == 2) {
            // Draw a vertical line
            char symbol;
            int length;

            cout << "Give me the length of the line: ";
            cin >> length;
            cout << "Give me the symbol: ";
            cin >> symbol;

            drawVerticalLine(length, symbol);
        } else if (choice == 3) {

        } else if (choice == 4) {

        } else if (choice == 5) {

        } else if (choice == 6) {

        } else if (choice == 7) {
            // No code is needed here
        } else {
            cerr << "Wrong choice, buddy!" << "\n";
        }
    } while (choice != 7);

    cout << "Have a nice day, pal, ^^" << "\n";

    return 0;
}

// Show the menu options to the user
void showMenu() {
    cout << "1) Draw a horizontal line" << "\n";
    cout << "2) Draw a vertical line" << "\n";
    cout << "3) Draw a square" << "\n";
    cout << "4) Draw a square filled" << "\n";
    cout << "5) Draw a rectangle" << "\n";
    cout << "6) Draw a rectangle filled" << "\n";
    cout << "7) Quit" << "\n";
}

// Draw a horizontal line
void drawHorizontalLine(int length, char symbol) {
    for (int i = 0; i < length; i++) {
        cout << symbol;
    }
    cout << "\n";
}

// Draw a vertical line
void drawVerticalLine(int length, char symbol) {
    for (int i = 0; i < length; i++) {
        cout << symbol << "\n";
    }
}
