// PROGRAM: Lesson 2 Driver
// PROGRAMMER: John Hillert
// LAST UPDATED: 11/19/02
// PURPOSE: To test the set2 derived class
///////////////////////////////////////////

#include <cstdlib>
#include <iostream>
#include "set2.h"

using namespace main_savitch_6B; 
using namespace std;

void main()
{
    set<int> test_set;
    set<int>::iterator i;
    int entry;
    char answer = 'y';

    // fill up set
    while (answer == 'y' || answer == 'Y')
    {
       cout << "\nEnter integer entry: ";
       cin >> entry;
       test_set.insert(entry);
       cout << "\nEnter another value (y for yes, n for no)? ";
       cin >> answer;
    }

    i = test_set.begin(); //set iterator to beginning of bag

    while(i != test_set.end())
    {
        // print out the value under the iterator before it gets moved 
        cout << endl;
        cout << *(i++); 
    }
 
    test_set.clear();
    
    cout << "\nThe test_set size is: " << test_set.size();
    cout << endl << endl << e