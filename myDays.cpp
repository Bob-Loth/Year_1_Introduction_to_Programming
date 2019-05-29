//Objective:  To calculate how many days old I will be by the due date of the assignment, not including the end date, using pre-calculated values.
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
  //Data : change these values to accommodate different dates
  int years = 25;   // 1994-2018, including end year
  int leapDays = 6; // 1996, 2000, 2004, 2008, 2012, 2016
  int daysBefore = 363; // on non-leap year, December 29th only has 2 days after it, so 363 days before, including itself.

  // output my name and objective and program information
  cout << "Objective: This program will calculate how many days old I will be by the due date of the assignment, not including the end date, using precalculated values.\n"; 
  cout << "Programmer: Robert Loth\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl; 


  // Perform calculations on data
  int days1 = years * 365;
  int days2 = days1 + leapDays;
  int days3 = days2 - daysBefore;
  int age   = days3 - 190;

  // Output, in 3 separate lines, DOB, due date, and age in days.
  cout << "DOB: 12/29/1994" << endl;
  cout << "Due Date: 6/24/2018" << endl;
  cout << "Age in days by due date: " << age << endl;

}//main