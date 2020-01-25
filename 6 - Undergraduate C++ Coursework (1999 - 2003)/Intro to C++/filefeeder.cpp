Received: from larkspur.Mines.EDU (larkspur.Mines.EDU [138.67.2.4])
	by slate.Mines.EDU (AIX4.3/8.9.3/8.9.1) with ESMTP id OAA93068
	for <jhillert@mines.edu>; Wed, 8 Nov 2000 14:30:02 -0700
Received: (from rspinhir@localhost)
	by larkspur.Mines.EDU (8.9.1/8.9.1) id OAA4163784
	for jhillert; Wed, 8 Nov 2000 14:30:01 -0700 (MST)
Date: Wed, 8 Nov 2000 14:30:01 -0700 (MST)
From: Spinhirne <rspinhir@larkspur.Mines.EDU>
Message-Id: <200011082130.OAA4163784@larkspur.Mines.EDU>
X-UIDL: N]""!i$J"!CE%!!A?6!!

Grade Report for Assignment

          Program1:  Ch 5 project 7     __16______ 20 pts

              header  2
              comments 3
              compiles   8
              In one loop :  reads from input1.dat and input2.dat 1
                             writes to output.dat                 0
                             uses no arrays                       0
		YOU HAVE MORE THAN ONE LOOP
              output.dat contains sorted list 2
                                         
          Program2:  Grades + comments       ___19_____ 20 pts   

              header  2 
              comments 3
              compiles  8
              Uses four functions listed   3
              reads from grades.dat        2
              Correct table output         1              
		EXTRA LINES ARE ADDED TO THE OUTPUT BEYOND THE DATA IN THE LINES IN THE INPUT
		FILES


          Total                          ___35_____ 40 pts
// Program: filefeeder.cpp
// Programming Project 7, Savitch Chapter 5
// Programmer: John Hillert
// Class: C++
// Date: 10/24/00
// Purpose: This program takes input from two files
// and combines them into a third. The ouput file
// will have numbers from the first two sorted
// from smallest to largest.
////////////////////////////////////////////////////
//
//
// Algorithm:
// - bring up iostream, and fstream, and any other
//   include directives needed
// - define a funtion that counts the number of 
//   terms in each file
// - define the prototype for a function that 
//   sorts the input from both files, then outputs
//   the sorted conglomerate of both files to an output file
//         a. first the function puts the values from the first
//	      input file into the array
//         b. then it does it for the second one
//         c. then it sends this array to bubblesort
//         d. finally it sends the sorted array to the output stream
// - define bubblesort to be used with previous function
// - start main function
// - start ifstreams input1 and input2 
// - start ofstream output1
// - open each ifstream with their corresponding 
//   input files, input1.dat and input2.dat
// - have a funcion count the terms in both files
// - send count and and all streams to sorting function
//
//
//
//
//   FINAL NOTE: forgive me the complexity, the sloppiness,
//   the utter horror of this program.  I was desparate, and there
//   was nothing I could do.

#include<iostream.h>
#include<fstream.h>
#include<stdlib.h>

const int arraysize = 300;

int count(ifstream& input1, ifstream& input2);
// precondition: takes two initialized ifstreams input1 and input2
// postcondition: counts the number of terms in both

void sortsend(ifstream& input1, ifstream& input2, ofstream& output, const int terms);
// precondition: takes two instreams for files input1 and input2 and an empty
// output file
// postcondition: puts their content into output1 file output.dat in sorted  
// order

void bubblesort(int array[], int arraysize);
// precondition: array has been designated the number of terms
// in the input files
// postcondition: returns array with values sorted from smallest
// to largest            

int main()
{
   ifstream input1, input2;
   ofstream output;
   int terms;

   input1.open("input1.dat");
   if (input1.fail())
   {
      cout << "Input1 file opening failed.\n";
      exit(1);
   }

   input2.open("input2.dat");
   if (input2.fail())
   {
      cout << "Input2 file opening failed.\n";
      exit(1);
   }
   
   terms = count(input1, input2);
   
   input1.close(); // I need to close these so that it will
   input2.close(); // recount the integer values in the file again

   // this means I have to reopen them too
   // and give the proper warnings
   input1.open("input1.dat");
   if(input1.fail())
   {
      cout << "Input1 file opening failed.\n";
      exit(1);
   }
   input2.open("input2.dat");
   if(input2.fail())
   {
      cout << "Input2 file opening failed.\n";
      exit(1);
   }
   
   output.open("output.dat");
   if (output.fail())
   {
      cout << "Output file opening failed.\n";
      exit(1);
   }

   sortsend(input1, input2, output, terms); // put in your files and
   // get a bigger organized one out of it
   
   input1.close();
   input2.close();
   output.close();

   return(0);
}

/*************************************************************************/

int count(ifstream& input1, ifstream& input2) 
{
   double next;
   int a = 0;
   while(input1 >> next)
   { 
      a++;
   }
   while(input2 >> next)
   {
      a++;
   }
   return a;
}

void sortsend(ifstream& input1, ifstream& input2, ofstream& output, const int terms)
{
   int array[arraysize] = {0};
   // THIS PUTS input2.dat INTO ARRAY
   int i=0;
   int next;
   while(input1 >> next)
   {
      array[i] = next;
      i++;
   }

   // THIS PUTS input2.dat INTO ARRAY
   while(input2 >> next)
   {
      array[i] = next;
      i++;
   }                      
   bubblesort(array, terms);
   
   for(int b = 0; b < terms; b++)
   {
      output << array[b];
      output << endl;
   }
}
void bubblesort(int array[], int terms)
{
   for(int j = 0; j < terms; j++)
      for(int k = 0; k < terms - 1; k++)
      {
         if(array[k] > array[k+1])
         {
            int temp = array[k];
            array[k] = array[k+1];
            array[k+1] = temp;
         }
      }
}               
// sourceCode2.cpp
// Programmer: John Hillert
// Purpose: This program takes a file that contains student ID's and
// test scores.  These scores are averaged, and the average is used
// to assign grades according to the following rule
// 	10 points +- average = satisfactory
//      more than 10 points above average = outstanding
//      more than 10 points below average = unsatisfactory
/////////////////////////////////////////////////////////////////////
//
//
//
//  
#include<iostream.h>
#include<fstream.h>
#include<iomanip.h>
#include<stdlib.h>

void readstudata( ifstream& rss, // IN: the data file stream
 		  int scores[],  // OUT: the scores
                  int id[],      // OUT: the IDs
                  int& count );  // OUT; the number of students read
// Precondition: ifstream with grade.dat, and arrays scores and id 
// have to be initialized
// Postcondition: get back both arrays.  scores full of grade.dat's 
// scores, and ID full of grade.dat's ID numbers

float mean(int scores[], int count);
// Precondition: array "scores" has been filled, and count = number of
// elements in array
// Postcondition: gives back the average of all the test scores in the 
// "scores" array

void printTable(int scores[], int id[], int count, float average );
// Precondition: "scores" and "ID" are filled with appropriate values, and
// count is the number of elements per array 
// Postcondition: after using printGrade displays a table of ID, score, 
// and comment grade 

void printGrad(int oneScore, float average);
// Precondition: takes individual score from "score array", and takes average
// Postcondition: returns a value according to the criterian described in 
// the program header

int main()
{
   ifstream rss;
   int scores[50];
   int id[50];
   int count = 50;
   float average;

   cout.setf(ios::left); // this helps justify table later

   rss.open("grade.dat");
   if(rss.fail())
   {
      cout << "Your file won't open!!!!";
      exit(1);
   }

   readstudata(rss, scores, id, count);

   average = mean(scores, count);

   printTable(scores, id, count, average);
 
   return 0;
}

/**************************************************************************/

void readstudata(ifstream& rss, int scores[], int id[], int& count)
{
   int next, j = 0, k = 0;
   for(int i = 1; i <= 2 * count; i++)
   {
      rss >> next;

      if(i % 2 == 0) 
      {
         scores[j] = next;
         j++;
      } 
      else
      {
         id[k] = next;
         k++;
      }
   }
}


float mean(int scores[], int count)
{
   float sum = 0, avg;
   for(int i = 0; i < count; i++)
   {
      sum = scores[i] + sum; 
   }
   avg = sum / i;
   return avg; 
}

void printTable(int scores[], int id[], int count, float average)
{
   cout << setw(7) << "ID" << setw(7) << "SCORE" << "GRADE" << endl;
   int oneScore;
   for(int i = 0; i < count; i++) 
   {
      oneScore = scores[i];
      cout << setw(7) << id[i] << setw(7) << scores[i];
      printGrad(oneScore, average); 
      cout << endl;
   }
}

void printGrad(int oneScore, float average)
{
   char a[] = "outstanding";
   char c[] = "satisfactory";
   char f[] = "unsatisfactory"; 

   if(oneScore > 10 + average)
      cout << a;
   else if(oneScore < average - 10)
      cout << f;
   else
      cout << c;
}   
