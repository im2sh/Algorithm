#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int T, K, ret;
vector<pair<int, int>> seq;
vector<pair<int, int>> visited;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void rotate(deque<int> &g, int num) {
    int temp;
    switch (num) {
        case 1:
            temp = g.back();
            g.pop_back();
            g.push_front(temp);
            break;
        case -1:
            temp = g.front();
            g.pop_front();
            g.push_back(temp);
            break;
    }
}

int rot(int n) {
    if (n == -1)
        return 1;
    return -1;
}

void solve() {
    string temp;
    int x, y;
    cin >> T;
    deque<deque<int>> gear(T);
    for (int i = 0; i < T; i++) {
        cin >> temp;
        for (int j = 0; j < temp.length(); j++) {
            gear[i].push_back(temp[j] - '0');
        }
    }

    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> x >> y;
        seq.push_back({x - 1, y});
    }
    for (int i = 0; i < seq.size(); i++) {
        int cnt = 0;
        visited.clear();
        int stan = seq[i].first;
        int dir = seq[i].second;
        int temp_dir = rot(dir);
        for (int j = stan - 1; j >= 0; j--) {
            deque<int> temp_g = gear[j + 1];
            if (temp_g[6] == gear[j][2]) {
                break;
            }
            visited.push_back({j, temp_dir});
            temp_dir = rot(temp_dir);
            cnt++;
        }
        for (int a = 0; a < cnt; a++) {
            rotate(gear[visited[a].first], visited[a].second);
        }
        cnt = 0;
        visited.clear();
        temp_dir = rot(dir);
        for (int j = stan + 1; j < T; j++) {
            deque<int> temp_g = gear[j - 1];
            if (temp_g[2] == gear[j][6]) {
                break;
            }
            visited.push_back({j, temp_dir});
            temp_dir = rot(temp_dir);
            cnt++;
        }
        for (int a = 0; a < cnt; a++) {
            rotate(gear[visited[a].first], visited[a].second);
        }
        rotate(gear[stan], dir);
    }

    for (int i = 0; i < T; i++) {
        ret += gear[i][0];
    }
}

int main(void) {
    FastIO();
    solve();
    cout << ret << "\n";
    return 0;
}
