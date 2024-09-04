/*
Selection Sort Algorithm

Suppose we are given an array of integers, and we are asked to sort them using the selection sort algorithm, then the array after being sorted would look something like this.

    index: 0 1 2 3 4      --->  index: 0 1 2 3 4
    value: 8 0 7 1 3            value: 0 1 3 7 8
        unsorted array                sorted array

In selection sort, at each pass, we make sure that the smallest element of the current unsorted subarray reaches its final position. And this is pursued by finding the smallest element in the unsorted subarray and replacing it at the end with the element at the first index of the unsorted subarray. This algorithm reduces the size of the unsorted part by 1 and increases the size of the sorted part by 1 at each respective pass. Let’s see how these work. Take a look at the unsorted array above, and I'll walk you through each pass one by one and you will see how we reach the result.

At each pass, we create a variable min to store the index of the minimum element. We start by assuming that the first element of the unsorted subarray is the minimum. We will iterate through the unsorted part of the array, and compare every element to this element at min index. If the element is less than the element at min index, we replace min by the current index and move ahead. Else, we keep going. And when we reach the end of the array, we replace the first element of the unsorted subarray with the element at min index. And doing this at every pass ensures that the smallest element of the unsorted part of the array reaches its final position at the end.

Since our array is of length 5, we will make 4 passes. You must have realized by now the reason why it would take just 4 passes.

1st Pass:

At first pass, our whole array comes under the unsorted part. We will start by assuming 0 as the min index. Now, we’ll have to check among the remaining 4 elements if there is still a lesser element than the first one.
        unsorted
        0 1 2 3 4
        8 0 7 1 3
        ^->
        |
        min
And when we compared the element at min index with the element at index 1, we found that 0 is less than 8 and hence we update our min index to 1.
        unsorted
        0 1 2 3 4
        8 0 7 1 3
          ^->
          |
          min
And now we keep checking with the updated min. Since 7 is not less than 0, we move ahead.
        unsorted
        0 1 2 3 4
        8 0 7 1 3
          ^--->
          |
          min
And now we compared the elements at index 1 and 3, and 0 is still lesser than 1, so we move ahead without making any changes.
        unsorted
        0 1 2 3 4
        8 0 7 1 3
          ^----->
          |
          min
And now we compared the element at the min index with the last element. Since there is nothing to change, we end our 1st pass here. Now we simply replace the element at 0th index with the element at the min index. And this gives us our first sorted subarray of size 1. And this is where our first pass finishes. We should make an overview of what we received at the end of the first pass.

   sorted| unsorted
        0| 1 2 3 4
        0| 8 7 1 3

Similarly,
2nd Pass:
    sorted | unsorted
        0 1| 2 3 4
        0 1| 7 8 3

3rd Pass:
       sorted | unsorted
        0 1 2 | 3 4
        0 1 3 | 8 7

4th Pass:
          sorted | unsorted
         0 1 2 3 | 4
         0 1 3 7 | 8
And since a subarray with a single element is always sorted, we ignore the only unsorted part and make it sorted too.
          sorted
         0 1 2 3 4
         0 1 3 7 8

And this is why the Selection Sort algorithm got its name. We select the minimum element at each pass and give it its final position. Few conclusions before we proceed to the programming segment:

1. Time Complexity of Selection Sort:
    We made 4 passes for an array of length 5. Therefore, for an array of length n we would have to make n-1 passes. And if you count the number of comparisons we made at each pass, there were (4+3+2+1), that is, a total of 10 comparisons. And every time we compared; we had a fair possibility of updating our min. So, 10 comparisons are equivalent to making 10 updates.

    So, for length 5, we had 4+3+2+1 number of comparisons. Therefore, for an array of length n, we would have (n-1) + (n-2) + (n-3) + (n-4) + . . . . . + 1 comparisons.

    Sum from 1 to n-1, we get , and hence the time complexity of the algorithm would be O(n2).

2. Selection sort algorithm is not a stable algorithm. Since the smallest element is replaced with the first element at each pass, it may jumble up positions of equal elements very easily. Hence, unstable. 

3. It is not a recursive algorithm, since we didn’t use recursion here.

4. Selection sort would anyways compare every element with the min element, regardless of the fact if the array is sorted or not, hence selection sort is not an adaptive algorithm by default.

5. This algorithm offers the benefit of making the least number of swaps to sort an array. We don’t make any redundant swaps here
*/

#include<stdio.h>

void printArray(int* A, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionSort(int *A, int n){
    int indexOfMin, temp;
    printf("Running Selection sort...\n");
    for (int i = 0; i < n-1; i++)
    {
        indexOfMin = i;
        for (int j = i+1; j < n; j++)
        {
            if(A[j] < A[indexOfMin]){
                indexOfMin = j;
            }
        }
        // Swap A[i] and A[indexOfMin]
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}

int main(){
    // Input Array (There will be total n-1 passes. 5-1 = 4 in this case!)
    //  00  01  02  03  04
    // |03, 05, 02, 13, 12

    // After first pass
    //  00  01  02  03  04
    //  02,|05, 03, 13, 12

    // After second pass
    // 00  01  02  03  04
    // 02, 03,|05, 13, 12

    // After third pass
    // 00  01  02  03  04
    // 02, 03, 05,|13, 12

    // After fourth pass
    // 00  01  02  03  04
    // 02, 03, 05, 12,|13


    int A[] = {3, 5, 2, 13, 12};
    int n = 5;
    printArray(A, n);
    selectionSort(A, n);
    printArray(A, n);

    return 0;
}
