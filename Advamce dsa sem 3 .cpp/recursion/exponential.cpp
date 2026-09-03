#include <iostream>
using namespace std;

int pow1(int a, int n) {

    if (n == 0) {
        return 1;
    }

    int x = pow1(a, n / 2);

    if (n % 2 == 0) {
        return x * x;
    }
    else {
        return a * x * x;
    }
}

int main() {

    int p1 = pow1(2, 10);
    int p2 = pow1(2, 5);

    cout << p1 << endl;
    cout << p2 << endl;

    return 0;
}