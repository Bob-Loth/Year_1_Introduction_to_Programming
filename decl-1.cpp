//Objective:  template for C++ programs and to test code
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
  int luckyNumber;      //positive whole number
  string favoriteMovie; // favorite movie, string value
  int age;              // in years, whole numbers
  char firstLetterName; // first letter of first name

  // output my name and objective and program information
  cout << "Objective: This program will serve as a template for all programs.\n written in this course.\n"; 
  cout << "Programmer: Robert Loth\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //receive input from keyboard
  cout << "What is your lucky number? (pick a positive whole number): ";
  cin >> luckyNumber;
  cin.ignore(1000,10);
  
  cout << "What is your favorite movie? ";
  getline(cin,favoriteMovie);
  
  cout << "What is your age in whole years? (0-122):";
  cin >> age;
  cin.ignore(1000,10);

  cout << "what is the first letter of your first name?: ";
  cin >> firstLetterName;
  cin.ignore(); 

  //output the keyboard input in readable formatting
  cout << endl << endl << "Your lucky number is " << luckyNumber << "." << endl;
  cout << "Your favorite movie is " << favoriteMovie << "." << endl;
  cout << "You are " << age << " years old." << endl;
  cout << "The first letter of your first name is " << firstLetterName << "." << endl;

  

}//main