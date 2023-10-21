#include <iostream>
#include <vector>

using namespace std;

int N, ret;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
vector<pair<int, int>> student, teacher;
char BOARD[6][6];

void FastIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void Init() {
    cin >> N;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> BOARD[y][x];
            if (BOARD[y][x] == 'X')
                student.push_back({y, x});
            else if (BOARD[y][x] == 'T')
                teacher.push_back({y, x});
        }
    }
}

int check() {
    for (pair<int, int> t: teacher) {
        for (int dir = 0; dir < 4; dir++) {
            int ny = t.first;
            int nx = t.second;
            while (true) {
                ny += dy[dir];
                nx += dx[dir];
                if (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1 || BOARD[ny][nx] == 'O')
                    break;
                if (BOARD[ny][nx] == 'S')
                    return 0;
            }
        }
    }
    return 1;
}

void dfs(int idx, int depth) {
    if (depth == 3) {
        ret += check();
        return;
    }
    for (int i = idx + 1; i < student.size(); i++) {
        int y = student[i].first;
        int x = student[i].second;
        BOARD[y][x] = 'O';
        dfs(i, depth + 1);
        BOARD[y][x] = 'X';
    }
}

void solve() {
    dfs(-1, 0);
    if (ret == 0)
        cout << "NO\n";
    else
        cout << "YES\n";
}

int main() {
    FastIO();
    Init();
    solve();
    return 0;
}