//INSTRUCTION:
//Look for ** using control-S
//Then, fill in the function body
//When done, compile queue.cpp to make sure it has no syntax errors

//=========================================================
//HW#: HW1P2 queue
//Your name: Brian Perez
//Complier:  g++
//File type: queue.cpp
//===========================================================

using namespace std;
#include <iostream>
#include "queue.h"  

// constructor 
queue::queue()
{
  front = -1;
  rear = -1;
  count = 0;
}

//destructor 
queue::~queue()
{ // nothing
}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
  if(count == 0)
    return true;
  else
    return false;
}

// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull()
{
  if(count == MAX_SIZE)
    return true;
  else
    return false;
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t newElem)
{ if(isFull()) throw Overflow();
  else{ 
    rear = (rear + 1) % MAX_SIZE;       //move the rear up one to the correct index 
    el[rear] = newElem;      //assign the element in the array the value of the newElem variable
    count ++;}         //increase the total count of elements in the array 
}

// PURPOSE: if empty, throw Underflow
// if not empty, removes the front element to give it back 
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue::remove(el_t& removedElem)
{ if(isEmpty()) throw Underflow();
  else{
    front = (front +1) % MAX_SIZE;         //move the front index to the correct position (1%10 = 1; 11%10 = 1) 
    removedElem = el[front];      //assign the value of the element at index front to removedElem
    el[front] = "";   //delete the element in index front
    count --;}     //decrement the value of count
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& theElem)
{ if(isEmpty()) throw Underflow();
  else{
    theElem = el[(front+1)%MAX_SIZE];}  //store the front element of the queue into theElem variable
}
// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize()
{  return count;}

// PURPOSE: display everything in the queue horizontally
// from front to rear enclosed in [   ]
// if empty, displays [ empty ]
void queue::displayAll()
{  if (isEmpty()) { cout << "[ empty ]" << endl;}
  else
    {
      int j = front;
      cout << "[";
      for (int i = 1; i <= count; i++)    //loops as many times as the number of elements present
	{j = (j +1) % MAX_SIZE;
	  //cout << front << el[j] << rear << " ";}      //print the element at the index of front
	  cout << el[j] << " ";}      //print the element at the index of front
      cout << "]" << endl;   
    }  
}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//calling remove followed by add.
void queue::goToBack()
{ if(isEmpty()) throw Underflow();    //throws to the underflow if the queue is empty
  else{
    if(count == 1)    //do nothing iff count is exactly 1
      ;
    else{
      string temp;          //create a temporary vaiable to store the queue element
      remove(temp);       //remove an element from the front
      add(temp);         //place the temp into the end of the queue   
    }
  }
}

