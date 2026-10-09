// preorder and post order and inorder traversal of binary tree;
#include<iostream>
#include<vector>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
};
node*Newnode(int x){
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
void createtree(node*T){
    int choice;
    cout<<"whether you want to create left child of "<<T->data<<"(1/0): ";
    cin>>choice;
    if(choice==1){
        int x;
        cout<<"Enter the data of left child of "<<T->data<<": ";
        cin>>x;
        node*p=Newnode(x);
        T->left=p;
    }
    cout<<"whether you want to create right child of "<<T->data<<"(1/0): ";
    cin>>choice;
    if(choice==1){
        int x;
        cout<<"Enter the data of right child of "<<T->data<<": ";
        cin>>x;
        node*p=Newnode(x);
        T->right=p;
        createtree(T->right);
    }
    int sum(node*T){
        if(T==NULL)
            return 0;
        return T->data + sum(T->left) + sum(T->right);
    }
int main(){
    node*root=NULL;
    int x;
    cout<<"Enter the data of root node: ";
    cin>>x;
    root=Newnode(x);
    createtree(root);
    cout<<"Sum of all nodes: "<<sum(root)<<endl;
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
