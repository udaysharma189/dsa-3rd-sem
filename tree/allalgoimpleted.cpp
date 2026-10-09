#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct node {
    char data;
    node* left;
    node* right;
};

node* newnode(char x) {
    node* T;
    T = new node;
    T->data = x;
    T->left = NULL;
    T->right = NULL;
    return T;
}

// Count leaf nodes
int countLeaf(node* T) {
    if (T == NULL)
        return 0;

    if (T->left == NULL && T->right == NULL)
        return 1;

    return countLeaf(T->left) + countLeaf(T->right);
}

// Count nodes with two children
int countnN2(node* T) {
    if (T == NULL)
        return 0;

    if (T->left != NULL && T->right != NULL)
        return 1 + countnN2(T->left) + countnN2(T->right);

    return countnN2(T->left) + countnN2(T->right);
}

// Count nodes with one child
int countnN1(node* T) {
    if (T == NULL)
        return 0;

    if (T->left != NULL && T->right != NULL)
        return countnN1(T->left) + countnN1(T->right);

    if (T->left != NULL || T->right != NULL)
        return 1 + countnN1(T->left) + countnN1(T->right);

    return 0;
}

// Check strictly binary tree
int strictlybinary(node* T) {
    if (T == NULL)
        return true;

    if (T->left == NULL && T->right == NULL)
        return true;

    if (T->left != NULL && T->right != NULL)
        return strictlybinary(T->left) && strictlybinary(T->right);

    return false;
}

// Height of tree
int height(node* T) {
    if (T == NULL)
        return 0;

    if (T->left == NULL && T->right == NULL)
        return 0;

    int lh = height(T->left);
    int rh = height(T->right);

    return 1 + max(lh, rh);
}

// Count total nodes
int countnodes(node* T) {
    if (T == NULL)
        return 0;

    return 1 + countnodes(T->left) + countnodes(T->right);
}

// Check complete/perfect condition
int iscomplete(node* T) {
    int N = countnodes(T);
    int h = height(T);

    int x = pow(2, h + 1);

    if (N == x - 1)
        return true;
    else
        return false;
}

int main() {
    node* root = newnode('A');

    root->left = newnode('B');
    root->right = newnode('C');

    root->left->left = newnode('F');

    root->right->left = newnode('D');
    root->right->right = newnode('E');

    cout << "Count of leaf nodes: " << countLeaf(root) << endl;
    cout << "Count of nodes with two children: " << countnN2(root) << endl;
    cout << "Count of nodes with one child: " << countnN1(root) << endl;
    cout << "Is strictly binary: " << strictlybinary(root) << endl;
    cout << "Height: " << height(root) << endl;
    cout << "Is complete: " << iscomplete(root) << endl;

    return 0;
}