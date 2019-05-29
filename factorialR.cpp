//Objective: read all song titles from a text file,
//and randomly select and output titles in a loop until the user wishes to stop. 
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
void introduction(string obj); // user introduction
int factorial(int fact);

//main program
int main()
{
  //Data
  string objective = "calculate a factorial.";
  introduction(objective); //userintroduction
  int i; // index variable
  int input; // user input
  int result=1; // result of factorial calculation
  
  cout << endl << "Please enter a positive integer, including 0: ";
  cin >> input;
  cin.ignore(1000,10);
  
  cout << input << "! = " << factorial(input) << endl;
  
  
 

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

int factorial(int fact)
{
  int f; //output
  if (fact < 0 ) return 0;
  else if (fact == 0 || fact == 1) f=1;
  else
  {
    f = fact * factorial(fact-1);
    return f;
  }//end else
}//end factorial