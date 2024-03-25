#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int N, M, sum, ret;
int BOARD[21][21];
int visited[21][21];
int friends_visited[3];
vector<pair<int, int>> friends;
vector<pair<int, int>> real_path;
vector<pair<pair<int, int>, int>> repair;
vector<int> tf;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int a, b;
    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> BOARD[y][x];
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        friends.push_back({a - 1, b - 1});
    }
}

void dfs(int y, int x, int depth, int temp, vector<pair<int, int>> temp_path) {
    if (depth == 3) {
        if (sum < temp) {
            sum = temp;
            real_path.clear();
            for (int i = 0; i < temp_path.size(); i++) {
                real_path.push_back(temp_path[i]);
            }
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= N || nx < 0 || nx >= N)
            continue;
        if (!visited[ny][nx]) {
            visited[ny][nx] = 1;
            temp_path.push_back({ny, nx});
            dfs(ny, nx, depth + 1, temp + BOARD[ny][nx], temp_path);
            temp_path.pop_back();
            visited[ny][nx] = 0;
        }
    }
}

void display() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cout << BOARD[y][x] << ' ';
        }
        cout << '\n';
    }
}

void go() {
    int tr = 0;
    for (int i = 0; i < tf.size(); i++) {
        vector<pair<int, int>> temp_path;
        sum = 0;
        int y = friends[tf[i]].first;
        int x = friends[tf[i]].second;

        temp_path.push_back({y, x});
        visited[y][x] = 1;
        dfs(y, x, 0, BOARD[y][x], temp_path);
        visited[y][x] = 0;
        for (int i = 0; i < real_path.size(); i++) {
            int ry = real_path[i].first;
            int rx = real_path[i].second;
            if (BOARD[ry][rx] == 0)
                continue;
            repair.push_back({{ry, rx}, BOARD[ry][rx]});
            BOARD[ry][rx] = 0;
        }
        tr += sum;
    }
    for (int i = 0; i < repair.size(); i++) {
        BOARD[repair[i].first.first][repair[i].first.second] = repair[i].second;
    }
    repair.clear();
    ret = max(ret, tr);
}

void solve(int depth) {
    if (depth == M) {
        go();
    }
    for (int i = 0; i < M; i++) {
        if (!friends_visited[i]) {
            friends_visited[i] = 1;
            tf.push_back(i);
            solve(depth + 1);
            tf.pop_back();
            friends_visited[i] = 0;
        }
    }
}


int main(int argc, char **argv) {
    FastIO();
    Init();
    solve(0);
    cout << ret;
    return 0;
}