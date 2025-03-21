/** \file main.cpp
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
/**
 * If not symbol is provided, this symbol will be used as default symbol
 */
const char DEFAULT_SYMBOL = 'X';
/**
 * Maximum length of the shape
 */
const int MAX_SHAPE_LENGTH = 20;
/**
 * Minimum length of the shape
 */
const int MIN_SHAPE_LENGTH = 5;

// Function prototype
void drawArrays(const int*, const int*, const char*, const int);
void drawHorizontalLine(const int, const char = DEFAULT_SYMBOL);
void drawVerticalLine(const int, const char = DEFAULT_SYMBOL);
void drawSquare(const int, const char = DEFAULT_SYMBOL);
void drawSquareFilled(const int, const char = DEFAULT_SYMBOL);
void drawRectangle(const int, const int, const char = DEFAULT_SYMBOL);
void drawRectangleFilled(const int, const int, const char = DEFAULT_SYMBOL);
void drawShapes(const int);
void drawShapeBasedOnType(const int, const int, const char);
void initializeArrays(int*, int*, char*, const int);
void showMenu();

/**
 * Driver of the application
 * @return 0
 */
int main() {
    const int ARRAY_SIZE = 10, MAX_SHAPES = 10;

    char symbol, shapeSymbol[ARRAY_SIZE];
    int choice, length, shapeType[ARRAY_SIZE], shapeLength[ARRAY_SIZE];

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
            // Initialize arrays and draw shapes from them
            initializeArrays(shapeType, shapeLength, shapeSymbol, ARRAY_SIZE);
            drawArrays(shapeType, shapeLength, shapeSymbol, ARRAY_SIZE);
        } else if (choice == 9) {
            // No code is needed here
        } else {
            cerr << "Wrong choice, buddy!" << "\n";
        }
    } while (choice != 9);

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
    cout << "8) Draw shapes from arrays" << "\n";
    cout << "9) Quit" << "\n";
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

    char shapeCharacter;
    int shapeLength, shapeType;

    cout << "Draws " << numShapes << " random shapes" << "\n";

    for (int i = 0; i < numShapes; i++) {
        shapeType = rand() % 6 + 1;
        shapeLength = MIN_SHAPE_LENGTH + rand() % (MAX_SHAPE_LENGTH - MIN_SHAPE_LENGTH + 1);
        shapeCharacter = 33 + (rand() % (126 - 33)); // Printable ASCII chars

        drawShapeBasedOnType(shapeType, shapeLength, shapeCharacter);
        cout << "\n";
    }
}

/**
 * Fills array shapeType with values 1 - 6, shapeLength with values 5 - 20 , and shapeSymbol with values 33 - 126
 * @param shapeType[] Array of shape types
 * @param shapeLength[] Array of shape lengths
 * @param shapeSymbol[] Array of shape symbols
 * @param arraySize Size of the arrays
 */
void initializeArrays(int* shapeType, int* shapeLength, char* shapeSymbol, const int arraySize) {
    assert(arraySize > 0);

    for (int i = 0; i < arraySize; i++) {
        shapeType[i] = rand() % 6 + 1;
        shapeLength[i] = MIN_SHAPE_LENGTH + rand() % (MAX_SHAPE_LENGTH - MIN_SHAPE_LENGTH + 1);
        shapeSymbol[i] = 33 + (rand() % (126 - 33)); // Printable ASCII chars
    }
}

/**
 * Draws shapes based on the values in the arrays
 * @param shapeType[] Array of shape types
 * @param shapeLength[] Array of shape lengths
 * @param shapeSymbol[] Array of shape symbols
 * @param arraySize Size of the arrays
 */
void drawArrays(const int* shapeType, const int* shapeLength, const char* shapeSymbol, const int arraySize) {
    assert(arraySize > 0);

    cout << "Draws " << arraySize << " shapes from array" << "\n";

    for (int i = 0; i < arraySize; i++) {
        drawShapeBasedOnType(shapeType[i], shapeLength[i], shapeSymbol[i]);
        cout << "\n";
    }
}

/**
 * Draws a shape based on the type
 * @param shapeType The type of the shape
 * @param shapeLength The length of the shape
 * @param shapeSymbol The symbol of the shape
 */
void drawShapeBasedOnType(const int shapeType, const int shapeLength, const char shapeSymbol) {
    assert(shapeType > 0 && shapeType < 7);
    assert(shapeLength > 0);

    switch (shapeType) {
    case 1:
        drawHorizontalLine(shapeLength, shapeSymbol);
        break;
    case 2:
        drawVerticalLine(shapeLength, shapeSymbol);
        break;
    case 3:
        drawSquare(shapeLength, shapeSymbol);
        break;
    case 4:
        drawSquareFilled(shapeLength, shapeSymbol);
        break;
    case 5:
        drawRectangle(shapeLength * 2, shapeLength, shapeSymbol);
        break;
    case 6:
        drawRectangleFilled(shapeLength * 2, shapeLength, shapeSymbol);
        break;
    default:
        cerr << "WARNING: should not happen!!!" << "\n";
        assert(false);
        break;
    }
}
