// CS311 Yoshii
// HW6 Client file 
//INSTRUCTION: Complete this file and comment using How to Comment file.
//---------------------------------------------

// ================================================
// HW#: HW6 dgraph client 
// Name: Brian Perez
// File type: client program  (tester) hw6client.cpp
// ===============================================
#include <iostream>
#include "dgraph.h"

using namespace std;
//Purpose: to test the class of dgraph and check its member functions 
int main()
{ 
  dgraph T1;   //Declare table object
  T1.fillTable();  //fillTable
  T1.displayGraph();   //display the table
  int degree;   //create a temp veriable for degree
  char L;     //variable for cin
  int I = 1;   //variable for while loop condition
  
  while(I != 9)   ///loop until the user wants to quit
    {
      try{     //start the try block
	cout << "\nFind information of which Vertex?: ";
	cin >> L;
	degree = T1.findOutDegree(L); //find the degree of L and store it into degree
	cout << "The degree of the vertex is: " << degree << endl;
	//copy the slist of the vertice, L, to S1 and display it   
	slist S1 = T1.findAdjacency(L);   
	cout << "Its adjacent vertices are: ";
	S1.displayAll();
	//ask for user input
	cout << "Enter \"9\" if you want to quit the Program or a different number if you want to continue(MUST ENTER A NUMBER): ";
	cin >> I;
      }catch(dgraph::BadVertex)  //catch block that shows an error msg but does not exit the program
	{    cerr << "Vertex was NOT found." << endl;}
    }
  return 0;
}