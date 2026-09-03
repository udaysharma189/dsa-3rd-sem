#include <bits/stdc++.h>
using namespace std;

struct Queue {
    vector<int> item;
    int rear;
    int front;
    int size;

    Queue(int SIZE) {
        item.resize(SIZE);
        size = SIZE;
        rear = -1;
        front = 0;
    }

    bool IsEmpty() {
        return front > rear;
    }

    bool IsFull() {
        return rear == size - 1;
    }

    void EnQueue(int x) {
        if (IsFull()) {
            cout << "OVERFLOW" << endl;
            return;
        }

        rear++;
        item[rear] = x;
    }

    int DeQueue() {
        if (IsEmpty()) {
            cout << "UNDERFLOW" << endl;
            return -1;
        }

        int x = item[front];
        front++;

        return x;
    }
};

int main() {

    Queue Q(5);

    Q.EnQueue(10);
    Q.EnQueue(20);
    Q.EnQueue(30);
    Q.EnQueue(40);

    cout << "Deleted: " << Q.DeQueue() << endl;
    cout << "Deleted: " << Q.DeQueue() << endl;

    Q.EnQueue(50);

    cout << "Deleted: " << Q.DeQueue() << endl;

    return 0;
}