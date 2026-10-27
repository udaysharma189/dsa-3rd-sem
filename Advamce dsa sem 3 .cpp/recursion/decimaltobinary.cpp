#include <iostream>
using namespace std;

void decimalToBinary(int n) {
    if (n == 0) {
        return;
    }

    decimalToBinary(n / 2);

    cout << n % 2;
}

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0;
    } else {
        decimalToBinary(n);
    }

    return 0;
}// decimal to binary code revesion