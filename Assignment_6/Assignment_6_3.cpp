#include <iostream>
using namespace std;

class DoublyList {
    struct Node {
        int data;
        Node *prev, *next;
    };
    Node* head;
public:
    DoublyList() { head = NULL; }

    void insert(int x){
        Node* n = new Node{x,NULL,NULL};
        if(!head) head = n;
        else{
            Node* t = head;
            while(t->next) t = t->next;
            t->next = n;
            n->prev = t;
        }
    }

    int size(){
        int c = 0;
        Node* t = head;
        while(t){
            c++;
            t = t->next;
        }
        return c;
    }
};

class CircularList {
    struct Node {
        int data;
        Node* next;
    };
    Node* head;
public:
    CircularList() { head = NULL; }

    void insert(int x){
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

    int size(){
        if(!head) return 0;
        int c = 0;
        Node* t = head;
        do{
            c++;
            t = t->next;
        }while(t != head);
        return c;
    }
};

int main(){
    DoublyList dl;
    CircularList cl;

    dl.insert(5);
    dl.insert(10);
    dl.insert(15);

    cl.insert(7);
    cl.insert(14);
    cl.insert(21);
    cl.insert(28);

    cout << "Size of Doubly Linked List = " << dl.size() << "\n";
    cout << "Size of Circular Linked List = " << cl.size() << "\n";
}
