/*
Arrays and Abstract Data Type in Data Structure

Abstract Data Types and Arrays:
ADTs or abstract data types are the ways of classifying data structures by providing a minimal expected interface and some set of methods. It is very similar to when we make a blueprint before actually getting into doing some job, be it constructing a computer or a building. The blueprint comprises all the minimum required logistics and the roadmap to pursuing the job.

                         
                        -------->Minimum required functionality
                    ADT
                        -------->Operations

Array - ADT
An array ADT holds the collection of given elements (can be int, float, custom) accessible by their index.

1. Minimal required functionality:
    We have two basic functionalities of an array, a get function to retrieve the element at index i and a set function to assign an element to some index in the array.

        get (i) – get element i
        set (i, num) – set element i to num.
2. Operations:-
    We can have a whole lot of different operations on the array we created, but we’ll limit ourselves to some basic ones.

        Max()
        Min()
        Search ( num )
        Insert ( i, num )
        Append (x)

Static and Dynamic Arrays:
    Static arrays – Size cannot be changed
    Dynamic arrays – Size can be changed

Memory Representations of Array:
    Index--> 0  1  2  3  4  5  6
    Value--> 1  2  3  4  5  6  7            ==> Array of size 7
    Address--> 100 104 108 112 116 120 124

Elements in an array are stored in contiguous memory locations.
Elements in an array can be accessed using the base address in constant time → O (1).
Although changing the size of an array is not possible, one can always reallocate it to some bigger memory location. Therefore resizing in an array is a costly operation.


Array as An Abstract Data Type
Suppose we want to build an array as an abstract data type with our customized set of values and customized set of operations in a heap. Let’s name this customized array myArray. 

Let our set of values which will represent our customized array include these parameters:

    total_size
    used_size
    base_address

And the operations include operators namely,

    max()
    get(i)
    set(i,num)
    add(another_array)

So, now when we are done creating a blueprint of the customized array. We can very easily code their implementation, but before that, let’s first learn what these values and operations, we have defined, do:

Understanding the ADT above:
    total_size: This stores the total reserved size of the array in the memory location.
    used_size: This stores the size of the memory location used.
    base_address: This is a pointer that stores the address of the first element of the array.

    index: 0  1  2  3  4  5
    value: 1  2  3  
           |______||________|
              ||        ||
      Used part of      Unused part of,
      the location        for later use

Here, the total_size returns 6, and the used_size returns 3. 
*/

// Implementing Array as an Abstract Data Type

#include<stdio.h>
#include<stdlib.h>
 
struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};
 
void createArray(struct myArray * a, int tSize, int uSize){
    // (*a).total_size = tSize;
    // (*a).used_size = uSize;
    // (*a).ptr = (int *)malloc(tSize * sizeof(int));
 
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));
}
 
void show(struct myArray *a){
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}
 
void setVal(struct myArray *a){
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter element %d", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
    
}
 
int main(){
    struct myArray marks;
    createArray(&marks, 10, 2);
    printf("We are running setVal now\n");
    setVal(&marks);
 
    printf("We are running show now\n");
    show(&marks);
 
    return 0;
}
