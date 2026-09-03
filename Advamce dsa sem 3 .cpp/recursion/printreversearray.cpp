#include<iostream>
#include<vector>
using namespace std;
void printarray(vector<int>arr,int i){
    if(i==arr.size())
        return;
   
    printarray(arr,i+1);
     cout<<arr[i]<<endl;
}
int main(){
    vector<int>arr={1,2,3,4,5};
    printarray(arr,0);
}