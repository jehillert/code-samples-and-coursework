// FILE: set.cpp
// PROGRAMMER: John Hillert
// LAST UPDATED: 11/19/02
// CLASS IMPLEMENTED: set (see set.h for documentation)

#include "set.h"
#include <iostream>

using namespace std;
using namespace main_savitch_3;

namespace jhillert_mines
{
    void set::insert(const value_type& entry) 
    {
        if (count(entry) > 0)
        {
            cout << "\nEntry is already in the bag.\n";
        }
        else
        {
           bag::insert(entry)