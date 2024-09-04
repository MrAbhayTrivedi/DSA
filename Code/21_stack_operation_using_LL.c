/*
Implementing all the Stack Operations using Linked List

1. isEmpty : It just checks if our top element is NULL. 

2. isFull : A stack is full, only if no more nodes are being created using malloc. This is the condition where heap memory gets exhausted.

3. Push : The first thing we need before pushing an element is to create a new node. Check if the stack is not already full. Now, we follow the same concept we learnt while inserting an element at the head or at the index 0 in a linked list. Just set the address of the current top in the next member of the new node, and update the top element with this new node.

4. Pop : First thing is to check if the stack is not already empty Now, we follow the same concept we learnt while deleting an element at the head or at the index 0 in a linked list. Just update the top pointer with the next node, skipping the current top.

5. peek: This operation is meant to return the element at a given position. Do mind that the position of an element is not the same as the index of an element.

Peeking in a stack linked list is not as efficient as when we worked with arrays. Peeking in a linked list takes O(n) because it first traverses to the position where we want to peek in. So, we’ll just have to move to that node and return its data.


6. stackTop: This operation just returns the topmost value in the stack. That is, it just returns the data member of the top pointer.

7. stackBottom: This operation just returns last value of stack, to do so we need to traverse all the elements till top->next!=NULL.

*/

#include<stdio.h>
#include<stdlib.h>
 
struct Node{
    int data;
    struct Node * next;
};
 
struct Node* top = NULL;
 
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next; 
    }
}
 
int isEmpty(struct Node* top){
    if (top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
 
int isFull(struct Node* top){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
 
struct Node* push(struct Node* top, int x){
    if(isFull(top)){
        printf("Stack Overflow\n");
    }
    else{
        struct Node* n = (struct Node*) malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

// If we are not using top as global variable then we need to pass address of top i.e. pointer to pointer
/*
int pop(struct Node** top){
    if(isEmpty(*top)){
        printf("Stack Underflow\n");
    }
    else{
        struct Node* n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x; 
    }
}
*/

/*
You must have observed we used the pointer to a pointer while popping elements from the stack. We referenced and unreferenced twice. So, to avoid all these complexities, I still have a better way to implement that thing. We can declare the top pointer globally. Earlier we used to declare it under main. Declaring it globally gives its access to all our functions without passing them as a parameter.
*/
int pop(struct Node* tp){
    if(isEmpty(tp)){
        printf("Stack Underflow\n");
    }
    else{
        struct Node* n = tp;
        top = (tp)->next;
        int x = n->data;
        free(n);
        return x; 
    }
}

int peek(int pos){
    struct Node* ptr = top;
    for (int i = 0; (i < pos-1 && ptr!=NULL); i++)
    {
        ptr = ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;
    }
    else{
        return -1;
    }
}


int stackTop(){
    return top->data;
}

int stackBottom(){
    struct Node* ptr = top;
    if(isEmpty(top)){
        return -1;
    }
    else{
        while (ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        return ptr->data;
        
    }
}
int main(){
    top = push(top, 78);
    top = push(top, 7);
    top = push(top, 8);
    
    // linkedListTraversal(top);
    
    //Below code will work if we do not declare top as global variable
    /*
    int element = pop(&top);// We are giving address of top instead of top alone
    printf("Popped element is %d\n", element);
    linkedListTraversal(top);
    */

    int element = pop(top); 
    printf("Popped element is %d\n", element);
    linkedListTraversal(top);

    top = push(top, 18);
    top = push(top, 15);

    for (int i = 1; i <= 4; i++)
    {
        printf("Value at position %d is : %d\n", i, peek(i));
    }

    printf("Topmost value is: %d\n",stackTop());
    printf("Bottom value is: %d\n",stackBottom());

    return 0;
}
