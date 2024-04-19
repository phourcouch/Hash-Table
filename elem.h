// CS311 Yoshii F23 - el_t for HW8 Hash Table
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
// I use IFNDEF in case this file gets included more than once
// Update based on **
// ---------------------------------------------------------
//HW#: HW8 hashtable
//Name: Kayla Le
//File Type: elem header file elem.h

#ifndef A
#define A

#include <iostream>
#include <string>
using namespace std;

class el_t
{
 private:  // these will change depending
           // on the client needs
  int key;      // key -- for EC, key has to change to string everywhere!!!
  string name;  // customer name
  //** add 2 more pieces of info here
  string  gender;//customer gender
  int age;//custoer age

 public:

  el_t();  // to create a blank el_t object
  el_t(int, string); // to create an initialized el_t object - useful for the client   ** add more arguments to create the object
  el_t(int, string, string,int);//to create an intialized el_t object 

 // The following functions are available to
 // the htable class to be able to
 // use different el_t without modifying the code

  int getkey(); // only the key part can be accessed by the user of this class.

  void setkey(int); // only the key part can be accessed by the user of this class.


  // In linked list search,
  //    == is used to compare node elements
  // but what does it mean for this client to compare
  // node elements?  
  bool operator==(el_t);  // overload == for search
  bool operator!=(el_t);  // overload != for search

  // This overloads cout for the el_t object
  // This is a friend function since the receiver object is not el_t
  friend ostream& operator<<(ostream&, const el_t&);


};

#endif
  


