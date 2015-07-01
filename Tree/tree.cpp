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

void tree::treeDelete(int val){
    //Identify node
    node *n = root;
    node *parent = NULL;
    bool found = false;
    while(n != NULL){
        if(val == n->val){
            found = true;
            break;
        }
        parent = n;
        //Value is less, go left
        if(val < n->val){
            n = n->left;
        }
        //Value is greater, go right
        else{
            n = n->right;
        }
    }

    if(!found){
        cout << "Value " << val << " not found in tree" << endl;
        return;
    }

    //Found node to delete
    else{
        //Case: Leaf Node
        if(n->left == NULL && n->right == NULL){
            //If node is root
            if(parent == NULL){
                node *t = n;
                root = NULL;
                delete n;
                return;
            }
            //Node is not root
            else{
                if(parent->left == n) parent->left = NULL;
                else parent->right = NULL;
                delete n;
                return;
            }
        }
        //Case: 2 Children
        if(n->left != NULL && n->right != NULL){
            if(n->left->right != NULL){
                //Find max of left child and replace node
                //then delete max child
                node *t = n->left;
                node *max_left_p = parent;
                node *max_left = n;
                while(t != NULL){
                    max_left_p = max_left;
                    max_left = t;
                    t = t->right;
                }
                n->val = max_left->val;
                max_left_p->right = NULL;
                delete max_left;
            }
            else{
                //Max of left child is the left child
                //Set equal to left child and delete left child
                node *t = n->left;
                n->val = t->val;
                n->left = t->left;
                delete t;
            }
            return;
        }
        else{
            //Case: 1 Child
            //If node is root
            if(parent == NULL){
                if(n->left != NULL){
                    root = n->left;
                }
                else{
                    root = n->right;
                }
                delete n;
            }

            else{
                //Replace with child
                if(n->left != NULL){
                    if(parent->left == n)
                        parent->left = n->left;
                    else
                        parent->right = n->left;
                    delete n;
                }else{
                    if(parent->left == n)
                        parent->left = n->right;
                    else
                        parent->right = n->right;
                    delete n;
                }
                return;
            }
        }
    }
    
}

int main(){

    /*
    tree T(5);
    T.treeInsert(3);
    T.treeInsert(7);
    T.treeInsert(4);
    T.treeInsert(6);
    T.treeInsert(10);

    T.treeDelete(5);
    T.treePrint(T.getRoot());
    */

    tree T(5);
    T.treeInsert(4);
    T.treeDelete(5);
    T.treePrint(T.getRoot());
    return 0;
}
