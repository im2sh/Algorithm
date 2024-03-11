#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int TC, N, ret = 987654321;
vector<string> people;
vector<string> tp;
bool visited[33];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void go(int idx, int depth) {
    if (depth == 3) {
        int diff = 0;
        int start = 0;
        int end = 2;
        for (int j = 0; j < 4; j++) {
            if (tp[start][j] != tp[end - 1][j])
                diff++;
            if (tp[start + 1][j] != tp[end][j])
                diff++;
            if (tp[start][j] != tp[end][j])
                diff++;
        }
        ret = min(ret, diff);
        return;
    }

    for (int i = idx; i < people.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            tp.push_back(people[i]);
            go(i + 1, depth + 1);
            tp.pop_back();
            visited[i] = false;
        }
    }
}

void solve() {
    string temp;
    while (TC--) {
        ret = 987654321;
        people.clear();
        tp.clear();
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> temp;
            people.push_back(temp);
        }

        if (N > 32) {
            cout << "0\n";
            continue;
        }

        go(0, 0);

        cout << ret << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}