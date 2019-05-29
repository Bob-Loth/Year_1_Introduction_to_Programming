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


//Programmer defined functions
void introduction(string obj); // user introduction
void ValueSuit(PlayingCard *compCard, PlayingCard *playerCard); // take PlayingCard and output its suit and value in the format: [value] of [suit]
bool GetYesOrNo();
//main program
int main()
{
  //Data
  string objective = "  play the card game of War."; //program objective
  srand(time(0));               // seed rng
  PlayingCard card[52];         //each card in the deck, in order, randomized selection later
  const int SIZE = 26;          //size of the player/computer array
  PlayingCard compCard[SIZE];   //card that the computer has used
  PlayingCard playerCard[SIZE]; //cards that the player has used
  PlayingCard alreadyPlayed[52];//resets upon filling
  int nCard=0;                  //keeps track of the number of cards played
  
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

//Picks a "random" card from the list. In order to simplify and speed up the loop, I added a non-random modification so it wouldn't try looping 500 times before finally picking the last unique card.
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
    
  //Name the computer's card, and output a readable label
  ValueSuit(&compCard[nCard], &playerCard[nCard]);
    
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

void ValueSuit(PlayingCard *compCard, PlayingCard *playerCard)
{
  int playerWins;
  int compWins;
  if (compCard->value == 11)
    {
      cout << "Computer's card is a Jack of " << compCard->suit << endl;
    }//if jack
    else if (compCard->value == 12)
    {
      cout << "Computer's card is a Queen of " << compCard->suit << endl;
    }//if queen
    else if (compCard->value == 13)
    {
      cout << "Computer's card is a King of " << compCard->suit << endl;
    }//if king
    else if (compCard->value == 14)
    {
      cout << "Computer's card is an Ace of " << compCard->suit << endl;
    }//if ace
    else cout << "Computer's card is a " << compCard->value << " of " << compCard->suit << endl;

    //Name the player's card, and output a readable label
    if (playerCard->value == 11)
    {
      cout << "Player's card is a Jack of " << playerCard->suit << endl;
    }//if jack
    else if (playerCard->value == 12)
    {
      cout << "Player's card is a Queen of " << playerCard->suit << endl;
    }//if queen
    else if (playerCard->value == 13)
    {
      cout << "Player's card is a King of " << playerCard->suit << endl;
    }//if king
    else if (playerCard->value == 14)
    {
      cout << "Player's card is an Ace of " << playerCard->suit << endl;
    }//if ace
    else cout << "Player's card is a " << playerCard->value << " of " << playerCard->suit << endl;
    cout << "-->--\n";
    if (playerCard->value > compCard->value)
      playerWins++;
    else if (playerCard->value < compCard->value)
      compWins++;
    else 
      cout << "It's a tie!\n";
    cout << "Computer wins: " << compWins << ", Human wins: " << playerWins << endl;  
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