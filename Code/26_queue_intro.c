/*
Queue as an English word must be a well-known thing to you. We stand in a queue while waiting for our turn to come. Indian railway is one of the places where people stand in a long queue, waiting for their chance to buy a ticket.  One important thing to observe, which is quite intuitive, is that your chance comes first when you come first in the queue. And the people standing last, who have joined the queue last, get to buy the ticket in the end.

Unlike stacks, where we followed LIFO( Last In First Out ) discipline, here in the queue, we have FIFO( First In First Out).

In stacks, we had to maintain just one end, head, where both insertion and deletion used to take place, and the other end was closed. But here, in queues, we have to maintain both the ends because we have insertion at one end and deletion from the other end.

Queue ADT
Data:

In order to create a queue, we need two pointers, one pointing to the insertion end, to gain knowledge about the address where the new element will be inserted to. And the other pointer pointing to the deletion end, which holds the address of the element which will be deleted first. Along with that, we need the storage to hold the element itself.

Methods:

Here are some of the basic methods we would want to have in queues:

1. enqueue() : to insert an element in a queue.
2. dequeue(): to remove an element from the queue
3. firstVal(): to return the value which is at the first position.
4. lastVal(): to return the value which is at the last position.
5. peek(position):  to return the element at some specific position.
6. isempty() / isfull(): to determine whether the queue is empty or full, which helps us carry out efficient enqueue and dequeue operations.

Array Implementation of Queue in Data Structure

Here, we have shown a branded ice cream shop that is famous enough to have a queue of people waiting to get one of their choices. And the shop owner wants to store the information of these people, so he uses an array to accomplish that. Assuming that we have 8 people and we want to store their information, we’ll have an array as illustrated below:
            index: 0 1 2 3 4  5 6 7
            value:               

Here, we’ll maintain an index variable, backInd, to store the index of the rearmost element. So, when we insert an element, we just increment the value of the backInd and insert the element at the current backInd value. Follow the array below to know how inserting works:

index: 0 1  2  3 4 5 6 7    -----> 0 1  2  3 4 5 6 7
value: 7 11 18 2 5                 7 11 18 2 5 8
                 ^                             ^
                 |                             |
                 backInd                       backInd

Now suppose we want to remove an element from the queue. And since a queue follows the FIFO discipline, we can only remove the element at the zeroth index, as that is the element inserted first in the queue. So, now we will remove the element at the zeroth index and shift all the elements to its adjacent left. Follow the illustrations below:

index: 0 1  2  3 4 5 6 7    -----> 0  1  2 3 4 5 6 7
value: 7 11 18 2 5 8               11 18 2 5 8
                   ^                         ^
                   |                         |
                   backInd                   backInd
But this removal of the zeroth element and shifting of other elements to their immediate left features O(n) time complexity. 

Summing up this method of enqueue and dequeue, we can say:

1. Insertion( enqueue ):

Increment backInd by 1.
Insert the element
Time complexity: O(1)
2. Deletion( dequeue ):

Remove the element at the zeroth index
Shift all other elements to their immediate left.
Decrement backInd by 1
3. Here, our first element is at index 0, and the rearmost element is at index backInd.

4. Condition for queue empty: backInd = -1.

5. Condition for queue full: backInd = size-1.

Can there be a better way to accomplish these tasks? The answer is yes.

We can use another index variable called frontInd, which stores the index of the cell just before the first element. We’ll maintain both these indices to bring about all our operations. Let’s now enlist the changes we’ll see after we introduce this new variable:


1. Insertion( enqueue ):

Increment backInd by 1.
Insert the element
Time complexity: O(1)
2. Deletion( dequeue ):

Remove the element at the zeroth index( no need for that in an array )
Increment frontInd by 1.
Time complexity: O(1)
3. Our first element is at index frontInd +1, and the rearmost element is at index backInd.

4. Condition for queue empty: frontInd = backInd.

5. Condition for queue full: backInd = size-1.

Now, we were able to achieve both operations in constant run time. And the new dequeue operation goes as follow:

index: -1 0 1  2  3 4 5 6 7   ----> 0 1  2  3 4 5 6 7
value:    7 11 18 2 5 8               11 18 2 5 8
        ^             ^             ^           ^
        |             |             |           |
        frontInd      backInd       frontInd    backInd

The act of optimizing a solution/program is very important, and you should always strive for a better solution to a problem. And a solution that takes less time is always preferred. So, this is how we implement the queue ADT using an array.
*/

#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int frontInd;
    int backInd;
    int* arr;
};


int main(){
    printf("This is just intro of Queue data structure and implementation using array.");
    return 0;
}