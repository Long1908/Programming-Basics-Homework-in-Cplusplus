// УП Домашно 2-Задача 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
using std::cout;
using std::cin;
using std::endl;

void enterNumbers(char*& number1, char*& number2)
{
    do
    {
        cin.getline(number1, 8193);
        cin.getline(number2, 8193);
    } while ((strlen(number1) >= 8193) && (strlen(number2) >= 8193));

}

void printNumbers(char* number1, char* number2)
{
    cout << number1 << endl;
    cout << number2 << endl;
}

int main()
{
    char* number1 = new char[8193];
    char* number2 = new char[8193];

    enterNumbers(number1, number2);
    printNumbers(number1, number2);

    delete[] number1;
    delete[] number2;
}
