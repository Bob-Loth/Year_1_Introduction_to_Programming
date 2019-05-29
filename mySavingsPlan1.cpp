//Objective:  calculate how much money to save every month for number of years before retirement and how much money would you have when you retire.
//Name: Teacher
//Course: COMSC-110-8269
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream>
#include <iomanip>
using namespace std;
#include <cmath>
//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
//NONE

//main program
int main()
{
  //Data
  int years = 10;              // years of depositing the deposit amount, later converted to monthly
  int deposit = 100;           // amount in USD
  double interestRate = 0.075; // annual interest rate, later converted to monthly for the purposes of the calculation
  double amountSaved;          // formatted later in output statement, the end result
  // introduction
  cout << "Objective: This program will calculate how much money to save every month for number of years before retirement and how much money would you have when you retire.\n";
  cout << "Programmer: Teacher\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
  
  // convert interest rate and years to monthly 
  interestRate = interestRate / 12;
  int time = years * 12;
  
  // perform amortization calculation, store results
  amountSaved = deposit * ((pow((1 + interestRate), time) - 1) / interestRate);
  
  
  //output values and accompanying labels, format output statement
  interestRate = interestRate * 1200; // converting interest rate from monthly number to annual percentage 
  cout << "In " << years << " years at " << interestRate << "%, $" << deposit;
  cout.setf(ios::fixed|ios::showpoint); // non default formatting, uses iomanip
  cout << setprecision(2);              // set to 2 after decimal point
  cout << " deposited per month will grow to $" << amountSaved << "." << endl;
 
  
}//main