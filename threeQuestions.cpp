//Objective:  
//Name: Robert Loth
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream> // for input and output 
using namespace std;
 

#include <cctype>


//Programmer defined data types
//NONE ch 13

//Special compiler dependent definitions
//NONE ch 7/8

//global constants/variables
//NONE ch 13

//Programmer defined functions
void introduction(string obj); // user introduction
void threeQuestions(); // asks 3 questions and returns the amount of correct answers

//main program
int main()
{
  //Data
  string objective = "use a subprogram that asks questions and returns a score"; //program objective
  
  introduction(objective); //userintroduction
  
  threeQuestions(); //asks questions and returns score

 
 
    
 
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

void threeQuestions()
{
  //data
  char answer1 = 'F'; //true answer to first question
  char answer2 = 'C'; //true answer to second question
  char answer3 = 'C'; //true answer to third question
  char userAnswer1; // user's answer to first question
  char userAnswer2; // user's answer to second question
  char userAnswer3; // user's answer to third question
  bool bool1 = false; // checks if first question was answered correctly
  bool bool2 = false; // checks if second question was answered correctly
  bool bool3 = false; // checks if third question was answered correctly
  int score = 0; // number of questions answered correctly

  //receive userAnswer1
  cout << "\n\n" << "What letter represents 15 in the hexadecimal system?: ";
  cin >> userAnswer1;
  cin.ignore(1000,10);
  
  //verify userAnswer1
  if (toupper(userAnswer1) == answer1)
  {
    cout << "Correct!\n";
    bool1 = true;
  }
  if (bool1) score = score + 1;
  cout << "That's "<< score << " correct so far.\n\n";

//receive userAnswer2
  cout << "\n\n" << "Floating point numbers have limitations on their:\nA: Precision\nB: Accuracy \nC: Both \nD: Neither\n\n";
  cin >> userAnswer2;
  cin.ignore(1000,10);
  
  //verify userAnswer2
  if (toupper(userAnswer2) == answer2)
  {
    cout << "Correct!\n";
    bool2 = true;
  }
  if (bool2) score = score + 1;
  cout << "That's "<< score << " correct so far.\n\n";
//receive userAnswer3
  cout << "\n\n" << "What is 14(decimal) in Binary?\nA:1010 \nB:1001 \nC:1110\n";
  cin >> userAnswer3;
  cin.ignore(1000,10);
  
  //verify userAnswer3
  if (toupper(userAnswer3) == answer3)
  {
    cout << "Correct!\n";
    bool3 = true;
  }
  if (bool3) score = score + 1;
  cout << "That's "<< score << " correct out of 3 questions asked.\n";
  if (score == 3) cout << "Congratulations!\n";
  
}