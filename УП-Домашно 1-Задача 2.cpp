// УП-Домашно 1-Задача 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	int time1, time2 , timeDifference;
	cin >> time1 >> time2;
	bool time1IsValid = false;
	bool time2IsValid = false;
	int hours , minutes ;

	if ((time1 & (1 << 12)) == 0)//12 hour
	{
		//identifying 'hours' and 'minutes' so that we can work with them;
		hours = 0;
		minutes = 0;
		if ((time1 & (1 << 11)) == 0)//in 12hour system the 12th digit can't be 1
			if ((time1 & (1 << 10)) == 0)//if the 11th digit isn't 1, then the hour can be from 0-9;
			{
				if (!((time1 & (1 << 6)) == 0))
					hours += pow(2, 0);
				if (!((time1 & (1 << 7)) == 0))
					hours += pow(2, 1);
				if (!((time1 & (1 << 8)) == 0))
					hours += pow(2, 2);
				if (!((time1 & (1 << 9)) == 0))
					hours += pow(2, 3);
				if (hours <= 9)
				{
					if (!((time1 & (1 << 0)) == 0))
						minutes += pow(2, 0);
					if (!((time1 & (1 << 1)) == 0))
						minutes += pow(2, 1);
					if (!((time1 & (1 << 2)) == 0))
						minutes += pow(2, 2);
					if (!((time1 & (1 << 3)) == 0))
						minutes += pow(2, 3);
					if (!((time1 & (1 << 4)) == 0))
						minutes += pow(2, 4);
					if (!((time1 & (1 << 5)) == 0))
						minutes += pow(2, 5);
					if (minutes <= 59)
					{
						cout << std::setw(2) << std::setfill('0') << hours << ":" << std::setw(2) << std::setfill('0') << minutes << endl;
						time1IsValid = true;
					}
					else//if the minutes are 60 or over, the clock will go over the boundaries
						cout << "Error! Clock 1 won't work!" << endl;
				}
				else//if the hours are 10 or more , the clock will go over the boundaries
					cout << "Error! Clock 1 won't work!" << endl;
			}
			else//the 11th digit is 1, which means it can only be 11:.. or 10:.. (AM)
			{
				hours = 10;//since the 11th digit is 1, that means the hour will be minimally 10;
				if (((time1 & (1 << 9)) == 0) && ((time1 & (1 << 8)) == 0) && ((time1 & (1 << 7)) == 0))//if the 11th digit is 1, then the 10th, 9th and 8th digit need to be 0
				{
					if (!((time1 & (1 << 0)) == 0))
						minutes += pow(2, 0);
					if (!((time1 & (1 << 1)) == 0))
						minutes += pow(2, 1);
					if (!((time1 & (1 << 2)) == 0))
						minutes += pow(2, 2);
					if (!((time1 & (1 << 3)) == 0))
						minutes += pow(2, 3);
					if (!((time1 & (1 << 4)) == 0))
						minutes += pow(2, 4);
					if (!((time1 & (1 << 5)) == 0))
						minutes += pow(2, 5);
					if (minutes <= 59)
					{
						if (!((time1 & (1 << 6)) == 0))
							++hours;
						cout << std::setw(2) << std::setfill('0') << hours << ":" << std::setw(2) << std::setfill('0') << minutes << endl;
						time1IsValid = true;
					}
					else//if the minutes are 60 or over, the clock will go over the boundaries
						cout << "Error! Clock 1 won't work!" << endl;
				}
				else//if some of the given digit - 10th, 9th and 8th , is 1, then we are going over the boundaries of the 12 hour(AM)clock 
					cout << "Error! Clock 1 won't work!" << endl;
			}
		else//if the 12th digit is 1, then we are going over the boundaries of the 12 hour(AM)clock 
			cout << "Error! Clock 1 won't work!" << endl;
	}
	else//24 hour 
	{
		hours = 0;
		minutes = 0;
		
		//first digit of the hour in a 24 hour time
		if (!((time1 & (1 << 10)) == 0))
			hours += pow(2, 0);
		if (!((time1 & (1 << 11)) == 0))
			hours += pow(2, 1);
		hours *= 10; // this makes the number we get from the operation above the first digit
		if (hours <= 20) // the first digit of the hour time cannot exceed 2, which means for now the hour cannot exceed 20
		{
			//second digit of the hour in a 24 hour time
			if (!((time1 & (1 << 6)) == 0))
				hours += pow(2, 0);
			if (!((time1 & (1 << 7)) == 0))
				hours += pow(2, 1);
			if (!((time1 & (1 << 8)) == 0))
				hours += pow(2, 2);
			if (!((time1 & (1 << 9)) == 0))
				hours += pow(2, 3);
			if ((time1 & (1 << 11)) == 0) // if the 12th digit is 0, that means that the second digit can be from 0 to 9
			{
				if (hours <= 19) // the second digit of an hour cannot exceed 9 which means the maximum hour we can get is 19
				{
					//minutes of the 24 hour time
					if (!((time1 & (1 << 0)) == 0))
						minutes += pow(2, 0);
					if (!((time1 & (1 << 1)) == 0))
						minutes += pow(2, 1);
					if (!((time1 & (1 << 2)) == 0))
						minutes += pow(2, 2);
					if (!((time1 & (1 << 3)) == 0))
						minutes += pow(2, 3);
					if (!((time1 & (1 << 4)) == 0))
						minutes += pow(2, 4);
					if (!((time1 & (1 << 5)) == 0))
						minutes += pow(2, 5);
					if (minutes <= 59)//the minutes can't show something over 59 
					{
						time1IsValid = true;
						cout << std::setw(2) << std::setfill('0') << hours << ":" << std::setw(2) << std::setfill('0') << minutes << endl;
					}
					else//if the minutes are 60 or over, the clock will go over the boundaries
						cout << "Error! Clock 1 won't work!" << endl;
				}
				else//if the hours are 10 or more , the clock will go over the boundaries
					cout << "Error! Clock 1 won't work!" << endl;
			}
			else if (!((time1 & (1 << 11)) == 0))//in other case if the 12th digit is 1, that means the first digit of the hour is 2
			{
				if (hours <= 24) // the hour cannot exceed 24
				{
					//minutes of the 24 hour time
					if (!((time1 & (1 << 0)) == 0))
						minutes += pow(2, 0);
					if (!((time1 & (1 << 1)) == 0))
						minutes += pow(2, 1);
					if (!((time1 & (1 << 2)) == 0))
						minutes += pow(2, 2);
					if (!((time1 & (1 << 3)) == 0))
						minutes += pow(2, 3);
					if (!((time1 & (1 << 4)) == 0))
						minutes += pow(2, 4);
					if (!((time1 & (1 << 5)) == 0))
						minutes += pow(2, 5);
					if (minutes <= 59)//the minutes can't show something over 59 
					{
						cout << std::setw(2) << std::setfill('0') << hours << ":" << std::setw(2) << std::setfill('0') << minutes << endl;
						time1IsValid = true;
					}
					else//if the minutes are 60 or over, the clock will go over the boundaries
						cout << "Error! Clock 1 won't work!" << endl;
				}
				else//if the hours are 10 or more , the clock will go over the boundaries
					cout << "Error! Clock 1 won't work!" << endl;
			}
		}
		else
			cout << "Error! Clock 1 won't work!" << endl;
	}

	//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	
	if ((time2 & (1 << 12)) == 0)//12 hour
	{
		//identifying 'hours' and 'minutes' so that we can work with them;
		hours = 0;
		minutes = 0;
		if ((time2 & (1 << 11)) == 0)//in 12hour system the 12th digit can't be 1
			if ((time2 & (1 << 10)) == 0)//if the 11th digit isn't 1, then the hour can be from 0-9;
			{
				if (!((time2 & (1 << 6)) == 0))
					hours += pow(2, 0);
				if (!((time2 & (1 << 7)) == 0))
					hours += pow(2, 1);
				if (!((time2 & (1 << 8)) == 0))
					hours += pow(2, 2);
				if (!((time2 & (1 << 9)) == 0))
					hours += pow(2, 3);
				if (hours <= 9)
				{
					if (!((time2 & (1 << 0)) == 0))
						minutes += pow(2, 0);
					if (!((time2 & (1 << 1)) == 0))
						minutes += pow(2, 1);
					if (!((time2 & (1 << 2)) == 0))
						minutes += pow(2, 2);
					if (!((time2 & (1 << 3)) == 0))
						minutes += pow(2, 3);
					if (!((time2 & (1 << 4)) == 0))
						minutes += pow(2, 4);
					if (!((time2 & (1 << 5)) == 0))
						minutes += pow(2, 5);
					if (minutes <= 59)
					{
						cout << std::setw(2) << std::setfill('0') << hours << ":" << std::setw(2) << std::setfill('0') << minutes << endl;
						time2IsValid = true;
					}
					else//if the minutes are 60 or over, the clock will go over the boundaries
						cout << "Error! Clock 2 won't work!" << endl;
				}
				else//if the hours are 10 or more , the clock will go over the boundaries
					cout << "Error! Clock 2 won't work!" << endl;
			}
			else//the 11th digit is 1, which means it can only be 11:.. or 10:.. (AM)
			{
				hours = 10;//since the 11th digit is 1, that means the hour will be minimally 10;
				if (((time2 & (1 << 9)) == 0) && ((time2 & (1 << 8)) == 0) && ((time2 & (1 << 7)) == 0))//if the 11th digit is 1, then the 10th, 9th and 8th digit need to be 0
				{
					if (!((time2 & (1 << 0)) == 0))
						minutes += pow(2, 0);
					if (!((time2 & (1 << 1)) == 0))
						minutes += pow(2, 1);
					if (!((time2 & (1 << 2)) == 0))
						minutes += pow(2, 2);
					if (!((time2 & (1 << 3)) == 0))
						minutes += pow(2, 3);
					if (!((time2 & (1 << 4)) == 0))
						minutes += pow(2, 4);
					if (!((time2 & (1 << 5)) == 0))
						minutes += pow(2, 5);
					if (minutes <= 59)
					{
						if (!((time2 & (1 << 6)) == 0))
							++hours;
						cout << std::setw(2) << std::setfill('0') << hours << ":" << std::setw(2) << std::setfill('0') << minutes << endl;
						time2IsValid = true;
					}
					else//if the minutes are 60 or over, the clock will go over the boundaries
						cout << "Error! Clock 2 won't work!" << endl;
				}
				else//if some of the given digit - 10th, 9th and 8th , is 1, then we are going over the boundaries of the 12 hour(AM)clock 
					cout << "Error! Clock 2 won't work!" << endl;
			}
		else//if the 12th digit is 1, then we are going over the boundaries of the 12 hour(AM)clock 
			cout << "Error! Clock 2 won't work!" << endl;
	}
	else//24 hour 
	{
		hours = 0;
		minutes = 0;

		//first digit of the hour in a 24 hour time
		if (!((time2 & (1 << 10)) == 0))
			hours += pow(2, 0);
		if (!((time2 & (1 << 11)) == 0))
			hours += pow(2, 1);
		hours *= 10; // this makes the number we get from the operation above the first digit
		if (hours <= 20) // the first digit of the hour time cannot exceed 2, which means for now the hour cannot exceed 20
		{
			//second digit of the hour in a 24 hour time
			if (!((time2 & (1 << 6)) == 0))
				hours += pow(2, 0);
			if (!((time2 & (1 << 7)) == 0))
				hours += pow(2, 1);
			if (!((time2 & (1 << 8)) == 0))
				hours += pow(2, 2);
			if (!((time2 & (1 << 9)) == 0))
				hours += pow(2, 3);
			if ((time2 & (1 << 11)) == 0) // if the 12th digit is 0, that means that the second digit can be from 0 to 9
			{
				if (hours <= 19) // the second digit of an hour cannot exceed 9 which means the maximum hour we can get is 19
				{
					//minutes of the 24 hour time
					if (!((time2 & (1 << 0)) == 0))
						minutes += pow(2, 0);
					if (!((time2 & (1 << 1)) == 0))
						minutes += pow(2, 1);
					if (!((time2 & (1 << 2)) == 0))
						minutes += pow(2, 2);
					if (!((time2 & (1 << 3)) == 0))
						minutes += pow(2, 3);
					if (!((time2 & (1 << 4)) == 0))
						minutes += pow(2, 4);
					if (!((time2 & (1 << 5)) == 0))
						minutes += pow(2, 5);
					if (minutes <= 59)//the minutes can't show something over 59 
					{
						time2IsValid = true;
						cout << std::setw(2) << std::setfill('0') << hours << ":" << std::setw(2) << std::setfill('0') << minutes << endl;
					}
					else//if the minutes are 60 or over, the clock will go over the boundaries
						cout << "Error! Clock 2 won't work!" << endl;
				}
				else//if the hours are 10 or more , the clock will go over the boundaries
					cout << "Error! Clock 2 won't work!" << endl;
			}
			else if (!((time2 & (1 << 11)) == 0))//in other case if the 12th digit is 1, that means the first digit of the hour is 2
			{
				if (hours <= 24) // the hour cannot exceed 24
				{
					//minutes of the 24 hour time
					if (!((time2 & (1 << 0)) == 0))
						minutes += pow(2, 0);
					if (!((time2 & (1 << 1)) == 0))
						minutes += pow(2, 1);
					if (!((time2 & (1 << 2)) == 0))
						minutes += pow(2, 2);
					if (!((time2 & (1 << 3)) == 0))
						minutes += pow(2, 3);
					if (!((time2 & (1 << 4)) == 0))
						minutes += pow(2, 4);
					if (!((time2 & (1 << 5)) == 0))
						minutes += pow(2, 5);
					if (minutes <= 59)//the minutes can't show something over 59 
					{
						cout << std::setw(2) << std::setfill('0') << hours << ":" << std::setw(2) << std::setfill('0') << minutes << endl;
						time2IsValid = true;
					}
					else//if the minutes are 60 or over, the clock will go over the boundaries
						cout << "Error! Clock 2 won't work!" << endl;
				}
				else//if the hours are 10 or more , the clock will go over the boundaries
					cout << "Error! Clock 2 won't work!" << endl;
			}
		}
		else
			cout << "Error! Clock 2 won't work!" << endl;
	}
	cout << endl;
	if (time1IsValid && time2IsValid)
	{
		hours = 0;
		minutes = 0;
		
		timeDifference = abs(time1 - time2);

		//first digit of the time differnce
		if (!((timeDifference & (1 << 10)) == 0))
			hours += pow(2, 0);
		if (!((timeDifference & (1 << 11)) == 0))
			hours += pow(2, 1);
		hours *= 10;

		//second digit of the time differnce
		if (!((timeDifference & (1 << 6)) == 0))
			hours += pow(2, 0);
		if (!((timeDifference & (1 << 7)) == 0))
			hours += pow(2, 1);
		if (!((timeDifference & (1 << 8)) == 0))
			hours += pow(2, 2);
		if (!((timeDifference & (1 << 9)) == 0))
			hours += pow(2, 3);

		//minutes
		if (!((timeDifference & (1 << 0)) == 0))
			minutes += pow(2, 0);
		if (!((timeDifference & (1 << 1)) == 0))
			minutes += pow(2, 1);
		if (!((timeDifference & (1 << 2)) == 0))
			minutes += pow(2, 2);
		if (!((timeDifference & (1 << 3)) == 0))
			minutes += pow(2, 3);
		if (!((timeDifference & (1 << 4)) == 0))
			minutes += pow(2, 4);
		if (!((timeDifference & (1 << 5)) == 0))
			minutes += pow(2, 5);
		if ((hours <= 24) && (minutes <= 59))
			cout << "diff " << std::setw(2) << std::setfill('0') << hours << ":" << std::setw(2) << std::setfill('0') << minutes << endl;
		else
			cout << "There was an error finding the difference between the two times." << endl;
	}
	else
	{
		if (!time1IsValid && !time2IsValid)
		{
			cout << "Both times are invalid!" << endl;
		}
		else if (!time1IsValid)
		{
			cout << "Since an error occured while calculating time 1, the difference cannot be solved." << endl;
		}
		else if (!time2IsValid)
		{
			cout << "Since an error occured while calculating time 2, the difference cannot be solved." << endl;
		}
		
	}

	return 0;

}