#include <iostream>
#include <string>

using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to check precedence of operators
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

// Manual stack implementation
struct Stack {
    char arr[100];
    int top = -1;

    void push(char c) {
        arr[++top] = c;
    }

    char pop() {
        return arr[top--];
    }

    char peek() {
        return arr[top];
    }

    bool empty() {
        return top == -1;
    }
};

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    Stack st;
    string postfix = "";

    for (char c : infix) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix += c; // Append operands directly
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() && st.peek() != '(') {
                postfix += st.pop();
            }
            st.pop(); // Remove '('
        } else if (isOperator(c)) {
            while (!st.empty() && precedence(st.peek()) >= precedence(c)) {
                postfix += st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        postfix += st.pop();
    }

    return postfix;
}

// Function to reverse a string
string reverseString(string str) {
    string reversed = "";
    for (int i = str.length() - 1; i >= 0; i--) {
        reversed += str[i];
    }
    return reversed;
}

// Function to convert infix to prefix
string infixToPrefix(string infix) {
    infix = reverseString(infix);
    for (char &c : infix) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }

    string postfix = infixToPostfix(infix);
    return reverseString(postfix);
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    string prefix = infixToPrefix(infix);

    cout << "Postfix: " << postfix << endl;
    cout << "Prefix: " << prefix << endl;

    return 0;
}
