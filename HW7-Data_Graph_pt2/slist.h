//=================================================
// HW#: HW3P2 slist
// Name: Brian Perez
// File: header file slist.h
//=================================================
#ifndef SSLIST_H
#define SSLIST_H
#include "llist.h"

//the following class will inherit the llist class's protected traits and will be able to use llist's methods/functions
class slist : public llist
{
 public:

  slist();   // constructor that will also call the llist constructor

  int search(el_t);
    // search through the list to see if any node contains the key.
    // If so, return its position (>=1). Otherwise, return 0.
    
  void replace(el_t,  int);
    // go to the Ith node (if I is between 1 and Count) and 
    // replace the element there with the new element. 
    // If I was an illegal value, throw OutOfRange 
    
  bool operator==(const slist&);
    // checks to see of the two lists look the same
};
#endif
