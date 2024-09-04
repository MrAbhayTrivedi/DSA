/*
Queue Using Linked Lists

Implementing queues using linked lists tests your proficiency in using/ handling both queues and linked lists.

If you remember, linked lists are chain-like structures with nodes having two parts, an integer variable to hold data and another node pointer to hold the address of the next node. Below illustrated is a linked list with three nodes. The last node points to NULL. And the first node is called the head.
        
    struct node (head)
        |``|
        4->3->8->NULL
        ^ ^
        | |
    data   pointer to the next node

Moving to the basics of a queue, a queue represents a line or sequence of elements where the elements follow the FIFO discipline. The element inserting the first gets removed the first. We maintained two index variables, f, and r, to mark the beginning and the end of the queue. Below illustrated is a queue with three elements.

index: -1 0 1 2 3  
value:    4 3 8               
        ^     ^            
        |     |             
        f     r   

Since we are implementing this queue using a linked list, the index variables are no longer integers. These become the pointers to the front and the rear nodes. And the queue somewhat starts looking like this.
        4->3->8->NULL
         ^      ^
         |      |
         f      r

Enqueue in a queue linked list:
Enqueuing in a queue linked list is very much similar to just inserting at the end in a linked list. As we discussed this thoroughly in our past lectures, you should not find this difficult. Inserting a new node at the end requires you to follow few steps:

    Check if there is a space left in the heap for a new node.
    If there is, create a new node n, assign it memory in heap, and fill its data with the new value the user has given.
    Point the next member of this new node n to NULL, and point the next member of the r to n. And make r equal to n. And we are done.
    There is one exception here. When we insert the first element, both f and r are pointing to NULL. So, instead of just making r equal to n, we make f equal to n as well. This marks the beginning of the list.

Dequeue in a queue linked list:
Dequeuing in a queue linked list is very much similar to deleting the head node in a linked list. Deleting the head node from the list requires you to follow few steps:

    Check if the queue list is already not empty using the isEmpty function.
    If it is, return -1. Else create a new node ptr and make it equal to the f node. And don’t forget to store the data of the f node in some integer variable.
    Make the f equal to the next member of f, and free the node ptr. Return the value you stored.

Condition for isEmpty:
    The only condition for the queue linked list to be empty is that the f node is NULL, which means there is no beginning, hence no element.

Condition for isFull:
    Queues implemented using linked lists never usually become full until the space in the heap memory is exhausted. Therefore, the only condition for the queue linked list to be full is that the new node becomes NULL when created.
*/

#include <stdio.h>
#include <stdlib.h>


// declaring f and r globally to avoid pointer to pointer confusion or returning the f and r after change every time
struct Node *f = NULL;
struct Node *r = NULL;
 
struct Node
{
    int data;
    struct Node *next;
};
 
void linkedListTraversal(struct Node *ptr)
{
    printf("Printing the elements of this linked list\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
 
void enqueue(int val)
{
    struct Node *n = (struct Node *) malloc(sizeof(struct Node));
    if(n==NULL){
        printf("Queue is Full");
    }
    else{
        n->data = val;
        n->next = NULL;
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next = n;
            r=n;
        }
    }
}
 
int dequeue()
{
    int val = -1;
    struct Node *ptr = f;
    if(f==NULL){
        printf("Queue is Empty\n");
    }
    else{
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}
 
int main()
{
    linkedListTraversal(f);
    printf("Dequeuing element %d\n", dequeue());
    enqueue(34);
    enqueue(4);
    enqueue(7);
    enqueue(17);
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    linkedListTraversal(f);
    return 0;
}
