/*
Searching in a Binary Search Trees (Search Operation)

For our purpose of understanding, we will first examine a sample binary search tree. Suppose we have a Binary Search Tree illustrated below.
                                (50)
                                 /\
                            (40)   (60)
                            /\       /\
                        (20) (45) (55) (70)

And let’s say the key we want to search in this binary search tree is 55.  Let’s start our search. So, we’ll first compare our key with the root node itself, which is 50.

But since 50 is less than 55, which side should we proceed with? Left, or Right? Of course, right. Since all the elements in the right subtree of a node are greater than that node, we’ll move to the right. The first element we check our key with is 60.

Now, since our key is smaller than 60, we’ll move to the left of the current node. The Left subtree of 60 contains only one element and since that is equal to our key, we revert the positive result that yes, the key was found. Had this leaf node been not equal to the key, and since there are no subtrees further, we would have stopped here itself with negative results, saying the key was not found.

Time Complexity of the Search Operation in a Binary Search Tree:

If you remember, we had studied an algorithm called the Binary Search. We could use that algorithm only if the array we were searching for some key in was sorted. And that algorithm had the time complexity of O(logn) where n was the length of the array. Because we were always dividing our search space into half on the basis of whether our key was smaller or greater than the mid.  And as you might have guessed, searching in a binary search tree is very much similar to that.

Searching in a binary search tree holds O(logn) time complexity in the best case where n is the number of nodes making it incredibly easier to search an element in a binary search tree, and even operations like inserting get relatively easier.

Let’s calculate exactly what happens. If you could see the above examples, the algorithm took the number of comparisons equal to the height of the binary search tree, because at each comparison we stepped down the depth by 1. So, the time complexity T ∝ h, that is, our time complexity is proportional to the height of the tree. Therefore, the time complexity becomes O(h).

Now, if you remember, the height of a tree ranges from logn to n, that is

(logn)   ≤   h   ≤ n

So, the best-case time complexity is O(logn) and the worst-case time complexity is O(n).

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


//Recursive Search in a Binary Search Tree
struct node * search(struct node* root, int key){
    if(root==NULL){
        return NULL;
    }
    if(key==root->data){
        return root;
    }
    else if(key<root->data){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
}

//Iterative Search in a Binary Search Tree
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

    struct node* n = search(p, 10);
    if(n!=NULL){
    printf("Found: %d\n", n->data);
    }
    else{
        printf("Element not found\n");
    }

    struct node* m = searchIter(p, 6);
    if(m!=NULL){
    printf("Found: %d\n", m->data);
    }
    else{
        printf("Element not found\n");
    }
    return 0;
}
