/*
Circular Linked List and Operations

Introduction:
A circular linked list is a linked list where the last element points to the first element (head) hence forming a circular chain. There is no node pointing to the NULL, indicating the absence of any end node. In circular linked lists, we have a head pointer but no starting of this list.

        head--->1-->2-->3-->4-->5-->head

Operations on a Circular Linked List:
    Operations on circular linked lists can be performed exactly like a singly linked list. It’s just that we have to maintain an extra pointer to check if we have gone through the list once.

Traversal:
    Traversal in a circular linked list can be achieved by creating a new struct Node* pointer p, which starts from the head and goes through the list until it points again at the head. So, this is how we go through this circle only once, visiting each node.
    And since traversal is achieved, all the other operations in a circular linked list become as easy as doing things in a linear linked list. 
    One thing that may have sounded confusing to you is that there is a head but no starting of this circular linked list. Yes, that is the case; we have this head pointer just to start or incept in this list and for our convenience while operating on it. There is no first element here.
*/

#include<stdio.h>
#include<stdlib.h>
 
struct Node
{
    int data;
    struct Node *next;
};
 
void linkedListTraversal(struct Node *head){
    struct Node *ptr = head;
    do{
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }while(ptr!=head);
}
 
 // Case 1: Insertion at the beginning i.e. at head
struct Node * insertAtFirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
 
    struct Node * p = head->next;
    while(p->next != head){
        p = p->next;
    }
    // At this point p points to the last node of this circular linked list
 
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
 
}

// Case 2: Insertion at the given index
struct Node * insertAtIndex(struct Node *head, int data,int index){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
 
    struct Node * p = head;
    struct Node * q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    
    // At this point p points to the last node of this circular linked list
 
    p->next = ptr;
    ptr->next = q;
    return head;
 
}

// Case 3: Insertion at the end
struct Node * insertAtEnd(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;

    while(p->next!=head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return head;
}
 
 // Case 4: Insertion after a Node
 struct Node * insertAfterNode(struct Node *head,struct Node *prevNode, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

// Case 5: Insertion at a given value
struct Node * insertAtValue(struct Node *head, int data, int value){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->data!=value && q!=head){
        p = p->next;
        q = q->next;
    }
    p->next = ptr;
    ptr->next = q;

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
 
    // Link first and second nodes
    head->data = 4;
    head->next = second;
 
    // Link second and third nodes
    second->data = 3;
    second->next = third;
 
    // Link third and fourth nodes
    third->data = 6;
    third->next = fourth;
 
    // Terminate the list at the third node
    fourth->data = 1;
    fourth->next = head;

    printf("Circular Linked list before insertion\n");
    linkedListTraversal(head);
    head = insertAtFirst(head, 54);
    head = insertAtFirst(head, 58); // Insertion at first
    head = insertAtFirst(head, 59);

    head = insertAtIndex(head, 55, 1); // Insertion at index

    head = insertAtEnd(head, 57);  // Insertion at end

    head = insertAfterNode(head, third, 45); // Insertion after a node

    head = insertAtValue(head, 44, 55); // Insertion at a given value
    
    printf("Circular Linked list after insertion\n");
    linkedListTraversal(head);
 
    return 0;
}
