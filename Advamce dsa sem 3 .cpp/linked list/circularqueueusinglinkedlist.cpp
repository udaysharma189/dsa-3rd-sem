#include <bits/stdc++.h>
using namespace std;

class Queue {
    struct Node {
        int data;
        Node* next;
    };

    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    bool IsEmpty() {
        return front == NULL;
    }

    void EnQueue(int x) {
        Node* newNode = new Node;

        newNode->data = x;

        if (IsEmpty()) {
            front = rear = newNode;
            rear->next = front;
        }
        else {
            newNode->next = front;
            rear->next = newNode;
            rear = newNode;
        }
    }

    int DeQueue() {
        if (IsEmpty()) {
            cout << "UNDERFLOW" << endl;
            return -1;
        }

        int x = front->data;

        if (front == rear) {
            delete front;
            front = rear = NULL;
        }
        else {
            Node* temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }

        return x;
    }

    int Peek() {
        if (IsEmpty()) {
            cout << "QUEUE IS EMPTY" << endl;
            return -1;
        }

        return front->data;
    }

    void Display() {
        if (IsEmpty()) {
            cout << "QUEUE IS EMPTY" << endl;
            return;
        }

        Node* temp = front;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);

        cout << endl;
    }
};

int main() {

    Queue Q;

    Q.EnQueue(10);
    Q.EnQueue(20);
    Q.EnQueue(30);
    Q.EnQueue(40);

    cout << "Circular Queue: ";
    Q.Display();

    cout << "Deleted: " << Q.DeQueue() << endl;

    cout << "After DeQueue: ";
    Q.Display();

    Q.EnQueue(50);

    cout << "After EnQueue: ";
    Q.Display();

    cout << "Front element: " << Q.Peek() << endl;

    return 0;
}