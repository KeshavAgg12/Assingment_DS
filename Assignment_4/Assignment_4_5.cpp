#include <iostream>
#include <queue>
using namespace std;

class StackTwoQueues {
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            cout << "[Two Queues] Stack is Empty!\n";
            return;
        }
        cout << "[Two Queues] " << q1.front() << " popped.\n";
        q1.pop();
    }

    void top() {
        if (q1.empty()) {
            cout << "[Two Queues] Stack is Empty!\n";
            return;
        }
        cout << "[Two Queues] Top element: " << q1.front() << endl;
    }

    bool isEmpty() {
        return q1.empty();
    }
};

class StackOneQueue {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "[One Queue] Stack is Empty!\n";
            return;
        }
        cout << "[One Queue] " << q.front() << " popped.\n";
        q.pop();
    }

    void top() {
        if (q.empty()) {
            cout << "[One Queue] Stack is Empty!\n";
            return;
        }
        cout << "[One Queue] Top element: " << q.front() << endl;
    }

    bool isEmpty() {
        return q.empty();
    }
};

int main() {
    cout << "--- Stack using Two Queues ---\n";
    StackTwoQueues s2q;
    s2q.push(10);
    s2q.push(20);
    s2q.push(30);
    s2q.top();
    s2q.pop();
    s2q.top();

    cout << "\n--- Stack using One Queue ---\n";
    StackOneQueue s1q;
    s1q.push(5);
    s1q.push(15);
    s1q.push(25);
    s1q.top();
    s1q.pop();
    s1q.top();

    return 0;
}
