//Objective:  decodes a string from a text file using an algorithm
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
void nsadecoder(); // moves characters 1 down on the ASCII character list
//main program
int main()
{
  //Data
  string objective = "decodes a string from a text file using an algorithm.";

  //program introduction
  introduction(objective);
  nsadecoder();
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

void nsadecoder()
{
  //DATA
  ifstream fin; // sets input file stream to fin
  ofstream fout; // sets output file stream to fout
  int i; // loop index
  string s = "secrets.txt"; // text file
  string line; //current encoded line from secrets.txt
  const int SIZE = 5;
  int offset[SIZE] = {-5, 8, 12, 6, 1}; // encryption "key"
  int index = i % SIZE; // used to return a sequence of 0, 1, 2, 3, 4, repeating from an index variable

  // Open secrets.txt and check for errors
  cout << "Opening secrets.txt...\n";
  fin.open(s.c_str());
  if (!fin.good()) throw "I/O error"; 

  //perform decoding
  while(!fin.eof()) //stops reading lines at end of file
  {
    getline(fin, line);
    for (i = 0; i < line.length(); i = i+1)
    {
      line[i] = line[i] - offset[index]; // bump the ASCII code by -1
    }// for i
    cout << line << endl; 
  }// while - reads each line
  fin.close();

  
} 
 
