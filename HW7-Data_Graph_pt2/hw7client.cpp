//==========================================
// HW#: HW7 DFS client using dgraph.h
// Name: Brian Perez
// File type: client hw7client.cpp 
//==========================================

// ** Be sure to include dgraph, slist and stack
#include "dgraph.h"
#include "slist.h"
#include "llist.h"
#include "stack.h"
#include <iostream>

using namespace std;

// This client uses the dgraph class and stack class
// to do depth first traversal of the graph stored in table.txt
int main()
{
  // ** copy here the algorithm (read carefully) in the HW7
  // assignment sheet and use that has the comments. 

  dgraph R;   //create a dgraph
  stack C;   //create an instance of the stack class
  int I=1;    //holds the visit number for each gvertex and increases after each assignment
  char X, Y; //char variables to hold characters
  //Fill and Display the graph before DFS begins.
  R.fillTable();
  R.displayGraph();

  //Push A onto the stack to start.
  C.push('A');
 
  while(!C.isEmpty())//  While the stack is not empty do:
  {
    //  Remove a vertex v from the stack.
    C.pop(X);
    cout << "\nRemoved " << X << " from stack";//Display the vertex name.

    if(!R.isMarked(X))//If v is not marked yet (visit number is 0) then 
      {	  //mark it (visit it using the function) and inform the user E.G. “Visit B as 2”
	cout << "\nVisit " << X << " as " << I;  
	R.visit(I, X);    //update X's visit counter
	I++;//increase the visit counter
  
	//get its adjacency list 
	if(R.findOutDegree(X) == 0){//if no adjacent ones inform the user E.G. “Deadend reached – backup”
	  cout << "\nDeadend reached - backup" << endl;
	}
	
	else//else put adjacent ones on the stack (delete from the rear and push) informing the user
	  {
	    slist T = R.findAdjacency(X);  //create a copy of the adjacent vertices slist
	    cout << "\n... pushing ";
	    T.displayAll();
	    while(!T.isEmpty()){    //transfer all the slist characters into the stack in reverse order while the slist is not empty
	      T.deleteRear(X);   //delete a char from the slist
	      C.push(X);   //add X to the stack, C
	    }
	  }
      }
    else{ //inform the user E.G. “B had been visited already - backup.”
      cout << endl << X << " had been visited already - backup" << endl;
    }
    C.displayAll();    //Display the stack clearly labeling it as the current stack
  }//end of while loop
  
  R.displayGraph();  //Display the Graph nicely with visit numbers for all vertices.
  return 0;
}//end of program
