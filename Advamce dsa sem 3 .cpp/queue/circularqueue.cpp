#include <bits/stdc++.h>
using namespace std;

class Queue {
    vector<int> item;
    int rear;
    int front;
    int size;

public:
    Queue(int SIZE) {
        item.resize(SIZE);
        size = SIZE;
        rear = 0;
        front = 0;
    }

    bool IsEmpty() {
        return rear == front;
    }

    bool IsFull() {
        return (rear + 1) % size == front;
    }

    void EnQueue(int x) {
        if (IsFull()) {
            cout << "OVERFLOW" << endl;
            return;
        }

        item[rear] = x;
        rear = (rear + 1) % size;
    }

    int DeQueue() {
        if (IsEmpty()) {
            cout << "UNDERFLOW" << endl;
            return -1;
        }

        int x = item[front];
        front = (front + 1) % size;
        return x;
    }
};

int main() {
    Queue Q(6);

    Q.EnQueue(10);
    Q.EnQueue(20);
    Q.EnQueue(30);

    cout << "Deleted " << Q.DeQueue() << endl;

    Q.EnQueue(40);
    Q.EnQueue(50);

    cout << "Deleted " << Q.DeQueue() << endl;
    cout << "Deleted " << Q.DeQueue() << endl;

    return 0;
}