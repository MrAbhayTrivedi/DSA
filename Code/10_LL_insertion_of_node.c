/*
Insertion of a Node in a Linked List

Consider the following Linked List,
    10 -> 20 -> 30 -> 40 -> 50 -> NULL
    ^
    |
    head

Insertion in this list can be divided into the following categories:

Case 1: Insert at the beginning

Case 2: Insert in between

Case 3: Insert at the end

Case 4: Insert after the node

For insertion following any of the above-mentioned cases, we would first need to create that extra node. And then, we overwrite the current connection and make new connections. And that is how we insert a new node at our desired place.

Syntax for creating a node:

    struct Node *ptr = (struct Node*) malloc (sizeof (struct Node))

The above syntax will create a node, and the next thing one would need to do is set the data for this node.

    ptr -> data = 9 

Case 1: Insert at the beginning

In order to insert the new node at the beginning, we would need to have the head pointer pointing to this new node and the new node’s pointer to the current head.

Case 2: Insert in between:

Assuming index starts from 0, we can insert an element at index i>0 as follows:

Bring a temporary pointer p pointing to the node before the element you want to insert in the linked list.
Since we want to insert between 8 and 2, we bring pointer p to 8.

Case 3: Insert at the end:

In order to insert an element at the end of the linked list, we bring a temporary pointer to the last element.

Case 4: Insert after a node:

Similar to the other cases, ptr can be inserted after a node as follows:

ptr->next = prevNode-> next;

prevNode-> next = ptr;

Inserting at the beginning        -> Time complexity:  O(1)
Inserting in between              -> Time complexity:  O(n)
Inserting at the end              -> Time complexity:  O(n)
Inserting after a given Node      -> Time complexity:  O(1)


*/
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Case 1
/*
Insertion at the beginning:
    Create a struct Node* function insertAtFirst which will return the pointer to the new head.
    We’ll pass the current head pointer and the data to insert at the beginning, in the function.
    Create a new struct Node* pointer ptr, and assign it a new memory location in the heap.
    Assign head to the next member of the ptr structure using ptr-> next = head, and the given data to its data member.
    Return this pointer ptr.
*/
struct Node * insertAtFirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = head;
    return ptr; 
}

// Case 2
/*
Insertion in between:
    Create a struct Node* function insertAtIndex which will return the pointer to the head.
    We’ll pass the current head pointer and the data to insert and the index where it will get inserted, in the function.
    Create a new struct Node* pointer ptr, and assign it a new memory location in the heap.
    Create a new struct Node* pointer pointing to head, and run a loop until this pointer reaches the index, where we are inserting a new node.
    Assign p->next to the next member of the ptr structure using ptr-> next = p->next, and the given data to its data member.
    Break the connection between p and p->next by assigning p->next the new pointer. That is, p->next = ptr.
    Return head.
*/
struct Node * insertAtIndex(struct Node *head, int data, int index){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;

    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Case 3
/*
Insertion at the end:
    Inserting at the end is very similar to inserting at any index. The difference holds in the limit of the while loop. Here we run a loop until the pointer reaches the end and points to NULL.
    Assign NULL to the next member of the new ptr structure using ptr-> next = NULL, and the given data to its data member.
    Break the connection between p and NULL by assigning p->next the new pointer. That is, p->next = ptr.
    Return head.
*/
struct Node * insertAtEnd(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;

    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// Case 4
/*
Insertion after a given node:
    Here, we already have a struct Node* pointer to insert the new node just next to it.
    Create a struct Node* function insertAfterNode which will return the pointer to the head.
    Pass into this function, the head node, the previous node, and the data.
    Create a new struct Node* pointer ptr, and assign it a new memory location in the heap.
    Since we already have a struct Node* prevNode given as a parameter, use it as p we had in the previous functions.
    Assign prevNode->next to the next member of the ptr structure using ptr-> next = prevNode->next, and the given data to its data member.
    Break the connection between prevNode and prevNode->next by assigning prevNode->next the new pointer. That is, prevNode->next = ptr.
    Return head.
*/
struct Node * insertAfterNode(struct Node *head, struct Node *prevNode, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    
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
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = NULL;

    printf("Linked list before insertion\n");
    linkedListTraversal(head);
    // head = insertAtFirst(head, 56);
    // head = insertAtIndex(head, 56, 1);
    // head = insertAtEnd(head, 56);
    head = insertAfterNode(head, third, 45);
    printf("\nLinked list after insertion\n");
    linkedListTraversal(head);

    
    return 0;
}