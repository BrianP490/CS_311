//CS311 Yoshii
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// =======================================================
// HW#: HW3P1 llist
// Your name: Brian Perez
// Compiler:  g++ 
// File type: header file  llist.h
//=======================================================

// alias el_t : element type definition
typedef int el_t;

//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer that stores the adress of the next node
};
//---------------------------------------------------------

class llist
{
  
 protected:
  Node *Front;       // pointer to the front node of the linked list
  Node *Rear;        // pointer to the rear node of the linked list
  int  Count;        // counter that represents the total number of nodes in the linked list

  // untility function to move to a specified node position
  void moveTo(int, Node*&);
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // both thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //This function will return if the value is empty as true or false.
  bool isEmpty();
    
  //This function will display all the contents in the linked list from the head to the tail
  void displayAll();

  //This function will add a node to the front of the linked list
  //The argument is a value that will be stored inside the new node
  void addFront(el_t);
    
  //This function will add a node to the back of the linked list
  //The argument is a value that will be stored inside the new node
  void addRear(el_t);

  //This function will delete the node at the front of the linked list
  //The parameter is a variable that will store the data of the deleted node
  void deleteFront(el_t&);
    
  //This function will delete the node at the rear of the linked list
  //The argument being sent is the container for the data that is inside the deleted node
  void deleteRear(el_t&);
    
  //This function will delete a node within the linked list 
  void deleteIth(int, el_t&);  // calls moveTo

  //This function will insert a node at the requested position    
  void insertIth(int, el_t);   // calls moveTo

  //Copy Constructor to allow pass by value and return by value of a llist
  llist(const llist&);
  
  //Overloading of = (returns a reference to a llist)
  llist& operator=(const llist&); 

};
