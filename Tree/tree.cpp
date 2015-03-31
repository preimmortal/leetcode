//David Lau
//BST Implementation

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

struct tree{
    struct node *root;
};

struct node{
    int val;
    node *right;
    node *left;
};

node *constructNode(int val){
    node *n = new node;
    n->val = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

tree *constructTree(int val){
    tree *T = new tree;
    node *n = constructNode(val);
    T->root = n;
    return T;
}

void treeAdd(node *c, int val){
    //if current node is empty, can be placed
    if(c == NULL){
        node *n =  constructNode(val);

    }
    //Less than or equal (left subtree)
    if(c->val >= val){
        treeAdd(c->left);
    }
    //Greater than (right subtree)
    else{
        treeAdd(c->right);
    }
}


int main(){
    tree *T = constructTree(5);
    return 0;
}
