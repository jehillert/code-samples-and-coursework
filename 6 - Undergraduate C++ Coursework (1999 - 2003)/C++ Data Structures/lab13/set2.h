// CLASS PROVIDED: set2 (part of namespace jhillert)
// PROGRAMMER: John Hillert
// LAST UPDATED: 11/19/02
// 
// MEMBER FUNCTIONS	
//   void insert(const value_type& entry)
//       Precondition: size() < capacity
//       Postcondition: If the entry is not within the bag, then it
//       is added.  If there is already an instance of the entry then it
//       is not added and a message is printed out.
//
//   void clear()
//       Postcondition: The set has had all substituent nodes deleted
//       and many_nodes is set to zero  
//
// VALUE SEMANTICS for the set class:
// Assignments and the copy constructor may be used with set objects
////////////////////////////////////////////////////////////////////

#ifndef JHILLERT_LESSON2 
#define JHILLERT_LESSON2
#include "bag5.h"

namespace main_savitch_6B 
{
    template <class Item>
    class set : public bag<Item> 
    {
    public:
        void insert(const Item& entry);
        void clear();
    };
}    

