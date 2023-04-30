//
// Created by 이석환 on 2023/04/30.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_SIZE 26
using namespace std;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int N;
int house[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
vector<int> apartment;
int cnt;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    string temp1;
    string temp2;
    int tempN;

    for (int y = 0; y < N; y++) {
        cin >> temp1;
        for (int x = 0; x < N; x++) {
            tempN = temp1[x] - '0';
            house[y][x] = tempN;
            if (!house[y][x])
                visited[y][x] = 1;
        }
    }
}

void bfs(int y, int x) {
    int apart_cnt = 1;
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});
    while (q.size()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + cy;
            int nx = dx[i] + cx;

            if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx] || !house[ny][nx])
                continue;
            visited[ny][nx] = 1;
            apart_cnt++;
            q.push({ny, nx});
        }
    }
    apartment.push_back(apart_cnt);
}

void solve() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (!house[y][x] || visited[y][x])
                continue;
            bfs(y, x);
            cnt++;
        }
    }

    sort(apartment.begin(), apartment.end());
    cout << cnt << "\n";
    for (auto &it: apartment) {
        cout << it << "\n";
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}