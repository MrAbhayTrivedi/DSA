/*
Implementing stacks using linked lists:

We can now consider a singly linked list. Follow the illustration below.

    7->22->4->3->NULL
    ^              ^
    |              |
    Side 1        Side 2

Consider this linked list functioning as a stack. And as you know, we have two sides of a linked list, one the head, and the other pointing to NULL. Which side do you feel should we consider as the top of the stack, where we push and pop from? After following me all the way through here, you would say the head side.

And why the head side, that is side 1?

Because that’s the head node of the linked list, and insertion and deletion of a node at head happens to function in a constant time complexity, O(1). Whereas inserting or deleting a node at the last position takes a linear time complexity, O(n).

So that stack equivalent of the above illustrated linked list looks something like this:
    top                                         |            |
    ^                                           |            |
    |                                           |____________|
    7->22->4->3->NULL       ---->     top ---> 3|_____7______|
    ^              ^                           2|_____22_____|
    |              |                           1|_____4______|
    Side 1        Side 2                       0|_____3______|
                                                    Stack

Let’s revise how we used to define a struct Node in linked lists. We had a struct, and two structure members, data and a struct Node pointer to store the address of the next node.

    struct Node{
        int data;
        struct Node* next;
    }

When is our stack empty or full?

Stacks when implemented with linked lists never get full. We can always add a node to it. There is no limit on the number of nodes a linked list can contain until we have some space in heap memory. Whereas stacks become empty when there is no node in the linked list, hence when the top equals to NULL.

    1. Condition for stack full: When heap memory is exhausted
    2. Condition for stack empty:  top == NULL

One change I would like to implement before we proceed; the head node we had in linked lists, is the top for our stacks now. So, from now on, the head node will be referred to as the top node. 

Even though a stack-linked list has no upper limit to its size, you can always set a custom size for it. 
*/

#include<stdio.h>
#include<stdlib.h>

struct stack{
    int data;
    struct stack* next;
};

void stackTraversal(struct stack* top){
    struct stack* temp=top;
    do{
        printf("%d ", temp->data);
        temp=temp->next;
    }while(temp!=NULL);
    printf("\n");
    
}

int isEmpty(struct stack * top){
    if(top==NULL)
        return 1;
    else
        return 0;
}

int isFull(){
    struct stack* temp=(struct stack*)malloc(sizeof(struct stack));
    if (temp==NULL){
        return 1;
    }
    return 0;
}
struct stack* push(struct stack* top, int data){
    struct stack* temp=(struct stack*)malloc(sizeof(struct stack));
    temp->data=data;
    temp->next=top;
    top=temp;
    return top;
}


int pop(struct stack** top){
    if(isEmpty(*top))
        return -1;
    else{
        struct stack* temp=*top;
        int ret_val=temp->data;
        *top=(*top)->next;
        free(temp);
        return ret_val;
    }
}

int peek(struct stack* top, int index){
    if(top==NULL)
        return -1;
    else{
        int i=1;
        struct stack* temp=top;
        while(temp->next!=NULL){
            if(i==index)
                return temp->data;
            temp=temp->next;
            i++;
        }
        return -1;
    }
}

int main(){
    struct stack * top=(struct stack*)malloc(sizeof(struct stack));
    struct stack * st1=(struct stack*)malloc(sizeof(struct stack));
    struct stack * st2=(struct stack*)malloc(sizeof(struct stack));
    struct stack * st3=(struct stack*)malloc(sizeof(struct stack));
    // st=NULL;
    top->data=7;
    top->next=st1;

    st1->data=22;
    st1->next=st2;

    st2->data=4;
    st2->next=st3;

    st3->data=3;
    st3->next=NULL;
    
    printf("Stack is Empty(1) or not Empty(0): %d\n",isEmpty(top));

    printf("Stack before insertion: \n");
    stackTraversal(top);
    top=push(top,10);
    top=push(top,15);
    top=push(top,16);
    printf("Stack after insertion: \n");
    stackTraversal(top);

    printf("Poped value: %d\n",pop(&top));
    printf("Stack after pop operation: \n");
    stackTraversal(top);

    int val = peek(top,2);
    printf("Output of peek operation at index 2: %d\n",val);

    return 0;
}