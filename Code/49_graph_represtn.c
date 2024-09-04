/*
Representation of Graphs - Adjacency List, Adjacency Matrix & Other Representations

Ways to represent a graph:

Any representation should basically be able to store the nodes of a graph and their connections between them. And this can be accomplished in so many ways but primarily the most used way to represent a graph is, 
    1. Adjacency List - Mark the nodes with their neighbours
    2. Adjacency Matrix - Aij = 1, if there is an edge between i and j, 0 otherwise.
We’ll see the above two in detail. Meanwhile, other representations include:

    3. Edge Set - Store the pair of nodes/vertices connected with an edge. Example: {(0, 1), (0, 4), (1, 4)}.
    4. Other implementations to represent a graph also exist. For example, Compact list representation, cost adjacency list, cost adjacency matrix, etc. 

Adjacency List:

In this method of representation of graphs, we store the nodes, along with the list of their neighbors. Basically, we maintain a list of all the does, and along with it, we store the list of nodes a particular node is connected with.

So first, we store the nodes we have in the graph.

0                                       (0)-----(1)
1                                        |     /  \
2                                        |   /     (3)
3                                        (2)
4                                         \
                                            (4)
Next, we look for the connections of each of these nodes we stored. Starting with 0, you can see that 0 is connected with both 1 and 2. So, we will store that beside node 0. Next, 1 is connected with all 0, 2, and 3. 2 is connected with both 0 and 4, and 3 is connected with only 1, and 4 is connected with only 2. So, this information gets stored as shown below.
0->(1)->(2)
1->(0)->(2)->(3)          Linked List
2->(0)->(1)->(4)
3->(1)
4->(2)

And the information about the connections of each of the nodes gets stored in separate linked lists as shown in the figure above. And each of the nodes itself acts as a pointer stored in an array pointing to the head of each of the linked lists. So, in this case, we would have an array of length 5 where the first index stores a pointer to the head of the adjacency linked list of the node 0.

And this was the adjacency list representation of graphs, and I can say that this is one of the most used representation methods.


Adjacency Matrix:

Adjacency matrix is another method of representation of graphs, where we represent our graph in the form of a matrix where cells are either filled with 0 or 1. Let’s call the cell falling on the intersection of ith row and jth column be Aij, then the cell would be filled with 1 if there is an edge between node i and j, otherwise, the cell would be filled with a 0.

Cost Adjacency Matrix:

The cost adjacency matrix is another method of representation of weighted graphs, where we represent our graph in the form of a matrix where cells are either filled with 0 or the cost of the edge. Let’s call the cell falling on the intersection of ith row and jth column be Aij, then the cell would be filled with the cost of the edge between node i and j if there is an edge between node i and j, otherwise, the cell would be filled with a 0 and if the cost could also be 0, then we’ll fill -1 in the cell where there is no edge.

Compact List Representation: here, the entire graph is compressed and stored in just one single 1D array.
*/

#include<stdio.h>
#include<stdlib.h>


int main(){
    printf("Graph Representation\n");
    return 0;
}