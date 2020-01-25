Received: from larkspur.Mines.EDU (larkspur.Mines.EDU [138.67.2.4])
	by slate.Mines.EDU (AIX4.3/8.9.3/8.9.1) with ESMTP id VAA41010
	for <jhillert@mines.edu>; Thu, 16 Nov 2000 21:49:05 -0700
Received: (from rspinhir@localhost)
	by larkspur.Mines.EDU (8.9.1/8.9.1) id VAA4785120
	for jhillert; Thu, 16 Nov 2000 21:49:03 -0700 (MST)
Date: Thu, 16 Nov 2000 21:49:03 -0700 (MST)
From: Spinhirne <rspinhir@larkspur.Mines.EDU>
Message-Id: <200011170449.VAA4785120@larkspur.Mines.EDU>
To: jhillert@larkspur.Mines.EDU
Subject: cs261f lab12
X-UIDL: dR'!!V>a!![D-!!DQ,!!

Grade Report for Lab 12

           Typescript1               ___5____ 5 pts
              Header and comments     1 pt
              GetCar and WriteCar completed for one record  2 pts
              Loop in main reads using GetCar and Writecar until
                EOF                                             1 pt
              Output file correctly shows price increase        1 pt


           Typescript 2              ___5____ 5 pts
              Header and comments   1 pts
              member function Print is completed and used   1 pt
              two constructors are protyped and completed and
                   tested                                     2 pts
              Normalize is completed and tested               1 pt

           Total                     ___10____ 10 pts
                     
Script started on Tue Nov 14 00:56:48 2000
$ cat cars.cpp
// cars.cpp 
// Program Uses: cars.dat
// Name: John Hillert
// Date: 11/13/00
// Program Cars reads a record from a file and writes 
// its contents back to another file with the price member 
// This code reprints car prices increased by 10%.  
/////////////////////////////////////////////////////////////////

#include <iostream.h>
#include <fstream.h>
#include <iomanip.h>

typedef  char String15[16];
struct  DateType
{
    int  month;
    int  day;
    int  year;
};

struct  CarType
{
    float    price;
    DateType purchased;
    String15 customer;
};

void  GetCar(ifstream&, CarType&);
// Pre:  File dataIn has been opened.
// Post: The fields of car are read from file dataIn.           

void  WriteCar(ofstream&, CarType);
// Pre:  File dataOut has been opened.
// Post: The fields of car are written on file dataOut,
//       appropriately labeled.                     

int main ()
{
    CarType  car;
    ifstream dataIn;
    ofstream dataOut;

    dataIn.open("cars.dat");
    dataOut.open("cars.out");

    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    dataOut.setf(ios::fixed, ios::floatfield); 
    dataOut.setf(ios::left); 
    dataOut.precision(2);

    while(! dataIn.eof())
    {
       GetCar(dataIn, car);
       car.price = car.price + car.price * .1;    
       if(! dataIn.eof())
          WriteCar(dataOut, car);
    }
    /* 
       Fill in the code to loop through the records in "cars.dat"
       increase each price by 10%.
       Write the new record to the file "cars.out"
       -- Use the functions GetCar and WriteCar.
    */ 
    
    return 0;
}

//*****************************************************


void  GetCar(ifstream&  dataIn, CarType&  car)
// Pre:  File dataIn has been opened.
// Post: The fields of car are read from file dataIn.
{
   // Use dataIn.get() to read in the customer name. 
   // Use a maximum length of 15 characters for the second parameter. 
   // See previous lab reviews for syntax.

   dataIn.getline(car.customer,15);
   // Read in the price, day, month and year.
   dataIn >> car.price;
   dataIn >> car.purchased.day;
   dataIn >> car.purchased.month;
   dataIn >> car.purchased.year;    
   dataIn.ignore(2, '\n');
   
}
                                                            
//*****************************************************

void  WriteCar(ofstream&  dataOut, CarType  car)
// Pre:  File dataOut has been opened.
// Post: The fields of car are written on file dataOut,
//     appropriately labeled.  
//
//    Customer:   name
//    Price:      increased
//    Purchased:  day/month/year
//    
{
    dataOut << setw(13) << "Customer:" << car.customer << endl;
    dataOut << setw(13) << "Price:" << "$" << car.price << endl;
    dataOut << setw(13) << "Purchased:" << car.purchased.day << "/" 
            << car.purchased.month << "/" << car.purchased.year << endl; 
    dataOut << endl;
    /*  
        Complete the code to output the information in the
        format given above

    */
}

$ cat cars.c dat
Tiny Tim      55000  1 1 1985
Mary Murphay  12500  2 7 1995
Bear Bare     44444  9 6 1990
Sally Sale    7500   6 3 1970
Betty Bye     18888  4 8 1988
Alice Alas    23005  6 6 1992

$ c CC cars.cpp
$ a.out
$ ls
a.out        cars.cpp     cars.dat     cars.out     money.cpp    typescript1
$ cat cars.c out
Customer:    Tiny Tim      
Price:       $60500.00
Purchased:   1/1/1985

Customer:    Mary Murphay  
Price:       $13750.00
Purchased:   2/7/1995

Customer:    Bear Bare     
Price:       $48888.40
Purchased:   9/6/1990

Customer:    Sally Sale    
Price:       $8250.00
Purchased:   6/3/1970

Customer:    Betty Bye     
Price:       $20776.80
Purchased:   4/8/1988

Customer:    Alice Alas    
Price:       $25305.50
Purchased:   6/6/1992

$ ^D
script done on Tue Nov 14 00:57:36 2000
Script started on Tue Nov 14 01:01:00 2000
$ ^[  $ script -a typescript2$ a.out                $ CC money.cpp$ rm typescript2$ a.out         $ CC money.cpp$ cat money.cpp$ 
// Program Money manipulates instances of class MoneyType.
// From here through the next line of asterisks would go in the header file.

class MoneyType 
  {public:    
       MoneyType(long, long);
       // Constructor allowing initialization
       MoneyType();
       // Default constructor
       void  Initialize(long, long);    
       // initializes dollars and cents
       long  DollarsAre() const;    
       // returns the value of dollars
       long  CentsAre() const;    
       // reurns value of cents 
       MoneyType Add(MoneyType) const;
       // adds value to self
       void  print(); 
       // Prints value to screen
       void Normalize();
    private:    
       long  dollars;     
       long  cents;
    };

//**********************************************************

// From here through the next line of asterisks would go in the driver file.
// The client program must include the header file.
#include <iostream.h>

int main ()
{        
     MoneyType  money1;    
     MoneyType  money2;    
     MoneyType  money3;    
     MoneyType  Money4(20, 22);  
     MoneyType  Money5;

     money1.Initialize(10, 59);    
     money2.Initialize(20, 70);    
     money3 = money1.Add(money2);    
     money3.print();

     cout << "\n\nMoney4 was initialized by a constructor \n"
          << "that took two values. The value of Money4 is: ";
     Money4.print();

     cout << "\n\nMoney5 was initialized by a default constructor \n"
          << "The value of Money5 is: ";
     Money5.print(); 

     cout << "\n\nMoney3 is the first value in this program.\n"
          << "Since what is actually 129 cents looks more like 12.9 cents"
          << "\nwe have a function called \"normalize\" to fix the problem\n"
          << "Here it is in action: money3.normalize = ";
     money3.Normalize();
     money3.print();
     cout << endl << endl;

     return 0;
}

//********************************************************

// From here through the end of the file would go in the implementation file.
// The implementation file must include the header file.

MoneyType::MoneyType(long Dollars, long Cents)
   {
      dollars = Dollars;
      cents = Cents;
   }
MoneyType::MoneyType()
   {
      dollars = 0;
      cents = 0;
   }
void  MoneyType::Initialize(long newDollars, long newCents)
// Post: dollars is set to newDollars; cents is set to
//       newCents.
   {        
      dollars = newDollars;
      cents = newCents; 
   } 

long  MoneyType::DollarsAre() const
// Post: Class member dollars is returned.
   {    
      return dollars;
   }  

long  MoneyType::CentsAre() const 
//Post: Class member cents is returned.
   {    
      return cents;
   }

MoneyType MoneyType::Add(MoneyType  value) const
// Pre:  Both operands have been initialized. 
// Post: value + self is returned.
   {    
        MoneyType  result;    
        result.cents = cents + value.cents;    
        result.dollars = dollars + value.dollars;    
        return result;
   }
void MoneyType::print() 
// Pre: value has to be filled
// Post: monetary amount from class MoneyType is output to the screen
   {
       cout << "$"  << dollars << "."           
            << cents  << endl;    
   }
void MoneyType::Normalize()
   {
      if(cents > 99)
      {
         dollars = dollars + (cents / 100);
         cents = cents % 100;
      }
   }
$ CC c money.cpp
$ a.out
$30.129


Money4 was initialized by a constructor 
that took two values. The value of Money4 is: $20.22


Money5 was initialized by a default constructor 
The value of Money5 is: $0.0


Money3 is the first value in this program.
Since what is actually 129 cents looks more like 12.9 cents
we have a function called "normalize" to fix the problem
Here it is in action: money3.normalize = $31.29


$ ^D
script done on Tue Nov 14 01:01:15 2000
