#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insert(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

int deleteAllOccurrences(int key) {
    int count = 0;
    while (head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == key) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            count++;
        } else {
            current = current->next;
        }
    }
    return count;
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n, val, key;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        insert(val);
    }
    cin >> key;

    int count = deleteAllOccurrences(key);
    cout << "Count: " << count << endl;
    cout << "Updated Linked List: ";
    display();
}
