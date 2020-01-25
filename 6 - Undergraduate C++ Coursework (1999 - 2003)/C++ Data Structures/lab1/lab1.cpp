// lab1.cpp
// Last Modified By: John Hillert
// Last Modified: 8/25/02
// Comments: This program fills an array with integers,
// prints the values of that array, and averages their values.
// It also takes an index of the array, and compares the array
// value at that index with the average, outputting how close the
// value is to the average.
//////////////////////////////////////////////////////////////////

// ALGORITHM
// 1. Open file stream to read in integer values from "integers.dat"
// 2. Fill array with integers from input file stream
// 3. Close file stream
// 4. Print integer values from array to the screen
// 5. Calculate and output the average of the integers
// 6. Test how close the value of an array element is to the integer  
//    average
// 7. Ask if other tests are wanted in the form of a while loop
 
#include<cassert>
#include<cmath>
#include<cstdlib>
#include<fstream>
#include<iostream>

using namespace std;

void print_values(int array[], int i);
// Precondition: takes the array "array" and the index to which the array 
// is filled
// Postcondition: Prints to the screen the contents of the array. 
 
double Average(int array[], int i);
// Precondition: takes the array "array" and the index to which the array 
// is filled
// Postcondition: returns a double value of the average of all values in the
// function

void compare(int array, int i, double average);
// Precondition: Takes the array "array" the index to which the array   
// is filled, the index to which the average is compared, and the average
// of the function.
// Postcondition: Prints how close the value of that array index is to the
// actual average.


const int MAX_VALUES = 100;

int main()
{
   // ARRAY AND AUXILIARY DECLARATIONS 
   int array[MAX_VALUES];
   int array_val;
   int index;
   int i = 0;
   double average;
   char response = 'y';

   // DECLARE AND OPEN INPUT FILE STREAM FOR INTEGER FILE 
   ifstream in_stream; 
   in_stream.open("integers.dat");  
   
   // MAKE SURE FILE LOADED
   assert(! in_stream.fail());

   // FILL ARRAY WITH INTEGERS 
   while(! in_stream.eof() && i < MAX_VALUES)
   {
      in_stream >> array_val;
      array[i] = array_val;
      
      i++;
   } 
   
   // CLOSE FILE STREAM
   in_stream.close();
    
   // PRINT INTEGERS TO THE SCREEN 
   print_values(array, i);

   // CALCULATE AVERAGE OF INTEGERS
   average = Average(array, i);

   // OUTPUT AVERAGE OF INTEGERS
   cout << endl << "\nThe average is:  " <<  average << endl << endl;

   // FUNCTIONS CALLS TO TEST COMPARE 
   // THIS LOOP LETS YOU COMPARE SEVERAL INDEX VALUES
   while(response == 'y' || response == 'Y')
   { 
      // ENTER AN INDEX VALUE TO COMPARE TO THE AVERAGE 
      cout << "\n\nEnter index value between " << 0 << " and " << i-1 
           << " that " << "you would like to compare to array average:   ";
      cin >> index;

      // CHECK TO SEE IF INDEX IS IN PROPER RANGE AND COMPARE TO AVERAGE 
      assert(index >= 0 && index < i);
      compare(array[index], i, average);

      // ENTER Y OF y IF YOU WANT TO COMPARE ANOTHER INDEX VALUE
      cout << "\n\nWould you like to compare another index? "
           << "\nPress 'y' or 'Y' for yes, any other character for no.\n";
      cin >> response;
      
      cout << endl;  
      print_values(array,i);

   }

   return EXIT_SUCCESS;

}

void print_values(int array[], int i)
{
   for(int j=0; j < i-1; j++)
   {
      cout << endl << array[j];
   }
}   
      
double Average(int array[], int i)
{
   double average;
   double sum = 0;
   int j = 0;

   for (j = 0; j < i-1; j++)
   { 
      sum = sum + array[j]; 
   }

   average = sum/j;
   return average;
}

void compare(int array, int i, double average) 
{
   if(abs(array - average) > 50)
   {
      cout << "\nFar Away";
   }
   else if(abs(array - average) <= 50 && abs(array - average) > 25)
   { 
      cout << "\nNot Too Far";    
   }
   else if