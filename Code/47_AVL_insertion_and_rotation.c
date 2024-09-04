/*
Insertion and Rotation in AVL Tree

Now, before we proceed to see what different types of rotation in an AVL tree we have, we would first like to know why rotation is even done.

In an AVL tree, rotations are performed to avoid the unbalancing of a node caused by insertion. Now, suppose we have a small AVL tree having just these two nodes.

                                (7)    An AVL Tree
                                /-1
                             (5)
                              0

And you can see, the balance factor of both the nodes are good, but as soon as we insert a new node having data 4, our updated tree becomes unbalanced to the left. The absolute balance factor of node 7 becomes greater than 1.        
                                (7)    An AVL Tree
                                /-2
                             (5)
                            /-1
                          (4)
                          0

So, the method you will follow to make this tree an AVL again is called rotation. Now, rotations can be of different types, one of them being the LL rotation.

LL Rotation:
    The name LL, just because we inserted the new element to the left subtree of the root. In this rotation technique, you just simply rotate your tree one time in the clockwise direction as shown below.
                    (7)    An AVL Tree          (5)
                   /-2                          /0\
                (5)                           (4)  (7)    
               /-1                             0    0
            (4)
            0
            not balanced                      balanced
    So, our tree got balanced again, with a perfect balance factor at each of its nodes. Next, we have the RR rotation.

RR Rotation:
    Now, suppose we have a small AVL tree having just these two nodes.
                                   (7)    An AVL Tree
                                    +1\
                                      (9)
                                       0
    And you can see, the balance factor of both the nodes are good, but as soon as we insert a new node having data 11, our updated tree becomes unbalanced to the right. The absolute balance factor of node 7 becomes greater than 1.
                                    (7)    An AVL Tree
                                    +2\
                                      (9)
                                       +1\
                                          (11)
                                           0
    So, the method you will follow now to make this tree an AVL again is called the RR rotation. The name RR, just because we inserted the new element to the right subtree of the root. In this rotation technique, you just simply rotate your tree one time in an anti-clockwise direction as shown below.
                (7)    An AVL Tree
                +2\                          (9)
                   (9)                       /0\
                    +1\                     (7) (11)
                     (11)                    0    0
                       0
                       not balanced                      balanced
    So, our tree got balanced again, with a perfect balance factor at each of its nodes.

LR Rotation:
    Now, suppose we have a small AVL tree having just these two nodes.
                                 (7)    An AVL Tree
                                /-1
                             (4)
                              0
    And you can see, the balance factor of both the nodes are good, but as soon as we insert a new node having data 5, our updated tree becomes unbalanced to the left. The absolute balance factor of node 7 becomes greater than 1.
                                  (7)   Not an AVL Tree anymore
                                /-2
                             (4)
                              +1\
                                (5)
                                 0

    So, the method you will follow now to make this tree an AVL again is called the LR rotation. The name LR, just because we inserted the new element to the right to the left subtree of the root. In this rotation technique, there is a subtle complexity, which says, first rotate the left subtree in the anticlockwise direction, and then the whole tree in the clockwise direction. Follow the two steps illustrated below:
    Step 1:
        (7)                                      (7)
        /-2            LR-Rotation               /-2
      (4)              ----------->             (5)
      +1\                 Step1                 /-1
        (5)                                    (4)
         0                                     0
    not balanced                               not balanced
    Step 2:
         (7)                                      
        /-2             LR-Rotation              
       (5)              ----------->              (5)
      /-1                 Step 2                  /0\
     (4)                                      (4)    (7)
      0                                       0       0
    not balanced                               balanced

    So, our tree got balanced again, with a perfect balance factor at each of its nodes. Although it was a bit clumsy, it was achievable. Next, we have the RL rotation.

RL Rotation:
    Now, suppose we have a small AVL tree having just these two nodes.
                                    (7)    An AVL Tree
                                    +1\
                                      (11)
                                       0
    And you can see, the balance factor of both the nodes are good, but as soon as we insert a new node having data 10, our updated tree becomes unbalanced to the right. The absolute balance factor of node 7 becomes greater than 1.          
                                    (7)    An an AVL Tree anymore
                                    +2\
                                      (11)
                                     /-1
                                  (10)
                                   0       
    So, the method you will follow now to make this tree an AVL again is called the RL rotation. The name RL, just because we inserted the new element to the left to the right subtree of the root. We follow the same technique we used above, which says, first rotate the right subtree in the clockwise direction, and then the whole tree in the anticlockwise direction. Follow the two steps illustrated below:

    Step 1:  
    (7)                                       (7)
    +2\                  RL-Rotation           +2\
       (11)              -------->              (10)
       /-1                 Step 1                 +1\
    (10)                                           (11)
     0                                              0
     not balanced                                 not balanced
     Step 2:
    (7)                                       
    +2\                 RL-Rotation          
      (10)              -------->              (10)
        +1\               Step 2               / 0 \
          (11)                               (7)     (11)
           0                                  0        0
     not balanced                              balanced 
    So, our tree got balanced again, with a perfect balance factor at each of its nodes.

Rotate Operations:

We can perform Rotate operations to balance a binary search tree such that the newly formed tree satisfies all the properties of a binary search tree. Following are the two basic Rotate operations:

    Left Rotate Operations.
    Right Rotate Operation

Left Rotate Operations:

In this Rotate Operation, we move our unbalanced node to the left. Consider a binary search tree given below, and the newly formed tree after its left rotation with respect to the root.
         (9)                                 (15)
         /\                                  /\
        (8) (15)        ----->              (9) (20)
             /\         Left Rotation        /\
         (11)   (20)                       (8) (11)
One thing to observe here is that node 11 had to change its parent after the rotation to be able to maintain the balance of the tree.

Right Rotate Operations:

In this Rotate Operation, we move our unbalanced node to the right. Consider a binary search tree given below, and the newly formed tree after its right rotation with respect to the root.
        (15)                                  (9)
         /\                                    /\
        (9) (20)        --------->           (8) (15)
        /\              Right Rotation             /\
      (8) (11)                                   (11) (20)
Again, as you can see that node 11 had to change its parent after the rotation to be able to maintain the balance of the tree. And rotating a tree to its left, and then again to the right, yields the same original tree as you can see from the above two examples.

Let’s move back to the balancing of the AVL tree after insertion.  So, when it comes to complex trees, in order to balance an AVL tree after insertion, we can follow the below-mentioned rules:

    1. For Left-Left insertion - Right rotate once with respect to the first imbalance node.
    2. For Right-Right insertion - Left rotate once with respect to the first imbalance node.
    3. For Left-Right insertion - Left rotate once and then Right rotate once.
    4. For Right-Left insertion - Right rotate once and then Left rotate once.

We’ll now see how a complex tree gets balanced again after an insertion. Consider the binary search AVL tree below:

      (A)
      /1\
    (B) (C)
    /0\  0
  (D) (E)
  0    0
The absolute balance factor of each node is written beside, and you can see how balanced the values are. Now suppose we need to insert an element that gets its position to the right of node D. Now the updated tree looks something like this.
      (A)
      /2\
    (B) (C)
    /1\  0
  (D) (E)
  1\   0
   (F)
    0
And the tree got imbalanced. Now, you follow these steps.

    -> The first thing you would do is search for the node which got imbalanced first. We start iterating from the node we inserted at and move upwards looking for that first imbalance node. Here node A is the one we were searching for.
    -> Second, you see what type of insertion was this with respect to the node we found. Here, the insertion happened to the left to the left of node A. So, this belongs to the first rule we saw above.
    -> Do what the rule says. Here the rule says to right rotate once with respect to the first imbalance node. So, the tree after rotating to the right becomes:
      (A)
      /2\                                (B)
    (B) (C)        ----->               / 0 \
    /1\  0         LL Rotation         (D)  (A)
  (D) (E)                              1\   /0\
  1\   0                               (F) (E) (C)
   (F)                                  0   0   0
    0
And similarly, had this been a type of right-right insertion, we would have first searched the first imbalanced node, and then would have rotated left with respect to it.
*/

#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};
 
int getHeight(struct Node *n){
    if(n==NULL)
        return 0;
    return n->height;
}
 
struct Node *createNode(int key){
    struct Node* node = (struct Node *) malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}
 
int max (int a, int b){
    return (a>b)?a:b;
}
 
int getBalanceFactor(struct Node * n){
    if(n==NULL){
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}
 
struct Node* rightRotate(struct Node* y){
    struct Node* x = y->left;
    struct Node* T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
 
    return x;
}
 
struct Node* leftRotate(struct Node* x){
    struct Node* y = x->right;
    struct Node* T2 = y->left;
 
    y->left = x;
    x->right = T2;
 
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
 
    return y;
}
 
struct Node *insert(struct Node* node, int key){
    if (node == NULL)
        return  createNode(key);
 
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
 
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node);
 
    // Left Left Case
        if(bf>1 && key < node->left->key){
            return rightRotate(node);
        }
    // Right Right Case
        if(bf<-1 && key > node->right->key){
            return leftRotate(node);
        }
    // Left Right Case
    if(bf>1 && key > node->left->key){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    // Right Left Case
    if(bf<-1 && key < node->right->key){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    return node;
}
 
void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
 
int main(){
    struct Node * root = NULL;
 
 
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preOrder(root);
    return 0;
}
