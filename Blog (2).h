// Declaration of blog class file
// CS-355 - Data Structures and Algorithms
// Written by Noah Stern
// Date: September 6, 2020

#include <iostream>
using namespace std;
class Blog
{
    private:
        string authorFirst;
        string authorLast;
        string content;
        int month, day, year;
    public:
        Blog();
        void setBlog(string, string, string, int, int, int);
        string getAuthorFirst() const;
        string getAuthorLast() const;
        string getContent() const;
        int getMonth() const;
        int getDay() const;
        int getYear() const;
        int daysElapsed() const;
        bool operator<(const Blog &right) const;
};
