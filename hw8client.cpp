// CS311 Yoshii F23 - hw8client.cpp
//   ** should be completed!!!
//
// Note that the client knows about elem.h functions.
// It can create el_t objects.
// Note that el_t X; will create a blank element X using the regular constructor.  
// Note that the second constructor of el_t can be used to
// create key+other info to add to the table. e.g. el_t X(30, "mary"...);
// NEVER delete my comments!!
//-----------------------------------------------

//============================================
// HW#: HW8 hashing client
// Name: Kayla Le
// File type: client hw8client.cpp (tester)
//===========================================

using namespace std;
#include "htable.h"
#include <iostream>
#include <fstream>
#include <string>

//** Add an explanation of what this App should be used for. 
int main()
{ 
  // cout an explanation of what this App should be used for. 
  cout << "This is a hashtable of People's Age, Name, Gender, you can add a person, find a person, delete a person, display the table, and save the table to a file at the end\n";
  htable HT;//table object
  string fname; // file name - decided to get the file name here
            // in the client in case the way I get them is application dependent

  cout << "What is the input file? (.txt file)";
  cin >> fname;//collect user's input
  
  ifstream fin (fname.c_str(), ios::in);//input file 
  HT.fillTable(fin);//calling filltable 
  // make sure some of elements collide. 
  HT.displayTable();//displaying table
  cout << endl;

  // this is the output file - newout.txt
  ofstream fout ("newout.txt", ios::out);  

  int selection;
  do {

  cout << "MENU: ---- " << endl; 
  cout << "1 Add an element" << endl; 
  cout << "2 Find an element" << endl;
  cout << "3 Delete an element" << endl;
  cout << "4 Display the table" << endl;
  cout << "5 Save the table to a file at the end" << endl;    
  cout << "6 Quit" << endl;
  cin >> selection;//get user's input

      int thekey;//holder for key
      string thename;//holder for name
      string thegender;//holder for gender
      int theage;//holder for age
      el_t theelement;//holder for element 
      int s;//holder for slot 

    switch (selection) {

    case 1:  // Add and indicate slot
      cout << "What is the key to add? ";
      cin >> thekey;
      cout << "What is the name?" ;
      cin >> thename;
      cout << "What is the gender?";
      cin >> thegender;
      cout << "What is the age?";
     cin >> theage;
       //  Here get two more pieces of info
      //  Create the element with all the info using the 2nd constructor
	theelement = el_t(thekey,thename,thegender,theage);
      s = HT.add(theelement);//add new element to table
      cout << "Added the element in slot " << s << endl;
      break;

    case 2: // Find and indicate element
      cout << "What is the key to find? ";
      cin >> thekey;
      theelement =  HT.find(thekey); // find based on thekey
      cout << "Found this:" << endl;
      cout << theelement << endl;
      break;      

    case 3: // Delete and indicate slot
      cout << "What is the key to find and delete? ";
      cin >> thekey;
      s  =  HT.deleteIt(thekey); // find and delete it based on thekey
      if (s == -1) cout << "Not found!" << endl; else
      cout << "Found it and deleted it from slot:" << s << endl;
      break;      

    case 4: // Display
      cout << "The current contents are: " << endl;
      HT.displayTable();
      break;

    case 5: // Save in the same format as input file
      HT.saveTable(fout);
      cout << "Saved the updated table in newout.txt" << endl;
      break;

    default:
      cout << "bye" << endl;
    }
  }
  while (selection != 6);

  fin.close();
  fout.close();
 }
