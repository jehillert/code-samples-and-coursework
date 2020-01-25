// Program: Recursive Programming Project 1      
// Programmer: John Hillert
// Last Updated: 10/27/02
// Purpose: To demonstrate the function requested in programming project
//          1 of chapter 9 in the Data Structures book.
// *************NOTE*************
// The project asks for 1 function and I have two.  I could have substitued
// a for loop instead of using the spaces function, but I did the recursive
// function for more practice. 
////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cassert>
#include <cstdlib>
 
void levels(int level, int current_level);
// Precondition: the number of levels is positive
// Postcondition: The following output is produced to the specified level
// This was written by call number 1.
//  This was written by call number 2.
//   This was written by call number 3.
//   This ALSO written by call number 3.
//  This ALSO written by call number 2.
// This ALSO written by call number 1.

void spaces(int current_level);
// Precondition: current_level are positive
// Postcondition: Prints out a number of spaces equal to current_level

int main()
{
   int level, current_level = 1;
   cout << "\n\nEnter a positive number of levels for the recursive " 
        << "function: "; 
   cin >> level;

   levels(level, current_level);
       
   return EXIT_SUCCESS;
}

void levels(int level, int current_level)
{
   const char BLANK = ' ';
   int i;
   assert(current_level > 0);
   assert(level > 0);    

   //if the current call equal level
   //  	  print first message
   //     print second message
   if(current_level == level)
   {
      spaces(current_level);
      cout << "This was written by call number " << current_level << ".\n";
      spaces(current_level);
      cout << "This ALSO written by call number " << current_level << ".\n";
   }
   //else
   //     print first message
   //     increment current_level by 1
   //     send level and current_level to levels
   //     print second message
   else
   { 
      spaces(current_level);
      cout << "This was written by call number " << current_level << ".\n";
      levels(level, current_level + 1);
      spaces(current_level);
      cout << "This ALSO written by call number " << current_level << ".\n";
   }   
}

void spaces(int current_level)
{
    char BLANK = ' ';
    
    if(current_level == 1)
    {
       cout << BLANK;
    }