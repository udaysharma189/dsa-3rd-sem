#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

void deleteBeginning(Node*& head) {
    if (head == NULL) {
        cout << "List is empty";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL";
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    deleteBeginning(head);

    display(head);

    return 0;
}