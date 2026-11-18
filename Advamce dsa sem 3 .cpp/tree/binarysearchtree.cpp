
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Insert Function
Node* insert(Node* root, int value) {
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Inorder Function
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Search Function
bool search(Node* root, int key) {
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Minimum Function
int findMin(Node* root) {
    if (root == NULL)
        return -1;

    while (root->left != NULL)
        root = root->left;

    return root->data;
}

// Maximum Function
int findMax(Node* root) {
    if (root == NULL)
        return -1;

    while (root->right != NULL)
        root = root->right;

    return root->data;
}

// Main Function
int main() {
    Node* root = NULL;

    root = insert(root, 5);
    insert(root, 4);
    insert(root, 8);
    insert(root, 1);
    insert(root, 9);
    insert(root, 7);
    insert(root, 6);
    insert(root, 2);
    insert(root, 12);
    insert(root, 11);
    insert(root, 10);
    insert(root, 22);
    insert(root, 18);
    insert(root, 17);
    insert(root, 16);

    cout << "Inorder: ";
    inorder(root);

    cout << "\nMinimum: " << findMin(root);
    cout << "\nMaximum: " << findMax(root);

    int key;
    cout << "\nEnter element: ";
    cin >> key;

    if (search(root, key))
        cout << "Element Found";
    else
        cout << "Element Not Found";

    return 0;
}
