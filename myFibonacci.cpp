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
int fib(int num); // creates a list of fibonacci numbers up to the nth value 


//main program
 
int main()
{

  //DATA
  string objective = "calculate a value in the Fibonacci sequence.";
  introduction(objective);
  int n;// corresponds to the position in an array of Fibonacci numbers. fib[0] is 0, fib[1] is 1, and so on.
  //create an array-based list that can contain the first 40 fibonacci numbers.
 
  cout << "Please enter an integer between 0 and 40. \nThis program will calculate the fibonacci number corresponding to its position: ";
  while(true)
  {
    cin >> n;
    cin.ignore(1000,10);
    if (n < 0 || n > 40)
    {
      cout << "please enter an integer between 0 and 40: ";
    }// end if invalid
    else break;
  }//end while validation loop



  cout <<"Fibonacci list: ";
  for (int i = 0; i<=n; i++)
   cout << fib(i) << " ";
  cout << "\nThe Fibonacci number at position "<< n <<" is "<< fib(n) << endl;
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

int fib(int num)
{
  //data
  int f; //returned value

  if (num<2)   f = num;
  else 
  {
  f = fib(num-1) + fib(num-2);
  }//end else
  return f;
  
}





