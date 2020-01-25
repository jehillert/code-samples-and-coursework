// Program: printq
// Programmer: John Hillert
// Last Updated: 9/30/02
// Purpose: To make a print que with a linked list using 
// iterators.
////////////////////////////////////////////////////////

#include <iostream.h>
#include <cstdlib> //exit_success, NULL, rand() 
#include <cassert>
#include "node2.h"

using namespace std;
using namespace main_savitch_6B;

template <class Item>
void print_queue(node<Item>* start);
// Precondition: start is a valid node
// Postcondition: Prints "There are no jobs" if list is empty.
// Otherwise it print the items in the list by order of priority
// then by order of entry.

template <class Item>
void add_to_queue(node_iterator<Item> start, node_iterator<Item> end, Item entry);
// Precondition: start is the same priority as the current print job
// and end is one priority higher than the current print job
// Postcondition: a node with entry has been added between the end
// of the same priority list and the beginning of the higher priority 
// list.  

int main()
{
   int time_steps;
   int priority;
   int print_time;

   node<int> *que;
//   que->set_link(NULL);
   que = NULL;

   node_iterator<int> priority1; 
   node_iterator<int> priority2; 
   node_iterator<int> priority3; 
   node_iterator<int> tail;

   // Adding "dummy" nodes and making iterators point to them
   // Keep in mind priorities must be added in reverse
   list_head_insert(que, 0); 
   priority3 = que; 
   list_head_insert(que, 0); 
   priority2 = que; 
   list_head_insert(que, 0); 
   priority1 = que; 

   cout << "\n\n\nEnter number of time steps: ";
   cin >> time_steps;
   cout << endl << endl;

   // time loop that picks priorities and times
   for (time_steps; time_steps > 0; --time_steps)
   {
      priority = rand() % 3 + 1;
      print_time = rand() % 10 + 1;

      cout << "\nThe priority of new job is: " << priority << endl
           << "The time of new job is: " << print_time << endl; 

      switch (priority)
      {
         case 1: add_to_queue(priority1, priority2, print_time);
                   break;
         case 2: add_to_queue(priority2, priority3, print_time);
                   break;
         default: add_to_queue(priority3, tail, print_time);
      }
   }

   cout << "\n\nThe final queue is: \n";
   print_queue(que);
   
   cout << endl << endl << endl;

   return EXIT_SUCCESS;

}

template <class Item>
void add_to_queue(node_iterator<Item> start, node_iterator<Item> end, Item entry)
{
   node_iterator<Item> current, previous;
   previous = NULL;
 
   for(current = start; current != end; current++)
   {
      previous = current;
   }
   
   list_insert(previous.get_current(), entry);
       
}

template <class Item>
void print_queue(node<Item>* start)
{
   node_iterator<Item> iter, tail;
   int priority = 1;
   for(iter = start; iter != tail; iter++)
   {
      if(*iter == 0)
  