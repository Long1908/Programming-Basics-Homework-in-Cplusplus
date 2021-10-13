// УП-Домашно 1-Задача 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	double x1, y1, w1, h1; // Coordinates, width and height for rectangle 1
	double x2, y2, w2, h2; // Coordinates, width and height for rectangle 2
	double S; // Area of the intersection of the rectangles

	cin >> x1 >> y1 >> w1 >> h1; // Entering coordinates, width and height for rectangle 1
	cin >> x2 >> y2 >> w2 >> h2; // Entering coordinates, width and height for rectangle 2

	//Bellow on the first 'if' we will check if the two rectangles intersect 
	if  ((x1 > x2 && x1 >= x2 + w2) ||
		(x2 > x1 && x2 >= x1 + w1) ||
		(y1 > y2 && y1 >= y2 + h2) ||
		(y2 > y1 && y2 >= y1 + h1))
	{
		S = 0; // There is no intersection between the two rectangles so logically the area is equal to 0
	}
	else
	{
		if (x2 > x1)
		{
			if (y2 > y1)
			{
				S = abs(abs((x1 + w1) - (x2 + w2)) - w2) * abs(abs((y1 + h1) - (y2 + h2)) - h2);
			}
			else if (y1 > y2)
			{
				S = abs(abs((x1 + w1) - (x2 + w2)) - w2) * abs(abs((y1 + h1) - (y2 + h2)) - h1);
			}
		}
		else if (x1 > x2)
		{
			if (y2 > y1)
			{
				S = abs(abs((x1 + w1) - (x2 + w2)) - w1) * abs(abs((y1 + h1) - (y2 + h2)) - h2);
			}
			else if (y1 > y2)
			{
				S = abs(abs((x1 + w1) - (x2 + w2)) - w1) * abs(abs((y1 + h1) - (y2 + h2)) - h1);
			}
		}
	}
	cout << S;
}
