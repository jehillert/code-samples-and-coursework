Received: from larkspur.Mines.EDU (larkspur.Mines.EDU [138.67.2.4])
	by slate.Mines.EDU (AIX4.3/8.9.3/8.9.1) with ESMTP id TAA85484
	for <jhillert@mines.edu>; Wed, 4 Oct 2000 19:56:36 -0600
Received: (from rspinhir@localhost)
	by larkspur.Mines.EDU (8.9.1/8.9.1) id TAA2634410
	for jhillert; Wed, 4 Oct 2000 19:56:33 -0600 (MDT)
Date: Wed, 4 Oct 2000 19:56:33 -0600 (MDT)
From: Spinhirne <rspinhir@larkspur.Mines.EDU>
Message-Id: <200010050156.TAA2634410@larkspur.Mines.EDU>
To: jhillert@larkspur.Mines.EDU
Subject: CS261F HW3
X-UIDL: I(4!!-iV"!1Hn!!>Z""!

Grade Report for Assignment3

        PartI:
          Correct answers to questions   ___10_____  10 pts

        PartII:
          Program1:  Ch 7 prob 9     ___15_____ 15 pts
              header  2
              comments 3
              good solution 10
              
                                         
          Program2:  Ch 3 prob 3       ___15_____ 15 pts   
              header  2 
              comments 3
              correct solution 10
              #4   + 0



          Total                          __40______ 40 pts
1. Identify and correct the errors in each of the following:
    a. if (age >= oldage)
       {
           cout << "Age is greater than or equal to " << oldage << endl;
       }
       else
       { 
            cout << "Age is less than " << oldage << endl;
       } 
    b. if (age >= oldage)
       {
           cout << "Age is greater than or equal to " << oldage << endl;
       }
       else 
       {   
           cout << "Age is less than " << oldage;
       }    
    a. if statement doesn't need semicolon.  The quote doesn't need to be split
       up.  Any reference to 65 was changed to a variable to fight magic
       constants.  There was  a spelling error in the last quote. line spacings
       were all screwed up and brackets were needed around if blocks and else
       blocks
    b. Any reference to 65 was changed to a variable to fight magic constants.
       There was no semicolon after last line.  There was a semicolon after
       else.  There were no brackets around if else blocks

2.  a.
    if (y == 8)
    {
        if (x == 5)
        {
            cout << "@@@@@" << endl;
        }
    }
    else
    {
        cout << "#####" << endl;
    }
    cout << "$$$$$" << endl;
    cout << "&&&&&" << endl;

    b.
    if (y == 8)
    {  
        if (x == 5)
        {
            cout << "@@@@@" << endl;
        }
    }
    else
    {
        cout << "#####" << endl;
        cout << "$$$$$" << endl;
        cout << "&&&&&" << endl;   
    }

    c.
    if (y == 8)
    {
        if (x ==5)
        {
            cout << "@@@@@" << endl;
        }
    }
    else
    {
        cout << "#####" << endl;
        cout << "$$$$$" << endl;
    }
    cout << "&&&&&" << endl;

    d.
    if ( y == 8)
    {
        if (x == 5)
        {
            cout << "@@@@@" << endl;
        }
    }
    else
    {
        cout << "#####" << endl;
        cout << "$$$$$" << endl;
        cout << "&&&&&" << endl;
    }
1. Identify and correct the errors in each of the following:
    a. if (age >= oldage)
       {
           cout << "Age is greater than or equal to " << oldage << endl;
       }
       else
       { 
            cout << "Age is less than " << oldage << endl;
       } 
    b. if (age >= oldage)
       {
           cout << "Age is greater than or equal to " << oldage << endl;
       }
       else 
       {   
           cout << "Age is less than " << oldage;
       }    
    a. if statement doesn't need semicolon.  The quote doesn't need to be split
       up.  Any reference to 65 was changed to a variable to fight magic
       constants.  There was  a spelling error in the last quote. line spacings
       were all screwed up and brackets were needed around if blocks and else
       blocks
    b. Any reference to 65 was changed to a variable to fight magic constants.
       There was no semicolon after last line.  There was a semicolon after
       else.  There were no brackets around if else blocks

2.  a.
    if (y == 8)
    {
        if (x == 5)
        {
            cout << "@@@@@" << endl;
        }
    }
    else
    {
        cout << "#####" << endl;
    }
    cout << "$$$$$" << endl;
    cout << "&&&&&" << endl;

    b.
    if (y == 8)
    {  
        if (x == 5)
        {
            cout << "@@@@@" << endl;
        }
    }
    else
    {
        cout << "#####" << endl;
        cout << "$$$$$" << endl;
        cout << "&&&&&" << endl;   
    }

    c.
    if (y == 8)
    {
        if (x ==5)
        {
            cout << "@@@@@" << endl;
        }
    }
    else
    {
        cout << "#####" << endl;
        cout << "$$$$$" << endl;
    }
    cout << "&&&&&" << endl;

    d.
    if ( y == 8)
    {
        if (x == 5)
        {
            cout << "@@@@@" << endl;
        }
    }
    else
    {
        cout << "#####" << endl;
        cout << "$$$$$" << endl;
        cout << "&&&&&" << endl;
    }
Script started on Wed Sep 27 00:41:55 2000
$ cat s factorial.cpp
// Name: John Hillert                       //
// Date: 9/26/00                            //
// Program: approximates e^x function       //
// up to 100 values in its defining series. //
// the user gives a value of x.             //
//////////////////////////////////////////////
// 
//
//           Algorithm:
// 1. need to make e^x function
// 1a. include prototype for factorial function
// 1b. put rest of this user terminated loop
//     so user can get multiple values of e^x
// 2. have user give you value of x
// 3. e^x has a sequence that approximates
//    it's value the more terms you sum up
// 4. use sum 1 + x + x^2/2! + x^3/3! + . . . x^n/n!
// 5. since it's a sum use a while loop 
// 6. let the counter go to 100 in that loop
// 7. define the bottom of the fraction with 
// 8. the factorial function.  But put an 
//    incrementer on the factorial variable, 
//    and on the exponent of x
// 9. output the final value
// 10. also output value of math.h's e^x value
//     using the users x values 
// 10a. end bracket for main loop here
// 11. include body of factorial function
//
//           Pseudocode:
// 1. include math and iostream
// 1a. int factorial(int n)
// 2. int main 
// 2a. "input value of x to obtain value of e^x"
// 2b. while (cin >> x) 
// 3. define x, sum, sumcomp, counter = 0
// 4. "input value of x to obtain value of e^x"
// 5. while (counter <= 100)
// 6. sum = x^counter/counter! + sum
// 7. end loop
// 8. put value of x in math.h's e^x
// 9. sumcomp = math.h's e^x
// 10. Output "programmer's value of e^x is:" << sum
// 11. output "math.h's value of e^x is:" << sumcomp
// 11a. "input value of x to obtain value of e^x"
// 11b. end main loop
// 12. int factorial(int n)
//     rest of function on page 149
 
#include<iostream.h>
#include<math.h>

double factorial(double number);
// precondition: this function takes a value
// and does the factorial operation on it
// postcondition: the new factorial values
// is returned to where it was used

int main()
{ 
    double x, sum = 1, computersum, counter;
    counter = 1; // setting counter 
    cout << "Input value of x to obtain value e^x: ";

    while (cin >> x) 
    {

        //THIS IS THE LOOP FOR THE PROGRAMMER DERIVED e VALUE
        while (counter <= 100)
        {
            sum = sum + pow(x, counter) / factorial(counter); 
            counter++;
        }
        computersum = exp(x); // COMPUTER DERIVED e VALUE
        cout << "Programmer's value of e^" << x << " is: " << sum << endl;
        cout << "Math.h's value is e^" << x << " is: " << computersum << endl;
      
        counter = 1; // resetting counter for next time around 
        sum = 1; // resetting sum for next time around 
        cout << "Input value if x to obtain value e^x: "; 
    }
    cout << endl;
    return 0;
} 

double factorial(double number)
{
    double product = 1;
    while (number > 0)
    {
        product = number * product;
        number--;
    }
    return product;
    
}
$ CC factorialx .cpp -lm
$ a.out
Input value of x to obtain value e^x: 4
Programmer's value of e^4 is: 54.5982
Math.h's value is e^4 is: 54.5982
Input value if x to obtain value e^x: 5
Programmer's value of e^5 is: 148.413
Math.h's value is e^5 is: 148.413
Input value if x to obtain value e^x: 6
Programmer's value of e^6 is: 403.429
Math.h's value is e^6 is: 403.429
Input value if x to obtain value e^x: 7
Programmer's value of e^7 is: 1096.63
Math.h's value is e^7 is: 1096.63
Input value if x to obtain value e^x: 1
Programmer's value of e^1 is: 2.71828
Math.h's value is e^1 is: 2.71828
Input value if x to obtain value e^x: 2
Programmer's value of e^2 is: 7.38906
Math.h's value is e^2 is: 7.38906
Input value if x to obtain value e^x: ^D
$ ^D
script done on Wed Sep 27 00:42:36 2000
Script started on Wed Sep 27 02:10:51 2000
$ cat inflation.cpp
// Name: John Hillert		       //
// Date: 9/27/00		       //
//                         	       //
// Program: This program determines    //
// the inflation on a product a year   //
// old.                                //
/////////////////////////////////////////
//
//
//
//            Algorithm:
// 1. set loop that can be 
//    terminated by ctrl^D
// 2. ask for price of itom
//    - the price a year ago
//    - the price now
// 3. send this info to a function
// 4. end loop
// 5. fill info for loop
//    according to:
//    Inflation = (price now - price a year ago)/(price a year ago)
//                * 100%
//
//
//
//            Pseudocode:
// 1. include iostream
// 2. define double inflation()
// 3. start main ()
// 4. set precision to 1 decimal for percentages
// 5. start loop --> while (cin)
// 6. "Enter price of an Audi TT Roadster one year ago: $"
// 7. cin old price and endl
// 8. "Enter price of an Audi TT Roadster now: $" 
// 9. cin new price and endl
// 10. send newprice and oldprice to inflation()
// 11. close loop
// 12. return 0 then define inflation()
// 13. Infl = ((newprice - oldprice) / oldprice) * 100 
// 14. return Infl

#include<iostream.h>

double inflation(double oldprice, double newprice);

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    double oldprice, newprice, percentInflation;

    while (cin) 
    {    
        cout << "Enter price of a product one year ago: $";
        cin >> oldprice;
        cout << "\nEnter current price of product: $";
        cin >> newprice;
        percentInflation = inflation(oldprice, newprice);
        cout << "\nThe price of this product has inflated by "
             << percentInflation << "%" << endl;
    }

    return 0;
}

double inflation(double oldprice, double newprice)
{
    double infl;
    infl = ((newprice - oldprice) / (oldprice)) * 100;
    return infl;
}

         
$ CC inflations .cpp
$ a.out
Enter price of a product one year ago: $10

Enter current price of product: $20

The price of this product has inflated by 100.0%
Enter price of a product one year ago: $21

Enter current price of product: $22

The price of this product has inflated by 4.8%
Enter price of a product one year ago: $9

Enter current price of product: $10

The price of this product has inflated by 11.1%
Enter price of a product one year ago: $10

Enter current price of product: $11

The price of this product has inflated by 10.0%
Enter price of a product one year ago: $^D
Enter current price of product: $
The price of this product has inflated by 10.0%
$ a.out
Enter price of a product one year ago: $50

Enter current price of product: $25

The price of this product has inflated by -50.0%
Enter price of a product one year ago: $^D
Enter current price of product: $
The price of this product has inflated by -50.0%
$ ^D

script done on Wed Sep 27 02:12:13 2000

script done on Wed Sep 27 02:12:13 2000
