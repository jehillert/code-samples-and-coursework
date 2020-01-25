// FILE: line.h
// CLASS PROVIDED: line (a class that manipulates lines in 3D space) 
//
// CONSTRUCTOR for the line class
//   line()
//     Postcondition: A line has been created with points (0,0) to (0,1)
//
//   line(point p1, point p2);
//     Postcondition: A line has been created with points p1(a,b) and p2(c,d)
// 
//   line(const line& source)
//     Precondition: An initialized line has been given as a parameter
//     Postcondition: A new line is created with the point values of the 
//     fed parameter
//
// CONSTANT MEMBER FUNCTIONS 
//   point get_start() const
//      Postcondition: The coordinates of the starting point 
//      of the line is returned
// 
//   point get_end() const 
//      Postcondition: The coordinates of the ending point of 
//      the line is returned
//
// OTHER MEMBER FUNCTIONS 
//   double slope()
//      Postcondition: The slope of the line is returned
//      
// FRIEND FUNCTIONS 
//    friend bool operator ==(line line1, line line2);
//      Postcondition: Returns true if points in line1 equal points in
//      line two, else returns false.
//
// NONMEMBER FUNCTIONS
//   line shift_vertical(const line& line1, int shift=1);
//      Postcondition: A line is returned with the same x coordinates 
//      of line1 but with y coordinates shifted by the value of shift 
//
//   ostream& operator <<(std::ostream& out, const line& source);
//      Postcondition: The x and y coordinates of both endpoints of the
//      line have been written to outs
//
//   istream& operator >>(std::istream& in, line& target);
//      Postcondition: The x and y coordinates of two endpoints of a line
//      have been written to a line called target 
//
// VALUE SEMANTICS for the line class
//    Assignments and the copy constructor may be used with line objects

#ifndef HILLERT_LAB2
#define HILLERT_LAB2
#include <iostream> 
#include "point.h"

namespace linelab
{
   class line
   {
   public:
      // CONSTRUCTORS
      line(); 
      line(linelab::point p1, linelab::point p2); 
      line(const line& source);
      // CONSTANT MEMBER FUNCTIONS
      linelab::point get_start() const {return start;}
      linelab::point get_end() const {return end;}
      //OTHER MEMBER FUNCTIONS
      double slope();
      // FRIEND FUNCTIONS 
      friend bool operator ==(line line1, line line2);
  
   private: 
      point start, end;
   };
   // NONMEMBER FUNCTIONS
   line shift_vertical(const line& line1, int shift = 1); 
   std::ostream& operator <<(std::ostream& out, const line& sour