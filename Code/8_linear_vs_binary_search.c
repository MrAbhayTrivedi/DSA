/*
Linear Search:
This search method searches for an element by visiting all the elements sequentially until the element is found or the array finishes. It follows the array traversal method.
    index: 0 1 2 3 4 5 6 7 8 9
    value: 1 2 3 8 5 6 7 2 9 10         --> Array can be sorted or unsorted
              \
               \  
Search for '2'  Element found at index 1

WC Complexity: O(n)

Binary Search:
This search method searches for an element by breaking the search space into half each time it finds the wrong element. This method is limited to a sorted array. The search continues towards either side of the mid, based on whether the element to be searched is lesser or greater than the mid element of the current search space.

        index: 0 1 2 3 4 5 6 7 8
        value: 1 2 3 8 5 6 7 2 9        --> Array must be sorted
               ^       ^       ^
               |       |       |
               low     mid     high

Search for '8'                           WC Complexity: O(log n)

From the above illustrations, we can draw a comparison between both the search methods based on their choice of arrays, operations, and worst-case complexities. 

 	
Linear Search                               Binary Search

1.Works on both sorted and unsorted arrays  Works only on sorted arrays

2.Equality operations                       Inequality operations

3.O(n) WC Complexity                        O(log n) WC Complexity


*/

#include<stdio.h>
 
int linearSearch(int arr[], int size, int element){
    for (int i = 0; i < size; i++)
    {
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}
 
int binarySearch(int arr[], int size, int element){
    int low, mid, high;
    low = 0;
    high = size-1;
    // Keep searching until low <= high
    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid] == element){
            return mid;
        }
        if(arr[mid]<element){
            low = mid+1;
        }
        else{
            high = mid -1;
        }
    } 
    return -1;
    
}
 
int main(){
    // Unsorted array for linear search
    // int arr[] = {1,3,5,56,4,3,23,5,4,54634,56,34};
    // int size = sizeof(arr)/sizeof(int);
    // int searchIndex=linearSearch(arr, size, 4);
    // printf("The element %d was found at index %d \n", 4, searchIndex);

    // Sorted array for binary search
    int arr[] = {1,3,5,56,64,73,123,225,444};
    int size = sizeof(arr)/sizeof(int);
    int element = 444;
    int searchIndex = binarySearch(arr, size, element);
    printf("The element %d was found at index %d \n", element, searchIndex);
    return 0;
}
