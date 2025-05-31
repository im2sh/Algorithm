#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
pair<int, int> line;
queue<int> q;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        if (temp == 1) {
            int num;
            cin >> num;

            q.push(num);
            if (line.first == q.size()) {
                if (line.second > num) {
                    line.second = num;
                }
            } else if (line.first < q.size()) {
                line = {(int) q.size(), num};
            }
        } else {
            q.pop();
        }
    }

    cout << line.first << ' ' << line.second;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}