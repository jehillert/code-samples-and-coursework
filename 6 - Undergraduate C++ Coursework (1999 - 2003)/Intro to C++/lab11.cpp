Received: from larkspur.Mines.EDU (larkspur.Mines.EDU [138.67.2.4])
	by slate.Mines.EDU (AIX4.3/8.9.3/8.9.1) with ESMTP id XAA140960
	for <jhillert@mines.edu>; Tue, 7 Nov 2000 23:16:04 -0700
Received: (from rspinhir@localhost)
	by larkspur.Mines.EDU (8.9.1/8.9.1) id XAA4133624
	for jhillert; Tue, 7 Nov 2000 23:16:03 -0700 (MST)
Date: Tue, 7 Nov 2000 23:16:03 -0700 (MST)
From: Spinhirne <rspinhir@larkspur.Mines.EDU>
Message-Id: <200011080616.XAA4133624@larkspur.Mines.EDU>
To: jhillert@larkspur.Mines.EDU
Subject: cs261f lab11
X-UIDL: `Wc!!in2!!McC"!bhE"!

Grade Report for Lab 11

           Typescript1               ___3____ 3 pts
              Header and comments     1 pts
              dynamic variables used correctly 2 pts

           Typescript 2              ___3____ 3 pts
              Header and comments   1 pts
              dynamic strings used correctly  2 pts
                  ( with buffer and new
                    and using strcp and strcat)

           Typescript 3              ___4___  4 pts
              Header and comments   1 pts
              Functions correctly defined  2 pts
              Correct re-use of functions  1 pts
                  ( one fillArray, one printArray to
                    fill and print multiple arrays )

           Total                     __10_____ 10 pts
                     
Script started on Sat Nov  4 18:49:37 2000
$ Ca  cat dynamic.d cpp
// Program: dynamic.cpp
// Name: John Hillert
// Date: 11/4/00
// Program dynamic.cpp reads in three variables, assigns
// pointers to them, adds them, and prints the result. 
//////////////////////////////////////////////////////////
#include <iostream.h>                                     

int  main ()
{    
    int*  one;    
    int*  two;    
    int*  three;    
    int  result;    

    // Code to create  DYNAMIC VARIABLES    
    // *one, *two, *three.    
    one = new int;
    two = new int;
    three = new int;
 
    cout  << "Enter three integer numbers separated"          
          << " by blanks; press return."  << endl;    

    cin >> *one >> *two >> *three;

   // Code to read the values into the    
   // dynamic variables.    

    cout << "The values summed will be: " 
         << *one << " " << *two << " " << *three << endl;
 
   // Code to print the values that are to    
   // be summed.      

    result = *one + *two + *three;

   // Code to add the three values and store    
   // the answer in result..    

     cout  << "The result is: " << result  << endl;    

   // FILL IN THE Code to deallocate the dynamic data.    

     delete one;
     delete two;
     delete three;

     return 0;

}   
$ CC dynamicl .scri    cpp
$ a.out
Enter three integer numbers separated by blanks; press return.
12 13 15
The values summed will be: 12 13 15
The result is: 40
$ ^D

script done on Sat Nov  4 18:50:02 2000

script done on Sat Nov  4 18:50:02 2000
Script started on Mon Nov  6 16:15:58 2000
$ cat dynamic2.cpp
// Program: dynamic2.cpp
// Name: John Hillert
// Date: 11/4/00
// Program dynamic.cpp reads in three variables, assigns
// pointers to them, adds them, and prints the result. 
//////////////////////////////////////////////////////////
#include <iostream.h>                                     
#include <string.h>

int  main ()
{   
    char buffer1[11];
    char buffer2[11];
    char buffer3[11];
 
    char*  one;    
    char*  two;    
    char*  three;    
    char* result;

    cout  << "Enter three strings (10 characters or less) separated"          
          << " by blanks; press return."  << endl;    

    cin >> buffer1;
    cin >> buffer2;
    cin >> buffer3;

    one = new char[strlen(buffer1) + 1];
    two = new char[strlen(buffer2) + 1];
    three = new char[strlen(buffer3) + 1];
 
    one = buffer1;
    two = buffer2;
    three = buffer3;

    cout << "The strings you are putting together will be: " 
         << one << " " << two << " " << three << endl << endl;
 
    result = new char[strlen(one) + strlen(two) + strlen(three) + 1];

    strcpy(result, one);
    strcat(result, two);
    strcat(result, three);
  
    cout << "The final result is: " << result << endl << endl;

    delete  one;
    delete  two;
    delete  three;
    delete  result;

    return 0;

}   
$ CC dynamic2.cpp
$ a.out
Enter three strings (10 characters or less) separated by blanks; press return.
jh ohnhiller makermaker yeePlepopo
The strings you are putting together will be: johnhiller makermaker yeePlepopo

The final result is: johnhillermakermakeryeePlepopo

$ 
script done on Mon Nov  6 16:16:57 2000
// Mat_Mult.cpp 
// Name: John Hillert
// Date: 06/2000
// program Mat_Mult.cpp 
// This program fills two arrays and follows the following psuedocode:
// for each row i in matrix1 do:
//     for each column j in matrix 2 do:
//         for each column k in matrix1 do:
//             increase matrix3[i,j] by matrix1[i,k]*matrix2[k,j]
////////////////////////////////////////////////////////////////////////

typedef double** matPtr;

void intro();
// precondition: none needed
// postcondition: outputs message about program

void input(int& rows, int& columns, int& Rows, int& kolumns);
// precondition: takes empty matrix dimension variables 
// postcondition: asks for values of variables and takes them
 
void fillArray(matPtr array, int rews, int coolumns);
// precondition: takes an empty 2D array, and its rows and columns
// postcondition: fills in this array with inputs from the user

void printArray(matPtr third, int rows, int kolumns);
// precondition: takes filled 2D array, and its rows and columns
// postcondition: prints out contents of the array

#include<iostream.h>

main()
{  
    matPtr first, second, third;
    int rows, columns, Rows, kolumns;

    intro();
    input(rows, columns, Rows, kolumns);

    // THIS INITIALIZES FIRST MATRIX
    // first is an array of double pointers
    first = new double * [rows];
    // each first[i] is an array of doubles. first[i] is a pointer as array name
    for (int i = 0; i < rows; i++)
        first[i] = new double[columns];

    // THIS INITIALIZES SECOND MATRIX
    second = new double * [Rows];
    for (i = 0; i < Rows; i++)
       second[i] = new double[kolumns];
 
    // THIS INITIALIZES THIRD MATRIX
    third = new double * [rows];
    for (i = 0; i < rows; i++)
       third[i] = new double[kolumns];
    
    // HERE IS WHERE WE FILL BOTH MATRICES
    cout << "Enter the elements of the 1st matrix\n";
    fillArray(first, rows, columns);
    cout << "Enter the elements of the 2nd matrix\n";
    fillArray(second, Rows, kolumns);

    // HERE IS WHERE WE MULTIPLY 
    for(i = 0; i < rows; i++)
       for(int j = 0; j < kolumns; j++)
          for(int k = 0; k < columns; k++)
          {
             third[i][j] = first[i][k] * second[k][j] + third[i][j];
          }

    // NOW WE PRINT OUT FINAL MATRIX
    printArray(third, rows, kolumns);
 
    // RETURNING MEMORY TO FREE HEAP FOR REUSE
    for (i = 0; i < rows; i++)    
       delete [] first[i]; 
    delete [] first;
   
    for (i = 0; i < Rows; i++)
       delete [] second[i];
    delete [] second;

    for (i = 0; i < rows; i++)
       delete [] third[i];
    delete [] third;

    return 0;
}

//****************************************************************************

void intro()
{
   cout << "\nThis program multiplies two matrices together\n"
        << "and outputs the resulting matrix. Note that for\n"
        << "matrices to be multiplied, the number of columns\n"
        << "in the 1st matrix have to equal the numer of \n"
        << "rows in the 2nd.\n\n\n";
} 

//****************************************************************************

void input(int& rows, int& columns, int& Rows, int& kolumns)
{
   cout << "Enter the number of rows for 1st matrix: ";
   cin >> rows;
   cout << "Enter a number for both the columns of 1st\n"
        << "matrix and rows of second matrix: ";
   cin >> columns;
   Rows = columns;
   cout << "Enter number of columns in 2nd matrix: ";
   cin >> kolumns;
   cout << endl;
}

//**************************************************************************** 

void fillArray(matPtr array, int rews, int coolumns)
{ 
   for(int i = 0; i < rews; i++)
      for(int j = 0; j < coolumns; j++)
      {
         cout << '[' << i << ',' << j << "]: ";
         cin >> array[i][j];
         cout << endl;
      }
}

//****************************************************************************

void printArray(matPtr third, int rows, int kolumns)
{
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < kolumns; j++)
         cout << "[" << i << "," << j << "]: " << third[i][j] << " ";
      cout << endl;
   }
}
   
Script started on Tue Nov  7 00:26:24 2000
$ catM  matrix.C
// Matrix.C
// Name: John Hillert
// Date: 06/2000
// program matrix.C 
// dynamic allocation of a two dimensional double array
////////////////////////////////////////////////////////////////////////

void fillArray(double **, int rows, int columns);
// precondition: takes an empty 2D array, and its rows and columns
// postcondition: fills in this array with inputs from the user

void printArray(double ** u, int rows, int columns);
// precondition: takes filled 2D array, and its rows and columns
// postcondition: prints out contents of the array

#include<iostream.h>

main()
{  
    double ** u ;
    int rows,columns;
  
    cout<< "Enter the number of rows";
    cin >> rows;
    cout<< "Enter the number of columns";
    cin >> columns;

    // u is an array of double pointers
    u = new double * [rows];
    // each u[i] is an array of doubles. u[i] is a pointer as array name
    for (int i = 0; i<rows; i++)
        u[i] = new double[columns];

    fillArray(u, rows, columns);
 
    printArray(u, rows, columns);

    // Returning memory to free heap for reuse
    for (i = 0; i< rows; i++)
        delete [] u[i];
    delete [] u;
}

void fillArray(double ** u, int rows, int columns)
{
   cout << "Enter the elements" << endl;
   for(int i = 0; i < rows; i++)
      for (int j = 0; j < columns; j++)
      {
         cout << '[' << i << ',' << j << "]: ";
         cin >> u[i][j];
         cout << endl;
      }
} 
void printArray(double ** u, int rows, int columns)
{
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < columns; j++)
         cout << "[" << i << "," << j << "]: " << u[i][j] << "  ";
      cout << endl;
   }
}

$ CC matrix.C
$ a.out
Enter the number of rows2
Enter the number of columns2
Enter the elements
[0,0]: 2

[0,1]: 3

[1,0]: 
3

[1,1]: 1

[0,0]: 2  [0,1]: 3  
[1,0]: 3  [1,1]: 1  
$ a.out
Enter the number of rows3
Enter the number of columns3
Enter the elements
[0,0]: 7

[0,1]: 2

[0,2]: 4

[1,0]: 2

[1,1]: 9

[1,2]: 1

[2,0]: 8

[2,1]: 10

[2,2]: 3

[0,0]: 7  [0,1]: 2  [0,2]: 4  
[1,0]: 2  [1,1]: 9  [1,2]: 1  
[2,0]: 8  [2,1]: 10  [2,2]: 3  
$ 1 3 a.out
Enter the number of rows2
Enter the number of columns3
Enter the elements
[0,0]: 1

[0,1]: 2

[0,2]: 3

[1,0]: 6

[1,1]: 8

[1,2]: 1

[0,0]: 1  [0,1]: 2  [0,2]: 3  
[1,0]: 6  [1,1]: 8  [1,2]: 1  
$ cat MatM _Mult.cpp
// Mat_Mult.cpp 
// Name: John Hillert
// Date: 06/2000
// program Mat_Mult.cpp 
// This program fills two arrays and follows the following psuedocode:
// for each row i in matrix1 do:
//     for each column j in matrix 2 do:
//         for each column k in matrix1 do:
//             increase matrix3[i,j] by matrix1[i,k]*matrix2[k,j]
////////////////////////////////////////////////////////////////////////

typedef double** matPtr;

void intro();
// precondition: none needed
// postcondition: outputs message about program

void input(int& rows, int& columns, int& Rows, int& kolumns);
// precondition: takes empty matrix dimension variables 
// postcondition: asks for values of variables and takes them
 
void fillArray(matPtr array, int rews, int coolumns);
// precondition: takes an empty 2D array, and its rows and columns
// postcondition: fills in this array with inputs from the user

void printArray(matPtr third, int rows, int kolumns);
// precondition: takes filled 2D array, and its rows and columns
// postcondition: prints out contents of the array

#include<iostream.h>

main()
{  
    matPtr first, second, third;
    int rows, columns, Rows, kolumns;

    intro();
    input(rows, columns, Rows, kolumns);

    // THIS INITIALIZES FIRST MATRIX
    // first is an array of double pointers
    first = new double * [rows];
    // each first[i] is an array of doubles. first[i] is a pointer as array name
    for (int i = 0; i < rows; i++)
        first[i] = new double[columns];

    // THIS INITIALIZES SECOND MATRIX
    second = new double * [Rows];
    for (i = 0; i < Rows; i++)
       second[i] = new double[kolumns];
 
    // THIS INITIALIZES THIRD MATRIX
    third = new double * [rows];
    for (i = 0; i < rows; i++)
       third[i] = new double[kolumns];
    
    // HERE IS WHERE WE FILL BOTH MATRICES
    cout << "Enter the elements of the 1st matrix\n";
    fillArray(first, rows, columns);
    cout << "Enter the elements of the 2nd matrix\n";
    fillArray(second, Rows, kolumns);

    // HERE IS WHERE WE MULTIPLY 
    for(i = 0; i < rows; i++)
       for(int j = 0; j < kolumns; j++)
          for(int k = 0; k < columns; k++)
          {
             third[i][j] = first[i][k] * second[k][j] + third[i][j];
          }

    // NOW WE PRINT OUT FINAL MATRIX
    printArray(third, rows, kolumns);
 
    // RETURNING MEMORY TO FREE HEAP FOR REUSE
    for (i = 0; i < rows; i++)    
       delete [] first[i]; 
    delete [] first;
   
    for (i = 0; i < Rows; i++)
       delete [] second[i];
    delete [] second;

    for (i = 0; i < rows; i++)
       delete [] third[i];
    delete [] third;

    return 0;
}

//****************************************************************************

void intro()
{
   cout << "\nThis program multiplies two matrices together\n"
        << "and outputs the resulting matrix. Note that for\n"
        << "matrices to be multiplied, the number of columns\n"
        << "in the 1st matrix have to equal the numer of \n"
        << "rows in the 2nd.\n\n\n";
} 

//****************************************************************************

void input(int& rows, int& columns, int& Rows, int& kolumns)
{
   cout << "Enter the number of rows for 1st matrix: ";
   cin >> rows;
   cout << "Enter a number for both the columns of 1st\n"
        << "matrix and rows of second matrix: ";
   cin >> columns;
   Rows = columns;
   cout << "Enter number of columns in 2nd matrix: ";
   cin >> kolumns;
   cout << endl;
}

//**************************************************************************** 

void fillArray(matPtr array, int rews, int coolumns)
{ 
   for(int i = 0; i < rews; i++)
      for(int j = 0; j < coolumns; j++)
      {
         cout << '[' << i << ',' << j << "]: ";
         cin >> array[i][j];
         cout << endl;
      }
}

//****************************************************************************

void printArray(matPtr third, int rows, int kolumns)
{
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < kolumns; j++)
         cout << "[" << i << "," << j << "]: " << third[i][j] << " ";
      cout << endl;
   }
}
   
$ CC Mat_Mult.cpp
$ a.out

This program multiplies two matrices together
and outputs the resulting matrix. Note that for
matrices to be multiplied, the number of columns
in the 1st matrix have to equal the numer of 
rows in the 2nd.


Enter the number of rows for 1st matrix: 2
Enter a number for both the columns of 1st
matrix and rows of second matrix: 2
Enter number of columns in 2nd matrix: 2

Enter the elements of the 1st matrix
[0,0]: 2

[0,1]: 3

[1,0]: 3

[1,1]: 1

Enter the elements of the 2nd matrix
[0,0]: 5

[0,1]: 1

[1,0]: 3

[1,1]: 9

[0,0]: 19 [0,1]: 29.0001 
[1,0]: 18 [1,1]: 12 
$ a.out

This program multiplies two matrices together
and outputs the resulting matrix. Note that for
matrices to be multiplied, the number of columns
in the 1st matrix have to equal the numer of 
rows in the 2nd.


Enter the number of rows for 1st matrix: 3
Enter a number for both the columns of 1st
matrix and rows of second matrix: 3
Enter number of columns in 2nd matrix: 3

Enter the elements of the 1st matrix
[0,0]: 1

[0,1]: 2

[0,2]: 4

[1,0]: 8

[1,1]: 7

[1,2]: 5

[2,0]: 6

[2,1]: 9

[2,2]: 5

Enter the elements of the 2nd matrix
[0,0]: 4

[0,1]: 5

[0,2]: 6

[1,0]: 5

[1,1]: 7

[1,2]: 8

[2,0]: 5

[2,1]: 4

[2,2]: 5

[0,0]: 34 [0,1]: 35 [0,2]: 42 
[1,0]: 92 [1,1]: 109 [1,2]: 4.3956e+209 
[2,0]: 94 [2,1]: 113 [2,2]: 133 
$ well that's about it.  I can't figure out tha e u buf g.  Any suggestions?
sh: well:  not found
$ ^D
script done on Tue Nov  7 00:29:20 2000
