/*
Double-Ended Queue in Data Structure

In DEQueue, we don’t follow the FIFO principle. As the name suggests, this variant of the queue is double-ended. This means that unlike normal queues where insertion could only happen at the rear end, and deletion at the front end, these double-ended queues have the freedom to insert and delete elements from the end of their choice.

Double-ended queues, hence, have the following characteristics:

    They don't follow the FIFO discipline.
    Insertion can be done at both the ends of the queue.
    Deletion can also be done from both ends of the queue.

Insertion in a DEQueue:
Insertion in a DEQueue is very intuitive.

index: -1 0 1  2  3 4 5 6 7
value:    7 11 18 2 5 8            
        ^             ^   
        |             |       
        front         rear      

Now since the front has no space to insert, you can only insert at the rear end. But if the front manages to have some space after some dequeuing, then our condition would be something like this:

index: -1 0 1 2 3  4  5 6 7
value:        7 11 18 2 5 8            
            ^             ^   
            |             |       
            front         rear  

Now, we have 2 places to fill in front as well. And in DEQueue, we have no restrictions. We would just fill our new element at the front and decrease its value by 1. And that would be it. See the results below:

index: -1 0 1 2 3  4  5 6 7
value:      8 7 11 18 2 5 8            
          ^               ^   
          |               |       
          front           rear  

Deletion in a DEQueue:
Deletion in a DEQueue is very similar to what we did above. Follow the illustration below:

index: -1 0 1  2  3 4 5 6 7
value:    7 11 18 2 5 8            
        ^             ^   
        |             |       
        front         rear 

Now, for one moment, think of the rear as the front end. You would simply then increase the front value by 1 and delete the element at the new front. Similarly, here we first delete the element at rear and decrease the value of the rear by 1. See the results below.  

index: -1 0 1  2  3 4 5 6 7
value:    7 11 18 2 5             
        ^           ^   
        |           |       
        front       rear

And yeah, we are done deleting the element from the rear end. And inserting at the front end. Moving further, DEQueues are of two types:

    1. Restricted Input DEQueue
    2. Restricted Output DEQueue

Restricted Input DEQueue:
    Input restricted DEQueues don’t allow insertion on the front end. But you can delete from both ends.

Restricted Output DEQueue:
    Output restricted DEQueues don’t allow deletion from the rear end. But you can perform the insertion on both the ends.

DEQueue ADT:
The data part would be the same as the queue.

Methods:

All the operations except the enqueue and dequeue will remain the same as that of the queue. In place of enqueue and dequeue, we would have: 

enqueueF()
enqueueR()
dequeueF()
dequeueR()

You can even have more of these, as initialise(), print(), etc.
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
 
void print(struct queue *q){
    printf("Printing elements: ");
    for (int i = q->f+1; i <= q->r; i++)
    {
        printf("%d ",q->arr[i]);
    }
    printf("\n");
    
}
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
 
void enqueueR(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        printf("Enqued element: %d\n", val);
    }
}

void enqueueF(struct queue *q, int val){
    if(q->f==-1){
        printf("This Queue is full from front can not insert an element\n");
    }
    else{
        q->arr[q->f] = val;
        q->f--;
        printf("Enqued element: %d\n", val);
    }
}
 
int dequeueF(struct queue *q){
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
 
int dequeueR(struct queue *q){
    int a = -1;
    if(q->r==-1){
        printf("This Queue is empty\n");
    }
    else{
        a = q->arr[q->r]; 
        q->r--;
    }
    return a;
}

int main(){
    struct queue q;
    q.size = 4;
    q.f = q.r = -1;
    q.arr = (int*) malloc(q.size*sizeof(int));
    
    // enqueueR few elements
    enqueueR(&q, 12);
    enqueueR(&q, 15);
    enqueueR(&q, 1); 
    enqueueR(&q, 2);
    print(&q);
    printf("Dequeuing element %d\n", dequeueF(&q));
    printf("Dequeuing element %d\n", dequeueF(&q));
    printf("Dequeuing element %d\n", dequeueF(&q)); 
    print(&q);
    enqueueR(&q, 45);
    enqueueR(&q, 46);
    enqueueF(&q, 47);
    enqueueF(&q, 48);
    enqueueF(&q, 49);
    enqueueF(&q, 50);
    print(&q);
    printf("Dequeuing element %d\n", dequeueR(&q));
    printf("Dequeuing element %d\n", dequeueR(&q));
    printf("Dequeuing element %d\n", dequeueR(&q));
    print(&q);
    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    if(isFull(&q)){
        printf("Queue is full\n");
    }
 
    return 0;
}
