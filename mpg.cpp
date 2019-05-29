//Objective:  get keyboard input from the user to calculate the miles/gallon. 
//Name: Robert Loth
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iomanip>
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
  double miles; // distance in miles of the trip
  double range; // the maximum range of the car with the fuel remaining in the tank
  double capacity; // total capacity of the fuel tank
  double gallons; // the amount of fuel, in gallons, in the fuel tank, after the trip
  double mpg; // miles per gallon that the vehicle got during the trip
  
  

  
  
 
  // output my name and objective and program information
  cout << "Objective: This program will get keyboard input from the user to calculate the miles/gallon. \n"; 
  cout << "Programmer: Robert Loth\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //retreive data about the trip and the car
  
while(true)
{
  cout << "How many miles long was the trip?: ";
  cin >> miles;
  cin.ignore(1000,10);
  if (miles > 0) break;
  cout << "Please enter a value greater than 0.\n\n";
}  
while(true)
{
  cout << "How many gallons can your vehicle normally hold?: ";
  cin >> capacity;
  cin.ignore(1000,10);
  if (capacity > 0) break;
  cout << "Please enter a value greater than 0.\n\n";
}  
while(true)
{
  cout << "How many gallons of gas are currently in the tank?: ";
  cin >> gallons;
  cin.ignore(1000,10);
  
  if (capacity < gallons) cout << "The gallons currently in the tank must be lower than the capacity of " << capacity << " gallons.\n\n";
  else if (gallons > 0) break;
  
  else if (gallons < 0) cout << "Please enter a value greater than 0.\n\n";
}
  //perform mpg calculation
  mpg = miles / (capacity - gallons);

  //perform range calculation
 
 range = mpg * gallons;

  //output mpg and range
  cout << fixed << setprecision(2) <<"/nYou got "<< mpg << " miles per gallon during that trip.\n\n";
  cout << "With your current fuel reserve, you can travel an additional "<<  range << " miles before needing to refuel.\n";
   
 
} // main 
