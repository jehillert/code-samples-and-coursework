Received: from larkspur.Mines.EDU (larkspur.Mines.EDU [138.67.2.4])
	by slate.Mines.EDU (AIX4.3/8.9.3/8.9.1) with ESMTP id KAA88774
	for <jhillert@mines.edu>; Wed, 6 Dec 2000 10:53:01 -0700
Received: (from rspinhir@localhost)
	by larkspur.Mines.EDU (8.9.1/8.9.1) id KAA5667326
	for jhillert; Wed, 6 Dec 2000 10:52:59 -0700 (MST)
Date: Wed, 6 Dec 2000 10:52:59 -0700 (MST)
From: Spinhirne <rspinhir@larkspur.Mines.EDU>
Message-Id: <200012061752.KAA5667326@larkspur.Mines.EDU>
To: jhillert@larkspur.Mines.EDU
Subject: cs261f HW6
X-UIDL: /-R"!J0^!!mNO"!!R>"!

Grade Report for Assignment 6

          Program1: CDAccount Class     ____20____ 20 pts

              header  1
              comments 2
              compiles   7
              constructors          1
              accessor functions ( one for each attribute )  3
              calculate maturity    1
              input (istream parameter)  1
              output (ostream parameter) 1
              test driver ( main() )     3
                                         
          Program2: Complex Class - ADT       ____18____ 20 pts   

              header  1
              comments 2
              compiles  3
              three file format    5
              Constructors, accessors, (modifiers- opt), iterator
              (display-opt), destructor (opt)            3              
              Overloads ==, + , -, *, >>, <<  : All non-members   4
              The minimum # of functions  2 constructors, two accessors,
              Overloaded operators (6).  


          Total                          ___38_____ 40 pts
// sourceCode1.cpp 
// Name: John Hillert 
// Date: 11/28/00
// Purpose: Program to demonstrate the CDAccount class 
/////////////////////////////////////////////////////////////////
// small algorithm
// - need a class
// - this classes public should include
//	- member function that returns INITIAL BALANCE 
//	- member function that returns BALANCE AT MATURITY 
//	- member function that returns INTEREST RATE 
//      - member function that returns TERM 
//      - constructor that SETS ALL SPECIFIED VALUES 
//      - DEFAULT CONSTRUCTOR 
// - NOTE: an input function in the previous functions must take
//   an istream formal parameter.  An output function must take an
//   ostream parameter
// - put all variables in the private
// - include test program
//////////////////////////////////////////////////////////////// 
#include <iostream.h>

class CDAccount
{
public:
   CDAccount(double Balance, double int_rate, double bankterm);
   // initializes all characteristics of a CD account
   // including the account balance, the interest rate, and the term
   CDAccount();
   // default constructor that initializes balance, int_rate, and 
   // the term to zero

   void initialize(istream& fin);
   // this allows you to change the contents of an account that already
   // exists or fill an account with info from a small file
   void show_account(ostream& fout);
   // this displays all of the contents of an account at once,
   // either onto a screen or into another file

   double initial_balance();
   // this function returns the initial balance in the CDAccount
   double new_balance();
   // this function returns the balance of the account at maturity
   double rate();
   // this function returns the interest rate of the account
   int term();
   // this function returns the time it takes for the account
   // to reach maturity
 
private:
   double balance;
   double interest_rate;
   double new_Balance;
   int account_term;//months until maturity
};

int main()
{
   CDAccount account1(124.25, 11.0, 12), account2;
  
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   cout << "\nThe initial balance of account1 is: $" 
        << account1.initial_balance();
   cout << "\nThe annual percent interest rate of account1 is: " 
        << account1.rate();
   cout << "\nThe term (in months) before account1 matures is: "
        << account1.term();
   cout << "\nThe balance after maturity is: $"
        << account1.new_balance() << endl;

   cout << "\nNow a test for changing an account after its "
        << "initial declaration.\n";
   cout << "\nThe values of account2 are: \n";
   account2.show_account(cout);
   
   account2.initialize(cin);
   cout << "The new values in account2 are: \n\n";  
   account2.show_account(cout); 
 
   cout << "End of test program.\n\n";
 
   return 0;
}

//******************************************************************//

CDAccount::CDAccount(double Balance, double int_rate, double bankterm)
{
   balance = Balance;
   interest_rate = int_rate;
   account_term = bankterm;
}

CDAccount::CDAccount()
{
   balance = 0;
   interest_rate = 0;
   account_term = 0; 
   new_Balance = 0;
}

void CDAccount::initialize(istream& fin)
{
   cout << "\nEnter new starting balance: $";
   fin >> balance;
   cout << "\nEnter new annual interest rate: ";
   fin >> interest_rate;
   cout << "\nEnter new term (in months): ";
   fin >> account_term; 
   cout << endl << endl;
}

void CDAccount::show_account(ostream& fout)
{
   fout << "\nThe balance of this account is: $"
        << balance;
   fout << "\nThe annual percent interest rate of this account is: "
        << interest_rate;
   fout << "\nThe term (in months) until maturity is: "
        << account_term;
   fout << "\nThe balance after maturity will be: $"
        << new_balance(); 
   fout << endl << endl;
}

double CDAccount::initial_balance()
{
   return balance;
}

double CDAccount::new_balance()
{
   double interest; 
   interest = balance * (interest_rate / 100) * (account_term / 12.0);
   new_Balance = balance + interest;

   return new_Balance; 
}

double CDAccount::rate()
{
   return interest_rate;
}

int CDAccount::term()
{
   return account_term;
}

// Complex.h
// Programmer: John Hillert
// Date: 11/28/00
//
// This is the HEADER FILE Complex.h. This is the INTERFACE for the 
// class Complex. 
///////////////////////////////////////////////////////////////////
#ifndef COMPLEX_H
#define COMPLEX_H

#include<iostream.h>  

class Complex
{
public:
   Complex(double real_part, double imaginary_part);
   // initializes the real and imaginary parts when object is declared 
   Complex(double real_part);
   // initializes the real part and sets imaginary part to zero
   // when object is declared
   Complex();
   // sets real and imaginary parts to zero when object is declared
   
   friend Complex operator +(const Complex&, const Complex&);
   // takes two objects and sums their real and imaginary values
   friend Complex operator -(const Complex& num1, const Complex& num2);
   // subtracts real and imaginary parts of num2 from num1 
   friend Complex operator *(const Complex&, const Complex&);
   // multiplies real and imaginary parts of two objects
   friend bool operator ==(const Complex&, const Complex&);   
   // returns true if the real and imaginary parts of the two 
   // arguments of type Complex are equal, otherwise returns false
  
   ostream& print(ostream& os) const;   
istream& read(istream& is);   
// overloads the << operator for output values of type Complex
   // Precondition: If outs is a file output stream, then outs 
   // has already been connected to a file
   // overloads the >> operator for input values of type Complex
   // ALL INPUTS OF IMAGINARY NUMBERS SHOULD BE IN "A + Bi" FORMAT
   // Precondition: If ins is a file input stream, then ins has already
   // connected to a file 
***************************
-2 YOU NEEDED TO HAVE ACCESSORS.
*****************************

private:
   double real;
   double imaginary;
};

ostream& operator <<(ostream& outs, const Complex& number);
istream& operator >>(istream& ins, Complex& number);



#endif //COMPLEX_H
/////////////////////////////////////////////////////////////////////////
// Complex.C
// Programmer: John Hillert
// Date: 11/29/00
//
// This is the IMPLEMENTATION FILE: Complex.C.  It is for the ADT Complex.
// The interface for the class Complex is in the header file Complex.h.
//////////////////////////////////////////////////////////////////////////
#include <iostream.h>
#include <stdlib.h>
#include "Complex.h"

Complex::Complex(double real_part, double imaginary_part)
{
   real = real_part;
   imaginary = imaginary_part;
}

Complex::Complex(double real_part)
{
   real = real_part;
   imaginary = 0;
}

Complex::Complex()
{
   real = 0;
   imaginary = 0; 
}

Complex operator +(const Complex& num1, const Complex& num2)
{
   Complex temp;
   temp.real = num1.real + num2.real;
   temp.imaginary = num1.imaginary + num2.imaginary;
   return temp;
}

Complex operator -(const Complex& num1, const Complex& num2)
{
   Complex temp;
   temp.real = num1.real - num2.real;
   temp.imaginary = num1.imaginary - num2.imaginary;
   return temp;
}

Complex operator *(const Complex& num1, const Complex& num2)
{
   Complex temp;
   temp.real = num1.real * num2.real - num1.imaginary * num2.imaginary;
   temp.imaginary = num1.real * num2.imaginary + num2.real * num1.imaginary;
   return temp;
}

bool operator ==(const Complex& num1, const Complex& num2)
{
   return (num1.real == num2.real && num1.imaginary == num2.imaginary);
}

ostream& Complex::print(ostream& os) const{
  os << real;
  if (imaginary > 0) os << " + " << imaginary << "i";
  else os << " - " << imaginary * -1 << "i";
  return (os);
}

istream& Complex::read(istream& is) {
   char symbol;
   is >> real >> symbol >> imaginary;
   if(symbol != '+' && symbol != '-')
   {
      cout << "Error: Incorrect format. Format should be \"a + bi\"\n";
      cout << "or \"a - bi\" where a and b are real numbers.\n";
      exit(1);
   }
   if(symbol == '-')
        imaginary *= -1;
   return is;   
}

ostream& operator <<(ostream& outs, const Complex& number)
{
   return (number.print(outs));
}

istream& operator >>(istream& ins, Complex& number)
// uses stdlib.h
{
   return (number.read(ins));
}
// driver.C
// Name: John Hillert
// Date: 11/29/2000
// Purpose: this is a test program for the class Complex
// It uses the header file Complex.h and the implementation
// file Complex.C
/////////////////////////////////////////////////////////////
#include <iostream.h>
#include "Complex.h"

int main()
{
   cout << "\n\nThis is a test program for the class Complex."
        << "\nFirst we initialize three numbers using the"
        << "\nconstructors, and display them using the"
        << "\noverloaded << operator.\n\n";

   Complex number1(3.44, 4.1);
   Complex number2(9);
   Complex number3;
   Complex number4;
   Complex comparenumber(3.44, 4.1);

   cout << "number 1: " << number1 << endl 
        << "number 2: " << number2 << endl 
        << "number 3: " << number3;
   cout << endl << endl;
   
   cout << "To test the >> operator enter an imaginary number in"
        << " the form \"A + Bi\": ";
   
   cin >> number3;
   cout << endl << number3 << endl;
   
   cout << "\nNow we test the addition operators by adding number 1\n"
        << "and number 2: ";
 
   number4 = number1 + number2;
   cout << number4 << endl;
   
   cout << "\nNow we test the addition operators.  The two added\n"
        << "from the previous example multiplied by number 1 is: ";
  
   number4 = number1 * number4;
   cout << number4 << endl;

   cout << "\nNext is the == operator. We'll see if the last number and\n"
        << "number 1 are equal.  If they are equal the next line will\n"
        << "return true, otherwise it will be false.\n";

   if(number1 == number4)
      cout << "true" << endl << endl;
   else
      cout << "false" << endl << endl;

   cout << "\nWe'll also compare number1 to a \"comparenumber\"\n"
        << "which is equal to number1. Here is the value.\n";

   if(number1 == comparenumber)
      cout << "true" << endl << endl;
   else 
      cout << "false" << endl << endl;

   cout << "Finally, we test the subtraction operator.  We'll subtract\n"
        << "number 1 from number 3:" << endl;
  
   number4 = number3 - number1;
   cout << number4 << endl << endl;

   return 0;
}
