#include<iostream>
#include<vector>
using namespace std;
vector<int>arr;
int sum(int arr[],int n){
    if(n==-1){
        return 0;

    }
    return arr[n-1]+sum(arr,n-1);
}
int main(){
    arr = {1,2,3,4,5,6,7,8,9,10};
    int result=sum(arr,10);
    cout<<result<<endl;
    return 0;
}
