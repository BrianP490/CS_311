Brian Perez
CS311
2/21/20
HW2P1 binsearch.cpp


using namespace std;
#include <iostream>

//--------------------------------------------
// CS311 HW2P1 Binary Search
// Name: Brian Perez
// Compiler: g++
// --------------------------------------------

/****************
This program will search an array, which is presorted in ascending order, using a binary search algorithm.
********************/

//This funstion will use comparisons to check if the number is found in the array. If found, it will return the location of the number array as an index. However, it will return -1 if the number is not found.
// x is what we are looking for in L; first and last are slot numbers
// 
int binarySearch(int L[], int x, int first, int last) 
{ int middle;      //variable for the middle index
  int found = -1;   //stores the index where L[] == x, set at -1 by default 

  //this while loop continues until the number we are looking for is found or we have searched the entire array
  while(first <= last && found == -1){   
    middle = (first + last)/2;   //set the middle in between the first and last positions
    cout << "comparing against an element in slot " << middle << endl;
    
    if(x == L[middle]){   //store the value of middle in found if the number inside the array at index "middle" are identical
      found = middle;}
    
    else if(x < L[middle]){   //narrow the scope of the array to just the left of the middle index 
      last = middle -1;}
    
    else{         //narrow the scope of the array to just the right of the middle index 
      first = middle +1;} 
  };

  return found;  //return the index 
}


int main()
{ int A[10];
  int e;  // to look for this

  // fixed elements for A
  A[0] = 1; A[1]= 3; A[2]=5; A[3]= 7; A[4]=9; A[5]=11; A[6]=13;
  A[7] =15; A[8]= 17; A[9]= 19;

  cout << "What do you want to look for? ";
  cin >> e;

  // Call binarySearch here to look for e in A
  int respos = binarySearch(A, e, 0, 9);

  if (respos == -1) cout << "Element not found" << endl; 
  else cout << "Found it in position " << respos+1 << endl;
  return 0;
}
