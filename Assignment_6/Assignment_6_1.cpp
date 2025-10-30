#include <iostream>
using namespace std;

class CircularList {
    struct Node {
        int data;
        Node* next;
    };
    Node* head;
public:
    CircularList() { head = NULL; }

    void insertFirst(int x){
        Node* n = new Node{x,NULL};
        if(!head){
            head = n;
            n->next = head;
        } else {
            Node* t = head;
            while(t->next != head) t = t->next;
            n->next = head;
            head = n;
            t->next = head;
        }
    }

    void insertLast(int x){
        Node* n = new Node{x,NULL};
        if(!head){
            head = n;
            n->next = head;
        } else {
            Node* t = head;
            while(t->next != head) t = t->next;
            t->next = n;
            n->next = head;
        }
    }

    void insertAfter(int key,int x){
        if(!head) return;
        Node* t = head;
        do{
            if(t->data == key){
                Node* n = new Node{x,t->next};
                t->next = n;
                return;
            }
            t = t->next;
        } while(t != head);
    }

    void insertBefore(int key,int x){
        if(!head) return;
        if(head->data == key){
            insertFirst(x);
            return;
        }
        Node* t = head;
        Node* prev = NULL;
        do{
            if(t->data == key){
                Node* n = new Node{x,t};
                prev->next = n;
                return;
            }
            prev = t;
            t = t->next;
        } while(t != head);
    }

    void del(int key){
        if(!head) return;
        Node* t = head;
        Node* prev = NULL;
        do{
            if(t->data == key){
                if(t == head){
                    Node* last = head;
                    while(last->next != head) last = last->next;
                    if(last == head){
                        delete head;
                        head = NULL;
                        return;
                    }
                    head = head->next;
                    last->next = head;
                    delete t;
                    return;
                }
                prev->next = t->next;
                delete t;
                return;
            }
            prev = t;
            t = t->next;
        } while(t != head);
    }

    void search(int key){
        if(!head){ cout<<"Not Found\n"; return; }
        Node* t = head;
        do{
            if(t->data == key){ cout<<"Found\n"; return; }
            t = t->next;
        } while(t != head);
        cout<<"Not Found\n";
    }

    void display(){
        if(!head) return;
        Node* t = head;
        do{
            cout<<t->data<<" ";
            t = t->next;
        } while(t != head);
        cout<<"\n";
    }
};

int main(){
    CircularList list;
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
