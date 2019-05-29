//Objective:  Select 2 numbers and an operator, and perform a calculation on those numbers using the operator.
//Name: Robert Loth
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream>
using namespace std;


//Programmer defined data types
//NONE ch 13

//Special compiler dependent definitions
//NONE ch 7/8

//global constants/variables
//NONE ch 13

//Programmer defined functions
//NONE 

//main program
int main()
{
  //Data
  double number1; //first number, the numerator in division
  double number2; // the denominator in division
  char operator; // number representing the operation to be carried out
  double result; // the result of the calculation being carried out

  // output my name and objective and program information
  cout << "Objective: Select 2 numbers and an operator, and perform a calculation on those numbers using the operator.\n"; 
  cout << "Programmer: Robert Loth\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //receive and validate number1
  cout << "This program will perform a basic math operation on 2 numbers of your choosing. Please enter your first number." << endl;
  cin >> number1;
  cin.ignore(1000,10);

  //receive and validate number2
  cout << "Please enter the second number."
  cin >> number2;
  cin.ignore(1000,10);  
}//main