// Program: Lab4_driver
// Author: John Hillert
// Last Updated: 9/17/02
// Purpose: To test the string_sequence class using a list of rodents
//          and a string_sequence called rodents to store them in.
// Note: This program should be piped into an output file, like
// teststring > output.dat where testring is the executable name. 
/////////////////////////////////////////////////////////////////////

#include <cassert>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include "string_sequence.h"

using namespace std;
using namespace stringseq;

void show_rodents(string_sequence rodent_list);

int main()
{
   char rodent[30]; 
   string_sequence rodents;

   // Input stream
   ifstream ins;

   ins.open("data.dat");
   assert(! ins.fail());

   // Output to the screen
   // Input the rodents into data structure 
   cout << "\n Input rodents now. . .\n\n";
   while(ins.peek() != EOF)
   {  
      ins.getline(rodent, 30);
      rodents.attach(rodent);
      cout << rodents.current() << endl;
   } 
   
   cout << "\nTESTING THE EXPAND FUNCTION\n";
   cout << "\nALSO TESTS OVERLOADED []\n";
   cout << "\nThe size of the used portion is: " << rodents.size();
   show_rodents(rodents);

   // TESTING REMOVE_CURRENT FUNCTION 
   cout << "\nTESTING REMOVE_CURRENT FUNCTION AT END OF ARRAY\n";
   cout << "\nThe current rodent is: " << rodents.current() << endl;
   rodents.remove_current();
   cout << "The current rodent is: " << rodents.current() << endl;
      
   // RELIST RODENTS TO SEE THAT CURRENT RODENT HAS REALLY BEEN REMOVED 
   cout << "\nRELIST RODENTS TO SEE THAT RODENT HAS BEEN REMOVED\n";
   show_rodents(rodents); 

   // AGAIN FOR BEGINNING OF ARRAY
   cout << "\nTESTING REMOVE_CURRENT FUNCTION AT BEGINNING OF ARRAY\n";
   rodents.start();
   cout << "\nThe current rodent is: " << rodents.current() << endl;
   rodents.remove_current();
   cout << "The current rodent is: " << rodents.current() << endl;
      
   cout << "\nRELIST RODENTS TO SEE THAT RODENT HAS BEEN REMOVED\n";
   show_rodents(rodents); 

   cout << "\n\nTESTING COPY CONSTRUCTOR\n";
   cout << "RODENTS IN \"rodents2\" ARE: \n"; 
   string_sequence rodents2(rodents);
   show_rodents(rodents2);

   cout << "\n\nTESTING OVERLOADED = BY SETTING EMPTY \"rodents3\" " 
        << "EQUAL TO ORIGINAL \"rodents\"\n\n";  

   string_sequence rodents3;
   rodents3 = rodents;
   show_rodents(rodents3);

   return EXIT_SUCCESS;
}
 
void show_rodents(string_sequence rodent_list)
{
   cout << "\n\nThe rodents in the list are:\n\n";
   for(size_t i =