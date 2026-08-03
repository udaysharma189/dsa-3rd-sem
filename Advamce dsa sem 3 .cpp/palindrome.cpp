#include <iostream>
#include <vector>
using namespace std;

class Stack {
public:
    vector<char> item;
    int top;

    Stack(int M) {
        item.resize(M);
        top = -1;
    }

    void push(char x) {
        if (top == item.size() - 1) {
            cout << "Stack Overflow" << endl;
        } else {
            top++;
            item[top] = x;
        }
    }

    char pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return '\0';
        } else {
            char x = item[top];
            top--;
            return x;
        }
    }

    char stackTop() {
        if (top == -1) {
            cout << "Stack is Empty" << endl;
            return '\0';
        }
        return item[top];
    }

    bool isEmpty() {
        return (top == -1);
    }
};

int main() {
    Stack s(6);

    s.push('A');
    s.push('B');
    s.push('C');
    s.push('D');

    char x = s.pop();
    cout << x << endl;

    x = s.stackTop();
    cout << x << endl;

    s.push('E');

    x = s.pop();
    cout << x << endl;

    x = s.pop();
    cout << x << endl;

    x = s.pop();
    cout << x << endl;

    return 0;
}