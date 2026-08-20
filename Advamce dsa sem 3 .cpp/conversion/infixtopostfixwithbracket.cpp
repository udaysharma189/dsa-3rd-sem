#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Stack {
    vector<char> item;
    int Top;

public:
    Stack(int s) {
        item.resize(s);
        Top = -1;
    }

    void Push(char x) {
        if (Top == item.size() - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        item[++Top] = x;
    }

    char Pop() {
        if (Top == -1) {
            return '\0';
        }
        return item[Top--];
    }

    char StackTop() {
        if (Top == -1)
            return '\0';
        return item[Top];
    }

    bool IsEmpty() {
        return Top == -1;
    }
};

bool prcd(char a, char b) {
    if (a == '(')
        return false;

    if (b == '(')
        return false;

    if (b == ')')
        return true;

    if (a == '^') {
        return b != '^';
    }

    if (a == '*' || a == '/' || a == '%') {
        return !(b == '^');
    }

    if (a == '+' || a == '-') {
        return (b == '+' || b == '-');
    }

    return false;
}

void InfixToPostfix(string Infix) {
    Stack s(100);
    string Postfix = "";

    for (int i = 0; i < Infix.size(); i++) {
        char symbol = Infix[i];

        if ((symbol >= 'a' && symbol <= 'z') ||
            (symbol >= 'A' && symbol <= 'Z') ||
            (symbol >= '0' && symbol <= '9')) {
            Postfix += symbol;
        }
        else {
            while (!s.IsEmpty() && prcd(s.StackTop(), symbol)) {
                Postfix += s.Pop();
            }

            if (symbol == ')') {
                s.Pop(); // remove '('
            }
            else {
                s.Push(symbol);
            }
        }
    }

    while (!s.IsEmpty()) {
        Postfix += s.Pop();
    }

    cout << Postfix << endl;
}

int main() {
    string Infix;
    cin >> Infix;

    InfixToPostfix(Infix);

    return 0;
}