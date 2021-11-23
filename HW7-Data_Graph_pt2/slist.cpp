// ====================================================
//HW#: HW3P2 slist  inheriting from llist
//Your name: Brian Perez
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================
using namespace std;
#include<iostream>
#include"slist.h" 

// ** Make sure llist constructor and destructors have couts in them

//this is the default constructor for the slist class that calls the llist default constructor
slist::slist()
{}


//The search funtion will search through the llist and returns the position of the value if the key value was found. Otherwise, it returns a 0. Positions always start at 1
int slist::search(el_t key)
{
  bool found = false;   //create a temp boolean variable 
  Node* Ptr = Front;  //create a pointer to traverse the slist and set it to its Front
  int I = 0;   //create a temp variable to store the position of the found key

  //start looking for the key in the slist
  while(Ptr && !found){   //loop until there are no more nodes or the key was found
    if(Ptr -> Elem == key)     //if the current node's element is the same as the key
      found = true;     //change found to true, it has found the key
    Ptr = Ptr -> Next;    //move to the next node in the llist
    I++;    //increment I
  }

  if(found)    //if the element was found, return the value in I
    return I;
  else         //otherwise, return a zero
    return 0;
}

//This function will replace an element in the linked list. The two passed variables are the new value and the position in the llist. ( don't forget to throw OutOfRange for bad pos) 
void slist::replace(el_t element, int pos)
{
  if(pos <= 0 || pos > Count)  //checks if the pos is outside the range of the linked list
    throw OutOfRange();   //throw the error called OutOfRange
  
  else{
    Node* Ptr = Front;   //create a node pointer and set it equal to the front node's address
    moveTo(pos, Ptr);    //move through the linked list to the requested position 
    Ptr -> Elem = element;    //change the Element of the node
    }
}

//This function will compare two slist objects and return if they are the same or different. the passed argument is the sslist that will be compared to the calling object
bool slist::operator==(const slist& OtherOne)
{
  bool equal = true;     //create a variable to store if the two slist objects are the same
  Node* OPtr = OtherOne.Front;    //set a pointer to the front of the second slist using the . operator
  Node* FPtr = this -> Front;   //set a second pointer to point to the first slist's front

  if(OtherOne.Count != this->Count)    //if the two linked lists have different counts, then return false
    equal = false;

  else     //start checking each node to see if they are the same
    {
      while(OPtr && equal)     //loop until the second llist has been fully traversed or the two llists are different
	{                      
	  if(OPtr -> Elem != FPtr -> Elem)   //if the nodes' elements at the same position are not equal
	    equal = false;   //change equal to false
	  
	  OPtr = OPtr -> Next;     //move the pointer of the second llist forward
	  FPtr = FPtr -> Next;    //move the pointer of the first llist forward
	}
    }
    
  return equal;
}
