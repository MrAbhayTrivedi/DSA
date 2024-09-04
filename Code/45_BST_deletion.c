/*
Deletion in a Binary Search Tree


You might be wondering how big a deal is deleting some nodes in a binary search tree. Well, for cases like the one I have drawn below, where you’ll be asked to remove say element 4 seems quite an easy job. You’ll just search for the element and remove it.
                            (8)
                            /\
                        (3)    (10)
                        /\        \
                    (1)   (6)     (14)
                           /\      /
                       (4) (7)  (13) 

But deleting in a binary search tree is no doubt a tough job like if you consider a case where the node, we’ll have to remove might not be a leaf node or the node is the root node.

So, whenever we talk about deleting a node from binary search tree, we have the following three cases in mind:

    ->The node is a leaf node.
    ->The node is a non-leaf node.
    ->The node is the root node.

Deleting a leaf node:
    Deleting a leaf node is the simplest case in deletion in binary search trees where the only thing you have to do is to search the element in the tree, and remove it from the tree, and make its parent node point to NULL. To be more specific, follow the steps below to delete a leaf node along with the illustrations of how we delete a leaf node in the above tree:

    -> Search the node.
    -> Delete the node.
                            (8)
                            /\
                        (3)    (10)
                        /\        \                (7)--Deleted Node
                    (1)   (6)     (14)
                           /\      /
                        (4) NULL  (13) 

Deleting a non-leaf node:
    Now suppose the node is not a leaf node, so you cannot just make its parent point to NULL, and get away with it. You have to even deal with the children of this node. Let’s try deleting node 6 in the above binary search tree.

    -> So, the first thing you would do is to search element 6.
    -> Now the dilemma is, which node will replace the position of node 6. Well, there is a simple answer to it. It says, when you delete a node that is not a leaf node, you replace its position with its InOrder predecessor or Inorder successor.
So, what does that mean? It means that if you write the InOrder traversal of the above tree, which I have already taught in my previous lectures, the nodes coming immediately before or after node 6, will be the one replacing it. So, if you write the InOrder traversal of the tree, you will get:

1→ 3→ 4 →6 →7→ 8→ 10→ 13→ 14

So, the InOrder predecessor and the Inorder successor of node 6 are 4 and 7 respectively. Hence you can substitute node 6 with any of these nodes, and the tree will still be a valid binary search tree. Refer to how it looks below.

                            (8)                 (8)
                            /\                  /\
                        (3)    (10)           (3)  (10)
                        /\        \           /\      \
                    (1)   (4)     (14)      (1)  (7)   (14)
                            \      /              /      /
                            (7)  (13)            (4)   (13)
So, both are still binary search trees. In the first case, we replaced node 6 with node 4. And the right subtree of node 4 is 7, which is still bigger than it. And in the second case, we replaced node 6 with node 7. And the left subtree of node 7 is 4, which is still smaller than the node. Hence, a win-win for us.

Deleting the root node: 
    -> Now, if you carefully observe, the root node is still another non-leaf node. So, the basics to delete the root node remains the same as what we did for a general non-leaf node. But since the root node holds a big size of subtrees along with, we have put this as a separate case here.
                            ((8))
                            /\
                        (3)    (10)
                        /\        \
                    (1)   (6)     (14)
                           /\      /
                        (4) (7)  (13) 
    -> So, the first thing you do is write the InOrder traversal of the whole tree. And then replace the position of the root node with its InOrder predecessor or Inorder successor. So, here the traversal order is,
            1→ 3→ 4 →6 →7→ 8→ 10→ 13→ 14

    So, the InOrder predecessor and the Inorder successor of the root node 8 are 7 and 10 respectively. Hence you can substitute node 8 with any of these nodes, but there is a catch here. So, if you substitute the root node here, with its InOrder predecessor 7, the tree will still be a binary search tree, but when you substitute the root node here, with its InOrder successor 10, there still becomes an empty position where node 10 used to be. So, we still placed the InOrder successor of 10, which was 13 on the position where 10 used to be. And then there are no empty nodes in between. This finalizes our deletion.
                            (7)                 (10)
                            /\                   /\
                        (3)    (10)           (3)  (13)
                        /\        \           /\      \
                    (1)   (6)     (14)      (1)  (6)  (14)
                           /      /              / \      
                        (4)    (13)            (4) (7)

So, there are a few steps:

->First, search for the node to be deleted.
->Search for the InOrder Predecessor and Successor of the node.
->Keep doing that until the tree has no empty nodes.
And this case is not limited to the root nodes, rather any nodes falling in between a tree. Well, there could be a case where the node was not found in the tree, so, for that, we would revert the statement that the node could not be found.
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
 
void inOrder(struct  node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
 
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
 
struct node * searchIter(struct node* root, int key){
    while(root!=NULL){
        if(key == root->data){
            return root;
        }
        else if(key<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return NULL;
}
 
void insert(struct node *root, int key){
    struct node *prev = NULL;
    while(root!=NULL){
        prev = root;
        if(key==root->data){
            printf("Cannot insert %d, already in BST", key);
            return;
        }
        else if(key<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    struct node* new = createNode(key);
    if(key<prev->data){
        prev->left = new;
    }
    else{
        prev->right = new;
    }
}

struct node *inOrderPredecessor(struct node* root){
    root = root->left;
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *deleteNode(struct node *root, int value){

    struct node* iPre;
    if (root == NULL){
        return NULL;
    }
    if (root->left==NULL&&root->right==NULL){
        free(root);
        return NULL;
    }

    //searching for the node to be deleted
    if (value < root->data){
        root-> left = deleteNode(root->left,value);
    }
    else if (value > root->data){
        root-> right = deleteNode(root->right,value);
    }
    //deletion strategy when the node is found
    else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
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

    inOrder(p);
    printf("\n");
    deleteNode(p, 3);
    inOrder(p);

    return 0;
}
