#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct Pos {
    int z, y, x;
};

const int dz[6] = {-1, 1, 0, 0, 0, 0};
const int dy[6] = {0, 0, -1, 1, 0, 0};
const int dx[6] = {0, 0, 0, 0, -1, 1};
int L, R, C;
bool flag = false;
char BOARD[31][31][31];
int visited[31][31][31];
Pos startPos, endPos;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    fill(&visited[0][0][0], &visited[0][0][0] + 31 * 31 * 31, 0);
    fill(&BOARD[0][0][0], &BOARD[0][0][0] + 31 * 31 * 31, 0);

    cin >> L >> R >> C;
    if (L == 0 && R == 0 && C == 0) {
        flag = true;
        return;
    }

    for (int z = 0; z < L; z++) {
        for (int y = 0; y < R; y++) {
            string temp;
            cin >> temp;
            for (int x = 0; x < C; x++) {
                BOARD[z][y][x] = temp[x];
                if (BOARD[z][y][x] == 'S')
                    startPos = {z, y, x};
                else if (BOARD[z][y][x] == 'E')
                    endPos = {z, y, x};
            }
        }
    }
}

void display() {
    for (int z = 0; z < L; z++) {
        for (int y = 0; y < R; y++) {
            for (int x = 0; x < C; x++) {
                cout << BOARD[z][y][x] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    cout << '\n';
}

void solve() {
    queue<Pos> q;
    q.push(startPos);
    visited[startPos.z][startPos.y][startPos.x] = 1;

    while (q.size()) {
        Pos cur = q.front();
        q.pop();
        if (cur.z == endPos.z && cur.y == endPos.y && cur.x == endPos.x) {
            cout << "Escaped in " << visited[cur.z][cur.y][cur.x] - 1 << " minute(s).\n";
            return;
        }

        for (int dir = 0; dir < 6; dir++) {
            int nz = cur.z + dz[dir];
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];

            if (nz < 0 || nz >= L || ny < 0 || ny >= R || nx < 0 || nx >= C || visited[nz][ny][nx] ||
                BOARD[nz][ny][nx] == '#')
                continue;
            q.push({nz, ny, nx});
            visited[nz][ny][nx] = visited[cur.z][cur.y][cur.x] + 1;
        }
    }
    cout << "Trapped!\n";

}

int main(void) {
    FastIO();
    while (true) {
        Init();
        if (flag)
            return 0;
        solve();
    }
}