//Objective:  Simulate an odometer of a car travelling .1 miles per second.
//Name: Robert Loth
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iomanip>

#include <iostream>
using namespace std;
 

#ifdef _WIN32

#include <windows.h> 

#else 
#include <unistd.h> 

#endif 
  


//Programmer defined data types
//NONE ch 13

//Special compiler dependent definitions
//NONE ch 7/8

//global constants/variables
//NONE ch 13

//Programmer defined functions
//NONE 

//main program
int main()
{
  //Data
  //NONE
  
  
 
  // output my name and objective and program information
  cout << "Objective: Simulate an odometer of a car travelling .1 miles per second.\n"; 
  cout << "Programmer: Robert Loth\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: TDM MinGW\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl; 

 
 
  cout << "CTRL-C to exit...\n"; 
  
   cout.fill('0'); 
 
 
  
     for (int mile = 0; mile < 100000; mile++) 
   
     { 
    
       for (int tenth = 0; tenth < 10; tenth++) 
    
       { 
       
         
   
         cout << setw(5) << mile << '.'; 
     
         cout << setw(1) << tenth << ' '; 
     
         cout.flush(); 
  
   
         #ifdef _WIN32   
 Sleep(1000); // one thousand milliseconds
    
         #else 
           sleep(1); // one second 
       
         #endif 
  
        cout << '\r'; // CR 
  
       } 
  
     } 

   
 
} // main 
