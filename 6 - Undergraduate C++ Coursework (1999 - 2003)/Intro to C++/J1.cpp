Received: from larkspur.Mines.EDU (larkspur.Mines.EDU [138.67.2.4])
	by slate.Mines.EDU (AIX4.3/8.9.3/8.9.1) with ESMTP id GAA148110
	for <jhillert@mines.edu>; Mon, 18 Sep 2000 06:01:55 -0600
Received: (from lejohnso@localhost)
	by larkspur.Mines.EDU (8.9.1/8.9.1) id GAA1521800
	for jhillert; Mon, 18 Sep 2000 06:01:55 -0600 (MDT)
Date: Mon, 18 Sep 2000 06:01:55 -0600 (MDT)
From: Johnson <lejohnso@larkspur.Mines.EDU>
Message-Id: <200009181201.GAA1521800@larkspur.Mines.EDU>
X-UIDL: &8f"!MJ$!!mXM"!2j="!

Grade Report for Assignment2

        PartI:
          Correct answers to questions   ____0___  10 pts

        PartII:
          Program1: Miles Per Hour       ___15___ 15 pts
               Header present    3pts
               Comments          2pts
               Correctly solves problem 8 pts
               Correct typescript 2pts
                                         
          Program2: Distance Table        ___15___ 15 pts   
               Header present    3pts
               Comments          2pts
               Correctly solves problem 8 pts
               Correct typescript 2pts


          Total                          ____30__ 40 pts

Comments:

I can not find the answers to Part I         -10


Script started on Tue Sep 12 19:35:17 2000
$ cat programa.cpp
// John Hillert                                                     //
// Program 1 - homework II                                          //
// Problem: make a program that calculates and displays a car speed //
// according to a given radar gun frequency.                        //
//////////////////////////////////////////////////////////////////////
//
//
//
// Program Plan
// 1. have a constant variable for the gun's inherent f0 and for the 
// variable that comes back to the gun, f1. Have decimal value for
// the speed, but have later formula give it a value.
// 2. make sure these variables can have large decimal approximations
// to seven decimal places.
// 3. output purpose of the program
// 4. output both variables and describe them
// 5. use formula v = (6.685E+8) (f1-f0) / (f1+f0) for speed variable
// where v is speed  
// 6. display final speed

#include<iostream.h>

int main()
{

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(7);

    double f0 = 2E-10, 
           f1 = 2.0000004E-10;

    double speed;

    cout << "This program determines a car's velocity using frequencies\n"
         << "emitted and recieved by a radar gun used on that vehicle.\n"; 
    cout << endl;
    cout << "The initial frequency is 2E-10 meters.\n"
         << "The frequency returned is 2.0000004E-10 meters.\n";  

    speed = (6.685E+8) *  (f1-f0) / (f1+f0);

    cout.precision(2);

    cout << endl << speed
         << " mph\n";

    return 0; 
 
}

$ CC programa.cpp
$ a.out
This program determines a car's velocity using frequencies
emitted and recieved by a radar gun used on that vehicle.

The initial frequency is 2E-10 meters.
The frequency returned is 2.0000004E-10 meters.

66.85 mph
$ ^D
script done on Tue Sep 12 19:35:46 2000
Script started on Tue Sep 12 19:36:07 2000
$ cat programb.cpp
// John Hillert                                              //
// Program 2                                                 //
// Problem: build a program that gives you a certain cash    // 
// cost when a certain distance is inputted.                 //
///////////////////////////////////////////////////////////////
//
//
//
//
// Program algorithm:
// 1. declare double value Cost and integer value Distance
// 2. set decimal place to two
// 3. tell user with cout that cost varies with distance
// and to enter a distance
// 4. skip a line and tell user to enter a distance
// 5. set up several if, else if, else statements with appropriate boolian
// expressions
// 6. tell user his the cost related to the distance he entered

#include<iostream.h>

int main()
{

    int Distance;
    double Cost;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "Cost varies with distance.\n"
         << "Enter distance to find out cost:\n"; 

    cin >> Distance;
   
    if (Distance <= 100)
        Cost = 5.00; 
    else if (Distance <= 500)
        Cost = 8.00;
    else if (Distance < 1000)
        Cost = 10.00;
    else
        Cost = 11.50;

    cout << "The cost is: $" << Cost << endl;

    return 0;

}
$ CC programb.cpp
$ a.out
Cost varies with distance.
Enter distance to find out cost:
100
The cost is: $5.00
$ a.out
Cost varies with distance.
Enter distance to find out cost:
101
The cost is: $8.00
$ a.out
Cost varies with distance.
Enter distance to find out cost:
500
The cost is: $8.00
$ a.out
Cost varies with distance.
Enter distance to find out cost:
501
The cost is: $10.00
$ a.out
Cost varies with distance.
Enter distance to find out cost:
999
The cost is: $10.00
$ a.out
Cost varies with distance.
Enter distance to find out cost:
1000
The cost is: $11.50
$ a.out
Cost varies with distance.
Enter distance to find out cost:
100000000
The cost is: $11.50
$ ^D

script done on Tue Sep 12 19:37:42 2000

script done on Tue Sep 12 19:37:42 2000
