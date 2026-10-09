#include<iostream>
#include<vector>
using namespace std;
vector<int>c;
void merge(vector<int>&a,int low,int mid,int high){
    int i=low,j=mid+1,k=low;
    while(i<=mid && j<=high){
        if(a[i]<a[j]){
            c[k]=a[i];
            i++;
            k++;
        }
        else{
            c[k]=a[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
        c[k]=a[i];
        i++;
        k++;
    }
    while(j<=high){
        c[k]=a[j];
        j++;
        k++;
    }
    for(int i=low;i<=high;i++){
        a[i]=c[i];
    }
}
void mergesort(vector<int>&a,int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
        
    }
}
int main(){
    int n;
    cin>>n;
    c.resize(n);
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mergesort(a,0,n-1);
    cout<<"Sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}