/**
 * \file main.cpp
 * \brief This file contains small drawing program
 * \details This program draw shorizontal and vertical lines, squares, rectangles
 * \author Nurlan Suyundukov
 * \version 0.0.1
 * \date 28/02/2025
 * \copyright University of Nicosia
 */
#include <cassert>
#include <iostream>
#include <iomanip>

using namespace std;

// Global variables
const char DEFAULT_SYMBOL = 'X';

// Function prototype
void drawHorizontalLine(const int, const char = DEFAULT_SYMBOL);
void drawVerticalLine(const int, const char = DEFAULT_SYMBOL);
void drawSquare(const int, const char = DEFAULT_SYMBOL);
void drawSquareFilled(const int, const char = DEFAULT_SYMBOL);
void drawRectangle(const int, const int, const char = DEFAULT_SYMBOL);
void drawRectangleFilled(const int, const int, const char = DEFAULT_SYMBOL);
void drawShapes(const int);
void showMenu();

/**
 * Driver of the application
 * @return 0
 */
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

/**
 * Shows the menu options to the user
 */
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

/**
 * Draws a horizontal line, given a length and a symbol
 * @param length The length of the line
 * @param symbol The symbol to be used for the line
 */
void drawHorizontalLine(const int length, const char symbol) {
    assert(length > 0);

    for (int i = 0; i < length; i++) {
        cout << symbol;
    }

    cout << "\n";
}

/**
 * Draws a vertical line, given a length and a symbol
 * @param length The length of the line
 * @param symbol The symbol to be used for the line
 */
void drawVerticalLine(const int length, const char symbol) {
    assert(length > 0);

    for (int i = 0; i < length; i++) {
        cout << symbol << "\n";
    }
}

/**
 * Draws a rectangle, given a height, width and a symbol
 * @param height The height of the rectangle
 * @param width The width of the rectangle
 * @param symbol The symbol to be used for the rectangle
 */
void drawRectangle(const int height, const int width, const char symbol) {
    assert(height > 0 && width > 0);

    drawHorizontalLine(width, symbol);
    for (int i = 0; i < height - 2; i++) {
        cout << symbol << setw(width - 1) << symbol << "\n";
    }
    drawHorizontalLine(width, symbol);
}

/**
 * Draws a filled rectangle, given a height, width and a symbol
 * @param height The height of the rectangle
 * @param width The width of the rectangle
 * @param symbol The symbol to be used for the rectangle
 */
void drawRectangleFilled(const int height, const int width, const char symbol) {
    assert(height > 0 && width > 0);

    for (int i = 0; i < height; i++) {
        drawHorizontalLine(width, symbol);
    }
}

/**
 * Draws a square, given a length and a symbol
 * @param length The length of the square
 * @param symbol The symbol to be used for the square
 */
void drawSquare(const int length, const char symbol) {
    assert(length > 0);

    drawRectangle(length, length, symbol);
}

/**
 * Draws a filled square, given a length and a symbol
 * @param length The length of the square
 * @param symbol The symbol to be used for the square
 */
void drawSquareFilled(const int length, const char symbol) {
    assert(length > 0);

    drawRectangleFilled(length, length, symbol);
}

/**
 * Draws a number of random shapes
 * @param numShapes The number of shapes to draw
 */
void drawShapes(const int numShapes) {
    assert(numShapes > 0);

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
            assert(false);
            break;
        }

        cout << "\n";
    }
}
