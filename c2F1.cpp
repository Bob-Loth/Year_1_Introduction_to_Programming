//Objective:  convert fahrenheit to celsius temperature from a text file.
//Name: Robert Loth
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <fstream> //using files as input
#include <iomanip> //using formatting
#include <iostream>//using output
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
  double c; // degrees Celsius
  double f; // degrees Fahrenheit
  ifstream fin; // sets input file stream to fin
  string temp = "temps.txt"; // file containing celsius temperatures to be converted
  string waiting; // waits for user to hit enter before starting program
  // output my name and objective and program information
  cout << "Objective: This program will convert fahrenheit to celsius temperature."; 
  cout << "Programmer: Robert Loth\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl; 
  //wait for user
  cout << "Reading from temps.txt. Please ensure that each temp is in degrees C and each is on a separate line. a value of -999 in temps.txt will signal the program to end at that line.";
  cin >> waiting;
  // receive file input for multiple degrees Celsius
  fin.open(temp.c_str());
  if (!fin.good()) throw "I/O error"; 

  //convert temperature and output results  
  while (fin.good())
  {
    fin >> c;
    fin.ignore(1000, 10);
    if (c == -999) break;
    // convert temperature
    f = ((9.0 / 5.0)* c) + 32;
    cout.setf(ios::fixed|ios::showpoint);
    cout << "  Temperature in F: " ;
    cout << setprecision(1) << f << setprecision(6);
    cout.unsetf(ios::fixed|ios::showpoint);
    cout << "  Temperature in C: " <<  c << " degrees.\n";
    
}//end while fin.good()
  
  


}//main