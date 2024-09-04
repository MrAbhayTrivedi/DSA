/*
Multiple Parenthesis Matching Using Stack 

Parenthesis matching has nothing to do with the validity of the expression. It just tells whether an expression has all the parentheses balanced or not. A balanced parentheses expression has a corresponding closing parenthesis to all of its opening parentheses. When we talk about matching multi parenthesis, our focus is mainly on the three types of an opening parenthesis, [ { ( and their corresponding closing parentheses, ) } ]. So, basically, this tutorial is just an extension of what we learned in the previous two.

Modifying what we did earlier to make it work for multi-matching needs very little attention. Just follow these steps:

1. Whenever we encounter an opening parenthesis, we simply push it in the stack, similar to what we did earlier.

2. And when we encounter a closing parenthesis, the following conditions should be met to declare its balance:

    Before we pop, this size of the stack must not be zero.
    The topmost parenthesis of the stack must match the type of closing parenthesis we encountered.

3. If we find a corresponding opening parenthesis with conditions in point 2 met for every closing parenthesis, and the stack size reduces to zero when we reach EOE, we declare these parentheses, matching or balanced. Otherwise not matching or unbalanced.

So, basically, we modified the pop operation. And that's all. Let's see what additions to the code we would like to make. But before that follow the illustration below to get a better understanding of the algorithm.
                     ___________________________________EOE->is stack empty? 
                    |                                               /      \
 |------------->iterating till EOE<--------------------|             no      yes
 |             ______/   \______                       |     unbalached    balanced
 |        found an             found a                 |         ^
 |      opening parenthesis    closing parenthesis     |         |
 |      /       \                    /      \          |         |
 |      no        yes               yes     no---------|         |
 |______|          |                 |                           |
 |               push in stack    is stack                       |
 |__________________|               empty?                       |
 |                                  /   \                        |
 |                                  no  yes----------------------|
 |                                   |                           |
 |                       does parenthesis match?                 |
 |                            /          \                       |          
 |----------------------------yes         no---------------------|         

    Example: ([a*(3+2]))
    We’ll try checking if the above expression has balanced multi-parentheses or not.

    Step 1: Iterate through the char array, and push the opening brackets of all types at positions 0, 1, 4 inside the stack.
    Step 2: When you encounter a closing bracket of any type in the expression, try checking if the kind of closing bracket you have got matches with the topmost bracket in the stack.
    Step 3: Since we couldn’t pop an opening bracket corresponding to a closed bracket, we would just end the program here, declaring the parentheses unbalanced.


*/

#include <stdio.h>
#include <stdlib.h>
 
struct stack
{
    int size;
    int top;
    char *arr;
};
 
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
 
char stackTop(struct stack* sp){
    return sp->arr[sp->top];
}
 
int match(char a, char b){
    if(a=='{' && b=='}'){
        return 1;
    }
    if(a=='(' && b==')'){
        return 1;
    }
    if(a=='[' && b==']'){
        return 1;
    }
  return 0;  
}
 
int parenthesisMatch(char * exp){
    // Create and initialize the stack
    struct stack* sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_ch;
 
    for (int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(sp, exp[i]);
        }
        else if(exp[i]==')'|| exp[i]=='}' || exp[i]==']'){
            if(isEmpty(sp)){
                return 0;
            }
            popped_ch = pop(sp);
            if(!match(popped_ch, exp[i])){ 
              return 0;  
            }
        }
    }
 
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
    
}
 
int main()
{
    char * exp = "[4-6]((8){(9-8)})";
    
    if(parenthesisMatch(exp)){
        printf("The parenthesis is balanced");
    }
    else{
        printf("The parenthesis is not balanced");
    }
    return 0;
}
