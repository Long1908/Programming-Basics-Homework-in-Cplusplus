// УП Домашно 1 - Задача 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    unsigned int day1, month1, year1, hour1, minute1, second1;
    unsigned int day2, month2, year2, hour2, minute2, second2;
    unsigned int differenceInSeconds = 0, differenceInMinutes = 0, differenceInHours = 0, differenceInDays = 0, differenceInMonths = 0, differenceInYears = 0;
    unsigned int daysBetweenTheTwoTimes;
    unsigned int normalYears, leapYears;
    unsigned int allDaysInTheMonth1;
    unsigned int allDaysInTheMonth2;
    char dot;
    char doubleDot;

    cin >> day1 >> dot >> month1 >> dot >> year1 >> hour1 >> doubleDot >> minute1 >> doubleDot >> second1;
    cin >> day2 >> dot >> month2 >> dot >> year2 >> hour2 >> doubleDot >> minute2 >> doubleDot >> second2;

    switch (month1)
    {
    case 1:
        allDaysInTheMonth1 = 31;
        break;
    case 2:
        if ((year1 % 400 == 0) || ((year1 % 4 == 0) && (year1 % 100 != 0)))
        {
            allDaysInTheMonth1 = 29;
        }
        else
            allDaysInTheMonth1 = 28;
        break;
    case 3:
        allDaysInTheMonth1 = 31;
        break;
    case 4:
        allDaysInTheMonth1 = 30;
        break;
    case 5:
        allDaysInTheMonth1 = 31;
        break;
    case 6:
        allDaysInTheMonth1 = 30;
        break;
    case 7:
        allDaysInTheMonth1 = 31;
        break;
    case 8:
        allDaysInTheMonth1 = 31;
        break;
    case 9:
        allDaysInTheMonth1 = 30;
        break;
    case 10:
        allDaysInTheMonth1 = 31;
        break;
    case 11:
        allDaysInTheMonth1 = 30;
        break;
    case 12:
        allDaysInTheMonth1 = 31;
        break;
    default:
        allDaysInTheMonth1 = 0;
        cout << "Invalid date / time" << endl;
        return 0;
    }

    switch (month2)
    {
    case 1:
        allDaysInTheMonth2 = 31;
        break;
    case 2:
        if ((year2 % 400 == 0) || ((year2 % 4 == 0) && (year2 % 100 != 0)))
        {
            allDaysInTheMonth2 = 29;
        }
        else
            allDaysInTheMonth2 = 28;
        break;
    case 3:
        allDaysInTheMonth2 = 31;
        break;
    case 4:
        allDaysInTheMonth2 = 30;
        break;
    case 5:
        allDaysInTheMonth2 = 31;
        break;
    case 6:
        allDaysInTheMonth2 = 30;
        break;
    case 7:
        allDaysInTheMonth2 = 31;
        break;
    case 8:
        allDaysInTheMonth2 = 31;
        break;
    case 9:
        allDaysInTheMonth2 = 30;
        break;
    case 10:
        allDaysInTheMonth2 = 31;
        break;
    case 11:
        allDaysInTheMonth2 = 30;
        break;
    case 12:
        allDaysInTheMonth2 = 31;
        break;
    default:
        allDaysInTheMonth2 = 0;
        cout << "Invalid date / time" << endl;
        return 0;
    }

    unsigned int highestYear = 0;

    if (((year1 >= 0) && (year1 <= 9999)) && ((year2 >= 0) && (year2 <= 9999)) &&
        ((day1 >= 1) && (day1 <= allDaysInTheMonth1)) && ((day2 >= 1) && (day2 <= allDaysInTheMonth2)))
    {
        if (year1 > year2)
        {
            highestYear = year1;
            if (month2 > month1)
            {
                month1 += 12;
                --year1;
            }
            if (day2 > day1)
            {
                day1 += 30;
                --month1;
            }
            if (hour2 > hour1)
            {
                hour1 += 24;
                --day1;
            }
            if (minute2 > minute1)
            {
                minute1 += 60;
                --hour1;
            }
            if (second2 > second1)
            {
                second1 += 60;
                --minute1;
            }
            differenceInYears = year1 - year2;
            differenceInMonths = month1 - month2;
            differenceInDays = day1 - day2;
            differenceInHours = hour1 - hour2;
            differenceInSeconds = second1 - second2;
            differenceInMinutes = minute1 - minute2;
        }
        else if (year1 < year2)
        {
            highestYear = year2;
            if (month1 > month2)
            {
                month2 += 12;
                --year2;
            }
            if (day1 > day2)
            {
                day2 += 30;
                --month2;
            }
            if (hour1 > hour2)
            {
                hour2 += 24;
                --day2;
            }
            if (minute1 > minute2)
            {
                minute2 += 60;
                --hour2;
            }
            if (second1 > second2)
            {
                second2 += 60;
                --minute2;
            }
            differenceInYears = year2 - year1;
            differenceInMonths = month2 - month1;
            differenceInDays = day2 - day1;
            differenceInHours = hour2 - hour1;
            differenceInSeconds = second2 - second1;
            differenceInMinutes = minute2 - minute1;
        }
        else if (year1 == year2)
        {
            highestYear = year1;
            if (month1 > month2)
            {
                if (day2 > day1)
                {
                    day1 += 30;
                    --month1;
                }
                if (hour2 > hour1)
                {
                    hour1 += 24;
                    --day1;
                }
                if (minute2 > minute1)
                {
                    minute1 += 60;
                    --hour1;
                }
                if (second2 > second1)
                {
                    second1 += 60;
                    --minute1;
                }
                differenceInMonths = month1 - month2;
                differenceInDays = day1 - day2;
                differenceInHours = hour1 - hour2;
                differenceInSeconds = second1 - second2;
                differenceInMinutes = minute1 - minute2;
            }
            else if (month1 < month2)
            {
                if (day1 > day2)
                {
                    day2 += 30;
                    --month2;
                }
                if (hour1 > hour2)
                {
                    hour2 += 24;
                    --day2;
                }
                if (minute1 > minute2)
                {
                    minute2 += 60;
                    --hour2;
                }
                if (second1 > second2)
                {
                    second2 += 60;
                    --minute2;
                }
                differenceInMonths = month2 - month1;
                differenceInDays = day2 - day1;
                differenceInHours = hour2 - hour1;
                differenceInSeconds = second2 - second1;
                differenceInMinutes = minute2 - minute1;
            }
            else if (month1 == month2)
            {
                if (day1 > day2)
                {
                    if (hour2 > hour1)
                    {
                        hour1 += 24;
                        --day1;
                    }
                    if (minute2 > minute1)
                    {
                        minute1 += 60;
                        --hour1;
                    }
                    if (second2 > second1)
                    {
                        second1 += 60;
                        --minute1;
                    }
                    differenceInDays = day1 - day2;
                    differenceInHours = hour1 - hour2;
                    differenceInSeconds = second1 - second2;
                    differenceInMinutes = minute1 - minute2;
                }
                else if (day1 < day2)
                {
                    if (hour1 > hour2)
                    {
                        hour2 += 24;
                        --day2;
                    }
                    if (minute1 > minute2)
                    {
                        minute2 += 60;
                        --hour2;
                    }
                    if (second1 > second2)
                    {
                        second2 += 60;
                        --minute2;
                    }
                    differenceInDays = day2 - day1;
                    differenceInHours = hour2 - hour1;
                    differenceInSeconds = second2 - second1;
                    differenceInMinutes = minute2 - minute1;

                }
                else if (day1 == day2)
                {
                    if (hour1 > hour2)
                    {
                        if (minute2 > minute1)
                        {
                            minute1 += 60;
                            --hour1;
                        }
                        if (second2 > second2)
                        {
                            second1 += 60;
                            --minute1;
                        }
                        differenceInHours = hour1 - hour2;
                        differenceInSeconds = second1 - second2;
                        differenceInMinutes = minute1 - minute2;
                    }
                    else if (hour1 < hour2)
                    {
                        if (minute1 > minute2)
                        {
                            minute2 += 60;
                            --hour2;
                        }
                        if (second1 > second2)
                        {
                            second2 += 60;
                            --minute2;
                        }
                        differenceInHours = hour2 - hour1;
                        differenceInSeconds = second2 - second1;
                        differenceInMinutes = minute2 - minute1;
                    }
                    else if (hour1 == hour2)
                    {
                        if (minute1 > minute2)
                        {
                            if (second2 > second1)
                            {
                                second1 += 60;
                                --minute1;
                            }
                            differenceInSeconds = second1 - second2;
                            differenceInMinutes = minute1 - minute2;
                        }
                        else if (minute1 < minute2)
                        {
                            if (second1 > second2)
                            {
                                second2 += 60;
                                --minute2;
                            }
                            differenceInSeconds = second2 - second1;
                            differenceInMinutes = minute2 - minute1;
                        }
                        else if (minute1 == minute2)
                        {
                            if (second1 > second2)
                            {
                                differenceInSeconds = second1 - second2;
                            }
                            else if (second1 < second2)
                            {
                                differenceInSeconds = second2 - second1;
                            }
                            else if (second1 == second2)
                            {
                                cout << "The times are identical" << endl;
                            }
                        }
                    }
                }
            }
        }
        leapYears = differenceInYears % 4;
        normalYears = differenceInYears - leapYears;
        daysBetweenTheTwoTimes = leapYears * 366 + normalYears * 365;
        switch (differenceInMonths)
        {
        case 1:
            daysBetweenTheTwoTimes += 31;
            break;
        case 2:
            daysBetweenTheTwoTimes += 59;
            break;
        case 3:
            daysBetweenTheTwoTimes += 90;
            break;
        case 4:
            daysBetweenTheTwoTimes += 120;
            break;
        case 5:
            daysBetweenTheTwoTimes += 151;
            break;
        case 6:
            daysBetweenTheTwoTimes += 181;
            break;
        case 7:
            daysBetweenTheTwoTimes += 212;
            break;
        case 8:
            daysBetweenTheTwoTimes += 243;
            break;
        case 9:
            daysBetweenTheTwoTimes += 273;
            break;
        case 10:
            daysBetweenTheTwoTimes += 304;
            break;
        case 11:
            daysBetweenTheTwoTimes += 334;
            break;
        default:
            daysBetweenTheTwoTimes += 0;
            break;
        }
        if ((highestYear % 4 == 0) && (differenceInMonths >= 2))
        {
            ++daysBetweenTheTwoTimes;
        }
        daysBetweenTheTwoTimes += differenceInDays;
        cout << daysBetweenTheTwoTimes << "-" << std::setfill('0') << std::setw(2) << differenceInHours << ":" << std::setfill('0') << std::setw(2) << differenceInMinutes << ":" << std::setfill('0') << std::setw(2) << differenceInSeconds << endl;
    }
    else
    {
        cout << "Invalid date / time" << endl;
        return 0;
    }


    return 0;
}