//Objective: read all song titles from a text file,
//and randomly select and output titles in a loop until the user wishes to stop. 
//Name: Robert Loth
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <string> // .length() command 
#include <iostream> //console input and output
using namespace std; 

//Programmer defined data types
//NONE ch 13

//Special compiler dependent definitions
//NONE ch 7/8

//global constants/variables
//NONE ch 13

//Programmer defined functions
void introduction(string obj); // user introduction
bool fileValid(string file); //checks to see if it is a string of 5 characters or greater, 
                             //and that the last 4 characters are ".txt"

//main program
int main()
{
  //Data
  string objective = "receive input and output file names as part of a larger program.";
  introduction(objective); //userintroduction
  string iFileName= "aa.txt"; //input file name, received by user input
  string dFileName = "fileContainingEmails.txt"; //default input file name
  string oFileName; //output file name, received by user input
  bool enterKey = false; // if true, uses the default file names.
  string enterToContinue; // used at end of program to wait indefinitely
  
  
    cout << "Enter input filename [default: " << dFileName << "]: ";
    getline(cin,iFileName);
  
    
  
  if (iFileName.length() == 0)
  {
    enterKey = true;
  }//if length iFileName
  else enterKey = false;
  if (enterKey || !fileValid(iFileName))
  {
     if (enterKey) cout << "Using default filename.\n";
     else if (!fileValid(iFileName)) cout << "Incorrect filename entered, using default filename.\n";
     iFileName = dFileName;
     dFileName = "copyPasteMyEmails.txt";
     
  }//if enterkey
  else
  {
    dFileName = iFileName;
  }//end else enterkey false
  enterKey = false;

  
    cout << "Enter output filename [default: " << dFileName << "]: ";
    getline(cin,oFileName);
  
  if (oFileName.length() == 0)
  {
    enterKey = true;
  }//if length oFileName
  if (enterKey || !fileValid(oFileName))
  {
    if (enterKey) cout << "Using default filename.\n";
    else if (!fileValid(oFileName)) cout << "Incorrect filename entered, using default filename.\n";
    oFileName = dFileName;
  }
  
  cout << "Input file: " << iFileName << endl;
  cout << "Output file: " << oFileName << endl;
  cout << "Press [ENTER] to continue...";
  getline(cin, enterToContinue);
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

bool fileValid(string file) //checks to see if it is a string of 5 characters or greater, 
{                             //and that the last 4 characters are ".txt"
  bool ValidCheck = true;
  string f = file;
  int lFile = f.length();

  if(lFile < 5) ValidCheck = false;
  else if (f[lFile-1] != 't' || f[lFile-2] != 'x' || f[lFile-3] != 't' || f[lFile-4] != '.') ValidCheck = false;
  return ValidCheck;
}                            