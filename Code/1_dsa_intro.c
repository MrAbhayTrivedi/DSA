/*
Introduction to Data Structures & Algorithms

Data Structures and Algorithms:
Let's clear up our basics with these terms before deep diving into DSA.  Data Structures and Algorithms are two different things.

Data Structures –  These are like the ingredients you need to build efficient algorithms. These are the ways to arrange data so that they (data items) can be used efficiently in the main memory. Examples: Array, Stack, Linked List, and many more.

Algorithms – Sequence of steps performed on the data using efficient data structures to solve a given problem, be it a basic or real-life-based one.  Examples include: sorting an array.

Some other Important terminologies:

Database – Collection of information in permanent storage for faster retrieval and updation. Examples are MySql, MongoDB, etc.

Data warehouse – Management of huge data of legacy data( the data we keep at a different place from our fresh data in the database to make the process of retrieval and updation fast) for better analysis.

Big data – Analysis of too large or complex data, which cannot be dealt with the traditional data processing applications.


Memory Layout of C Programs:
When the program starts, its code gets copied to the main memory.
The stack holds the memory occupied by functions. It stores the activation records of the functions used in the program. And erases them as they get executed.
The heap contains the data which is requested by the program as dynamic memory using pointers.
Initialized and uninitialized data segments hold initialized and uninitialized global variables, respectively.
Take a look at the below diagram for a better understanding:

                __________________________
                |    Heap                 |
                |                         | 
                |_________________________|
                |                         |
                |   Stack                 |
                |_________________________|
                |   Uninitialized Data    |<-----Static+Global Variables
                |   Initialized Data      |
                |_________________________|
                |   Code Segment          |
                |_________________________|
                        Memory(RAM)
*/

#include<stdio.h>
#include<stdlib.h>


int main(){
    printf("Hello World");
    return 0;
}