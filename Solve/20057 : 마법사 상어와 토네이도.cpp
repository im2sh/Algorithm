#include <iostream>

using namespace std;

#define SIZE 500

int map[SIZE][SIZE];
int visited[SIZE][SIZE];
int N;
int R, C;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1,
                   0,
                   1,
                   0};
int ret;
int sy, sx;
const int wind_y[4][9] = {
        {-1, 1,  -2, 2, 0,  -1, 1, -1, 1}, // <-
        {-1, -1, 0,  0, 2,  0,  0, 1,  1}, // down
        {-1, 1,  -2, 2, 0,  -1, 1, -1, 1}, // ->
        {1,  1,  0,  0, -2, 0,  0, -1, -1} // Up
};

const int wind_x[4][9] = {
        {1,  1,  0,  0, -2, 0,  0, -1, -1},
        {-1, 1,  -2, 2, 0,  -1, 1, -1, 1},
        {-1, -1, 0,  0, 2,  0,  0, 1,  1},
        {-1, 1,  -2, 2, 0,  -1, 1, -1, 1}
};

const int rate[9] = {1, 1, 2, 2, 5, 7, 7, 10, 10};

void display() {
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cout << map[y][x] << " ";
        }
        cout << "\n";
    }
}

void wind(int cy, int cx, int d) {
    int sum = 0;
    int sand = map[cy][cx];
    int ny, nx;
    int spreadSand = 0;
    int liveSand = 0;
    for (int i = 0; i < 9; i++) {
        ny = cy + wind_y[d][i];
        nx = cx + wind_x[d][i];
        spreadSand = (sand * rate[i]) / 100;

        sum += spreadSand;
        if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
            ret += spreadSand;
            continue;
        }
        if (spreadSand != 0) {
            map[ny][nx] += spreadSand;
        }
    }
    liveSand = sand - sum;
    ny = cy + dy[d];
    nx = cx + dx[d];
    if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
        ret += liveSand;
    } else {
        map[ny][nx] += liveSand;
    }
    map[cy][cx] = 0;
}

//void wind(int cy, int cx, int d) {
//    int sum = 0;
//    int sand = map[cy][cx];
//    int ny, nx;
//    int spreadSand = 0;
//    int liveSand = 0;
//    for (int i = 0; i < 9; i++) {
//        ny = cy + wind_y[d][i];
//        nx = cx + wind_x[d][i];
//        spreadSand = (sand * rate[i]) / 100;
//
//        if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
//            ret += spreadSand;
//            continue;
//        }
//        if (spreadSand != 0) {
//            map[ny][nx] += spreadSand;
//            sum += spreadSand;
//        }
//    }
//    liveSand = sand - sum;
//    map[cy][cx] = 0;
//    ny = cy + dy[d];
//    nx = cx + dx[d];
//    if (ny < 0 || ny >= N || nx < 0 || nx >= N)
//        ret += liveSand;
//    else
//        map[ny][nx] = liveSand;
//}

void solve(int y, int x) {
    fill(&visited[0][0], &visited[0][0] + SIZE * SIZE, 0);
    int dir = -1;
    while (true) {
        if (y == 0 && x == 0)
            break;
        visited[y][x] = 1;
        int nd = (dir + 1) % 4;
        int ny = y + dy[nd];
        int nx = x + dx[nd];
        if (visited[ny][nx]) {
            nd = dir;
            ny = y + dy[nd];
            nx = x + dx[nd];
        }
        wind(ny, nx, nd);
        y = ny;
        x = nx;
        dir = nd;
        display();
        cout << "\n";
//        for (int i = 0; i < 2; i++) {
//            int ny = y + dy[dir];
//            int nx = x + dx[dir];
//
//            if (visited[ny][nx])
//                continue;
//            wind(ny, nx, dir);
//            visited[ny][nx] = 1;
//            dir = (dir + 1) % 4;
//            y = ny;
//            x = nx;
//            display();
//            cout << "\n";
//        }
    }
}

void Init() {
    cin >> N;

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> map[y][x];
        }
    }

}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Init();
    sy = N / 2;
    sx = N / 2;
    solve(sy, sx);
    cout << ret << "\n";
    return 0;
}
