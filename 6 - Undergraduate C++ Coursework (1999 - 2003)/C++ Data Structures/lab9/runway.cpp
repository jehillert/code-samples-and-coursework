// Program: runway.cpp
// Programmer: John Hillert
// Last Updated: 10/21/02
// Purpose: This program simulates an airport with 1 runway.
//          Arriving and departing planes must share this       
//          runway with landing planes getting priortity
//          due to the dangers of a limited fuel supply.
// Input:
// 1. The amount of time needed for one plane to land
// 2. The amount fo tim needed for one plane to take off
// 3. The average amount of time between arrival of planes 
//    to the landing queue.
// 4. The average amount of time between arrival of planes to the 
//    takeoff queue
// 5. The maxium amount of time that a plane can stay in the landing
//    queue without running out of fuel and crashing 
// 6. The total length of time to be simulated 
//
// Output:
// 1. The number of planes that took off in the simulated time
// 2. The number of planes that landed in the simulated time
// 3. The number of planes that crashed because they ran out of fuel 
//    before they could land
// 4. The average time that a plane spent in te takeoff queue.
// 5. The average time that a plane spent in the landing queue.
// 6. The number of planes left in the landing queue
// 7. The number of planes left in the takeoff queue 
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
//
// NOTE: I have reused Savitch's class from the chapter. Dr. Rader
// said this would be okay.
//
// FEEDBACK ON THE SIMULATIONS:
//
// 1. If the probability of a takeoff is very high, this has little effect
//    on crashes unless the simulation has takeoffs that take as long as a 
//    plane has fuel.
// 2. If the probability of planes landing is high then there 
//    will be crashes, even if takeoff and landing times are small.
// 3. If both takeoff and land probabilities are low, and fuel time
//    is similar to takeoff and landing times, then the chances of a 
//    crash are low.
// 4. If the takeoff times or landing times are larger than the fuel times
//    (implying an inefficient airport) then the chances becomes significant
// 5. If landing probabilities are high then the wait for planes taking off
//    becomes significant.
// LAST REMARK: If any of these things listed above happens the airport 
// will need a new runway.  However, exact numbers are impossible.  There
// are 6 different variables and no numerical conclusions can be obtained
// with this type of simulation unless most of them are held constant. 
//
////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#include <cstdlib>
#include <iostream>
#include <queue>
#include "S_runway.h" 

using namespace std;
using namespace Savitch_revised8;

void simulation(double l_prob, double t_prob, int landing_time, 
                int takeoff_time, int crash_time, unsigned int total_time);
// Precondition: all probabilities between 0 and 1
// Postcondition: The function has simulated an airport with a single runway,
// planes that could crash if they run out of fuel before landing, and planes
// that take off.  These planes take their turns in their respective queues,
// randomly adding themselves to their queues. It should be noted that landing
// planes have priority over takeoff planes.
// It prints the output listed in the header of this file.

void event(int up0_down1, unsigned int current_second);
// Postcondition: prints out whether a plane landed
// or took off, but not that one crashed

void output(const averager t_avg_times, const averager l_avg_times, 
            const int crashes, const queue<unsigned int> t_arrivals, 
            const queue<unsigned int> l_arrivals); 
// This function is mostly practice for passing classes and templates
// into functions in a way that they can't be changed.
// Precondition: A simulation has completed successfully
// Postcondition: All data listed in the header under Output is
// printed to the screen.

int main()
{
   double l_prob, t_prob;
   int landing_time, takeoff_time;
   int crash_time;
   unsigned int total_time;
   char answer = 'y';

   while(answer == 'y' || answer == 'Y')
   {
      //GET INPUT FROM USER
      cout << "\n\nRunway Simulator\n\n";

      cout << "Enter probability for a new takeoff plane: ";
      cin >> t_prob;

      cout << "Enter probability for a new landing plane: ";
      cin >> l_prob;

      cout << "Enter amount of time needed for plane to take off: ";
      cin >> takeoff_time;

      cout << "Enter amount of time needed for plane to land: ";
      cin >> landing_time;

      cout << "Enter time plane can spend in air before loosing fuel: ";
      cin >> crash_time;

      cout << "Enter total timesteps of simulation (How long will it run?): ";
      cin >> total_time;
       
      // CALL THE SIMULATION FUNCTION
      simulation(l_prob, t_prob, landing_time, takeoff_time, crash_time, 
                 total_time);
      
      
      cout << "\n\nWould you like to run another simulation "
           << "('y' for yes, 'n' for no)?   ";
      cin >> answer;
   }

   return EXIT_SUCCESS;

}


void simulation(double l_prob, double t_prob, int landing_time, 
                int takeoff_time, int crash_time, unsigned int total_time)
{
   queue<unsigned int> l_arrivals, t_arrivals;
   bool_source new_lander(l_prob), new_takeoff(t_prob);
   averager l_avg_times, t_avg_times;
   runway landing(landing_time), takeoff(takeoff_time);
   unsigned int current_second; 
   unsigned int next;
   unsigned int wait;
   unsigned int how_late;
   int crashes = 0;
   int up0_down1 = 3; 

   //START SIMULATING
   for(current_second = 1; current_second <= total_time; ++current_second)
   {   
      // ARE THERE NEW LANDINGS AND TAKEOFFS? 
      if(new_lander.query())
         l_arrivals.push(current_second);
      if(new_takeoff.query())
         t_arrivals.push(current_second);

      // IS ANYBODY LANDING OR TAKING OFF?
      if(! landing.is_busy() && ! takeoff.is_busy())
      {
         event(up0_down1, current_second);
 
         // LAND ANY PLANES IN THE AIR FIRST     
         if(!l_arrivals.empty())  
         { 
            // HOW LONG HAS PLANE BEEN IN THE AIR
            next = l_arrivals.front();
            wait = current_second - next;
            
            // WHILE THE CURRENT PLANE IS CRASHED
            while(wait >= crash_time && !l_arrivals.empty())
            {
               crashes++;
               l_arrivals.pop();
               
               how_late = wait - crash_time;
               cout << "\nPlane crashed " << how_late << " times steps ago."; 

               next = l_arrivals.front();
               wait = current_second - next;
            }

            // CHECK AGAIN TO SEE IF THERE IS A PLANE TO LAND
            if(! l_arrivals.empty())
            {
               l_arrivals.pop();
               l_avg_times.next_number(wait);
               landing.start_going(); 
               up0_down1 = 1; // A PLANE IS NOW LANDING  
            }
            else
            {
               up0_down1 = 3;
            }
         }
       
         else if(! t_arrivals.empty())
         {
            next = t_arrivals.front();
            wait = current_second - next;
            t_arrivals.pop();
            t_avg_times.next_number(wait); 
            takeoff.start_going();
            up0_down1 = 0;
         }
         
         else  
         {
            up0_down1 = 3;
         }
      }       
      
      // INCREMENT TIME FOR THE APPROPRIATE USAGE OF THE RUNWAY
      if(up0_down1 == 1) 
         landing.one_second();
      if(up0_down1 == 0) 
         takeoff.one_second();
   }
    
   event(up0_down1, current_second-1);

   // PRINT OUTPUT  
   output(t_avg_times, l_avg_times, crashes, t_arrivals, l_arrivals);

}
 
void event(int up0_down1, unsigned int current_second)
{

   // IS THERE A PREVIOUS FLIGHT AND WAS IT A TAKEOFF OR LANDING?  
   // IF THERE WAS THEN ANNOUNCE IT.
   if(up0_down1 == 0)
   {
       cout << "\nPlane departed at time " << current_second;
   }

   else if(up0_down1 == 1)
   {
      cout << "\nPlane landed at time " << current_second; 
   }
         
   else
   { 
   // DO NOTHING BECAUSE THIS NOBODY USED IT LAST TIME} 
   }
}

void output(const averager t_avg_times, const averager l_avg_times, 
            const int crashes, const queue<unsigned int> t_arrivals, 
            const queue<unsigned int> l_arrivals) 
{
   cout << "\n\nSIMULATION RESULTS\n";
   cout << "\nThe number of takeoffs:     " << t_avg_times.how_many_numbers();
   cout << "\nThe number of landings:     " << l_avg_times.how_many_numbers();
   cout << "\nThe number of crashes:      " << crashes;
   cout << "\nThe average takeo