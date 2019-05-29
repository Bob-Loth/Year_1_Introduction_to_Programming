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
  double number1 = 0; //first number, the numerator in division
  double number2 = 0; // the denominator in division
  int operat = 0; // number representing the operation to be carried out
  double result= 0; // the result of the calculation being carried out
  char done; // checks to see if there are any more calculations

  // output my name and objective and program information
  cout << "Objective: Select 2 numbers and an operator, and perform a calculation on those numbers using the operator.\n"; 
  cout << "Programmer: Robert Loth\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //receive and validate number1
  
do
{
  cout << "This program will perform a basic math operation on 2 numbers of your choosing. "<< endl;
  
      cout << "Please enter your first number: ";
      cin >> number1;
      cin.ignore(1000,10);
     
    //receive and validate number2

  
      cout << "Please enter your second number: ";
      cin >> number2;
      cin.ignore(1000,10);  
    
    //receive operator, then select the relative operation
  do  
  {
    cout << "Please choose an operator to perform an operation with: + (1), - (2), * (3), or / (4).";
    cin >> operat;
    cin.ignore(1000,10);
    if (operat == 1)
    {
        result = number1 + number2;
    }//if +
    else if (operat == 2)
    {
      result = number1 - number2;
    }//if -
    else if (operat == 3)
         {
           result = number1 * number2;
         }// if *
    else if (operat == 4)
         { if (number2 == 0)
           {  
             cout << "You cannot divide by 0";
           }//divide by 0 error   
           else result = number1 / number2;
         }// if else
    else 
      { 
        cout << "Let's try again.  \n\n";
        
    }//end of if elseif else
  } while(operat != 1 && operat != 2 && operat != 3 && operat !=4);//do while loop to validate operation

  if (operat == 1)
  {
    cout << endl << number1 << " + " << number2 << " = " << result;
  }//result if addition

  else if (operat == 2)
  {
    cout << endl << number1 << " - " << number2 << " = " << result;
  }//result if subtraction

  else if (operat == 3)
  {
  cout << endl << number1 << " * " << number2 << " = " << result;
  }//result if multiplication

  else if (operat == 4) 
  {
    if (number2 == 0);
    else cout << endl << number1 << " / " << number2 << " = " << result;
  }//result if division

  else cout << "shutting down, unexpected error";
  //receive input for operat, which defines the operation to use
  
  cout << endl << endl << "Another calculation? [Y=yes or N=no]: ";
  cin >> done;
  cin.ignore();
} while (toupper(done)  == 'Y');//outermost do while


}//main