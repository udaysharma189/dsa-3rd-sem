#include<iostream>
#include<vector>
using namespace std;
void printarray(vector<int>arr,int i){
    if(i==arr.size())
        return;
    cout<<arr[i]<<endl;
    printarray(arr,i+1);
}
int main(){
    vector<int>arr={1,2,3,4,5};
    printarray(arr,0);
}