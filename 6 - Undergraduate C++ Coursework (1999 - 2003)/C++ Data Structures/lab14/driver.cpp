// FILE: driver.cpp
// PROGRAMMER: John Hillert
// LAST UPDATED: 11/29/02

const int key_length     = 4;
const int name_length    = 21;
const int gallons_length = 3;
const int fee_length     = 6;

#include <cassert>
#include <cstdlib>
#include <fstream>
#include <iostream>  
#include "printable_table.h"
#include "w_field.h"

using namespace assignment14;
using namespace main_savitch_12A;
using namespace std;

void read_data(table<w_field>& w_table);
// Precondition: There exists a properly formatted
// file called water.fixed in the current directory. 
// Postcondition: w_table has been filled with 
// information from an input file using fixed length formatting.

int main()
{
    int key;
    printable_table<w_field> w_table;
    w_field result;
    bool found;
    int new_key = 0;
 
    cout << "\nReading fixed length data into table.\n";
    read_data(w_table); 
    cout << "Contents of the table. . .\n";
    w_table.print_table();
 
    while(new_key == 0)
    {
        cout << "\n\nEnter key: ";
        cin >> key;
    
        w_table.find(key, found, result); 

        if (found) 
        {
            cout << "Customer Information: " << endl;
            cout << result << endl;
        }

        else
        {
            cout << "\nNo customer information under specified key.\n"; 
        }
    
        cout << "\n\nDo you want to enter another key (0 for yes, 1 for no): ";
        cin >> new_key;
    }
    
    cout << endl << endl << endl;
    return EXIT_SUCCESS;

}

void read_data(table<w_field>& w_table)
{
    w_field temp_field;
    int i=0;
    int space_counter;
    char c; //for get
    ifstream fin;

    char key[key_length + 1]; // these character strings get filled
    char name[name_length + 1];
    char gallons[gallons_length + 1];
    char fee[fee_length];

    int key1; //need the actual numbers 
    int gallons1;
    double fee1;

    fin.open("water.fixed");
    assert(!fin.fail());

    while(fin.peek() != EOF)
    {
        // Fill key variable and turn it into an integer value
        for(i = 0; i < key_length; i++)
        {
            fin.get(c);
            key[i] = c;
        }
        key1 = atoi(key);
       
        // Fill name character array and skip blank spaces
        space_counter = 0; // reset the space counter
        for(i = 0; i < name_length; i++)
        {
            fin.get(c);
            if (space_counter == 2)
            {
                //Don't add anything, two consecutive spaces
                //have been encountered
            }

            // Make the last inserted character the end line character 
            // because two consecutive spaces have been encountered
            else if(c == ' ' && space_counter == 1)
            {
                name[i-1] = '\0';
                space_counter++;
            }

            // The program encounters a space in the name
            else if(c == ' ')
            {
                name[i] = c;
                space_counter++;
            }

            // The program encounters a normal name character
            else
            {
                name[i] = c; 
                space_counter = 0;
                name[i] = c;
            }
        }
        name[i] = '\0';

        // Fill gallons variable and turn into integer value
        for(i = 0; i < gallons_length; i++)
        {
            fin.get(c);
            gallons[i] = c;
    
        }
        gallons1 = atoi(gallons);

        // Fill fee variable and turn into double value
        for(i = 0; i < fee_length; i++)
        {
            fin.get(c);
            fee[i] = c;
        }
        fee1 = atof(fee);

        temp_field = w_field(key1, name, gallons1, fee1);
        
        w_table.insert(temp_field);

        // get the endline character 
        