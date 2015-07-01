//David Lau
//BST Implementation

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

class node{
    friend class tree;
    private:
        int val;
        node *left;
        node *right;

    public:
        //Constructor 
        node()
            : val(0), left(NULL), right(NULL)
        {}

        //Constructor with Value
        node(int v)
            : val(v), left(NULL), right(NULL)
        {}

        int getVal(){
            return val;
        }

        node *getLeft(){
            return left;
        }

        node *getRight(){
            return right;
        }
};

class tree{
    private:
        node *root;

    public:
        //Constructor
        tree();

        //Constructor with val
        tree(int val);

        //Destructor
        ~tree();
      
        node *getRoot();
        void clear(node *n);
        node *treeSearch(node *n, int val);
        void treePrint(node *n);
        void treeInsert(int val);
        void treeDelete(int val);
        
};

tree::tree(){
    root = NULL;
}

tree::tree(int val){
    root = new node(val);
}

tree::~tree(){
    //Define Destructor
    clear(root);
}

node *tree::getRoot(){
    return root;
}

void tree::clear(node *n){
    if(n == NULL) return;
    clear(n->left);
    clear(n->right);
    delete n;
}

node *tree::treeSearch(node *n, int val){
    //Do Binary Search
    if(n == NULL) return NULL;
    if(n->val == val) return n;
    if(n->val > val) return treeSearch(n->left, val);
    if(n->val < val) return treeSearch(n->right, val);
}

void tree::treePrint(node *n){
    //Do in order print of tree
    if(n == NULL) return;
    cout << n->val << endl;
    treePrint(n->left);
    treePrint(n->right);
}

void tree::treeInsert(int val){
    node *n = new node(val);
    //Case: Tree is empty
    if(root == NULL){
        root = n;
    }

    //Case: Tree is not empty
    node *curr = root;
    node *parent = curr;
    while(curr){
        parent = curr;
        if(val <= curr->val){
            curr = curr->left;
        }else{
            curr = curr->right;
        }
    }
    if(val <= parent->val){
        parent->left = n;
    }else{
        parent->right = n;
    }
}

//TODO: Finish Delete
void tree::treeDelete(int val){
    
}

int main(){
    tree T(5);
    T.treeInsert(3);
    T.treeInsert(7);
    T.treeInsert(4);
    T.treeInsert(6);
    T.treePrint(T.getRoot());
    //out << T.treeSearch(T.getRoot(),0) << endl;
    return 0;
}
