#include<iostream>
#include<vector>
using namespace std;    

void merge(vector<int>&a, vector<int>&b, int m, int n){
    int i = 0, j = 0;
    vector<int> c;
    while(i < m && j < n){
        if(a[i] < b[j]){
            c.push_back(a[i]);
            i++;
        }
        else if (a[i] == b[j]){
            c.push_back(a[i]);
            i++;
            j++;
        }
        else {
            c.push_back(b[j]);
            j++;
        }
    }
    while(i < m){
        c.push_back(a[i]);
        i++;
    }   
    while(j < n){
        c.push_back(b[j]);
        j++;
    }
    for(int k = 0; k < c.size(); k++){
        cout << c[k] << " ";
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> a;
    a.push_back(5);
    a.push_back(10);
    a.push_back(15);    
    a.push_back(20);
    a.push_back(25);
    vector<int> b;
    b.push_back(3); 
    b.push_back(6);
    b.push_back(9);
    b.push_back(12);
    b.push_back(15);
    
    merge(a, b, a.size(), b.size());
    return 0;
}