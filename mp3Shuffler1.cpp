//Objective: read all song titles from a text file,
//and randomly select and output titles in a loop until the user wishes to stop. 
//Name: Robert Loth
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream>
#include <fstream> //using files as input and output
using namespace std;
 

#include <cstdlib>
#include <ctime>

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
  string objective = "read all song titles from a text file, and randomly select and output titles in a loop until the user wishes to stop."; //program objective
  const int SIZE = 200; // 200 capacity of array songs
  string songs[SIZE]; // array of the names of songs from songs.txt
  int nSongs= 0; // counter of array-based list
  srand(time(0)); //seed the rng
  char playSong = 'y'; // determines whether or not to continue the program 
  int random; // selects random track
  int i=0; // index variable in play loop
  introduction(objective); //userintroduction
  ifstream fin; // input stream 
  string line; // receives file input


  //add input from text file to array-based list
 
 fin.open("songs.txt");
  if (!fin.good()) throw "I/O error";
  while (fin.good() && (nSongs < 200))
  {
    getline(fin,line);
    songs[nSongs] = line;
    nSongs++;
  }//end while get list of songs
    
  //prompt user to "play a song"
  
while (tolower(playSong) == 'y')
{
  while (true)
  {
    cout <<  "play a song [Y/N]? ";
    cin >> playSong;
    cin.ignore(1000,10); 
    if (tolower(playSong) == 'n' ) break;
    else if (tolower(playSong) =='y') break;
  }//while inner
  if (tolower(playSong) == 'y')
  { 
      cout << endl;
      random = (rand() % nSongs);
      cout << "Track " << random + 1 << ": " << songs[random] << endl;  
      i++;
  }//if
}//while outer
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

