/*
What is a Binary Tree?

A binary tree is a special type of tree where each node has a degree equal to or less than two which means each node should have at most two children.

Few examples of a binary tree are mentioned below:  
        (7)-A
        / \
B- (8) (2) - C                     (9)-A
            |                      /
           (3)-D                  (1)-B
           \
            (6) -E

Example 1 has nodes A, B, C, D, E with degrees {2, 0, 1, 1, 0} respectively which satisfies the conditions for a binary tree. Similarly, example 2 has nodes A and B, having degrees 1 each, hence a binary tree.

Types of Binary Trees

1. Full or Strict Binary trees:
    Binary trees as we said earlier have a degree of 2 or less than 2. But a strict binary tree is a binary tree having all of its nodes with a degree of 2 or 0. That is each of its nodes either have 2 children or is a leaf node.
2. Perfect Binary Tree:
    A perfect binary tree has all its internal nodes with degree strictly 2 and has all its leaf nodes on the same level. A perfect binary tree as the name suggests appears exactly perfect.
3. Complete Binary Tree:
    A complete binary tree has all its levels completely filled except possibly the last level. And if the last level is not completely filled then the last level’s keys must be all left-aligned.
4. Degenerate tree:
    The easiest of all, degenerate trees are binary trees where every parent node has just one child and that can be either to its left or right. 
5. Skewed trees:
    Skewed trees are binary trees where every parent node has just a single child and that child should be strict to the left or to the right for all the parents. Slewed trees having all the child nodes aligned to the left are called left-skewed trees, and skewed trees having all the child nodes aligned to the right are called right-skewed trees. 
*/
#include<stdio.h>
#include<stdlib.h>


int main(){
    printf("Hello World, Introduction to binary tree!\n");
    return 0;
}