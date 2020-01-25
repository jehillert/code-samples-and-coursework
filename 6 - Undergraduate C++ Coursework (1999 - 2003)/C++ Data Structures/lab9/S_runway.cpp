// FILE: S_runway.cxx
// NOTE: This is borrowed from Savitch with only a few modifications
// LAST MODIFIED: 10/21/02
// CLASSES implemented: bool_source, averager, runway
//
// INVARIANT for the bool_source ADT:
//   1. The member variable probability is the appoximate probability that
//      query( ) returns true.
//
// INVARIANT for the averager ADT:
//   1. The member variable count indicates how many numbers the averager has
//      been given.
//   2. The member variable sum is the sum of all the numbers that the
//      averager has been given.
//
// INVARIANT for the runway class:
//   1. The member variable seconds_for_runway is the number of seconds required
//      for one runway.
//   2. The member varible runway_time_left is 0 if the runway is not busy;
//      otherwise it is the number of seconds until the runway is free.

#include <cassert>    // Provides assert
#include <cstdlib>    // Provides rand, RAND_MAX, size_t
#include "S_runway.h"  // Provides bool_source, averager, runway definitions
using namespace std;

namespace Savitch_revised8 
{
    bool_source::bool_source(double p)
    // Library facilities used: cassert
    {
        assert(p >= 0);
        assert(p <= 1);
        probability = p;
    }

    bool bool_source::query( ) const
    // Library facilities used: cstdlib
    {
        return (rand( ) < probability * RAND_MAX);
    }

    averager::averager( )
    {
        count = 0;
        sum = 0;
    }

    void averager::next_number(double value)
    {
        ++count;
        sum += value;
    }
    
    double averager::average( ) const
    // Library facilities used: cassert
    {
        return sum/count;
    }
    
    runway::runway(unsigned int s)
    {
        seconds_for_runway = s;
        runway_time_left = 0;
    }


    void runway::one_second( )
    {
        if (is_busy( ))
            --runway_time_left;
    }

    
    void runway::start_going( )
    // Library facilities used: cassert
    {
       