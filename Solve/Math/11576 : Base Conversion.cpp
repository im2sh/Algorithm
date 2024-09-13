#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

int A, B, M, decimal, divide;
stack<int> ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> A >> B;
    cin >> M;
    while (M--) {
        int temp;
        cin >> temp;
        decimal += temp * pow(A, M);
    }
}

void solve() {
    divide = decimal;
    while (divide) {
        ret.push(divide % B);
        divide /= B;
    }

    while (!ret.empty()) {
        cout << ret.top() << " ";
        ret.pop();
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}