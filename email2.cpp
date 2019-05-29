//Objective: read all song titles from a text file,
//and randomly select and output titles in a loop until the user wishes to stop. 
//Name: Robert Loth
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream> // console input and output
#include <fstream> // file input
#include <string> // .length() command 
using namespace std; 

//Programmer defined data types
//NONE ch 13

//Special compiler dependent definitions
//NONE ch 7/8

//global constants/variables
//NONE ch 13

//Programmer defined functions
void introduction(string obj); // user introduction
string getFileName (string fileType, string def);
bool fileValid(string file); //checks to see if it is a string of 5 characters or greater, 
                             //and that the last 4 characters are ".txt"
void processLines(string f); //opens a file as a string parameter, 

//main program
int main()
{
  //Data
  string objective = "receive a file name that you enter, find any @ signs in the file, and output the line that a @ sign is on, for every @ sign on the line.";
  introduction(objective); //userintroduction
  string iFileName; //input file name, received by user input
  string dFileName = "fileContainingEmails.txt"; //default input file name
  string oFileName; //output file name, received by user input
  string enterToContinue; // used at end of program to wait indefinitely


  cout << "Enter input filename [default: " << dFileName << "][press ENTER for default]: ";
  processLines(getFileName("input",dFileName)); // opens, checks, outputs lines, and closes, 4 in 1 
  cout << "Enter output filename [default: " << dFileName << "][press ENTER for default]: ";
   
  cout << endl <<"Input file: " << getFileName("input",getFileName("input",iFileName)) << endl;
  cout << "Output file: " << getFileName("output",getFileName("output",oFileName)) << endl;
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

bool fileValid(string file) 
{ // file name must be 5 characters or greater, the last 4 characters must be ".txt"
  //file name must not contain <,>,:,",/,|,?, or * characters
  //file name must not start or end with .,-,_, or space characters
  // if any of these conditions are not satisfied, the function returns false.
                          
  bool ValidCheck = true;
  string f = file;
  int lFile = f.length();
  int i;
  if(lFile < 5) ValidCheck = false;
  else if (f[lFile-1] != 't' || f[lFile-2] != 'x' || f[lFile-3] != 't' || f[lFile-4] != '.') ValidCheck = false;
  for (i=0; i<lFile; i++)
  {
    if (i >= 128 || f[i] == '<' || f[i] == '>' || f[i] == ':' || f[i] == '"') ValidCheck = false;
    else if (f[i] == '/' ) ValidCheck = false;
    else if (f[i] == '|' || f[i] == '?' || f[i] == '*' ) ValidCheck = false;
  }//end for  
  if (f[0] == ' ' || f[0] == '.' || f[0] == '-' || f[0] == '_') ValidCheck = false;
  if (f[lFile-1] == ' ' || f[lFile-1] == '.' || f[lFile-1] == '-' || f[lFile-1] == '_') ValidCheck = false;

  return ValidCheck;
}     
string getFileName (string fileType, string def)
{  
  //DATA
  string iFileName; //input file name, received by user input
  string oFileName; //output file name, received by user input
  string ireturnedValue;
  string oreturnedValue;
  
  if (fileType == "output")
  { 
    getline(cin,oFileName);
    
    if (oFileName.length() == 0 || !fileValid(oFileName))
    {
      oreturnedValue = "copyPasteMyEmails.txt";
    }//if valid
    else 
    {
      oreturnedValue = oFileName;
    }//end else
    return oreturnedValue;
  }//end if output

  else if (fileType == "input")
  {  
    getline(cin,iFileName);
  
    if (iFileName.length() == 0 || !fileValid(iFileName))
    {
      iFileName = ireturnedValue;
      ireturnedValue = "fileContainingEmails.txt";  
    }//if enterkey
    else
    {
      ireturnedValue = iFileName;
    }//end else enterkey false
    return ireturnedValue;  
  }//end if input
   
    
}
void processLines(string f)
{ 
    int i; //index variable in for loop
  ifstream fin; // file input stream name
  string line; // contains one line from string file at a time, used to output lines.
  fin.open(f.c_str());
  if (!fin.good()) throw "IO error";
  while(!fin.eof())
  {
    getline(fin,line);
    for (i = 0; i < line.length(); i = i+1)
    {
      if (line[i] == '@')
      {
        cout << line << endl;
      }//end if output line if it contains @ sign
    }//for each character in each line.
  }//while not eof, each line
  fin.close();
}                       