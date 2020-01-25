Received: from larkspur.Mines.EDU (larkspur.Mines.EDU [138.67.2.4])
	by slate.Mines.EDU (AIX4.3/8.9.3/8.9.1) with ESMTP id TAA37410
	for <jhillert@mines.edu>; Tue, 24 Oct 2000 19:28:06 -0600
Received: (from rspinhir@localhost)
	by larkspur.Mines.EDU (8.9.1/8.9.1) id TAA3343154
	for jhillert; Tue, 24 Oct 2000 19:28:03 -0600 (MDT)
Date: Tue, 24 Oct 2000 19:28:03 -0600 (MDT)
From: Spinhirne <rspinhir@larkspur.Mines.EDU>
Message-Id: <200010250128.TAA3343154@larkspur.Mines.EDU>
To: jhillert@larkspur.Mines.EDU
Subject: cs261f lab9
X-UIDL: eB;!!_[&#!p-&#!fc0"!

Grade Report for Lab 8

           Typescript1               ___6____ 6 pts
              Header and comments     1 pts
              Fills array, finds largest
              prints array, sorts array   3 pts
              All above actions are declared
              in functions correctly         2 pts


           Typescript 2              ___4____ 4 pts
              Header and comments   1 pts
              Correctly determines frequency 1 pt
              Correctly determines percent   1 pt
              Uses enum type as index variables  1 pt



           Total                     __10_____ 10 pts
                     
Script started on Sun Oct 22 17:07:20 2000
$ cat readList.cpp
// readList.cpp
// Name: John Hillert
// Date: 10/22/00
// Purpose:
// This program reads a list of real numbers from
// a data file "real.dat"
//////////////////////////////////////////////////
#include<iostream.h>
#include<fstream.h>

const int MAX_NUMBER = 100;

void assign(ifstream& infile, double List[], int MAX_NUMBER);   
// precondition: file needs to be connected to ifstream argument
// Postcondition: assign values to each array element 

void display(double List[], int MAX_NUMBER);
// Precondition: all values need to be assigned to array
// Postcondition: displays all values from array to screen

double largestvalue(double List[], int MAX_NUMBER);
// Precondition: takes "filled" array     
// Postcondition: finds largest value and returns it to main()

void bubblesort(double List[], int MAX_NUMBER);
// Precondition: takes "filled" array
// Postcondition: sorts values from highest to lowest

void swap(double& listval, double& listval2);
// Precondition: takes two back to back values from array
// Postcondition: returns these values swapped
// this function is part of bubblesort function 

main()
{ 
   ifstream inData;

   double  List[MAX_NUMBER];

   inData.open("real.dat"); // real.dat binded to inData

   assign(inData, List, MAX_NUMBER);  
   display(List, MAX_NUMBER);

   cout << endl << endl << endl
        << "The largest of these values is: "   
        << largestvalue(List, MAX_NUMBER) 
        << endl << endl << endl;

   bubblesort(List, MAX_NUMBER);
   display(List, MAX_NUMBER);
   
   cout << endl << endl << endl; 
   return 0;
}
void assign(ifstream& infile, double List[], int MAX_NUMBER)    
{
    double value;
    for(int i = 0; i < MAX_NUMBER; i++)
       {
          infile >> value;
          List[i] = value;
       }     
}
void display(double List[], int MAX_NUMBER)
{
    for(int i = 0; i < MAX_NUMBER; i++)
    {
        cout << List[i] << " ";
        if ((i + 1) % 10 == 0)
            cout << endl; 
    }
}  
double largestvalue(double List[], int MAX_NUMBER)
{
    double largest;
    largest = List[0];
    for(int i = 1; i < MAX_NUMBER; i++)
    {
         if(largest < List[i])
             largest = List[i];
    }
    return largest;
}
void bubblesort(double List[], int MAX_NUMBER)
{
    for(int j = 0; j < MAX_NUMBER; j++)
        for(int i = 0; i < MAX_NUMBER; i++)
        {
            if (List[i] < List[i+1])
                swap(List[i], List[i+1]);
        }
}
void swap(double& listval, double& listval2)
{
    double hold;
    hold = listval;
    listval = listval2;
    listval2 = hold;
}                
$ CC readList.cpp
$ a.out
70.53 29.14 8.27 3.02 36.31 7.85 2.3 80.11 15.67 23.5 
53.07 33.39 89.29 92.16 64.79 47.03 6.99 0.9 4.4 39.26 
10.32 33.29 36.82 57.64 16.15 79.61 92.73 12.75 40.38 49.23 
5.4 74.43 78.37 13.68 77.46 14.69 85.05 43.28 94.8 64.24 
66.78 11.39 97.63 19.59 67.07 62.42 66.63 37.59 63.32 34.55 
76.85 37.16 31.36 77.2 58.32 47.51 56.81 51.06 23.79 97.19 
63.81 29.19 71.63 42.19 6.39 12.61 20.4 91.44 19.41 78.72 
55.69 49.72 53.64 16.84 69.31 84.23 79.27 35.94 21.82 6.11 
34.01 98.68 6.8 65.38 39.4 65.12 12.89 96.21 79.7 36.68 
56.93 43.52 29.4 92.08 85.71 35.79 68.21 69.63 27.24 87.62 



The largest of these values is: 98.68


98.68 97.63 97.19 96.21 94.8 92.73 92.16 92.08 91.44 89.29 
87.62 85.71 85.05 84.23 80.11 79.7 79.61 79.27 78.72 78.37 
77.46 77.2 76.85 74.43 71.63 70.53 69.63 69.31 68.21 67.07 
66.78 66.63 65.38 65.12 64.79 64.24 63.81 63.32 62.42 58.32 
57.64 56.93 56.81 55.69 53.64 53.07 51.06 49.72 49.23 47.51 
47.03 43.52 43.28 42.19 40.38 39.4 39.26 37.59 37.16 36.82 
36.68 36.31 35.94 35.79 34.55 34.01 33.39 33.29 31.36 29.4 
29.19 29.14 27.24 23.79 23.5 21.82 20.4 19.59 19.41 16.84 
16.15 15.67 14.69 13.68 12.89 12.75 12.61 11.39 10.32 8.27 
7.85 6.99 6.8 6.39 6.11 5.4 4.4 3.02 2.3 0.9 



$ ^D

script done on Sun Oct 22 17:07:52 2000
Script started on Mon Oct 23 15:46:47 2000
$ cat favorit.cpp
///////////////////////////////////////////////////////////////
// Favorit.cpp
// Name: John Hillert
// Date: 10/22/00
// Purpose:
// Program Favorit determines the favorite football team whose
// mascot is a bird.
///////////////////////////////////////////////////////////////

#include <iostream.h>

enum  Birds  {RAVEN, CARDINAL, EAGLE, SEAHAWK, FALCON};
int numbirds = 5;

void Prompt();
//Precondition: takes no input, but it is good to know
//which birds belong to which city
//Postcondition: outputs choices: "enter this # for your
//favorite team  

int totalresponse(int sums[], int numbirds);
//Precondition: takes "filled" array called sums, and total
//number of bird categories
//Postcondition: adds up and returns all votes for favorite
//team

void percent(int sums[], int numbirds, double gtotal);
//Precondition: Takes array and total responses
//Postcondition: Takes array values and divides them by total
//to give percentage of populatity for that team 

int main ()
{
    int  sums[5]; // the array that individual responses go in
    int  number;
    Birds  index; // values from Birds can go into value index 

    cout.setf(ios::showpoint); // this is for percentages
    cout.setf(ios::fixed);
    cout.precision(2);

    for (index = RAVEN; index <= FALCON ; index = Birds(index + 1))
        sums[index] = 0; // sets all elements to 0 value

    Prompt(); // displays teams and their corresponding inputs
    cin  >> number;
    while (number != 5) // this loop tallies up fans per team
    {
        sums[number]++;

	Prompt();
	cin  >> number;

    }

    for(index = RAVEN; index <= FALCON; index = Birds(index + 1))
        switch(index) // outputs number of votes with each team 
        {
            case RAVEN:
                cout << "Number of Ravens fans: " 
                     << sums[RAVEN] << endl;
                break;
            case CARDINAL:
                cout << "Number of Cardinals fans: "
                     << sums[CARDINAL] << endl;
 		break;
            case EAGLE:
	        cout << "Number of Eagles fans: "
 		     << sums[EAGLE] << endl;
 		break;
	    case SEAHAWK:
 		cout << "Number of Seahawks fans: "
		     << sums[SEAHAWK] << endl;
 		break;
  	    case FALCON:
 	        cout << "Number of Falcons fans: "
 		     << sums[FALCON] << endl;
 		break;
        } 	 	
    
    double gtotal; 
    gtotal = totalresponse(sums, numbirds); 
    // gtotal is double for double valued percentages
    cout << "\n\n\nThe total number of responses is: "   
         << int(gtotal) << endl; // displays all values

    percent(sums, numbirds, gtotal); // displays percents

    return 0;
}

/*******************************************************/

void Prompt()
{
    cout  << "Enter a 0 if your favorite football team is Baltimore."
	  << endl;
    cout  << "Enter a 1 if your favorite football team is Arizona."
	  << endl;
    cout  << "Enter a 2 if your favorite football team is Philadelphia."
	  << endl;
    cout  << "Enter a 3 if your favorite football team is Seattle."
	  << endl;
    cout  << "Enter a 4 if your favorite football team is Atlanta."
          << endl;

    cout  <<"Enter a 5 if you wish to quit the survey."
	  << endl;
}
int totalresponse(int sums[], int numbirds)
{
    int grandtotal = 0;
    for(int i = RAVEN; i <= FALCON; i = Birds(i + 1))
        grandtotal = sums[i] + grandtotal;
    return grandtotal;
}
void percent(int sums[], int numbirds, double gtotal)
{
    cout << "\n\nThe Ravens have " << (sums[0] / gtotal) * 100
         << " % of the popularity.\n"; 
    cout << "The Cardinals have " << (sums[1] / gtotal) * 100
         << " % of the popularity.\n";
    cout << "The Eagles have " << (sums[2] / gtotal) * 100
         << " % of the popularity.\n";
    cout << "The Seahawks have " << (sums[3] / gtotal) * 100
         << " % of the popularity.\n";
    cout << "The Falcons have " << (sums[4] / gtotal) * 100 
         << " % of the popularity.\n\n";
} 
$ CC favorit.cpp
$ a.out
Enter a 0 if your favorite football team is Baltimore.
Enter a 1 if your favorite football team is Arizona.
Enter a 2 if your favorite football team is Philadelphia.
Enter a 3 if your favorite football team is Seattle.
Enter a 4 if your favorite football team is Atlanta.
Enter a 5 if you wish to quit the survey.
0
Enter a 0 if your favorite football team is Baltimore.
Enter a 1 if your favorite football team is Arizona.
Enter a 2 if your favorite football team is Philadelphia.
Enter a 3 if your favorite football team is Seattle.
Enter a 4 if your favorite football team is Atlanta.
Enter a 5 if you wish to quit the survey.
0
Enter a 0 if your favorite football team is Baltimore.
Enter a 1 if your favorite football team is Arizona.
Enter a 2 if your favorite football team is Philadelphia.
Enter a 3 if your favorite football team is Seattle.
Enter a 4 if your favorite football team is Atlanta.
Enter a 5 if you wish to quit the survey.
0
Enter a 0 if your favorite football team is Baltimore.
Enter a 1 if your favorite football team is Arizona.
Enter a 2 if your favorite football team is Philadelphia.
Enter a 3 if your favorite football team is Seattle.
Enter a 4 if your favorite football team is Atlanta.
Enter a 5 if you wish to quit the survey.
0
Enter a 0 if your favorite football team is Baltimore.
Enter a 1 if your favorite football team is Arizona.
Enter a 2 if your favorite football team is Philadelphia.
Enter a 3 if your favorite football team is Seattle.
Enter a 4 if your favorite football team is Atlanta.
Enter a 5 if you wish to quit the survey.
0
Enter a 0 if your favorite football team is Baltimore.
Enter a 1 if your favorite football team is Arizona.
Enter a 2 if your favorite football team is Philadelphia.
Enter a 3 if your favorite football team is Seattle.
Enter a 4 if your favorite football team is Atlanta.
Enter a 5 if you wish to quit the survey.
1
Enter a 0 if your favorite football team is Baltimore.
Enter a 1 if your favorite football team is Arizona.
Enter a 2 if your favorite football team is Philadelphia.
Enter a 3 if your favorite football team is Seattle.
Enter a 4 if your favorite football team is Atlanta.
Enter a 5 if you wish to quit the survey.
1
Enter a 0 if your favorite football team is Baltimore.
Enter a 1 if your favorite football team is Arizona.
Enter a 2 if your favorite football team is Philadelphia.
Enter a 3 if your favorite football team is Seattle.
Enter a 4 if your favorite football team is Atlanta.
Enter a 5 if you wish to quit the survey.
1
Enter a 0 if your favorite football team is Baltimore.
Enter a 1 if your favorite football team is Arizona.
Enter a 2 if your favorite football team is Philadelphia.
Enter a 3 if your favorite football team is Seattle.
Enter a 4 if your favorite football team is Atlanta.
Enter a 5 if you wish to quit the survey.
2
Enter a 0 if your favorite football team is Baltimore.
Enter a 1 if your favorite football team is Arizona.
Enter a 2 if your favorite football team is Philadelphia.
Enter a 3 if your favorite football team is Seattle.
Enter a 4 if your favorite football team is Atlanta.
Enter a 5 if you wish to quit the survey.
2
Enter a 0 if your favorite football team is Baltimore.
Enter a 1 if your favorite football team is Arizona.
Enter a 2 if your favorite football team is Philadelphia.
Enter a 3 if your favorite football team is Seattle.
Enter a 4 if your favorite football team is Atlanta.
Enter a 5 if you wish to quit the survey.
2
Enter a 0 if your favorite football team is Baltimore.
Enter a 1 if your favorite football team is Arizona.
Enter a 2 if your favorite football team is Philadelphia.
Enter a 3 if your favorite football team is Seattle.
Enter a 4 if your favorite football team is Atlanta.
Enter a 5 if you wish to quit the survey.
2
Enter a 0 if your favorite football team is Baltimore.
Enter a 1 if your favorite football team is Arizona.
Enter a 2 if your favorite football team is Philadelphia.
Enter a 3 if your favorite football team is Seattle.
Enter a 4 if your favorite football team is Atlanta.
Enter a 5 if you wish to quit the survey.
2
Enter a 0 if your favorite football team is Baltimore.
Enter a 1 if your favorite football team is Arizona.
Enter a 2 if your favorite football team is Philadelphia.
Enter a 3 if your favorite football team is Seattle.
Enter a 4 if your favorite football team is Atlanta.
Enter a 5 if you wish to quit the survey.
2
Enter a 0 if your favorite football team is Baltimore.
Enter a 1 if your favorite football team is Arizona.
Enter a 2 if your favorite football team is Philadelphia.
Enter a 3 if your favorite football team is Seattle.
Enter a 4 if your favorite football team is Atlanta.
Enter a 5 if you wish to quit the survey.
2
Enter a 0 if your favorite football team is Baltimore.
Enter a 1 if your favorite football team is Arizona.
Enter a 2 if your favorite football team is Philadelphia.
Enter a 3 if your favorite football team is Seattle.
Enter a 4 if your favorite football team is Atlanta.
Enter a 5 if you wish to quit the survey.
3
Enter a 0 if your favorite football team is Baltimore.
Enter a 1 if your favorite football team is Arizona.
Enter a 2 if your favorite football team is Philadelphia.
Enter a 3 if your favorite football team is Seattle.
Enter a 4 if your favorite football team is Atlanta.
Enter a 5 if you wish to quit the survey.
3
Enter a 0 if your favorite football team is Baltimore.
Enter a 1 if your favorite football team is Arizona.
Enter a 2 if your favorite football team is Philadelphia.
Enter a 3 if your favorite football team is Seattle.
Enter a 4 if your favorite football team is Atlanta.
Enter a 5 if you wish to quit the survey.
4
Enter a 0 if your favorite football team is Baltimore.
Enter a 1 if your favorite football team is Arizona.
Enter a 2 if your favorite football team is Philadelphia.
Enter a 3 if your favorite football team is Seattle.
Enter a 4 if your favorite football team is Atlanta.
Enter a 5 if you wish to quit the survey.
4
Enter a 0 if your favorite football team is Baltimore.
Enter a 1 if your favorite football team is Arizona.
Enter a 2 if your favorite football team is Philadelphia.
Enter a 3 if your favorite football team is Seattle.
Enter a 4 if your favorite football team is Atlanta.
Enter a 5 if you wish to quit the survey.
5
Number of Ravens fans: 5
Number of Cardinals fans: 3
Number of Eagles fans: 7
Number of Seahawks fans: 2
Number of Falcons fans: 2



The total number of responses is: 19


The Ravens have 26.32 % of the popularity.
The Cardinals have 15.79 % of the popularity.
The Eagles have 36.84 % of the popularity.
The Seahawks have 10.53 % of the popularity.
The Falcons have 10.53 % of the popularity.

$ ^D

script done on Mon Oct 23 15:47:54 2000

script done on Mon Oct 23 15:47:54 2000
