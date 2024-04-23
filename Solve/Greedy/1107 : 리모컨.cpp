#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int N, M, ret = 987654321;
bool visited[10];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int temp;
        cin >> temp;
        visited[temp] = true;
    }
}

int check(int x) {
    int len = 0;
    if (x == 0 && !visited[0])
        return 1;
    int n = x;
    while (n > 0) {
        int r = n % 10;
        if (visited[r])
            return 0;
        len++;
        n /= 10;
    }
    return len;
}

void solve() {
    if (N == 100) {
        cout << "0";
        return;
    }

    int click = abs(N - 100);

    for (int i = 0; i < 1000000; i++) {
        int target = i;

        int len = check(target);
        if (len == 0)
            continue;
        ret = min(ret, (len + abs(target - N)));
    }
    ret = min(ret, click);
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}