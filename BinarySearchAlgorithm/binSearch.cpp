/**************************************************
 *  Binary Search
 * 
 *  Given a sorted array of n integers and target value, determine
 *  if the target exists in the array, print the index of it.
 * 
 * 
 * ***********************************************/
#include <iostream>
#include <stdio.h>

using namespace std;

int binSearch(int *arr, int target, int start, int end);

/********************************************************
 * 
 *  Using commandline parameters for the input data
 *  argc: this is the size of the parameter array. It is used
 *          for calculating the size of the input array
 *  argsv: this array holds both the target and the sorted array
 *          At index 1, is the target value, and the rest of the 
 *          values are the sorted array
 * 
 * ***************************************************/
int main(int argc, char **argsv) {
    // initialize target
    int target;
    // create int array for easier processing
    int arr[argc-2];
    
    // convert all the *char values to int and put them in array
    for(int x = 1; x < argc; x++) {
        if(x == 1)
            target = atoi(argsv[x]);
        else
            arr[x-2] = atoi(argsv[x]);
    }

    // call binary search function. It should return the index of the
    // array if it is in the array or -1 if it is not in the array
    int x =  binSearch(arr, target, 0, argc-3);

    if(x < 0)
        printf("%d is not in the array\n", target);
    else
        printf("%d is at index: %d\n", target, x);
    
}

/**************************************************************
 * 
 *  Binary Search
 * *arr: pointer to beginning of the array
 * target: the number that we are searching for in the array
 * start: the first index in the part of the array that we are searching in
 * end: the last index in the array that we are searching in
 * 
 * ***********************************************************/
int binSearch(int *arr, int target, int start, int end) {
    
    int mid = ( start + end) / 2;
    printf("\nstart: %d, mid: %d, end: %d, target: %d, mid-value: %d\n", start, mid, end, target, arr[mid]);
    getchar();
    if(target == arr[mid])
        return mid;
    else if (start == end)
        return -1;
    else if (target < arr[mid])
        return binSearch(arr, target, start, mid-1);
    else
        return binSearch(arr, target, mid+1, end);
}