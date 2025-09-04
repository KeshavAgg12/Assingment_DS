#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    bool isEmpty() { return top == -1; }
    void push(char c) { if (top < MAX - 1) arr[++top] = c; }
    char pop() { return isEmpty() ? '\0' : arr[top--]; }
    char peek() { return isEmpty() ? '\0' : arr[top]; }
};

int precedence(char op) {
    if(op=='^') return 3;
    if(op=='*' || op=='/') return 2;
    if(op=='+' || op=='-') return 1;
    return 0;
}

bool isOperator(char c) {
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='^';
}

string infixToPostfix(string expr) {
    Stack s;
    string postfix = "";
    for(char c: expr) {
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
            postfix += c;
        else if(c=='(')
            s.push(c);
        else if(c==')') {
            while(!s.isEmpty() && s.peek()!='(')
                postfix += s.pop();
            s.pop();
        }
        else if(isOperator(c)) {
            while(!s.isEmpty() && precedence(s.peek()) >= precedence(c))
                postfix += s.pop();
            s.push(c);
        }
    }
    while(!s.isEmpty())
        postfix += s.pop();
    return postfix;
}

int main() {
    string expr;
    cout << "Enter infix expression: ";
    getline(cin, expr);

    cout << "Postfix expression: " << infixToPostfix(expr) << endl;

    return 0;
}
