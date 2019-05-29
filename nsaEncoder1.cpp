//Objective:  encodes a string from a text file using an algorithm
//Name: Robert Loth
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream>
#include <fstream> //using files as input
#include <string> // length command and getting characters in a string
using namespace std;

//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
void introduction(string obj); //program introduction
void nsaencoder(); // moves characters 1 up on the ASCII character list
//main program
int main()
{
  //Data
  string objective = "encodes a string from a text file using an algorithm.";

  //program introduction
  introduction(objective);
  nsaencoder();
}//main

//program introduction
void introduction(string obj)
{
  //Data
  //obj = the program objective (text)
  // output my name and objective and program information
  cout << "Objective: This program "; 
  cout << obj << endl;
  cout << "Programmer: Robert Loth\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 
}//introduction

void nsaencoder()
{
  //DATA
  ifstream fin; // sets input file stream to fin
  ofstream fout; // sets output file stream to fout
  int i; // loop index
  string s; // text file name
  string line; // string of a line in text file
  string encodedtxt; //result of encoding

  // Receive text input and open a user-chosen file
  cout << "Enter the full name, including .txt, of a text file you would like to encode.: ";
  cin >> s;
  cin.ignore(1000,10);
  fin.open(s.c_str());
  if (!fin.good()) throw "I/O error"; 
  fout.open("secrets.txt",ios::app); //create or append to a file called secrets.txt

  //perform encoding
  cout << "Encoding the contents of " << s << "...\n\n";
  while(getline(fin,line))
  {
    for (i = 0; i < line.length(); i = i+1)
    {
      
      line[i] = line[i] + 1; // bump the ASCII code by 1
    }// for encode one line
    
    //store encoded message in secrets.txt
    fout << line << endl; // add each encoded line to a file called secrets.txt
    cout << line << endl; // shows each line in console
  }//end while encode every line
//close input file and secrets.txt
fin.close();
fout.close();
}//end nsaencoder 
 
