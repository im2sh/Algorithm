#include <iostream>
#include <cmath>

using namespace std;

int N, ret, cnt;
int col[15];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

bool check(int depth) {
    for (int i = 0; i < depth; i++) {
        if (col[i] == col[depth] || abs(col[depth] - col[i]) == depth - i)
            return false;
    }
    return true;
}

void solve(int x) {
    if (x == N) {
        ret++;
        return;
    }
    for (int i = 0; i < N; i++) {
        col[x] = i;
        if (check(x)) {
            solve(x + 1);
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve(0);
    cout << ret;
    return 0;
}