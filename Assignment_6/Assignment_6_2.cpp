#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = NULL;
    }

    void insert(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            head->next = head; // circular
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head; // circular link
    }

    void display() {
        if (head == NULL) return;

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        // Print head value again
        cout << head->data;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insert(20);
    cll.insert(100);
    cll.insert(40);
    cll.insert(80);
    cll.insert(60);

    cll.display();
    return 0;
}

