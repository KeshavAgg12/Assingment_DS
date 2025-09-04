#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX 5

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX - 1);
    }

    void push(int val) {
        if (isFull()) {
            cout << "\nStack Overflow! Cannot push " << val << endl;
        } else {
            arr[++top] = val;
            cout << val << " pushed onto stack\n";
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "\nStack Underflow! Nothing to pop\n";
            return -1;
        } else {
            return arr[top--];
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "\nStack is empty\n";
            return -1;
        } else {
            return arr[top];
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "\nStack is empty\n";
        } else {
            cout << "\nStack elements (top to bottom): ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack s;
    int choice, val;

    while (true) {
        cout << "\n------ Stack Menu ------\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check isEmpty\n";
        cout << "6. Check isFull\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                s.push(val);
                break;

            case 2:
                val = s.pop();
                if (val != -1)
                    cout << "Popped element: " << val << endl;
                break;

            case 3:
                val = s.peek();
                if (val != -1)
                    cout << "Top element: " << val << endl;
                break;

            case 4:
                s.display();
                break;

            case 5:
                if (s.isEmpty())
                    cout << "Stack is empty\n";
                else
                    cout << "Stack is not empty\n";
                break;

            case 6:
                if (s.isFull())
                    cout << "Stack is full\n";
                else
                    cout << "Stack is not full\n";
                break;

            case 7:
                exit(0);

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
