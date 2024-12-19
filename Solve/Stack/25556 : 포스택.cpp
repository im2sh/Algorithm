#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N;
vector<int> arr;
stack<int> A;
stack<int> B;
stack<int> C;
stack<int> D;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        int target = arr[i];

        if (A.empty()) {
            A.push(target);
        } else if (!A.empty() && A.top() < target) {
            A.push(target);
        } else if (B.empty()) {
            B.push(target);
        } else if (!B.empty() && B.top() < target) {
            B.push(target);
        } else if (C.empty()) {
            C.push(target);
        } else if (!C.empty() && C.top() < target) {
            C.push(target);
        } else if (D.empty()) {
            D.push(target);
        } else if (!D.empty() && D.top() < target) {
            D.push(target);
        } else {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}