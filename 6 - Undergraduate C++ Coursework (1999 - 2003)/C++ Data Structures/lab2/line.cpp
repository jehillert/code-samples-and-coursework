// FILE: line.cpp
// CLASS IMPLEMENTED line.cpp (seed line.h for documentation)

#include <iostream>
#include "point.h"
#include "line.h"

using namespace std;

namespace linelab
{
   line::line()
   {
      point initial_start(0,0);
      point initial_end(1,1);

      start = initial_start;
      end = initial_end;
   }

   line::line(point p1, point p2)
   {
      start = p1;
      end = p2;
   }

   line::line(const line& source)
   {
      cout << "In copy constructor.\n";
      
      start = source.get_start();
      end = source.get_end();
   }

   double line::slope()
   {
      return (end.get_y() - start.get_y())/(end.get_x() - start.get_x());
   }

   bool operator ==(line line1, line line2)
   {
      return
         (line1.get_start() == line2.get_start())
         &&
         (line1.get_end() == line2.get_end());
   }

   line shift_vertical(const line& line1, int shift)
   {
      point p1(line1.get_start().get_x(), line1.get_start().get_y() + shift);
      point p2(line1.get_end().get_x(), line1.get_end().get_y() + shift);
   
      cout << "\n\nThe copy constructor is called in shift_vertical"
           << "\nbecause shift_verticle returns an object, which in turn"  
           << "\nis a call to the copy constructor.\n";
      line line2(p1, p2);
      return line2;
      // return line(p1,p2) gives no copy constructor
   } 

   ostream& operator <<(ostream& outs, const line& source)
   {
      outs << source.get_start() << " " 
           << source.get_end(); 
      return outs;
   }
   
   istream& operator >>(istream& ins, line& target)
   { 
      point point1, point2;
      ins >> point1;
      ins >> point2;
  