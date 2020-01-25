Received: from larkspur.Mines.EDU (larkspur.Mines.EDU [138.67.2.4])
	by slate.Mines.EDU (AIX4.3/8.9.3/8.9.1) with ESMTP id OAA87868
	for <jhillert@mines.edu>; Fri, 8 Sep 2000 14:58:50 -0600
Received: (from lejohnso@localhost)
	by larkspur.Mines.EDU (8.9.1/8.9.1) id OAA450973
	for jhillert; Fri, 8 Sep 2000 14:58:50 -0600 (MDT)
Date: Fri, 8 Sep 2000 14:58:50 -0600 (MDT)
From: Johnson <lejohnso@larkspur.Mines.EDU>
Message-Id: <200009082058.OAA450973@larkspur.Mines.EDU>
X-UIDL: XF>!!_n+"!c4O"!~]@"!

Grade Report for Lab 2 MACS 261 F


       Pre-lab    _____________ 0 /  2 pts

       Exercise 1  ____________ 4 /  4 pts
      
          Header correct  2
          Blanks filled   2

       Exercise 2  ____________ 4 / 4 pts
    
          Header correct  2
          Problem correct
            with correct 
            formatting    2

        Total      _____________ 8/ 10 pts



Comments:

Where is the prelab ???????      -2



Script started on Sat Sep  2 14:50:05 2000
$ cat blanks.cpp
/////////////////////////////////////////////////////////////////
//                                                             //
// Name: John Hillert                                          //
// Date: August 25, 2000                                       //
// Purpose:  Fill in the blanks                                //
//                                                             //
/////////////////////////////////////////////////////////////////
                                                            

#include<iostream.h>  

const double SERVICECharge = 25.00,
             COSTPerFoot   =  2.00,      // used to avoid magic constants
             FEETPerYard   =  3.00;
int main()

{ 

     // Declaration of local variables
     int Installations;   // number of installations
     double YardsOfCable,   // yards of cable  
            Revenue;        // This is the amount of money made

     // Input section with prompts to the screen
     cout  << "\nPlease enter : "
           << "\n\tthe number of installations. ";

     cin   >> Installations;
      
     cout  << "\n\tthe yard of cable used. "; 

     cin   >> YardsOfCable;

     // Calculate Revenue
     Revenue = Installations * SERVICECharge + COSTPerFoot * 
               FEETPerYard * YardsOfCable;

     // Print results to the screen
     cout  << "\nThe revenue generated is $" << Revenue << "\n\n";



     return 0;

}  

$ CC prog    blanks.cpp
$ a.out blanks.cpp

Please enter : 
	the number of installations. 27

	the yard of cable used. 263.0

The revenue generated is $2253

$ ^D
script done on Sat Sep  2 14:50:43 2000
Script started on Sat Sep  2 15:40:10 2000
$ cat numbers.cpp
//////////////////////////////////////////////////
//                                              //
// Name: John Hillert                           //
// Date: 9/2/00                                 //
// Purpose: this is a program that divides the  //
// sum of two numbers by the sum of three       //
// numbers.                                     //
//                                              // 
//////////////////////////////////////////////////
                                    

// Program Shell-- numbers.cpp 

#include <iostream.h>

const int numbera = 1066; // these are
const int numberb = 1942; // the variables
const int numberc = 512;  // in the 
const int numberd = 1;    // equation
const int numbere = -23;  //                                                  

int main ()
{                                                       
        
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(4); // we want four decimals

	float answer;

	answer = (float) (numbera + numberb) / (numberc + numberd + numbere); // the equation

	cout << answer << endl; // display answer
 
	return 0;
}

$ CC numbers.cpp
$ a.out numbers.cpp
6.1388
$ ^D

script done on Sat Sep  2 15:40:32 2000

script done on Sat Sep  2 15:40:32 2000
