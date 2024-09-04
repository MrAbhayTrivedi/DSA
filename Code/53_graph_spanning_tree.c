/*
Spanning Trees & maximum no of possible spanning trees for complete graphs

Subgraphs:

A subgraph of a graph G is a graph whose vertices and edges are subsets of the original graph G. It means that if we consider the graph G illustrated below, then its subgraphs could be the graph S.

                    (0)----(1)
                    |   \    |
                    |    \   |
                    |     \  |        (0)-----(1)
                    (3)-----(2)        |
                      \     /         (3)
                        (4)                S
                        /\
                       (5) (6)
                       G
S is a subgraph of graph G because nodes 0, 1, and 3 form the subset of the set of nodes in G, and the edges connecting 0 to 3 and 0 to 1 also form the subset of the set of edges in G.

Connected Graphs:

A connected graph, as the word connected suggests, is a graph that is connected in the sense of a topological space, i.e., that there is a path from any point to any other point in the graph. And the graph which is not connected is said to be disconnected. 

                 P1 (0)----(1)
                    |   \    |
                    |    \   |
                    |     \  |        
                    (3)-----(2)        
                      \     /         
                        (4)               
                        /\
                       (5) (6)P2

We have marked two random points P1 and P2, and we’ll see if there is a path from P1 to P2. And if you could see, there is indeed a path from P1 to P2 via nodes 2 and 4.
There could be a number of other ways to reach point P2 from P1, but there should exist at least one path from any point to another point for the graph to be called connected, otherwise disconnected. You should check for some other pair of vertices in the above graph. 

Complete Graphs:

A complete graph is a simple undirected graph in which every pair of distinct vertices is connected by a unique edge. Below, I have illustrated complete graphs with 3 and 4 nodes respectively.

                    (0)----(1)
                    \       /
                     \    /
                      \ /
                      (2)
                      complete graph with 3 nodes
As you can see, in any of the examples above, every pair of nodes is connected using a unique edge of their own. That is what makes a graph complete. 

Note: Every complete graph is a connected graph, although every connected graph is not necessarily complete.

What are spanning trees?

As we learnt, a subgraph of a graph G is a graph whose vertices and edges are subsets of the original graph G. Hence, a connected subgraph ‘S’ of a graph G (V, E) is said to be a spanning tree of the graph if and only if:

    1. All the vertices of G are present in S,
    2. No. of edges in S should be |V|-1, where |V| represents the number of vertices.  
That is, for a subgraph of a graph to be called a spanning tree of that graph, it should have all vertices of the original graph and must have exactly |V|-1 edges, where |V| represents the number of vertices and the graph should be connected. 

    (0)----(1)              (0)----(1)
    |        |              |
    |        |              |
    (2)-----(3)           (2)-----(3)
        G                  S


Now, let’s find out, step by step, if graph S is a spanning tree of graph G or not, considering nodes 1 and 3 don't have an edge in common.

Is graph S a subgraph of graph G? ✓
Yes, graph S is a subgraph of graph G. All nodes/vertices present in S are also a part of graph G, and all vertices exist in graph G too. 

Is graph S connected? ✓
Yes, graph S is connected since we can go from any node to any other node via some edges in the graph.

Are all vertices of graph G present in graph S? ✓
Yes, all vertices of graph G which are vertices 0, 1, 2, and 3, are present in graph S.

Does the number of edges in graph S equal the number of vertices in graph G - 1? ✓
Yes, the number of edges in graph S equals the number of vertices in graph G - 1, since the number of vertices in graph G is 4, and the number of edges in graph S is 3.


 If you are asked to create a spanning tree of a graph, you must first plot all the vertices of the original graph. And then create V-1 edges which were there in the original graph and what makes your graph connected. This would be sufficient, and you can just ignore all other edges present in the original graph.

 Number of Spanning trees for Complete graphs:

A complete graph has n(n-2) spanning trees where n represents the number of vertices in the graph. Consider the complete graph I have made below with 4 nodes.
    (0)----(1)              
    |        |              
    |        |              
    (2)-----(3)          
        G                  
This complete graph has 4 vertices, hence the number of spanning trees it can have is, 4 raised to the power (4-2), i.e., 42 which is 16.

Calculating Spanning tree Cost & Minimum Spanning Tree

For easy understanding of things, I’ll walk you all through an instance where there is a subject named Prem, and he’s desperate to meet his beloved who is residing currently at someplace whose location he is not aware of. Although he has good options for places to visit and there are different routes to see all those places. Prem is not sort of a rich brat. He would definitely love to save money while he travels through places. 

Consider the graph given below and the places are shown in the graph are the ones Prem has to visit. He wants to travel through all the places and at the same time for minimum possible expenditure. Each two places are connected through a route and every route would have some travel cost as well.
   Delhi     Chennai
        17
    (0)--(1)              
  7 | \4/ |50              
    |/22\  |              
  (2)--(3)  
     0        
Canada      Hyderabad        

Prem, therefore, needs to come up with an algorithm that will help him find his beloved by wandering through all possible locations and at the least possible cost. And this is where finding a minimum cost spanning tree helps.

Cost of a Spanning Tree:

The cost of the spanning tree is the sum of the weights of all the edges in the tree. Now, consider the example of Prem we took at the beginning, and the graph he was to create a spanning tree of.

Now, suppose we created a spanning tree out of it which I’ve illustrated below.
   Delhi     Chennai
      17
   (0)--(1)
   |
 7 |
  (3)--(2)
     0
Canada      Hyderabad

What would be the cost of this spanning tree? Yes, 17+7+0 which is, 24. Let this cost for the spanning tree S1, be Cost1. Suppose another spanning tree of the same graph be:
   Delhi     Chennai
      17
   (0)--(1)
   |    |
   7    50
   |    |
  (3)  (2)
  Canada      Hyderabad

This spanning tree has a cost worth 17+7+50, which is 74, and which is definitely greater than 24 what we calculated earlier for S1. And therefore, Prem would definitely not want to incur some cost greater than 24.

Minimum spanning tree:

A Minimum Spanning tree, abbreviated as MST, is the spanning tree having the minimum cost. A graph can have a number of spanning trees all having some cost, say S1, S2, S3, S4, and S5 having cost 100, 104, 500, 400, and 10 respectively, but the one incurring the minimum cost is called the minimum spanning tree. Here, S5 having cost 10 would be the minimum spanning tree.

Applications of Minimum Spanning Tree:

Applications of a minimum spanning tree must have gotten somewhat clear from the example of Prem, where we want to traverse all the nodes, which means the graph remains connected but it must have only bare minimum costing edges.
*/

#include<stdio.h>
#include<stdlib.h>


int main(){
    printf("This is graph spanning tree introduction.\n");
    return 0;
}