#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    bool isEmpty() { return top == -1; }
    void push(int val) { if (top < MAX - 1) arr[++top] = val; }
    int pop() { return isEmpty() ? 0 : arr[top--]; }
};

int evaluatePostfix(string expr) {
    Stack s;
    for (char c : expr) {
        if (c >= '0' && c <= '9') {       
            s.push(c - '0');              
        } else {                          
            int b = s.pop();
            int a = s.pop();
            switch(c) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/': s.push(a / b); break;
            }
        }
    }
    return s.pop();
}

int main() {
    string postfix;
    cout << "Enter postfix expression (single-digit operands): ";
    getline(cin, postfix);

    cout << "Result: " << evaluatePostfix(postfix) << endl;

    return 0;
}