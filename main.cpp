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
void drawShapes(int);
void showMenu();

// Driver of the application
int main() {
    const int MAX_SHAPES = 10;

    char symbol;
    int choice, length;

	srand(static_cast<unsigned int>(time(NULL)));

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
			// Draw random shapes
			int numShapes;
			cout << "Give me number of shapes: ";
			cin >> numShapes;
			drawShapes(numShapes);
        } else if (choice == 8) {
            // No code is needed here
        } else {
            cerr << "Wrong choice, buddy!" << "\n";
        }
    } while (choice != 8);

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
	cout << "7) Draw a random shapes" << "\n";
    cout << "8) Quit" << "\n";
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

// Draw a square
void drawSquare(int length, char symbol) {
    drawRectangle(length, length, symbol);
}

// Draw a square filled
void drawSquareFilled(int length, char symbol) {
    drawRectangleFilled(length, length, symbol);
}

// Draws a number of random shapes, used for automatic testing
void drawShapes(int numShapes) {
    const int MIN_SHAPE_LENGTH = 5;

	char shapeCharacter;
    int shapeLength, shapeType;

	cout << "Draws " << numShapes << " random shapes" << "\n";

    for (int i = 0; i < numShapes; i++) {
        shapeType = rand() % 6 + 1;
        shapeLength = rand() % 16 + MIN_SHAPE_LENGTH;
        shapeCharacter = 33 + (rand() % (126 - 33)); // Printable ASCII chars

        switch (shapeType) {
        case 1:
            drawHorizontalLine(shapeLength, shapeCharacter);
            break;
        case 2:
            drawVerticalLine(shapeLength, shapeCharacter);
            break;
        case 3:
            drawSquare(shapeLength, shapeCharacter);
            break;
        case 4:
            drawSquareFilled(shapeLength, shapeCharacter);
            break;
        case 5:
            drawRectangle(shapeLength * 2, shapeLength, shapeCharacter);
            break;
        case 6:
            drawRectangleFilled(shapeLength * 2, shapeLength, shapeCharacter);
            break;
        default:
            cerr << "WARNING: should not happen!!!" << "\n";
            break;
        }

		cout << "\n";
    }
}
