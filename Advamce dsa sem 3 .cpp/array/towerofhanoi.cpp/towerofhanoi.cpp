#include<iostream>
#include<vector>
using namespace std;
int i=1;
void toh(int n,char S,char M,char D){
    if(n==1){
        cout<<i++<<":"<<S<<"-->"<<D<<endl;
        return;
    }
    toh(n-1,S,D,M);
    cout<<i++<<":"<<S<<"-->"<<D<<endl;
    toh(n-1,M,S,D);
}
int main() {
    int n;
    cin >> n;

    toh(n, 'S', 'M', 'D');

    return 0;
}// tower of hanoi