#include <iostream>
#include <queue>

#define MAX_SIZE 304

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int N, M;
int jx, jy, bx, by;
char school[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}


void Init() {
    cin >> N >> M;
    cin >> jy >> jx >> by >> bx;
    jy -= 1;
    jx -= 1;
    by -= 1;
    bx -= 1;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> school[y][x];
        }
    }
}

void display() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << school[i][j];
        }
        cout << '\n';
    }
    cout << "\n";
}

int solve() {
    queue<pair<int, int>> q;
    queue<pair<int, int>> oneq;
    int level = 0;
    q.push({jy, jx});
    visited[jy][jx] = 1;
    while (school[by][bx] != '0') {
        level++;
        display();
        while (q.size()) {
            //display();
            int cy = q.front().first;
            int cx = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int ny = dy[i] + cy;
                int nx = dx[i] + cx;

                if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx])
                    continue;
                visited[ny][nx] = level;
                if (school[ny][nx] == '1' || school[ny][nx] == '#') {
                    school[ny][nx] = '0';
                    oneq.push({ny, nx});
                } else {
                    q.push({ny, nx});
                }
            }
        }
        q = oneq;
    }
    return visited[by][bx];
}

int main(void) {
    FastIO();
    Init();
    cout << solve();
    return 0;
}