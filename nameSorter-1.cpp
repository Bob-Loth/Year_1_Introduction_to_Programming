//Objective:  
//Name: Robert Loth
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream>
#include <fstream> //using files as input and output
using namespace std;

#include <cctype>
//Programmer defined data types
//NONE ch 13

//Special compiler dependent definitions
//NONE ch 7/8

//global constants/variables
//NONE ch 13

//Programmer defined functions
void introduction(string obj); // user introduction


//main program
int main()
{
  //Data
  string objective = "sort a list of names."; //program objective
  string fileName; //input file name
  string line; //a line from the input file
  double averageScore; //calculated average of all the scores from the input file
  int count=0; //number of scores in the input file
  int totalScores; //sum of all the scores in the input file
  int maxScore; //highest score of all the scores in the input file
  int minScore; //lowest score of all the scores in the input file
  int nGreater; //number of scores greater than the average score
  int i; // index value for traversing each element in the array
  const int SIZE = 5;
  string names[SIZE];
  string namesTemp[SIZE];
  int nNames = 0;
  ifstream fin; //file input
  ofstream fout; //file output
  string temp; // temporary storage used in sorting
  string temp2; //temporary storage used in sorting
  introduction(objective); //userintroduction


  //open file chosen by user that contains names
  cout << "Please enter the full file name of your list of names: ";
  cin >> fileName;
  cin.ignore(1000,10);
 
 fin.open(fileName.c_str());
  if (!fin.good()) throw "I/O error";
  while(nNames < 5)
  {
    getline(fin,line);
    names[nNames] = line;
    for(i = 0; i < line.length(); i++) 
    {
      line[i] = tolower(line[i]);
    }//end for string tolower
    namesTemp[nNames] = line;
    nNames++;
  }//end while add to array

//account for case-sensitivity  still working on this section



  //swap sort
 for (i=0; i<nNames; i++)
 {
   for (int j = i+1; j < nNames; j++)
   {
     if (namesTemp[i] > namesTemp[j])
     {
       temp = namesTemp[i];
       temp2 = names[i];
       namesTemp[i] = namesTemp[j];
       names[i] = names[j];
       namesTemp[j] = temp;
       names[j] = temp2;
     }//end inner if
   }//end inner for
 }//end outer for
  
cout << names[0] << endl << names[1] << endl << names[2] << endl << names[3] << endl <<names[4]<< endl << endl;

 
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

