#include <iostream>
#include <vector>

using namespace std;
int N, M, ret;
pair<bool, int> BOARD[51][51];
pair<int, int> command[101];
vector<pair<int, int>> wind;
vector<pair<int, int>> pour;

const int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int d, s;
    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            BOARD[y][x].first = false;
            cin >> BOARD[y][x].second;
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> d >> s;
        command[i].first = d - 1;
        command[i].second = s;
    }
}

void getWind() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (BOARD[y][x].first) {
                wind.push_back({y, x});
            }
        }
    }
}

void goWind(int d, int s) {
    int cy, cx, ny, nx;
    (N - 1) - d * s;
    for (int i = 0; i < wind.size(); i++) {
        cy = wind[i].first;
        cx = wind[i].second;

        ny = (cy + N + (dy[d] * (s % N))) % N;
        nx = (cx + N + (dx[d] * (s % N))) % N;
        
        BOARD[cy][cx].first = false;
        BOARD[ny][nx].second++;
        pour.push_back({ny, nx});
    }
}

void copyWind() {
    int cy, cx, ny, nx;
    for (int i = 0; i < pour.size(); i++) {
        int cnt = 0;
        cy = pour[i].first;
        cx = pour[i].second;
        for (int dir = 1; dir < 8; dir += 2) {
            ny = cy + dy[dir];
            nx = cx + dx[dir];
            if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                continue;
            if (BOARD[ny][nx].second > 0)
                cnt++;
        }
        BOARD[cy][cx].second += cnt;
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (BOARD[y][x].first)
                BOARD[y][x].first = false;
            else if (!BOARD[y][x].first && BOARD[y][x].second >= 2) {
                BOARD[y][x].first = true;
                BOARD[y][x].second -= 2;
            }
        }
    }
}

void calWater() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            ret += BOARD[y][x].second;
        }
    }
}

void display() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cout << BOARD[y][x].first << " ";
        }
        cout << '\n';
    }
}

void solve() {
    BOARD[N - 2][0].first = true;
    BOARD[N - 2][1].first = true;
    BOARD[N - 1][0].first = true;
    BOARD[N - 1][1].first = true;

    for (int i = 0; i < M; i++) {
        wind.clear();
        pour.clear();
        getWind();
        goWind(command[i].first, command[i].second);
        for (int j = 0; j < pour.size(); j++) {
            BOARD[pour[j].first][pour[j].second].first = true;
        }
        copyWind();
    }
    calWater();
}

int main(void) {
    FastIO();
    Init();
    solve();
    cout << ret;
    return 0;
}