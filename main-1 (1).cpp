// main file (Driver) to create a blog object
//					  add blogs to a list
//					  display blogs
// CS-355 - Data Structures and Algorithms
// Written by Noah Stern
// Date: September 6, 2020

#include <iostream>
#include <iomanip>
#include  <fstream>
#include "Blog.h"
using namespace std;

const int MAX_BLOGS = 100;

int menu();
void addBlog(Blog blog[] , int & num);
void displayBlogs(Blog blog[], int num);
void sortBlogs (Blog blog[], int numBlogs);
void createWebPages (Blog blog[], int numBlogs);
int main()
{
    Blog blog[MAX_BLOGS];
    int numBlogs = 0;
    int choice = 0;
    do
    {
        choice = menu();
        switch (choice)                                                             
        {
            case 1: // Add blog
            	sortBlogs (blog, numBlogs);
                addBlog(blog, numBlogs);
                break;
            case 2: // Display all blogs
                displayBlogs(blog, numBlogs);
                break;
	        case 3: //Create web page
            	createWebPages(blog, numBlogs);
             	break;
        	case 4: // Say good bye
                cout << "Good bye" << endl;
                break;
            default: // INVALID CHOICE
                cout << "You have entered an invalid choice" << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}

//***************************************************
// Name: menu
// Purpose: display menu
// Input: N/A
// Output: choice
// Return: choice
//***************************************************
int menu()
{
	int choice = 0;
	cout << "1-add blog" << endl;
	cout << "2-display all blogs" << endl;
	cout<< "3-create web page" << endl;
    cout << "4-quit" << endl;
	cout << "Pick one: " << endl;
	cin >> choice;

	return choice;
}

//***************************************************
// Name: addBlog
// Purpose: add information to blog
// Input: blog, numBlogs
// Output: numblogs
// Return: N/A
//***************************************************
void addBlog(Blog blog[], int &numBlogs)
{
	int year, day, month;
	string authorFirst, authorLast, content;
	cout << "Enter author first name: " << endl;
	cin >> ws;
	getline(cin,authorFirst);
	cout << "Enter author last name: " << endl;
	cin >> ws;
	getline(cin,authorLast);
	cout << "Enter content: " << endl;
	cin >> ws;
	getline(cin,content);
	cout << "Enter month: " << endl;
	cin >> month;
	cout << "Enter day: " << endl;
	cin >> day;
	cout << "Enter year: " << endl;
	cin >> year;

	blog[numBlogs].setBlog(authorFirst, authorLast, content, month, day, year);

	numBlogs++;
}

//***************************************************
// Name: displayBlogs
// Purpose: display information from blogs to screen
// Input: blog, numBlogs
// Output: N/A
// Return: N/A
//***************************************************
void displayBlogs(Blog blog[], int numBlogs)
{
	cout << setfill(' ') << setw(7) << "Date" << setw(20) << "Author" << setw(25) << "            Content        " << endl;
	for(int i=0; i<numBlogs; i++)
        {
            cout << endl;
            cout << setfill('0') << setw(2)<< blog[i].getMonth();
            cout << "-";
            cout << setfill('0') << setw(2) << blog[i].getDay();
            cout << "-";
            cout << blog[i].getYear();
            cout << setfill(' ') << setw(10) << blog[i].getAuthorFirst();
            cout << " ";
            cout << setfill(' ') << setw(10) << blog[i].getAuthorLast();
            cout << "     ";
            cout << setfill(' ') << setw(25) << blog[i].getContent();
	 }
	 cout << endl << endl << endl;
}
//***************************************************
// Name: sortBlogs
// Purpose: sorts blogs in ascending order
// Incoming: blog, numblogs
// Outgoing: N/A
// Return: N/A
//***************************************************
void sortBlogs (Blog blog[], int numBlogs)
{
   for (int i = 0; i < numBlogs - 1; i++)
   {
       for (int j = numBlogs - 1; j > i; j--)
           if ((blog[j] < blog[j-1])) 
           {
               Blog temp = blog[j];
               blog[j] = blog[j-1];
               blog[j-1] = temp;
           }
   }
}

//***************************************************
// Name: createWebPages
// Purpose: create web page with first name, last name, content, date
// Incoming: blog, numblogs
// Outgoing: N/A
// Return: N/A
//***************************************************
void createWebPages (Blog blog[], int numBlogs)
{
	  ofstream outfile;
	  ofstream outfile1;
  	  string filename;
  	  outfile1.open("website\\index.html");
  	  outfile1 << "<!DOCTYPE html>" << endl << "<html lang=\"en\">" << endl
       		   << "<head>" << endl << "<title>The CS 355 Super Blog</title>"
       		   << "</head>" << endl << "<body>" << endl << "<h1>The CS 355 Super Blog</h1>"
       		   << endl;

	  for (int i = 0; i < numBlogs; i++)
      {
	       string first = blog[i].getAuthorFirst();
	       string last = blog[i].getAuthorLast();
	       outfile1 << "<a href=\""<< first + last + ".html\"> Blog Written By "<<first+" "+last<<"</a> Date: "<<setw(2) << setfill('0') << blog[i].getDay() << "-" << setw(2) << setfill('0')
	           		<< blog[i].getMonth() << "-" << setw(2) << blog[i].getYear()<<"</br></br>"<<endl<<endl;
      }

	  for (int i=0; i<numBlogs; i++)
	  {
		    filename = "website\\" + blog[i].getAuthorFirst() + blog[i].getAuthorLast() + ".html";
		    outfile.open(filename.c_str());
		    outfile << "<!DOCTYPE html>" << endl << "<html lang=\"en\">" << endl
		            << "<head>" << endl << "<title>The CS 355 Super Blog</title>"
		            << endl << "</head>" << endl << "<body>" << endl;
		
		    outfile << "<p>Written by " << blog[i].getAuthorFirst() << " " << blog[i].getAuthorLast() << "</p> " << endl;
		    outfile << "<p>Blog: " << blog[i].getContent() << "</p>" << endl;
		    outfile <<  "<p>Date: " << blog[i].getMonth() << "-"
		            << blog[i].getDay() << "-"
		            << blog[i].getYear() << "</p>" << endl;
		
		    outfile << "</body>" << endl << "</html>" << endl;
		    outfile.close();
	  }
		
		  cout << "The system created " << numBlogs << " web page(s)." << endl;
}



