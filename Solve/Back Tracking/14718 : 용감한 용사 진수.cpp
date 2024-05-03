#include <iostream>
#include <vector>

using namespace std;
int N, K, ret = 987654321;
int ability[100][3];
int visited[3];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        ability[i][0] = a;
        ability[i][1] = b;
        ability[i][2] = c;
    }
}

int go(vector<int> temp) {
    int cnt = 0;
    int _str = temp[0];
    int _dex = temp[1];
    int _int = temp[2];

    for (int i = 0; i < N; i++) {
        if (_str >= ability[i][0] && _dex >= ability[i][1] && _int >= ability[i][2])
            cnt++;
    }
    if (cnt >= K)
        return (_str + _dex + _int);
    return 987654321;
}

void dfs(int depth, vector<int> temp) {
    if (depth == 3) {
        ret = min(ret, go(temp));
        return;
    }

    for (int i = 0; i < N; i++) {
        temp.push_back(ability[i][depth]);
        dfs(depth + 1, temp);
        temp.pop_back();
    }
}

void solve() {
    vector<int> temp;
    dfs(0, temp);
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}