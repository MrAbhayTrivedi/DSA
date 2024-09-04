/*
Introduction to Circular Queue

A Circular Queue is an extended version of a normal queue where the last element of the queue is connected to the first element of the queue forming a circle.

The operations are performed based on FIFO (First In First Out) principle. It is also called ‘Ring Buffer’. 

In a normal Queue, we can insert elements until queue becomes full. But once queue becomes full, we can not insert the next element even if there is a space in front of queue.

Operations on Circular Queue:
    Front: Get the front item from the queue.
    Rear: Get the last item from the queue.
    enQueue(value) This function is used to insert an element into the circular queue. In a circular queue, the new element is always inserted at the rear position. 
        Check whether the queue is full – [i.e., the rear end is in just before the front end in a circular manner].
        If it is full then display Queue is full. 
            If the queue is not full then,  insert an element at the end of the queue.
    deQueue() This function is used to delete an element from the circular queue. In a circular queue, the element is always deleted from the front position. 
        Check whether the queue is Empty.
        If it is empty then display Queue is empty.
            If the queue is not empty, then get the last element and remove it from the queue.


Illustration of Circular Queue Operations:
Follow the below image for a better understanding of the enqueue and dequeue operations.

How to Implement a Circular Queue?
A circular queue can be implemented using two data structures:
    Array
    Linked List
Here we have shown the implementation of a circular queue using an array data structure.

Implement Circular Queue using Array:
    1. Initialize an array queue of size n, where n is the maximum number of elements that the queue can hold.
    2. Initialize two variables front and rear to -1.
    3. Enqueue: To enqueue an element x into the queue, do the following:
        Increment rear by 1.
            If rear is equal to n, set rear to 0.
        If front is -1, set front to 0.
        Set queue[rear] to x.
    4. Dequeue: To dequeue an element from the queue, do the following:
        Check if the queue is empty by checking if front is -1. 
            If it is, return an error message indicating that the queue is empty.
        Set x to queue[front].
        If front is equal to rear, set front and rear to -1.
    Otherwise, increment front by 1 and if front is equal to n, set front to 0.
    Return x.
*/


#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int front;
    int back;
    int *arr;
};

// In a non-empty queue, front and back both represent position of an element
// back represents the position of the latest element enqueued
// while front represents the position of the element to be dequeued
// In an empty queue, front and back are both -1
// If front==back in a non-empty queue, we dequeue the element at front, and reset the queue by front=back=-1

int isEmpty(struct queue* q){
    if(q->front==-1 && q->back==-1) return 1;
    else return 0;
}

int isFull(struct queue* q){
    if((q->back+1)%q->size==q->front) return 1;
    else return 0;
}

void enqueue(struct queue* q, int val){
    if(isFull(q)){
        printf("Queue full. Can't enqueue.\n");
    }
    else{
        if(isEmpty(q)){                         // if the queue is empty
            q->front=0, q->back=0;              // set front and back to 0
        }
        else{
            q->back = (q->back+1)%q->size;      // if it's not empty, move back one step ahead circularly
        }
        q->arr[q->back] = val;                  // and then enqueue
        printf("%d enqueued.\n",val);
    }
}

int dequeue(struct queue* q){
    if(isEmpty(q)){
        printf("Can't perform dequeue. Queue empty. \n");
        return 404;
    }
    else{
        int a = q->arr[q->front];               // store the value at front in var a
        if(q->front==q->back){                  // if in any scenario front has reached to the back
            q->front=-1, q->back=-1;            // reset queue
        }
        else{
            q->front = (q->front+1)%q->size;    // else move front one step ahead circularly
        }
        return a;
    }
}
void displayQueue(struct queue* q)
{
    if (q->front == -1)
    {
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in Circular Queue are: ");
    if (q->back >= q->front)
    {
        for (int i = q->front; i <= q->back; i++)
            printf("%d ",q->arr[i]);
        printf("\n");
    }
    else
    {
        for (int i = q->front; i < q->size; i++)
            printf("%d ", q->arr[i]);
 
        for (int i = 0; i <= q->back; i++)
            printf("%d ", q->arr[i]);
        printf("\n");
    }
}

int main(){
    struct queue* q=(struct queue*) malloc(sizeof(struct queue));
    q->size = 4;
    q->front = -1;
    q->back = -1;
    q->arr = (int*) malloc(q->size*sizeof(int));

    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    enqueue(q,4);
    enqueue(q,4);
    enqueue(q,4);
    enqueue(q,4);
    displayQueue(q);
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    if (isFull(q))
    {
        printf("Queue is Full\n");
    }
    dequeue(q);
    dequeue(q);
    dequeue(q);
    displayQueue(q);
    enqueue(q,5);
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }

    displayQueue(q);
    return 0;
}
/*
Complexity Analysis of Circular Queue Operations:
    Time Complexity: 
        Enqueue: O(1) because no loop is involved for a single enqueue.
        Dequeue: O(1) because no loop is involved for one dequeue operation.
    Auxiliary Space: O(N) as the queue is of size N.
Applications of Circular Queue:
    Memory Management: The unused memory locations in the case of ordinary queues can be utilized in circular queues.
    Traffic system: In computer controlled traffic system, circular queues are used to switch on the traffic lights one by one repeatedly as per the time set.
    CPU Scheduling: Operating systems often maintain a queue of processes that are ready to execute or that are waiting for a particular event to occur.

*/