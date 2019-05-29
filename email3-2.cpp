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
void processLines(string f); //opens a file as a string parameter, checks each line for email addresses, and outputs any email addresses found on that line.
bool isValidEmailChar (char c); // checks to see if the character is 0-9, a-z, A-Z, or _,-,+,. Returns true if one of those characters is found.

//main program
int main()
{
  //Data
  string objective = "receive a file name that you enter, find any @ signs in the file, and output the line that a @ sign is on, for every @ sign on the line.";
  introduction(objective); //userintroduction
  string iFileName = "fileContainingEmails.txt"; //input file name, received by user input
  string dFileName = "copyPasteMyEmails.txt"; //default output file name
  string oFileName; //output file name, received by user input
  

  cout << "Enter input filename [default: " << iFileName << "][press ENTER for default]: ";
  getline(cin,iFileName); 

  //input validation for input file
  iFileName = getFileName("input", iFileName);

  // opens file, checks, outputs lines, and closes file 
  processLines(iFileName); 
  
  /gets output file name
  dFileName = "copyPasteMyEmails.txt";
  cout << "Enter output filename [default: " << dFileName << "][press ENTER for default]: ";
  getline(cin,oFileName);
  oFileName = getFileName("output", oFileName);          // input validation for output file

  //outputs results
  cout << endl <<"Input file: " << iFileName << endl;
  cout << "Output file: " << oFileName << endl;
  cout << "Press [ENTER] to continue...";
  cin.ignore(1000,10);
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
  if (fileType == "output")
  { 
    if (def.length() == 0 ||!fileValid(def)) return "copyPasteMyEmails.txt";
    else return def;
  }//end if output
  else if (fileType == "input")
  { 
    if (def.length() == 0 ||!fileValid(def)) return "fileContainingEmails.txt";  
    else return def; 
  }//end if input 
}

bool isValidEmailChar(char c)
{
  bool validChar = false;
  if (c== '_' || c== '.' || c== '-' || c== '+') validChar = true;
  else if ( (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) validChar = true;
  else if ( (c >= '0') && (c <= '9')) validChar = true;
  return validChar;
} 
void processLines(string f)
{ 
  int i; //index variable in for loop
  int s; //finds the start of a valid email address
  int e; //finds the end of a valid email address
  bool hasDot; // searches the expanse of e (1 after the @) for a period character ".", returns true if found 
  int nEmailLine=0; // outputs the number of emails on one line
  int nEmailTotal=0; // outputs the total number of emails in the file.
  ifstream fin; // file input stream name
  string lineFromFile; // contains one line from string file at a time, used to output lines.
  string anEmail; // contains one email that has characters before and after the @ sign, and has a period after, but not adjacent to the @ sign.
  fin.open(f.c_str());
  if (!fin.good()) throw "IO error";
  while(!fin.eof())
  {
    getline(fin,lineFromFile);
    for (i = 0; i < lineFromFile.length(); i = i+1)
    { //search for @ sign
      if (lineFromFile[i] == '@')
      { 
        //search for start of valid email address
        s = i-1;
        while(isValidEmailChar(lineFromFile[s]))
        {
          s--;
        }//end while search for start
        s++;
        hasDot = false;
        
        //search for endd of valid email address
        e = i+1;
        while(isValidEmailChar(lineFromFile[e]))
        {
          if(lineFromFile[e] == '.' && lineFromFile[i+1] != '.') hasDot = true;
          e++;
        }//end while search for dot and end
        // cout << "E=" << e << "\nS=" << s << "\nI=" << i << endl;   //Used as a test to see if i, s, and e were functioning properly, remove first comment line to retest
        
        //output valid email addresses
        if (lineFromFile[i] == '@' && s < i && e > i && hasDot == true)
        {
          anEmail = lineFromFile.substr(s, e-s);
          cout << anEmail << "; ";
          nEmailLine++;
        }
      }//end while valid email character in start
    }//for each character in each line.
    cout << endl << "Number of emails in this line = " << nEmailLine << "\n\n";
    nEmailTotal += nEmailLine;   //add emails in a line to the total number of emails
    nEmailLine = 0;              //reset nEmailLine for the next line
  }//while not eof, each line
  cout << "\n" << "Number of emails in the whole file = " << nEmailTotal << "\n\n";
  fin.close();
}                       