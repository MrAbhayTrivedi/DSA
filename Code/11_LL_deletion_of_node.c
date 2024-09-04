/*
Deletion in a Linked List

Consider the following Linked List:
    1 -> 2 -> 3 -> 4 -> 5 -> NULL
    ^
    |
    head

Deletion in this list can be divided into the following categories:

Case 1: Deleting the first node.

Case 2: Deleting the node at the index.

Case 3: Deleting the last node.

Case 4: Deleting the first node with a given value.

For deletion, following any of the above-mentioned cases, we would just need to free that extra node left after we disconnect it from the list. Before that, we overwrite the current connection and make new connections. And that is how we delete a node from our desired place.

Syntax for freeing a node:
    
    free(ptr);

The above syntax will free this node, that is, remove its reserved location in the heap.

Case 1: Insert at the beginning:
    In order to delete the node at the beginning, we would need to have the head pointer pointing to the node second to the head node, that is, head-> next. And we would simply free the node that’s left.

Case 2: Deleting at some index in between:
    Assuming index starts from 0, we can delete an element from index i>0 as follows:

    Bring a temporary pointer p pointing to the node before the element you want to delete in the linked list.
    Since we want to delete between 2 and 8, we bring pointer p to 2.
    Assuming ptr points at the element we want to delete.
    We make pointer p point to the next node after pointer ptr skipping ptr.
    We can now free the pointer skipped.

Case 3: Deleting at the end:
    In order to delete an element at the end of the linked list, we bring a temporary pointer ptr to the last element. And a pointer p  to the second last. We make the second last element to point at NULL. And we free the pointer ptr.

Case 4: Delete the first node with a given value:
    Similar to the other cases, ptr can be deleted for a given value as well by following few steps:

    p->next = givenVal-> next;
    free(givenVal);
    If, the value 8(say) comes twice in the list, this function will be made to delete only the first occurrence.

Deleting the first node            -> Time complexity:  O(1)
Deleting a node in between         -> Time complexity:  O(n)
Deleting the last node             -> Time complexity:  O(n)
Deleting the element with a given value from the linked list     -> Time complexity:  O(n)
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Case 1: Deleting the first element from the linked list
/*
    Create a struct Node* function deleteFirst which will return the pointer to the new head after deleting the current head.
    We’ll pass the current head pointer in the function.
    Create a new struct Node* pointer ptr, and make it point to the current head.
    Assign head to the next member of the list, by head = head->next, because this is going to be the new head of the linked list.
    Free the pointer ptr. And return the head
*/
struct Node * deleteFirst(struct Node * head){
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Case 2: Deleting the element at a given index from the linked list
/*
    Create a struct Node* function deleteAtIndex which will return the pointer to the head.
    In the function, we'll pass the current head pointer and the index where the node is to be deleted.
    Create a new struct Node* pointer p pointing to head.
    Create a new struct Node* pointer q pointing to head->next, and run a loop until this pointer reaches the index, from where we are deleting the node.
    Assign q->next to the next member of the p structure using p-> next = q->next.
    Free the pointer q, because it has zero connections with the list now.
    Return head
*/
struct Node * deleteAtIndex(struct Node * head, int index){
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = q->next;
    free(q);
    return head;
}

// Case 3: Deleting the last element
/*
    Deleting the last node is quite similar to deleting from any other index. The difference holds in the limit of the while loop. Here we run a loop until the pointer reaches the end and points to NULL.
    Assign NULL to the next member of the p structure using p-> next = NULL.
    Break the connection between q and NULL by freeing the ptr q.
    Return head
*/
struct Node * deleteAtLast(struct Node * head){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->next !=NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = NULL;
    free(q);
    return head;
}


// Case 4: Deleting the element with a given value from the linked list
/*
    Here, we already have a value that needs to be deleted from the list. The main thing is that we’ll delete only the first occurrence.
    Create a struct Node* function deleteByValue which will return the pointer to the head.
    Pass into this function the head node, the value which needs to be deleted.
    Create a new struct Node* pointer p pointing to the head.
    Create another struct Node* pointer q pointing to the next of head.
    Run a while loop until the pointer q encounters the given value or the list finishes.
    If it encounters the value, delete that node by making p point the next node, skipping the node q. And free q from memory.
    And if the list just finishes, it means there was no such value in the list. Continue without doing anything.
    Return head
*/
struct Node * deleteAtValue(struct Node * head, int value){
    struct Node *p = head;
    struct Node *q = head->next;
    while(q->data!=value && q->next!= NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    return head;
}
int main()
{
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
    third->data = 8;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 1;
    fourth->next = NULL;

    printf("Linked list before deletion\n");
    linkedListTraversal(head);

    // head = deleteFirst(head); // For deleting first element of the linked list
    // head = deleteAtIndex(head, 2);   //For deleting element at index 2
    // head = deleteAtLast(head);        //For deleting last element of the linked list

    head=deleteAtValue(head, 3);  //For deleting element with a given value
    printf("Linked list after deletion\n");
    linkedListTraversal(head);

    return 0;
}