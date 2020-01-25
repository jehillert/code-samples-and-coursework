Received: from larkspur.Mines.EDU (larkspur.Mines.EDU [138.67.2.4])
	by slate.Mines.EDU (AIX4.3/8.9.3/8.9.1) with ESMTP id MAA45026
	for <jhillert@mines.edu>; Wed, 27 Sep 2000 12:29:35 -0600
Received: (from rspinhir@localhost)
	by larkspur.Mines.EDU (8.9.1/8.9.1) id MAA2130475
	for jhillert; Wed, 27 Sep 2000 12:29:30 -0600 (MDT)
Date: Wed, 27 Sep 2000 12:29:30 -0600 (MDT)
From: Spinhirne <rspinhir@larkspur.Mines.EDU>
Message-Id: <200009271829.MAA2130475@larkspur.Mines.EDU>
To: jhillert@larkspur.Mines.EDU
Subject: cs261f Lab5
X-UIDL: ]"e"!V#)"!:&+!!(m>!!

Grade Report for Lab 5

           Prelab               _____1_____ 1 pts
           Typescript1   
                 correct values     1 pts
                 columns + formatting 0 pts 
                 header + comments 1 pts
                                
                                _____2_____  3 pts
           Typescript2
                 overloaded functions 2 pts
                 header + comments  1 pts

                                _____3_____ 3 pts
           Lesson 2
                 Typescript 3    
                 correct algorithm 2pts
                 header + comments 0pt
                                 ____2_____ 3 pts


           Total                     ___8____ 10 pts
                     
Script started on Fri Sep 22 00:36:24 2000
$ cat average.cpp
//Illustrates overloading the function name ave.
#include<iostream.h>

	double ave(double n1, double n2);
        // Precondition: The function accepts two values, n1 and n2,
        //                of type double 
	// Postcondition: Returns the average of the two numbers n1 and n2.

	double ave(double n1, double n2, double n3);
        //Precondition:   The functions accepts three values, n1, n2, and n3,
        //                of type double 
	//Postcondition:  Returns the average of the three numbers 
        //                n1, n2, and n3.

	int main( )
	{
	    cout << "The average of 2.0, 2.5, and 3.0 is "
	         << ave(2.0, 2.5, 3.0) << endl;
   
	    cout << "The average of 4.5 and 5.5 is "
	         << ave(4.5, 5.5) << endl;
   
	    return 0;
	}

	double ave(double n1, double n2)
	{
	    return ((n1 + n2)/2.0);
	}

	double ave(double n1, double n2, double n3)
	{
		 return ((n1 + n2 + n3)/3.0);
	}
$ CC average.cpp
$ a.out
The average of 2.0, 2.5, and 3.0 is 2.5
The average of 4.5 and 5.5 is 5
$ ^D
script done on Fri Sep 22 00:36:37 2000
Script started on Sun Sep 24 14:59:44 2000
$ cat ftcc .cpp
// Name: John Hillert                          //
// Lab: 5 Temperature Tables                   //
// Date: 9/23/00                               //
// Problem: convert Celcius to Fahrenheit      //
// and Fahrenheit to Celcius in five columns   //
// each.                                       //
////////////////////////////////////////////////
 
#include<iostream.h>
#include<iomanip.h>

double FahrenheitToCelsius(double F);
// Precondition: Start with a double value that represents
// a Fahrenheit temperature
// Postcondition: Returns the converted temperature in Celsius 

double CelsiusToFahrenheit(double C); // converts C to F
// Precondition: Start with a double value that represents 
// a Celsius temperature
// Postcondition: Returns the converted temperature in Fahrenheit

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1); 
    cout.setf(ios::left);

    int C, F;
    double tempF, tempC;
    int counter, counter1;
 
    C = 0;   // these are the start values
    F = 32;
 
    counter = 1; // preset counters 
    counter1 = 1; 
    
    // THIS IS THE LOOP FOR THE C TO F TABLE 
    while (counter <= 20) 
    {
        while (counter1 <= 5)           // this loop  
        {                               // is the heading
            cout << setw(7) << "C" << setw(10) << "F"; // for the temp
            counter1++;                                // readouts 
        }			
        cout << endl; 
        counter1 = 1; // resetting counter1 
        
        while (counter1 <= 5)
        {
            tempF = CelsiusToFahrenheit(C);
            cout << setw(7) << C << setw(10) << tempF;
            C++;
            counter1++;
        }
        cout << endl;  
        counter1 = 1; // resetting counter1 
        counter++;
    }
    tempF = CelsiusToFahrenheit(C);
    cout << setw(7) << "C" << setw(10) << "F" << endl; 
    cout << setw(7) << C << setw(10) << tempF << endl;
    cout << endl << endl;

    // THIS IS THE LOOP FOR THE F TO C TABLE
    counter = 1; 
    while (counter <= 36)
    {
        while (counter1 <= 5) 
        {
            cout << setw(7) << "F" << setw(10) << "C";        
            counter1++;
        }
        cout << endl;
        counter1 = 1; // resetting counter1
         
        while (counter1 <= 5) 
        {
            tempC = FahrenheitToCelsius(F);
            cout << setw(7) << F << setw(10) << tempC;
            F++;
            counter1++;
        }  
        cout << endl;
        counter1 = 1; // resetting counter1
        counter++;
    }
    tempC = FahrenheitToCelsius(F);
    cout << setw(7) << "F" << setw(10) << "C" << endl;
    cout << setw(7) << F << setw(10) << tempC << endl;
 
    return 0;
}

double FahrenheitToCelsius(double F)
{
    //definition to convert Fahrenheit to Celsius
    // with the formula 5/9(temp-32)
    return (5.0/9.0 * (F-32)); 
}

double CelsiusToFahrenheit(double C)
{
    //defintion to convert Celsius to Fahrenheit
    // with the formula C/59 + 32
    return ((9.0 * C) / 5.0 + 32.0);
}
$ CC ftc.cpp
$ a.out
C      F         C      F         C      F         C      F         C      F         
0      32.0      1      33.8      2      35.6      3      37.4      4      39.2      
C      F         C      F         C      F         C      F         C      F         
5      41.0      6      42.8      7      44.6      8      46.4      9      48.2      
C      F         C      F         C      F         C      F         C      F         
10     50.0      11     51.8      12     53.6      13     55.4      14     57.2      
C      F         C      F         C      F         C      F         C      F         
15     59.0      16     60.8      17     62.6      18     64.4      19     66.2      
C      F         C      F         C      F         C      F         C      F         
20     68.0      21     69.8      22     71.6      23     73.4      24     75.2      
C      F         C      F         C      F         C      F         C      F         
25     77.0      26     78.8      27     80.6      28     82.4      29     84.2      
C      F         C      F         C      F         C      F         C      F         
30     86.0      31     87.8      32     89.6      33     91.4      34     93.2      
C      F         C      F         C      F         C      F         C      F         
35     95.0      36     96.8      37     98.6      38     100.4     39     102.2     
C      F         C      F         C      F         C      F         C      F         
40     104.0     41     105.8     42     107.6     43     109.4     44     111.2     
C      F         C      F         C      F         C      F         C      F         
45     113.0     46     114.8     47     116.6     48     118.4     49     120.2     
C      F         C      F         C      F         C      F         C      F         
50     122.0     51     123.8     52     125.6     53     127.4     54     129.2     
C      F         C      F         C      F         C      F         C      F         
55     131.0     56     132.8     57     134.6     58     136.4     59     138.2     
C      F         C      F         C      F         C      F         C      F         
60     140.0     61     141.8     62     143.6     63     145.4     64     147.2     
C      F         C      F         C      F         C      F         C      F         
65     149.0     66     150.8     67     152.6     68     154.4     69     156.2     
C      F         C      F         C      F         C      F         C      F         
70     158.0     71     159.8     72     161.6     73     163.4     74     165.2     
C      F         C      F         C      F         C      F         C      F         
75     167.0     76     168.8     77     170.6     78     172.4     79     174.2     
C      F         C      F         C      F         C      F         C      F         
80     176.0     81     177.8     82     179.6     83     181.4     84     183.2     
C      F         C      F         C      F         C      F         C      F         
85     185.0     86     186.8     87     188.6     88     190.4     89     192.2     
C      F         C      F         C      F         C      F         C      F         
90     194.0     91     195.8     92     197.6     93     199.4     94     201.2     
C      F         C      F         C      F         C      F         C      F         
95     203.0     96     204.8     97     206.6     98     208.4     99     210.2     
C      F         
100    212.0     


F      C         F      C         F      C         F      C         F      C         
32     0.0       33     0.6       34     1.1       35     1.7       36     2.2       
F      C         F      C         F      C         F      C         F      C         
37     2.8       38     3.3       39     3.9       40     4.4       41     5.0       
F      C         F      C         F      C         F      C         F      C         
42     5.6       43     6.1       44     6.7       45     7.2       46     7.8       
F      C         F      C         F      C         F      C         F      C         
47     8.3       48     8.9       49     9.4       50     10.0      51     10.6      
F      C         F      C         F      C         F      C         F      C         
52     11.1      53     11.7      54     12.2      55     12.8      56     13.3      
F      C         F      C         F      C         F      C         F      C         
57     13.9      58     14.4      59     15.0      60     15.6      61     16.1      
F      C         F      C         F      C         F      C         F      C         
62     16.7      63     17.2      64     17.8      65     18.3      66     18.9      
F      C         F      C         F      C         F      C         F      C         
67     19.4      68     20.0      69     20.6      70     21.1      71     21.7      
F      C         F      C         F      C         F      C         F      C         
72     22.2      73     22.8      74     23.3      75     23.9      76     24.4      
F      C         F      C         F      C         F      C         F      C         
77     25.0      78     25.6      79     26.1      80     26.7      81     27.2      
F      C         F      C         F      C         F      C         F      C         
82     27.8      83     28.3      84     28.9      85     29.4      86     30.0      
F      C         F      C         F      C         F      C         F      C         
87     30.6      88     31.1      89     31.7      90     32.2      91     32.8      
F      C         F      C         F      C         F      C         F      C         
92     33.3      93     33.9      94     34.4      95     35.0      96     35.6      
F      C         F      C         F      C         F      C         F      C         
97     36.1      98     36.7      99     37.2      100    37.8      101    38.3      
F      C         F      C         F      C         F      C         F      C         
102    38.9      103    39.4      104    40.0      105    40.6      106    41.1      
F      C         F      C         F      C         F      C         F      C         
107    41.7      108    42.2      109    42.8      110    43.3      111    43.9      
F      C         F      C         F      C         F      C         F      C         
112    44.4      113    45.0      114    45.6      115    46.1      116    46.7      
F      C         F      C         F      C         F      C         F      C         
117    47.2      118    47.8      119    48.3      120    48.9      121    49.4      
F      C         F      C         F      C         F      C         F      C         
122    50.0      123    50.6      124    51.1      125    51.7      126    52.2      
F      C         F      C         F      C         F      C         F      C         
127    52.8      128    53.3      129    53.9      130    54.4      131    55.0      
F      C         F      C         F      C         F      C         F      C         
132    55.6      133    56.1      134    56.7      135    57.2      136    57.8      
F      C         F      C         F      C         F      C         F      C         
137    58.3      138    58.9      139    59.4      140    60.0      141    60.6      
F      C         F      C         F      C         F      C         F      C         
142    61.1      143    61.7      144    62.2      145    62.8      146    63.3      
F      C         F      C         F      C         F      C         F      C         
147    63.9      148    64.4      149    65.0      150    65.6      151    66.1      
F      C         F      C         F      C         F      C         F      C         
152    66.7      153    67.2      154    67.8      155    68.3      156    68.9      
F      C         F      C         F      C         F      C         F      C         
157    69.4      158    70.0      159    70.6      160    71.1      161    71.7      
F      C         F      C         F      C         F      C         F      C         
162    72.2      163    72.8      164    73.3      165    73.9      166    74.4      
F      C         F      C         F      C         F      C         F      C         
167    75.0      168    75.6      169    76.1      170    76.7      171    77.2      
F      C         F      C         F      C         F      C         F      C         
172    77.8      173    78.3      174    78.9      175    79.4      176    80.0      
F      C         F      C         F      C         F      C         F      C         
177    80.6      178    81.1      179    81.7      180    82.2      181    82.8      
F      C         F      C         F      C         F      C         F      C         
182    83.3      183    83.9      184    84.4      185    85.0      186    85.6      
F      C         F      C         F      C         F      C         F      C         
187    86.1      188    86.7      189    87.2      190    87.8      191    88.3      
F      C         F      C         F      C         F      C         F      C         
192    88.9      193    89.4      194    90.0      195    90.6      196    91.1      
F      C         F      C         F      C         F      C         F      C         
197    91.7      198    92.2      199    92.8      200    93.3      201    93.9      
F      C         F      C         F      C         F      C         F      C         
202    94.4      203    95.0      204    95.6      205    96.1      206    96.7      
F      C         F      C         F      C         F      C         F      C         
207    97.2      208    97.8      209    98.3      210    98.9      211    99.4      
F      C         
212    100.0     
$ ^D
script done on Sun Sep 24 15:00:10 2000
Script started on Sun Sep 24 16:09:02 2000
$ cat maximumc .cpp
// Program Maximum determines the largest of three integer values.     
// Three integer variables are filled with random integers in
// the range of 15 to 95 
//                               
// Program Maximum also determines the largest of three double values.
// Three doubles variables are fileed with random double values 
// in the range 10 to 70 (70 not included)
// 

#include <iostream.h>
#include <stdlib.h>

int maximum(int Var1, int Var2, int Var3);
// Precondition: start with three random integers
// Postcondition: get back the maximum of those three

double maximum(double dVar1, double dVar2, double dVar3);
// Precondition: start with three random double values
// Postcondition: get back the maximum of those three

int main ()
{
    int  intVar1, intVar2, intVar3, maximumInteger;

    // Get random integer values from 15 to 95 using the rand() function.
    // For integers in the range [a,b], use the formula: 
    // a + rand()%(b-a+1)
    intVar1 = 15 + rand()%(81);
    intVar2 = 15 + rand()%(81);
    intVar3 = 15 + rand()%(81);
    
    maximumInteger = maximum(intVar1,intVar2,intVar3);    

    cout << " The maximum of " << intVar1 << " " << intVar2 << " "
         << intVar3 << " is " << maximumInteger << endl;

    double dVar1, dVar2, dVar3, maximumDouble;

    //Get random doubles with 3 decimal places. Use the rand() function.
    //You may use the formula above by multiplying and dividing
    //by 1000:
    // (a*1000 + rand()%(b*1000-a*1000))/1000
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    dVar1 = (10000 + rand()%(60000)) / 1000.0;
    dVar2 = (10000 + rand()%(60000)) / 1000.0;
    dVar3 = (10000 + rand()%(60000)) / 1000.0;
 
    maximumDouble = maximum(dVar1, dVar2, dVar3);

    cout << " The maximum of " << dVar1 << " " << dVar2 << " "
         << dVar3 << " is " << maximumDouble << endl;
     

    return 0;
}  

int maximum(int Var1, int Var2, int Var3)
{
    int maxI;
    if (Var1 > Var2 && Var1 > Var3)
        maxI = Var1;
    else if (Var2 > Var1 && Var2 > Var3)
        maxI = Var2;
    else
        maxI = Var3;
    return (maxI);
}

double maximum(double dVar1, double dVar2, double dVar3)
{
    double maxD;
    if (dVar1 > dVar2 && dVar1 > dVar3)
        maxD = dVar1;
    else if (dVar2 > dVar1 && dVar2 > dVar3)
        maxD = dVar2;
    else
        maxD = dVar3; 
    return (maxD);
} 
$ [ CC maximumc .cpp
$ a.out
 The maximum of 86 22 84 is 86
 The maximum of 27.515 41.051 15.627 is 41.051
$ ^D

script done on Sun Sep 24 16:09:25 2000

script done on Sun Sep 24 16:09:25 2000
Script started on Sun Sep 24 19:56:39 2000
$ cat third.cpp
// Name: John Hillert
// Date: 9/24/00
// Problem: Rounding Program
// 
// Algorithm:
// Step 1: multiply the number by 10^n
// Step 2: Add 0.5
// Step 3: Delete the fractional part of the result
// Step 4: Divide by 10^n
////////////////////////////////////////////////////////

#include<iostream.h>
#include<math.h>

double round(double number, double n);
// Precondition: takes a users number, and the amount of 
// decimal places to round that number
// Postcondition: gives back the rounded number 

double exp(double exponent);
// this function takes 10 to the nth because
// math.h has a useless power function

int main()
{
    double number, n, fnumber;
    cout << "Enter number:\n";
    cin >> number;
    cout << "Enter number of decimal places you want this number rounded to:\n";
    cin >> n;
    fnumber = round(number, n);
    cout << "Your rounded number is: " << fnumber << endl; 

    return 0;
}

double round(double number, double n)
    {
        number = number * exp(n) + 0.5; 
        number = int(number);
        number = number / exp(n);
        return (number); 
    }
**********************
YOU SHOULD HAVE COMMENTS WITHIN PROGRAM
*******************
 
double exp(double exponent)
   {
       int counter = 1;
       int tento_n = 1;
       while (counter <= exponent)
           { 
               tento_n = 10 * tento_n;
               counter++;
           }
       return (tento_n); 
    }

$ CC third.cpp
$ a.out
Enter number:
4.9775
Enter number of decimal places you want this number rounded to:
3
Your rounded number is: 4.978
$ 4.9774
sh: 4.9774:  not found
$ a.out
Enter number:
4.9774
Enter number of decimal places you want this number rounded to:
3
Your rounded number is: 4.977
$ a.out
Enter number:
4.9775
Enter number of decimal places you want this number rounded to:
3
Your rounded number is: 4.978
$ 3.  a.out
Enter number:
6.71145937
Enter number of decimal places you want this number rounded to:
2
Your rounded number is: 6.71
$ a.out
Enter number:
6.749
Enter number of decimal places you want this number rounded to:
3
Your rounded number is: 6.749
$ a.out
Enter number:
6.701
Enter number of decimal places you want this number rounded to:
a.out
Your rounded number is: 7
$ a.out
Enter number:
6.701
Enter number of decimal places you want this number rounded to:
2
Your rounded number is: 6.7
$ ^D
script done on Sun Sep 24 19:59:06 2000
