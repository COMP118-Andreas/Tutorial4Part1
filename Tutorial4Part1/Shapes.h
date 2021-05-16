/**  \file       Lab1.cpp
  *  \brief      Small program that draws shapes. User can choice their size and the
  *              characters used to implement these shapes.
  *  \details    The program can draw a horizontal line, a vertical line, a square, a
  *              rectangle, initialize arrays by drawing completely random shapes based on
  *              some functions, and it can also calculate the area of a circle, given the radius.
  *  \author     Andreas Solomou
  *  \version    0.1
  *  \date       2020-2020
  *  \copyright  University of Nicosia.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cmath>
using namespace std;
// Function prototypes
const int MAX_ARRAY = 10;

/**
 * Function <code>main</code> is the starting point.
 * <BR>
 * @return Returns <code>0</code>.
 */
int main() {
	srand(time(NULL));
	int choice;
	int randomValue = rand() % 100;           // Random number in range 0-99
	char shapeCh[MAX_ARRAY];
	int shapeTy[MAX_ARRAY], shapeLen[MAX_ARRAY], shapeHeight[MAX_ARRAY], shapeSize[MAX_ARRAY];
	double calculateArea;

	do {
		// Show menu
		cout << "\t\t === MENU === \t\t\n";
		cout << "\n1) Draw a horizontal line";
		cout << "\n2) Draw a vertical line";
		cout << "\n3) Draw a square";
		cout << "\n4) Draw a rectangle";
		cout << "\n5) Draw random shapes";
		cout << "\n6) Calculate the area of a circle";
		cout << "\n7) Quit";
		// User's choice
		cout << "\nEnter choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			int len;
			char ch;
			cout << "\nEnter length: ";
			cin >> len;
			cout << "\nEnter symbol: ";
			cin >> ch;
			drawHorizontalLine(len, ch);
			break;
		case 2:
			int h;                      // h = height
			char ch1;
			cout << "\nEnter height: ";
			cin >> h;
			cout << "\nEnter symbol: ";
			cin >> ch1;
			drawVerticalLine(h, ch1);
			break;
		case 3: int size; char ch2;
			cout << "\nEnter size of square: ";
			cin >> size;
			cout << "\nEnter symbol: ";
			cin >> ch2;
			drawSquare(size, ch2);
			break;
		case 4:
			cout << "\nEnter length: ";
			cin >> len;
			cout << "\nEnter height: ";
			cin >> h;
			cout << "\nEnter symbol: ";
			cin >> ch;
			drawRectangle(len, h, ch);
			break;
		case 5:
			initializeArrays(shapeTy, shapeLen, shapeCh, MAX_ARRAY);
			drawShapes(shapeTy, shapeLen, shapeCh, MAX_ARRAY, shapeHeight, shapeSize);
			break;
		case 6:
			double radius;
			cout << "\nEnter radius: ";
			cin >> radius;
			calculateArea = calAreaOfCircle(radius);
			cout << "The area of this circle is: " << calculateArea << endl;
		case 7:
			break;
			// In case 7 the program just quits
		default:
			cout << "\nWrong choice!!";
			break;
		}


	} while (choice != 7);             // While the choice is NOT 1-7, the loop stops and the program shows the following error message:

	cout << "\nGood Bye!\n";

	return 0;
}
/**
 * Function <code>drawHorizontalLine</code> draws a horizontal line of the
   given length and symbol.
 * <BR>
 * @param length Is the length of the line to be drawn.
 * @param ch The character used as the symbol of the line.
 */
void drawHorizontalLine(const int length, const char ch) {
	cout << "\nDraw horizontal line\n\n";
	for (int i = 0; i < length; ++i)
		cout << ch;
	cout << endl;
	cout << "\nI am drawHorizontalLine";
}
/**
 * Function <code>drawVerticalLine</code> draws a vertical line of the
   given height and symbol.
 * <BR>
 * @param height Is the height of the line to be drawn.
 * @param ch The character used as the symbol of the line.
 */
void drawVerticalLine(const int height, const char ch) {
	cout << "\nDraw vertical line\n\n";
	for (int i = 0; i < height; ++i) {
		cout << ch;
		cout << endl;
	} cout << endl;
	cout << "\nI am drawVerticalLine";
}
/**
 * Function <code>drawSqaure</code> draws a square of the given
   size and symbol.
 * <BR>
 * @param size Is the size of the square to be drawn.
 * @param ch The character used as the symbol of the square lines.
 */
void drawSquare(const int size, const char ch) {
	cout << "\nDraw a square\n\n";
	for (int i = 0; i < size; ++i) {              // i = rows
		for (int j = 0; j < size; ++j) {          // j = columns
			if ((i == 0) || (i == (size - 1)))
				cout << ch;
			else if ((j == 0) || (j == (size - 1)))
				cout << ch;
			else
				cout << " ";
		} cout << endl;
		cout << "\nI am drawSquare";
	}
}

/**
 * Function <code>drawRectangle</code> draws a rectangle of the given
   length, height and symbol.
 * <BR>
 * @param length Is the length of the rectangle's line to be drawn.
 * @param height Is the height of the rectangle's line to be drawn.
 * @param ch The character used as the symbol of the lines.
 */
void drawRectangle(const int length, const int height, const char ch) {
	cout << "\nDraw a rectangle\n\n";
	for (int i = 0; i < length; ++i) {              // i = rows/length
		for (int j = 0; j < height; ++j) {          // j = columns/height
			if ((i == 0) || (i == (length - 1)))
				cout << ch;
			else if ((j == 0) || (j == (height - 1)))
				cout << ch;
			else
				cout << " ";
		} cout << endl;
	}
	cout << "\nI am drawRectangle";
}
/**
 * Function <code>initializeArrays</code> initializes 3 arrays (shapeTy[],
   shapeLen[], shapeCh[]) with some specific random values.
 * <BR>
 * @param shapeTy[] Is the type of the random shape to be drawn.
 * @param shapeLen[] Is the length of the random shape to be drawn.
 * @param shapeCh[] The character used as the symbol of the lines to be drawn.
 * @param size Is the number of shapes.
 */
void initializeArrays(int shapeTy[], int shapeLen[], char shapeCh[], const int size) {
	for (int i = 0; i < size; ++i) {
		shapeTy[i] = 1 + rand() % 4;         // indicating which type of shape to print
		shapeLen[i] = 1 + rand() % 20;       // shape length
		shapeCh[i] = 26 + rand() % 100;      // ASCII table values (>=26)
	}
}
/**
 * Function <code>drawShapes</code> draws some random shapes, which
   have random dimensions and characters, based on user's choice.
 * <BR>
 * @param shapeTy[] Is the type of the random shape to be drawn.
 * @param shapeLen[] Is the length of the random shape to be drawn.
 * @param shapeCh[] The character used as the symbol of the lines to be drawn.
 * @param size Is the number of shapes.
 * @param shapeHeight[] Is the height of the random shape to be drawn.
 * @param shapeSize[] Is the size of the random shape to be drawn, in case it
		  has two dimensions.
 */
void drawShapes(const int shapeTy[], const int shapeLen[], const char shapeCh[], const int size, const int shapeHeight[], const int shapeSize[]) {
	for (int i = 0; i < size; ++i) {
		if (shapeTy[i] == 1)
			drawHorizontalLine(shapeLen[i], shapeCh[i]);
		else if (shapeTy[i] == 2)
			drawVerticalLine(shapeHeight[i], shapeCh[i]);
		else if (shapeTy[i] == 3)
			drawSquare(shapeSize[i], shapeCh[i]);
		else if (shapeTy[i] == 4)
			drawRectangle(shapeLen[i], shapeHeight[i], shapeCh[i]);
	}
}
/**
 * Function <code>calAreaOfCircle</code> shows us an example of using
 * cassert library for pre-condition and post-condition tests inside
 * our functions, so we have as least bugs as we can.
 * <BR>
 * @param radius Is the radius of the circle.
 * @return Returns res, which is a circle's area.
 */
double calAreaOfCircle(const double radius) {
	const double PI = 3.1415;
	double res;
	assert(radius > 0); // Pre condition
	res = PI * pow(radius, 2.0);
	assert(res > 0); // Post condition
	return res;
#pragma once
