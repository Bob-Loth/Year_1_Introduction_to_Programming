//Objective:  
//Name: Robert Loth
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <iostream>
using namespace std;
 




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
  string objective = "prompt the user to input 4 numbers between 0 and 100, and calculate the average of those 4 numbers, and how many of those 4 numbers are above the average."; //program objective
  int i = 0; // second loop index
  int count = 0;// first loop index
  int sum = 0; // sum of integers in array
  double average = 0; // average of integers in array
  int nGreater = 0; // number of integers greater than the average in the array
  int numbers[4]; //the array to be used

  introduction(objective); //userintroduction
  
  
  
  cout << "Please input 4 numbers between 0 and 100.\n";
//put numbers in array and get their sum
for( count = 0; count<=3; count++)
{
  do
  {  
    cout << "Please input a number [0-100]: ";
    cin >> numbers[0];
    cin.ignore(1000,10);
  }while(numbers[count] < 0 || numbers[count] > 100);//end while input validation
  sum = sum + numbers[count];
}//end for loop

//calculate average of numbers in array
if (count > 0)
{
  average = sum / count;
} 
    

//calculate the number of input values that are greater than the average

for (i=0; i<=3; i++)
{
  if (numbers[i] > average) nGreater++;
}//end for 

//output results
cout << "The average of " << count << " numbers is " << average << ".\n";
cout << nGreater << " numbers are greater than the average." << endl;

 
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

