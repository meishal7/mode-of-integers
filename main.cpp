/*
main.cpp This program allocates array of int dynamically. Takes user input, stores it into array, and finds the mode.
Author: Elena Mudrakova
Module: 3
Project: HW 3

Algorithm:
Before main()
1.  #include <iostream>
2. Include functions prototypes. 
In main()
1. Declare int length, slices.
2. Take user input for length.
3. Allocate array of int dynamically.
4. In for loop ask for user input for array elements and initialize array with user input.
5. Call bubbleSort(pieSlices, length).
6. Call findMode(pieSlices, length).
7. Delete allocated array.
8. Set pieSlices = nullptr.
After main()
1. Declare void swap(int *x, int *y)  
    1. int temp = *x;  
    2. *x = *y;  
    3. *y = temp; 
2. Declare void bubbleSort(int *arr, int length)  
    1. int i, j;  
    2. Create outer for loop ( i < length-1)
      In outer for loop:
      1.Create another for loop (j < length-i-1)
        In inner for loop: 
        1. if (arr[j] > arr[j+1])  
        2. swap(&arr[j], &arr[j+1])
3. Declare void findMode(int *arr, int length)
    3.1 Set int number = first element of array.
    3.2 Set mode = number
    3.3 Set count = 1 because we have the first number for now.
    3.4 Set countMode (it's the biggest number of times the number is repeated) = 1 because we have the first number for now.
    3.5 Iterate through array with for loop beginning from the second element
    In for loop:
      3.5.1 If number ie repeated, then count++
      3.5.2 Else (it's different number now) compare count and countMode. If count > countMode then the current number is repeated the most number of times, so countMode = count; mode = number
      3.5.6 Otherwise reset the count to 1 again, set number to current iterated element and begin counting again.  
*/
#include <iostream>
using namespace std;

//Prototypes
void bubbleSort(int *arr, int length);
void swap(int *x, int *y);
int avg(int arr[], int length);
void findMode(int *arr, int length);

int main() {
  int length, slices;
  
  //Take user input
  cout << "For how many people would you like to enter the number of pie slices?" << endl;
  cout << "Enter the number: ";
  
  cin >> length;
  
  //Allocate array of int
  int *pieSlices = new int[length];
  
  //Initialize array with user input
  for(int i = 0; i<length; i++){
    cout << "Enter the number of pie slices: ";
    //Input validation
    if(slices < 0){
      cout << "Invalid number. Number can not be negative. Try again." << endl;
      exit(0);
    }
    cin >> slices;
    pieSlices[i] = slices;
  }
  //Sort array
  bubbleSort(pieSlices, length);
  //Find the mode
  findMode(pieSlices, length);

  
  delete [] pieSlices;
  pieSlices = nullptr;
  
  return 0;
}

// Function declaration
// A function to swap elements of array
void swap(int *x, int *y)  
{  
    int temp = *x;  
    *x = *y;  
    *y = temp;  
}
// A function to implement bubble sort  
void bubbleSort(int *arr, int length)  
{  
    int i, j;  
    for (i = 0; i < length-1; i++){
      for (j = 0; j < length-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  

    }      
}
//A function to find the mode
void findMode(int *arr, int length){
  //Number for counting how many times it's repeated
  int number = arr[0];
  int mode = number;
  int count = 1;//number of times the current number is repeated
  int countMode = 1;//the biggest number of times the number is repeated

  for(int i=1; i<length; i++){
    //If the number is repeated, increase the count
    if(arr[i] == number) count++;
    //Now it's different number already
    else{
      //If count > countMode then current number is repeated the most number of times, we have a mode
      if(count > countMode){
        countMode = count;
        mode = number;
      }
      //Otherwise reset the count and begin counting the new number now 
      number = arr[i];
      count = 1;
    }
  }
  cout << "The mode is " << mode << endl;
}