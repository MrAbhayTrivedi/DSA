/*
Breadth First Search (BFS) Graph Traversal

We should first learn the concept of the BFS spanning tree in order to understand the Breadth-First Search in a very intuitive way.

Method 1: BFS Spanning Tree:

To understand what BFS Spanning Tree means, consider the graph I’ve illustrated below.

                    (0)----(1)
                    |   \    |
                    |    \   |
                    |     \  |
                    (3)-----(2)
                      \     /
                        (4)
                        /\
                       (5) (6)

Now, choose any node, say 0, and try to construct a tree with this chosen node as its root. Or basically, hang this whole tree in a gravity-driven environment with this node and assume those edges are not rigid but flexible. So, the graph would now look something like this.

                    (0)
                    /|\
                (3)-(2)-(1)
                \    /
                  (4)
                  /\
                (5) (6)

Now, mark dashed or simply remove all the edges which are either sideways or duplicate (above a node) to turn this graph into a valid tree, and as you know for a graph to be a tree, it shouldn’t have any cycle. So, we can remove the edges between nodes 2 and 3, and then between nodes 1 and 2 being sideways. Then also between 2 and 4. You could have rather removed the one between node 3 and 4 instead of 2 and 4, but both ways work since these are duplicate to node 4. The tree we receive after we do these above-mentioned changes is,
                    (0)
                    /|\
                (3) (2) (1)
                \    
                  (4)
                  /\
                (5) (6)

This constructed tree above is known as a BFS Spanning Tree. And surprisingly, the level order traversal of this BFS spanning tree gives us the Breadth-First Search traversal of the graph we started originally with. And if you remember what a level order traversal of a tree is, we simply write the nodes in the same level from left to right. So, the level order traversal of the above BFS Spanning Tree is 0, 3, 2, 1, 4, 5, 6.

And a BFS Spanning Tree is not unique to a graph. We could have removed, as discussed above, the edge between nodes 3 and 4, instead of nodes 2 and 4. That would have yielded a different BFS Spanning Tree.

Therefore, given a graph, this is probably the easiest way, I believe, to write the Breadth-First Search traversal of the graph. Here, the chances of making a mistake are minimal. Despite the simplicity of the above technique, there is a very convenient method we follow when we implement the Breadth-First Search traversal algorithm in our program. Let us now discuss that.

Method 2: Conventional Breadth-First Search Traversal Algorithm:

Consider the same graph we covered above. Let me illustrate that again.
                    (0)----(1)
                    |   \    |
                    |    \   |
                    |     \  |
                    (3)-----(2)
                      \     /
                        (4)
                        /\
                       (5) (6)

Considering we could begin with any source node; we'll start with 0 only. Let’s define a queue named exploration queue which would hold the nodes we’ll be exploring one by one. We would maintain another array holding the status of whether a node is already visited or not. Since we are starting with node 0, we would enqueue 0 into our exploration queue and mark it visited.
            Visited: [0]
            Exploration Queue: [0]

Now, we’ll start visiting all the nodes connected to node 0, and remove node 0 from the exploration queue, enqueuing all the currently visited nodes which were nodes 1, 2, and 3. We are pushing them inside the exploration queue because these might further have some unvisited nodes connected to them. Mark these nodes visited as well.
            Visited: [0, 1, 2, 3]
            Exploration Queue: [1, 2, 3]

After this, we have node 1 at the top in the exploration queue, so we'll take it out and visit all unvisited nodes connected to it. Unfortunately, there aren't any. Therefore, we'll continue exploring further.
            Visited: [0, 1, 2, 3]
            Exploration Queue: [2, 3]

Next, we have node 2. And the only unvisited node connected to node 2 is node 4. So, we’ll mark it visited and will also enqueue it in our exploration queue. 
            Visited: [0, 1, 2, 3, 4]
            Exploration Queue: [3, 4]

Node 3 is the next in line. Since, all nodes 1, 2, and 4 which are the nodes connected to it are already visited, we have nothing to do here while we are on node 3.
            Visited: [0, 1, 2, 3, 4]
            Exploration Queue: [4]

Next, we have node 4 on the top in the exploration queue. Let's get it out and see what nodes are connected and unvisited to it. So, we got nodes 5 and 6. Mark them visited and push them inside the exploration queue.
            Visited: [0, 1, 2, 3, 4, 5, 6]
            Exploration Queue: [5, 6]

And now we can explore the other two nodes left in the queue, and since all nodes are already visited, we’ll get nothing in them. And this got our queue emptied and every node traversed in Breadth-First Search manner. 
            Visited: [0, 1, 2, 3, 4, 5, 6]
            Exploration Queue: []

And the order in which we marked our nodes visited is the Breadth-First Search traversal order. Here, it is 0, 1, 2, 3, 4, 5, 6. So basically, the visited array maintains whether the node itself is visited or not, and the exploration queue maintains whether the nodes connected to a node are visited or not. This was the difference. 
*/

#include<stdio.h>
#include<stdlib.h>
 
struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};
 
 
int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
 
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
 
void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        // printf("Enqued element: %d\n", val);
    }
}
 
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f]; 
    }
    return a;
}
 
int main(){
    // Initializing Queue (Array Implementation)
    struct queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));
    
    // BFS Implementation 
    int node;
    int i = 1;
    int visited[7] = {0,0,0,0,0,0,0};
    int a [7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} 
    };
    printf("%d", i);
    visited[i] = 1;
    enqueue(&q, i); // Enqueue i for exploration
    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if(a[node][j] ==1 && visited[j] == 0){
                printf("%d  ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
    return 0;
}
