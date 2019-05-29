//Objective:  play the card game of War.
//Name: Robert Loth
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream>
using namespace std;
 

#include <cmath>
#include <cstdlib> // for random number generator
#include <ctime> // for seeding random number generator

//Programmer defined data types
//NONE ch 13

//Special compiler dependent definitions
//NONE ch 7/8

//global constants/variables
//NONE ch 13

//Programmer defined functions
void introduction(string obj); // user introduction
void myBillions();

//main program
int main()
{
  //Data
  string objective = "  play the card game of War."; //program objective
  srand(time(0)); // seed rng
  int playerSuit; //rng from 0-3 to simulate suit in cards.  Has no bearing on who wins
  int compSuit; //rng from 0-3 to simulate suit in cards. Has no bearing on who wins
  string playerSuitOutput; //translate 0-3 into hearts, clubs, spades, or diamonds.
  string compSuitOutput; //translate 0-3 into hearts, clubs, spades, or diamonds.
  int playerValue; //rng from 1-13 to simulate card number. 2-10 are normal but 1 is ace, 11 is jack, 12 is queen, 13 is king
  int compValue; // rng from 1-13 to simulate card number. 2-10 are normal but 1 is ace, 11 is jack, 12 is queen, 13 is king
  string playerValueOutput; //shows the number, or special card
  string compValueOutput; //shows the number, or special card
 
 string playerVictor; //  string value used as label to pronounce the winner of each round. 
  string compVictor; //string value used as label to pronounce the winner of each round.
  string Victor; //string value used as label to pronounce the winner of each round.
  char repeatGame; // determines if game is played another time

  introduction(objective); //userintroduction
  

do
{
  //initialize card number and suit
  playerSuit = (rand() % 4) + 1;
  compSuit = (rand() % 4) + 1;
  playerValue = (rand() % 13) + 1;
  compValue = (rand() % 13) + 1;

  //create output conditions for playersuit
  if (playerSuit == 1) playerSuitOutput = " of hearts.";
  else if (playerSuit == 2) playerSuitOutput = " of diamonds";
  else if (playerSuit == 3) playerSuitOutput = " of clubs";
  else playerSuitOutput = " of spades";

  //create output conditions for compsuit
  if (compSuit == 1) compSuitOutput = " of hearts.";
  else if (compSuit == 2) compSuitOutput = " of diamonds";
  else if (compSuit == 3) compSuitOutput = " of clubs";
  else if (compSuit == 4) compSuitOutput = " of spades";

  //create output conditions for player's card number
  if (playerValue == 1) playerValueOutput = "an Ace";
  else if (playerValue == 11) playerValueOutput = "a Jack";
  else if (playerValue == 12) playerValueOutput = "a Queen";
  else if (playerValue == 13) playerValueOutput = "a King";
  

  //create output conditions for computer's card number
  if (compValue == 1) compValueOutput = "an Ace";
  else if (compValue == 11) compValueOutput = "a Jack";
  else if (compValue == 12) compValueOutput = "a Queen";
  else if (compValue == 13) compValueOutput = "a King";
 
  
  //Now to actually "play the game"
  //Logic codeblock
  cout << endl;
  if (compValue >= 2 && compValue <= 10) cout << "Computer's card is a " << compValue << compSuitOutput << endl;
  else cout << "Computer's card is " << compValueOutput << compSuitOutput << endl;
  if (playerValue >= 2 && playerValue <= 10) cout << "Player's card is a " << playerValue << playerSuitOutput << endl;
  else cout << "Player's card is " << playerValueOutput << playerSuitOutput << endl;
  if (playerValue > compValue) cout << "Player wins!\n";
  else if (playerValue < compValue) cout << "Computer wins!\n";
  else 
  {
    cout << "It's a tie!\n";
  }
  //continue arg
  while(true)
  {
  cout << "\nContinue? [y/n]:";
  cin >> repeatGame;
  if (repeatGame == 'n') break;
  else if (repeatGame == 'y') break;
  }//while true input val continue game
}while (repeatGame == 'y');//while repeat game
 
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

