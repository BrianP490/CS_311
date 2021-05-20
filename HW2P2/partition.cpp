#include<iostream>
using namespace std;
//----------------------------------------
//CS311 HW2P2 Partition
//Name: Brian Perez
//Compiler: g++
//-----------------------------------------

// partitions the array a into smaller than pivot and others.
// f is the beginning of the section to be partitioned
// r is the end of the section to be partitioned
// return the first slot of the Large section
int partition(int pivot, int a[], int f, int r)
{
  int left = f; // pointer from the left
  int right = r; // pointer from the right 
  int i;  //create a local variable for the for loop later
  int temp; //create a temporary int variable (used for swapping values)

  // loop for finding out of place pairs and swap them
  // loop until the left and right cross
  while (left <= right){
    if(a[left] > a[right]){//if the value in the array at index left is greater than the value in the array at index right, enter the following procedure
      cout << "Swap " << a[left] << " and " << a[right] << endl; 
      //if both are bad, swap
      temp = a[right];
      a[right] = a[left];
      a[left] = temp;

      //swap the contents of right and left 
      temp = right;
      right = left;
      left = temp;
    }
    //otherwise, decrement the right index
    else{right--;}
  }

  //find the index where the elements start to become greater to or equal to the pivot
  for(i = 0; a[i] < pivot;i++)
    {}
  
  // return the partition point where
  // those smaller than pivot are before what is returned
  // ** there is a special cases and a regular case
  
  if(i == 0)//if the index is 0 return 0    
    return 1;
  
  else//otherwise return the index i
    return i;
}

int main()
{
  int x;  // number of elements
  int nums[10];
  cout << "How many elements? (must be less than 10) "; 
  cin >> x;
  cout << "Enter elements one per line.." << endl;
  for (int i = 0; i < x; i++)
    { cin >> nums[i]; }

  // the pivot is always the first element
  cout << "Ok the pivot is " << nums[0] << endl;

  int part = partition(nums[0], nums, 0, x-1);

  cout << "Results..." << endl;
  // display up to the partition without endl
  for (int i = 0; i < part; i++)
    cout << nums[i];

  cout << "|";
  // display from the partition on.. without endl
  for (int i = part; i < x; i++)
    cout << nums[i];

  cout << endl;
  return 0;
}
