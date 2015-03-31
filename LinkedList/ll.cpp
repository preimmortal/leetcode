//David Lau
//Linked List Implementation
#include <iostream>

using namespace std;

class linkedList{
    struct listNode{
        int v;
        listNode *next;
    };

    public:
        linkedList(){
            head = NULL;
            tail = NULL;
        }

        void listAdd(int val){
            listNode *n = new listNode;
            n->v = val;
            n->next = NULL;

            if(head == NULL){
                head = n;
                tail = n;
            }
            else{
                tail->next = n;
                tail = n;
            }
        }

        void listPrint(){
            listNode *n = head;
            while(n!=NULL){
                cout << n->v << "\n";
                n = n->next;
            }
        }

        //Delete all nodes with specific value from list
        void listDelete(int val){
            listNode *n = head;
            listNode *p = NULL;
            while(n != NULL){
                if(n->v == val){
                    //Case head
                    if(n==head){
                        head = head->next;
                        delete(n);
                        n = head;
                        continue;
                    }
                    //Case Tail
                    else if(n==tail){
                        tail = p;
                        p->next = NULL;
                        delete(n);
                        n=p;
                    }
                    //Case Middle
                    else{
                        p->next = n->next;
                        delete(n);
                        n=p;
                    }
                }
                p = n;
                n = n->next;
            }
        }


    private:
        listNode *head;
        listNode *tail;
};



int main(){
    linkedList L;
    for(int i=0; i<10; i++){
        L.listAdd(i);
    }
    L.listDelete(4);
    L.listPrint();
    return 0;
}
