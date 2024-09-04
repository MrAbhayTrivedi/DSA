/*
Count Sort Algorithm

Suppose we are given an array of integers and are asked to sort them using any sorting algorithm of our choice, then it is not difficult to generate the resultant array, which is just the sorted form of the given array. Still, the method you choose to reach the result matters the most.  Count Sort is one of the fastest methods of all. We will discuss constraints later, which would make you wonder why we don't use just this. We will do all the analysis, but before that, let’s see what count sort is. The below figure shows the array given.

index: 0 1 2 3 4 5 6
value: 3 1 9 7 1 2 4
        unsorted array

1. The algorithm first asks you to find the largest element from all the elements in the array and store it in some integer variable max. Then create a count array of size max+1. This array would count the no. of occurrences of some number in the given array. We will have to initialize all count array elements with 0 for that to work.

2. After initializing the count array, traverse through the given array, and increment the value of that element in the count array by 1. By defining the size of the count array as the maximum element in the array, you ensure that each element in the array has its own corresponding index in the count array. After we traverse through the whole array, we’ll have the count of each element in the array.

3. Now traverse through the count array, and look for the nonzero elements. The moment you find an index with some value other than zero, fill in the sorted array the index of the non-zero element until it becomes zero by decrementing it by 1 every time you fill it in the resultant array. And then move further. This way, you create a sorted array. Let’s take the one we have as an example above and use the count sort algorithm to sort it.


First of all, find the maximum element in the array. Here, it is 9. So, we’ll create a count array of size 10 and initialize every element by 0.
                   i
            index: 0 1 2 3 4 5 6  
            value: 3 1 9 7 1 2 4     Max=9
                unsorted array

            index: 0 1 2 3 4 5 6 7 8 9
            value: 0 0 0 0 0 0 0 0 0 0     
                     Count Array

Now, let’s iterate through the given array and count the no. of occurrences of each number less than equal to the maximum element.
                                 i
            index: 0 1 2 3 4 5 6  
            value: 
                unsorted array

            index: 0 1 2 3 4 5 6 7 8 9
            value: 0 2 1 1 1 0 0 1 0 1     
                     Count Array

We would iterate through the count array and fill the unsorted array with the index we encounter having a non-zero number of occurrences.
                   i
            index: 0 1 2 3 4 5 6  
            value: 
                unsorted array
                   j
            index: 0 1 2 3 4 5 6 7 8 9
            value: 0 2 1 1 1 0 0 1 0 1     
                     Count Array
Now since there are zero numbers of zeros in the given array, we move further to index 1.
                   i
            index: 0 1 2 3 4 5 6  
            value: 
                  sorted array
                     j
            index: 0 1 2 3 4 5 6 7 8 9
            value: 0 2 1 1 1 0 0 1 0 1     
                     Count Array
And since there were two ones in the array we were given, we push two ones in the sorted array and move our iterator to the next empty index.
                       i
            index: 0 1 2 3 4 5 6  
            value: 1 1
                  sorted array
                       j
            index: 0 1 2 3 4 5 6 7 8 9
            value: 0 0 1 1 1 0 0 1 0 1     
                     Count Array
And following a similar procedure for all the elements in the count array, we reach our sorted array in no time.
                                 i
            index: 0 1 2 3 4 5 6  
            value: 1 1 2 3 4 7 9
                  sorted array
                                       j
            index: 0 1 2 3 4 5 6 7 8 9
            value: 0 0 0 0 0 0 0 0 0 0     
                     Count Array
*/

#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}


int maximum(int A[], int n){
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < A[i]){
            max = A[i];
        }
    }
    return max;
    
}
void countSort(int * A, int n){
    int i, j;
    // Find the maximum element in A
    int max = maximum(A, n); 

    // Create the count array
    int* count = (int *) malloc((max+1)*sizeof(int));

    // Initialize the array elements to 0
    for (i = 0; i < max+1; i++)
    {
        count[i] = 0; 
    }

    // Increment the corresponding index in the count array
    for (i = 0; i < n; i++)
    {
        count[A[i]] = count[A[i]] + 1; 
    }

    i =0; // counter for count array
    j =0; // counter for given array A

    while(i<= max){
        if(count[i]>0){
            A[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else{
            i++;
        }
    } 
}

int main(){
    int A[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;
    printArray(A, n);
    countSort(A, n);
    printArray(A, n); 
    return 0;
}
/*
Time Complexity of Count Sort: 
Calculating the time complexity of the count sort algorithm is one of the easiest jobs to do. If you carefully observe the whole process, we only ran two different loops, one through the given array and one through the count array, which had the size equal to the maximum element in the given array. If we suppose the maximum element to be m, then the algorithm's time complexity becomes O(n+m), and for an array of some huge size, this reduces to just O(n), which is the most efficient by far algorithm. However, there is a negative point as well. The algorithm uses extra space for the count array.  And this linear complexity is reachable only at the cost of the space the count array takes.
*/