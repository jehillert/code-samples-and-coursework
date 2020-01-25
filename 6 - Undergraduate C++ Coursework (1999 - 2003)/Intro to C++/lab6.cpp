Received: from larkspur.Mines.EDU (larkspur.Mines.EDU [138.67.2.4])
	by slate.Mines.EDU (AIX4.3/8.9.3/8.9.1) with ESMTP id UAA45106
	for <jhillert@mines.edu>; Tue, 3 Oct 2000 20:16:26 -0600
Received: (from rspinhir@localhost)
	by larkspur.Mines.EDU (8.9.1/8.9.1) id UAA2476174
	for jhillert; Tue, 3 Oct 2000 20:16:23 -0600 (MDT)
Date: Tue, 3 Oct 2000 20:16:23 -0600 (MDT)
From: Spinhirne <rspinhir@larkspur.Mines.EDU>
Message-Id: <200010040216.UAA2476174@larkspur.Mines.EDU>
To: jhillert@larkspur.Mines.EDU
Subject: CS261F Lab6
X-UIDL: %[D!!$CH!!~mT"!>46"!

Grade Report for Lab 6

           Typescript1 
                 correct header                    1 pts  
                 correct printMenu() fn            1 pts
                 correct error(char) fn            1 pts 
                 correct loops for error checking  1 pts
                                
                                ____4______  4 pts
           Typescript2
                 correct header            0 pts
                 correct compute function  2 pts

                                ____2______ 3 pts
           Lesson 2
                 Typescript 3    
                  header              0 pts
                  corrections:    
                       reference parameters 1 pts
                       wrong order in cout statement  1 pts

                                 ___2______ 3 pts


           Total                     ____8___ 10 pts
                     
Script started on Mon Oct  2 22:16:31 2000
$ cat converta.cpp
// Program convert.cpp converts a temperature in Fahrenheit to
// Celsius or a temperature in Celsius to Fahrenheit 
// dpepending on whether the user enters an F or a C

#include <iostream.h>

double ConvertedTemp(double tempIn, char letter); 
// Precondition: Takes a Celcius or Fahrenheit
// value and a letter telling the function
// which temp that value is associated with
// Postcondition: returns a value converted to the 
// other temp. (example if C goes in then F comes out.)
  
void printMenu();
// Precondition: no parameters are needed
// Postcondition: A menu giving all input
// posibilities for the first part of the 
// function are given.

bool Error(char letter);
// Precondition: takes a character
// inputted after menu
// Postcondition: returns true if 
// value is letter is not C,F, or Q
 
int main ()
{
    char  letter;               // Place to store input letter
    double  tempIn;            // Temperature to be converted
    double  ConvertedTemp(double, char);
   
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
 
    printMenu();

    cin  >> letter;
    while (Error(letter) == true)
    {
        cout << "ERROR!\n"  
             << "The choice you have entered is incorrect.\n"
             << "Please try again, remembering that lowercase\n"
             << "letters are not valid choices.\n";
        cin >> letter;
    }
    while (letter != 'Q')
    {
        cout  << "Type an integer number, and press return." 
              << endl;
        cin  >> tempIn;
    
        if (letter == 'F')
            cout << "Fahrenheit to Celsius"  << endl;
        else 
            cout << "Celsius to Fahrenheit"  << endl;
        cout  << "Temperature to convert: "  << tempIn  
              << endl;
        cout  << "Converted temperature:  "  
              << ConvertedTemp(tempIn, letter) 
              << endl  << endl;
        cout  << "Type a C, F,  or Q; then press return."  
              << endl;

        cin  >> letter;
        while (Error(letter) == true)
        {
            cout << "ERROR!\n" 
                 << "The choice you have entered is incorrect.\n"
                 << "Please try again, remembering that lowercase\n"
  		 << "letters are not valid choices.\n";
            cin >> letter;
        } 

    }
return 0;
}
double ConvertedTemp(double tempIn, char letter)
{
    if (letter == 'C')
        return (9 * tempIn / 5) + 32;
    else
        return 5 * (tempIn - 32) / 9;
} 
void printMenu()
{
    cout << "Input Menu" << endl << endl;
    cout << "F: Convert from Fahrenheit to Celcius" << endl;
    cout << "C: Convert from Celsius to Fahrenheit" << endl;
    cout << "Q: Quit" << endl;
    cout << "Type a C, F, or Q; then press return." << endl;
    return;
}
bool Error(char letter)
{
    if (letter != 'F' && letter != 'C' && letter != 'Q')
        return true;
    else
        return false;
}

$ CC converta.cpp
$ a.out
Input Menu

F: Convert from Fahrenheit to Celcius
C: Convert from Celsius to Fahrenheit
Q: Quit
Type a C, F, or Q; then press return.

c C
Type an integer number, and press return.
0
Celsius to Fahrenheit
Temperature to convert: 0.0
Converted temperature:  32.0

Type a C, F,  or Q; then press return.
C
Type an integer number, and press return.
100
Celsius to Fahrenheit
Temperature to convert: 100.0
Converted temperature:  212.0

Type a C, F,  or Q; then press return.
c
ERROR!
The choice you have entered is incorrect.
Please try again, remembering that lowercase
letters are not valid choices.
F C
Type an integer number, and press return.
57
Celsius to Fahrenheit
Temperature to convert: 57.0
Converted temperature:  134.6

Type a C, F,  or Q; then press return.
F
Type an integer number, and press return.
42
Fahrenheit to Celsius
Temperature to convert: 42.0
Converted temperature:  5.6

Type a C, F,  or Q; then press return.
f
ERROR!
The choice you have entered is incorrect.
Please try again, remembering that lowercase
letters are not valid choices.
212
ERROR!
The choice you have entered is incorrect.
Please try again, remembering that lowercase
letters are not valid choices.
ERROR!
The choice you have entered is incorrect.
Please try again, remembering that lowercase
letters are not valid choices.
ERROR!
The choice you have entered is incorrect.
Please try again, remembering that lowercase
letters are not valid choices.
212   Q
$ 
script done on Mon Oct  2 22:18:22 2000
Script started on Mon Oct  2 22:18:38 2000
$ trianglea.cpp
sh: trianglea.cpp: cannot execute
$ a.  cat triangle^[  $ cat triangle
Cannot open triangle: No such file or directory
$ ^D
script done on Mon Oct  2 22:19:10 2000
Script started on Mon Oct  2 22:19:16 2000
*****************
YOU NEED TO INCLUDE YOUR NAME AND               
PROGRAM NUMBER IN THE HEADER
*****************
$ cat trianglea.cpp
// program to compute area and perimeter of a triangle given three
// sides
//

#include<iostream.h>
#include<math.h>

void compute( double a, double b, double c, double& perimeter, double&
area);
// Precondition:  Three doubles are entered that represent the sides
//                of a valid triangle.  
// Postcondition: The perimeter and area are returned by reference
//                


int main()
{
    double side1, side2, side3, trianglePerimeter = 0, triangleArea = 0;
   
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
 
    // Prompt the user for three doubles that represent the sides
    // of a triangle.  Allow for keyboard input afterwards
    cout << "Enter the lengths of the three sides of a triangle:";
    cout << "\n1: ";
    cin >> side1;

    while (cin)
    {  
        cout << "\n2: ";
        cin >> side2;
        cout << "\n3: ";
        cin >> side3;

        // the valid condition concerns the hypotenuse and the sum
        // of the two other sides.  If one side (or any side for that matter)
        // is greater than the sum of the other two than a triangle can't be 
        // formed.

        if (side1 < side2 + side3 && side2 < side1 + side3 && side3 < side1 + side2)  
        {
    
            compute(side1,side2,side3,trianglePerimeter,triangleArea);
            cout << "\nThe perimeter is " << trianglePerimeter 
	    << " and the area is " << triangleArea << endl;

        }
    
       else
           cout << "\nThe values you have provided will not form a triangle."
                << "\nPlease give new values.\n"; 
        cout << "\nEnter the three side lengths of a triangle:";
        cout << "\n1: ";
        cin >> side1;
    }
    return 0; 
}

void compute( double a, double b, double c, double& perimeter, double& area)
{
   double s;
   perimeter = a + b + c;
   s = perimeter / 2;
   area = sqrt(s * (s - a) * (s - b) * (s - c));
}
   
$ CC trianglea.cpp
$ a.out
Enter the lengths of the three sides of a triangle:
1: 12 

2: 2

3: 3

The values you have provided will not form a triangle.
Please give new values.

Enter the three side lengths of a triangle:
1: 3

2: 4

3: 5

The perimeter is 12.0 and the area is 6.0

Enter the three side lengths of a triangle:
1: 7

2: 8

3: 9

The perimeter is 24.0 and the area is 26.8

Enter the three side lengths of a triangle:
1: 10

2: 20

3: 30

The values you have provided will not form a triangle.
Please give new values.

Enter the three side lengths of a triangle:
1: Q
$ ^D
script done on Mon Oct  2 22:20:11 2000
Script started on Mon Oct  2 22:20:19 2000
$ cat driver.cpp
// Program Driver is a program to test function Swap
*****************
YOU NEED TO INCLUDE YOUR NAME AND               
PROGRAM NUMBER IN THE HEADER
*****************

#include <iostream.h>

void  Swap(int&, int&);

int main ()
{
    int  x;
    int  y;
    cout  << "Enter two integer values; press return."  << endl;
    cin  >> x  >> y;

    cout  << "Input values: "  << x  << " and "  << y  << endl;
    Swap(x, y);
    cout  << "Values swapped: "  << x  << " and "  << y  << endl;
    return 0;
}

// ***************************************

void  Swap(int& a, int& b)
{
    int x;

    x = a;
    a = b;
    b = x;
}


$ CC s driver.cpp
$ a.out
Enter two integer values; press return.
5
10
Input values: 5 and 10
Values swapped: 10 and 5
$ a.out
Enter two integer values; press return.
77
102
Input values: 77 and 102
Values swapped: 102 and 77
$ a.out
Enter two integer values; press return.
-77
102
Input values: -77 and 102
Values swapped: 102 and -77
$ the s and       x and y were                Note: the x and w y were sdcr   rewed up         screwed up in the line before retun  urn0 and there were no&  "&"'s in ht  the funt  nct  ction cla  akl  ll    prototype or defintion.
> 
script done on Mon Oct  2 22:22:36 2000
