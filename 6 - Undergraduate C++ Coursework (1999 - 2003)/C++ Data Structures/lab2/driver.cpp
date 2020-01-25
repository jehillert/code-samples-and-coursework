// driver.cpp
// Author: John Hillert
// Last Modified: 9/2
// Comments:  This comment is a driver to test the line class
//////////////////////////////////////////////////////////////

#include <cstdlib>
#include <iostream>
#include "line.h"
using namespace std;
using namespace linelab;

int main()
{
   int shifted = 1;
   point p1(0,1), p2(2,3);
   

   // CALLING AND PRINTING DEFAULT CONSTRUCTOR TO CREATE line1 

   cout << "\n\n\nInitializing object line1 with default constructor. . ."; 
   line line1;
   cout << "\n\nLine1 from the default constructor:  " << line1;
  
   // ENTER AND WRITE OUT NEW VALUES FOR line1 USING >> OPERATOR
   cout << "\n\nEnter new values for line1:  "; 
   cin >> line1;

   cout << "\n\nLine1 is now: " << line1 << endl;

   // USING REGULAR CONSTRUCTOR TO CREATE A LINE
   line line2(p1, p2);
   cout << "\nLine2 is: " << line2 << endl;

   // TESTING == and != OPERATOR
   cout << "\n\nThe copy constructor is called twice by the boolian \"==\"" 
        << "\nfunction call because its two arguments are call-by-value.\n";
 
   if (line1 == line2)
      cout << "\nline1 == line2" << endl;
   else
      cout << "\nline1 != line2" << endl;
   
   // TESTING SLOPE AND SHIFT_VERTICAL FUNCTIONS
   cout << "\nThe slope for line2 is: " << line2.slope() << endl;

   line1 = shift_vertical(line2, shifted);
   
   // TESTING OVERLOADING OF << OPERATOR
   cout << "\nline1 is " << line1 << ", which is line2,  " << line2 
        << ", shifted vertically by 1" <<