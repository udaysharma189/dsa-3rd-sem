#include<iostream>
using namespace std;
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } 
    if (a == 0) {
        return b;
    }
    if(a > b) {
        return gcd(a % b, b);
    } else {
        return gcd(a, b % a);
    }
} 
int main() {
    int result = gcd(0,2);
    cout  << result << endl;
    return 0;
}