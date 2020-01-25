Received: from larkspur.Mines.EDU (larkspur.Mines.EDU [138.67.2.4])
	by slate.Mines.EDU (AIX4.3/8.9.3/8.9.1) with ESMTP id WAA125416
	for <jhillert@mines.edu>; Mon, 20 Nov 2000 22:07:04 -0700
Received: (from rspinhir@localhost)
	by larkspur.Mines.EDU (8.9.1/8.9.1) id WAA4864441
	for jhillert; Mon, 20 Nov 2000 22:07:02 -0700 (MST)
Date: Mon, 20 Nov 2000 22:07:02 -0700 (MST)
From: Spinhirne <rspinhir@larkspur.Mines.EDU>
Message-Id: <200011210507.WAA4864441@larkspur.Mines.EDU>
To: jhillert@larkspur.Mines.EDU
Subject: cs261f hw5 
X-UIDL: @(~"!K!A!!@9&#!;J?!!
Status: RO
X-Status: 

Grade Report for Assignment 5

          Program1:  Parallel arrays     ___20_____ 20 pts

              header  2
              comments 3
              compiles   8
              two sorts: string and double    4
                 keeps all arrays in correct order
              two output files and screen output   3
                 alphabetical.dat and numeric.dat
                                         
          Program2: Ch 10 project 11       ___19_____ 20 pts   

              header  2 
              comments 3
              compiles  8
              Uses 2-D char array   2
              Continues until full or user
                   signals EOF and gives
                   error message if seat full     2
		-1 PROGRAM ENDS BEFORE LAST SEAT IS TAKEN.
              Correct seat output         2              



          Total                          ___38_____ 40 pts
// sourceCode1.cpp
// Name: John Hillert
// Date: 11/7/00
// Purpose:  This program takes a donorlist with lines consisting
// of first name, last name, and floating point donation and 
// organizes the final information on the screen and in two output
// files.  One file is organized by alphabetical order, another by
// donation amount (descending order). The origional list, alphabetic
// list, and numeric list will be output to the screen.
//////////////////////////////////////////////////////////////////////
//
//
//
//      ALGORITHM
// - write include statements
// - write given function prototypes
// - start main function
// - declare character arrays to first, and second
// - declare double array donation and set equal to zero
// - open up donarList.dat and issue warning
// - declare integer for array size
// - call readData function
//   = make buffer array
//   = make while loop with the EOF ending it 
//       = take first word from input file using buffer array 
//       = strlen buffer
//       = make length of first[length] equal to length of buffer plus 1
//       = copy buffer value into first[length] 
//       = take next word for input file using buffer array
//       = strlen buffer
//       = make lenth of last[length] equal to length of buffer plus 1
//       = copy buffer value into first[length]
//       = put next value, which is a double, into donation[length] 
//       = length++
//       = repeat loop until EOF
// - call sortStrings function
//   = do a bubblesort here where you limiting condition is the size of the 
//     array
//   = if strcmp(last[i], last[i+1] < 0 then don't do anything
//   = if strcmp(last[i], last[i+1] = 0 then compare first names
//   = if strcmp(last[i], last[i+1] > 0 then call swap all i and i+1
//   = in all three arrays  
// - open output file named alphabetic.dat and include warning
// - call printResults
//   = start for loop that ends one less than array length
//      = cout first, last, and donation to output file and screen
//      = cout end line to output file and screen
// - call sortDoubles function
//   = do a bubblesort here where your limiting condition is the size of
//     the array
//   = if donation[i] < donation[i + 1] then swap all matrix values
//     Note: don't worry if they are equal.  They will still be in
//     alphabetic order from previous sorting
// - open output file numeric.dat and include warning
// - call printResults
//   = same here as before with printresults except output to numeric.dat
// - close input file
// - close alphabetic.dat
// - close numeric.dat
// - empty arrays using delete: example is in lab11 Matrix.C
// - return O;
// - close main then define functions according to descriptions above

#include<iostream.h>
#include<fstream.h> 
#include<stdlib.h>
#include<string.h>

typedef char** ItemType;

void readData(ifstream&, ItemType, ItemType, double[], int& length);
// Precondition: ifstream object is bound to an input file,
// three arrays are to be filled, and an integer returned 
// that contains the number of records stored.
// Postcondition: Three filed, and a count of the number of records.

void sortStrings(ItemType, ItemType, double[], int); 
// Precondition: Filled arrays, and an integer for number of items filled
// Postcondition: Arrays are aligned per the sorted array of last names

void sortDoubles(ItemType, ItemType, double[], int);
// Precondition: Filled arrays, an integer for number of items in all arrays
// Postconditions: Arrays are aligned per the sorted array of donation amounts

void printResults(ItemType, ItemType, double[], int);
// Precondition: Filled arrays, and an integer represeting count
// Postcondition: origional contents of input file displayed to screen

void printResults(ostream&, ItemType, ItemType, double[], int);
// Precondition: Filled arrays, an integer representing the count, and
// an ostream operator for a file or screen destination
// Postcondition: prints list to screen or appropriate file

void swap(ItemType, ItemType, double[], int i);
// Precondition: arrays are filled, two array elements are being
// compared, and their index is kept track of
// Postcondition: elements i and i + 1 for all three arrays are swapped
 
void openfail();
// Precondition: file didn't open 
// Postcondition: program ends

int main()
{
   ItemType first, last;
   double *donation;
   int length;
      
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   cout.setf(ios::left);

   first = new char*[100];
   last = new char*[100];
   donation = new double[100];

   for(int i=0;i<100;i++) donation[i] = 0;
 
   ifstream input;
   input.open("donorList.dat");
   if(input.fail())
     openfail();
   readData(input, first, last, donation, length); 
 
   printResults(first, last, donation, length);

   sortStrings(first, last, donation, length);
   
   ofstream alphabet;
   alphabet.open("alphabetic.dat");
   if(alphabet.fail())
      openfail();

   cout << "ORDER OF DONORS ALPHABETICALLY" << endl;
   printResults(alphabet, first, last, donation, length);
   cout << endl << endl;

   sortDoubles(first, last, donation, length);

   ofstream numeric;
   numeric.open("numeric.dat");
   if(numeric.fail())
      openfail();

   cout << "ORDER OF DONORS BY CONTRIBUTION (DESCENDING ORDER)" << endl;
   printResults(numeric, first, last, donation, length);
 
   input.close();
   alphabet.close();
   numeric.close();

   // Returning memory to free heap for reuse
   for(i = 0; i < length; i++)
      delete [] first[i];
   delete [] first;

   for(i = 0; i < length; i++)
      delete [] last[i];
   delete [] last; 

   delete [] donation;

   return 0;

}

void readData(ifstream& input, ItemType first, ItemType last, double
             donation[], int& length) 
{
  char array[80];
  length = 0;
  input >> array;
  while (! input.eof()) 
  {
     first[length] = new char[strlen(array) + 1];
     strcpy(first[length], array);
     input >> array;
     last[length] = new char[strlen(array) + 1];
     strcpy(last[length], array);
     input >> donation[length];  
     length++;          
     input >> array;
  }
}

void sortStrings(ItemType first, ItemType last, double donation[], int length)
{
   for(int j = 0; j < length; j++)
      for(int i = 0; i < length - 1; i++) 
      {
         if(strcmp(last[i], last[i+1]) > 0)
            swap(first, last, donation, i);
         if(strcmp(last[i], last[i+1]) == 0)
            if(strcmp(first[i], first[i+1]) > 0)
               swap(first, last, donation, i);
      }
}

void sortDoubles(ItemType first, ItemType last, double donation[], int length)
{
   for(int j = 0; j < length; j++)
      for(int i = 0; i < length - 1; i++)
      {
         if(donation[i] < donation[i+1])
            swap(first, last, donation, i);
      }
}

void printResults(ItemType first, ItemType last, double donation[], int length)
{
   cout << "ORDER DONORS BEFORE SORTING" << endl;
   for (int i=0; i < length; i++)
   {
      cout << last[i] << ", " << first[i] << "    $" << donation[i];
      cout << endl;
   }
   cout << endl << endl;
}

void printResults(ostream& output, ItemType first, ItemType last, double 
                  donation[], int length) 
{
   output.setf(ios::fixed);
   output.setf(ios::showpoint);
   output.precision(2);

   for(int i = 0; i < length; i++)
   {
      cout << last[i] << ", " << first[i] << "   $" << donation[i];  
      cout << endl;
      output << first[i] << "  " << last[i] << " $" << donation[i];
      output << endl;
   }
}

void swap(ItemType first, ItemType last, double donation[], int i)
{
   double temp = 0;
   ItemType sub;
   sub = new char*[1]; 
   temp = donation[i];
   donation[i] = donation[i+1];
   donation[i+1] = temp;
  
   sub[0] = first[i];
   first[i] = first[i+1];
   first[i+1] = sub[0];

   sub[0] = last[i];
   last[i] = last[i+1];
   last[i+1] = sub[0];
}

void openfail()
{
    cout << "File opening failed" << endl;
    exit(1);
} 

// sourceCode2 
// Name: John Hillert
// Purpose: this program has the seating chart for an airplane.
// A traveler asks for a seat.  If its filled he has to choose another
// seat, but if its unoocupied he  gets it and a
// new chart is printed to the screen with taken seets occupied
// by an X.  
//////////////////////////////////////////////////////////////////////////
//
//
// Algorithm
// - declare includes
// - make prototypes
// - define two dimensional character array to hold seats
// - define int array to list rows
// - give an introduction to program
// - fill array
//   = have two loops, one for rows, and one for columns
//       = for each column value j, specify a value
// - print array
//    = have a for loop for rows in aray and array
//       = cout all array values for a specific row separated by spaces
// - give customer seat choice
//    = ask for row, get row.  Ask for seat letter, get seat letter
// - start a while loop that ends with Ctrl^C or when seats are full
// - send this info to Xseat
//    = if choice was valid. then x out that seat 
//    = if invaled don't x it out and tell user why choice is invalid
// - print updated array or just print last array again for new choice
// - repeat until user wants to stop or until there's no more choices
// - end program  

#include<iostream.h>
#include<iomanip.h>

const int rows = 7;
const int columns = 4;

void fillArray(int aray[], char array[][columns], int rows);
// Precondition: aray and array have been declared, as well as columns and rows
// Postcondition: aray is filled 1 through 7 and array is an ABCD matrix

void printArray(int aray[], char array[][columns], int rows);
// Precondition: arays have been filled
// Postcondition: a seating chart is output to the screen

void choice(int& isle, char& seatletter);
// Precondition: isle is an int and seatletter is a char
// Postcondition: fills these variables with relevant values
 
void Xseat(char array[][columns], int rows, int isle, char seatletter, int& l);
// Precondition: matrix is full, seat choice has been input
// Postcondition: chosen seat is now occupied by an X
 
int main()
{
   char array[rows][columns]; // two dimensional arrays for seats
   int aray[rows]; // int array for rows
   int isle, l=1; // l is a counter to help signal last of seats 
   char seatletter;

   cout << "\n\n\nWelcome to Failed O-Ring Airlines.\n" // INTRO
        << "This program lets you select seats\n"
        << "from available seating.\n"
        << "Press Ctrl^C to exit.\n\n\n"; 
 
   fillArray(aray, array, rows); 
   printArray(aray, array, rows);
   
   choice(isle, seatletter);

   // This while loop goes until Ctrl^C or last seat is taken 
   while(l != rows * columns) 
   {
      Xseat(array, rows, isle, seatletter, l);
      printArray(aray, array, rows);
      choice(isle, seatletter);
   }

   cout << "\nWell I'll be! You've taken the last seat.\n" 
        "What's the next customer gonna do!" << endl << endl;
 
   return 0;
}   

void fillArray(int aray[], char array[][columns], int rows)
{
   for(int i = 0; i < rows; i++)
      for(int j = 0; j < columns; j++)
      {
         aray[i] = i + 1;
         if(j == 0)
            array[i][j] = 'A';
         if(j == 1)
            array[i][j] = 'B';
         if(j == 2)
            array[i][j] = 'C';
         if(j == 3)
            array[i][j] = 'D';
      }      
}

void printArray(int aray[], char array[][columns], int rows)
{
   for(int i = 0; i < rows; i++)
   {
      int j = 0;
      cout << aray[i] << "  " << array[i][j] << " " 
           << array[i][j+1] << "  " << array[i][j+2]
           << " " << array[i][j+3];
      cout << endl;
   }
}  

void choice(int& isle, char& seatletter)
{
   cout << "What seat do you want? Note that seats marked by an \"X\" "
        << "are unavailable.\n";
   cout << "Enter isle: ";
   cin >> isle;
   cout << "Enter seat letter: ";
   cin >> seatletter;
}

void Xseat(char array[][columns], int rows, int isle, char seatletter, int& l)
{
   int temp = 0;
   if(seatletter == 'A')
      temp = 0;
   else if(seatletter == 'B')
      temp = 1;
   else if(seatletter == 'C')
      temp = 2;
   else if(seatletter == 'D')
      temp = 3;
   else
   {
      cout << "\nInvalid seat letter entry. Try again.\n\n";
      temp = 9;
   }
   if(isle < 1 || isle > 7)
   {
      cout << "\nInvalid isle number. Try again.\n\n";
      temp = 9; 
   }
   if(array[isle - 1][temp] == 'X')
   {
      cout << "\nThis seat is already taken. Try again.\n\n";
   }
   if(temp != 9)  
   {
      array[isle - 1][temp] = 'X';
      l++;
      cout << endl;
   }
}            
