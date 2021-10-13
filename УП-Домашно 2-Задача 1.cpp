// УП-Домашно 2-Задача 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void enterDataForTheBoard(int &height, int &width)
{
	do
	{
		cin >> height >> width;
		if (height < 4)
			cout << "Your height is too low" << endl;
		if (height > 20)
			cout << "Your height is too high" << endl;
		if (width < 4)
			cout << "Your width is too low" << endl;
		if (width > 40)
			cout << "Your width is too high" << endl;
	} while ((height < 4 || height > 20) || (width < 4 || width > 40));
}

void deleteBoard(char**& board, int height, int width)
{
	for (size_t i = 0; i < height; ++i)
	{
		delete[] board[i];
	}
	delete[] board;
}
void createBoard(char**& board, int height, int width)
{
	for (size_t i = 0; i < height; ++i)
	{
		board[i] = new char[width];
	}
}

void fillBoard(char**& board, int height, int width)
{
	for (size_t i = 0; i < height; ++i)
	{
		for (size_t j = 0; j < width; ++j)
		{
			board[i][j] = ' ';
		}
	}
}

void printBoard(char** board, int height, int width)
{
	for (size_t i = 0; i < height; ++i)
	{
		for (size_t j = 0; j < width; ++j)
		{
			if (j == 0)
				cout << "|";
			cout << board[i][j] << "|";
			if (j == width - 1)
				cout << endl;
		}
	}
}

int checkDown(char** board, int row, int move, int height, int width, char symbol, int counterForSameSymbol)
{
	if (board[row][move] == symbol)
	{
		counterForSameSymbol += 1;
		if (counterForSameSymbol == 3)
		{
			cout << "We have a winner!" << endl;
			return 0;
		}
		else
		{
			return checkDown(board, ++row, move, height, width, symbol, counterForSameSymbol);
		}
	}
}

int checkLeft(char** board, int row, int move, int height, int width, char symbol, int counterForSameSymbol)
{
	if (board[row][move] == symbol)
	{
		counterForSameSymbol += 1;
		if (counterForSameSymbol == 3)
		{
			cout << "We have a winner!" << endl;
			return 0;
		}
		else
		{
			return checkLeft(board, row, --move, height, width, symbol, counterForSameSymbol);
		}
	}
}

int checkRight(char** board, int row, int move, int height, int width, char symbol, int counterForSameSymbol)
{
	if (board[row][move] == symbol)
	{
		counterForSameSymbol += 1;
		if (counterForSameSymbol == 3)
		{
			cout << "We have a winner!" << endl;
			return 0;
		}
		else
		{
			return checkRight(board, row, ++move, height, width, symbol, counterForSameSymbol);
		}
	}
}
int checkDownLeft(char** board, int row, int move, int height, int width, char symbol, int counterForSameSymbol)
{
	if (board[row][move] == symbol)
	{
		counterForSameSymbol += 1;
		if (counterForSameSymbol == 3)
		{
			cout << "We have a winner!" << endl;
			return 0;
		}
		else
		{
			return checkDownLeft(board, ++row, --move, height, width, symbol, counterForSameSymbol);
		}
	}
}
int checkDownRight(char** board, int row, int move, int height, int width, char symbol, int counterForSameSymbol)
{
	if (board[row][move] == symbol)
	{
		counterForSameSymbol += 1;
		if (counterForSameSymbol == 3)
		{
			cout << "We have a winner!" << endl;
			return 0;
		}
		else
		{
			return checkDownRight(board, ++row, ++move, height, width, symbol, counterForSameSymbol);
		}
	}
}
int checkUpRight(char** board, int row, int move, int height, int width, char symbol, int counterForSameSymbol)
{
	if (board[row][move] == symbol)
	{
		counterForSameSymbol += 1;
		if (counterForSameSymbol == 3)
		{
			cout << "We have a winner!" << endl;
			return 0;
		}
		else
		{
			return checkUpRight(board, --row, ++move,  height, width, symbol, counterForSameSymbol);
		}
	}
}

int checkUpLeft(char** board, int row, int move, int height, int width, char symbol, int counterForSameSymbol)
{
	if (board[row][move] == symbol)
	{
		counterForSameSymbol += 1;
		if (counterForSameSymbol == 3)
		{
			cout << "We have a winner!" << endl;
			return 0;
		}
		else
		{
			return checkUpLeft(board, --row, --move, height, width, symbol, counterForSameSymbol);
		}
	}
}

void checkForWinner(char** board, int row, int move, int height, int width, char symbol, int counterForSameSymbol)
{
	int rowContainer = row;
	int moveContainer = move;
	if (row + 3 < height)
		checkDown(board, ++row, move, height, width, symbol, counterForSameSymbol);
	row = rowContainer;
	move = moveContainer;
	if (move - 3 >= 0)
		checkLeft(board, row, --move, height, width, symbol, counterForSameSymbol);
	row = rowContainer;
	move = moveContainer;
	if (move + 3 < width)
		checkRight(board, row, ++move, height, width, symbol, counterForSameSymbol);
	row = rowContainer;
	move = moveContainer;
	if ((row + 3 < height) && (move - 3 >= 0))
		checkDownLeft(board, ++row, --move, height, width, symbol, counterForSameSymbol);
	row = rowContainer;
	move = moveContainer;
	if ((row + 3 < height) && (move + 3 < width))
		checkDownRight(board, ++row, ++move, height, width, symbol, counterForSameSymbol);
	row = rowContainer;
	move = moveContainer;
	if ((row - 3 >= 0) && (move + 3 < width))
		checkUpRight(board, --row, ++move, height, width, symbol, counterForSameSymbol);
	row = rowContainer;
	move = moveContainer;
	if ((row - 3 >= 0) && (move + 3 < width))
		checkUpLeft(board, --row, --move, height, width, symbol, counterForSameSymbol);
	row = rowContainer;
	move = moveContainer;
}


int main()
{
	int height, width , row;
	int counterForSameSymbol = 0;
	bool gameOver = false;
	bool successfulMove = false;
	int player = 1;
	int move;
	char symbol;

	enterDataForTheBoard(height, width);

	char** board = new char*[height];
	createBoard(board, height, width);
	fillBoard(board, height, width);
	printBoard(board, height, width);
	
	do
	{
		if (player == 1)
		{
			cout << "Player 1: Please enter your move: ";
			cin >> move;
			row = height - 1;
			move = move - 1;
			successfulMove = false;
			do
			{
				if (board[row][move] == ' ')
				{
					symbol = 'X';
					board[row][move] = symbol;
					printBoard(board, height, width);
					successfulMove = true;
					checkForWinner(board, row, move, height, width, symbol, counterForSameSymbol);
					player = 2;

				}
				else
				{
					if (row >= 1)
						row = --row;
					else
					{
						cout << "There is no more room in this row. " << endl;
						break;
					}
				}

			} while (!successfulMove);
		}
		else if (player == 2)
		{
			cout << "Player 2: Please enter your move: ";
			cin >> move;
			row = height - 1;
			move = move - 1;
			successfulMove = false;
			do
			{
				if (board[row][move] == ' ')
				{
					symbol = 'O';
					board[row][move] = symbol;
					printBoard(board, height, width);
					successfulMove = true;
					checkForWinner(board, row, move, height, width, symbol, counterForSameSymbol);
					player = 1;
				}
				else
				{
					if (row >= 1)
						row = --row;
					else
					{
						cout << "There is no more room in this row. " << endl;
						break;
					}
				}

			} while (!successfulMove);
		}
	} while (!gameOver);
	deleteBoard(board, height, width);

	return 0;
}
