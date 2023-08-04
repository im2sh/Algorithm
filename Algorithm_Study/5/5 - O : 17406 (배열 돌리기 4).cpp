#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef struct point {
    int r;
    int c;
    int s;
} Point;
int N, M, K;
int arr[52][52];
int copy_arr[52][52];
vector<Point> seq;
int op[6];
int visited[6];
int ret = 987654321;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int a, b, c;
    cin >> N >> M >> K;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> arr[y][x];
        }
    }

    for (int i = 0; i < K; i++) {
        cin >> a >> b >> c;
        seq.push_back({a - 1, b - 1, c});
    }
}

void rotate(int r, int c, int s) {
    while (s > 0) {
        int temp = copy_arr[r - s][c - s];
        for (int i = r - s; i < r + s; i++)
            copy_arr[i][c - s] = copy_arr[i + 1][c - s];
        for (int i = c - s; i < c + s; i++)
            copy_arr[r + s][i] = copy_arr[r + s][i + 1];
        for (int i = r + s; i > r - s; i--)
            copy_arr[i][c + s] = copy_arr[i - 1][c + s];
        for (int i = c + s; i > c - s; i--)
            copy_arr[r - s][i] = copy_arr[r - s][i - 1];
        copy_arr[r - s][c - s + 1] = temp;
        s--;
    }
}

void getMaxValue() {
    int maxVal = 0;
    for (int y = 0; y < N; y++) {
        maxVal = 0;
        for (int x = 0; x < M; x++) {
            maxVal += copy_arr[y][x];
        }
        ret = min(ret, maxVal);
    }
}

void display() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cout << copy_arr[y][x] << " ";
        }
        cout << "\n";
    }
}

void solve(int depth) {
    if (depth == K) {
        memcpy(copy_arr, arr, sizeof(copy_arr));
        for (int i = 0; i < depth; i++) {
            rotate(seq[op[i]].r, seq[op[i]].c, seq[op[i]].s);
        }
        getMaxValue();
    }

    for (int i = 0; i < K; i++) {
        if (visited[i])
            continue;
        visited[i] = 1;
        op[depth] = i;
        solve(depth + 1);
        visited[i] = 0;
    }
}

int main(void) {
    FastIO();
    Init();
    solve(0);
    cout << ret << "\n";
    return 0;
}