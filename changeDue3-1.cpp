//Objective:  calculate change due in a transaction using these U.S. bills – no cents: $1, $2, $5, $10, $20, $50, $100, $500, $1000, $5000, $10000, and $100000 bills.
//Name: Robert Loth
//Course: COMSC-110-1021
//Compiler: TDM MinGW
//Editor: MS NotePad

//libraries
#include <fstream>
#include <iostream>
using namespace std;

//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
//NONE

//main program
int main()
{
  // output my name and objective and program information
  cout << "Objective: calculate change due in a transaction using these U.S. bills – no cents: \n $1, $2, $5, $10, $20, $50, $100, $500, $1000, $5000, $10000, and $100000 bills.\n"; 
  cout << "Programmer: Teacher\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: VC++ 2010 Express\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //variables
  int amountOwed; //amount owed
  int cashPaid;  //amount paid
  int totalChangeDue = cashPaid - amountOwed; //total change due
  int changeDue = totalChangeDue;
  int thousand100; //number of $100000 bills
  int thousand10; //number of $10000 bills
  int thousand5; //number of $5000 bills
  int thousand;  //number of $1000 bills
  int hundred5; //number of $500 bills
  int hundred;  //number of $100 bills
  int fifty;  //number of $50 bills
  int twenty; //number of $20 bills
  int ten;  //number of $10 bills
  int five;  //number of $5 bills
  int two; //number of $2 bills
  int one;  //number of $1 bills
  ifstream fin; // sets input file stream to fin
  string changeInput = "change.txt";
  

  //receive and error handle input about cash paid and amount owed
  fin.open(changeInput.c_str());
  if (!fin.good()) throw "I/O error"; 
  cout << "Getting data from change.txt. Check if amount owed is on line 1, and cash paid is on line 2.";
  fin >> amountOwed; 
  fin.ignore(1000, 10); 
  fin >> cashPaid; 
  fin.ignore(1000, 10); 
  fin.close();
  
  
  //calculate change due
  thousand100 = changeDue / 100000;  //number of $100,000 bills
  changeDue = changeDue % 100000;  //remainder from $100,000
  thousand10 = changeDue / 10000;  //number of $10,000 bills
  changeDue = changeDue % 10000; //remainder from $10,000
  thousand5 = changeDue / 5000; //number of $5000 bills
  changeDue = changeDue % 5000; //remainder from $5000
  thousand = changeDue / 1000; //number of $1000 bills
  changeDue = changeDue % 1000;//remainder from $1000
  hundred5 = changeDue / 500;  //number of $1000 bills
  changeDue = changeDue % 500; //remainder from $500
  hundred = changeDue / 100;   
  changeDue = changeDue % 100;
  fifty = changeDue / 50;
  changeDue = changeDue % 50;
  twenty = changeDue / 20;
  changeDue = changeDue % 20;
  ten = changeDue / 10;
  changeDue = changeDue % 10;
  five = changeDue / 5;
  changeDue = changeDue % 5;
  two = changeDue / 2;
  changeDue = changeDue % 2;
  one = changeDue;



 

  //output calculated change due for each kind of monetary demonination
  cout << "Amount owed: " << amountOwed;
  cout << " Cash paid: " << cashPaid;
  cout << " Total change due: " << totalChangeDue << endl;
  cout << "this many $100,000 bills: " << thousand100 << endl;
  cout << "this many $10,000 bills: " << thousand10 << endl;
  cout << "this many $5,000 bills: " << thousand5 << endl;
  cout << "this many $1,000 bills: " << thousand << endl;
  cout << "this many $500 bills: " << hundred5 << endl;
  cout << "this many $100 bills: " << hundred << endl;
  cout << "this many $50 bills" << fifty << endl;
  cout << "this many $20 bills" << twenty << endl;
  cout << "this many $10 bills" << ten << endl;
  cout << "this many $5 bills" << five << endl;
  cout << " this many $2 bills: " << two << endl; 
  cout << " this many $1 bills: " << one << endl; 
}