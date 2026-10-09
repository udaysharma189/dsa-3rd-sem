// preorder and post order and inorder traversal of binary tree;
#include<iostream>
#include<vector>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
};
node*newnode(char x){
    node*p;
    p=new node;
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}
void inorder(node*root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void preorder(node*root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node*root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
int main(){
    node*root=newnode('A');
    root->left=newnode('B');
    root->right=newnode('C');
    root->left->left=newnode('F');
    root->right->left=newnode('D');
    root->right->right=newnode('E');
    cout<<"Inorder: ";
    inorder(root);
    cout<<endl;
    cout<<"Preorder: ";
    preorder(root);
    cout<<endl;
    cout<<"Postorder: ";
    postorder(root);
    cout<<endl;
}
