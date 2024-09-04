/*
Bubble Sort Algorithm

Suppose we are given an array of integers and are asked to sort them using the bubble sort algorithm, then it is not difficult to generate the resultant array, which is just the sorted form of the given array. In fact, whichever algorithm you follow, the result would be the same. The below figure shows the same.

    index: 0 1  2 3 4  5    --->    index: 0 1 2 3 4  5
    value: 7 11 9 2 17 4            value: 2 4 7 9 11 17

The difference lies in the algorithm we follow. With bubble sort, we intend to ensure that the largest element of the segment reaches the last position at each iteration.  It's important for us to know how that will be pursued. 

Bubble sort intends to sort an array using (n-1) passes where n is the array's length. And in one pass, the largest element of the current unsorted part reaches its final position, and our unsorted part of the array reduces by 1, and the sorted part increases by 1. Take a look at the unsorted array above, and I'll walk you through each pass one by one, so you can feel how it gets sorted.

At each pass, we will iterate through the unsorted part of the array and compare every adjacent pair. We move ahead if the adjacent pair is sorted; otherwise, we make it sorted by swapping their positions. And doing this at every pass ensures that the largest element of the unsorted part of the array reaches its final position at the end.

Since our array is of length 6, we will make 5 passes.

1st Pass:
At first pass, our whole array comes under the unsorted part. We will start by comparing each adjacent pair. Since our array is of length 6, we have 5 pairs to compare.

Let’s start with the first one.
          |```|
    index: 0 1  2 3 4  5
    value: 7 11 9 2 17 4
Since these two are already sorted, we move ahead without making any changes.
             |```|
    index: 0 1  2 3 4  5
    value: 7 11 9 2 17 4
Now since 9 is less than 11, we swap their positions to make them sorted.
                |```|
    index: 0 1  2  3 4  5
    value: 7 9  11 2 17 4
Again, we swap the positions of 11 and 2.
                  |```|
    index: 0 1  2  3  4  5
    value: 7 9  2  11 17 4
We move ahead without changing anything since they are already sorted.
                      |```|
    index: 0 1  2  3  4  5
    value: 7 9  2  11 17 4

Here, we make a swap since 17 is greater than 4.

And this is where our first pass finishes. We should make an overview of what we received at the end of the first pass.

    index: 0 1  2 3 4  5    --->    index: 0 1 2 3  4  5
    value: 7 11 9 2 17 4            value: 7 9 2 11 4 17
          |_____________|                  |_________||__|    
          Unsorted array                   Unsorted   Sorted
                                           array      array
Similarly,
2nd Pass:
    index: 0 1 2 3  4  5    --->    index: 0 1 2 3  4  5 
    value: 7 9 2 11 4 17            value: 7 2 9 4  11 17
          |_________||__|                 |_______||_____|
          Unsorted   Sorted               Unsorted   Sorted
          array      array                array      array

3rd Pass:
    index: 0 1 2 3 4  5    --->    index: 0 1 2 3 4  5 
    value: 7 9 2 4 11 17           value: 2 7 4 9 11 17
          |_______||___|                 |_____||_____|
          Unsorted  Sorted               Unsorted Sorted
          array     array                array    array

4th Pass:
    index: 0 1 2 3 4  5    --->    index: 0 1 2 3 4  5 
    value: 2 7 4 9 11 17           value: 2 4 7 9 11 17
          |_____||_____|                  |__||_______|
          Unsorted Sorted              Unsorted Sorted
          array    array               array    array

5th Pass:
    index: 0 1 2 3 4  5    --->    index: 0 1 2 3 4  5 
    value: 2 4 7 9 11 17           value: 2 4 7 9 11 17
          |___||_______|                  |___________|
          Unsorted Sorted                   Sorted
          array    array                    array
And this is what the Bubble Sort algorithm looks like. 

Time Complexity of Bubble Sort:

    -> If you count the number of comparisons we made, there were (5+4+3+2+1), that is, a total of 15 comparisons. And every time we compared, we had a fair probability of making a swap. So, 15 comparisons intend to make 15 possible swaps.  Let us quickly generalize this sum. For length 6, we had 5+4+3+2+1 number of comparisons and possible swaps. Therefore, for an array of length n, we would have (n-1) + (n-2) + (n-3) + (n-4) + . . . . . + 1 comparison and possible swaps.
    -> This is a high school thing to find the sum from 1 to n-1, which is n(n-1)/2, and hence our complexity of runtime becomes O(n^2).
    -> And if you could observe, we never made a swap when two elements of a pair become equal. Hence the algorithm is a stable algorithm. 
    -> It is not a recursive algorithm since we didn’t use recursion here.
    -> This algorithm has no adaptive aspect since every pair will be compared, even if the array given has already been sorted. So, no adaptiveness. Although it can be modified to make it adaptive, it's not adaptive by default. We’ll see in the next lecture how it can be made adaptive.

Before we wrap up, bubble sort is called bubble because it bubbles up lighter elements to the left and stores larger elements towards the right.
*/

#include<stdio.h>
 
void printArray(int* A, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void bubbleSort(int *A, int n){
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n-1; i++) // For number of pass
    {
        printf("Working on pass number %d\n", i+1); 
        for (int j = 0; j <n-1-i ; j++) // For comparison in each pass
        {
            if(A[j]>A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp; 
            }
        }  
    } 
}
 

/*
Modifying bubbleSort to make it adaptive

What would an adaptive bubble sort do? Once it detects that our array has already been sorted, it will not perform any more comparisons. So, just a single pass should do the job.

Therefore, the catch here is that the array is already sorted if we didn't have to perform any swapping during any of the passes. This is where we will stop making any more passes.
We will make an integer variable isSorted which would hold 1 if our array is sorted and 0 otherwise. Make isSorted equal to 1 prior to starting any comparison in each pass. If any of our comparisons demands swapping of elements, we switch isSorted to 0. 

At the end of each pass, check if the isSorted changed to 0. If it did, our array was not yet sorted; otherwise, end the comparison there itself, since our array was already sorted.
*/ 
void bubbleSortAdaptive(int *A, int n){
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n-1; i++) // For number of pass
    {
        printf("Working on pass number %d\n", i+1);
        isSorted = 1;
        for (int j = 0; j <n-1-i ; j++) // For comparison in each pass
        {
            if(A[j]>A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                isSorted = 0;
            }
        } 
        if(isSorted){
            return;
        }
    } 
}
 
int main(){
    // int A[] = {12, 54, 65, 7, 23, 9};
    int A[] = {1, 2, 5, 6, 12, 54, 625, 7, 23, 9, 987};
    // int A[] = {1, 2, 3, 4, 5, 6};
    int n = 11;
    printArray(A, n); // Printing the array before sorting
    bubbleSort(A, n); // Function to sort the array
    printArray(A, n); // Printing the array before sorting
    return 0;
}
