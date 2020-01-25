// Program: Recursive Programming Project 2
// Programmer: John Hillert
// Last Updated: 10/27/02
// Purpose: To demonstrate the function request in programming 
//          project 5 in chapter 9 of the Data Structures text 
////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cassert>
#include <cstdlib>

double sumover(unsigned int n);
// Precondition: n must be positive
// Postcondition: Returns the sum of the reciprocals of the
// first n positive integers.

int main()
{
   unsigned int n;
   double answer;
   
   cout << "\n\nEnter a positive integer for reciprocal summation: ";
   cin >> n;
   answer = sumover(n);

   cout << "\nThe answer is: " << answer << endl << endl; 

   return EXIT_SUCCESS;
}

double sumover(unsigned int n)
{
   assert(n >= 0);

   if(n == 0) 
   {
      return 0;
   }

   else if(n == 1)
   {
      return 1;
   }
   
   else
   {
      return