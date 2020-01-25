// FILE: string_sequence.cpp
// CLASS IMPLEMENTED: string_sequence (see string_sequence for documentation
// INVARIANT for the class:
//   1. The number of strings in the string_sequence is stored in used
//   2. The number of strings in the bag are stored in a partially filled 
//      dynamic array pointed to by data.  Each element of the array is
//      pointing to another dynamic array that stores a string.     
//   3. The size of the array is in the member variable called capacity
////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <cstring>
#include "string_sequence.h"

using namespace std;

namespace stringseq 
{
   string_sequence::string_sequence(size_type initial_capacity)
   {
      capacity = initial_capacity;
      data = new char*[capacity];
      used = 0; 
      current_index = used;
   }

   string_sequence::string_sequence(const string_sequence& source)
   {
      capacity = source.capacity; 
      data = new char*[capacity];
      
      for (size_type i = 0; i < source.size(); i++) 
      {
         data[i] = new char[strlen(source.data[i])+1];
         strcpy(data[i], source.data[i]);
      }

      used = source.used; 
      current_index = source.current_index;
   
   }      

   string_sequence::~string_sequence()
   {
      for (start(); current_index < used; advance()) 
      {
         delete [] data[current_index];    
      }
      
      delete [] data;
   }

   void string_sequence::start()
   {
      if (size() != 0)
      current_index = 0; 
   }

   void string_sequence::advance()
   {
      assert(is_item());
   
      if (current_index != used - 1)
      {
         current_index++;
      }
      else
      {
         current_index = used;
      }
   }
   
   void string_sequence::insert(const char* entry)
   {
      if (used == capacity)
      {
         expand(used*2 + 1);
      }

      // if there isn't a current item then put at beginning of string_sequence
      if (!is_item())
         current_index = 0; 
      
      // Instead of copying the strings, just change where they point to 
      for(size_type i = used; i > current_index; i--)
      {   
         data[i] = data[i-1];
      }

      data[current_index] = new char[strlen(entry)+1];
      strcpy(data[current_index], entry);
      used++;
   }

   void string_sequence::attach(const char* entry)
   {
      if (used == capacity)
      {
         expand(used*2 + 1);
      }
 
      if (!is_item())
         current_index = used;
      else
         current_index = current_index + 1; 

      for(size_type i = used; i > current_index; i--)
      {
         data[i] = data[i-1];
      }
      
      data[current_index] = new char[strlen(entry)+1];
      strcpy(data[current_index], entry);
      used++;

   }

   void string_sequence::remove_current() 
   {
      if(! is_item())
      {
         return;
      } 
      
      used--;
      delete [] data[current_index]; 
      
      for(size_type i = current_index; i < used; i++)
      {
         data[i] = data[i+1];
      }
   }

   string_sequence::size_type string_sequence::size( ) const
   {
      return used;
   }

   bool string_sequence::is_item() const
   {
      return current_index >= 0 && current_index < used;
   }

   char* string_sequence::current() const
   {
      if(is_item())
         return data[current_index];
      else
         return "There is no current item";
   }

   char* string_sequence::operator [](size_type index)
   {
      return data[index];
   }  
       
   void string_sequence::operator =(const string_sequence& source)
   {
      char** new_data; 
      // check for self-assignment
      if (this == &source)
         return;

      if (capacity != source.capacity)
      {
         new_data = new char*[source.capacity];
         for (size_type j = 0; j < used; j++) 
         {
            delete [] data[j];    
         }
         delete [] data;
   
         data = new_data;
      }

      capacity = source.capacity; 
     
      // copy strings from source to data 
      for (size_type i= 0; i < source.used; i++) 
      {
         data[i] = new char[strlen(source.data[i])+1];
         strcpy(data[i], source.data[i]);
      }
      current_index = source.current_index;
      used = source.used;
   }

   void string_sequence::expand(size_type new_capacity)
   {
      char** new_data;
 
      if (new_capacity == capacity)
      {
         return;
      }
      
      // Array should not get smaller than the amount of strings in data type
      if (new_capacity < used)
      {
         new_capacity = used;
      }
      
      // fill up temporary array with data values
      new_data = new char*[new_capacity];

      // have new_data point to everything that data points to 
      for (size_type i = 0; i < used; i++) 
      {
         new_data[i] = data[i];
      }
      
      // Note to self:delete the array of pointers, because something else is 
      // already pointing to them. Do not delete the strings,
      // because nothing else is pointing to them except the
      // new_data pointers.  If you have two things pointing
      // to the same allocation, you can delete one and the other
      // will still be good.  The delete command gets rid of
      // pointers, but it seems that it i