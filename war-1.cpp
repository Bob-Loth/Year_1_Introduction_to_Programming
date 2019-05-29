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
struct PlayingCard
{
  string suit; // 0 = spades, 1 = diamonds, 2 = hearts, 3 = clubs
  int value;// 2-10 = 2-10, 11 = jack, 12 = queen, 13 = king, 14 = ace
  int rand;//
};

//Special compiler dependent definitions
//NONE ch 7/8

//global constants/variables
//NONE ch 13

//Programmer defined functions
void introduction(string obj); // user introduction
void ValueSuit(int *PlayingCard); // take PlayingCard and output its suit and value in the format: [value] of [suit]
bool GetYesOrNo();
//main program
int main()
{
  //Data
  string objective = "  play the card game of War."; //program objective
  srand(time(0)); // seed rng
  PlayingCard card[52];
  const int SIZE = 26;
  PlayingCard compCard[SIZE];
  PlayingCard playerCard[SIZE];
  PlayingCard alreadyPlayed[52];
  int nCard=0;
  int playerWins=0;
  int compWins=0;
  introduction(objective); //userintroduction
   
//initialize card number and suit, creates a sorted deck.
  for (int i=0; i<52; i++)
  {
    if (i<13)
    {
      card[i].suit = "Spades";
      card[i].value = i+2;
      
    }//if spades
    else if (i<26)
    {
      card[i].suit = "Diamonds";
      card[i].value = i-11;
    }//if diamonds
    else if (i<39)
    {
      card[i].suit = "Hearts";
      card[i].value = i-24;
    }//if heartsy
    else
    {
      card[i].suit = "Clubs";
      card[i].value = i-37;
    }//else clubs
  }//end for
do
{
    int rand10 = (rand() % 10) + 1; // random number 1-10
    nCard=0;
    do
    {
      int rand52 = rand() % 52;
      playerCard[nCard] = card[rand52];
      if (alreadyPlayed[nCard].suit == playerCard[nCard].suit && alreadyPlayed[nCard].value == playerCard[nCard].value)
      {
        if (rand10 <=5) playerCard[nCard] = card[rand52 - 1];
        else playerCard[nCard] = card[rand52 + 1];
      }
    }while (alreadyPlayed[nCard].suit == playerCard[nCard].suit && alreadyPlayed[nCard].value == playerCard[nCard].value);
    alreadyPlayed[nCard] = playerCard[nCard];

    do
    {
      int rand52 = rand() % 52;
      compCard[nCard] = card[rand52];
      if (alreadyPlayed[nCard].suit == compCard[nCard].suit && alreadyPlayed[nCard].value == compCard[nCard].value)
      {
        if (rand10 <=5) compCard[nCard] = card[rand52 - 1];
        else compCard[nCard] = card[rand52 + 1];
      }
    }while (alreadyPlayed[nCard].suit == compCard[nCard].suit && alreadyPlayed[nCard].value == compCard[nCard].value);  
    alreadyPlayed[nCard] = compCard[nCard];
    
    if (compCard[nCard].value == 11)
    {
      cout << "Computer's card is a Jack of " << compCard[nCard].suit << endl;
    }//if jack
    else if (compCard[nCard].value == 12)
    {
      cout << "Computer's card is a Queen of " << compCard[nCard].suit << endl;
    }//if queen
    else if (compCard[nCard].value == 13)
    {
      cout << "Computer's card is a King of " << compCard[nCard].suit << endl;
    }//if king
    else if (compCard[nCard].value == 14)
    {
      cout << "Computer's card is an Ace of " << compCard[nCard].suit << endl;
    }//if ace
    else cout << "Computer's card is a " << compCard[nCard].value << " of " << compCard[nCard].suit << endl;


    if (playerCard[nCard].value == 11)
    {
      cout << "Player's card is a Jack of " << playerCard[nCard].suit << endl;
    }//if jack
    else if (playerCard[nCard].value == 12)
    {
      cout << "Player's card is a Queen of " << playerCard[nCard].suit << endl;
    }//if queen
    else if (playerCard[nCard].value == 13)
    {
      cout << "Player's card is a King of " << playerCard[nCard].suit << endl;
    }//if king
    else if (playerCard[nCard].value == 14)
    {
      cout << "Player's card is an Ace of " << playerCard[nCard].suit << endl;
    }//if ace
    else cout << "Player's card is a " << playerCard[nCard].value << " of " << playerCard[nCard].suit << endl;
    cout << "-->--\n";
    if (playerCard[nCard].value > compCard[nCard].value)
      playerWins++;
    else if (playerCard[nCard].value < compCard[nCard].value)
      compWins++;
    else 
      cout << "It's a tie!\n";
    cout << "Computer wins: " << compWins << ", Human wins: " << playerWins << endl;
    
}while (GetYesOrNo());//while true repeat game

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

void ValueSuit(struct PlayingCard)
{
    
}

bool GetYesOrNo()  // determines if game is played another time
{
  char repeatGame; 
  while(repeatGame != 'n' || repeatGame != 'y')
  {
  cout << "\nContinue? [y/n]:";
  cin >> repeatGame;
  cin.ignore(1000,10);
  if (repeatGame == 'y') return true;
  else if (repeatGame == 'n') return false;
  }//while true input val continue game
  
}