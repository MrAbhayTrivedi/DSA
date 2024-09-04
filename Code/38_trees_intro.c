/*
A tree usually represents the hierarchy of elements and depicts the relationships between the elements. Trees are considered as one of the largely used facets of data structures. To give you a better idea of how a tree looks like, let me give an example:

                           (7)
                           /|\
                        (8)(2)(11)  
                        / \ \   \
                      (1)(0) (2) (3)
                                   \
                                    (6)
Every circle(here int in bracket) represents a node, and every arrow represents the hierarchy. For you to be able to understand the terminology associated with trees, I will further name these nodes.
                            (7)-A
                           /|\
                       B-(8)(2)(11) -C
                        / \ \ D \
                      E-(1)(0) (2) (3)-H
                            F   G   \
                                    (6)-I

Now, you can very easily say that node C is the child of node A or node B is the parent of node E. You would be wondering what a parent or child is. I was coming to that only.

Terminologies used in trees:

    1. Root: The topmost node of a tree is called the root. There is no edge pointing to it, but one or more than one edge originating from it. Here, A is the root node.
    2. Parent: Any node which connects to the child. Node which has an edge pointing to some other node. Here, C is the parent of H.
    3. Child: Any node which is connected to a parent node. Node which has an edge pointing to it from some other node. Here, H is the child of C.
    4. Siblings: Nodes belonging to the same parent are called siblings of each other. Nodes B, C and D are siblings of each other, since they have the same parent node A.
    5. Ancestors: Nodes accessible by following up the edges from a child node upwards are called the ancestors of that node. Ancestors are also the parents of the parents of …… that node. Here, nodes A, C and H are the ancestors of node I.
    6. Descendants: Nodes accessible by following up the edges from a parent node downwards are called the descendants of that node. Descendants are also the child of the child of …… that node. Here, nodes H and I are the descendants of node C.
    7. Leaf/ External Node: Nodes which have no edge originating from it, and have no child attached to it. These nodes cannot be a parent. Here, nodes E, F, G and I are leaf nodes.
    8. Internal node: Nodes with at least one child. Here, nodes B, D and C are internal nodes.
    9. Depth: Depth of a node is the number of edges from root to that node. Here, the depth of nodes A, C, H and I are 0, 1, 2 and 3 respectively.                                Depth
                           (7)-A   -------------->0
                           /|\
                       B-(8)(2)(11) -C  --------->1
                        / \ \ D \
                      E-(1)(0) (2) (3)-H   ------>2
                            F   G   \
                                    (6)-I  ------>3

    10. Height: Height of a node is the number of edges from that node to the deepest leaf. Here, the height of node A is 3, since the deepest leaf from this node is node I. And similarly, height of node C is 2.
There are still a lot of concepts left. To help you get a better understanding of trees, I presented this brief introduction. These were the basics you had to learn to move to the advanced topics. To understand what lies ahead, you need to learn the terminologies.

Apart from these, there are a few additional points that I would like to add.

    1. A tree with n nodes has n-1 edges. Why n-1?
    Because in a tree, there is one and only edge corresponding to all the nodes except the root node. The root node has no parent, hence no edge pointing to it. Therefore, a total of n-1 edges.

    2. The degree of a node in a tree is the number of children of a node.
    3. The degree of a tree is the highest degree of a node among all the nodes present in the tree.

                           (7) Root Node
                           /|\
                        (8)(2)(11)  
                        / \ \   \  Edge
                      (1)(0) (2) (3)
                                   \
                                    (6) Leaf Node

In the above tree, the number of nodes is 9, and hence the number of edges are 8. You can even count and verify the fact that a tree with n nodes has n-1 edges. Moreover, the highest degree of a node is that of the root node, which has 3 children. Hence the degree of the tree is also 3.

Example and Use of Trees:
    1. Trees are ideally used to represent hierarchical data. Although I should have said most of this in the first video, few things actually become clearer as time goes on. So, trees are useful in representing an organizational hierarchy. 

    2. Another good example would be our file manager in desktops. There is a C Drive, it contains folders Windows, Program Files, etc. which further contain folders. So, they are hierarchically represented using a tree.
*/

#include<stdio.h>
#include<stdlib.h>


int main(){
    printf("Hello World, intro to trees\n");
    return 0;
}