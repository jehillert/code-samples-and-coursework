// FILE: sequence_test.cxx
// Program By: Michael Main and Walter Savitch 
// Last Modified by: John Hillert
// Last Modified: 9/9/02
// An interactive test program for the new sequence class
// This program has a mode function added to it
// Also, all double have been changed to floats 
#include <cctype>       // Provides toupper
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "sequence1.h"  // With value_type defined as float 
using namespace std;
using namespace seqlab;

// PROTOTYPES for functions used by this test program:
void print_menu( );
// Postcondition: A menu of choices for this program has been written to cout.

char get_user_command( );
// Postcondition: The user has been prompted to enter a one character command.
// The next character has been read (skipping blanks and newline characters), 
// and this character has been returned.

void show_sequence(sequence display);
// Postcondition: The items on display have been printed to cout (one per line).

float get_number( );
// Postcondition: The user has been prompted to enter a real number. The
// number has been read, echoed to the screen, and returned by the function.

float mode(sequence test);
// Precondition: The user has put some values into the sequence 
// Postcondition: the mode of the sequence is return

int main( )
{
    sequence test; // A sequence that we’ll perform tests on
    char choice;   // A command character entered by the user
    
    cout << "I have initialized an empty sequence of real numbers." << endl;

    do
    {
        print_menu( );
        choice = toupper(get_user_command( ));
        switch (choice)
        {
            case '!': test.start( );
                      break;
            case '+': test.advance( );
                      break;
            case '?': if (test.is_item( ))
                          cout << "There is an item." << endl;
                      else 
                          cout << "There is no current item." << endl;
                      break;
            case 'C': if (test.is_item( ))
                           cout << "Current item is: " << test.current( ) << endl;
                      else
                          cout << "There is no current item." << endl;
                      break;
            case 'P': show_sequence(test);
                      break;
            case 'S': cout << "Size is " << test.size( ) << '.' << endl;
                      break;
            case 'I': test.insert(get_number( ));
                      break;
            case 'A': test.attach(get_number( ));
                      break;
            case 'R': test.remove_current( );
                      cout << "The current item has been removed." << endl;
                      break;     
            case 'M': if(test.is_item())
                      {
                         cout << "The mode of test is: " << mode(test) << endl;
                      }
                      else
                      {
                         cout << "The data type is empty: no mode." << endl;
                      }
                      break; 
            case 'Q': cout << "Ridicule is the best test of truth." << endl;
                      break;
            default:  cout << choice << " is invalid." << endl;
        }
    }
    while ((choice != 'Q'));

    return EXIT_SUCCESS;
}

void print_menu( )
// Library facilities used: iostream.h
{
    cout << endl; // Print blank line before the menu
    cout << "The following choices are available: " << endl;
    cout << " !   Activate the start( ) function" << endl;
    cout << " +   Activate the advance( ) function" << endl;
    cout << " ?   Print the result from the is_item( ) function" << endl;
    cout << " C   Print the result from the current( ) function" << endl;
    cout << " P   Print a copy of the entire sequence" << endl;
    cout << " S   Print the result from the size( ) function" << endl;
    cout << " I   Insert a new number with the insert(...) function" << endl;
    cout << " A   Attach a new number with the attach(...) function" << endl;
    cout << " R   Activate the remove_current( ) function" << endl;
    cout << " M   Find the mode of test" << endl;
    cout << " Q   Quit this test program" << endl;
}

char get_user_command( )
// Library facilities used: iostream
{
    char command;

    cout << "Enter choice: ";
    cin >> command; // Input of characters skips blanks and newline character

    return command;
}

void show_sequence(sequence display)
// Library facilities used: iostream
{
    for (display.start( ); display.is_item( ); display.advance( ))
        cout << display.current( ) << endl;
}

float get_number( )
// Library facilities used: iostream
{
    float result;
    
    cout << "Please enter a real number for the sequence: ";
    cin  >> result;
    cout << result << " has been read." << endl;
    return result;
}

float mode(sequence test)
{
   std::size_t i=0;
   float value;
 
   for(test.start(); test.is_item(); test.advance()