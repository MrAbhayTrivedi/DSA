/*
QuickSort Algorithm

The QuickSort algorithm is quite different from the ones we have studied so far. Here, we use the divide and conquer method to sort our array in pieces reducing our effort and space complexity of the algorithm. There are two new concepts you must know before you jump into the core. First is the divide and conquer method. As the name suggests, Divide and Conquer divides a problem into subproblems and solves them at their levels, giving the output as a result of all these subproblems. The second is the partition method in sorting. In the partition method, we choose an element as a pivot and try pushing all the elements smaller than the pivot element to its left and all the greater elements to its right. We thus finalize the position of the pivot element. QuickSort is implemented using both these concepts.

Suppose we are given an array of integers, and we are asked to sort them using the quicksort algorithm, then the very first task you would do is to choose a pivot. Pivots are chosen in various ways, but for now, we’ll consider the first element of every unsorted subarray as the pivot. Remember this while we proceed.

    index: 0 1 2 3 4 5 6 7 8 9
    value: 2 4 3 9 1 4 8 7 5 6
            unsorted array

In the quicksort algorithm, every time you get a fresh unsorted subarray, you do a partition on it.  Partition asks you to first choose an element as a pivot. And as already decided, we would choose the first element of the unsorted subarray as the pivot. We would need two more index variables, i and j. Below enlisted is the flow of our partition algorithm we must adhere to. We always start from step 1 with each fresh partition call.

    1. Define i as the low index, which is the index of the first element of the subarray, and j as the high index, which is the index of the last element of the subarray.
    2. Set the pivot as the element at the low index i since that is the first index of the unsorted subarray.
    3. Increase i by 1 until you reach an element greater than the pivot element.
    4. Decrease j by 1 until you reach an element smaller than or equal to the pivot element.
    5. Having fixed the values of i and j, interchange the elements at indices i and j.
    6. Repeat steps 3, 4, and 5 until j becomes less than or equal to i.
    7. Finally, swap the pivot element and the element at the index.
This was the partitioning algorithm. Every time you call a partition, the pivot element gets its final position. A partition never guarantees a sorted array, but it does guarantee that all the smaller elements are located to the pivot’s left, and all the greater elements are located to the pivot’s right.

Now let's look at how the array we received at the beginning gets sorted using partitioning and divide and conquer recursively for smaller subarrays.

Firstly, the whole array is unsorted, and hence we apply quicksort on the whole array.

Now, we apply a partition in this array. Applying partition asks you to follow all the above steps we discussed.
    index: 0 1 2 3 4 5 6 7 8 9
    value: 2 4 3 9 1 4 8 7 5 6
           ^                 ^
           |                 |
           pivot (i)         j
        current unsorted array

Keep increasing i until we reach an element greater than the pivot, and keep decreasing j until we reach an element smaller or equal to the pivot.
    index: 0 1 2 3 4 5 6 7 8 9
    value: 2 4 3 9 1 4 8 7 5 6
           ^ i     j
           |                 
           pivot         
        current unsorted array
Swap the two elements and continue the search further until j crosses i or becomes equal to i.
    index: 0 1 2 3 4 5 6 7 8 9
    value: 2 1 3 9 4 4 8 7 5 6
           ^ j i
           |                 
           pivot         
        current unsorted array
As j crossed i while searching, we followed the final step of swapping the pivot element and the element at j.
    index: 0 1 2 3 4 5 6 7 8 9
    value: 1 2 3 9 4 4 8 7 5 6
             ^
             |                 
             pivot         
        current unsorted array
And this would be the final position of the current pivot even in our sorted array. As you can see, all the elements smaller than 2 are on the left, and the rest greater than 2 are on the right. Here comes the role of divide and conquer. We separate our focus from the whole array to just the subarrays, which are not sorted yet.  Here, we have subarrays {1} and {3, 9, 4, 4, 8, 7, 5, 6} unsorted. So, we make a call to quicksort on these two subarrays.

Now since the first subarray has just a single element, we consider it sorted.
Similarly, we will apply same steps on next subarray and so on.        i             j
    index: 0 1    2 3 4 5 6 7 8 9
    value: 1 2    3 9 4 4 8 7 5 6
                  ^
                  |                 
                  pivot         
                  current unsorted array
                   i           j
    index: 0 1 2   3 4 5 6 7 8 9
    value: 1 2 3   9 4 4 8 7 5 6
                   ^
                   |                 
                   pivot         
                   current unsorted array
                   i         j
    index: 0 1 2   3 4 5 6 7 8    9
    value: 1 2 3   6 4 4 8 7 5    9
                   ^
                   |                 
                   pivot         
                   current unsorted array
                            
    index: 0 1 2   3 4 5   6    7 8    9
    value: 1 2 3   5 4 4   6    7 5    9
                     |           |
                   unsorted     unsorted
    index: 0 1 2 3 4 5 6 7 8 9
    value: 1 2 3 4 4 5 6 7 8 9
            sorted

*/
#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high)
{
    int partitionIndex; // Index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(A, low, high); 
        quickSort(A, low, partitionIndex - 1);  // sort left subarray 
        quickSort(A, partitionIndex + 1, high); // sort right subarray
    }
}

int main()
{
    //int A[] = {3, 5, 2, 13, 12, 3, 2, 13, 45};
    int A[] = {9, 4, 4, 8, 7, 5, 6};
    // 3, 5, 2, 13, 12, 3, 2, 13, 45
    // 3, 2, 2, 13i, 12, 3j, 5, 13, 45
    // 3, 2, 2, 3j, 12i, 13, 5, 13, 45 --> first call to partition returns 3
    int n = 9;
    n =7;
    printArray(A, n);
    quickSort(A, 0, n - 1);
    printArray(A, n);
    return 0;
}

/*
Analysis of QuickSort Sorting Algorithm
In the last video, we learned to use the quick sort algorithm. We saw how we used the methods of divide and conquer and partitioning to achieve sorting. Later, in the video, we even saw the program to implement all these methods to sort an array using the quick sort algorithm. Today, we’ll see the analysis of the quicksort algorithm on all criteria we defined earlier.

1. Time Complexity:
Let’s start with the runtime complexity of the algorithm:

Worst Case:

The worst-case in a quicksort algorithm happens when our array is already sorted.
That is, for an array of size n, there would be (n-1) partitions. Now, during each partition, long story short, we made our two index variables, i and j run from either direction towards each other until they actually become equal or cross each other. And we do some swapping in between as well. These operations count to some linear function of n, contributing O(n) to the runtime complexity.

And since there are a total of (n-1) partitions, our total runtime complexity becomes n(n-1) which is simply O(n2). This is our worst-case complexity.

Best Case:

The condition when our algorithm performs in its best possible time complexity is when our array gets divided into two almost equal subarrays at each partition. Below mentioned tree defines the state of best-case when we apply quicksort on an array of 16 elements, of which each newly made subarray is almost half of its parent array.

No. partitions were different at each level of the tree. If we count starting from the top, the top-level had one partition on an array of length (n=16), the second level had 2 partitions on arrays of length n/2, then the third level had 4 partitions on arrays of length n/4… and so on.

Here, T(x) is the time taken during the partition of the array with x elements. And as we know, the partition takes a linear function time, and we can assume T(x) to be equal to x; hence the total time complexity becomes,

Total time = 1(n) + 2(n/2) +4(n/4) + ..........+ until the height of the tree(h) Total time = n*h

Now, can you decide what h is? H is the height of the tree, and the height of the tree, if you remember, is log2(n), where n is the size of the given array. In the above example, h = 4, since log2(16) equals 4. Hence the time complexity of the algorithm in its best case is O(nlogn).

Note: The average time complexity remains O(nlogn). Calculations have been avoided here due to their complexity.

2. Stability:
The QuickSort algorithm is not stable. It does swaps of all kinds and hence loses its stability.

3. Quicksort algorithm is an in-place algorithm. It doesn't consume any extra space in the memory. It does all kinds of operations in the same array itself.
4. There is no hard and fast rule to choose only the first element as the pivot; rather, you can have any random element as its pivot using the rand() function and that you wouldn’t believe actually reduces the algorithm's complexity.
*/