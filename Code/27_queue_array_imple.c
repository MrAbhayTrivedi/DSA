/*
Array implementation of Queue and its Operations in Data Structure

Given array below represents a queue:

index: -1 0 1  2  3 4 5 6 7   
value:    7 11 18 2 5 8              
        ^             ^             
        |             |             
        frontInd      backInd  

To implement this, we’ll use a structure and have the following members inside it:

1. size: to store the size of the array

2. frontInd: to store the index prior to the first element.

3. backInd: to store the index of the rearmost element.

4. *arr: to store the address of the array dynamically allocated in heap.

struct queue
{
    int size;
    int frontInd;
    int backInd;
    int* arr;
};

Now to use this struct element as a queue, you just need to initialize its instances as:

struct Queue q; (we are not dynamically allocating q here for now, as we did in stacks).
Use dot here, and not arrow operator to assign values to struct members, since q is not a pointer.
q.size = 10; (this gives size element the value 10)
q.frontInd = q.backInd = -1;(this gives both the indices element the value -1)
Use malloc to assign memory to the arr element of struct q.
And this is how you initialize a queue. We will now devote our attention to two important operations in a queue: enqueue and dequeue.

Enqueue:
Enqueuing is inserting a new element in a queue. Prior to inserting an element into a queue, we need to take note of a few points.

First, check if the queue is already not full.
If it is, it is the case of queue overflow, else just increment backInd by 1, insert the new element there. Follow the illustration below.


Dequeue:
Dequeuing is deleting the element in a queue which is the first among all the elements to get inserted. Prior to deleting that element from a queue, we need to follow the below-mentioned points:

3. First, check if the queue is already not empty.

4. If it is, it is the case of queue underflow, else just increment frontInd by 1. In arrays, we don’t delete elements; we just stop referring to the element. Follow the illustration below.

Condition for isEmpty:

If our frontInd equals backInd, then there is no element in our queue, and this is the case of an empty queue.

Condition for isFull:

If our backInd equals (the size of the array) -1, then there is no space left in our queue, and this is the case of a full queue.
*/

#include<stdio.h>
#include<stdlib.h>
 
struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};
 
 
int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
 
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
 
void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        printf("Enqued element: %d\n", val);
    }
}
 
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f]; 
    }
    return a;
}
 
int main(){
    struct queue q;
    q.size = 4;
    q.f = q.r = -1;
    q.arr = (int*) malloc(q.size*sizeof(int));
    
    // Enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1); 
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q)); 
    enqueue(&q, 45);
    enqueue(&q, 45);
    enqueue(&q, 45);
 
    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    if(isFull(&q)){
        printf("Queue is full\n");
    }
 
    return 0;
}
