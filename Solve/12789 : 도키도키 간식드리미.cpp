#include <iostream>
#include <stack>

using namespace std;
int N, cnt;
int target = 1;
int arr[1001];
stack<int> st;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        arr[i] = temp;
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        if (st.empty() && cnt < N) {
            st.push(arr[cnt++]);
        }
        while (st.top() != target && cnt < N) {
            st.push(arr[cnt++]);
        }
        if (!st.empty() && st.top() == target) {
            st.pop();
            target++;
        } else {
            cout << "Sad\n";
            return;
        }
    }
    cout << "Nice\n";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}