
using namespace std;
#include <iostream>
#include <vector>

//--------------------------------------------
//CS311 HW2P2 Combine 
//Name: Brian Perez
//Compiler: g++
//--------------------------------------------

// combine two sorted lists A and B into R
// displays comparison every time it is done
void combine( vector<int> A, vector<int> B, vector<int> &R )
{int j = 0;     //create a temporary value for the second array's index
  int i;

  
  while(i < A.size() && j < B.size()){    //loop through both vectors entirely until one vector has been traversed 
    cout << "comparison" << endl;
    if(A[i] < B[j]){
      R.push_back(A[i]);//add the value of A[i] into vertex R
      i++;}//increase the counter for vector A

    else{R.push_back(B[j]);j++;}//otherwise, place B[j] into vertex R and update j
  }
  //determine which vector needs to be added to the vector R
  if(i<j){//go into the loop if the first index,i, has not been completly accessed
    cout << "The rest of the first one goes down" << endl;
    for(i; i < A.size(); i++)//go through the rest of the first vector
      R.push_back(A[i]);//add the elements to R
  }
  else{//add the rest of the second vecotr into R
    cout << "The rest of the second one goes down." << endl;
    for(j; j < B.size(); j++)//add all the remaining elements into R
      R.push_back(B[j]);
  }
}

int main()
{  
  vector<int> L1;
  vector<int> L2;
  vector<int> L3;
  int N;  // how many elements in each of L1 and L2
  int e;  // for each element

  cout << "How many elements in each list?" << endl;
  cin >> N;

  cout << "List1"  << endl;
  for (int i = 1; i <=N; i++)
    { cout << "element :"; cin >> e; L1.push_back(e);} 

  cout << "List2"  << endl; 
  for (int i = 1; i <=N; i++)
    { cout << "element :"; cin >> e; L2.push_back(e);} 
  

  // call combine here to combine L1 and L2 into L3
  combine(L1, L2, L3);
  
  cout << "The result is: ";
  for (int i = 0; i < N*2; i++)
    { cout << L3[i]; } cout << endl;
  return 0;
}// end of main
