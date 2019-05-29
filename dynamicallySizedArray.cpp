//Objective:  provide basic stats on a dynamic series of test scores
//Name: Robert Loth
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream>
using namespace std;
 

#include <cmath>


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
  string objective = "provide basic stats on a dynamic series of test scores"; //program objective
  int size = 0; // number of elements in array
  int* array-Scores[]; //array containing scores
  int max; //highest score in array
  int min; //lowest score in array
  int sum; // sum of all scores
  double average; // average of all scores
  int nGradeA = 0; // number of scores 90 or above
  int temp; // temporary variable used in sorting and input
  int i;//index variable 1
  int j;//index variable 2

  introduction(objective); //userintroduction

  //get user input until -99 is pressed and add valid values to array-Scores
  while (temp !=-99) //while input loop
  {
    cout << endl << " enter a score [0-100] or hit -99 to finish: ";
    cin >> temp;
    cin.ignore();
    if (temp = -99) break;
    if else (temp < 0 || temp > 100) cout << "Try again [0-100]: "
    else //add to array
    {
      array-Scores[] = temp; //adds temp to the next empty space in dynamic array
      size++;
    }//end else add to array
 
 }//end while input loop 

//Continue from here, finished up to input by 1:30pm
 
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

