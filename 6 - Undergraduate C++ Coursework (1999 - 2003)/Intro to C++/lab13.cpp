Received: from larkspur.Mines.EDU (larkspur.Mines.EDU [138.67.2.4])
	by slate.Mines.EDU (AIX4.3/8.9.3/8.9.1) with ESMTP id XAA126714
	for <jhillert@mines.edu>; Tue, 21 Nov 2000 23:58:06 -0700
Received: (from rspinhir@localhost)
	by larkspur.Mines.EDU (8.9.1/8.9.1) id XAA3975465
	for jhillert; Tue, 21 Nov 2000 23:58:01 -0700 (MST)
Date: Tue, 21 Nov 2000 23:58:01 -0700 (MST)
From: Spinhirne <rspinhir@larkspur.Mines.EDU>
Message-Id: <200011220658.XAA3975465@larkspur.Mines.EDU>
To: jhillert@larkspur.Mines.EDU
Subject: cs261f lab13
X-UIDL: 6Ad"!d!2!!K)3!!nl9!!

Grade Report for Lab 

           Typescript1               ___5____ 5 pts
              Header and comments     1 pt
              Array of type sphereClass declared for 10 items  1pt
              Attributes of spheres filled with:
                a + rand()%(b-1+1) for some range using SetRadius( ) 
                ( optional use of Constructor to set radius )  2 pts  
              Ten spheres displayed using member function    
                             DisplayStatistics()               1 pt  

           Typescript 2              ___5____ 5 pts
              No points off for comments on this part
              Implementation file complete 3 pts    
              Driver completed             2 pts

           Total                     ___10____ 10 pts
                     
Script started on Fri Nov 17 23:15:21 2000
$ cat sphere/sphere-demo> .C
// sphere-demo.C
// Last Modified: 11/17/00
// Last Modified by: John Hillert
// Purpose: This program displays the statistics of ten random spheres
// using the class sphere.h
////////////////////////////////////////////////////////////////////////


#include <iostream.h>
#include <time.h>
#include <stdlib.h>
#include "sphere.h"

const int maxspheres = 10;

main( )
{
	sphereClass Sphere[maxspheres];
 
	for(int i = 0; i < maxspheres; i++)
	{
	   srand(i+1);
           Sphere[i].SetRadius(rand());
           Sphere[i].DisplayStatistics();
	}

	return 0;           
            

}
$ make sphere
`sphere' is up to date.
$ sphere-demo
sh: sphere-demo:  not found
$ cd sphere
$ shpere     phere-demo

Radius = 16838
Diameter = 33676
Circumference = 105796
Area = 3.56279e+09
Volume = 1.99968e+13

Radius = 908
Diameter = 1816
Circumference = 5705.13
Area = 1.03605e+07
Volume = 3.13578e+09

Radius = 17747
Diameter = 35494
Circumference = 111508
Area = 3.95785e+09
Volume = 2.34133e+13

Radius = 1817
Diameter = 3634
Circumference = 11416.5
Area = 4.14877e+07
Volume = 2.51277e+10

Radius = 18655
Diameter = 37310
Circumference = 117213
Area = 4.37321e+09
Volume = 2.71941e+13

Radius = 2726
Diameter = 5452
Circumference = 17127.9
Area = 9.33816e+07
Volume = 8.48527e+10

Radius = 19564
Diameter = 39128
Circumference = 122924
Area = 4.80978e+09
Volume = 3.13661e+13

Radius = 3634
Diameter = 7268
Circumference = 22833.1
Area = 1.65951e+08
Volume = 2.01022e+11

Radius = 20472
Diameter = 40944
Circumference = 128629
Area = 5.2666e+09
Volume = 3.59393e+13

Radius = 4543
Diameter = 9086
Circumference = 28544.5
Area = 2.59355e+08
Volume = 3.9275e+11
$ ^D
script done on Fri Nov 17 23:16:06 2000
Script started on Mon Nov 20 17:26:11 2000
$ cat vector.h
// header file for class vectorClass

#include<iostream.h>
#include<stdlib.h>

class vectorClass
{
     private:
          // Attributes for the class 
          int * array;
          int length;
          // length is the capacity of the array that is always filled
     public:
          // Methods for the class
          vectorClass();
          // Precondition: default constructor
          // Postcondition: length is 0 and array pointer is NULL

          vectorClass(int maxLength);
          // Precondition: maxLength is an integer value
          // Postcondition: length = maxLength and array points to the head of a 
          //                section of memory with capacity maxLength

          vectorClass(const vectorClass &v);
          // Postcondition:  Copy - constructor

          ~vectorClass();
          // Postcondition:  Memory is freed 

           int getLength() const; 
           // Postcondition: returns length

           void display();
           // Postcondition:  iterator to display all the values

           int & operator[](int i) const;
           // Precondition: i is less than length
           // Postcondition: returns the value stored in the ith component

           vectorClass  operator=( const vectorClass& v);
           // Postcondition: overloaded assignment operator to allow its use for
           //                the dynamic attributes
};

/* Non-member function ******************************************/

vectorClass operator+(const vectorClass& v1,  const vectorClass& v2);
// Precondition: two input vectors 
// Postcondition: returns the sum of the input vectors

$ cat dri   vector  .cpp
// Implementation file for class vectorClass
#include <iostream.h>
#include <iomanip.h>
#include <stdlib.h>
#include "vector.h"


vectorClass::vectorClass()
{
    array =NULL;
    length =0;
}

vectorClass::vectorClass(int maxLength)
{
   length = maxLength;
   array = new int [length];
   /* fill in the code to set the length attribute to maxLength
      and allocate memory for array */
}

vectorClass::vectorClass(const vectorClass & v)
{
     length = v.length;
     array = new int [length];
     for ( int i = 0 ; i < length; i++ )
           array[i] = v.array[i];
   
}
 
vectorClass::~vectorClass()
{
     delete [] array;
     cout << "destructor is called and contents of this vector are deleted.\n";
     /* put in code to free memory and  
        print a message that the destructor is called */
}
 
int vectorClass::getLength() const 
{
      return length;
     /* fill in code to return the length attribute */
}
 
void vectorClass::display()
{
    cout << "(";

    for(int i = 0; i < length; i++)
    {
       cout << array[i];
       if(i < length - 1)
          cout << "," << setw(4);
    } 
    cout << ")" << endl;
    /* fill in code to display the contents of the components
       of the array to the screen  
       Format so the components are aligned    */
}

int & vectorClass::operator[](int i) const
{
      if ( i <0|| length <= i)
        {
            cerr << " Illegal vectorClass index: " << i << " max index =";
            cerr << (length -1) << endl;
            exit(1);
         }
      return array[i];
}

vectorClass  vectorClass::operator =(const vectorClass& v)
{
     length = v.length;
     for ( int i = 0; i< length ; i++)
          array[i]=v.array[i];
      
     return *this;
     //  this pointer refers to the left hand object
}

vectorClass operator+(const vectorClass&  v1,const vectorClass &  v2 )
// not a member function
{
     if(v1.getLength() != v2.getLength())
     {
	cerr << "Illegal vector addition: Vectors have unequal dimensions.\n";
        exit(1);
     }
     vectorClass temp(v1.getLength());

     for(int i = 0; i < v1.getLength(); i++)
     {
        temp[i] = v1[i] + v2[i];
     }

     return temp;
     /* Fill in code :
        1) Check that the vectors are of the same length and send an error 
           to the screen if not.  (See [] operator)
        2) Create a temporary object of type vectorClass
        3) Add the vectors component by component into the temporary object.
        4) Return the temporary object. 
     */
}
$ cat driver  .cc pp
#include <iostream.h> 
#include <stdlib.h>
#include "vector.h"

const int elements = 7;

void fillVector(vectorClass&, int, int&);
// Precondition: vector of type vectorClass has been 
// declared with length "elements" 
// Postcondition: returns vector with values designated to each element

main()
{ 
    int j = 1; // this a counter for random numbers in fillVector
    vectorClass vector1(elements), vector2(elements), vector3(elements);
  
    fillVector(vector1, elements, j);
    fillVector(vector2, elements, j);
   
    for(int i = 0; i < elements; i++)
       vector3[i] = 0; 

    cout << "Vector 1:   ";
    vector1.display();

    cout << "Vector 2:   ";
    vector2.display();

    cout << "Vector 3:   ";
    vector3.display();

    vector3 = vector1 + vector2;

    cout << "Vector 1 and Vector 2 are added and put into Vector 3.\n"
   	 << "Vector 3:   ";

    vector3.display();

    return 0;
}

void fillVector(vectorClass& vector, int elements, int& j)
{
    for(int i = 0; i < elements; i++)
    {
	srand(j);
	vector[i] = rand()%100;
        j++;
    }
} 	       
$ make
`driver' is up to date.
$ driver
Vector 1:   (38,   8,  47,  17,  55,  26,  64)
Vector 2:   (34,  72,  43,  81,  51,  90,  60)
Vector 3:   (0,   0,   0,   0,   0,   0,   0)
destructor is called and contents of this vector are deleted.
destructor is called and contents of this vector are deleted.
Vector 1 and Vector 2 are added and put into Vector 3.
Vector 3:   (72,  80,  90,  98, 106, 116, 124)
destructor is called and contents of this vector are deleted.
destructor is called and contents of this vector are deleted.
destructor is called and contents of this vector are deleted.
$ ^D

script done on Mon Nov 20 17:27:23 2000
Script started on Fri Nov 17 23:15:21 2000
$ cat sphere/sphere-demo> .C
// sphere-demo.C
// Last Modified: 11/17/00
// Last Modified by: John Hillert
// Purpose: This program displays the statistics of ten random spheres
// using the class sphere.h
////////////////////////////////////////////////////////////////////////


#include <iostream.h>
#include <time.h>
#include <stdlib.h>
#include "sphere.h"

const int maxspheres = 10;

main( )
{
	sphereClass Sphere[maxspheres];
 
	for(int i = 0; i < maxspheres; i++)
	{
	   srand(i+1);
           Sphere[i].SetRadius(rand());
           Sphere[i].DisplayStatistics();
	}

	return 0;           
            

}
$ make sphere
`sphere' is up to date.
$ sphere-demo
sh: sphere-demo:  not found
$ cd sphere
$ shpere     phere-demo

Radius = 16838
Diameter = 33676
Circumference = 105796
Area = 3.56279e+09
Volume = 1.99968e+13

Radius = 908
Diameter = 1816
Circumference = 5705.13
Area = 1.03605e+07
Volume = 3.13578e+09

Radius = 17747
Diameter = 35494
Circumference = 111508
Area = 3.95785e+09
Volume = 2.34133e+13

Radius = 1817
Diameter = 3634
Circumference = 11416.5
Area = 4.14877e+07
Volume = 2.51277e+10

Radius = 18655
Diameter = 37310
Circumference = 117213
Area = 4.37321e+09
Volume = 2.71941e+13

Radius = 2726
Diameter = 5452
Circumference = 17127.9
Area = 9.33816e+07
Volume = 8.48527e+10

Radius = 19564
Diameter = 39128
Circumference = 122924
Area = 4.80978e+09
Volume = 3.13661e+13

Radius = 3634
Diameter = 7268
Circumference = 22833.1
Area = 1.65951e+08
Volume = 2.01022e+11

Radius = 20472
Diameter = 40944
Circumference = 128629
Area = 5.2666e+09
Volume = 3.59393e+13

Radius = 4543
Diameter = 9086
Circumference = 28544.5
Area = 2.59355e+08
Volume = 3.9275e+11
$ ^D
script done on Fri Nov 17 23:16:06 2000
Script started on Mon Nov 20 17:41:57 2000
$ cat driver.c           d vector
$ cat driver.cpp
// Program: driver.cpp
// Last Modified: 11/20/00
// Name: John Hillert
// Purpose: This program is the driver for class vectorClass.  It shows
// several aspects of this class by filling three vectors, the first two
// with random numbers.  Then it adds those two and puts them into the third.
// The three vectors are output before the addition, and then the third
// is output again after the addition.
////////////////////////////////////////////////////////////////////////////
#include <iostream.h> 
#include <stdlib.h>
#include "vector.h"

const int elements = 7;

void fillVector(vectorClass&, int, int&);
// Precondition: vector of type vectorClass has been 
// declared with length "elements" 
// Postcondition: returns vector with values designated to each element

main()
{ 
    int j = 1; // this a counter for random numbers in fillVector
    vectorClass vector1(elements), vector2(elements), vector3(elements);
  
    fillVector(vector1, elements, j);
    fillVector(vector2, elements, j);
   
    for(int i = 0; i < elements; i++)
       vector3[i] = 0; 

    cout << "Vector 1:   ";
    vector1.display();

    cout << "Vector 2:   ";
    vector2.display();

    cout << "Vector 3:   ";
    vector3.display();

    vector3 = vector1 + vector2;

    cout << "Vector 1 and Vector 2 are added and put into Vector 3.\n"
   	 << "Vector 3:   ";

    vector3.display();

    return 0;
}

void fillVector(vectorClass& vector, int elements, int& j)
{
    for(int i = 0; i < elements; i++)
    {
	srand(j);
	vector[i] = rand()%100;
        j++;
    }
} 	       
$ cat vector.h
// header file for class vectorClass

#include<iostream.h>
#include<stdlib.h>

class vectorClass
{
     private:
          // Attributes for the class 
          int * array;
          int length;
          // length is the capacity of the array that is always filled
     public:
          // Methods for the class
          vectorClass();
          // Precondition: default constructor
          // Postcondition: length is 0 and array pointer is NULL

          vectorClass(int maxLength);
          // Precondition: maxLength is an integer value
          // Postcondition: length = maxLength and array points to the head of a 
          //                section of memory with capacity maxLength

          vectorClass(const vectorClass &v);
          // Postcondition:  Copy - constructor

          ~vectorClass();
          // Postcondition:  Memory is freed 

           int getLength() const; 
           // Postcondition: returns length

           void display();
           // Postcondition:  iterator to display all the values

           int & operator[](int i) const;
           // Precondition: i is less than length
           // Postcondition: returns the value stored in the ith component

           vectorClass  operator=( const vectorClass& v);
           // Postcondition: overloaded assignment operator to allow its use for
           //                the dynamic attributes
};

/* Non-member function ******************************************/

vectorClass operator+(const vectorClass& v1,  const vectorClass& v2);
// Precondition: two input vectors 
// Postcondition: returns the sum of the input vectors

$ cat vector  .cpp
// Program: vector.cpp
// Last Modified: 11/20/00
// Name of modifier: John Hillert
// Implementation file for class vectorClass
///////////////////////////////////////////////////////////////////////////
#include <iostream.h>
#include <iomanip.h>
#include <stdlib.h>
#include "vector.h"


vectorClass::vectorClass()
{
    array =NULL;
    length =0;
}

vectorClass::vectorClass(int maxLength)
{
   length = maxLength;
   array = new int [length];
   /* fill in the code to set the length attribute to maxLength
      and allocate memory for array */
}

vectorClass::vectorClass(const vectorClass & v)
{
     length = v.length;
     array = new int [length];
     for ( int i = 0 ; i < length; i++ )
           array[i] = v.array[i];
   
}
 
vectorClass::~vectorClass()
{
     delete [] array;
     cout << "destructor is called and contents of this vector are deleted.\n";
     /* put in code to free memory and  
        print a message that the destructor is called */
}
 
int vectorClass::getLength() const 
{
      return length;
     /* fill in code to return the length attribute */
}
 
void vectorClass::display()
{
    cout << "(";

    for(int i = 0; i < length; i++)
    {
       cout << array[i];
       if(i < length - 1)
          cout << "," << setw(4);
    } 
    cout << ")" << endl;
    /* fill in code to display the contents of the components
       of the array to the screen  
       Format so the components are aligned    */
}

int & vectorClass::operator[](int i) const
{
      if ( i <0|| length <= i)
        {
            cerr << " Illegal vectorClass index: " << i << " max index =";
            cerr << (length -1) << endl;
            exit(1);
         }
      return array[i];
}

vectorClass  vectorClass::operator =(const vectorClass& v)
{
     length = v.length;
     for ( int i = 0; i< length ; i++)
          array[i]=v.array[i];
      
     return *this;
     //  this pointer refers to the left hand object
}

vectorClass operator+(const vectorClass&  v1,const vectorClass &  v2 )
// not a member function
{
     if(v1.getLength() != v2.getLength())
     {
	cerr << "Illegal vector addition: Vectors have unequal dimensions.\n";
        exit(1);
     }
     vectorClass temp(v1.getLength());

     for(int i = 0; i < v1.getLength(); i++)
     {
        temp[i] = v1[i] + v2[i];
     }

     return temp;
     /* Fill in code :
        1) Check that the vectors are of the same length and send an error 
           to the screen if not.  (See [] operator)
        2) Create a temporary object of type vectorClass
        3) Add the vectors component by component into the temporary object.
        4) Return the temporary object. 
     */
}
$ make
	CC -c vector.cpp
	CC -c driver.cpp	
	CC vector.o driver.o -o driver 
$ driver
Vector 1:   (38,   8,  47,  17,  55,  26,  64)
Vector 2:   (34,  72,  43,  81,  51,  90,  60)
Vector 3:   (0,   0,   0,   0,   0,   0,   0)
destructor is called and contents of this vector are deleted.
destructor is called and contents of this vector are deleted.
Vector 1 and Vector 2 are added and put into Vector 3.
Vector 3:   (72,  80,  90,  98, 106, 116, 124)
destructor is called and contents of this vector are deleted.
destructor is called and contents of this vector are deleted.
destructor is called and contents of this vector are deleted.
$ 
script done on Mon Nov 20 17:42:27 2000
