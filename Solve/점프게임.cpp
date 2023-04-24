#include <iostream>
#include <queue>

using namespace std;

int C, N;
int arr[104][104];
int visited[104][104];

int dir[2][2] = {{0, 1},
                 {1, 0}};

void init_visited() {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = 0;
        }
    }
}

void print_path(pair<int, int> Q[104][104], int x, int y) {

    if (Q[x][y].first != 0) {
        if (Q[x][y].first == 2) {
            print_path(Q, x - Q[x][y].second, y);
            cout << arr[x][y] << " ";
        } else {
            print_path(Q, x, y - Q[x][y].second);
            cout << arr[x][y] << " ";
        }
    }
    return;
}

int BFS_iter(int x, int y) {


    pair<int, int> Q[104][104];

    visited[x][y] = 1;
    int dx, dy;
    queue<pair<int, int>> q;
    q.push({x, y});

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;


        if (x == N - 1 and y == N - 1) {

            cout << "\n";
            cout << arr[0][0] << " ";
            print_path(Q, N - 1, N - 1);
            return 1;
        }
        q.pop();

        for (int i = 0; i < 2; i++) {
            dx = x + (dir[i][0] * arr[x][y]);
            dy = y + (dir[i][1] * arr[x][y]);

            if (dx < 0 or dx >= N or dy < 0 or dy >= N) {
                continue;
            }

            if (visited[dx][dy] == 0) {
                q.push({dx, dy});
                if (i == 0) {
                    Q[dx][dy].first = 1;
                    Q[dx][dy].second = arr[x][y];
                } else {
                    Q[dx][dy].first = 2;
                    Q[dx][dy].second = arr[x][y];
                }
                visited[dx][dy] = 1;
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    init_visited();

    for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
            cin >> arr[j][k];
        }
    }

    if (BFS_iter(0, 0)) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }


    return 0;

}