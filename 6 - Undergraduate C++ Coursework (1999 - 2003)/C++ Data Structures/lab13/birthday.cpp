// PROGRAM:        birthday.cpp
// PROGRAMMER:     John Hillert
// LAST UPDATED:   11/19/02
// PURPOSE: To see whether you tend to get duplicates given a certain
// number (23) of random birthdays.
//
////////////////////////////////////////////////////////////////////
//
// PROGRAM DESCRIPTION (as taken from assignment)
// 
// 1. Declare needed variables, including a set to hold integers
// 2. Loop 23 times:
//       1. Clear the set
//       2. Calculate a random number from 0 - 364
//       3. Insert the number in the set
// 3. If the size of the set is 23, print No Duplicates, otherwise
//    print the number of duplicates.
// 4. Ask if the user would like to run another set, repeat above loop
//    if the answer is affirmative.
//
////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include "set2.h"
using namespace std;
using namespace main_savitch_6B;

int main()
{
    set<int> birthdays;
    int iterator;   
    int iterations = 23;
    int no_dups    = 23;
    int duplicates;
    int rand_num; 
    char answer    = 'y';

    while (answer == 'y' || answer == 'Y')
    {
    
        birthdays.clear();

        for (iterator = 1; iterator <= iterations; iterator++)
        {
            rand_num = rand() % 364;
            birthdays.insert(rand_num);
        }
 
        if (birthdays.size() == no_dups)
        {
            cout << "\nNo Duplicates\n";
        }
        else
        {
            duplicates = no_dups - birthdays.size();
            cout << "\nNumber of duplicates: " << duplicates << endl;
        }

        cout << "\nWould you like to run another set (y for yes, n for no)? ";
        cin >> answer;
    }