//CS311 Yoshii
//INSTRUCTION:
//Look for ** to complete this program 
//The string output should match my hw1queueDemo.out 

//=========================================================
//HW#: HW1P2 queue application (generate all strings)
//Your name: Brian Perez
//Complier:  g++
//File type: client program client2.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "queue.h"

//Purpose of the program: The purpose of the program is generate all the possible combinations that can be made with the letters A, B, and C in different sizes strings.
//Algorithm: Add first the letters(A, B, and C) to the queue then each time, dequeue the first element attach A, B, and C to the ends making three new strings ,and add them to the queue.
int main()
{ 
  queue entries;       //create an instancs of the queue class called entries
  el_t temp;           //user defined string variable
  // add "A", "B", "C" in the queue
  entries.add("A");
  entries.add("B");
  entries.add("C");

  //enter and stay in the while loop until the queue has overflown by using up all the 50 slots
  while(entries.getSize() <= MAX_SIZE) 
    {
      try
	{ 
	  entries.remove(temp);  //remove the first element of the queue
	  cout << temp << endl;
	  //add the letters A, B, and C onto the temp and push it into the queue at the end
	  entries.add(temp + "A");    
	  entries.add(temp + "B");
	  entries.add(temp + "C");
	}

      //catch exeptions and report the problems and quit the program using exit function call
      catch(queue::Overflow)
	{cerr << "Error: You have caused the queue to overflow." << endl; exit(1);}
      catch(queue::Underflow)
	{cerr << "Error: You have caused the queue to underflow. The program will now terminate." << endl; exit(1);}
    
    }// end of whileloop
  return 0;
}

