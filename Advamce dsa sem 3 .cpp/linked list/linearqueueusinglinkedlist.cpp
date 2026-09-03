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
        newNode->next = NULL;

        if (IsEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int DeQueue() {
        if (IsEmpty()) {
            cout << "UNDERFLOW" << endl;
            return -1;
        }

        Node* temp = front;
        int x = front->data;

        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        delete temp;

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

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {

    Queue Q;

    Q.EnQueue(10);
    Q.EnQueue(20);
    Q.EnQueue(30);
    Q.EnQueue(40);

    cout << "Queue: ";
    Q.Display();

    cout << "Deleted: " << Q.DeQueue() << endl;

    cout << "Queue after DeQueue: ";
    Q.Display();

    cout << "Front element: " << Q.Peek() << endl;

    return 0;
}