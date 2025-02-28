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

// Driver of the application
int main() {
	// Show menu
	cout << "1) Draw a horizontal line" << endl;
	cout << "2) Draw a vertical line" << endl;
	cout << "3) Draw a square" << endl;
	cout << "4) Draw a square filled" << endl;
	cout << "5) Draw a rectangle" << endl;
	cout << "6) Draw a rectangle filled" << endl;
	cout << "7) Quit" << endl;

	cout << "Have a nice day ^^" << endl;
}
