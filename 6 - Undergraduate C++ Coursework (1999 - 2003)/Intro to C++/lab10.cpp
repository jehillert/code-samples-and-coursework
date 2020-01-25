Received: from larkspur.Mines.EDU (larkspur.Mines.EDU [138.67.2.4])
	by slate.Mines.EDU (AIX4.3/8.9.3/8.9.1) with ESMTP id RAA159468
	for <jhillert@mines.edu>; Wed, 1 Nov 2000 17:01:35 -0700
Received: (from rspinhir@localhost)
	by larkspur.Mines.EDU (8.9.1/8.9.1) id RAA3976899
	for jhillert; Wed, 1 Nov 2000 17:01:32 -0700 (MST)
Date: Wed, 1 Nov 2000 17:01:32 -0700 (MST)
From: Spinhirne <rspinhir@larkspur.Mines.EDU>
Message-Id: <200011020001.RAA3976899@larkspur.Mines.EDU>
To: jhillert@larkspur.Mines.EDU
Subject: cs261f lab10
X-UIDL: PJ("!//+"!o\Q!!=jA!!

Grade Report for Lab 10

           Typescript1               ___4____ 4 pts
              Header and comments     1 pts
              Correct EOF loop        2 pts
              Input for filename      1 pt

           Typescript 2              ___3____ 3 pts
              Header and comments   1 pts
              Determines enum type  1 pts
              Correct output using dataIn.get()  1 pt


           Typescript 3              ___3___  3 pts
              Header and comments   1 pts
              Completed twodim.cpp basic   1 pts
              Completed largest function   1 pts


           Total                     __10_____ 10 pts
                     
Script started on Mon Oct 30 15:35:14 2000
$ cs at shell1.cpp
// Program: shell1.cpp
// Name: John Hillert
// Date: 10/30/00
// Program Shell1 takes pairs of strings from a file of the users choice
// and states which string comes first alphabetically
////////////////////////////////////////////////////////////////////////

#include <iostream.h>
#include <string.h>
#include <fstream.h>
#include <stdlib.h>

typedef  char String20[21];
enum  CompareType {LESS, EQUAL, GREATER};

CompareType  Compare(const String20, const String20);

int  main ()
{
    String20  str1;
    String20  str2;
    String20 filename;

    ifstream indata;
    
    cout << "\nThis program takes pairs of strings from a file of your\n"
         << "choice and states which one comes first alphabetically.\n";

    cout << "\nEnter name of file: "; 
    cin >> filename;
   
    indata.open(filename);

    while(indata.fail())
    {
       char ans; 
       cout << "\nERROR! Input file opening failed. Either the wrong file name\n"
            << "was typed in, or there is a problem with the file itself.\n"
            << "\nDo you wish to try again? Enter Y for yes, or N for no.\n";
       cin >> ans;
       if(ans == 'y' || ans == 'Y')
       {
          cout << "\nEnter name of file:";
          cin >> filename;
          indata.open(filename); 
       }
       else
          exit(1);
    }
    
    indata >> str1;
    indata >> str2;
 
    while(! indata.eof())
    {
       switch (Compare(str1, str2))
       {
           case LESS:
              cout << str1 << " is before " << str2 << endl;
              break;
           case EQUAL:
              cout << str1 << " equals " << str2 << endl;
              break;
           case GREATER:
              cout <<  str1 << " is after " << str2 << endl;
              break;
       }
       indata >> str1;
       indata >> str2;
    }
    indata.close();

    return 0;
}

//*************************************************

CompareType Compare(const String20 str1, const String20  str2)
{
    int  result;
    result = strcmp(str1, str2);      
    if(result < 0)
       return LESS;
    if(result == 0)
       return EQUAL;
    if(result > 0)
       return GREATER;
}


$ CC shell1.cpp
cc-1116 CC: WARNING File = shell1.cpp, Line = 88
  Non-void function "Compare" (declared at line 78) should return a value.

  }
  ^

$ a.out

This program takes pairs of strings from a file of your
choice and states which one comes first alphabetically.

Enter name of file: lkj

ERROR! Input file opening failed. Either the wrong file name
was typed in, or there is a problem with the file itself.

Do you wish to try again? Enter Y for yes, or N for no.
y

Enter name of file:StringPr.dat
Bob is before bob
tree is after Tree
tree equals tree
tree is after three
Tree is before tree
Tree equals Tree
TREE is before TREET
TREET is after TREE
55 is before 56
56 is after 55
bobby is after Bob
dd is after 55
55 equals 55
Robert is before bob
have is after haVe
We is before wE
tried equals tried
all is before of
the is after THE
combinations is after c6ombinations
Quit equals Quit
$ a.out

This program takes pairs of strings from a file of your
choice and states which one comes first alphabetically.

Enter name of file: lkj

ERROR! Input file opening failed. Either the wrong file name
was typed in, or there is a problem with the file itself.

Do you wish to try again? Enter Y for yes, or N for no.
n
$ ^D
script done on Mon Oct 30 15:35:54 2000
Script started on Mon Oct 30 16:20:30 2000
$ cat shell2.cpp
// shell2.cpp
// Last modified by: John Hillert
// Date: 10/30/00
// Program Shell2 reads characters from file DataIn and 
// writes them to DataOut with the following changes:             
//    all letters are converted to uppercase, digits are
//    unchanged, and all other characters except blanks and         
//    newline markers are removed.                                       
////////////////////////////////////////////////////////////

#include <iostream.h>
#include <ctype.h>
#include <fstream.h>

enum CharType {LO_CASE, UP_CASE, DIGIT, BLANK_NEWLINE, OTHER};

CharType  kindOfChar(char);
// Gets the enumerator equivalent to its character input.

int main ()
{
    ifstream  dataIn;
    ofstream  dataOut;
    char  character;

    dataIn.open("reformat.dat");
    dataOut.open("dataout.dat");

    dataIn.get(character);    // priming read
    while (dataIn)
    {
	switch (kindOfChar(character))
	{
           char c;
           case LO_CASE: 
           {
              c = toupper(character);
              dataOut.put(c);
              break;
           }
           case UP_CASE:
           {
  	      c = tolower(character);
              dataOut.put(c);
 	      break;
           }
	   case DIGIT:
           {
	      dataOut.put(character);
              break;
           }
           case BLANK_NEWLINE:
           {
              dataOut.put(character);
              break;
           }
	}
	dataIn.get(character);
    }
    dataIn.close();
    dataOut.close();

    return 0;
}


/*************************************************/

CharType  kindOfChar(char character)
// Post: character is converted to the corresponding
//       constant in the enumeration type CharType.
{
    if isupper(character)
	return UP_CASE; 
    else if islower(character)
        return LO_CASE;  
    else if isdigit(character)
        return DIGIT;                                                   
    else if (character == ' ' || character == '\n')
        return BLANK_NEWLINE;                
    else
        return OTHER;
}

$ CC shell2.cpp
$ a.out
$ ls
StringPr.dat    dataout.dat     safeshell2.cpp  shell2.cpp      typescript2
a.out           reformat.dat    shell1.cpp      typescript1
$ \ vi    more dataout.dat
[KLOWERCASE CHARACTERS   uppercase characters
abcdef  
ABCDEFT
12345  6789
     
   

[K[7mdataout.dat: END[m[K$ more reformat.dat
[Klowercase characters   UPPERCASE CHARACTERS
ABCDEF  ....
abcdeft;;;;;
12345  6789
: < > ? " :
   

[K[7mreformat.dat: END[m[K$ ^D

script done on Mon Oct 30 16:23:04 2000

script done on Mon Oct 30 16:23:04 2000
Script started on Mon Oct 30 18:01:48 2000
$ cat twodim.cpp
// twodim.cpp
// Last modified by: John Hillert
// Date: 10/30/00
//
// Program TwoDim manipulates a two-dimensional array 
// variable.                                        
/////////////////////////////////////////////////////////

#include <iostream.h>
#include <fstream.h>

const int ROW_MAX = 8;
const int COL_MAX = 10;

typedef int ItemType;

typedef ItemType TableType[ROW_MAX][COL_MAX];

void  GetTable(ifstream&, TableType, int&, int&);
// Reads values and stores them in the table.

void  PrintTable(ofstream&, const TableType, int, int);
// Writes values in the table to a file. 

void largnum(ofstream&, const TableType, int, int);

int  main ()
{
    TableType  table;
    int  rowsUsed;
    int  colsUsed;
    ifstream  dataIn;
    ofstream  dataOut;
 
    dataIn.open("twod.dat");
    dataOut.open("twod.out");
    GetTable(dataIn, table, rowsUsed, colsUsed);
    PrintTable(dataOut, table, rowsUsed, colsUsed);
    largnum(dataOut, table, rowsUsed, colsUsed);
    return 0;
}
                                                           
//***************************************************    
                                                     
void  GetTable(ifstream&  data, TableType  table,
               int&  rowsUsed, int&  colsUsed)
// Pre:  rowsUsed and colsUsed are on the first line of 
//       file data; values are one row per line       
//       beginning with the second line.                
// Post: Values have been read and stored in the table.                

{
    ItemType  item;
    data  >> rowsUsed >> colsUsed; 

    for (int row = 0; row < rowsUsed; row++)
        for (int col = 0; col < colsUsed; col++)
        {
            data >> item; 
            table[row][col] = item;
        }
}                                                            

//****************************************************     

void  PrintTable(ofstream&  data, const TableType  table, 
                 int  rowsUsed, int  colsUsed)
// Pre:  The table contains valid data.
// Post: Values in the table have been sent to a file by row, 
//       one row per line. 
{                                                           
    for (int row = 0; row < rowsUsed; row++)
        for (int col = 0; col < colsUsed; col++)
        {
            data << table[row][col] << "  ";
            if(col == colsUsed - 1)
                data << endl;
        }                                                      
}

//*****************************************************

void largnum(ofstream& data, const TableType table,
             int rowsUsed, int colsUsed)
// Pre: Table still has the same data
// Post: highest value is found, and output to the output
//       function
{
    data << endl;
    int largest = table[0][0], a, b;
    for (int row = 0; row < rowsUsed; row++)
        for (int col = 0; col < colsUsed; col++)
        {
            if(largest < table[row][col])
            {
                largest = table[row][col];
                a = row;
                b = col;
            }
        }
    data << "The largest value in this table is: " << largest
         << "\nIt is found at location: table[" 
         << a << "][" << b << "]" << endl;
    data << "In other words: row " << a + 1 << ", column " << b + 1 << endl;
}      

             
$ CC twodim.cpp
$ a.out
$ ls
StringPr.dat  reformat.dat  twod.dat      typescript1
a.out         shell1.cpp    twod.out      typescript2
dataout.dat   shell2.cpp    twodim.cpp    typescript3
$ more twod.dat
[K4  5
3  1  4  1  5
2  3  6  7  1
7  8  8  8  8
9  8  7  6  5
[K[7mtwod.dat: END[m[K$ more twod.out
[K3  1  4  1  5  
2  3  6  7  1  
7  8  8  8  8  
9  8  7  6  5  

The largest value in this table is: 9
It is found at location: table[3][0]
In other words: row 4, column 1
[K[7mtwod.out: END[m[K$ ^D

script done on Mon Oct 30 18:02:29 2000

script done on Mon Oct 30 18:02:29 2000
