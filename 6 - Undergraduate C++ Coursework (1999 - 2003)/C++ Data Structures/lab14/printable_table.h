// CLASS PROVIDED: printable_table(part of the namespace main_savitch_12A)
//   printable_table is a derived class of the table class. All the member and
//   friend functions are inherited with the new addition of print_table
//
// MEMBER FUNCTION
//   print_table()
//     Precondition: current table must have at least one entry
//     Postcondition: All entries in table are printed
//
//
// VALUE SEMANTICS: for the printable_table class
//   Assignments and the copy consturctor may be used with printable_table
//   objects.
#ifndef JHILLERT2
#define JHILLERT2
#include "table1.h"

namespace main_savitch_12A
{
    template <class RecordType>
    class printable_table : public table<RecordType>
    {
    public:
        void print_table();
    };
} 

#include "printa