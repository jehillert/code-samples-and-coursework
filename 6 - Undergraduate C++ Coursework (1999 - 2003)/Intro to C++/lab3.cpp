Received: from larkspur.Mines.EDU (larkspur.Mines.EDU [138.67.2.4])
	by slate.Mines.EDU (AIX4.3/8.9.3/8.9.1) with ESMTP id AAA53798
	for <jhillert@mines.edu>; Wed, 13 Sep 2000 00:55:10 -0600
Received: (from rspinhir@localhost)
	by larkspur.Mines.EDU (8.9.1/8.9.1) id AAA1139618
	for jhillert; Wed, 13 Sep 2000 00:55:07 -0600 (MDT)
Date: Wed, 13 Sep 2000 00:55:07 -0600 (MDT)
From: Spinhirne <rspinhir@larkspur.Mines.EDU>
Message-Id: <200009130655.AAA1139618@larkspur.Mines.EDU>
To: jhillert@larkspur.Mines.EDU
Subject: CS261 Lab3
X-UIDL: ?(i!!/c]!!d^H!!ni~"!

Grade Report for Lab 3
                                                 Possible
                                                  Points 

          Prelab                 __________3_____  3 pts

          Exercise 1
               Compound condition
                &&  used to bracket
               condition with no else's  __2_____  2 pts

               Nested if else used to
               build table process
               with no &&'s              __2_____  2 pts


          Exercise 2     
               Submitted with multiple
               test cases run.           __2_____  3 pts


          Total                          __9_____  10 pts
  
Comments:







John Hillert
C++ Programming 10:00


a:

A B    !A&&B B&&!A
T T    F     F
T F    F     F
F T    T     T
F F    F     F

these are equivalent

b:

A B    !(A&&B)    A||B
T T    F          T
T F    F          T
F T    F          T
F F    T          F

these are not equivalent

c:

A B C  A&&(B||C)  (A&&B)||C
T T T  T          T
T T F  T          T
T F T  T          T
T F F  F          F
F T T  F          T
F T F  F          F
F F T  F          T
F F F  F          F

these are not equivalent

d:

A B C  (A&&B||C)  !(A||B&&C)
T T T  T          F
T T F  T          F
T F T  T          F
T F F  F          F
F T T  T          F
F T F  F          T
F F T  T          T
F F F  F          T

these are not equivalent

e:

A==B C<D A!=B C<=D (A==B)&&(C<D)) (A!=B)||(C<=D)
T    T   F    T    T              T
F    T   T    T    F              T
T    F   F    T    F              T
F    F   T    F    F              T

these are not equivalent

The solution sets are not equal to each other in all circumstances so b,c,d, and e 
have two expressions that aren't equivalent to each other
  

Script started on Sun Sep 10 16:33:38 2000
$ cat shell3a.cpp
// Name: John Hillert
// Date: 08/08/00
// Purpose:  
// shell3a.cpp is a program that reads the number of cubic meters
// of natural gas from the keyboard and determines the amount to
// charge the customer.
/////////////////////////////////////////////////////////////////////////
#include <iostream.h>

int main ()
{   
    double gas, bill;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << " Enter the cubic meters of natural gas used: ";
    cin >> gas;
   
 
    if (gas <= 70)
       bill = 5.00;
    if (gas > 70 && gas <= 170)
       bill = 5.00 + (gas - 70) * .05;
    if (gas > 170 && gas <= 400)
       bill = 10.00 + (gas - 170) * .025;
    if (gas > 400) 
       bill = 15.75 + (gas - 400) * .015;      





    cout << "The amout to pay is: $" << bill << endl;
    
    return 0;
}

$ catt    CC shell3a.cpp
$ a.out h shell3a.cpp
 Enter the cubic meters of natural gas used: 50
The amout to pay is: $5.00
$ a.out shell3a.cpp
 Enter the cubic meters of natural gas used: 160
The amout to pay is: $9.50
$ a.out shell3a.cpp
 Enter the cubic meters of natural gas used: 390
The amout to pay is: $15.50
$ a.out shell3a.cpp
 Enter the cubic meters of natural gas used: 410
The amout to pay is: $15.90
$ ^D

script done on Sun Sep 10 16:35:37 2000

script done on Sun Sep 10 16:35:37 2000
Script started on Sun Sep 10 16:47:37 2000
$ cat shell3a.cpp
// Name: John Hillert
// Date: 08/08/00
// Purpose:  
// shell3a.cpp is a program that reads the number of cubic meters
// of natural gas from the keyboard and determines the amount to
// charge the customer.
/////////////////////////////////////////////////////////////////////////
#include <iostream.h>

int main ()
{   
    double gas, bill;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << " Enter the cubic meters of natural gas used: ";
    cin >> gas;
   
 
    if (gas <= 70)
       bill = 5.00;
    else if (gas <= 170)
       bill = 5.00 + (gas - 70) * .05;
    else if (gas <= 400)
       bill = 10.00 + (gas - 170) * .025;
    else  
       bill = 15.75 + (gas - 400) * .015;      





    cout << "The amout to pay is: $" << bill << endl;
    
    return 0;
}

$ CC shell3a.cpp
$ a.out
 Enter the cubic meters of natural gas used: 5 60  50
The amout to pay is: $5.00
$ a.out
 Enter the cubic meters of natural gas used: 160
The amout to pay is: $9.50
$ a.out] 
 Enter the cubic meters of natural gas used: 390
The amout to pay is: $15.50
$ a.out
 Enter the cubic meters of natural gas used: 410
The amout to pay is: $15.90
$ ^D
script done on Sun Sep 10 16:48:26 2000
Script started on Sun Sep 10 19:56:47 2000
$ cat pest.cpp
// Program pest.cpp reads reads in values from the user,
// decides if the airplane can apply pesticides and
// prints out an appropriate message.  
#include <iostream.h>
                                                            
int main ()
{     
       int  temp;    
       int  humid;    
       int  wind; 
                                                           
       cout  << "Enter the temperature; press return"  << endl;    
       cin  >> temp;    
       cout  << "Enter the relative humidity; press return"  << endl;    
       cin  >> humid;    
       cout  << "Enter the wind speed in mph; press return."  << endl;    
       cin  >> wind;       


       if (temp >= 70 && humid >= 15 && humid <= 35 && wind <= 10) 
           cout << "Conditions are satisfactory.  It is safe to spray.\n";
      else
          cout << "Warning!!! Spraying conditions unsafe.\n";



       return 0;
}                          
$ CC pest.cpp
$ a.out
Enter the temperature; press return
69
Enter the relative humidity; press return
15
Enter the wind speed in mph; press return.
0
Warning!!! Spraying conditions unsafe.
$ 
script done on Sun Sep 10 19:57:43 2000
**********
YOU SHOULD HAVE TRIED MORE TEST CASES TO SHOW ALL POSSIBLITIES
**********

