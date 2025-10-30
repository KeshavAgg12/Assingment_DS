#include <iostream>
using namespace std;

class DoublyList {
    struct Node {
        char data;
        Node *prev, *next;
    };
    Node* head;
public:
    DoublyList() { head = NULL; }

    void insert(char x){
        Node* n = new Node{x,NULL,NULL};
        if(!head) head = n;
        else{
            Node* t = head;
            while(t->next) t = t->next;
            t->next = n;
            n->prev = t;
        }
    }

    bool isPalindrome(){
        if(!head || !head->next) return true;
        Node* left = head;
        Node* right = head;
        while(right->next) right = right->next;
        while(left != right && right->next != left){
            if(left->data != right->data) return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

int main(){
    DoublyList list;
    string s;
    cin >> s;
    for(char c : s) list.insert(c);

    if(list.isPalindrome()) cout << "Palindrome";
    else cout << "Not Palindrome";
}
