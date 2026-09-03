#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
    
    
    
    
};
node *getnode(){
    node *p;
    p=new node;
    return p;
    
}
node *Enqueue(node *pq,int x){
    node *curr,*prev;
    curr=pq;
    prev=NULL;
    node *r;
    r=getnode();
    r->data=x;


if (prev!=NULL){
    prev->next=r;
    r->next=curr;
    return pq;
    
}
else{
    r->next=pq;
    pq=r;
    return pq;
}}
node *Dequeue(node *pq){
    node *curr,*prev;
    curr=pq;
    prev=NULL;
    if (curr==NULL){
        cout<<"Queue is empty"<<endl;
        return pq;
        
    }
    else{
        while(curr->next!=NULL){
            prev=curr;
            curr=curr->next;
            
        }
        if (prev!=NULL){
            prev->next=NULL;
            delete curr;
            return pq;
            
        }
        else{
            delete curr;
            return NULL;
            
        }
        
    }
    
}

int main() {
    node *pq;
    pq=NULL;
    pq=Enqueue(pq,5);
    pq=Enqueue(pq,1);
    pq=Enqueue(pq,1);
    pq=Enqueue(pq,2);
    pq=Enqueue(pq,2);
    pq=Enqueue(pq,5);
    pq=Enqueue(pq,6);
    pq=Enqueue(pq,9);
    pq=Dequeue(pq);
    pq=Dequeue(pq);
    pq=Dequeue(pq);
    pq=Dequeue(pq);
    
    
    node *p=pq;
    while(p!=NULL){
        cout<<p->data<< " " <<endl;
        p=p->next;
        
    }
    

}