/*
Introduction to Stack in Data Structures

A stack is a linear data structure. Any operation on the stack is performed in LIFO (Last In First Out) order. This means the element to enter the container last would be the first one to leave the container. It is imperative that elements above an element in a stack must be removed first before fetching any element.

An element can be pushed in this basket-type container illustrated below. Any basket has a limit, and so does our container too. Elements in a stack can only be pushed to a limit. And this extra pushing of elements in a stack leads to stack overflow.

        |             |
        |             | Insertion/Deletion operation can happen on this end
        |             |
        |             |
        |_____________|
        |______2______| Item 2 which entered the basket last will be the first one to come out
        |______3______|

Applications of Stack:

    1. We have talked about function calls before as well. A function until it returns reserves a space in the memory stack. Any function embedded in some function comes above the parent function in the stack. So, first, the embedded function ends, and then the parent one. Here, the function called last ends first.  (LIFO).

    2. Infix to postfix conversion (and other similar conversions) will be dealt with in the coming tutorials.

    3. Parenthesis matching and many more...

Stack ADT:
In order to create a stack, we need a pointer to the topmost element to gain knowledge about the element which is on the top so that any operation can be carried about. Along with that, we need the space for the other elements to get in and their data.

Here are some of the basic operations we would want to perform on stacks:

    1. push(): to push an element into the stack
    2. pop(): to remove the topmost element from the stack

        pop                       ____________
           ^        <------------ |__________|
        |  |          |             push
        |  |          | 
        |             |
        |             |
        |_____________|
        |______2______| 
        |______3______|
            Stack

    3. peek(index): to return the value at a given index
    4. isempty() / isfull() : to determine whether the stack is empty or full to carry efficient push and pull operations.

Implementation:
    A stack element can be implemented by both an array and a linked list. 
*/

#include<stdio.h>
#include<stdlib.h>


int main(){
    
    return 0;
}