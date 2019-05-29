//Objective:  Make a user guess a number between 1 and 10 and verify it against a randomly generated number.
//Name: Robert Loth
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>

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
  srand(time(0)); rand();
  int usersGuess;
  int randomNumber;

  // output my name and objective and program information
  cout << "Objective: This program will Make a user guess a number between 1 and 10 and verify it against a randomly generated number.\n"; 
  cout << "Programmer: Robert Loth\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  cout << "I'm thinking of a number between 1 and 10. (enter a number between 1 and 10.)" ;
    cin >> usersGuess ;
    cin.ignore(1000,10);
    cout << endl;
  randomNumber = 1 + (rand() % 10); // 1 to 10
  
  while(usersGuess != randomNumber)
  {
    
    if (usersGuess < 1 || usersGuess > 10)
    {  
      cout << "I really want a number between 1 and 10.";
      cin >>  usersGuess;
      cin.ignore(1000,10);
    }//if wrong guess

    else 
    {
      cout << "Try again...  " << endl;
      cin >> usersGuess;
      cin.ignore(1000,10);
    }   
      
   
  }//while ends on success
  cout << "You guessed it!" << endl;
}//main