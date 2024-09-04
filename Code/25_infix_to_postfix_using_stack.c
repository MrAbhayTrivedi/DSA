/*
Converting an infix expression to its postfix counterpart needs you to follow certain steps. The following are the steps:

    -> Start moving left to right from the beginning of the expression.
    -> The moment you receive an operand, concatenate it to the postfix expression string.
    -> And the moment you encounter an operator, move to the stack along with its relative precedence number and see if the topmost operator in the stack has higher or lower precedence. If it's lower, push this operator inside the stack. Else, keep popping operators from the stack and concatenate it to the postfix expression until the topmost operator becomes weaker in precedence relative to the current operator.
    -> If you reach the EOE, pop every element from the stack, and concatenate them as well. And the expression you will receive after doing all the steps will be the postfix equivalent of the expression we were given.

For our understanding today, let us consider the expression x - y / z - k * a. Step by step, we will turn this expression into its postfix equivalent using stacks.

1. We will start traversing from the left. 
    Infix             Postfix                       Stack
    x-y/z-k*a                                     |          |
    ^                                             |          |
    |                                             |__________|
    start from here

2. First, we got the letter ‘x’. We just pushed it into the postfix string. Then we got the subtraction symbol ‘-’, and we push it into the stack since the stack is empty.
    Infix             Postfix                       Stack
    x-y/z-k*a         x                           |          |
     ^                                            |          |
     |                                            |___-,1____|

3. Similarly, we push the division operator in the stack since the topmost operator has a precedence number 1, and the division has 2. 
    Infix             Postfix                       Stack
    x-y/z-k*a         xy                           |          |
       ^                                           |___/,2____|
       |                                           |___-,1____|

4. The next operator we encounter is again a subtraction. Since the topmost operator in the stack has an operator precedence number 2, we would pop elements out from the stack until we can push the current operator. This leads to removing both the present operators in the stack since they are both greater or equal in precedence. Don’t forget to concatenate the popped operators to the postfix expression.
    Infix             Postfix                       Stack
    x-y/z-k*a         xyz/-                          |          |
         ^                                           |          |
         |                                           |___-,1____|

5. Next, we have a multiplication operator whose precedence number is 2 relative to the topmost operator in the stack. Hence we simply push it in the stack.
    Infix             Postfix                       Stack
    x-y/z-k*a         xyz/-k                       |          |
           ^                                       |___*,2____|
           |                                       |___-,1____|

6. And then we get to the EOE and still have two elements inside the stack. So, just pop them one by one, and concatenate them to the postfix. And this is when we succeed in converting the infix to the postfix expression.
    Infix             Postfix                       Stack
    x-y/z-k*a         xyz/-ka*-                   |          |
                                                  |          |
                                                  |__________|
    
Follow every step meticulously, and you will find it very easy to master this. You can see if the answer we found at the end is correct manually.  
    x - y / z - k * a →  (( x - ( y / z )) - ( k * a )) →  (( x - [ y z / ]) - [ k a * ]  )  → [ x y z / - ] - [ k a * ]  →  x y z / - k a * - 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct stack
{
    int size;
    int top;
    char *arr;
};
 
int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}
 
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
void push(struct stack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
 
char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int precedence(char ch){
    if(ch == '*' || ch=='/')
        return 3;
    else if(ch == '+' || ch=='-')
        return 2; 
    else
        return 0;
}
 
int isOperator(char ch){
    if(ch=='+' || ch=='-' ||ch=='*' || ch=='/') 
        return 1;
    else
        return 0;
}
char* infixToPostfix(char* infix){
    struct stack * sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10; 
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));
    char * postfix = (char *) malloc((strlen(infix)+1) * sizeof(char));
    int i=0; // Track infix traversal
    int j = 0; // Track postfix addition 
    while (infix[i]!='\0')
    {
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if(precedence(infix[i])> precedence(stackTop(sp))){
                push(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))    
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    // char * infix = "x-y/z-k*d";
    char * infix = "x-y/z-w+k*d";
    printf("postfix is %s", infixToPostfix(infix));
    return 0;
}
