// FILE: sequence1.cpp
// CLASS IMPLEMENTED: sequence1 (see sequence1 for documentation

#include <cassert>
#include "sequence1.h"

using namespace std;

namespace seqlab
{
   sequence::sequence()
   {
      used = 0; 
      current_index = used;
   }

   void sequence::start()
   {
      if (size() != 0)
      current_index = 0; 
   }

   void sequence::advance()
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
   
   void sequence::insert(const value_type& entry)
   {
      assert(size() < CAPACITY);
      
      // if there isn't a current item then put at beginning of sequence
      if (!is_item())
         current_index = 0; 

      for(size_type i = used; i > current_index; i--)
      {   
         data[i] = data[i-1];
      }

      data[current_index] = entry;
      used++;
   }

   void sequence::attach(const value_type& entry)
   {
      assert(size() < CAPACITY);
   
      if (!is_item())
         current_index = used;

      // current index changes to index after the current one
      current_index = current_index + 1; 
      
      for(size_type i = used; i > current_index; i--)
      {
         data[i] = data[i-1];
      }
      
      data[current_index] = entry;
      used++;

   }

   void sequence::remove_current() 
   {
      assert(is_item());
   
      used--;

      for(size_type i = current_index; i < used; i++)
      {
         data[i] = data[i+1];
      }
   }

   sequence::size_type sequence::size( ) const
   {
      return used;
   }

   bool sequence::is_item() const
   {
      return current_index >= 0 && current_index < used;
   }

   sequence::value_type sequence::current() const
   {
      return data[current_index];
   }

   sequence::size_type sequence::instances() 
   {
      assert(is_item());

      value_type value;
      value = data[current_index];
      size_type i;
      size_type j= 0;

      for(i = 0; i < used; i++)
      