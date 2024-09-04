/*
What is a doubly-linked list?
Each node contains a data part and two pointers in a doubly-linked list, one for the previous node and the other for the next node.

Below illustrated is a doubly-linked list with three nodes. Both the end pointers point to the NULL.

    NULL <-> 1 <-> 2 <-> 3 <-> NULL

How is it different from a singly linked list?
    A doubly linked list allows traversal in both directions. We have the addresses of both the next node and the previous node. So, at any node, we’ll have the freedom to choose between going right or left.
    A node comprises three parts, the data, a pointer to the next node, and a pointer to the previous node.
    Head node has the pointer to the previous node pointing to NULL.

Implementation in C:

Let’s try implementing a doubly linked list in our codes. We’ll have a struct Node as before. The only information added to this struct Node is a struct Node* pointer to the previous node. Let’s name this prev.

This new information makes us travel in both directions, but using it follows the use of more memory space for a single node that now comprises three members. It is because of this we have a singly linked list. 

struct Node {
    int data;
    Struct Node* next;
    Struct Node* prev;
};
*/

#include<stdio.h>
#include<stdlib.h>

//Creating a node for doubly linked list
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Traversal in forward direction
void linkedListTraversal(struct Node *head){
    struct Node *ptr = head;
    do{
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }while(ptr!=NULL);
}

// Traversal in reverse direction
void linkedListReverseTraversal(struct Node *tail){
    struct Node *ptr = tail;
    do{
        printf("Element is %d\n", ptr->data);
        ptr = ptr->prev;
    }while(ptr!=NULL);
}

// Insertion at the beginning
struct Node * insertAtFirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = head;
    head->prev = ptr;
    ptr->prev = NULL;
    head = ptr;
    return head;

}


//Insertion in between at a given index
struct Node * insertAtIndex(struct Node *head, int data,int index){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    ptr->next = q;
    ptr->prev = p;
    q->prev = ptr;
    p->next = ptr;
    return head;

}

int main(){
    
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first node's next to second node and first node's prev to NULL
    head->data = 4;
    head->prev = NULL;
    head->next = second;

    // Link second node's next to third node and second node's prev to first node
    second->prev = head;
    second->data = 3;
    second->next = third;

    // Link third node's next to fourth node and third node's prev to second node
    third->data = 6;
    third->prev = second;
    third->next = fourth;

    //Link fourth node's next to NULL to terminate and fourth node's prev to third node
    fourth->data = 1;
    fourth->prev = third;
    fourth->next = NULL;

    printf("Doubly Linked list before insertion\n");
    linkedListTraversal(head);
    head = insertAtFirst(head, 54);
    head = insertAtFirst(head, 58);
    head = insertAtFirst(head, 59);
    printf("\nDoubly Linked list after insertion at beginning\n");
    linkedListTraversal(head);

    head = insertAtIndex(head, 55, 2);
    printf("\nDoubly Linked list after insertion at givenindex\n");
    linkedListTraversal(head);
    printf("\nDoubly Linked list in reverse order\n");
    linkedListReverseTraversal(fourth);
    return 0;
}