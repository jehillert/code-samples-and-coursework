Received: from larkspur.Mines.EDU (larkspur.Mines.EDU [138.67.2.4])
	by slate.Mines.EDU (AIX4.3/8.9.3/8.9.1) with ESMTP id QAA110550
	for <jhillert@mines.edu>; Sat, 9 Dec 2000 16:08:45 -0700
Received: (from rspinhir@localhost)
	by larkspur.Mines.EDU (8.9.1/8.9.1) id QAA5785157
	for jhillert; Sat, 9 Dec 2000 16:08:40 -0700 (MST)
Date: Sat, 9 Dec 2000 16:08:40 -0700 (MST)
From: Spinhirne <rspinhir@larkspur.Mines.EDU>
Message-Id: <200012092308.QAA5785157@larkspur.Mines.EDU>
To: jhillert@larkspur.Mines.EDU
Subject: cs261f lab14
X-UIDL: !%C"!~iJ"!g,>!!PSB!!

Grade Report for Lab 

           Typescript1               ___4____ 4 pts
              Header and comments     1 pt
              factorial for 0!        1 pt
              correct use in main() of
                 factorial for combination formula  2 pts

           Typescript 2              ___3____ 3 pts
              Header and comments      1 pt
              correct function for Bob number  2 pts
              (must be recursive)

           Typescript 3		     ___3____ 3 pts
              Header and comments     1 pt
              correctfunction for array sum  2 pts
              (must be recursive)

           Total                     __10_____ 10 pts
                     
Script started on Sun Dec  3 15:24:17 2000
$ ^[  $ script -a typescript1$ rm typescript1       $ exit          $ a.out$ CC factorial.cpp$ cat factorial.cpp$ 
// factorial.cpp
// Last modified by: John Hillert
// Last modified: 12/03/00
// Factorial function -- an example of recursion 
#include <iostream.h>
#include <iomanip.h>

long C(long p, long m);
long Factorial(long);

main()
{
   long m, p;
 
   cout << "\nThis program lets the user calculate the number of possible \n" 
        << "combinations of \"m\" items taken \"p\" at a time.\n\n";
   cout << "Example: to calculate the number of 4 person committees that\n"
        << "can be formed from a pool of 10 people, enter 10 for \"m\",\n"
        << "and 4 for \"p\".\n\n"; 

   cout << "\n\nEnter \"m\": ";
   cin >> m;
   cout << "\n\nEnter \"p\": ";
   cin >> p;

   cout << "\n\nThe number of combinations is: " << C(p,m);
   cout << endl << endl;  

   return 0;
}

long C(long p, long m)
// Precondition: m or n is not neg
{
   long grouping;
   grouping = Factorial(m) / (Factorial(m - p) * Factorial(p));
   return grouping;
}
 
long Factorial(long number)
// Precondition: n is nonnegative
{
   if (number == 0)
      return 1;
   else if (number  == 1)
      return 1;
   else {
      return (number * Factorial(number - 1));
   }
}
$ ^[  $ cat factorial.cpp$ script -a typescript1$ rm typescript1       $ exit          $ a.out$ CC factorial.cpp$ 
$ a.out

This program lets the user calculate the number of possible 
combinations of "m" items taken "p" at a time.

Example: to calculate the number of 4 person committees that
can be formed from a pool of 10 people, enter 10 for "m",
and 4 for "p".



Enter "m": 10


Enter "p": 4


The number of combinations is: 210

$ exit

script done on Sun Dec  3 15:24:34 2000
Script started on Sun Dec  3 22:59:57 2000
$ cat bob.cpp
// Program: bob.cpp
// Last Modified: 12/3/00
// Last Modified by: John Hillert
// This program finds BobNumbers
// Formula: f(n) = f(n-2) - f(n-1)
// Base Case: when n = 2, and n = 1, return 3 and 2 respectively
///////////////////////////////////////////////////////////////////////
 
#include <iostream.h>

long BobNumber(long);

main()
{
    long result, number;

    cout << "Enter an integer: ";
    cin >> number;
    result = BobNumber(number);
    cout << "BobNumber(" << number << ") = " << result << endl;
    return 0;
}

// Recursive definition of function BobNumber 
long BobNumber(long n)
{
   if (n == 1)
      return 2;
   if (n == 2)
      return 3;
   else
      return (n * (BobNumber(n - 2) - BobNumber(n - 1)));
}
$ CC bob.cpp
$ a.out
Enter an integer:  
5
BobNumber(5) = -135
$ a.out
Enter an integer: 4
BobNumber(4) = 24
$ a.out
Enter an integer: 3
BobNumber(3) = -3
$ a.out
Enter an integer: 2
BobNumber(2) = 3
$ a.out
Enter an integer: 1
BobNumber(1) = 2
$ 
$ ^D

script done on Sun Dec  3 23:00:48 2000

script done on Sun Dec  3 23:00:48 2000
Script started on Sun Dec  3 23:01:00 2000
$ CC array.cpp
$ catr    array.cpp
// array.cpp
// Programmer: John Hillert
// Date: 12/03/00
// Purpose:  This program tests a function to add all the values
// in a one-dimensional array.
// Base Case: when array element -1 is reached, return 0
////////////////////////////////////////////////////////////////
#include<iostream.h>

const int size = 25;

void FillArray(int a[], int size2);
int AddArray(int a[], int size2); 

int main()
{
   int array[size];
   int size2;

   cout << "\n\nThis program tests a function that adds all the values\n"
 	<< "of a 25 element one-dimensional array.\n\n";

   cout << "Enter the number of values you wish to enter (25 max): ";
   cin >> size2;

   FillArray(array, size2); 
   cout << endl << "The sum of the array is: " 
        << AddArray(array, size2) << endl << endl; 

   return 0;
}

void FillArray(int a[], int size2)
{
   for(int i = 0; i < size2; i++)
   {
      cout << "\n\nEnter an integer value for array[" << i << "]: ";
      cin >> a[i];
   }  
}

int AddArray(int a[], int size2)
{
   if(size2 < 1)
      return 0;
   return AddArray(a, size2 - 1) + a[size2 - 1];
}    

$ CC array.cpp
$ a.out


This program tests a function that adds all the values
of a 25 element one-dimensional array.

Enter the number of values you wish to enter (25 max): 14


Enter an integer value for array[0]: 14


Enter an integer value for array[1]: 53


Enter an integer value for array[2]: 22


Enter an integer value for array[3]: 13


Enter an integer value for array[4]: 66


Enter an integer value for array[5]: 37


Enter an integer value for array[6]: 90


Enter an integer value for array[7]: 100


Enter an integer value for array[8]: 1


Enter an integer value for array[9]: 23


Enter an integer value for array[10]: 43


Enter an integer value for array[11]: 17


Enter an integer value for array[12]: 22


Enter an integer value for array[13]: 4

The sum of the array is: 505

$ 
$ exit

script done on Sun Dec  3 23:02:09 2000
