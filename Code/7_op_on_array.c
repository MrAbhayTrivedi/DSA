/*
Operations on Arrays in Data Structures: Traversal, Insertion, Deletion and Searching

Operations on an Array:
While there are many operations that can be implemented and studied, we only need to be familiar with the primary ones at this point.  An array supports the following operations:

    Traversal
    Insertion
    Deletion
    Search
Other operations include sorting ascending, sorting descending, etc. Let's follow up on these individually.

Traversal:
Visiting every element of an array once is known as traversing the array.

    Why Traversal?
    For use cases like:

    Storing all elements – Using scanf()
    Printing all elements – Using printf()
    Updating elements.
An array can easily be traversed using a for loop in C language.

An important note on Arrays:
If we create an array of length 100 using a[100] in C language, we need not use all the elements. It is possible for a program to use just 60 elements out of these 100. (But we cannot go beyond 100 elements).

            Index: 0 1 3 4 5 ........................... 99
            Value: 1 2 3 4 - -----------------------------
            4 bytes for each element

Insertion:
An element can be inserted in an array at a specific position. For this operation to succeed, the array must have enough capacity. Suppose we want to add an element 10 at index 2 in the below-illustrated array, then the elements after index 1 must get shifted to their adjacent right to make way for a new element.
        Index: 0 1 2 3 4 5 6        Elements need to be shifted
        Value: 1 2 3 4              to maintain the relative order
                   ^
                   |
                   10
When no position is specified, it’s best to insert the element at the end to avoid shifting, and this is when we achieve the best runtime O(1).

Deletion:
An element at a specified position can be deleted, creating a void that needs to be fixed by shifting all the elements to their adjacent left, as illustrated in the figure below.

We can also bring the last element of the array to fill the void if the relative ordering is not important. :)

        Index: 0 1 2 3 4 5 6 ......
        Value: 1 2 3 4 5 6 7 ......     Deleting element 3 at index 2

        Index: 0 1 2 3 4 5 6 ......
        Value: 1 2   4 5 6 7 ......     Shift the elements after index 2 to their adjacent left

        Index: 0 1 2 3 4 5 6 ......
        Value: 1 2 4 5 6 7 ......     Deletion done!

Searching:
Searching can be done by traversing the array until the element to be searched is found.O(n) There is still a better method. We had analyzed both linear and binary search. This search method is only applicable for sorted arrays. Therefore, for sorted arrays, the time taken to search is much less than an unsorted array. O(logn)

    index: 0 1 2 3 4 5 6 7 8 9 10.........
    value: 1 2 9 3 12 ....................
    ---------> Linear Search

Sorting:
Sorting means arranging an array in an orderly fashion (ascending or descending). We have different algorithms to sort arrays. 

    index: 0 1 2 3 4 5 6                    index: 0 1 2 3 4 5 6
    value: 1 2 9 3 12 10 15                 value: 1 2 3 9 10 12 15
    ------>Unsorted Array                   ------>Sorted Array
*/

#include<stdio.h>
 
 
void display(int arr[], int n){
    // Code for Traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");   
}
 
int indInsertion(int arr[], int size, int element, int capacity, int index){
    // code for Insertion
    if(size>=capacity){
        return -1;
    }
    for (int i = size-1; i >=index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1; 
}

void indDeletion(int arr[], int size, int index)
{
    // code for Deletion
    for (int i = index; i < size-1; i++)
    {
        arr[i] = arr[i + 1];
    }  
}

int main(){
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5, element = 45, index=1;
    display(arr, size); 
    indInsertion(arr, size, element, 100, index);
    size +=1;
    display(arr, size);

    indDeletion(arr, size, index);
    size -= 1;
    display(arr, size);
    return 0;
}
