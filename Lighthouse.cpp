//Objective:  calculate the visibility distance in miles from the height of a lighthouse of a given height in feet.
//Name: Robert Loth
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iomanip>
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
//NONE 

//main program
int main()
{
  //Data
  double height;   // height of lighthouse in decimal feet
  double distance; // distance between lighthouse and boat, in miles

  // output my name and objective and program information
  cout << "Objective: This program will calculate the visibility distance in miles from the height of a lighthouse of a given height in feet.\n"; 
  cout << "Programmer: Robert Loth\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl; 
  
  //ask for height, store height
  cout << "This program will calculate the distance, in miles, from which a boat can see a lighthouse, based on the lighthouses height, in feet." << endl;
  cout << "What is the height of the lighthouse, in decimal feet? ";
  cin >> height;
  cin.ignore(1000,10);

  //calculate to get distance, store distance
  distance = sqrt( 0.8 * height );

  //output result in readable format
  cout << fixed;
  cout << endl << setprecision(3) << "A lighthouse that is " << height;
  cout << " feet tall will provide light to boats that are up to "<< setprecision(0) << distance <<" miles away." << endl;

}//main