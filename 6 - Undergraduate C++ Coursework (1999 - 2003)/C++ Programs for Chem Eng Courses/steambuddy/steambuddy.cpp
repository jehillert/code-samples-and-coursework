
// Steambuddy
// Programmer: John Hillert
// Class: CHEN 201 Material and Energy Balances
// Purpose: This program provides a user with computerized
// steam table information.  The user chooses the desired
// calculation, provides the necessary thermodynamic information,
// and gets an answer if the input is within specified parameters.
//////////////////////////////////////////////////////////////////

#include<iostream.h>
#include<stdlib.h>
#include<fstream.h>
#include<string>
#include<ctype.h>


typedef double** doublepointer;

const int column_size = 6;

int DataStart(ifstream&);
// Precondition: requires input stream connected to file
// Postcondition; returns the number of terms that have to
// be discarded before steam values begin in file

int ArraySize(ifstream&, int line_counter);
// Precondition: requires input stream connected to file and # of lines that
// need to be skipped before coming to double values
// Postcondition: returns number of rows

void FillArray(ifstream&, doublepointer&, int line_counter, int array_size, int columnsize, int rows);
// Precondition: takes input file stream, amount of lines that need to be skipped,
// size of array, and column number
// Postcondition: returns an array

double MinSearch(const doublepointer&, int column, int rows);
// Precondition: takes array and column number of desired variable
// Postcondition: returns minimum value of that variable from steam table

double MaxSearch(const doublepointer&, int colmn, int rows);
// Precondition: takes array and column number of desired variable
// Postcondition: returns minimum value of that variable from steam table

void Region(const doublepointer&, int rows, double Tmin, double Tmax, double Pmin, double Pmax);
// Precondition: takes array and all T & P min/max variables
// Postcondition: displays region that T & P data falls under
// Description: this function asks the user to provide T & P data
// then checks for validity of data, and finally gives provides
// the region or an error message

void Psat(const doublepointer&, int rows, double Pmin, double Pmax);
// Precondition: takes array, Pmin, and Pmax values
// Postconditions: displays either temp, sat vl, sat vvap, sat hliq, and sat hvap
// or provides an error
// Description: this function asks user for a pressure saturation value, checks
// to see if it's within the scope of the table, then returns all the saturation
// values for that pressure

void Tsat(const doublepointer &, int rows, double Tmin, double Tmax);
// Description: this function does the same thing as "Psat" except the roles of
// T & P are reversed

void Px(const doublepointer &, int rows, double Pmin, double Pmax);
// Precondition: takes array, Pmin, and Pmax
// Postcondition: returns temp, specific volume, and enthalpy at Psat
// Description: asks user for Px info

void Tx(const doublepointer&, int rows, double Tmin, double Tmax);
// Precondition: takes array, Tmin, and Tmax
// Postcondition: returns pressure, specific volume, and enthalpy at Tsat
// Description: asks user for Tx info

void Ph(const doublepointer&, int rows, double Pmin, double Pmax);
// Precondition: takes array, and min/max values for P & h
// Postcondition: returns temp and quality
// Description: asks user for Ph info

void Th(const doublepointer&, int rows, double Tmin, double Tmax);
// Precondition: takes array, and min/max values for T & h
// Postcondition: returns pressure and quality
// Description: askes user for Th info

void hx(const doublepointer&, int rows);
// Precondition: takes array, hmin, and hmax
// Postcondition: returns temperature and pressure

int SearchHigh(const doublepointer&, int rows, double Var, int column);
// Precondition: takes array, steam table variable, and column # of variable.
// variable has to be within limits of steam table
// Postcondition: returns row of next highest steam table value

int SearchLow(const doublepointer&, int rows, double Var, int column);
// Precondition: takes array, steam table variable, and column # of variable
// Postcondition: returns row of next lowest steam table value

double interpolate(double y2, double y1, double x2, double x1, double x);
// Precondition: takes steam table values and variable value needed for interpolation
// Postcondition: returns y value, or an interpolation of the value you desired

double extrapolate(double x, double yf, double yg);
// Precondition: takes qualtiy and both sat values of a variable such as enthalpy
// or specific volume
// Postcondition: returns average value of that value

double quality(double yf, double yg, double yav);
// Precondition: takes both sat values of a variable, and the variables
// average value
// Postcondition: returns quality


int main()
{
	int column1 = 0,
		column2 = 1,
		column3 = 2,
		column4 = 3,
		column5 = 4,
		column6 = 5;
	int WrongChoice; // this is to make sure the selection loop iterates if a wrong choice is made
	int array_size;
	int	line_counter;
	int	rows;
	int wait; // THIS IS SO THE SCREEN DOESN'T FLY BY
	double Tmin, Tmax, Pmin, Pmax;
	doublepointer Array;
	char filename[21];
	char choice[4];
	char response[5]; // this is to help assign value to "answer"

	bool answer = true, answer1 = true; // these help to end loops

	// here is the introduction to the program
	cout << "                         Steambuddy" << endl;
	cout << "This program is designed to recieve an input file containing\n";
	cout << "thermodynamic data for saturated steam.  After being loaded the user\n";
	cout << "can choose from a menu of desired steam table calculations. After\n";
	cout << "a selection has been made the user will be prompted to provide\n";
	cout << "input neccesary for the calculation.  Either the desired answer or\n";
	cout << "an error message will be returned.  Please note that the input file must\n";
	cout << "be in the same directory as the program.\n";
	cout << "\n\nNote: You may press Ctrl^Break at any time to quit." << endl;

	// WHERE STEAM TABLE FILE IS OPENED

	cout << "\n\nEnter file name (maximum of 20 characters):" << endl;
	cin >> filename;

	ifstream input;
	input.open(filename);
	if(input.fail()) // ERROR IF FILE DOESN'T OPEN
	{
		cout << "ERROR: File failed to open.  File name length\n"
			 << "must be 20 characters or less, and must be in \n"
			 << "current directory." << endl;
		exit(1);
	}

	// WHERE ARRAY IS DECLARED AND FILLED
	line_counter = DataStart(input); // RETURNS # OF LINES BEFORE NUMERICAL DATA STARTS IN THE INPUT FILE
	input.close();

	input.open(filename); // OPEN AGAIN TO READ FROM BEGINNING
	array_size = ArraySize(input, line_counter); // RETURNS # OF double VALUES THAT WILL BE READ INTO ARRAY
	input.close();

	// THIS DETERMINES ROW SIZE AND PARTIALLY CHECKS DEPENDABILITY OF INPUT FILE
	if(array_size%column_size > 0)
	{
		rows = array_size/column_size + 1;
		cout << "\n\nWARNING: All rows in steam table array do not have same number \n"
			 << "of terms. There is high probability that calculations will be \n"
			 << "wrong. This could be due to incompatible file format or programmer \n"
			 << "stupidity.  Proceed with calculations at your own risk, and \n"
			 << "only if you know that last row of input file isn't full.\n";
		cout << "Press return to continue.\n\n\n";
		cin >> wait;
	}
	else
	{
		rows = array_size/column_size; // YOU KNOW NUMBER OF COLUMNS SO DIVIDE THE TOTAL NUMBER
	}								   // BY COLUMN AND YOU GET ROWS

	// DECLARING ARRAY DIMENSIONS FOR DYNAMIC ARRAY
	Array = new double*[rows];
	for(int i = 0; i < rows; i++)
	{
		Array[i] = new double[column_size];
	}

	input.open(filename); // OPEN FILE AGAIN TO READ FROM BEGINNING
	FillArray(input, Array, line_counter, array_size, column_size, rows); // FUNCTION FILLS IN STEAM DATA INTO ARRAY
	input.close(); // CLOSE FILE FOR THE LAST TIME

	// WHERE MINS AND MAXES ARE FOUND WITHIN STEAM TABLE. THESE VALUES WILL
	// HELP PREVENT USER FROM GETTING A NONSENSICAL ANSWER BECAUSE DATA WAS
	// ACCEPTED OUTSIDE THE PARAMETERS

	Tmin = MinSearch(Array, column1, rows);
	Tmax = MaxSearch(Array, column1, rows);
	Pmin = MinSearch(Array, column2, rows);
	Pmax = MaxSearch(Array, column2, rows);

	while(answer == true)
	{
		// HERE IS THE MENU FOR THE CALCULATIONS
		cout << "\n\n\n\n\nMain Menu\n\n\n"
			 << "Desired Calculations                                   Must Provide\n"
			 << "--------------------------------------------------------------------\n\n"
			 << "A. region (saturation, superheated, subcooled)         P, T\n"
			 << "B. temp, sat v-liq, sat v-vap, sat h-liq, sat h-vap    P\n"
			 << "C. pres, sat v-liq, sat v-vap, sat h-liq, sat h-vap    T\n"
			 << "D. temp, specific volume, enthalpy                     P, x\n"
			 << "E. pres, specific volume, enthalpy                     T, x\n"
			 << "F. temp, quality                                       P, h\n"
			 << "G. pres, quality                                       T, h\n"
			 << "H. temp, pres                                          h, x\n";

		WrongChoice = 1;
		// PROGRAM SENDS CHOICE TO A FUNCTION SUITED TO THAT TYPE OF CALCULATION
		while(WrongChoice == 1)
		{
			// PROGRAM PROMPTS FOR A MENU SELECTION
			cout << "\n\nEnter letter choice and press return:  ";
			cin >> choice;

			if(strcmp(choice,"A") == 0 || strcmp(choice, "A.") == 0 || strcmp(choice, "a") == 0)
			{
				Region(Array, rows, Tmin, Tmax, Pmin, Pmax);

				WrongChoice = 2;
			}
			else if(strcmp(choice,"B") == 0 || strcmp(choice, "B.") == 0 || strcmp(choice, "b") == 0)
			{
				Psat(Array, rows, Pmin, Pmax);

				WrongChoice = 2;
			}
			else if(strcmp(choice,"C") == 0 || strcmp(choice, "C.") == 0 || strcmp(choice, "c") == 0)
			{
				Tsat(Array, rows, Tmin, Tmax);

				WrongChoice = 2;
			}
			else if(strcmp(choice,"D") == 0 || strcmp(choice, "D.") == 0 || strcmp(choice, "d") == 0)
			{
				Px(Array, rows, Pmin, Pmax);

				WrongChoice = 2;
			}
			else if(strcmp(choice,"E") == 0 || strcmp(choice, "E.") == 0 || strcmp(choice, "e") == 0)
			{
				Tx(Array, rows, Tmin, Tmax);

				WrongChoice = 2;
			}
			else if(strcmp(choice,"F") == 0 || strcmp(choice, "F.") == 0 || strcmp(choice, "f") == 0)
			{
				Ph(Array, rows, Pmin, Pmax);

				WrongChoice = 2;
			}
			else if(strcmp(choice,"G") == 0 || strcmp(choice, "G.") == 0 || strcmp(choice, "g") == 0)
			{
				Th(Array, rows, Tmin, Tmax);

				WrongChoice = 2;
			}
			else if(strcmp(choice,"H") == 0 || strcmp(choice, "H.") == 0 || strcmp(choice, "h") == 0)
			{
				hx(Array, rows);

				WrongChoice = 2;
			}
			else
			{
				cout << "You have entered an invalid choice.\n"
					 << "Enter new value or press Ctrl^Break to quit.\n";
				WrongChoice =1;
			}
		}

		// THIS PART HANDLES WHETHER TO RUN THE PROGRAM AGAIN. IF USER
		// DOESN'T PUT IN PROPER CHOICE THE answer1 VALUE WILL REMAIN TRUE
		// AND IT LOOP WILL KEEP ITERATING UNLESS USER EXITS PROGRAM WITH CTRL^D
		// OR GETS THE RIGHT INPUT.
		cout << "\n\n\nRun new calculation (Y or N)?\n";
		answer1 = true;

		while(answer1 == true)
		{
			cin >> response;
			if(strcmp(response,"Y") == 0 || strcmp(response,"y") == 0 || strcmp(response,"Yes") == 0 || strcmp(response,"yes") == 0)
			{
				answer = true;
				answer1 = false;
			}
			else if (strcmp(response,"N") == 0 || strcmp(response,"n") == 0 || strcmp(response,"No") == 0 || strcmp(response,"no") == 0)
			{
				answer = false;
				answer1 = false;
			}
			else
			{
				cout << "You have entered an invalide choice.\n"
					 << "Enter \"Y\" for a new calculation or \n"
					 << "\"N\" to quit.\n";
				answer1 = true;
			}
		}
	}

	// AT THIS POINT THE PROGRAM SHOULD BE OVER
	// TIME TO FREE THE HEAP THAT THE ARRAY IS OCCUPYING

	for(i = 0; i < rows; i++)
	{
		delete [] Array[i];
	}
	delete [] Array;

	cout << endl << endl << endl << endl;

return 0;
}

int DataStart(ifstream& input)
{
    // THIS FUNCTION SAYS THAT IF IT FINDS A LINE WITH ANYTHING THAT ISN'T A
	// NUMBER, A \n, A DECIMAL POINT, OR A BLANK SPACE THEN COUNT THAT AS A
	// STARTING ROW TO DELETE WHEN ARRAY_SIZE WANTS TO FIND THE NUMBER OF VALID doubleS
	char next;
	int line_counter = 0;
    bool var1, var2 = true;

	while(var2 == true)
	{
		input.get(next); //GET A CHARACTER
		if(isdigit(next) == false && next != ' '&& next != '\n' && next != '.')
		// IF next HAS A CHARACTER OR SOME SYMBOL THAT ISN'T PART OF A TYPICAL STEAM TABLE DATA POINT
		// THEN RETURN TRUE SO THAT THE WHOLE LINE MAY BE DELETED IN THE ARRAY_SIZE FUNCTION
		{
			var1 = true;
		}
		if(var1 == false && next == '\n')
		// THIS STOPS THE LINE COUNTING ITERATION BECAUSE IT HAS FOUND THE FIRST LINE THAT CONTAINS
		// STEAM TABLE DATA
		{
			var2 = false;
		}
		if(var1 == true && next == '\n')
		// IF THE LINE HAS NON DATA POINT INFO IN IT AND YOU GET TO \n THEN COUNT THAT AS A LINE THAT
		// NEEDS TO BE DELETED LATER ON
		{
			line_counter++;
			var1 = false; // MAKE var1 FALSE SO THAT IT CAN BE USED IN THE NEXT ITERATION
		}

	}

	return line_counter++;
}

int ArraySize(ifstream& input, int line_counter)
{
	// THIS GETS PAST ALL THE JUNK LINES USING LINE_COUNTER
	// THEN COUNTS ALL THE TERMS NEEDED FOR THE ARRAY
	int counter = 0;
	int array_counter = 0;
	char next;
	double next1;

	while(! input.eof())
	{
		while(counter < line_counter)
		{
			input.get(next);
			if(next == '\n')
			{
				counter++;
			}
		}

		input >> next1;
		array_counter++;
	}

	return array_counter - 1; // -1 BECAUSE WE DON'T WANT EOF AS PART OF OUR ARRAY
}

void FillArray(ifstream& input, doublepointer& Array, int line_counter, int array_size, int columnsize, int rows)
{
	// NEEDS TO GET PAST JUNK JUST LIKE IN ARRAYSIZE FUNCTION
	int counter = 0;
	char next;
	double next1;

	while(counter < line_counter)
			{
				input.get(next);
				if(next == '\n')
				{
					counter++;
				}
			}
	// FILLS UP ARRAY WITH STEAM TABLE VALUES HERE
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columnsize; j++)
		{
			input >> next1;
			Array[i][j] = next1;
		}
	}
}

double MinSearch(const doublepointer& Array, int column, int rows)
{
	int i = 0;
	double minimum = Array[i][column]; // HERE'S THE MINIMUM VARIABLE

	for(i = 0; i < rows; i++)
	{
		if(minimum > Array[i][column])
		{
			minimum = Array[i][column];
		}
	}

	return minimum;

}
double MaxSearch(const doublepointer& Array, int column, int rows)
{
	int i = 0;
	double maximum = Array[i][column]; // HERES THE MAXIMUM VARIABLE

	for(i = 0; i < rows; i++)
	{
		if(maximum < Array[i][column])
		{
			maximum = Array[i][column];
		}
	}

	return maximum;
}

void Region(const doublepointer& Array, int rows, double Tmin, double Tmax, double Pmin, double Pmax)
{
	double T;
	double P;
	double Tsat, Psat, P2, P1, T2, T1;
	int column1 = 0;
	int column2 = 1;
	int rowhigh, rowlow;
	bool indicator = true;
	char response[5];

	while(indicator == true)
	{
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\nHere you will enter T and P data in order to get info about\n"
			 << "the phase of water.  Note that one value can be out of the steam\n"
			 << "table data range as long as the other is within range or out of\n"
			 << "range on the opposite side of the data range.\n"
			 << "\nExample: Given a T that is 4 degrees C lower than the lowest\n"
			 << "temperature value and a pressure 5 kPa above the highest pressure\n"
			 << "you would know that it has to be a subcooled liquid since it takes\n"
			 << "much less pressure to condense the lowest temperature.\n\n";

		cout << "Max T:  " << Tmax << " C" << endl;
		cout << "Min T:  " << Tmin << " C" << endl;
		cout << "Max P:  " << Pmax << " kPa" << endl;
		cout << "Min P:  " << Pmin << " kPa" << endl;

		cout << "\nPlease enter temperature in degrees Celsius:\n";
		cin >> T;
		cout << "\nPlease enter pressure in kPa:\n";
		cin >> P;

		if(T < Tmin && P < Pmin || T > Tmax && P > Pmax)
		{

			cout << "\nERROR: You have entered invalid data.\n"
				 << "Try again (Y or N)?";

			cin >> response;

			if(strcmp(response,"Y") == 0 || strcmp(response,"y") == 0 || strcmp(response,"Yes") == 0 || strcmp(response,"yes") == 0)
			{
				indicator = true;
			}
			else
			{
				indicator = false;
			}
		}
		else
		{
			// THESE FLAOT VALUES GO INTO THE INTERPOLATE FUNCTION
			if(T > Tmax && P < Pmin)
			{
				cout << "\n\nAt a temperature of " << T << " degrees C and a pressure of " << P << " kPa";
				cout << "\nwater is in the . . .\n\n";

				cout << "Superheated vapor region\n\n";
			}
			else if(P > Pmax && T < Tmin)
			{
				cout << "\n\nAt a temperature of " << T << " degrees C and a pressure of " << P << " kPa";
				cout << "\nwater is in the . . .\n\n";

				cout << "Subcooled liquid region\n\n";
			}
			else if(T <= Tmax && T >= Tmin)
			{
				rowhigh = SearchHigh(Array, rows, T, column1);
				rowlow = SearchLow(Array, rows, T, column1);
				T2 = Array[rowhigh][column1];
				T1 = Array[rowlow][column1];
				P2 = Array[rowhigh][column2];
				P1 = Array[rowlow][column2];

				Psat = interpolate(P2, P1, T2,T1,T);
				// THIS COMPARES THE INTERPOLATED PSAT VALUE TO THE VALUE THE USER PUT IN, THEN DETERMINES
				// THE REGION FROM THAT COMPARISON
				cout << "\n\nAt a temperature of " << T << " degrees C and a pressure of " << P << " kPa";
				cout << "\nwater is in the . . .\n\n";
				if(P > Psat)
					cout << "Subcooled liquid region\n\n";
				else if(P == Psat)
					cout << "Saturated liquid/vapor region\n\n";
				else
					cout << "Superheated vapor region\n\n";
			}
			else
			{
				rowhigh = SearchHigh(Array, rows, P, column2);
				rowlow = SearchLow(Array, rows, P, column2);
				T2 = Array[rowhigh][column1];
				T1 = Array[rowlow][column1];
				P2 = Array[rowhigh][column2];
				P1 = Array[rowlow][column2];

				Tsat = interpolate(T2, T1, P2,P1,P);
				// THIS COMPARES THE INTERPOLATED PSAT VALUE TO THE VALUE THE USER PUT IN, THEN DETERMINES
				// THE REGION FROM THAT COMPARISON
				cout << "\n\nAt a temperature of " << T << " degrees C and a pressure of " << P << " kPa";
				cout << "\nwater is in the . . .\n\n";
				if(T < Tsat)
					cout << "Subcooled liquid region\n\n";
				else if(T = Tsat)
					cout << "Saturated liquid/vapor region\n\n";
				else
					cout << "Superheated vapor region\n\n";
			}
			indicator = false;
		}
	}

}

void Psat(const doublepointer& Array,int rows, double Pmin, double Pmax)
{
	bool indicator = true;
	char response[5];
	int column1 = 0;
	int column2 = 1;
	int column3 = 2;
	int column4 = 3;
	int column5 = 4;
	int column6 = 5;
	int rowhigh, rowlow;
	double P, Tsat, hliq, hvap, vliq, vvap;
	double P2, P1, T2, T1, hliq2, hliq1, hvap2, hvap1,
		  vvap2, vvap1, vliq2, vliq1;


	while(indicator == true)
	{
		cout << "\n\nMax P:  " << Pmax << " kPa" << endl;
		cout << "Min P:  " << Pmin << " kPa" << endl;

		cout << "\n\nPlease enter pressure in kPa:\n";
		cin >> P;

		if(P < Pmin || P > Pmax)
		{

			cout << "\nERROR: You have entered invalid data.\n"
				 << "Try again (Y or N)?";

			cin >> response;

			if(strcmp(response,"Y") == 0 || strcmp(response,"y") == 0 || strcmp(response,"Yes") == 0 || strcmp(response,"yes") == 0)
			{
				indicator = true;
			}
			else
			{
				indicator = false;
			}
		}
		else
		{
			rowhigh = SearchHigh(Array, rows, P, column2);
			rowlow = SearchLow(Array, rows, P, column2);
			P2 = Array[rowhigh][column2];
			P1 = Array[rowlow][column2];
			T2 = Array[rowhigh][column1];
			T1 = Array[rowlow][column1];
			vliq2 = Array[rowhigh][column3];
			vliq1 = Array[rowlow][column3];
			vvap2 = Array[rowhigh][column4];
			vvap1 = Array[rowlow][column4];
			hliq2 = Array[rowhigh][column5];
			hliq1 = Array[rowlow][column5];
			hvap2 = Array[rowhigh][column6];
			hvap1 = Array[rowlow][column6];

			vliq = interpolate(vliq2, vliq1, P2, P1, P);
			vvap = interpolate(vvap2, vvap1, P2, P1, P);
			hliq = interpolate(hliq2, hliq1, P2, P1, P);
			hvap = interpolate(hvap2, hvap1, P2, P1, P);
			Tsat = interpolate(T2, T1, P2, P1, P);

			cout << "\n\nAt a saturation pressure of  " << P << " kPa . . .";
			cout << "\n\nTsat:  " << Tsat << " C\n";
			cout << "\nv-liquid:  " << vliq << " m3/kg\n";
			cout << "v-vapor:   " << vvap << " m3/kg\n";
			cout << "h-liquid:   "<< hliq << " kJ/kg\n";
			cout << "h-vapor:   " << hvap << " kJ/kg\n";
			indicator = false;
			}

	}
}

void Tsat(const doublepointer & Array, int rows, double Tmin, double Tmax)
{

	bool indicator = true;
	char response[5];
	int column1 = 0;
	int column2 = 1;
	int column3 = 2;
	int column4 = 3;
	int column5 = 4;
	int column6 = 5;
	int rowhigh, rowlow;
	double T, Psat, hliq, hvap, vliq, vvap;
	double P2, P1, T2, T1, hliq2, hliq1, hvap2, hvap1,
		  vvap2, vvap1, vliq2, vliq1;


	while(indicator == true)
	{
		cout << "\n\nMax T:  " << Tmax << " C" << endl;
		cout << "Min T:  " << Tmin << " C" << endl;

		cout << "\n\nPlease enter temperature in degrees C:\n";
		cin >> T;

		if(T < Tmin || T > Tmax)
		{

			cout << "\nERROR: You have entered invalid data.\n"
				 << "Try again (Y or N)?";

			cin >> response;

			if(strcmp(response,"Y") == 0 || strcmp(response,"y") == 0 || strcmp(response,"Yes") == 0 || strcmp(response,"yes") == 0)
			{
				indicator = true;
			}
			else
			{
				indicator = false;
			}
		}
		else
		{
			rowhigh = SearchHigh(Array, rows, T, column1);
			rowlow = SearchLow(Array, rows, T, column1);
			T2 = Array[rowhigh][column1];
			T1 = Array[rowlow][column1];
			P2 = Array[rowhigh][column2];
			P1 = Array[rowlow][column2];
			vliq2 = Array[rowhigh][column3];
			vliq1 = Array[rowlow][column3];
			vvap2 = Array[rowhigh][column4];
			vvap1 = Array[rowlow][column4];
			hliq2 = Array[rowhigh][column5];
			hliq1 = Array[rowlow][column5];
			hvap2 = Array[rowhigh][column6];
			hvap1 = Array[rowlow][column6];

			vliq = interpolate(vliq2, vliq1, T2, T1, T);
			vvap = interpolate(vvap2, vvap1, T2, T1, T);
			hliq = interpolate(hliq2, hliq1, T2, T1, T);
			hvap = interpolate(hvap2, hvap1, T2, T1, T);
			Psat = interpolate(P2, P1, T2, T1, T);

			cout << "\n\nAt a saturation temperature of  " << T << " degrees C . . .";
			cout << "\n\nPsat:  " << Psat << " kPa\n";
			cout << "\nv-liquid:  " << vliq << " m3/kg\n";
			cout << "v-vapor:   " << vvap << " m3/kg\n";
			cout << "h-liquid:   "<< hliq << " kJ/kg\n";
			cout << "h-vapor:   " << hvap << " kJ/kg\n";
			indicator = false;
		}
	}
}

void Px(const doublepointer & Array, int rows, double Pmin, double Pmax)
{
	bool indicator = true;
	char response[5];
	int rowhigh, rowlow;
	int column1 = 0;
	int column2 = 1;
	int column3 = 2;
	int column4 = 3;
	int column5 = 4;
	int column6 = 5;
	double P, Tsat, x, hav, vav, hliq, hvap, vliq, vvap;
	double P2, P1, T2, T1, hliq2, hliq1, hvap2, hvap1,
		  vvap2, vvap1, vliq2, vliq1;

	while(indicator == true)
	{

		cout << "\nMax P:  " << Pmax << " kPa" << endl;
		cout << "Min P:  " << Pmin << " kPa" << endl;

		cout << "\n\nPlease enter pressure in kPa: \n";
		cin >> P;
		cout << "\n\nPlease enter quality (dimensionless): \n";
		cin >> x;

		if(P < Pmin || P > Pmax || x > 1 || x < 0)
			{

				cout << "\nERROR: You have entered invalid data.\n"
					 << "Try again (Y or N)?";

				cin >> response;

				if(strcmp(response,"Y") == 0 || strcmp(response,"y") == 0 || strcmp(response,"Yes") == 0 || strcmp(response,"yes") == 0)
				{
					indicator = true;
				}
				else
				{
					indicator = false;
				}
			}
		else
		{

			rowhigh = SearchHigh(Array, rows, P, column2);
			rowlow = SearchLow(Array, rows, P, column2);

			T2 = Array[rowhigh][column1];
			T1 = Array[rowlow][column1];
			P2 = Array[rowhigh][column2];
			P1 = Array[rowlow][column2];
			vliq2 = Array[rowhigh][column3];
			vliq1 = Array[rowlow][column3];
			vvap2 = Array[rowhigh][column4];
			vvap1 = Array[rowlow][column4];
			hliq2 = Array[rowhigh][column5];
			hliq1 = Array[rowlow][column5];
			hvap2 = Array[rowhigh][column6];
			hvap1 = Array[rowlow][column6];

			Tsat = interpolate(T2, T1, P2, P1, P);
			vliq = interpolate(vliq2,vliq1,P2, P1, P);
			vvap = interpolate(vvap2, vvap1, P2, P1, P);
			hliq = interpolate(hliq2, hliq1, P2, P1, P);
			hvap = interpolate(hvap2, hvap1, P2, P1, P);

			vav = extrapolate(x, vliq, vvap);
			hav = extrapolate(x, hliq, hvap);

			cout << "\n\nAt " << P << " kPa and a quality of " << x << " . . .\n\n";
			cout << "Saturation temperature: " << Tsat << " C";
			cout << "\nSpecific volume: " << vav << " m3/kg";
			cout << "\nEnthalpy: " << hav << " kJ/kg\n";

			indicator = false;
		}
	}

}

void Tx(const doublepointer& Array, int rows, double Tmin, double Tmax)
{
	bool indicator = true;
	char response[5];
	int rowhigh, rowlow;
	int column1 = 0;
	int column2 = 1;
	int column3 = 2;
	int column4 = 3;
	int column5 = 4;
	int column6 = 5;
	double T, Psat, x, hav, vav, hliq, hvap, vliq, vvap;
	double P2, P1, T2, T1, hliq2, hliq1, hvap2, hvap1,
		  vvap2, vvap1, vliq2, vliq1;

	while(indicator == true)
	{
		cout << "\nMax T:  " << Tmax << " C" << endl;
		cout << "Min T:  " << Tmin << " C" << endl;

		cout << "\n\nPlease enter temperature in degrees C: \n";
 		cin >> T;
		cout << "\n\nPlease enter quality (dimensionless): \n";
		cin >> x;

		if(T < Tmin || T > Tmax || x > 1 || x < 0)
			{

				cout << "\nERROR: You have entered invalid data.\n"
					 << "Try again (Y or N)?";

				cin >> response;

				if(strcmp(response,"Y") == 0 || strcmp(response,"y") == 0 || strcmp(response,"Yes") == 0 || strcmp(response,"yes") == 0)
				{
					indicator = true;
				}
				else
				{
					indicator = false;
				}
			}
		else
		{

			rowhigh = SearchHigh(Array, rows, T, column1);
			rowlow = SearchLow(Array, rows, T, column1);

			T2 = Array[rowhigh][column1];
			T1 = Array[rowlow][column1];
			P2 = Array[rowhigh][column2];
			P1 = Array[rowlow][column2];
			vliq2 = Array[rowhigh][column3];
			vliq1 = Array[rowlow][column3];
			vvap2 = Array[rowhigh][column4];
			vvap1 = Array[rowlow][column4];
			hliq2 = Array[rowhigh][column5];
			hliq1 = Array[rowlow][column5];
			hvap2 = Array[rowhigh][column6];
			hvap1 = Array[rowlow][column6];

			Psat = interpolate(P2, P1, T2, T1, T);
			vliq = interpolate(vliq2,vliq1,T2, T1, T);
			vvap = interpolate(vvap2, vvap1, T2, T1, T);
			hliq = interpolate(hliq2, hliq1, T2, T1, T);
			hvap = interpolate(hvap2, hvap1, T2, T1, T);

			vav = extrapolate(x, vliq, vvap);
			hav = extrapolate(x, hliq, hvap);

			cout << "\n\nAt " << T << " degrees C and a quality of " << x << " . . .\n\n";
			cout << "Saturation pressure: " << Psat << " kPa";
			cout << "\nSpecific volume: " << vav << " m3/kg";
			cout << "\nEnthalpy: " << hav << " kJ/kg\n";

			indicator = false;
		}
	}
}

void Ph(const doublepointer& Array, int rows, double Pmin, double Pmax)
{
	bool indicator = true;
	char response[5];
	int rowhigh, rowlow;
	int column1 = 0;
	int column2 = 1;
	int column5 = 4;
	int column6 = 5;
	double h, P, Tsat, x, hliq, hvap;
	double P2, P1, T2, T1, hliq2, hliq1, hvap2, hvap1;

	while(indicator == true) // THIS WHILE STATEMENT IS IN CASE OF ERROR
	{
		cout << "\nMax P:  " << Pmax << " kPa" << endl;
		cout << "Min P:  " << Pmin << " kPa" << endl;

		cout << "\n\nPlease enter pressure in kPa: \n";
		cin >> P;
		cout << "\nPlease enter enthalpy in kJ/kg: \n";
		cin >> h;

		if(P < Pmin || P > Pmax)
			{

				cout << "\nERROR: You have entered invalid data.\n"
					 << "Try again (Y or N)?";

				cin >> response;

				if(strcmp(response,"Y") == 0 || strcmp(response,"y") == 0 || strcmp(response,"Yes") == 0 || strcmp(response,"yes") == 0)
				{
					indicator = true;
				}
				else
				{
					indicator = false;
				}
			}
		else // IF THERE ISN'T AN ERROR THEN DO THIS
		{
			rowhigh = SearchHigh(Array, rows, P, column2);
			rowlow = SearchLow(Array, rows, P, column2);

			T2 = Array[rowhigh][column1];
			T1 = Array[rowlow][column1];
			P2 = Array[rowhigh][column2];
			P1 = Array[rowlow][column2];
			hliq2 = Array[rowhigh][column5];
			hliq1 = Array[rowlow][column5];
			hvap2 = Array[rowhigh][column6];
			hvap1 = Array[rowlow][column6];
			Tsat = interpolate(T2,T1,P2,P1,P);
			hliq = interpolate(hliq2, hliq1, P2, P1, P);
			hvap = interpolate(hvap2,hvap1,P2,P1,P);

			if(h > hvap || h < hliq) // ERROR IN CASE ENTHALPY IS OUT OF SCOPE
			{

				cout << "\nERROR: You have entered invalid data.\n"
					 << "No quality exists when h > hvap or h < hliq.\n"
					 << "Try again (Y or N)?";

				cin >> response;

				if(strcmp(response,"Y") == 0 || strcmp(response,"y") == 0 || strcmp(response,"Yes") == 0 || strcmp(response,"yes") == 0)
				{
					indicator = true;
				}
				else
				{
					indicator = false;
				}
			}
			else // IN THIS ELSE STATEMENT QUALITY IS GIVEN A VALUE
			{
				x = quality(hliq,hvap,h);

				cout << "\n\nAt a pressure of " << P << " kPa and an enthalpy of " << h << " kJ/kg . . .\n";
				cout << "Saturation temperature: " << Tsat << " C\n";
				cout << "Quality: " << x << endl;
				indicator = false;
			}
		}
	}
}

void Th(const doublepointer& Array, int rows, double Tmin, double Tmax)
{
	bool indicator = true;
	char response[5];
	int rowhigh, rowlow;
	int column1 = 0;
	int column2 = 1;
	int column5 = 4;
	int column6 = 5;
	double T, Psat, x, h, hliq, hvap;
	double P2, P1, T2, T1, hliq2, hliq1, hvap2, hvap1;

	while(indicator == true) // THIS WHILE STATMENT IS IN CASE OF ERROR
	{
		cout << "\nMax T:  " << Tmax << " C" << endl;
		cout << "Min T:  " << Tmin << " C" << endl;

		cout << "\n\nPlease enter temperature in degrees C: \n";
		cin >> T;
		cout << "\n\nPlease enter enthalpy in kJ/kg: \n";
		cin >> h;

		if(T < Tmin || T > Tmax)
			{

				cout << "\nERROR: You have entered invalid data.\n"
					 << "Try again (Y or N)?";

				cin >> response;

				if(strcmp(response,"Y") == 0 || strcmp(response,"y") == 0 || strcmp(response,"Yes") == 0 || strcmp(response,"yes") == 0)
				{
					indicator = true;
				}
				else
				{
					indicator = false;
				}
			}
		else // IF THERE ISN'T AN ERROR THEN DO THIS
		{
			rowhigh = SearchHigh(Array, rows, T, column1);
			rowlow = SearchLow(Array, rows, T, column1);

			T2 = Array[rowhigh][column1];
			T1 = Array[rowlow][column1];
			P2 = Array[rowhigh][column2];
			P1 = Array[rowlow][column2];
			hliq2 = Array[rowhigh][column5];
			hliq1 = Array[rowlow][column5];
			hvap2 = Array[rowhigh][column6];
			hvap1 = Array[rowlow][column6];

			Psat = interpolate(P2,P1,T2,T1,T);
			hliq = interpolate(hliq2, hliq1, T2, T1, T);
			hvap = interpolate(hvap2,hvap1,T2,T1,T);

			if(h > hvap || h < hliq) // ERROR IN CASE ENTHALPY IS OUT OF SCOPE
			{

				cout << "\nERROR: You have entered invalid data.\n"
					 << "No quality exists when h > hvap or h < hliq.\n"
					 << "Try again (Y or N)?";

				cin >> response;

				if(strcmp(response,"Y") == 0 || strcmp(response,"y") == 0 || strcmp(response,"Yes") == 0 || strcmp(response,"yes") == 0)
				{
					indicator = true;
				}
				else
				{
					indicator = false;
				}
			}
			else // IN THIS ELSE STATEMENT QUALITY IS GIVEN A VALUE
			{
				x = quality(hliq,hvap,h);

				cout << "\n\nAt a temperature of " << T << " degrees C and an enthalpy of " << h << "kJ/kg . . .\n\n";
				cout << "The saturation pressure is: " << Psat << " C\n";
				cout << "The quality is: " << x << endl;
				indicator = false;
			}
		}
	}
}
void hx(const doublepointer& Array, int rows)
{
	bool indicator = true;
	char response[5];
	int rowhigh, rowlow;
	int column1 = 0;
	int column2 = 1;
	int column5 = 4;
	int column6 = 5;
	double *newarray = new double[rows];
	double h, x, Psat, Tsat;
	double h2, h1, T2, T1, P2, P1;

	while(indicator == true)

		// THIS WHILE STATEMENT IS IN CASE OF ERROR
	{
		cout << "\n\nPlease enter enthalpy in kJ/kg: \n";
		cin >> h;
		cout << "\n\nPlease enter quality (dimensionless): \n";
		cin >> x;
		cout << "Program will now check if table covers this data.\n";

		for(int i = 0; i < rows; i++)
		{
			newarray[i] = extrapolate(x, Array[i][column5], Array[i][column6]);
		}

		if(x < 0 || x > 1 || h < newarray[0] || h > newarray[rows - 1])
		{
			cout << "\nERROR: You have entered invalid data.\n"
				 << "Try again (Y or N)?";

			cin >> response;

			if(strcmp(response,"Y") == 0 || strcmp(response,"y") == 0 || strcmp(response,"Yes") == 0 || strcmp(response,"yes") == 0)
			{
				indicator = true;
			}
			else
			{
				indicator = false;
			}
		}
		else
		{
			for(int j = 0; j < rows - 1; j++)
			{
				if(h == newarray[j])
				{
					rowhigh = j;
					rowlow = j;
				}
				if(h == newarray[j+1])
				{
					rowhigh = j + 1;
					rowlow = j + 1;
				}
				if(h > newarray[j] && h < newarray[j+1])
				{
					rowhigh = j+1;
					rowlow = j;
				}
			}

			h2 = newarray[rowhigh];
			h1 = newarray[rowlow];
			P2 = Array[rowhigh][column2];
			P1 = Array[rowlow][column2];
			T2 = Array[rowhigh][column1];
			T1 = Array[rowlow][column1];

			Tsat = interpolate(T2, T1, h2, h1, h);
			Psat = interpolate(P2, P1, h2, h1, h);

			cout << "\n\nWith an enthalpy of " << h << " kJ/kg and a quality of " << x << " . . .\n";
			cout << "\nThe saturation temperature is: " << Tsat << " degrees C\n";
			cout << "The saturation pressure is: " << Psat << " kPa\n";

			indicator = false;
		}

	}
}

int SearchHigh(const doublepointer& Array, int rows, double Var, int column)
{
	int ROW;
	for(int i = 0; i < rows - 1; i++)
	{
		if(Array[i][column] == Var)
			ROW = i;
		if(Array[i][column] < Var && Array[i+1][column] >= Var)
			ROW = i+1;
	}
	return ROW;
}

int SearchLow(const doublepointer& Array, int rows, double Var, int column)
{
	int ROW;
	for(int i = 0; i < rows - 1; i++)
	{
		if(Array[i+1][column] == Var)
			ROW = i+1;
		if(Array[i][column] <= Var && Array[i+1][column] > Var)
			ROW = i;
	}
	return ROW;

}
double interpolate(double y2, double y1, double x2, double x1, double x)
{
	double y;

	if(y2 == y1 && x2 == x1)
		y = y2;
	else
	{
		y = y1 + (x - x1)*(y2 - y1)/(x2 - x1);
	}
	return y;
}
double extrapolate(double x, double yf, double yg)
{
	double y;
	y = yf + x * (yg - yf);
	return y;
}
double quality(double yf, double yg, double yav)
{
	double x;
	x = (yav - yf) / (yg - yf);
	return x;
}
