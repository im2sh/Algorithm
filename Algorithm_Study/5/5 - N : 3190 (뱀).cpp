#include <iostream>
#include <map>
#include <queue>

using namespace std;

int N, K, L, ret;
int M[101][101];
vector<pair<int, char>> command;
bool die;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
int visited[101][101];
queue<pair<int, int>> snake;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int a, b;
    int cx;
    char c;
    cin >> N;
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> a >> b;
        M[a][b] = 2;
    }
    cin >> L;
    for (int i = 0; i < L; i++) {
        cin >> cx >> c;
        command.push_back(make_pair(cx, c));
    }
}

pair<int, int> move(int y, int x, int dir) {
    int a, b;
    pair<int, int> temp;
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    visited[y][x] = 1;
    temp = make_pair(ny, nx);
    if (M[ny][nx] != 2) {
        tie(a, b) = snake.front();
        snake.pop();
        visited[a][b] = 0;
    }
    if (ny <= 0 || ny > N || nx <= 0 || nx > N || visited[ny][nx]) {
        die = true;
        return temp;
    }

    snake.push({y, x});
    M[ny][nx] = 1;
    return temp;
}


void solve() {
    int dir = 0;
    int cnt = 0;
    snake.push({1, 1});
    int y = 1;
    int x = 1;
    visited[1][1] = 1;
    while (1) {
        if (ret == command[cnt].first) {
            if (command[cnt].second == 'D')
                dir = (dir + 1) % 4;
            else
                dir = (dir + 3) % 4;
            cnt++;
        }
        tie(y, x) = move(y, x, dir);
        ret++;
        cout << '\n';
        if (die)
            break;
    }
    cout << ret << "\n";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}