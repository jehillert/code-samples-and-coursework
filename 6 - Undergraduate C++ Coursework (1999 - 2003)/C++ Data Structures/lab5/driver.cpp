// Program: Sort_list
// Programmer: John Hillert
// Last Updated: 9/24
// Purpose: To write a function that uses Main and Savitch's 
//          node class to store a list of integers, and then 
//          sort them from smallest to largest.
///////////////////////////////////////////////////////////////////////
// sort_list algorithm from Main and Savitch
// while(the first list still has some nodes)
// {
//    1. Find the node with the largest item of all the 
//       nodes in the first list
//    2. Remove this node from the first list.
//    3. Insert this node at the head of the second list.
// }

#include <iostream>
#include <cassert>
#include <cstdlib>
#include "node.h"
using namespace std;
using namespace main_savitch_5;

void sort_list(node*& head_ptr);
// Precondition: head_ptr is a head pointer of a linked
// list of items, and these items can be compared with a 
// less-than operator. 
// Postcondition: head_ptr points to the head of a linked
// list with exactly the same entries (including repetitions
// if any), but the entries in this list are sorted from 
// to largest.  The original linked list is no longer available

void print_list(node* head_ptr);
// Postcondition: The contents of the linked list are printed
// to the screen. If the list is empty it is so stated.


int main()
{
   node *head_ptr;
   int entry;
   int answer;
 
   cout << "Do wish to add a number to the linked list (1 = yes, 2 = no)? ";
   cin >> answer;
   cout << endl;

   while (answer == 1)
   {
      cout << "Enter integer node data value: ";
      cin >> entry;
      cout << endl;
     
      list_head_insert(head_ptr, entry);
      
      cout << "Do wish to add another number (1 = yes, 2 = no)? ";
      cin >> answer;
      cout << endl;
    }

    cout << "\nCurrent list is: \n";
    print_list(head_ptr);

    cout << "\nCalling sort_list. . .\n";
    sort_list(head_ptr);
    cout << "\nPrinting sorted list: \n";
    print_list(head_ptr);

    return EXIT_SUCCESS;       
    
}

void sort_list(node*& head_ptr)
{
   node *new_hptr;
   node *curser;
   node *max;
   node *precurser;
   node *max_precurser;

   int i = 0;
   precurser = NULL;
   max_precurser = NULL;

   max = head_ptr;
   while (head_ptr != NULL)
   {
      // find the largest number in the list
      for(curser = head_ptr; curser != NULL; curser = curser->link())
      {
         if (max->data() < curser->data())
         {
               max = curser;  
               max_precurser = precurser;
         }
         precurser = curser; 
      }
      // add highest to beginning of new list
      list_head_insert(new_hptr, max->data());

      // if highest is first then use list_head_remove
      // otherwise list_remove
      if (max == head_ptr)
         list_head_remove(head_ptr);
      else
         list_remove(max_precurser); 
      if (i == 0)
      {
         new_hptr->set_link(NULL);
         i++;
      } 
      precurser = NULL;
      max_precurser = NULL; 
      max = head_ptr; 
   }   
   list_clear(head_ptr);
   head_ptr = new_hptr; // head_ptr is now the sorted list 
}

void print_list(node* head_ptr)
{
   assert(head_ptr != NULL);
   node *curser;
   
   curser = head_ptr;

   if (head_ptr == NULL)
   {
      cout << "\nThe list is empty.\n";
      return;
   }

   cout << curser-