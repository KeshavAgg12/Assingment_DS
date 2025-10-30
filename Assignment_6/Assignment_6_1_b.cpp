#include <iostream>
using namespace std;

class DoublyList {
    struct Node {
        int data;
        Node *prev,*next;
    };
    Node* head;
public:
    DoublyList(){ head = NULL; }

    void insertFirst(int x){
        Node* n = new Node{x,NULL,head};
        if(head) head->prev = n;
        head = n;
    }

    void insertLast(int x){
        Node* n = new Node{x,NULL,NULL};
        if(!head) head = n;
        else{
            Node* t = head;
            while(t->next) t = t->next;
            t->next = n;
            n->prev = t;
        }
    }

    void insertAfter(int key,int x){
        Node* t = head;
        while(t){
            if(t->data == key){
                Node* n = new Node{x,t,t->next};
                if(t->next) t->next->prev = n;
                t->next = n;
                return;
            }
            t = t->next;
        }
    }

    void insertBefore(int key,int x){
        Node* t = head;
        while(t){
            if(t->data == key){
                if(t == head){
                    insertFirst(x);
                    return;
                }
                Node* n = new Node{x,t->prev,t};
                t->prev->next = n;
                t->prev = n;
                return;
            }
            t = t->next;
        }
    }

    void del(int key){
        Node* t = head;
        while(t){
            if(t->data == key){
                if(t->prev) t->prev->next = t->next;
                else head = t->next;
                if(t->next) t->next->prev = t->prev;
                delete t;
                return;
            }
            t = t->next;
        }
    }

    void search(int key){
        Node* t = head;
        while(t){
            if(t->data == key){ cout<<"Found\n"; return; }
            t = t->next;
        }
        cout<<"Not Found\n";
    }

    void display(){
        Node* t = head;
        while(t){
            cout<<t->data<<" ";
            t = t->next;
        }
        cout<<"\n";
    }
};

int main(){
    DoublyList list;
    int ch,x,key;
    while(true){
        cout<<"1 Insert First\n2 Insert Last\n3 Insert After\n4 Insert Before\n5 Delete\n6 Search\n7 Display\n8 Exit\n";
        cin>>ch;
        if(ch==1){ cin>>x; list.insertFirst(x); }
        else if(ch==2){ cin>>x; list.insertLast(x); }
        else if(ch==3){ cin>>key>>x; list.insertAfter(key,x); }
        else if(ch==4){ cin>>key>>x; list.insertBefore(key,x); }
        else if(ch==5){ cin>>key; list.del(key); }
        else if(ch==6){ cin>>key; list.search(key); }
        else if(ch==7){ list.display(); }
        else break;
    }
}
