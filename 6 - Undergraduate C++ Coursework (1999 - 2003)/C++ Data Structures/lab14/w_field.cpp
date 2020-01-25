// FILE: w_field.cpp
// CLASS IMPLEMENTED: w_field
// PROGRAMMER: John Hillert
// LAST UPDATED: 11/29/02
//
//
//
// INVARIANT OF THE CLASS:
//	1. A unique number that identifies the object is
//	   stored in variable key.
//	2. A persons name is stored in a dynamic array called
// 	   name[].
//	3. The number of gallons and the fee for the entry are
//	   stored in private integer and dbouel variables called
//	   gallons and fee.
//
// DYNAMIC MEMORY: 
//	The constructor, copy constructor, and destructro uses
//	dynamic memory. 

#include <cstring>
#include <cstdlib>
#include <iostream>
#include "w_field.h"
using namespace std;

namespace assignment14
{
    w_field::w_field()
    {
        key = 0;
        name = NULL;
        gallons = 0;
        fee = 0.0;
    } 
 
    w_field::w_field(int ikey, char iname[], int igallons, double ifee)
    {
        key = ikey;
        name = new char[strlen(iname)+1];
        strcpy(name, iname);
        gallons = igallons;
        fee = ifee;
    }
    
    w_field::w_field(const w_field& source)
    {
        key = source.key;
        name = new char[strlen(source.name)+1];
        strcpy(name, source.name);
        gallons = source.gallons;
        fee = source.fee;
    }

    void w_field::operator =(const w_field& source)
    {
        if (this == &source)
            return;
        
        key = source.key;
        delete [] name;
        name = new char[strlen(source.name)+1];
        strcpy(name, source.name);
        gallons = source.gallons;
        fee = source.fee;
    }

    ostream& operator <<(ostream& outs, const w_field& source)
    {
        outs << endl << source.key;
        outs << endl << source.name;
        outs << endl << source.gallon