//Objective:  Play a game of rock, paper, scissors between the computer and a human player.
//Track score, do not count ties, and output the numbers of computer wins and human wins after all play ends.
//Replay until the human player decides to quit.
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
//NONE 

//main program
int main()
{
  //Data
  char userPlay ;             // the user input that determines what hand they throw. Acceptable values R r, P p, S s, for rock paper scissors, or Q q, to quit
  int computerPlay ;          // randomly generated computer input that simulates an opponent's hand throw.
  int userScore = 0 ;         // Total amount of wins for the human player
  int computerScore = 0 ;     // Total amount of wins for the computer player
  srand(time(0)); rand();     // random number seed used in computerPlay
  int count = 0;              //number of games played
  char cont;              //tells the program whether to start a new match or not
  
  // output my name and objective and program information
  cout << "Objective: Play a game of rock, paper, scissors between the computer and a human player.\n"; 
  cout << "Programmer: Robert Loth\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl; 
do //used to repeat the game for any number of tries
{
  do  //input validation loop
  {
    // simulate the two hands, store results
    computerPlay = 1 + rand() % 2;
    cout << "\nChoose: [R=rock, P=paper, S=scissors, or Q=quit]:" ;
    cin >> userPlay; 
    cin.ignore(1000,10);
  
    // validate userPlay
      if (tolower(userPlay) == 'q') break;  // sentinel value to quit the program
      
  } while (tolower(userPlay) != 'r' && tolower(userPlay) != 'p' && tolower(userPlay) != 's');  //end of input validation loop    
   
  //determine winner, 1 = r; 2= p; 3 = s;
    
  
  //if tie
    if (computerPlay == 1 && tolower(userPlay) == 'r' || computerPlay == 2 && tolower(userPlay) == 'p' || computerPlay == 3 && tolower(userPlay) == 's') //if tie
    {
      if (computerPlay == 1)  // 1=r
      {
        cout << "Computer: R " << "Human: R" << ", " << "tie" << endl << endl;
      }// r tie
      else if (computerPlay == 2)  // 2=p
      {
        cout << "Computer: P " << "Human: P" << ", " << "tie" << endl << endl;
      }//p tie
      else
      {
        cout << "Computer: S " << "Human: S" << ", " << "tie" << endl << endl;
      }//s tie
      count = count + 1;
    }//end if tie 

 
  //if user wins
    else if (computerPlay == 1 && tolower(userPlay) == 'p' || computerPlay == 2 && tolower(userPlay) == 's' || computerPlay == 3 && tolower(userPlay) == 'r') //if user wins
    {
      if (computerPlay == 1)// 1=r
      {
        cout << "Computer: R " << "Human: " << userPlay << ", " << "You Win!" << endl << endl;
      }// r user wins
      else if (computerPlay == 2)// 2=p
      {
        cout << "Computer: P " << "Human: " << userPlay << ", " << "You Win!" << endl << endl;
      }//p user wins
      else
      {
        cout << "Computer: S " << "Human: " << userPlay << ", " << "You Win!" << endl << endl;
      }//s user wins
      userScore = userScore + 1;
      count = count + 1;
    }// end if user wins
  
    
  //if user loses
    else if (computerPlay == 1 && tolower(userPlay) == 's' || computerPlay == 2 && tolower(userPlay) == 'r' || computerPlay == 3 && tolower(userPlay) == 'p') //if user loses
    {
      if (computerPlay == 1)// 1=r
      {
        cout << "Computer: R " << "Human: " << userPlay << ", " << "You Lose!" << endl << endl;
      }// r user wins
      else if (computerPlay == 2)// 2=p
      {
        cout << "Computer: P " << "Human: " << userPlay << ", " << "You Lose!" << endl << endl;
      }//p user wins
      else
      {
        cout << "Computer: S " << "Human: " << userPlay << ", " << "You Lose!" << endl << endl;
      }//s user loses
      computerScore = computerScore + 1;
      count = count + 1;
    }  //end if user loses


    //ask to start a new game, validate Y/N input
    do
    {
      cout << "\n\nContinue? [Y/N]: ";
      cin >> cont;

      if (tolower(cont) == 'n' || tolower(cont) == 'y')  break;
      else cout << "Please enter either Y or N. \n\n";

    }while(true);  
  }while (tolower(cont) == 'y'); //end do while repeat whole game loop
      //closing statement
  cout << "Thank you for playing!\n";
  cout << "Final Score \n" << "Total Games: " << count << endl;
  cout << "Computer Wins: " << computerScore << "\nHuman Wins: " << userScore << "\nTies: " << count - userScore - computerScore;
  
} // main 
