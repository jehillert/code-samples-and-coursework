//		Flashbuddy
// Programmer: John Hillert
// Written: October - 2001
// Class: CHEN 358 Chemical Engineering Thermodynamics Lab
// Purpose: This program does flash calculations using:
//
//			1. Redlich-Kwong EOS
//			2. Soave-Redlich-Kwong EOS
//			3. Peng-Robinson EOS
//
// Last Updated:
//
//
//
/////////////////////////////////////////////////////////////

#include<iostream.h>
#include<math.h>


// something to hold properties of each fluid
struct fluid
{
	double Tc;
	double Pc;
	double w;
};



void EOS( double& a, double& b, fluid fluids, int choice, double T);
// This function calculates a and b for a specific fluid
// Precondition: a[], b[], the struct "fluids," and the EOS choice must be designated
// Postcondition: returns the a[i], and b[i]
void fill_array(double target[], double source[], int size);
// This function puts values from one array into an array of equal size
// Precondition: arrays should be of equal size
// Postcondition: returns target[] with same values as source[].
double am(double a[], double zxy[], int size);
// Calculates the summation of am
// Precondition: a[] must be filled, and x[] or y[] need to be full, array size needs to be included
// Postcondition: returns am as the sum of zxy[i]*a[i]^1/2 from i = 0 ==> size-1
double bm(double b[], double zxy[], int size);
// Calculates the summation bm
// Precondition: b[] must be filled, and x[] or y[] need to be full, array size needs to be included
// Postcondition: returns am as the summ of zxy[i]*b[i] from i = 0 ==> size-1
double Zcalc(double A,double B,int u,int w, int ztype);
// Calculates either the liquid or the vapor root depending on what ztype you specify
// Precondition:  A, B, u, and w must be designated. ztype ==> if 1 then liquid root, if 2 then vapor root
// Postcondition: returns the desired Z root
void cubic(double a, double b, double c, double d, int& isolv, double roots[]);
// Calculates the roots.  This is a subroutine of Zcalc
// Precondition: takes coefficients, array, and isolv.  Array is 3 because there are only 3 roots
// Postcondition: returns all of the roots, as well as isolve.  isolve will designate content of roots[]
double phi_calc(double a, double am, double b, double bm, double A, double B, double Z, int u, int w);
// Calculates phi
// Precondition: takes a, am, b, bm, A, B, Z, u, w for either vapor or liquid
// Postcondition: gives back phi
double psi_calc(const double z[], const double K[], double psi, int size);
// calculates a new psi
// Precondition: takes two arrays and psi
// Postcondition: calculates new psi
/*********************************************************************************************/
/*********************************************************************************************/

int main()
{
	// VARIABLE DECLARATIONS		
	const int comp = 5; // number of components
	int u, w, counter = 0, iterations;
	double T, P, R = 0.08314; // inputs
	double z[comp], y[comp], x[comp],a[comp],b[comp], phi_l[comp],phi_v[comp], K[comp]; //arrays
	double psi, amx,amy,bmx,bmy, Ax, Ay, Bx, By, Zl, Zv, sum = 1;
	int option = 0, answer = 1;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(4);

	// Struct list for all component fluids
	fluid ethane = {305.4, 48.8, 0.099}; // struct format pg 302 Savitch
	fluid propane = {369.8, 42.5, 0.153};
	fluid propanol = {536.8, 51.7, 0.623}; // this is 1-Propanol
	fluid pentane = {469.7, 33.7, 0.251};
	fluid heptane = {540.3, 27.4, 0.349}; // this is n-Heptane
	

	while(answer == 1)// this is for multiple calculations
	{
		psi = .5; // 1st guess at psi
		// USER INPUT
		// T, P, EOS, and iteration data
		int choice=4; 
		while(choice == 4)
		{
			cout << "Enter T in Kelvin:   ";
			cin >> T;
			cout << "\n\nEnter P in bar:   ";
			cin >> P;

			cout << "\n\nEnter number of desired EOS:\n\n";
			cout << "1   ----   Redlich-Kwong\n"
				 << "2   ----   Soave-Redlich-Kwong\n"
				 << "3   ----   Peng-Robinson\n" << endl;
			cin >> choice;
			
			cout << "\nEnter max iterations: ";
			cin >> iterations; // this lets the user put a limit on max iterations

			// if choice is incorrect, user must choose again
			if(choice != 1 && choice && choice != 2 && choice != 3)
			{
				cout << "\nError: Invalid choice. Try again,\n"
					 << "using just the number and no other\n"
					 << "characters.\n\n";
				choice = 4;
			}
		}
		//Designate u and w for phi equations later
		if(choice == 1 || choice == 2)
		{
			u = 1;
			w = 0;
		}
		else
		{
			u = 2;
			w = -1;
		}

		// z VALUES
		// Maybe I should put in a check to see if molar compositions sum up to one, 
		// but this may exclude experimental molar compositions from being used.

		while(option != 1) //put in mole fraction components
		{
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nEnter z (molar composition) for the following fluids:\n\n";
			cout << "Ethane:   ";
			cin >> z[0];
			cout << "\n\nPropane:   ";
			cin >> z[1];
			cout << "\n\n1-Propanol:   ";
			cin >> z[2];
			cout << "\n\nPentane:   ";
			cin >> z[3];
			cout << "\n\nn-Heptane:   ";
			cin >> z[4];

			cout << "\n\n Are these values correct? Enter 1 for yes, 2 for no.   "; // lets the user keep hands on 
			cin >> option;															// keypad instead of letters
		}
		option = 0;
		
		// designating initial y and x values
		fill_array(y, z, comp);
		fill_array(x, z, comp);
		
		// filling up a and b arrays using fluids and appropriate EOS equations
		EOS(a[0],b[0], ethane, choice, T);
		EOS(a[1],b[1], propane, choice, T);
		EOS(a[2],b[2], propanol, choice, T);
		EOS(a[3],b[3], pentane, choice, T);
		EOS(a[4],b[4], heptane, choice, T);

		while(sum >= 0.00000001 && counter <= iterations)// this is the main while loop
		{
			// Set sum to zero so it doesn't add up and never converge
			sum = 0;
			//summation values for am and bm, both liquid and vapor fractions
			amx = am(a,x,comp);
			bmx = bm(b,x,comp);


			amy = am(a,y,comp);
			bmy = bm(b,y,comp);
			
			//A and B values for liquid and vapor fractions
			Ax = (amx * P)/(R*R*T*T);
			Bx = (bmx * P)/(R*T);

			Ay = (amy * P)/(R*R*T*T);
			By = (bmy * P)/(R*T);

			// Solving for Z: if third argument is 1 then you want Zl, if it's 2 then Zv
			Zl = Zcalc(Ax,Bx,u,w,1);
			Zv = Zcalc(Ay,By,u,w,2);
		
			// steps 3 through 5 are right here
			for(int j = 0; j<comp; j++)
			{
				phi_l[j] = phi_calc(a[j], amx, b[j], bmx, Ax, Bx, Zl, u, w); // fills up phi vapor and liquid arrays
				phi_v[j] = phi_calc(a[j], amy, b[j], bmy, Ay, By, Zv, u, w);

				K[j] = phi_l[j]/phi_v[j]; // fills up K array
				x[j] = z[j]/(K[j] + psi*(1-K[j])); // calculates new x value
				y[j] = x[j]*K[j]; // calculates new y value
				sum = sum + x[j] - y[j]; // calculates the sum of all the new x and y values.  
			}   // sum is used as a test for accuracy of the results

			// Once x and y values are accurate enough then output results
			if(sum < 0.00000001 || counter == iterations)
			{
				cout << "\n\nAfter " << counter << " iterations. . . "; // tell user how many iterations it took
				cout << "\n\nPsi:    " << psi; // tell user what the final psi is
				
				cout << "\n\nx of ethane:        "<< x[0];
				cout << "\ny of ethane:        "<< y[0];
								
				cout << "\n\nx of propane:       "<< x[1];
				cout << "\ny of propane:       "<< y[1];
			
				cout << "\n\nx of 1-propanol:    "<< x[2];
				cout << "\ny of 1-propanol:    "<< y[2];
				
				cout << "\n\nx of pentane:       "<< x[3];
				cout << "\ny of pentane:       "<< y[3];
				
				cout << "\n\nx of n-heptane:     "<< x[4];
				cout << "\ny of n-heptane:     "<< y[4];
			}
			else
			{
				psi = psi_calc(z, K, psi, comp); // calculate a new psi since the last one didn't give the greatest accuracy
			}
			counter = counter++; // so iterating doesn't take too long
		}
		
		// this is for going around and doing a second, or third calculation
		cout << "\n\nWould you like another calculation? 1 for yes, 2 for no.   "; //again letting whole program work from
		cin >> answer;															   // keypad
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		counter = 0; // reset counter
		sum = 1;
	}
		
		
	return 0;

}

void EOS(double& a, double& b, fluid fluids, int choice, double T)
{
	double R = .08314;
	double fw, fw2, Tr;
	Tr = T/fluids.Tc;
	fw = 0.48+1.574*fluids.w-0.176*fluids.w*fluids.w;
	fw2 = 0.37464+1.542264*fluids.w-0.26992*fluids.w*fluids.w;

	if(choice == 1) //Redlich-Kwong
	{
		b = (0.08664*R*fluids.Tc/fluids.Pc);
		a = (0.42748*R*R*pow(fluids.Tc, 2.5))/(fluids.Pc*sqrt(T));
	}
	else if(choice == 2) //Soave-Redlich Kwong
	{
		b = (0.08664*R*fluids.Tc/fluids.Pc);
		a = (0.42748*R*R*fluids.Tc*fluids.Tc/fluids.Pc)*pow(1+fw*(1-sqrt(Tr)),2);
	}
	else
	{
		b = 0.07780*R*fluids.Tc/fluids.Pc; //Peng-Robinson
		a = (0.45724*R*R*fluids.Tc*fluids.Tc/fluids.Pc)*pow(1+fw2*(1-sqrt(Tr)),2);
	}
}


void fill_array(double target[], double source[], int size)
{
	for(int i = 0; i < size; i++)
	{
		target[i]=source[i];
	}
}
	
double am(double a[], double zxy[], int size)
{
	double am = 0, newpart;

	for(int i = 0; i<size; i++)
	{

		newpart = zxy[i]*sqrt(a[i]);

		am = am + newpart;
	}
	am = am*am;

	return am;
}

double bm(double b[], double zxy[], int size)
{
	double bm = 0, newpart;

	for(int i = 0; i<size; i++)
	{
		newpart = b[i] * zxy[i];
		bm = bm + newpart;
	}
	return bm;
}

double Zcalc(double A,double B,int u,int w, int ztype)
{
	double a, b, c, d, Z;
	int isolv=0;
	double roots[3]; // cubic solvers can only have 3 roots
	
	a = 1;
	b = -1-B+1.0*u*B;
	c = A + 1.0*w*B*B - 1.0*u*B - 1.0*u*B*B;
	d = -1.0*A*B-1.0*w*B*B-1.0*w*B*B*B;

	cubic(a, b, c, d, isolv, roots);

	// if ztype is a 1 then we want the lowest root because Z is for the liquid phase
	// if it's a 2 then we want the highest root because Z is for vapor phase
	if(ztype == 1 && isolv != 0)
	{
		Z = roots[0];
	}
	else if(ztype == 2 && isolv != 0)
	{
		if(isolv == 1)
			Z = roots[0];
		else
			Z = roots[2];
	}
	else // if isolv is zero then there aren't any roots
	{
		Z = 0;
	}

	return Z;
}
void cubic(double a, double b, double c, double d, int& isolv, double roots[])
{
	//  The author of this subroutine is Charles Vestal.  I translated it into C++
	double p, q, D; // the next three doubles are created in 
	double u, v, r1, r2, r3, x, theta; // the function
    double pi = 3.1415926535;
	int i = 0;

	for(i=0;i<3;i++)
	{
		roots[i]=0;
	}
	
	b=b/a;
	c=c/a;
	d=d/a;
	a=a/a;

	//defining intermediary values p,q,D
	p = (1/3.0)*(3*c-b*b);
	q = (1/27.0)*(2*b*b*b-9*b*c + 27*d);
	D = (p/3)*(p/3)*(p/3) + (q/2)*(q/2);
	
	isolv = 0;

	
	if(b==0.0 && c == 0.0 && d == 0.0)
	{
		isolv = 1;
	}
	else if(a != 0)
	{

		if(D > 0.0)
		{
			if(0.5*q+sqrt(D) < 0.0)
			{
				u = pow(fabs((0.5)*q-sqrt(D)),(1/3.0));
				v = pow(fabs((0.5)*q+sqrt(D)),(1/3.0));
			}
			else
			{
				v = -1.0*pow(fabs(0.5*q+sqrt(D)),(1/3.0));
				if(0.5*q-sqrt(D) < 0.0)
				{
					u = pow(fabs(0.50*q - sqrt(D)),(1/3.0));
				}
				else
				{
					u = -1*pow(fabs(0.50*q - sqrt(D)),(1/3.0));
				}
			}
		}
		else
		{
			x=(-q/2.0)/sqrt(pow(fabs(p),3)/27);
			
			if(x>1.0 || x<1.0)
			{
				isolv = 0;
			}
			theta = acos(x);
		}
		if(D > 0.0)
		{
			isolv = 1;
			roots[0] = u+v - b/3.0;
		}
		else
		{
			r1 = 2.0*sqrt(fabs(p)/3.0)*cos(theta/3.0)-b/3.0;
			r2 = -2.0*sqrt(fabs(p)/3.0)*cos((theta+pi)/3.0)-b/3.0;
			r3 = -2.0*sqrt(fabs(p)/3.0)*cos((theta-pi)/3.0)-b/3.0;
			if(D<0.0)
			{
				isolv = 3;
				//
				// inline sort of roots in ascending order
				//
				if(r1<r2 && r1<r3)
				{
					roots[0] = r1;
					if(r2>r3)
					{
						roots[1] = r3;
						roots[2] = r2;
					}
					else
					{
						roots[1] = r2;
						roots[2] = r3;
					}
				}
				else if(r2 < r1 && r2 < r3)
				{
					roots[0] = r2;
					if(r1>r3)
					{
						roots[1] = r3;
						roots[2] = r1;
					}
					else
					{
						roots[1] = r1;
						roots[2] = r3;
					}
				}
				else
				{
					roots[0] = r3;
					if(r2>r1)
					{
						roots[1] = r1;
						roots[2] = r2;
					}
					else
					{
						roots[1] = r2;
						roots[2] = r1;
					}
				}
			
			}
			else
			{
				isolv = 2;
				
				// inline sort of roots in ascending order
				if(r1<r2 && r1 < r3) 
				{
					roots[0] = r1;
					roots[1] = r2;
					roots[2] = r3;
				}
				else if (r2 < r1 && r2 < r3)
				{
					roots[0] = r2;
					roots[1] = r1;
					roots[2] = r3;
				}
				else
				{
					roots[0] = r3;
					roots[1] = r1;
					roots[2] = r2;
				}
			}
		}

	}
	else
	{} 
}
double phi_calc(double a, double am, double b, double bm, double A, double B, double Z, int u, int w)
{
	double phi;
	double e = 2.71828182846;
	double exponent;
	double gamma;
	
	gamma = 2.0*sqrt(a/am);
	exponent = (b/bm)*(Z-1)-log(Z-B)+(A/(B*sqrt(u*u-4*w)))*((b/bm)-gamma)*log((2*Z+B*(u+sqrt(u*u-4*w)))/(2*Z+B*(u-sqrt(u*u-4*w))));
	phi = pow(e, exponent);

	return phi;
}
double psi_calc(const double z[], const double K[], double psi, int size)
{
	double top = 0, bottom = 0;
	double new_psi;

	for(int i = 0; i < 5; i++)
	{
		top = top + (z[i]*(K[i]-1))/(K[i] + psi*(1-K[i]));
		bottom = bottom + (z[i]*(K[i]-1)*(K[i]-1))/pow(K[i] + psi*(1-K[i]),2);
	}

	new_psi = psi - top/bottom;

	return new_psi;
}
	








	





	

