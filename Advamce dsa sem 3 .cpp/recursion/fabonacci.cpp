#include<iostream>
#include<vector>
using namespace std;
vector<int>dat(101,0);

long long fib(long long n){
    if(n==1){
    return 0;
    }
    if(n==2){
    return 1;
    }
    if(dat[n]==0){
    dat[n]= fib(n-1)+fib(n-2);
    }
    return dat[n];
}
int main(){
    for(long long i=1;i<=5000;i++)
    cout<<i<<":"<<fib(i)<<endl;
}