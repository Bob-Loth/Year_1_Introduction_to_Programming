//Objective: read all song titles from a text file,
//and randomly select and output titles in a loop until the user wishes to stop. 
//Name: Robert Loth
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <fstream> //file io
#include <iostream> //console input and output
#include <string> // .length() command 
using namespace std; 

//Programmer defined data types
struct Favorites
{
string movie;
string song;
string food;
string sport;
string tvShow;
string book;
string place;
} people[8];

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
  ifstream fin; // file input stream
  string objective = "pass by reference a table of data";
  introduction(objective); //userintroduction 
  int n=12;
  string whoAreYou[n];
  int nRecords = 0;//counts the number of records in the file
  int i = 0; //index for outputting who is this? guesses
  string userGuess; // response to who is this? user input

  fin.open("favoritesData.txt");
  if (!fin.good()) throw "IO error";
  while(!fin.eof())
  {
    getline(fin,people[nRecords].movie);
    getline(fin,people[nRecords].song);
    getline(fin,people[nRecords].food);
    getline(fin,people[nRecords].sport);
    getline(fin,people[nRecords].tvShow);
    getline(fin,people[nRecords].book);
    getline(fin,people[nRecords].place);
    nRecords++;
    fin.ignore();
  }//while reads file
  for (i=0; i<nRecords; i++)
  {
    cout << "favorite movie: " << people[i].movie << endl;
    cout << "favorite song: " << people[i].song << endl;
    cout << "favorite food: " << people[i].food << endl;
    cout << "favorite sport: " << people[i].sport << endl;
    cout << "favorite tvShow: " << people[i].tvShow << endl;
    cout << "favorite book: " << people[i].book << endl;
    cout << "favorite place: " << people[i].place << endl;
    cout << "Who is this?: ";
    getline(cin,userGuess);
    cout << endl << "Person #" << i+1 << ": you think this is: " << userGuess << endl;
    cin.ignore(1000,10);
    whoAreYou[i] = userGuess;
  }
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

