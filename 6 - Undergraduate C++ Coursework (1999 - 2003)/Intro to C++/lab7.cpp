Received: from larkspur.Mines.EDU (larkspur.Mines.EDU [138.67.2.4])
	by slate.Mines.EDU (AIX4.3/8.9.3/8.9.1) with ESMTP id RAA93316
	for <jhillert@mines.edu>; Tue, 17 Oct 2000 17:49:01 -0600
Received: (from rspinhir@localhost)
	by larkspur.Mines.EDU (8.9.1/8.9.1) id RAA3134655
	for jhillert; Tue, 17 Oct 2000 17:48:58 -0600 (MDT)
Date: Tue, 17 Oct 2000 17:48:58 -0600 (MDT)
From: Spinhirne <rspinhir@larkspur.Mines.EDU>
Message-Id: <200010172348.RAA3134655@larkspur.Mines.EDU>
To: jhillert@larkspur.Mines.EDU
Subject: cs261f lab7
X-UIDL: 2S`!!jVR!!^dn!!IV?"!

Grade Report for Lab 6


           Header and comments    _____2____ 2 pts

           Complete loop to read and accumulate sums

                                  _____3____ 3 pts

           Completed function to calculate slope and 
              intercepts 
                                  _____3____ 3 pts

           Correct line output   y= 3.33658x + 700.828
                                  
                                   ____2____  2 pts

           Total                     __10_____ 10 pts
                     
Script started on Tue Oct 10 12:41:27 2000
$ cat shell7.cpp
// Shell for the application program  Regression Line.
// Name: John Hillert
// Date: 9/6/00
// Purpose: Find the equation of the least squares line for a set of n
// data points (x,y).  Slope is its slope, and YIntercept it its y intercept. 
// SumX, SumY, SumX2, and SumXY are the sums of the x's, the y's, the squares
// of the x's, and the products x*y. XMean and YMean are the means of the x's
// and the y's.
////////////////////////////////////////////////////////////////////////////////
// 
// 
//
// Algorithm:
// 1. int n = 0, and declare doubles x and y
// 2. double SumX, SumY, SumX2, SumXY, all to 0
// 3. cin value x
// 4. start a while loop: until cin >> y
//    5. n++
//    6. SumX = x + SumX
//    7. SumX2 = SumX2 + x*x
//    8. SumY=y+SumY
//    9. SumXY = SumXY + x*y
//    10. cin x  
//    11. end while 
// 12. if n>0 call CalculateSlopeIntercept:
//     cout << "y = " << slope << "x + " << YIntercept
// 13. else cout "No data points were read"
//
// Function CalculateSlopeIntercept Algorithm:
// 1. XMean + SumX/n and YMean = SumY/n
// 2. Slope = (SumXY - SumX*YMean)/(SumX2 - SumX*XMean)
// 3. YIntercept = YMean-Slope * XMean
// 4 return Slope and YIntercept (IN other words use & in prototype)
  
#include<iostream.h>  
 
void computeSlopeIntercept( double SumX, double SumY, double SumX2, double SumXY,
                           int n, double& Slope, double& YIntercept );
// Precondition: input SumX, SumY, SumX2, SumXY, n
// Postcondition: returns slope of least squares line,
// and YIntercept of least squares line



main()
{   
    int n = 0;
    double x, y,
           SumX = 0.0,
           SumY = 0.0,
           SumX2 = 0.0,
           SumXY = 0.0,
           Slope, YIntercept;

    cout << "Enter x, y for data point ( or CTRL d to quit ):\n";
    cin >> x;
    cin >> y;
 
    while(!cin.eof())
    {
        n++; 
        SumX = x + SumX;
        SumX2 = SumX2 + x * x;
        SumY = y + SumY;
        SumXY = SumXY + x * y; 
        cout << "\nEnter next data point x, y:\n";
        cin >> x;  
        cin >> y;
    }
 
    if ( n > 0 )   
    {
         computeSlopeIntercept(SumX, SumY, SumX2, SumXY, n, Slope, YIntercept);
         cout << "Regression line: " << "y = " << Slope << "x + " << YIntercept;
         cout << endl;
    }
    else
       cout << " No data points to process " << endl;

}
    
    

void computeSlopeIntercept(double SumX, double SumY, double SumX2, double SumXY, 
			  int n, double& Slope, double& YIntercept)
{
    double XMean, YMean;
    XMean = SumX / n;
    YMean = SumY / n;
    Slope = (SumXY - SumX * YMean) / (SumX2 - SumX * XMean);
    YIntercept =  YMean - Slope * XMean; 
} 


$ CC shell7.cpp
$ a.out
Enter x, y for data point ( or CTRL d to quit ):
20
761

Enter next data point x, y:
31.5
817

Enter next data point x, y:
50
874

Enter next data point x, y:
71.8
917

Enter next data point x, y:
91.3
1018

Enter next data point x, y:
^DRegression line: y = 3.33658x + 700.828
$ ^D
script done on Tue Oct 10 12:42:36 2000
