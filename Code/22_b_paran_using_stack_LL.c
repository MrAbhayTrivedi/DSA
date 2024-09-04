/* We will be using Linked list to implement the parenthesis matching problem. */

#include<stdio.h>
#include<stdlib.h>

struct stack{
    char data;
    struct stack* next;
};

void stackTraversal(struct stack* top){
    struct stack* temp=top;
    do{
        printf("%d ", temp->data);
        temp=temp->next;
    }while(temp!=NULL);
    printf("\n");
    
}

int isEmpty(struct stack * top){
    if(top==NULL)
        return 1;
    else
        return 0;
}

int isFull(){
    struct stack* temp=(struct stack*)malloc(sizeof(struct stack));
    if (temp==NULL){
        return 1;
    }
    return 0;
}

struct stack* push(struct stack* top, char data){
    struct stack* temp=(struct stack*)malloc(sizeof(struct stack));
    temp->data=data;
    temp->next=top;
    top=temp;
    return top;
}


char pop(struct stack** top){
    if(isEmpty(*top))
        return -1;
    else{
        struct stack* temp=*top;
        char ret_val=temp->data;
        *top=(*top)->next;
        free(temp);
        return ret_val;
    }
}

int parenthesisMatch(char * exp){
    // Create and initialize the stack
    struct stack* sp;
    sp=NULL;
    
    for (int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='('){
            sp=push(sp, '(');
        }
        else if(exp[i]==')'){
            if(isEmpty(sp)){
                return 0;
            }
            pop(&sp); 
        }
    }
 
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
    
}

int main(){
    char *exp="((a+b)*c)-((d-e)*f)()";

    if(parenthesisMatch(exp)){
        printf("The parenthesis is matching");
    }
    else{
        printf("The parenthesis is not matching");
    }
    
    return 0;
}