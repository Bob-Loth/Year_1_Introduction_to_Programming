//Objective:  Calculate the average height of everyone in the classroom.
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
  double sum = 0.0; //the sum of all heights currently added
  int count = 0; // the amount of people in the room
  double averageHeight = 0; // the average height of everyone in the room
  int height; // each individual height, replaced each entry
  
  

  // output my name and objective and program information
  cout << "Objective: Calculate the average height of everyone in the classroom.\n"; 
  cout << "Programmer: Robert Loth\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  cout << "This program is going to be used to calculate the average height of everyone in the room." << endl << endl;
  cout << "This program will not work if there are no people in the room. How many people are in the room? ";
  cin >> count;
  cin.ignore(1000,10);
  int i = 0;
  while( i < count )
  {  
    cout << "What  is person "<< i+1 << "'s height in inches,";
    cout << " rounded down to the nearest whole inch? Acceptable inputs [20-100] ";
    cin >> height;
    cin.ignore(1000,10);
    cout << endl;
    if (height >= 20 && height <=100) 
    {
      sum = sum + height;
      i++;
    }//validate input range true
    else
    {
      cout << "Try entering the value again. 20-100 inches: We will return to the original prompt. \n \n";
    }//validate input range false
  }//while
  

  if(count <= 0)
  cout << "Why would you do this? There must be someone in the room.";

  else 
  {
    averageHeight = sum / count;
    cout << "There are " << count << " people in the room." << endl << "The average height of everyone in the room is " << averageHeight << " inches.";
  }
}//main