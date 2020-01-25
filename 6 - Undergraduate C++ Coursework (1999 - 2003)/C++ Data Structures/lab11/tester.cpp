// Program: BST Tester
// Programmer: John Hillert
// Last Updated: 11/05/02
// Purpose: This program tests the BST class.
//////////////////////////////////////////////

#include <cassert>
#include <cstdlib> // EXIT_SUCCESS
#include <fstream> // IO manipulation
#include <iostream>
#include "bst.h"

void print_value(const int& i);
// Postcondition: Prints out value of i to the screen

using namespace main_savitch_10;
using namespace std;

int main()
{
    // INITIALIZING THE BST 
    binary_tree_node<int> *bst;
    
    // OTHER VARS
    ifstream fin;
    int number;
    int count = 0;
    int countdown;
    int *array; 

    // OPEN UP INPUT FILE AND CHECK FOR ERROR 
    fin.open("numbers.dat");
    assert(! fin.fail());

    // READ IN DATA
    fin >> number;
  
    while(! fin.eof())
    {
       count++;
       insert(bst, number);
       fin >> number;
    }
 
    // PRINTING WITH INORDER FUNCTION
    inorder(print_value, bst);
    cout << endl << endl;
 
    // USING PRINT FUNCTION 
    print(bst, 0);
    cout << endl << endl;

    // FILL ARRAY WITH VALUES FROM TREE
    // VALUES ARE ENTERED IN FROM THE END TO THE BEGINNING:
    // SO FROM (COUNT - 1) TO 0
    array = new int[count];
    countdown = count;
    while(tree_size(bst) != 0)
    {
         bst_remove_max(bst, number);
         array[countdown - 1] = number;
         countdown--;
    }
    
    cout << endl << endl;
    create_balanced(bst, array, 0, count);
    print(bst, 0);

    return EXIT_SUCCESS;
}