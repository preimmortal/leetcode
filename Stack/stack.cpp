//David Lau
//Stack Implementation


#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

struct stack{
    struct node *head;
    struct node *tail;
};

struct node{
    int v;
    node *next;
};

stack *constructStack(){
    stack *S = new stack;
    S->head = NULL;
    S->tail = NULL;
    return S;
}
//Stacks = LIFO
void stackPush(stack *S, int val){
    //Construct new node
    node *n = new node;
    n->v = val;
    n->next = NULL;

    //Case: stack is empty
    if(S->head == NULL){
        S->head = n;
        S->tail = n;
    }
    //Case: stack is not empty
    else{
        n->next = S->head;
        S->head = n;
    }
}

//Pop first element of stack
int stackPop(stack *S){
    int v;
    //Case: stack is empty
    if(S->head == NULL){
        throw;
    }
    //Case: stack is not empty
    else{
        v = S->head->v; 
        node *n = S->head;
        S->head = S->head->next;
        delete(n);
    }
    return v;
}

int main(){
    stack *S = constructStack();
    for(int i=0; i<10; i++){
        stackPush(S, i);
    }
    for(int i=0; i<10; i++){
        printf("%d\n", stackPop(S));
    }
    delete(S);
    return 0;
}
