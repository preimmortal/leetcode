//David Lau
//Queue Implementation
//FIFO

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

struct queue{
    struct node *head;
    struct node *tail;
};

struct node{
    int v;
    node *next;
};

queue *constructQueue(){
    queue *Q = new queue;
    Q->head = NULL;
    Q->tail = NULL;
    return Q;
}

void queuePush(queue *Q,int val){
    node *n = new node;
    n->v = val;
    n->next =  NULL;
    //Case: Q empty
    if(Q->head == NULL){
        Q->head = n;
        Q->tail = n;
    }
    //Case: Q not empty
    else{
        Q->tail->next = n;
        Q->tail = n;
    }
}

int queuePop(queue *Q){
    //Pop Head
    int val;
    //Case: Q empty
    if(Q->head == NULL){
        throw;
    }
    //Case: Q not empty
    else{
        node *n = Q->head;
        val = n->v;
        Q->head = Q->head->next;
        delete(n);
    }
    return val;
}

int main(){
    queue *Q = constructQueue();

    for(int i=0; i<10; i++){
        queuePush(Q, i);
    }

    for(int i=0; i<10; i++){
        printf("%d\n", queuePop(Q));
    }
    delete(Q);
    return 0;
}
