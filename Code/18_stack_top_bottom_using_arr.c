/*
stackTop, stackBottom

    stack: index: 0 1  2  3 4
           value: 7 11 22 
                        ^
                        |
                        top
stackTop:

This operation is responsible for returning the topmost element in a stack. Retrieving the topmost element was never a big deal. We can just use the stack member top to fetch the topmost index and its corresponding element. Here, in the illustration above, we have the top member at index 2. So, the stackTop operation shall return the value 22.

 

stackBottom:

This operation is responsible for returning the bottommost element in a stack, which intuitively, is the element at index 0. We can just fetch the bottommost index, which is 0, and return the corresponding element. Here, in the illustration above, we have the bottommost element at index 0. So, the stackBottom operation shall return the value 7.
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
 
int peek(struct stack* sp, int i){
    int arrayInd = sp->top -i + 1;
    if(arrayInd < 0){
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else{
        return sp->arr[arrayInd];
    }
}
 
int stackTop(struct stack* sp){
    if (sp->top == -1){
        printf("Stack is empty\n");
        return -1;
    }
    return sp->arr[sp->top];
}
 
int stackBottom(struct stack* sp){
    if (sp->top == -1){
        printf("Stack is empty\n");
        return -1;
    }
    return sp->arr[0];
}
 
int main(){
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 50;
    sp->top = -1;
    sp->arr = (int *) malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");
 
    printf("Before pushing, Full: %d\n", isFull(sp));
    printf("Before pushing, Empty: %d\n", isEmpty(sp));
    printf("Call before pushing: The top most value of this stack is %d\n", stackTop(sp));
    printf("Call before pushing: The bottom most value of this stack is %d\n", stackBottom(sp));
    push(sp, 1);
    push(sp, 23);
    push(sp, 99);
    push(sp, 75);
    push(sp, 3);
    push(sp, 64);
    push(sp, 57);
    push(sp, 46);
    push(sp, 89);
    push(sp, 6);  
    push(sp, 5);  
    push(sp, 75);  
    
    // // Printing values from the stack
    // for (int j = 1; j <= sp->top + 1; j++)
    // {
    //     printf("The value at position %d is %d\n", j, peek(sp, j));
    // }
     
    printf("Call after pushing: The top most value of this stack is %d\n", stackTop(sp));
    printf("Call after pushing: The bottom most value of this stack is %d\n", stackBottom(sp));
    return 0;
}
