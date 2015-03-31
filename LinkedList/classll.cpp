//David Lau
//Class Based Linked List


#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

class node{
    friend class list;

    private:
        int val;
        node *next;
    public:
        //Constructor for node with no value
        node()
        : val(0), next(NULL)
        { }
        //Constructor for node with value
        node(int v)
        : val(v), next(NULL)
        { }
        //Constructor for node with value and next pointer 
        node(int v, node *n)
        : val(v), next(n)
        { }

        int getValue(){
            return val;
        }

        node *getNext(){
            return next;
        }
};

class list{
    private:
        node *head;
        node *tail;
    public:
        //Constructor
        list();
        //Constructor with value
        list(int val);
        //Destructor
        ~list();

        void tailAppend(int val);
        void clear();
        void print();
};

list::list(){
    head = NULL;
    tail = NULL;
}

list::list(int val){
    head = new node(val);
    tail = head;
}

list::~list(){
    clear();
}

void list::tailAppend(int val){
    //List is empty
    if(head == NULL){
        head = new node(val);
        tail = head;
    }
    //List is not empty
    else{
        tail->next = new node(val);
        tail = tail->next;
    }
}

void list::clear(){
    while(head != NULL){
        node *p = head;
        head = head->next;
        delete p;
    }
    tail = NULL;
}

void list::print(){
    node *t = head;
    while(t != NULL){
        cout << t->val << endl;
        t = t->next;
    }
}

int main(){
    list L(5);

    for(int i=0; i<10; i++){
        L.tailAppend(i);
    }
    L.print();
    
    return 0;
}
