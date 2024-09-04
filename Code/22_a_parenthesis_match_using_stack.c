/*
Parenthesis Matching Problem Using Stack Data Structure (Applications of Stack)

What is parenthesis matching?
If you remember learning mathematics in school, we had BODMAS there, which required you to solve the expressions, first enclosed by brackets, and then the independent ones. That's the bracket we're referring to. We have to see if the given expression has balanced brackets which means every opening bracket must have a corresponding closing bracket and vice versa.

Below given illustrations would surely make it clear for you.
                      |```|   |```|
            Example: ((a+b)*c-(d+e))  
                     |_____________|
                        Balanced Parenthesis

            Example: 1-3)*4(8  
                        ^  ^
                        |  |
        No corresponding   No corresponding
        opening bracket    closing bracket

                    Unbalanced Parenthesis
Checking if the parentheses are balanced or not must be a cakewalk for humans, since we have been dealing with this for the whole time. But even we would fail if the expression becomes too large with a great number of parentheses. This is where automating the process helps. And for automation, we need a proper working algorithm. We will see how we accomplish that together.

We’ll use stacks to match these parentheses. Let’s see how:

    1. Assume the expression given to you as a character array.
        3*2-(8+1)   --->   Index: 0 1 2 3 4 5 6 7 8 9
                        Values: 3 * 2 - ( 8 + 1 ) \0

    2. Iterate through the character array and ignore everything you find other than the opening and the closing parenthesis.  Every time you find an opening parenthesis, push it inside a character stack. And every time you find a closing parenthesis, pop from the stack, in which you pushed the opening bracket.
    3. Conditions for unbalanced parentheses:

        -> When you find a closing parenthesis and try achieving the pop operation in the stack, the stack must not become underflow. To match the existing closing parenthesis, at least one opening bracket should be available to pop. If there is no opening bracket inside the stack to pop, we say the expression has unbalanced parentheses.
        -> For example: the expression (2+3)*6)1+5 has no opening bracket corresponding to the last closing bracket. Hence unbalanced.
        -> At EOE, that is, when you reach the end of the expression, and there is still one or more opening brackets left in the stack, and it is not empty, we call these parentheses unbalanced.
        -> For example: the expression (2+3)*6(1+5 has 1 opening bracket left in the stack even after reaching the EOE. Hence unbalanced.

    4. Note: Counting and matching the opening and closing brackets numbers is not enough to conclude if the parentheses are balanced. For eg: 1+3)*6(6+2.

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
 
int parenthesisMatch(char * exp){
    // Create and initialize the stack
    struct stack* sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
 
 
    for (int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='('){
            push(sp, '(');
        }
        else if(exp[i]==')'){
            if(isEmpty(sp)){
                return 0;
            }
            pop(sp); 
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
    // char * exp = "((8)(*--$$9))";
    char * exp = "8)*(9)";
    // Check if stack is empty
    if(parenthesisMatch(exp)){
        printf("The parenthesis is matching");
    }
    else{
        printf("The parenthesis is not matching");
    }
    return 0;
}

/*
Note: Parenthesis matching nowhere tells us if the given expression is mathematically valid or not. Because it is not supposed to, this algorithm has been meant just to return whether the parentheses in the expression are balanced or not.

For e.g., the expression ((8)(*9)) is mathematically invalid but has balanced parentheses.
*/