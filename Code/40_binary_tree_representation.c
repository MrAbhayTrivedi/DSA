/*
Representation of a Binary Tree

Array representation of Binary trees: 
Arrays are linear data structures and for arrays to function, their size must be specified before elements are inserted into them. And this counts as the biggest demerit of representing binary trees using arrays. Suppose you declare an array of size 100, and after storing 100 nodes in it, you cannot even insert a single element further, regardless of all the spaces left in the memory.  Another way you’d say is to copy the whole thing again to a new array of bigger size but that is not considered a good practice.

Anyways, we will use an array to represent a binary tree. Suppose we have a binary tree with 7 nodes.

                    (7)
                    / \
                  (11) (2)
                  / \   / \
                (7) (1)(11)(9)
And there are actually a number of ways to represent these nodes via an array. I’ll use the most convenient one where we traverse each level starting from the root node and from left to right and mark them with the indices these nodes would belong to.
                    (7)-0
                    / \
                1-(11) (2)-2
                  / \   / \
              3-(7) (1)(11)(9)-6
                     4   5
And now we can simply make an array of length 7 and store these elements at their corresponding indices.
        index: 0 1 2 3 4 5 6
        value: 7 11 2 7 1 11 9

And you might be wondering about the cases where the binary is just not perfect. What if the last level has distributed leaves? Then let me tell you, there is a way out for that as well. Let’s consider one case here. A binary tree with 9 nodes, and the last two nodes on the extremities of the last level.
                    (7)
                    / \
                  (11) (2)
                  / \   / \
                (7) (1)(11)(9)    
                /            \
               (7)           (9)

Here, while traversing we get stuck at the 8th index. We don’t know if declaring the last node as the 8th index element makes it a general representation of the tree or not. So, we simply make the tree perfect ourselves. We first assume the remaining vacant places to be NULL.
                    (7)
                    / \
                  (11) (2)
                  / \   / \
                (7) (1)(11)(9)    here, N=NULL
                / \  /\ /\  / \
               (7)N N N N N N (9)

And now we can easily mark their indices from 0 to 14.
                    (7)-0
                    / \
                1-(11) (2)-2
                  / \4 5/ \
              3-(7) (1)(11)(9)-6    here, N=NULL
                / \  /\ /\  / \
            7-(7)N N N N N N (9)-14
                 8 9 10 11 12 13 

And the array representation of the tree looks something like this. It is an array of length 15.
     index: 0 1  2 3 4 5  6 7 8 9 10 11 12 13 14
     value: 7 11 2 7 1 11 9 7                 9

But was this even an efficient approach? Like Binary Trees are made only for efficient traversal and insertion and deletion and using an array for that really makes the process troublesome. Each of these operations becomes quite costly to accomplish. And that size constraint was already for making things worse. So overall, we would say that the array representation of a binary is not a very good choice. And what are the other options?

We have another method to represent binary trees called the linked representation of binary trees. Don’t confuse this with linked lists you have studied. And the reason why I am saying that is because linked lists are lists that are linear data structures.

Linked Representation of Binary Trees:

This method of representing binary trees using linked nodes is considered the most efficient method of representation. For this, we use doubly-linked lists. I just hope you recall what doubly-linked lists are. 

Using links makes the understanding of a binary tree very easy. It actually makes us visualize the tree even. Suppose we have a binary tree of 3 levels.

                    (2)
                    / \
                  (1)  (4)
                  / \   / \
                (11)(12)NULL(3)  

Now if you remember a doubly linked list helped us traversing both to the left and the right. And using that we would create a similar node here, pointing both to the left and the right child node. Follow the below representation of a node here in the linked representation of a binary tree.
                    (2)
                    / \

You can see how closely this representation resembles a real tree node, unlike the array representation where all the nodes succumbed to a 2D structure.  And now we can very easily transform the whole tree into its linked representation which is just how we imagined it would have looked in real life.  

                  |  |2|  |
                  /        \
        |  |1|  |           |  |4|  |
        /        \        /        \
|  |11|  |   |  |12|  |  NULL       |  |3|  |
  |    |       |     |               |     |
NULL  NULL    NULL   NULL           NULL   NULL

So, this was the representation of the binary tree we saw above using linked representation. And what are these nodes? These are structures having three structure members, first a data element to store the data of the node, and then two structure pointers to hold the address of the child nodes, one for the left, and the other for the right.
                     / int data
                |  |  |   |               struct Node
                 /        \
            Node* left  Node* right

And let me show you that struct Node definition part in C language:

struct node{
    int data;
    struct node* left;
    struct node* right;
};
*/
#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node *n; // creating a node pointer
    n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data; // Setting the data
    n->left = NULL; // Setting the left and right children to NULL
    n->right = NULL; // Setting the left and right children to NULL
    return n; // Finally returning the created node
}

int main(){
    /*
    // Constructing the root node
    struct node *p;
    p = (struct node *) malloc(sizeof(struct node));
    p->data = 2;
    p->left = NULL;
    p->right = NULL;

    // Constructing the second node
    struct node *p1;
    p1 = (struct node *) malloc(sizeof(struct node));
    p->data = 1;
    p1->left = NULL;
    p1->right = NULL;

    // Constructing the third node
    struct node *p2;
    p2 = (struct node *) malloc(sizeof(struct node));
    p->data = 4;
    p2->left = NULL;
    p2->right = NULL;
    */
   
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(2);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(4);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    return 0;
}
