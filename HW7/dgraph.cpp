//CS311 Yoshii dgraph.cpp 
// INSTRUCTION:
//  Complete all the functions you listed in dgraph.h
//  Comment the file completely using How to Comment file.
//  Use HW6-help.docx to finish the functions.
//-------------------------------------------------------

//======================================================
// HW#: HW6 dgraph
// Name: Brian Perez
// File Type: implementation file dgraph.cpp
//========================================================
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include "dgraph.h"
//constructor for dgraph class
dgraph::dgraph(){
 // initialize vertexName (blank) and visit numbers (0)    // initialize countUsed to be 0{
  countUsed = 0;  //set the number of used indexes of the Gtable array to 0

  for(int i = 0; i < SIZE; i++)  //loop through and initialize the entire table
    {
      dgraph::Gtable[i].vertexName = ' ';
      dgraph::Gtable[i].visit = 0;
    }
}
//Destructor for dgraph class
dgraph::~dgraph()   // do we have to delete all nodes of slists in table??
// Question: If we do not do this, will the llist destructor be called automatically??? Try it.
{
}
//Purpose: Adds vertexes, outDegrees of each vertex, and adjacent verteces, if any using a text file.
void dgraph::fillTable()  // be sure to read from a specified file
{
  string fname;   //var for file name
  cout << "Enter a file name: ";
  cin >> fname;
  ifstream fin (fname.c_str(), ios::in); // declare and open fname
  char temp;  //counter for traversing the table

  while(fin >> Gtable[countUsed].vertexName)   //loop until the function reads the whole text file
    {
      fin >> Gtable[countUsed].outDegree;  //the outDegree will come from the third index of cstring line that is converted to an integer value
      
      for(int i = 0; i < Gtable[countUsed].outDegree; i += 1 )   //goes through the rest of the line and add the char to the slist in the Gvertex
	{	fin>> temp;  //get the adjacent vertex's char from text file
	    Gtable[countUsed].adjacentOnes.addRear(temp);   //add the char into the slist of Gvertex of a certain Gtable index
	}
      countUsed++;
    }

  fin.close();   //close the text file
}

//Purpose: Displays the Directed Graph. It shows each letter in table format, its out Degree, and all adjacent vertices.
void dgraph::displayGraph() // be sure to display
{// in a really nice table format -- all columns but no unused rows 
  cout << "*************************************" << "\nDisplaying table\n*************************************" << endl;
  for(int i= 0; i<= countUsed; i++) //loop through the entire dgraph
    {
      if((Gtable[i].vertexName >= 65) && (Gtable[i].vertexName <= 90)) //if the Gvertex has a valid name start displaying 
	{
	  cout << Gtable[i].vertexName << " " << Gtable[i].outDegree << "  "<< Gtable[i].visit << " "; 
	  Gtable[i].adjacentOnes.displayAll(); //show the adjacent vertices
	}
    }
}
//Purpose: To return the out Degree of whatever letter is requested
//Parameter: The requested character that will be searched for.
int dgraph::findOutDegree(char V)// throws exception
{// does not use a loop
  int i = V - 65;    //convert the passed char into an int and store the value in i.V is an int starting from 65 and in order to get the index, subtract by 65 
  //throw an exception if the passed char is not in the table 
  if((i <= -1) || (i > countUsed + 1) || (Gtable[i].vertexName != V))
    throw BadVertex ();
  else
    return Gtable[i].outDegree; //return the outdegree of V
}
//Purpose: to return the adjacent vertices as a slist
//Parameter: the char that the function will find the adjacent vertices of
slist dgraph::findAdjacency(char V)// throws exception
{// does not use a loop
  int i = V - 65; //stores the parameter as an int value
  //throw an exception if the passed char is not in the table 
  if((i <= -1) || (i > countUsed + 1) || (Gtable[i].vertexName != V))
    throw BadVertex ();
  else
    return Gtable[i].adjacentOnes;  //return the adjacent vertices of V
}

//Purpose: to assign a certain vertex's visit number
//Parameters: The given visit number, and the vertex name
void dgraph::visit(int I, char A)
{
  int temp = A - 65;   //turn A into an index
  Gtable[temp].visit = I;  //get the vertice's visit num from I
}
//Purpose: to return true if a given vertex was already visited
//Parameter: the char that the client is asking info about
bool dgraph::isMarked(char A)
{
  bool Marked = true;    //temp variable that stores true or false
  int temp = A - 65;    //variable for index 
  if(Gtable[temp].visit == 0)  //if the given vertex was not visited, return false
    return !Marked;
  else
    return Marked;  //return true
}
