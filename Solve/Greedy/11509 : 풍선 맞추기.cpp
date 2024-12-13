#include <iostream>
#include <vector>

using namespace std;

int N, ret;
int visited[1000004];
vector<int> ballon;

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
        ballon.push_back(temp);
    }
}


void solve() {
    for (int i = 0; i < N; i++) {
        if (visited[ballon[i] + 1] > 0) {
            visited[ballon[i] + 1]--;
            visited[ballon[i]]++;
        } else {
            visited[ballon[i]]++;
            ret++;
        }
    }

    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}