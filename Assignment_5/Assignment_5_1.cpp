#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int value) {
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

void insertBefore(int value, int beforeValue) {
    if (head == NULL) return;

    Node* newNode = new Node();
    newNode->data = value;

    if (head->data == beforeValue) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL && temp->next->data != beforeValue)
        temp = temp->next;

    if (temp->next == NULL) return;

    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAfter(int value, int afterValue) {
    Node* temp = head;
    while (temp != NULL && temp->data != afterValue)
        temp = temp->next;

    if (temp == NULL) return;

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFromBeginning() {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteFromEnd() {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

void deleteSpecific(int value) {
    if (head == NULL) return;
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != value)
        temp = temp->next;
    if (temp->next == NULL) return;
    Node* delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
}

void search(int value) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == value) {
            cout << value << " found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << value << " not found" << endl;
}

void display() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int choice, val, key;

    while (true) {
        cout << "\n1.Insert at Beginning\n2.Insert at End\n3.Insert Before\n4.Insert After\n5.Delete from Beginning\n6.Delete from End\n7.Delete Specific\n8.Search\n9.Display\n10.Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cin >> val;
                insertAtBeginning(val);
                break;
            case 2:
                cin >> val;
                insertAtEnd(val);
                break;
            case 3:
                cin >> val >> key;
                insertBefore(val, key);
                break;
            case 4:
                cin >> val >> key;
                insertAfter(val, key);
                break;
            case 5:
                deleteFromBeginning();
                break;
            case 6:
                deleteFromEnd();
                break;
            case 7:
                cin >> val;
                deleteSpecific(val);
                break;
            case 8:
                cin >> val;
                search(val);
                break;
            case 9:
                display();
                break;
            case 10:
                return 0;
        }
    }
}
