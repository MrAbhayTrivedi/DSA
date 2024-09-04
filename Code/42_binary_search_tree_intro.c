/*
Binary Search Trees: Introduction & Properties

Binary Search Trees: 
    ->It is a type of binary tree.
    ->All nodes of the left subtree are lesser than the node itself.
    ->All nodes of the right subtree are greater than the node itself.
    ->Left and Right subtrees are also binary trees.
    ->There are no duplicate nodes.

        (7)
        /\
    (11)  (6)
    Having discussed all the properties, you must now tell me if the above binary tree was a binary search tree or not. The answer should be no. Since the left subtree of the root node has a single element that is greater than the root node violating the 2nd property, it is not a binary search tree. Let me take one more example.
        (7)
        /\
    (1)   (6)
    Tell me if this is a binary search tree. Still no. Because the left subtree is good but the right subtree of the root node is lesser than the root node itself violating the 3rd property.
                    (9)
                    /\
                (4)     (11)
                /\         \
            (2)   (7)      (15)
                   /\        /
                (5)  (8)    (14)
    Take your time and analyze the different properties of a binary search tree and tell if this is a binary search tree or not.

    Solution: YES.
    Why?
    The very first thing to observe here is the properties of a Binary Search Tree. You would check if all the properties are satisfied for each of the nodes of the tree. So, you first start with the root node which is element 9 and see if all the nodes on the left subtree {4, 2, 5, 7} are smaller than 9 and all the nodes of the right subtree {11, 15, 14} are greater than 9. And since they are, we’ll proceed with the next node. Doing this for all the nodes, we’ll conclude that this is a Binary Search Tree. Had there been even one violation for any of the nodes, we would have said, no.
    
    ->Lastly, there is one more amazing property that I've been keeping all along to amaze you. It says the InOrder traversal of a binary search tree gives an ascending sorted array. So, this is one of the easiest ways to check if a tree is a binary search tree. 

    Let’s write the InOrder Traversal of the tree 
    So, the final InOrder traversal order of the above tree is

    2 → 4 → 5 → 6 → 7 → 8 → 9 → 11 → 14 → 15,

    which is obviously in increasingly sorted order. Hence, it is a binary search tree.

    And this is how easy we have made checking if a tree is a binary search tree or not.

*/

//Checking if a binary tree is a binary search tree or not!



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

void inOrder(struct  node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

/*
Creating the function isBST:

    Create an integer function isBST and pass the pointer to the root node of the tree you want to check as the only parameter. Inside the function, check if the pointer is not NULL, as we have been checking the whole time, and this is also considered as the base case for the recursion to stop. If it is NULL, we would simply return 1 since an empty tree is always a binary search tree. Else, this is a complex yet understandable part. You should follow what I am saying.
    Create a static struct Node pointer prev initialised with NULL. This maintains the pointer to the parent node. And since the root node doesn't have any parent, we have initialized it with NULL and made it static.
    Now, see if the left subtree is a Binary Search Tree or not, by calling it recursively. If it is not a BST, return 0 here itself. Else, see if the prev is not NULL otherwise this is the root node of the whole tree and we won't check this condition. If the prev node is not NULL and the current node, which is the root node of the current subtree, is smaller than or equal to the prev node, then we would return 0. Since this violates the increasing orderliness.
    If it still passes all the if conditions we have structured above, we will store the current node in the prev and move it recursively to the right subtree. And this is nothing but a modified version of the InOrder Traversal.

I suggest ignoring the recursion and do not trace how the function isBST works if the function isBST is at all confusing. Just note that we have done nothing but the InOrder traversal of the tree, and we have checked if the previous value is smaller than the current value, that's it.

Note: Static variables are used when we don’t want our value for that variable to change every time that function is called.
*/
int isBST(struct  node* root){
    static struct node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

int main(){
     
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4  

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // preOrder(p);
    // printf("\n");
    // postOrder(p); 
    // printf("\n");
    inOrder(p);
    printf("\n");
    // printf("%d", isBST(p)); 
    if(isBST(p)){
        printf("This is a BST" );
    }
    else{
        printf("This is not a BST");
    }
    return 0;
}
