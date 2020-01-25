Received: from larkspur.Mines.EDU (larkspur.Mines.EDU [138.67.2.4])
	by slate.Mines.EDU (AIX4.3/8.9.3/8.9.1) with ESMTP id TAA92520
	for <jhillert@mines.edu>; Tue, 19 Sep 2000 19:05:07 -0600
Received: (from rspinhir@localhost)
	by larkspur.Mines.EDU (8.9.1/8.9.1) id TAA1537913
	for jhillert; Tue, 19 Sep 2000 19:05:02 -0600 (MDT)
Date: Tue, 19 Sep 2000 19:05:02 -0600 (MDT)
From: Spinhirne <rspinhir@larkspur.Mines.EDU>
Message-Id: <200009200105.TAA1537913@larkspur.Mines.EDU>
To: jhillert@larkspur.Mines.EDU
Subject: CS261F Lab4
X-UIDL: G9-"!ge5!!pnJ"!Rj="!

Grade Report for Lab 4

           Prelab               ______2____ 2 pts
           Typescript1   
                 correct values     1 pts
                 columns + formatting 1 pts 
                 header + comments 1 pts
                                
                                ______3____  3 pts
           Typescript2
                 EOF condition      1 pts
                 prompt and input   1 pts
                 header + comments  1 pts

                                ______3_____  3 pts
           Lesson 2
                 Typescript 3      ___2______ 2 pts

                 EC                  _0______ 3 pts

           Total                     _10______ 10 pts
                     
Script started on Thu Sep 14 13:35:14 2000
$ cat typos.cpp
// Program Typos prints three integer numbers, sums the numbers, calculates
// the average, and prints the sum and the average of the three numbers.

#include<iostream.h>
#include<iomanip.h>

const int ONE = 5;
const int TWO = 6;
const int THREE = 7;

int main ()
{
    int sum;
    int average;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.setf(ios::floatfield);

    cout << ONE << " " << TWO << " " << THREE << endl;
    sum = ONE + TWO + THREE;
    average = sum / 3;
    cout  << "The sum is "  << sum  << " and the average is "
	  << average << endl;
    return 0;
}
$ CC typose .scr         typos.cpp
$ a.out
5 6 7
The sum is 18 and the average is 6
$ ^D

script done on Thu Sep 14 13:35:47 2000
Script started on Fri Sep 15 10:43:23 2000
$ cat liters.cpp
// A program to convert Gallons to Liters
//

#include <iostream.h>
#include <iomanip.h>

main()
{
    const int MAX_GALLONS = 25;
    const int START_VAL = 5;
    const int STEP_SIZE = 1;
    int gallons;
    double liters;
    
    cout << "GALLONS           LITERS\n"
         << "_______         __________\n";

    // set gallons to start value

    gallons = START_VAL; 

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);

    while ( gallons <= MAX_GALLONS)
       {
          liters = (gallons * 3.785); 
          cout << setw(4) << gallons << setw(20) << liters << endl;
          gallons = gallons + STEP_SIZE;
       }
       return 0; 
}
$ CC liters.cpp
$ a.out
GALLONS           LITERS
_______         __________
   5              18.925
   6              22.710
   7              26.495
   8              30.280
   9              34.065
  10              37.850
  11              41.635
  12              45.420
  13              49.205
  14              52.990
  15              56.775
  16              60.560
  17              64.345
  18              68.130
  19              71.915
  20              75.700
  21              79.485
  22              83.270
  23              87.055
  24              90.840
  25              94.625
$ ^D

script done on Fri Sep 15 10:43:38 2000

script done on Fri Sep 15 10:43:38 2000
Script started on Sat Sep 16 12:58:07 2000
$ cat count.cpp
// Program Count prompts for, reads, echo prints, and sums a 
// fixed number of real (double) values.  The sum is printed.

#include <iostream.h>



int main ()
{                                                            
    double  sum;                     // summing variable          
    double realNumber;               // input value      
    sum = 0;              
   
    cout << endl << endl; 
    cout << "Enter a set of real numbers, one at a time.\n"
         << "Ctrl^D will show the sum of these numbers.\n" << endl;
        
    
    while (cin)                                  
    {

        cout << "Enter Real Number: ";
        cin >> realNumber;
        sum = sum + realNumber;
        cout << "The number entered is: " << realNumber << endl;
        realNumber = 0;
 
     }
    cout  << "Sum is "  << sum  << endl;
    return 0;
}

$ CC t count.cpp
$ a.out


Enter a set of real numbers, one at a time.
Ctrl^D will show the sum of these numbers.

Enter Real Number: 8.1
The number entered is: 8.1
Enter Real Number: 5.3
The number entered is: 5.3
Enter Real Number: 3.5
The number entered is: 3.5
Enter Real Number: -2.0
The number entered is: -2
Enter Real Number: .3
The number entered is: 0.3
Enter Real Number: 9.1
The number entered is: 9.1
Enter Real Number: 1.8
The number entered is: 1.8
Enter Real Number: 7.1
The number entered is: 7.1
Enter Real Number: 3.0
The number entered is: 3
Enter Real Number: 10.1^D^?  
The number entered is: 10.1
Enter Real Number: ^DThe number entered is: 0
Sum is 46.3
$ ^D
script done on Sat Sep 16 12:58:59 2000
Script started on Sat Sep 16 14:31:44 2000
$ a cat star.cpp
// Name: John Hillert                     //
// Date: 9/16/00                          //
// Purpose: To produce a pattern of stars //
// desirable to Barbara Jennings and the  //
// paper grader.                          // 
////////////////////////////////////////////

#include<iostream.h>

int main()
{

    int i, j;
    
    for (i = 1; i <= 5; i++)
        {
          for (j = 5; i <= j; j--)
              cout << '*';
          cout << endl;
        }

    return 0;
} 
$ CC star.cpp
$ a.out
*****
****
***
**
*
$ ^D

script done on Sat Sep 16 14:31:58 2000

script done on Sat Sep 16 14:31:58 2000
Script started on Thu Sep 14 13:35:14 2000
$ cat typos.cpp
// Program Typos prints three integer numbers, sums the numbers, calculates
// the average, and prints the sum and the average of the three numbers.

#include<iostream.h>
#include<iomanip.h>

const int ONE = 5;
const int TWO = 6;
const int THREE = 7;

int main ()
{
    int sum;
    int average;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.setf(ios::floatfield);

    cout << ONE << " " << TWO << " " << THREE << endl;
    sum = ONE + TWO + THREE;
    average = sum / 3;
    cout  << "The sum is "  << sum  << " and the average is "
	  << average << endl;
    return 0;
}
$ CC typose .scr         typos.cpp
$ a.out
5 6 7
The sum is 18 and the average is 6
$ ^D

script done on Thu Sep 14 13:35:47 2000
Script started on Fri Sep 15 10:43:23 2000
$ cat liters.cpp
// A program to convert Gallons to Liters
//

#include <iostream.h>
#include <iomanip.h>

main()
{
    const int MAX_GALLONS = 25;
    const int START_VAL = 5;
    const int STEP_SIZE = 1;
    int gallons;
    double liters;
    
    cout << "GALLONS           LITERS\n"
         << "_______         __________\n";

    // set gallons to start value

    gallons = START_VAL; 

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);

    while ( gallons <= MAX_GALLONS)
       {
          liters = (gallons * 3.785); 
          cout << setw(4) << gallons << setw(20) << liters << endl;
          gallons = gallons + STEP_SIZE;
       }
       return 0; 
}
$ CC liters.cpp
$ a.out
GALLONS           LITERS
_______         __________
   5              18.925
   6              22.710
   7              26.495
   8              30.280
   9              34.065
  10              37.850
  11              41.635
  12              45.420
  13              49.205
  14              52.990
  15              56.775
  16              60.560
  17              64.345
  18              68.130
  19              71.915
  20              75.700
  21              79.485
  22              83.270
  23              87.055
  24              90.840
  25              94.625
$ ^D

script done on Fri Sep 15 10:43:38 2000

script done on Fri Sep 15 10:43:38 2000
Script started on Sat Sep 16 12:58:07 2000
$ cat count.cpp
// Program Count prompts for, reads, echo prints, and sums a 
// fixed number of real (double) values.  The sum is printed.

#include <iostream.h>



int main ()
{                                                            
    double  sum;                     // summing variable          
    double realNumber;               // input value      
    sum = 0;              
   
    cout << endl << endl; 
    cout << "Enter a set of real numbers, one at a time.\n"
         << "Ctrl^D will show the sum of these numbers.\n" << endl;
        
    
    while (cin)                                  
    {

        cout << "Enter Real Number: ";
        cin >> realNumber;
        sum = sum + realNumber;
        cout << "The number entered is: " << realNumber << endl;
        realNumber = 0;
 
     }
    cout  << "Sum is "  << sum  << endl;
    return 0;
}

$ CC t count.cpp
$ a.out


Enter a set of real numbers, one at a time.
Ctrl^D will show the sum of these numbers.

Enter Real Number: 8.1
The number entered is: 8.1
Enter Real Number: 5.3
The number entered is: 5.3
Enter Real Number: 3.5
The number entered is: 3.5
Enter Real Number: -2.0
The number entered is: -2
Enter Real Number: .3
The number entered is: 0.3
Enter Real Number: 9.1
The number entered is: 9.1
Enter Real Number: 1.8
The number entered is: 1.8
Enter Real Number: 7.1
The number entered is: 7.1
Enter Real Number: 3.0
The number entered is: 3
Enter Real Number: 10.1^D^?  
The number entered is: 10.1
Enter Real Number: ^DThe number entered is: 0
Sum is 46.3
$ ^D
script done on Sat Sep 16 12:58:59 2000
Script started on Mon Sep 18 17:06:21 2000
$ cat star.cpp
// Name: John Hillert                     //
// Date: 9/16/00                          //
// Purpose: To produce a pattern of stars //
// desirable to Barbara Jennings and the  //
// paper grader.                          // 
////////////////////////////////////////////

#include<iostream.h>

int main()
{

    int i, j;
    
    for (i = 1; i <= 6; i++)
        {
          for (j = 6; i <= j; j--)
              cout << '*';
          cout << endl;
        }

    return 0;
} 
$ CC star.cpp[
ld32: FATAL   9  : I/O error (star.cpp[): No such file or directory
$ star.cpp
sh: star.cpp: cannot execute
$ CC star.cpp
$ vi st     a.out
******
*****
****
***
**
*
$ ^D

script done on Mon Sep 18 17:06:42 2000

script done on Mon Sep 18 17:06:42 2000
