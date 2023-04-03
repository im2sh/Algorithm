#include <iostream>
#include <queue>
#include <algorithm>

#define SIZE 1004

using namespace std;

const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, -1, 0, 1};

int R, C;
char map[SIZE][SIZE];
int people[SIZE][SIZE];
int fire[SIZE][SIZE];
queue<pair<int, int>> firemap;


int people_bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    people[y][x] = 1;

    while (q.size()) {
        tie(y, x) = q.front();
        q.pop();
        if (y == 0 || y == R - 1 || x == 0 || x == C - 1) {
            return people[y][x];
        }
        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;

            if (ny < 0 || ny >= R || nx < 0 || nx >= C || people[ny][nx] || map[ny][nx] == '#' || map[ny][nx] == 'F')
                continue;
            people[ny][nx] = people[y][x] + 1;
            if (people[ny][nx] >= fire[ny][nx] && fire[ny][nx] != 0) {
                people[ny][nx] = 0;
                continue;
            }
            q.push({ny, nx});
        }
    }
    return -1;
}

void fire_bfs() {
    int x, y;
    while (firemap.size()) {
        tie(y, x) = firemap.front();
        firemap.pop();

        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;

            if (ny < 0 || ny >= R || nx < 0 || ny >= C || fire[ny][nx] || map[ny][nx] == '#' || map[ny][nx] == 'J')
                continue;
            fire[ny][nx] = fire[y][x] + 1;
            firemap.push({ny, nx});
        }
    }
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    pair<int, int> jihun;
    cin >> R >> C;

    fill(&fire[0][0], &fire[0][0] + SIZE * SIZE, 0);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'F') {
                firemap.push({i, j});
                fire[i][j] = 1;
            } else if (map[i][j] == 'J') {
                jihun = make_pair(i, j);
            }

        }
    }
    fire_bfs();
    fill(&people[0][0], &people[0][0] + SIZE * SIZE, 0);
    int ret = people_bfs(jihun.first, jihun.second);
    if (ret == -1)
        cout << "IMPOSSIBLE" << "\n";
    else
        cout << ret << "\n";
    return 0;
}