#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct board {
    int original;
    int water;
    vector<int> live;
    vector<int> dead;
} BOARD;

int N, M, K, ret;
BOARD B[10][10];
const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int visited[10][10];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int a, b, c;
    cin >> N >> M >> K;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> B[y][x].original;
            B[y][x].water = 5;
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        B[a - 1][b - 1].live.push_back(c);
    }
}

void displayTree() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (B[y][x].live.size()) {
                cout << y << " : " << x << '\n';
                for (int k = 0; k < B[y][x].live.size(); k++) {
                    cout << B[y][x].live[k] << " ";
                }
                cout << "\n";
            }
        }
    }
}

void spring() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (B[y][x].live.size()) {
                sort(B[y][x].live.begin(), B[y][x].live.end());
            }
        }
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (B[y][x].live.size()) {
                for (int i = 0; i < B[y][x].live.size(); i++) {
                    if (B[y][x].water >= B[y][x].live[i]) {
                        B[y][x].water -= B[y][x].live[i];
                        B[y][x].live[i]++;
                    } else {
                        int size = B[y][x].live.size();
                        for (int k = size - 1; k >= i; k--) {
                            B[y][x].dead.push_back(B[y][x].live[k]);
                            B[y][x].live.pop_back();
                        }
                        break;
                    }
                }
            }
        }
    }
}

void summer() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (B[y][x].dead.size()) {
                int sum = 0;
                for (int i = 0; i < B[y][x].dead.size(); i++) {
                    sum += (B[y][x].dead[i] / 2);
                }
                B[y][x].water += sum;
                B[y][x].dead.clear();
            }
        }
    }
}

void autumn() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (B[y][x].live.size()) {
                for (int i = 0; i < B[y][x].live.size(); i++) {
                    if (B[y][x].live[i] % 5 == 0) {
                        for (int dir = 0; dir < 8; dir++) {
                            int ny = y + dy[dir];
                            int nx = x + dx[dir];
                            if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                                continue;
                            B[ny][nx].live.push_back(1);
                        }
                    }
                }
            }
        }
    }
}

void winter() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            B[y][x].water += B[y][x].original;
        }
    }
}

void findTree() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            ret += B[y][x].live.size();
        }
    }
}

void solve() {
    while (K--) {
        spring();
        summer();
        autumn();
        winter();
    }
    findTree();
    cout << ret << "\n";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
