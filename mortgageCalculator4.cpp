//Objective:  
//Name: Robert Loth
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iomanip>
#include <iostream>
using namespace std;
 

#include <cmath>


//Programmer defined data types
struct MortgageInfo // contains data items to calculate mortgage payment
  {
    double amountBorrowed; //in dollars
    double interestRate; // decimal monthly interest rate
    double monthlyPayment; //
    int years; // length of repayment period in years
  };//MortageInfo

//Special compiler dependent definitions
//NONE ch 7/8

//global constants/variables
//NONE ch 13

//Programmer defined functions
void introduction(string obj); // user introduction
void mortgageCalc(MortgageInfo& a); // calculates the monthly payment on a mortgage using input from structure MortgageInfo.

//main program
int main()
{
  //Data
  string objective = "calculate a mortgage payment using structures."; //program objective
  MortgageInfo a;
  a.years = 360;
  double annualInterest;
  introduction(objective); //userintroduction
  int i; //index variable
  bool clsprg = true; closes pro

  
  for (i=0; i<=5; i++)
  {
     if (i==0) cout << "Please enter your student ID: ";
     else if (i<=4) cout << "Incorrect ID. Please try again or contact student services: " ;
     else if (i==5) cout << "One try remaining. Please contact student services: ";
     cin >> password;
     cin.ignore(1000,10);
     if (password == 7744771) 
     {
       break; //I couldn't find my student id in time
       clsprg = true;
     }//check password
     if password != 774771) clsprg = false;
  }
   
if (clsprg)
{  
  cout << "What is the total amount, in dollars, that was borrowed?: ";
  cin >> a.amountBorrowed;
  cin.ignore(1000,10);
  cout << "What is the annual decimal interest rate?: ";
  cin >> annualInterest;
  cin.ignore(1000,10);
  a.interestRate = annualInterest / 12;
  a.monthlyPayment = (a.amountBorrowed * a.interestRate * pow((a.interestRate + 1),a.years)) / ( pow((a.interestRate + 1),a.years) - 1 );

  cout << "\nWith a loan of $"<< a.amountBorrowed << " at " << a.interestRate * 1200<< "% annual interest, you will need to pay $"<<a.monthlyPayment<< " per month."; 
}// if clsprg 
    
 
} // main 


// output my name and objective and program information
void introduction(string obj)
{
  //data
  //obj is the program objective passed from main program

  cout << "Objective: This program will "; 
  cout << obj << endl;
  cout << "Programmer: Robert Loth\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl; 
}//end introduction


  
