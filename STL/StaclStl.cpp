#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> S;

    S.push(10);
    S.push(20);
    S.push(30);

    while (!S.empty()) {
        cout << S.top() << " " << endl;
        S.pop();
    }

    return 0;
}