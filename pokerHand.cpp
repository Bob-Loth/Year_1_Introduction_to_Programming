//Objective:  Draw 5 cards
//Name: Robert Loth
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
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
  //NONE

  // output my name and objective and program information
  cout << "Objective: This program will draw 5 cards.\n"; 
  cout << "Programmer: Robert Loth\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl; 
//Poker draw


  srand(time(0)); rand(); // "seed" the random number generator
  int n = 5; // deal this many cards
  for (int i = 0; i < n; i++) //count
  {
    int value = 1 + rand() % 13;
    int suit  = rand() % 4;
    switch (value)
    {
      case 1:
        cout << "Ace";
        break;
      case 11:
        cout << "Jack";
        break;
      case 12:
        cout << "Queen";
        break;
      case 13:
        cout << "King";
        break;
      default:
        cout << value;
    } // switch
    switch (suit)
    {
      case 0:
        cout << " of Spades" << endl;
        break;
      case 1:
        cout << " of Hearts" << endl;
        break;
      case 2:
        cout << " of Diamonds" << endl;
        break;
      case 3:
        cout << " of Clubs" << endl;
    } // switch
  } // for
} // main
// Running this program in quick succession will produce identical results