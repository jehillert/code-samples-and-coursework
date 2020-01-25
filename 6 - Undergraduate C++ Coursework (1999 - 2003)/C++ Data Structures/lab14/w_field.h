// FILE: w_field.h
// CLASS PROVIDED: w_field
// PROGRAMMMER: John Hillert
// DATE: 11/29/02
//
//
// VALUE SEMANTICS for the semantics class:
//      assignments and the copy constructor may be used with
//      w_field objects.

#ifndef JHILLERT
#define JHILLERT

namespace assignment14
{
    class w_field
    {
    public:
        // PUBLIC VARIABLES
        int key; 
        // CONSTRUCTOR
        w_field();
        w_field(int ikey, char iname[], int igallons, double ifee);
        // COPY CONSTRUCTOR
        w_field(const w_field& source);
        // DESTRUCTOR
        ~w_field() {delete [] name;}
        //MODIFICATION MEMBER FUNCTIONS
        void operator =(const w_field& source);
        //FRIEND FUNCTION
        friend ostream& operator <<(ostream& outs, const w_field& source);
    private:
        char *name;
        int gallons;
   