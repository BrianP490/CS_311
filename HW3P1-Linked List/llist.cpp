// ====================================================
//HW#: HW3P1 llist
//Your name: Brian Perez
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 

llist::llist()
{ cout << "... in llist constructor..." << endl;
  Front = NULL;
  Rear = NULL;
  Count = 0; }

llist::~llist()
{ cout << ".... in llist destructor..." << endl;
  el_t temp;
  while(Count != 0)
    deleteFront(temp); 
}

//PURPOSE: to check if the linked list is empty
//PARAMETER: none
bool llist::isEmpty() {
  if(Count == 0 && !Front && !Rear)
    return true;
  else
    return false;
} // be sure to check all 3 data members

//PURPOSE: to display all of the contents of the linked list
//PARAMETER: none
void llist::displayAll() {
  if(isEmpty())    //checks to see if the linked list is empty. If it is, show a blank list
    {
      cout << "[ empty ]" << endl;
    }
  else{
    Node* nodePtr;  //create a node pointer 
    nodePtr = Front;   //set the pointer to point to the same node as the pointer called Front

    cout << "[ ";  //begin printing the contents of the linked list

    while(nodePtr) //keep entering the while loop until the nodePtr is valid, meaning that the node is not Null
      {	cout << nodePtr -> Elem << " ";   //print the Element inside the node and add a space
	nodePtr = nodePtr -> Next;   //move the pointer forward to the next node 
      }
    cout << "]" << endl;    //print a closing bracket after the list has been displayed
  }
 }  // be sure to display horizontally in [  ] with
// blanks between elements
  
//PURPOSE: to add a node to the end of the linked list
//PARAMETER: a passed copy of an el_t
void llist::addRear(el_t NewNum) {
  if(isEmpty())   //case 1: checks if this is going to create a new linked list
    {
      Node* newNode = new Node;   //declares a node pointer and assigns it to an avaiable adress
      newNode -> Elem = NewNum;  //assign the node its data
      newNode -> Next = NULL;   //make the node's next = to Null
      Front = newNode;   //make the Front and Rear of the linked list equal to the adress of newNode
      Rear = newNode;
    }
  else{  //case 2 the new node will be added to an established llist
    Rear -> Next = new Node;    //the rear's next now points to a memory adress that can hold a Node
    Rear = Rear -> Next;   //update the rear pointer to point to the new node
    Rear -> Elem = NewNum;   //assign the new node its element 
    Rear -> Next = NULL;   //make the rear's next pointer Null
  }
  Count++;   //count is updated
 } // comment the 2 cases

//PURPOSE: to add a node at the beginning of the list
//PARAMETER: a passed copy of an el_t
void llist::addFront(el_t NewNum) { 
  //case 1: if the llist is not established
  if(isEmpty())   //checks if this is going to create a new linked list
    {
      Node* newNode = new Node;   //declares a node pointer and assigns it to an available adress
      newNode -> Elem = NewNum;  //assign the node its data
      newNode -> Next = NULL;   //make the node's next = to Null
      Front = newNode;   //make the Front and Rear of the linked list equal to the adress of newNode
      Rear = newNode;
    }
  //case 2: if the llist is already established 
  else{
    Node* newNode = new Node;  //declares a node pointer and assigns it to an available adress
    newNode -> Elem = NewNum;  //assign the node its data
    newNode -> Next = Front;   //assign the node's next to point to the same node that Front is pointing to
    Front = newNode;  //make the Front pointer point to the newly created Node
  }
  Count++;  //increase the count of the number of nodes in the linked list
} // comment the 2 cases

//PURPOSE: to delete a node at the front of the linked list
//PARAMETER: a passed address of an el_t
void llist::deleteFront(el_t& OldNum) { 
  if(isEmpty())   //case 1: if the llist is empty, throw an exception
    {throw Underflow();}
  else if(Count == 1){  //case 2: if there is only one node in the llist
    OldNum = Front -> Elem;   //assign the value of the node to OldNum
    delete Front;   //delete the contents of the first node
    Rear = NULL;   //set Front and Rear to Null to avoid errors
    Front = NULL;    
    Count--;   //update the counter for the number of nodes
  }
  else{  //case 3: there are multiple nodes in the list and front can easily be deleted
    OldNum = Front -> Elem;  //store the node's element into OldNum
    Node* Second = Front -> Next;   //create a linked list node pointer to point to the second node
    delete Front;   //delete the contents of the first node
    Front = Second;    //make Front now point to the node that Second is pointing to
    Count--;   //update the counter for the number of nodes
  }

} // comment the 3 cases

//PURPOSE: to take off a node from the rear of the linked list
//PARAMETER: an el_t passed by reference
void llist::deleteRear(el_t& OldNum){
  if(isEmpty()) throw Underflow();//case 1: if the llist is empty, throw an exception
  else if(Count == 1){  //case 2: if there is only one node in the linked list
    OldNum = Rear -> Elem;   //assign the value of the node to OldNum
    delete Rear;   //delete the contents of the first node
    Front = NULL;   //set Front and Rear to Null to avoid errors
    Rear = NULL;
    Count--;   //update the counter for the number of nodes
  }
  else{//case 3: there are multiple nodes in the list and front can easily be deleted
    OldNum = Rear -> Elem;  //store the node's element into OldNum
    Node* PrevNode = Front;   //create a pointer to use to traverse the llist and set it to Front
    while(PrevNode -> Next != Rear) PrevNode = PrevNode -> Next;  //traverse the llist until it is one node behind Rear's node
    delete Rear;   //delete the rear node
    Rear = PrevNode;    //make Rear now point to the node that PrevNode is pointing to
    Rear -> Next = NULL;   //make the Rear's next point to Null to prevent errors
    Count--;   //update the counter for the number of nodes
  }
} // comment the 3 cases
/* harder ones follow */

// Utility Function to move a local pointer to the Jth node
void llist::moveTo(int J, Node*& temp)
{ // moves temp J-1 times
  for ( int K = 1; K <= J-1; K++ ) temp = temp->Next;
}

//PURPOSE: To delete a node at the client's choosing
//PARAMETER: a position, I, of whick node to delete, and a variable to store the deleted node's data
void llist::deleteIth(int I, el_t& OldNum) { 
  if(I == 0 || I >= Count + 1) throw OutOfRange();
  else if(I == 1) 
    deleteFront(OldNum);
  else if(I == Count)
    deleteRear(OldNum);
  else{
    Node* Pointer = Front;   //create a pointer to point to the node that is to the left of the node being deleted
    moveTo(I - 1 , Pointer);   //use the moveTo funtion to jump to the I-1th node
    Node* Temp = Pointer -> Next;   //create a temporary node pointer to delete the nodes data   
    OldNum = Temp -> Elem;  //store the data of the nod eabout to be deleted  
    Pointer -> Next = Temp -> Next;  //make the pointer's next point to the temp node's next
    delete Temp;   //delete the indicated node  
    Count--;  //decrement the number of nodes in the count
  }

} // use moveTo to move local pointers. Be sure to comment to which node you are moving them.  

//PURPOSE: To insert a node at a position given by the client
//PARAMETER: a position number, I, and the new node's data, newNum
void llist::insertIth(int I, el_t newNum) { 
  if( I <= 0 || I >= Count + 2) throw OutOfRange();  //catch any numberrs out of range
  else if(I == 1)   //if the client wants to add a node at the front
    addFront(newNum);   //call insert function
  else if(I == Count + 1)   //if the client wants to add a node at the rear
    addRear(newNum);   //call insert function
  else{    //if the client wants to insert a node any where between the Front and the Rear
    Node* PrevPointer = Front;   //make a node pointer and set it to front's pointer
    moveTo(I - 1 , PrevPointer);   //use the moveTo funtion to jump to the I-1th node
    Node* NewNode = new Node;   //create a new node
    NewNode -> Elem = newNum;   //assign the node its data    
    NewNode -> Next = PrevPointer -> Next;  //assign the newNode's next to the previous nodes next to maintain order
    PrevPointer -> Next = NewNode;  //point the previous node's next to point to the new node 
    Count++; //increase the counter of number of Nodes
  }
} // use moveTo to move local pointers. Be sure to comment to which node you are moving them.

//PURPOSE: to make a deep copy of a linked list 
//PARAMETER: a previouly created linked list that is unchangeable and passed by reference 
llist::llist(const llist& Original) {
  Front = NULL;    //initialize the llist values
  Rear = NULL;
  Count = 0;

  el_t x;
  if(&Original != this)//if the calling object, the list that is going to changed is the same as the OtherOne
    {//this is the address pointer to the left hand side of the statement of L1= L2;
      while(!this->isEmpty())  //loops through the linked list untill it is empty
	this -> deleteRear(x);   //removes the rear from the llist
      Node* P; //create a local pointer to traverse the second llist
      P = Original.Front;   //set the pointer to point to the front of the second llist
      while(P!=NULL)   //while P has not reacehd a NULL address
	{
	  this -> addRear(P->Elem);   //add a node to the first llist
	  P = P -> Next;   //update the p pointer forward the second llist(L2)
	}
    }
} // use my code

//PURPOSE: to create a deep copy of a linked list
//PARAMETER: a linked list that is unchangeable and passed by reference
llist& llist::operator=(const llist& OtherOne) { 
  el_t x;
  if(&OtherOne != this)//if the calling object, the list that is going to changed is the same as the OtherOne
    {//this is the address pointer to the left hand side of the statement of L1= L2;
      while(!this->isEmpty())  //loops through the linked list untill it is empty
	this -> deleteRear(x);   //removes the rear from the llist
      Node* P; //create a local pointer to traverse the second llist
      P = OtherOne.Front;   //set the pointer to point to the front of the second llist
      while(P!=NULL)   //while P has not reacehd a NULL address
	{
	  this -> addRear(P->Elem);   //add a node to the first llist
	  P = P -> Next;   //update the p pointer forward the second llist(L2)
	}       
    }
  return *this;   //returns the address of the new linked list, L1
}
