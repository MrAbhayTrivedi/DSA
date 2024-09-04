/*
Traversal in Binary Tree (InOrder, PostOrder and PreOrder Traversals)

So basically, we have three different ways to traverse in a binary tree. They are InOrder, PostOrder, and PreOrder Traversals. Let's take a sample tree, and walk through it one by one, using each traversal technique for better understanding.

                      (7)
                      / \
                    (11) (2)
                    / \   / \
                 (7)NULL NULL(9)

PreOrder Traversal in a Binary Tree:
    So in this traversal technique, the first node you start with is the root node. And thereafter you visit the left subtree and then the right subtree.
    So, here you first visit the root node element 7 and then move to the left subtree. The left subtree in itself is a tree with root node 11. So, you visit that and move further to the left subtree of this subtree. There you see a single element 7, you visit that, and then move to the right subtree which is a NULL. So, you're finished with the left subtree of the main tree.  Now, you move to the right subtree which has element 2 as its node. And then a NULL to its left and element 9 to its right.

    So basically, you recursively visit each subtree in the same order. And your final traversal order is:
            7 11 7 2 9

PostOrder Traversal in a Binary Tree:
    In this traversal technique, things are quite opposite to the PreOrder traversal. Here, you first visit the left subtree, and then the right subtree. So, the last node you’ll visit is the root node. 
    This was again a general idea of you traverse in a binary tree using PostOrder Traversal. Each time you get a tree, you first visit its left subtree, and then its right subtree, and then move to its root node.
        7 11 9 2 7
InOrder Traversal in a Binary Tree:
    In this traversal technique, we simply start with the left subtree, that is you first visit the left subtree, and then go to the root node and then you’ll visit the right subtree.
    This was a general idea of you traverse in a binary tree using InOrder Traversal. Each time you get a tree, you first visit its left subtree, and then its root node, and then finally its right subtree.
    7 11 7 2 9

Summary:
        InOrder Traversal: Left -> Root -> Right
        PreOrder Traversal: Root -> Left -> Right
        PostOrder Traversal: Left -> Right -> Root

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

void preOrder(struct  node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct  node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void InOrder(struct  node* root){
    if(root!=NULL){
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}


int main(){
     
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);
    // Finally The tree looks like this:
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2  

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    preOrder(p);
    printf("\n");
    postOrder(p);
    printf("\n");
    InOrder(p);
    return 0;
}
/*
*Best* Trick To Find PreOrder, InOrder & PostOrder Traversal

PreOrder Traversal:
    In this method, we start with the node, and then move to the left subtree and then to the right subtree. But the trick says, extend an edge to the left of all the nodes. Follow the figure below to understand what is being said.
                           -(7)
                            /\
                      -(2)   -(1)
                        /\
                    -(0)  -(4)
    And now, start driving from the root to the left of the root node, and whenever you intersect a red edge while driving, print its value.
    And this is how you were quickly able to write the order of nodes you visited first in the PreOrder Traversal. It was 7→2→0→4→1.

PostOrder Traversal:
    In this method, we start with the left subtree first, and then move to the right subtree, and then finally to the root node. But the trick illustrates, extending an edge to the right of all the nodes. Earlier it was left, now it is right. Follow the figure below to understand.
                           (7)-
                            /\
                      (2)-   (1)-
                        /\
                    (0)-  (4)-

    And now, drive the same way we did earlier. Start driving from the root to the left of the root node and whenever you intersect a red edge while driving, print its value. R Arrows have been drawn to direct you to the path we have taken.
    And this is how you were quickly able to write the order of nodes you visited first in the PostOrder Traversal. It was 0→4→2→1→7. 

InOrder Traversal:
    In this method, we start with the left subtree first, and then move to the root node and then finally to the right subtree. But the trick says, extend an edge to the bottom of all the nodes. We went to the left, to the right, and now to the bottom. Follow the figure below to understand.
                            (7)
                            /|\
                        (2)   (1)
                        /|\     |
                    (0)  (4)
                     |    |

    Then, drive as we have done all along. Start driving from the root to the left of the root node and whenever you intersect a red edge while driving, print its value. Arrows have been drawn to direct you to the path we have taken.
    And this is how you were quickly able to write the order of nodes you visited first in the InOrder Traversal. It was 0→2→4→7→1.

 
*/