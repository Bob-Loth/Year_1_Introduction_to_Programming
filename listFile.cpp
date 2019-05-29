//Objective: read all song titles from a text file,
//and randomly select and output titles in a loop until the user wishes to stop. 
//Name: Robert Loth
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <fstream> 
#include <iostream> 
using namespace std; 

//Programmer defined data types
struct Scores
{
  int score;
  Scores* next; // the next-link
}; // Student


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
  void introduction(string obj); //userintroduction

  
  //DATA
  string objective = "read a list of scores";
  ifstream fin;
  int sum = 0; //sum of all scores
  double average = 0; // the average of all scores
  int count = 0; //total count of scores
  int nGreater = 0; //number of scores greater than avg
  int highest = 0; //the highest score
  int lowest = 100; // the lowest score
  int invl=0; // counter of invalid numbers
  introduction(objective);
  
  Scores* start = 0; //create an empty linked list of data type Scores

//open scores.txt and add values to linked list
fin.open("scores.txt"); 
if (!fin.good()) throw "I/O error"; 
while (fin.good()) 
{ 
  
  Scores* aScore = new Scores;
  // read a score from the file  
  fin >> aScore->score; 
  fin.ignore(1000,10);
 
  //add new node to list, if it is a valid entry
  if (aScore->score >= 0 && aScore->score <= 100)
  {
  aScore->next = start;
  start = aScore;  
  }//end if 0-100 valid
  else if (aScore->score < 0 || aScore->score > 100) invl++;
  
} // while 
fin.close();
cout << invl << " scores in scores.txt were invalid. Scores must be between 0 and 100. \n\n";

//traversing the list to find average, highest, lowest and number of scores
  // find the average 
  Scores* p;
  for (p = start; p; p = p->next)
  {
    count++;
    sum += p->score;
  }//end for average
  average = (double)sum / count;
  

  cout << "The average of " << count << " numbers is " << average << ".\n"; 
  
  //find the highest score
  for (p = start; p; p = p->next)
  {
    if (p->score > highest) highest = p->score;
  }// end for highest
cout << "The highest score is " << highest << ".\n";

  //find the lowest score
  for (p = start; p; p = p->next)
  {
    if (p->score < lowest) lowest = p->score;
  }//end for lowest
cout << "The lowest score is " << lowest << ".\n";

  // count number of scores > average 
  for (p = start; p; p = p->next) 
  {
    if (p->score > average) nGreater++; 
  }//end for nGreater
cout << nGreater  << " scores are greater than the average." << endl; 


  
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

