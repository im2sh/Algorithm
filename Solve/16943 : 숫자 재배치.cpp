#include <iostream>
#include <algorithm>

using namespace std;

string A;
int B;
int ret = -1;

int visited[10];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> A >> B;
}

void go(int depth, string temp) {
    if (depth == A.length()) {
        if (temp[0] == '0')
            return;
        int target = stoi(temp);
        if (target < B) {
            ret = max(ret, target);
        }
    }

    for (int i = 0; i < A.size(); i++) {
        if (!visited[i]) {
            visited[i] = 1;
            go(depth + 1, temp + A[i]);
            visited[i] = 0;
        }
    }
}

void solve() {
    string temp = "";
    go(0, temp);
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}