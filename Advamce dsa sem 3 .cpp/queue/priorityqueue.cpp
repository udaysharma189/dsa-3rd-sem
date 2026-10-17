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
// prioprity queue and operation 