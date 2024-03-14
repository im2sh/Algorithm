#include <iostream>
#include <deque>
#include <vector>

using namespace std;

deque<int> wheel[4];
int K, ret;
vector<pair<int, int>> seq;
pair<bool, int> selected[4];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    string temp;
    for (int i = 0; i < 4; i++) {
        cin >> temp;
        for (int j = 0; j < 8; j++) {
            wheel[i].push_back(temp[j] - '0');
        }
    }

    int a, b;
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> a >> b;
        seq.push_back({a - 1, b});
    }

}

void rotate(int idx, int dir) {
    if (dir == 1) {
        int temp = wheel[idx].back();
        wheel[idx].pop_back();
        wheel[idx].push_front(temp);
    } else {
        int temp = wheel[idx].front();
        wheel[idx].pop_front();
        wheel[idx].push_back(temp);
    }
}

int changeDir(int dir) {
    if (dir == 1)
        return -1;
    return 1;
}

void select_rotate_wheel(int idx, int dir) {
    int basic = wheel[idx][6];
    int cd = dir;
    bool flag = false;
    for (int i = idx - 1; i >= 0; i--) {
        if (flag)
            break;
        if (wheel[i][2] != basic) {
            selected[i].first = true;
            cd = changeDir(cd);
            selected[i].second = cd;
        } else {
            flag = true;
        }
        basic = wheel[i][6];
    }

    basic = wheel[idx][2];
    cd = dir;
    flag = false;
    for (int i = idx + 1; i < 4; i++) {
        if (flag)
            break;
        if (wheel[i][6] != basic) {
            selected[i].first = true;
            cd = changeDir(cd);
            selected[i].second = cd;
        } else {
            flag = true;
        }
        basic = wheel[i][2];
    }
    selected[idx].first = true;
    selected[idx].second = dir;
}

void display() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            cout << wheel[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void solve() {
    for (int i = 0; i < K; i++) {
        fill(&selected[0], &selected[0] + 4, make_pair(false, 0));
        int idx = seq[i].first;
        int dir = seq[i].second;

        select_rotate_wheel(idx, dir);

        for (int j = 0; j < 4; j++) {
            if (selected[j].first)
                rotate(j, selected[j].second);
        }
    }
    int temp = 1;
    for (int i = 0; i < 4; i++) {
        if (wheel[i][0] == 1) {
            ret += temp;
        }
        temp *= 2;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}