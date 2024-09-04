/*
Push, Pop and Other Operations in Stack Implemented Using an Array

Operation 1: Push-

    1. The first thing is to define a stack. Suppose we have the creating stack and declaring its fundamentals part done, then pushing an element requires you to first check if there is any space left in the stack.

    2. Call the isFull function which we did in the previous tutorial. If it’s full, then we cannot push anymore elements. This is the case of stack overflow. Otherwise, increase the variable top by 1 and insert the element at the index top of the stack.

    3. So, this is how we push an element in a stack array. Suppose we have an element x to insert in a stack array of size 4. We first checked if it was full, and found it was not full. We retrieved its top which was 3 here. We made it 4 by increasing it once. Now, just insert the element x at index 4, and we are done.

Operation 2: Pop-

Popping an element is very similar to inserting an element. You should first give it a try yourself. There are very subtle changes.

    1. The first thing again is to define a stack. Get over with all the fundamentals. You must have learnt that by now. Then popping an element requires you to first check if there is any element left in the stack to pop.

    2. Call the isEmpty function which we practiced in the previous tutorial. If it’s empty, then we cannot pop any element, since there is none left. This is the case of stack underflow. Otherwise, store the topmost element in a temporary variable. Decrease the variable top by 1 and return the temporary variable which stored the popped element.

    3. So, this is how we pop an element from a stack array. Suppose we make a pop call in a stack array of size 4. We first checked if it was empty, and found it was not empty. We retrieved its top which was 4 here. Stored the element at 4. We made it 3 by decreasing it once. Now, just return the element x, and popping is done.

 
*/

#include<stdio.h>
#include<stdlib.h>
 
struct stack{
    int size ;
    int top;
    int * arr;
};
 
int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
            return 1;
        }
        else{
            return 0;
        }
}
 
int isFull(struct stack* ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}
 
void push(struct stack* ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
 
int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
 
int main(){
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *) malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");
 
    printf("Before pushing, Full: %d\n", isFull(sp));
    printf("Before pushing, Empty: %d\n", isEmpty(sp));

    push(sp, 1);
    push(sp, 23);
    push(sp, 99);
    push(sp, 75);
    push(sp, 3);
    push(sp, 64);
    push(sp, 57);
    push(sp, 46);
    push(sp, 89);
    push(sp, 6); // ---> Pushed 10 values 
    // push(sp, 46); // Stack Overflow since the size of the stack is 10
    printf("After pushing, Full: %d\n", isFull(sp));
    printf("After pushing, Empty: %d\n", isEmpty(sp));

    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    return 0;
}
