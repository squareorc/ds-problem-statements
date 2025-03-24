#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    int top;
    char* arr;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new char[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(char c) {
        if (top == capacity - 1) {
            cout << "Stack overflow\n";
            return;
        }
        arr[++top] = c;
    }

    char pop() {
        if (top == -1) {
            cout << "Stack underflow\n";
            return '\0';
        }
        return arr[top--];
    }

    char peek() {
        if (top == -1) {
            return '\0';
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isParenthesisBalanced(const string& expr) {
    Stack stack(expr.length());

    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (stack.isEmpty() || !isMatchingPair(stack.pop(), c)) {
                return false;
            }
        }
    }

    return stack.isEmpty();
}

int main() {
    string equation = "((((a+b)*c)+d)-e)";
    if (isParenthesisBalanced(equation)) {
        cout << "Parentheses are balanced.\n";
    } else {
        cout << "Parentheses are not balanced.\n";
    }
    return 0;
}