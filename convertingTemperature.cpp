//Objective:  convert fahrenheit to celsius temperature.
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
  double c; // degrees Celsius
  double f; // degrees Fahrenheit

  // output my name and objective and program information
  cout << "Objective: This program will convert fahrenheit to celsius temperature."; 
  cout << "Programmer: Robert Loth\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  // ask user to enter Fahrenheit
  cout << "Enter the temperature in degrees Fahrenheit: ";
  cin >> f;

  // convert temperature
  c = 5 * (f - 32) / 9;

  //output results
  cout << "That's " << c << " degrees Celsius!" << endl; 


}//main