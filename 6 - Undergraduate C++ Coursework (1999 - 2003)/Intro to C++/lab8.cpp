Received: from larkspur.Mines.EDU (larkspur.Mines.EDU [138.67.2.4])
	by slate.Mines.EDU (AIX4.3/8.9.3/8.9.1) with ESMTP id NAA89406
	for <jhillert@mines.edu>; Wed, 18 Oct 2000 13:56:37 -0600
Received: (from rspinhir@localhost)
	by larkspur.Mines.EDU (8.9.1/8.9.1) id NAA3170551
	for jhillert; Wed, 18 Oct 2000 13:56:35 -0600 (MDT)
Date: Wed, 18 Oct 2000 13:56:35 -0600 (MDT)
From: Spinhirne <rspinhir@larkspur.Mines.EDU>
Message-Id: <200010181956.NAA3170551@larkspur.Mines.EDU>
To: jhillert@larkspur.Mines.EDU
Subject: cs261f lab8
X-UIDL: IV(#!BR*!!l]#"!c[M"!

Grade Report for Lab 8

           Typescript1               ___3____ 3 pts
              Header and comments     1 pts
              EOF loop to read looping.dat 
                                      2 pts

            Typescript2               __4____  4 pts
              Header and comments   1 pts
              Random range correct  1 pts
              Formatting correct (10 columns)  1 pt
              Output file typescripted  1 pt

            Typescript3                __3___ 3 pts
               Header and comments   1 pts
               Function assigns enum types  1 pts
               Switch uses enum correctly   1 pts

           Total                     __10_____ 10 pts
                     
Script started on Mon Oct 16 00:48:03 2000
$ cat readFile.cpp
// readFile.cpp  
// Last Modified by: John Hillert
// Date: 10/16/00
// readFile.cpp is meant to take info from a file, put it
// into an output file, and display that same info onto
// the screen.
/////////////////////////////////////////////////////////

#include <iostream.h>
#include <fstream.h>

int main()
{
   float value;                  // declare variable 
   ifstream inData;              // declare input stream object
   ofstream outData;             // declare output stream object

   outData.setf(ios::fixed);
   outData.setf(ios::floatfield);
   outData.setf(ios::showpoint);
   // This works just like the functions with cout to format
   // the data in the output file.

   inData.open("looping.dat", ios::in);
   // binds the disk file Data.In to the input stream object inData

   outData.open("Data.Out", ios::out);
   // binds the disk file Data.Out to the output stream object outData

   while (! inData.eof())
   {
       // reads all values
       inData >> value;
       cout << value << endl;
       outData << value << endl;
   } 
       
   inData.close();
   outData.close();
     
       
   return 0;
   }
$ CC readFile.cpp
$ a.out
1066
1492
1977
1947
1953
1066
1668
1935
1926
1492
1066
1492
1977
1947
1953
1066
1668
1935
1926
1492
1492
$ ls
Data.In       gauge.cpp     random.dat    typescript1
Data.Out      gauge.dat     readFile.cpp  typescript2
a.out         looping.dat   shell8.cpp    typescript3
$ cat Data.out   Out
1066.00
1492.00
1977.00
1947.00
1953.00
1066.00
1668.00
1935.00
1926.00
1492.00
1066.00
1492.00
1977.00
1947.00
1953.00
1066.00
1668.00
1935.00
1926.00
1492.00
1492.00
$ ^D
script done on Mon Oct 16 00:49:19 2000
Script started on Sun Oct 15 23:53:38 2000
$ cat   cat shell8.cpp
// Program: shell8.cpp
// Name: John Hillert
// Date: 10/15/00
// shell8.cpp is a program to write random integers to a file
// in a prescribed format. Then bring back and display on screen.
/////////////////////////////////////////////////////////////////

#include<iostream.h>
#include<fstream.h>
#include<stdlib.h>

main()
{
   ofstream dataOut;// declare object for output to file
   int i, value; // loop variable and random value

   dataOut.open("random.dat");
   if (dataOut.fail())
   {
      cout << "Output file opening failed.\n";
      exit(1);
   }

   for(i=1; i<=10; i++)
   {
       for(int a=1; a<=10; a++)
       {
          srand(rand());
          value = 16 + rand() % 78;  
          dataOut << value << " "; 
       }
       dataOut << endl;
   }
    
   dataOut.close();
  
    // NOW OLD GOES ONTO SCREEN
   ifstream dataIn;// take old output and display
   dataIn.open("random.dat");
   char number;
 
   while(! dataIn.eof()) 
   {
       dataIn.get(number);
       cout << number;
   }

   return 0; 
}
$ CC shell8.cpp
$ a.out
18 85 17 17 36 51 21 34 86 42 
68 81 53 85 67 51 27 84 45 57 
29 30 38 54 40 43 27 42 23 64 
24 38 64 81 21 72 68 25 82 50 
39 20 68 27 86 33 87 66 58 75 
78 19 28 52 16 22 71 46 37 33 
53 61 55 74 48 82 42 68 50 58 
20 40 54 62 73 93 91 47 17 21 
76 26 63 44 90 80 26 37 63 44 
90 80 26 37 63 44 90 80 26 37 

$ car t random.dat
18 85 17 17 36 51 21 34 86 42 
68 81 53 85 67 51 27 84 45 57 
29 30 38 54 40 43 27 42 23 64 
24 38 64 81 21 72 68 25 82 50 
39 20 68 27 86 33 87 66 58 75 
78 19 28 52 16 22 71 46 37 33 
53 61 55 74 48 82 42 68 50 58 
20 40 54 62 73 93 91 47 17 21 
76 26 63 44 90 80 26 37 63 44 
90 80 26 37 63 44 90 80 26 37 
$ 
script done on Sun Oct 15 23:54:20 2000
Script started on Mon Oct 16 00:44:11 2000
$ cat gaur ge.cpp
// Program: Gauge.cpp 
// Last Modified by: John Hillert
// Date: 8/15/00
// Program Gauge inputs pressure readings from file Gauge.dat 
// and writes appropriate messages.  
//////////////////////////////////////////////////////////////

#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>

enum  DecisionType {ERROR, NORMAL, HIGH, EVACUATE}; 

void  GetPressure(ifstream&, DecisionType&);
// Pre:  File readings has been opened and operator sent by reference.
// Post: An integer pressure is read from a file with the object 
//     readings and an enumerated value is returned
//     by reference through the variable pressure.

int main ()
{
    ifstream  readings;
    DecisionType  pressure;        
    readings.open("gauge.dat");
    if (readings.fail())
    {
        cout << "Error: Input file opening failed.\n";
        exit(1);
    }

    do
    {
        GetPressure(readings, pressure);
        switch (pressure)
        {
         /* complete the switch statement to print messages */
            case ERROR :
                cout << "Error in input";
                break;
            case NORMAL :
                cout << "Pressure is in normal range.";
                break;
            case HIGH :
                cout << "Pressure on the high side.";
                break;
            case EVACUATE :
                cout << "Evacuate the plant!!!";   
        }
        cout << endl;
    }  while (pressure != EVACUATE);
    return 0;
}

/**************************************************/        
                                                            

void GetPressure(ifstream& readings, DecisionType& pressure)
//       Pressure is ERROR if a negative pressure is read.        
//       Pressure is NORMAL if the value is between 0 and 49.   
//       Pressure is HIGH if the value is between 50 and 99.        
//       Pressure is EVACUATE if the value is 100 or above.       

{                                                            
    int  reading;
    readings  >> reading;
    if (reading < 0)
        pressure = ERROR;
    else if (reading < 50)
        pressure = NORMAL;
    else if (reading < 100)
        pressure = HIGH;
    else 
        pressure = EVACUATE;
}                                                         

$ c CC gauge.cpp
$ a.out
Pressure is in normal range.
Pressure is in normal range.
Pressure is in normal range.
Pressure on the high side.
Pressure on the high side.
Error in input
Evacuate the plant!!!
$ cat gauge.c dat
10 1  49  50  99  -2  120
$ ^D
script done on Mon Oct 16 00:44:39 2000
