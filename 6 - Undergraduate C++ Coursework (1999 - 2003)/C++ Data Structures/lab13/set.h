// CLASS PROVIDED: set (part of namespace jhillert)
// PROGRAMMER: John Hillert
// LAST UPDATED: 11/19/02
// 
// MEMBER FUNCTIONS	
// void insert(const value_type& entry)
// Precondition: size() < capacity
// Postcondition: If the entry is not within the bag, then it
// is added.  If there is already an instance of the entry then it
// is not added and a message is printed out.
//
// VALUE SEMANTICS for the set class:
// Assignments and the copy constructor may be used with set objects
////////////////////////////////////////////////////////////////////

#ifndef JHILLERT_LESSON1 
#define JHILLERT_LESSON1
#include "bag1.h"

namespace jhillert_mines
{
    class set : public main_savitch_3::bag 
    {
    public:
        void insert(const value_type& entry);