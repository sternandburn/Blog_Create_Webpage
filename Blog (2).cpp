// Implementation file for the blog class
// CS-355 - Data Structures and Algorithms
// Written by Noah Stern
// Date: September 6, 2020


#include "Blog.h"
#include <iomanip>
#include <ctime>
Blog::Blog()
{
    authorFirst = "";
    authorLast = "";
    content = "";
    month = 0;
    day = 0;
    year = 0;
}

void Blog::setBlog(string f, string l, string c,
                   int m, int d, int y)
{
    authorFirst = f;
    authorLast = l;
    content = c;
    month = m;
    day = d;
    year = y;
}

string Blog::getAuthorFirst() const
{
    return authorFirst;
}
string Blog::getAuthorLast() const
{
    return authorLast;
}
string Blog::getContent() const
{
    return content;
}
int Blog::getMonth() const
{
    return month;
}
int Blog::getDay() const
{
    return day;
}
int Blog::getYear() const
{
    return year;
}

int Blog::daysElapsed() const
{
    const int monthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int num = 365*year + day;
    for(int i=0; i<month-1; i++)
    {
            num += monthDays[i];
    }
    int numLeaps = year/4 - year/100 +year/400;
    num += numLeaps;

    time_t now = time(0);
    tm * ltm = localtime(&now);
    int currYear = 1900 + ltm->tm_year;
    int currMonth = 1 + ltm->tm_mon;
    int currDay = ltm->tm_mday;

    int num2 = 365*currYear + currDay;
    for(int i=0; i<month-1; i++)
    {
            num2 += monthDays[i];
    }
    int numLeaps2 = year/4 - year/100 +year/400;
    num2 += numLeaps2;

    int elapsed = num2 - num;
    return elapsed;
}
//***************************************************
// Name: operator< (const blog &right)
// Purpose: overload < operator to return true or false
// Incoming: blog right
// Outgoing: true/false
// Return: true/false
//***************************************************
bool Blog::operator<(const Blog &right) const
{
     if(daysElapsed() < right.daysElapsed())
            return true;
     else
            return false;
}

