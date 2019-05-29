//Objective: read all song titles from a text file,
//and randomly select and output titles in a loop until the user wishes to stop. 
//Name: Robert Loth
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream> // console input and output
#include <deque> //used to create and maintain collections
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
string getFileName (string fileType, string& console, string& dFileName);
bool fileValid(string file); //checks to see if it is a string of 5 characters or greater, and that the last 4 characters are ".txt"
void processLines(deque<string>& nonDupe, string f); //opens a file as a string parameter, checks each line for email addresses, and outputs any email addresses found on that line.
bool isValidEmailChar (char c); // checks to see if the character is 0-9, a-z, A-Z, or _,-,+,. Returns true if one of those characters is found.
void isDuplicate(deque<string>& nonDupe, string aEmail); //checks anEmail whether it is a duplicate email address using case sensitive comparison to create list of non-duplicate email addresses
string changeCase(string s); // converts string to all one case for case dependent comparisons
void sortList(deque<string>& nonDupe, deque<string>& nonDupeAlpha); //sorts the nonDupe list into alphabetical order, and passes it by reference back to main.
void outputList(deque<string> nonDupe, string iFileName, string oFileName); //outputs the sorted nonDupe list to a file of the user's choosing, properly formatted.


//main program
int main()
{
  //Data
  string objective = "Produce a list of valid, nonduplicate email addresses from a given file, display them in a sorted list, and output that sorted list to a specified output file.";
  introduction(objective); //userintroduction
  string iFileName; //input file name, received by user input
  string dFileName = "fileContainingEmails.txt"; //default output file name
  string oFileName; //output file name, received by user input
  int i = 0; //index file used to output all nonduplicate email addresses
  deque<string> nonDupe; // contains all nonduplicate values of the duplicate
  deque<string> nonDupeAlpha; // used to sort in alphabetical order the values of nonDupe

  //gets input file name
  cout << "Enter input filename [default: " << dFileName << "][press ENTER for default]: ";
  getline(cin,iFileName); 

  //input validation for input file
  iFileName = getFileName("input", iFileName, dFileName);
  if (iFileName == dFileName)
  {
    dFileName = "copyPasteMyEmails.txt";
  }//if default
  else 
  {
    dFileName = iFileName;
  }//else 
  // opens file, checks for valid, nonduplicate emails, saves emails to nonDupe list, and closes file 
  processLines(nonDupe, iFileName); 
  
  //sorts nonDupe list into alphabetical order
  sortList(nonDupe, nonDupeAlpha);

  //output non-duplicate emails from collection to console
  for (i=0; i < nonDupe.size(); i++)
  {
    if (i+1 == nonDupe.size()) cout << nonDupe[i] << endl << endl;
    else cout << nonDupe[i] << ";\n";
  }
  
  //gets output file name
  cout << "Enter output filename [default: " << dFileName << "][press ENTER for default]: ";
  getline(cin,oFileName);
  
  // input validation for output file
  oFileName = getFileName("output", oFileName, dFileName);          

  //outputs results
  outputList(nonDupe, iFileName, oFileName);
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

//checks for valid file, details on valid file characters in comments below
bool fileValid(string file) 
{ //This function is used in getFileName, input parameter is either iFileName or oFileName
  //file name must be 5 characters or greater, the last 4 characters must be ".txt"
  //file name must not contain <,>,:,",/,|,?, or * characters
  //file name must not start or end with .,-,_, or space characters
  //if any of these conditions are not satisfied, the function returns false.
                          
  bool ValidCheck = true;
  string f = file;
  int lFile = f.length();
  int i;
  if(lFile < 5) ValidCheck = false;
  else if (f[lFile-1] != 't' || f[lFile-2] != 'x' || f[lFile-3] != 't' || f[lFile-4] != '.') ValidCheck = false;
  for (i=0; i<lFile; i++)
  {
    if (i >= 128 || f[i] == '<' || f[i] == '>' || f[i] == ':' || f[i] == '"') ValidCheck = false;
    else if (f[i] == '|' || f[i] == '?' || f[i] == '*' || f[i] == '/') ValidCheck = false;
  }//end for  
  if (f[0] == ' ' || f[0] == '.' || f[0] == '-' || f[0] == '_') ValidCheck = false;
  if (f[lFile-1] == ' ' || f[lFile-1] == '.' || f[lFile-1] == '-' || f[lFile-1] == '_') ValidCheck = false;

  return ValidCheck;
}

//uses fileValid() to either output a default file if the file was invalid, or output the user-chosen file if the file was valid.     
string getFileName (string fileType, string& console, string& dFileName)
{  
  //output tree
  if (fileType == "output")
  { 
    if (console.length() == 0 ||!fileValid(console)) 
    {
      return dFileName;
    }//if invalid file input
    else 
    {
      return console;
    }//if valid file input
  }//end if output

  //input tree
  else if (fileType == "input")
  { 
    if (console.length() == 0 ||!fileValid(console)) 
    {
      return dFileName;  
    }//invalid, default
    else
    {
      return console; 
    }//valid file found
  }//end if input 
}
//Checks a character to see if it is a valid email character. Used in s and e loops in processLine to find bounds of valid email address.
bool isValidEmailChar(char c)
{
  bool validChar = false; //default is false, true if the character is an accepted, valid character.

  if (c== '_' || c== '.' || c== '-' || c== '+') validChar = true;
  else if ( (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) validChar = true;
  else if ( (c >= '0') && (c <= '9')) validChar = true;
  return validChar;
} 

// opens file, checks for valid, nonduplicate emails, saves unsorted emails to nonDupe list, and closes file 
void processLines(deque<string>& nonDupe,string f)
{ 
  int i; //index variable in for loop
  int s; //finds the start of a valid email address
  int e; //finds the end of a valid email address
  bool hasDot; // searches the expanse of e (1 after the @) for a period character ".", returns true if found 
  ifstream fin; // file input stream name
  string lineFromFile; // contains one line from string file at a time, used to output lines.
  string anEmail; // contains one email that has characters before and after the @ sign, and has a period after, but not adjacent to the @ sign.
  
  //open input file and check each line for @ character, and perform additional checks if @ is found. No action otherwise
  fin.open(f.c_str());
  if (!fin.good()) throw "IO error";
  while(!fin.eof())
  {
    getline(fin,lineFromFile);
    for (i = 0; i < lineFromFile.length(); i++)
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

        //search for end of valid email address
        e = i+1;
        while(isValidEmailChar(lineFromFile[e]))
        {
          if(lineFromFile[e] == '.' && e > i+1) hasDot = true;
          e++;
        }//end while search for dot and end
         
        //output valid email addresses
        if (lineFromFile[i] == '@' && s < i && e > i && hasDot == true)
        {
          anEmail = lineFromFile.substr(s, e-s);
          isDuplicate(nonDupe, anEmail);
        } //end if lineFromFile is email address
      }//end if invalid email character in start
    }//for each character in each line.
  }//while not eof, each line
  fin.close();
}//processLine              
void isDuplicate (deque<string>& nonDupe, string aEmail)
{
  int k=0;// index variable
  bool duplicateFound = false;
  if (nonDupe.size() == 0)
  {
    nonDupe.push_front(aEmail);
  }//if first time
  else
  {
    for (k=0; k < nonDupe.size(); k++)
    {  
    
      if (changeCase(aEmail) == changeCase(nonDupe[k])) 
      {
         duplicateFound = true;
         break;
      }//if duplicate
    }//for all values in nonDupe
    if (!duplicateFound) 
    {
      nonDupe.push_back(aEmail);
    }//if unique email
  }//else second+ time
}//isDuplicate
string changeCase(string s)
{
  string capslock; // returns the string with all characters in uppercase
  int i; // index used in for loop
  for(i = 0; i < s.length(); i++) 
  {
    s[i] = toupper(s[i]);
  }//end for string tolower
  capslock = s;
  return capslock;
}//changeCase


void sortList(deque<string>& nonDupe, deque<string>& nonDupeAlpha)
{
  
  int i;// outer loop
  int j;// inner loop
  int k;//populating nonDupeAlpha
  string temp;// sorting for mirror
  string temp2;// sorting for original

  //create a mirrored list of email addresses in all caps
  for (k=0; k < nonDupe.size(); k++)
  {
    nonDupeAlpha.push_back(changeCase(nonDupe[k]));
  }//for k populating alpha

  //sort both the original and the mirror according to the mirror's parameters
  for (i=0; i < nonDupe.size(); i++)
  {
    for (j = i+1; j < nonDupe.size(); j++)
    {
      if (nonDupeAlpha[i] > nonDupeAlpha[j])
      {
        temp = nonDupeAlpha[i];
        temp2 = nonDupe[i];
        nonDupeAlpha[i] = nonDupeAlpha[j];
        nonDupe[i] = nonDupe[j];
        nonDupeAlpha[j] = temp;
        nonDupe[j] = temp2;
      }
    }//for j inner
  }//for i outer

}//sortList

void outputList(deque<string> nonDupe, string iFileName, string oFileName)
{
  ofstream fout; //set file output stream variable
  int m=0; //index variable

  //Open oFileName and write the sorted nonduplicate email addresses to it.
  if (nonDupe.size()!=0)
  {
    cout << "Writing to " << oFileName << "...\n";
    fout.open(oFileName.c_str());
    for (m=0; m < nonDupe.size(); m++)
    {
      if (m+1 == nonDupe.size()) fout << nonDupe[m];
      else fout << nonDupe[m] << "; ";
    }//for m
  }//if no emails in file, do not open file
  //User instructions on how to use the file
  else
  {
    cout << endl << "There were no valid email addresses in "<<iFileName<<".  " << "Please check that the file name is correct, ends in .txt, and it contains email addresses.";
  }//output error when no email addresses found
  if (nonDupe.size()!=0)
  {
    cout << endl << nonDupe.size() << " emails were found in "<<iFileName<<" and written to " << oFileName << ". They have been sorted alphabetically, and duplicate email addresses were removed.";
    cout << endl << "You can now copy and paste the contents of "<< oFileName << " into any fields that require multiple email addresses. \n";
    cout <<  "Simply open "<<oFileName<<", hit ctrl+a, then hit ctrl+c. Close the file, select any email field, then hit ctrl+v.\n";
  }//else emails were found
  fout.close();
}//outputList





         