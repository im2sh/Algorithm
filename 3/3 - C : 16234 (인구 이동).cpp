#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
#define SIZE 104

int N, L, R;
const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, -1, 0, 1};
int country[SIZE][SIZE];
int visited[SIZE][SIZE];
vector<pair<int, int>> people;
bool flag;

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = dy[i] + y;
        int nx = dx[i] + x;
        int move = abs(country[ny][nx] - country[y][x]);
        if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx])
            continue;
        else if (move < L || move > R)
            continue;

        people.push_back({ny, nx});
        dfs(ny, nx);
    }
}

void movepeople() {
    int temp = 0;
    int result = 0;
    for (auto it: people) {
        temp += country[it.first][it.second];
    }
    result = temp / people.size();

    for (auto it: people) {
        country[it.first][it.second] = result;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> L >> R;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> country[i][j];
        }
    }

    int cnt = 0;
    while (true) {
        flag = 0;
        fill(&visited[0][0], &visited[0][0] + SIZE * SIZE, 0);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j]) {
                    people.clear();
                    people.push_back({i, j});
                    dfs(i, j);
                    if (people.size() == 1)
                        continue;
                    movepeople();
                    flag = true;
                }
            }
        }
        if (!flag)
            break;
        cnt++;
    }

    cout << cnt << "\n";
    return 0;
}