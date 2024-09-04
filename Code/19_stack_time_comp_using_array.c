/*
Time complexities of other operations:

    -> isEmpty(): This operation just checks if the top member equals -1. This works in a constant time, hence, O(1).
    -> isFull(): This operation just checks if the top member equals size -1. Even this works in a constant time, hence, O(1).
    -> push(): Pushing an element in a stack needs you to just increase the value of top by 1 and insert the element at the index. This is again a case of O(1).
    -> pop(): Popping an element in a stack needs you to just decrease the value of top by 1 and return the element we ignored. This is again a case of O(1).
    -> peek(): Peeking at a position just returns the element at the index, (top - position + 1), which happens to work in a constant time. So, even this is an example of O(1).
    -> stackTop(): Operations happen to work in a constant runtime, that is O(1).
    -> stackBottom(): Operations happen to work in a constant runtime, that is O(1).
So, basically all the operations we discussed follow a constant time complexity.

 
*/

#include<stdio.h>
#include<stdlib.h>


int main(){
    printf("Done with stack using array.\nThis file is time complexity of stack using array.\n");
    return 0;
}