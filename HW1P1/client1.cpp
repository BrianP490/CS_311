//CS311 Yoshii
//INSTRUCTION:
//Look for ** to complete this program (Use control-S)
//The output should match my hw1stackDemo.out 

//=========================================================
//HW#: HW1P1 stack application (post-fix evaluation)
//Your name: Brian Perez
//Complier:  g++
//File type: client program client1.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"

//Purpose of the program: The purpose of the program is to solve a postfix expression. It will give the client error messages i
//Algorithm: Using a stack, the program reads from a string and when it encounters an expression like '+' or '*', it will perform the operation on the top two items from the stack. At the end of the program, it will display the result or display an error message about why it could not create a solution.  
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  
  while (expression[i] != '\0')
    {
     try
       {
	 item = expression[i];  // current char
	 if(item == '-' || item == '+' || item == '*') {  //check for operation symbols
	   postfixstack.pop(box2);  //gets the value of the top of stack and passes it to box2
	   postfixstack.pop(box1);  //pops the top value form the stack and places it into box1
	   
	   switch(item) {  //check to see what operation to do
	     
	   case '+':   //adds the two poped elements and adds the result into the stack
	     box1 = box1 + box2;
	     postfixstack.push(box1);
	     break;
	   case '-':  //subtract bo2 from box1 and pushes the result into stack
	     box1 = box1 - box2;
	     postfixstack.push(box1);
	     break;
	   case '*':  //multiplies the popped elements and pushes the product into the stack
	     box1 = box1 * box2;
	     postfixstack.push(box1);
	     break;
	   }
	 }
	 else if(item >= 48 && item <= 57){    //if the number is between 0 and 9 it pushes the number into the stack
	   postfixstack.push(item - 48);}  //converts the char into an integer for the stack to use

	 else throw "Invalid element";    //throws an error msg if invalid element is in the string
	 
	 
       } // this closes try
      // Catch exceptions and report problems and quit the program now (exit(1)). 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow) 
	{cerr << "Error: You have caused the stack to overflow. Too many operands. " << endl; exit(1);}
      catch (stack::Underflow)
	{cerr << "Error: You have caused the stack to underflow. Too few operands." << endl; exit(1);}
      catch (char const* errormsg ) // for invalid item case
	{cerr << "Error has occured - Type is: " << errormsg << endl; exit(1); }

      // go back to the loop after incrementing i
     i++;
    }// end of while
  
 // After the loop successfully completes: 
 // Pop the result and show it.
  postfixstack.pop(box2);
  cout << "The result is: " << box2 << endl;
 // If anything is left on the stack, an incomplete expression 
 // was found so inform the user.
  if(!postfixstack.isEmpty())
    {
      cout << "The stack is not empty. The result is incomplete. The program will now termitate." << endl << endl;
    }
     return 0;
}// end of the program
