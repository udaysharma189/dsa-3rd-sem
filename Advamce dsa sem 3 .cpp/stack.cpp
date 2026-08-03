#include <bits/stdc++.h>
using namespace std;

class Stack
{
    vector<int> item;
    int top;

public:
    Stack(int s)
    {
        item.resize(s);
        top = -1;
    }

    void push(int x)
    {
        if (top == item.size() - 1)
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            top++;
            item[top] = x;
        }
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        int x = item[top];
        top--;
        return x;
    }

    int StackTop()
    {
        if (top == -1)
        {
            cout << "Stack Empty" << endl;
            return -1;
        }

        return item[top];
    }

    bool IsEmpty()
    {
        return top == -1;
    }
};

int main()
{
    Stack stk(10);

    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    stk.push(6);

    cout << "Top Element : " << stk.StackTop() << endl;

    cout << "Popped : " << stk.pop() << endl;
    cout << "Top Element : " << stk.StackTop() << endl;

    return 0;
}