#include <iostream>
#include <vector>

#define MAX_WEIGHT 500
using namespace std;

int N, K, ret;
int weight = 500;
bool visited[8];
vector<int> kit;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        kit.push_back(temp);
    }
}

void go(int depth) {
    if (depth == N)
        ret++;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            if (weight + kit[i] - K >= 500) {
                weight += kit[i] - K;
                go(depth + 1);
                weight -= kit[i] - K;
            }
            visited[i] = false;
        }
    }
}

void solve() {
    go(0);
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
