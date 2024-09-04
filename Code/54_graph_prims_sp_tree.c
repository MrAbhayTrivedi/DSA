/*
Prims Minimum Spanning Tree

Prim’s Algorithm:

    -> Prim’s algorithm uses the Greedy approach to find the minimum spanning tree.
    -> There are mainly two steps that this algorithm follows to find the minimum spanning tree of a graph:
        1. We start with any node and start creating the Minimum Spanning Tree.
        2. In Prim’s Algorithm, we grow the spanning tree from a starting position until n-1 edges are or all nodes are covered. 

Let me now take a simple example. Consider the complete graph with 4 vertices, K4, illustrated below: 
        (0)--2--(1)
        | \ 3  / |
        6   \/   8
        |  1 /\  |
       (3)--15--(2)
        K4
Now, as the first step says, we can start without any node in the graph. Arbitrarily, we will choose node 1. And since the edge between nodes 1 and 3 is the least weighted, we’ll consider this edge in our minimum spanning tree. 
        (1)
        /1
     (3)
     spanning tree

Next, we’ll try involving node 0 in our spanning tree. Possible candidates for connecting node 0 from either node 3 or node 1 which compose the current spanning tree are edges having weights 6 and 2.  Obviously, we’ll choose the one with weight 2.
        (0)--2--(1)
                /
              /1
            (3)
            spanning tree
Now, the only node left is node 2. Possible candidates for connecting this node to the current spanning tree are edges with weights 15, 3, and 8. And there shouldn’t be any doubt while considering the edge with weight 3.

        (0)--2--(1)
          \    /
           \3/
           /\
         1/  \
        (3)     (2)
        spanning tree
    
The cost of this spanning tree is (1+2+3), i.e., 6 which is the minimum possible. And that finishes our construction of the spanning tree for graph K4. And this is exactly the way Prim’s algorithm works.
*/

#include<stdio.h>
#include<stdlib.h>


int main(){
    printf("Prims Minimum Spanning Tree Algorithm\n");
    return 0;
}