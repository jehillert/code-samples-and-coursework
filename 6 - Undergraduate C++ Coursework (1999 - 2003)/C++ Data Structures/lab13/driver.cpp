// PROGRAM: Lesson 1 Driver
// PROGRAMMER: John Hillert
// LAST UPDATED: 11/19/02
// PURPOSE: To test the set derived class
///////////////////////////////////////////

#include <cstdlib>
#include <iostream>
#include "set.h"

using namespace jhillert_mines;
using namespace std;

void main()
{
    set test_set;
    int entry;

    // have an infinite loop asking for integer entries
    while (cin)
    {
       cout << "\nEnter integer entry: ";
       cin >> entry;
       test_set.insert(entry);
    }

    return