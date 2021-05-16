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
#include "Shapes.h"
#include <iostream>
using namespace std;

int main() {
	return 0;
}

void drawHorizontalLine(const int length, const char ch) {
	cout << "\nDraw horizontal line\n\n";
	for (int i = 0; i < length; ++i)
		cout << ch;
	cout << endl;
	cout << "\nI am drawHorizontalLine";
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
