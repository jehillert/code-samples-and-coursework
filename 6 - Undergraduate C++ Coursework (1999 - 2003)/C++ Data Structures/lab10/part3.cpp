// Program: Recursive Programming Project 3
// Programmer: John Hillert
// Last Updated: 10/27/02
// Purpose: To demonstrate the function that shifts all indices 
//          between two specified bounds in the array.
///////////////////////////////////////////////////////////////

#include <iostream>
#include <cassert>
#include <cstdlib>

const int LOW_BOUND = -1; // first bound can be neg 1 to get element 1
const int HIGH_BOUND = 26; // array goes from 0 to 25. 26 is just outside.

void reverser(char string[], int lower_bound, int upper_bound);
// Precondition: string is a valid array of characters, and lower_bound 
// and upper_bound are positive. 
// Postcondition: The characters between bounds lower_bound
// and upper_bound have reversed in order.

int main()
{
   char array[] = "abcdefghijklmnopqrstuvwxyz";
   int lower_bound, upper_bound;
 
   //INTRO AND INPUT
   cout << "\n\n\n\n"; 
   cout << "This function reverses the order of all elements in a string\n"
        << "array between a lower bound and an upper bound.  The elements\n"
        << "go from 0 to the number of letters minus 1.  Therefore, the\n"
        << "bounds can go from -1 to the number of letters.";

   cout << "\n\nEnter upper bound from " << LOW_BOUND << " to " << HIGH_BOUND
        << ": ";
   cin >> upper_bound;
   cout << "\nEnter lower bound from " << LOW_BOUND << " to " << HIGH_BOUND 
        << " with (lower_bound < upper_bound): ";
   cin >> lower_bound;

   reverser(array, lower_bound, upper_bound);
  
   cout << endl << endl << array << "\n\n\n\n\n\n\n\n\n";
  
   return EXIT_SUCCESS;
}

void reverser(char string[], int lower_bound, int upper_bound)
{
   char temp;
   assert(lower_bound >= LOW_BOUND && lower_bound <= HIGH_BOUND); 
   assert(upper_bound >= LOW_BOUND && upper_bound <= HIGH_BOUND); 
   assert(lower_bound <= upper_bound);

   if((upper_bound - lower_bound) == 2)
   {}   // Do nothing. bounds have gotten the same element between them
   else if((upper_bound - lower_bound) == 3)
   {
      // switch the two elements between the final boundaries
      temp = string[lower_bound + 1];
      string[lower_bound + 1] = string[upper_bound - 1];
      string[upper_bound - 1] = temp; 
   } 
   else
   {
      // switch the two elements just inside the two boundaries
      // then squeeze the boundaries in by 1 on both sides
      temp = string[lower_bound + 1];
      string[lower_bound + 1] = string[upper_bound - 1];
      string[upper_bound - 1] = temp; 
  