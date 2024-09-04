/*
Stack Using an Array

If we recall, arrays are linear data structures whose elements are indexed, and the elements can be accessed in constant time with their index. To implement a stack using an array, we’ll maintain a variable that will store the index of the top element.

So, basically, we have few things to keep in check when we implement stacks using arrays.

    1. A fixed-size array. This size can even be bigger than the size of the stack we are trying to implement, to stay on the safe side.

    2. An integer variable to store the index of the top element, or the last element we entered in the array. This value is -1 when there is no element in the array.

 

We will try constructing a structure to embed all these functionalities. Let’s see how.

    struct stack{
        int size;
        int top;
        int* arr;
    }

So, the struct above includes as its members, the size of the array, the index of the top element, and the pointer to the array we will make.

To use this struct,

You will just have to declare a struct stack
Set its top element to -1. 
Furthermore, you will have to reserve memory in the heap using malloc.
    struct stack S;
    S.size = 80;
    S.top = -1;
    S.arr = (int*)malloc(S.size*sizeof(int));

We have used an integer array above, although it is just for the sake of simplicity. You have the freedom to customize your data types according to your needs.

We can now move on implementing the stack ADT, particularly their operators. We have in the list, push and pull, peek, and isempty/full operation. Let’s visit them one by one.

push():

    By pushing, we mean inserting an element at the top of the stack. While using the arrays, we have the index to the top element of the array. So, we’ll just insert the new element at the index (top+1) and increase the top by 1. This operation takes a constant time, O(1). It’s intuitive to note that this operation is valid until (top+1) is a valid index and the array has an empty space.

pop():

    Pop means to remove the last element entered in the stack, and that element has the index top. So, this becomes an easy job. We’ll just have to decrease the value of the top by 1, and we are done. The popped element can even be used in any way we like.
*/

#include <stdio.h>
#include <stdlib.h>
 
struct stack
{
    int size;
    int top;
    int *arr;
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
 
int main()
{
    // Old/Basic way of making a stack
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *) malloc(s.size * sizeof(int));
 
    // Efficient/advanced way of making a stack using -> (arrow operator)
    struct stack *s;
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

        // Check if stack is empty
    if(isEmpty(s)){
        printf("The stack is empty\n");
    }
    else{
        printf("The stack is not empty\n");
    }

    // Pushing an element manually
    s->arr[0] = 7;
    s->top++;
 
    // Check if stack is empty
    if(isEmpty(s)){
        printf("The stack is empty\n");
    }
    else{
        printf("The stack is not empty\n");
    }

 
    return 0;
}
