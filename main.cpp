// main.cpp : This file contains small drawing program
// Date: 28/02/2025
// Author: Nurlan Suyundukov
#include <iostream>
#include <iomanip>

using namespace std;

// Global variables
const char DEFAULT_SYMBOL = 'X';

// Function prototype
void drawHorizontalLine(int, char = DEFAULT_SYMBOL);
void drawVerticalLine(int, char = DEFAULT_SYMBOL);
void drawSquare(int, char = DEFAULT_SYMBOL);
void drawSquareFilled(int, char = DEFAULT_SYMBOL);
void drawRectangle(int, int, char = DEFAULT_SYMBOL);
void drawRectangleFilled(int, int, char = DEFAULT_SYMBOL);
void showMenu();

// Driver of the application
int main() {
    char symbol;
    int choice, length;

    do {
        // Show menu
        showMenu();

        // Get user's choice
        cout << "Enter your choice: ";
        cin >> choice;

        // Handle user's choice
        if (choice == 1) {
            // Draw a horizontal line
            do {
                cout << "Give me the length of the line: ";
                cin >> length;
                if (length < 1) {
                  cerr << "Length must be greater than 0" << "\n";
                }
            } while (length < 1);
            cout << "Give me the symbol: ";
            cin >> symbol;

            drawHorizontalLine(length, symbol);
        } else if (choice == 2) {
            // Draw a vertical line
            do {
                cout << "Give me the length of the line: ";
                cin >> length;
                if (length < 1) {
                    cerr << "Length must be greater than 0" << "\n";
                }
            } while (length < 1);
            cout << "Give me the symbol: ";
            cin >> symbol;

            drawVerticalLine(length, symbol);
        } else if (choice == 3) {
            // Draw a square
            do {
                cout << "Give me the length of the square: ";
                cin >> length;
                if (length < 1) {
                    cerr << "Length must be greater than 0" << "\n";
                }
            } while (length < 1);
            cout << "Give me the symbol: ";
            cin >> symbol;

            drawSquare(length, symbol);
        } else if (choice == 4) {
            // Draw a square filled
            do {
                cout << "Give me the length of the square: ";
                cin >> length;
                if (length < 1) {
                    cerr << "Length must be greater than 0" << "\n";
                }
            } while (length < 1);
            cout << "Give me the symbol: ";
            cin >> symbol;

            drawSquareFilled(length, symbol);
        } else if (choice == 5) {
            // Draw a rectangle
            int height, width;

            do {
                cout << "Give me the height of the rectangle: ";
                cin >> height;
                cout << "Give me the width of the rectangle: ";
                cin >> width;
                if (height < 1 || width < 1) {
                    cerr << "Rectangle's dimensions must be greater than 0" << "\n";
                }
            } while (height < 1 || width < 1);
            cout << "Give me the symbol: ";
            cin >> symbol;

            drawRectangle(height, width, symbol);
        } else if (choice == 6) {
            // Draw a rectangle filled
            int height, width;

            do {
                cout << "Give me the height of the rectangle: ";
                cin >> height;
                cout << "Give me the width of the rectangle: ";
                cin >> width;
                if (height < 1 || width < 1) {
                    cerr << "Rectangle's dimensions must be greater than 0" << "\n";
                }
            } while (height < 1 || width < 1);
            cout << "Give me the symbol: ";
            cin >> symbol;

            drawRectangleFilled(height, width, symbol);
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

// Draw a square
void drawSquare(int length, char symbol) {
    drawHorizontalLine(length, symbol);
    for (int i = 0; i < length - 2; i++) {
        cout << symbol << setw(length - 1) << symbol << "\n";
    }
    drawHorizontalLine(length, symbol);
}

// Draw a square filled
void drawSquareFilled(int length, char symbol) {
    for (int i = 0; i < length; i++) {
        drawHorizontalLine(length, symbol);
    }
}

// Draw a rectangle
void drawRectangle(int height, int width, char symbol) {
    drawHorizontalLine(width, symbol);
    for (int i = 0; i < height - 2; i++) {
        cout << symbol << setw(width - 1) << symbol << "\n";
    }
    drawHorizontalLine(width, symbol);
}

// Draw a rectangle filled
void drawRectangleFilled(int height, int width, char symbol) {
    for (int i = 0; i < height; i++) {
        drawHorizontalLine(width, symbol);
    }
}
