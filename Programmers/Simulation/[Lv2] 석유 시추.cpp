#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int N, M, ret;
int BOARD[501][501];
int visited[501][501];
int idx = 1;
map<int, int> land_cnt;
set<int> s;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = idx;
    int cnt = 1;
    while (q.size()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx] || BOARD[ny][nx] == 0)
                continue;
            visited[ny][nx] = idx;
            q.push({ny, nx});
            cnt++;
        }
    }
    land_cnt[idx] = cnt;
}

void init(vector<vector<int>> land) {
    N = land.size();
    M = land[0].size();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            BOARD[i][j] = land[i][j];
        }
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (!visited[y][x] && BOARD[y][x]) {
                bfs(y, x);
                idx++;
            }
        }
    }
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    init(land);

    for (int i = 0; i < M; i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) {
            if (visited[j][i] != 0) {
                s.insert(visited[j][i]);
            }
        }
        for (auto &it: s) {
            sum += land_cnt[it];
        }
        ret = max(ret, sum);
        s.clear();
    }
    answer = ret;
    return answer;
}