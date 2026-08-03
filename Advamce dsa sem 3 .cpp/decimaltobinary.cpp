#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cout << "Enter a decimal number: ";
    cin >> n;

    if (n == 0) {
        cout << "Binary = 0";
        return 0;
    }

    stack<int> s;

    while (n > 0) {
        s.push(n % 2);
        n = n / 2;
    }

    cout << "Binary = ";
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }

    return 0;
}