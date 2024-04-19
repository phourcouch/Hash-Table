// CS311 Yoshii F23 - Hash Table - complete all ** parts.
// Note: this class does not know the parts of element except for key
// so that it would work even if each element in the hash table changed
//  NEVER delete my comments!!
//-----------------------------------------------------

// ============================================
// HW#: HW8 Hash Table
// Name: Kayla Le
// File Type: implementation htable.cpp
// =============================================

using namespace std;
#include <iostream>
#include "htable.h"
#include "elem.h"
htable::htable()
{}

htable::~htable()
{}

// a simple hash function that uses % TSIZE simply
// For EC: you have to shorten the long key first!!!!
int htable::hash(int key)
{ return (key % TSIZE);  }

// adds the element to the table and returns slot#
int htable::add(el_t element )
{
  int slot = hash(element.getkey());  // hash with the key part
  // Note that this means adding the element to a slist in the slot (call addRear)
  table[slot].addRear(element);
  
  return slot;
}

// finds element using the skey and returns the found element itself
// or a blank element  -- there is no cout in here
el_t htable::find(int skey)
{ 

 int slot = hash(skey); // hash with skey
 el_t selement;  // this is the element to look for in slist
 selement.setkey(skey); // initialize selement with just the skey (call setkey)
  // call slist's search2 with selement which returns the found element 
  el_t  foundElem = table[slot].search2(selement);
  return foundElem;  // return the found element from here (it could be blank)
}

// finds the element given the key  and deletes it from the table.
//  Returns the slot number.
int htable::deleteIt(int key)
{
  
 int slot = hash(key); // hash with skey
 el_t selement;  // this is the element to look for in slist
 selement.setkey(key); //  initialize selement with just the skey
  //  call slist's search which gives you the location I and then deleteIth
  int locationI = table[slot].search(selement);
   table[slot].deleteIth(locationI, selement);
  return slot; //  return the slot number
}

// fills the table using the specified input file 
void htable::fillTable(istream& fin)
{ int akey;//holder for key
  string Name;//holder for name
  string Gender;//holder for gender
  int Age; //holder for age
  //  model this after HW6 to get data from the file the user specified
  //  which elem and slist functions do you call? List them here first.
  while (fin >> akey){ 
    
    // fin other parts and create an element
    fin >> Name;
    fin >> Gender;
    fin >> Age;

    el_t  NewElem(akey,Name,Gender,Age);//creatiing element 

    // YOu can call the add function to add the created element to the table
   add(NewElem);
  }

}

// displays the entire table with slot#s too
void htable::displayTable()
{
  for (int i = 0; i < TSIZE; i++)//loop through the size of table
    { cout << i << ":" ;   //print out current slot number
     table[i].displayAll(); // call slist's displayAll to display elements or empty 
    }
}

// saves into the specified file in the same format as the input file
void htable:: saveTable(ostream& fout) 
{
 el_t element; //holder for remvoed element 
  // for each non-empty slot of the table, retrieve the slist to a local variable
  // and fout each removed element.
   for(int i = 0; i < TSIZE;i++){//loop through table
   if(!table[i].isEmpty()){//if not empty, delete element and the store it into new file 
        while(!table[i].isEmpty()){//use while loop to get collided elements 
         table[i].deleteFront(element);
        fout << element << endl;
      }
    }
   }
}
