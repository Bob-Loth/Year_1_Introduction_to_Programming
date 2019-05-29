//Objective:  
//Name: Robert Loth
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream>
using namespace std;
 

#include <cstdlib>
#include <ctime>

//Programmer defined data types
//NONE ch 13

//Special compiler dependent definitions
//NONE ch 7/8

//global constants/variables
//NONE ch 13

//Programmer defined functions
void introduction(string obj); // user introduction


//main program
int main()
{
  //Data
  string objective = "serve as a template for all programs"; //program objective
  const int MAX_GUESS = 100;// list capacity
  int nGuess = 0; // initially empty list
  int guess[MAX_GUESS];// array-based list of 100 capacity
  int aGuess; //guess to be added to array guess
  srand(time(0)); // seed rng
  int correctGuess = (rand() % 100) + 1; // random number between 1 and 100 used in guessing game
  bool addtolist = true; // if false, will not allow adding that score
  int i; // for loop index variable

  introduction(objective); //userintroduction
//introduction
cout << "I'm thinking of a number between 1 and 100. Guess what it is: ";

//play game
do 
{    
  
  cin >> aGuess;
  cin.ignore(1000,10);
  
//traverse list to see if the value has been guessed before
  for (i=0; i < nGuess; i++)
  {
    if (guess[i] == aGuess) //unique check
    {
      cout << "You already guessed " << aGuess << ".\n";
      addtolist = false;
    }//end unique check
    else addtolist = true;
  }//for don't add unless unique, show you already guessed prompt
// check if there is space, and it is unique before adding the guess to the list  
  if (nGuess < MAX_GUESS && addtolist) 
  {
    guess[nGuess++] = aGuess;
  }//end if max check

  // display results of the previous guess
  if (aGuess > correctGuess)
  {
    cout << "That's too high -- guess again: ";
  }// if too high
  else if (aGuess < correctGuess)
  {
    cout << "That's too low -- guess again: ";
  }// if too low
  else if (aGuess = correctGuess)
  {
    cout << "That's right -- it's " << correctGuess << endl;
  }// if just right
}while (aGuess != correctGuess); //keep playing until user guesses the number




 
    
 
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

