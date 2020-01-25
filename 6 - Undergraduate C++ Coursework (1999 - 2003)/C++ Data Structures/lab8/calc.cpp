// Program: Calculator
// Programmer: John Hillert
// Last Updated: 10/15/02
// Purpose: This program takes multiple expressions, prints them
// to the screen, and then evaluates them, substituting in values
// provided for the variables.

#include <iostream>
#include <stack>
#include <cassert>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include "node2.h"

using namespace main_savitch_6B;

const char LEFT_PARENTHESIS = '(';
const char RIGHT_PARENTHESIS = ')';
const char DECIMAL = '.';

struct op
{
  char op_type; 
  char op_or_name;
  double value;
};
// struct op stores three types of op_types.  'O' is for operator, 
// 'V' is for variable, 'N' is for number.  op_or_name stores the 
// name of the variable or the character that represents the operator.

// PRIMARY FUNCTIONS
void get_variables(node<op>*& variables);
// Postcondition: Asks user for variables and their values.  
// These variables and values are stored in linked list of structure
// type variables.  The variable letter is stored under member
// op_or_name and the value is stored in value. Each op_type is 'V'
// for variable. 

bool get_expression(node<op>*& exp, istream& ins);
// Precondition: exp is a valid linked list, and ins is a valid
// input stream
// Postcondition: fills linked list of type op that stores
// an entire expression that the user inputs. Returns true if
// the expression has balanced parentheses, otherwise false

double evaluate_expression(node<op>* exp, node<op>* variables);
// Precondition: exp and variables (variables can be empty if there 
// are no variables to be subbed) are filled linked lists. Exp 
// is a valid expression (balanced parentheses) and variables
// has all the values for the variables in that expression.
// Postcondition: a numerical value for the expression is returned

void print_expression(node<op>* exp, node<op>* variables);
// Precondition: exp and variables (variables can be empty if there 
// are no variables to be subbed) are filled linked lists. Exp 
// is a valid expression (balanced parentheses) and variables
// has all the values for the variables in that expression.
// Postcondition: the expression that was entered is printed out
// to the screen, with values of the variables filled in for those
// variables.

// HELPER FUNCTIONS
bool lower_precedence(char op1, char op2);
// Precondition: op1 and op2 are characters
// Postcondition: True if op1 has lower precedence than op2, else
// false

void list_attach(node<op>*& head, node<op>*& tail, op entry);
// Precondition: head and tail are declared nodes of type op.  
// Postcondition: If head is NULL, it puts entry at the 
// head of the list and sets tail = head.  If it isn't NULL then
// put it at the end of he list

double apply(char operation, double lhs, double rhs);
// Postcondition: Returns the value received when the operator
// operates on the lhs and rhs arguments 

double get_value(node<op>* variables, char name);
// Postcondition: searches "variables" in order to find the value
// associated with variable "name." Returns that value, or prints
// an error if the variable does not exist. 

void main( )
{
   node<op>* expression = NULL;
   node<op>* variables = NULL;
   bool matched;
   char answer = 'y';

   while(answer == 'y' || answer == 'Y')
   {
      get_variables(variables);
      cin.ignore();
      matched = get_expression(expression, cin);

      if(matched)
      {
         print_expression(expression, variables);
      }

      else
      {
         cout << "\n\n\n\n\n\ERROR: Parenthesis aren't matched.\n\n\n";
         exit(0);
      }

      cout << "\nThe expression evaluates to: " 
           << evaluate_expression(expression, variables) << endl << endl;

      // Return expression and variables to the heap so they can 
      // safely be reused
      list_clear(expression);
      list_clear(variables);
      
      cout << "\nWould you like to evaluate another expression "
               <<  "('y' yes, 'n' no)?";
      cin >> answer;
   }
 
}

void get_variables(node<op>*& variables)
{
   char answer;
   op variable;

   cout << "\n\nDo you have variables to declare ('y' for yes, 'n' for no)?  ";
   cin >> answer;
   
   while (answer == 'y' || answer == 'Y')
   {
      variable.op_type = 'V';

      cout << "\nEnter variable (one character only): ";
      cin >> variable.op_or_name;
      cout << "Enter variable value: ";
      cin >> variable.value; 
      
      list_head_insert(variables, variable);
      cout << "\nDo you wish to declare another variable? "
           << "('y' yes, 'n' no)? ";
      cin >> answer;
   }
} 
 
bool get_expression(node<op>*& exp, istream& ins)
{
   stack<char> operations;
   char symbol;
   double number;
   op variable;
   node<op> *exp_tail=NULL;

   cout << "\n\nEnter expression: \n";
   
   while(ins && ins.peek() != '\n')
   {
      if (ins.peek() == LEFT_PARENTHESIS)
      {
         ins >> symbol;
         operations.push(symbol); 
      }

      else if(isdigit(ins.peek()) || (ins.peek() == DECIMAL))
      {
         ins >> number;
         variable.op_type = 'N';
         variable.value = number;
         list_attach(exp, exp_tail, variable);   
      }

      else if(isalpha(ins.peek()))
      {
         ins >> symbol;
         variable.op_type = 'V';
         variable.op_or_name = symbol;
         list_attach(exp, exp_tail, variable);
      }

      else if(strchr("+-*/", ins.peek()) != NULL)
      {
         while(! operations.empty() && operations.top() != LEFT_PARENTHESIS 
              && ! lower_precedence(operations.top(), ins.peek()))
         { 
         
            variable.op_type = 'O';
            variable.op_or_name = operations.top();
            operations.pop();
            list_attach(exp, exp_tail, variable);

         }
         ins >> symbol;
         operations.push(symbol);
      }

      else if(ins.peek() == RIGHT_PARENTHESIS)
      {
         ins >> symbol;
         while(operations.top() != LEFT_PARENTHESIS && ! operations.empty())
         {
            variable.op_type = 'O';
            variable.op_or_name = operations.top();
            operations.pop();
            list_attach(exp, exp_tail, variable);
         }

         if(operations.top() == LEFT_PARENTHESIS)
         {
            operations.pop();
         }
         else
         {
            return false; 
         }
      }
      
      else
      {
         ins.ignore();
      }
   } 
   while(! operations.empty())      
   {
      variable.op_type = 'O';
      variable.op_or_name = operations.top();
      operations.pop();
      list_attach(exp, exp_tail, variable);
   }
   return true;
}

double evaluate_expression(node<op>* exp, node<op>* variables)
{
   stack<double> numbers;
   node<op> *cursor;
   op variable;
   double lhs;
   double rhs;

   for(cursor = exp; cursor != NULL; cursor = cursor->link())
   {
      variable = cursor->data();   

      if(variable.op_type == 'N')
      { 
         numbers.push(variable.value);
      }

      else if(variable.op_type == 'V')
      {
         numbers.push(get_value(variables, variable.op_or_name));
      } 
      else
      {
         rhs = numbers.top();
         numbers.pop();
         lhs = numbers.top();
         numbers.pop();
         numbers.push(apply(variable.op_or_name, lhs, rhs));
      }  
   }

   return numbers.top();
}

void print_expression(node<op>* exp, node<op>* variables)
{
    op term;  // holds current item from expression list
    while (exp != NULL)
    {
	term = exp->data();		// get term
        exp = exp->link();		// move to next item
	if (term.op_type == 'O')  // Operator
	{
	   cout << term.op_or_name;
	   cout << " ";
	}
	if (term.op_type == 'V')  // Variable, must get value
	{
  	   cout << get_value(variables, term.op_or_name);
  	   cout << " ";
	}
	if (term.op_type == 'N')  // Number, use value directly  
	{
	   cout << term.value;
	   cout << " ";
	}
  }
    cout << endl;
}

bool lower_precedence(char op1, char op2)
{
   if((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/'))
      return true;
   else
      return false;
}

void list_attach(node<op>*& head, node<op>*& tail, op entry)
{
   if(head == NULL)
   {
      head = new node<op>;
      head->data() = entry;
      tail = head;
   }
   else
   {
      list_insert(tail, entry);
      tail = tail->link();
   }
}

double apply(char operation, double lhs, double rhs)
{
   double value;
   switch (operation)
   {
      case '+': value = lhs + rhs;
                break;
      case '-': value = lhs - rhs;
                break;
      case '*': value = lhs * rhs;
                break;
      case '/': value = lhs/rhs;
                break;
   }
 