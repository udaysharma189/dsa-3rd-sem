#include<iostream>
using namespace std;
class queue{
    vector<int>item;
    int rear;
    int front;
    public:
    queue(int size){
        item.resize(size);
        rear=-1;
        front=0;
    }
    bool Isempty(){
        if(rear-front+1==0)
        return true;
        else
        return false;
    }
    void Enqueue(int x){
        int m=item.size();
        if(rear-front+1<m){
            rear++;
            item[rear]=x;
        }
        else{
            cout<<"Queue is full"<<endl;
        }   
        void Dequeue(){
            if(Isempty()){  
                
                cout<<"Queue is empty"<<endl;
            }
            else{
                cout<<"Deleted element is "<<item[front]<<endl;
                front++;
            }   
    }
}
