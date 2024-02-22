#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C, cnt;
char alpha[16];
int visited[16];
char need[5] = {'a', 'e', 'i', 'o', 'u'};
int need_visited[5] = {0,};
vector<string> ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> L >> C;
    for (int i = 0; i < C; i++) {
        cin >> alpha[i];
    }
    sort(alpha, alpha + C);
}

void check() {
    string temp = "";
    int needCnt = 0;
    fill(&need_visited[0], &need_visited[0] + 5, 0);

    for (int i = 0; i < C; i++) {
        if (visited[i]) {
            temp += alpha[i];
        }
    }

    for (int i = 0; i < temp.size(); i++) {
        char tempAlpha = temp[i];
        for (int j = 0; j < 5; j++) {
            if (!need_visited[j] && need[j] == tempAlpha) {
                need_visited[j] = 1;
                needCnt++;
                break;
            }
        }
    }
    
    if (L - needCnt >= 2 && needCnt >= 1) {
        ret.push_back(temp);
    }
}

void dfs(int idx, int depth) {
    if (depth == L) {
        check();
        cnt++;
        return;
    }

    for (int i = idx; i < C; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            dfs(i, depth + 1);
            visited[i] = 0;
        }
    }
}

void solve() {
    dfs(0, 0);
    sort(ret.begin(), ret.end());

    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}