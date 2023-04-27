#include <iostream>
#include <queue>

#define MAX_SIZE 1504

using namespace std;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int R, C;
char hosu[MAX_SIZE][MAX_SIZE];
int hosu_visited[MAX_SIZE][MAX_SIZE];
int swan_visited[MAX_SIZE][MAX_SIZE];
queue<pair<int, int>> swan;
queue<pair<int, int>> swanQ;
queue<pair<int, int>> waterQ;
queue<pair<int, int>> iceQ;
int cnt = 0;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp_y, temp_x;
    fill(&hosu_visited[0][0], &hosu_visited[0][0] + MAX_SIZE * MAX_SIZE, 0);
    fill(&swan_visited[0][0], &swan_visited[0][0] + MAX_SIZE * MAX_SIZE, 0);
    cin >> R >> C;
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            cin >> hosu[y][x];
            if (hosu[y][x] == 'L') {
                temp_y = y;
                temp_x = x;
            }
            if (hosu[y][x] == '.' || hosu[y][x] == 'L') { // 오리도 물 위에 있음
                hosu_visited[y][x] = 1; // 물이면 탐색할 필요 없기 때문에 미리 방문했다고 표시
                waterQ.push({y, x});
            }
        }
    }
    swan.push({temp_y, temp_x});
    swan_visited[temp_y][temp_x] = 1;
}


bool swanmove() {
    while (swan.size()) {
        int cy = swan.front().first;
        int cx = swan.front().second;
        swan.pop();

        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + cy;
            int nx = dx[i] + cx;

            if (ny < 0 || ny >= R || nx < 0 || nx >= C || swan_visited[ny][nx])
                continue;
            swan_visited[ny][nx] = 1;
            if (hosu[ny][nx] == '.')
                swan.push({ny, nx});
            else if (hosu[ny][nx] == 'X')
                swanQ.push({ny, nx});
            else if (hosu[ny][nx] == 'L')
                return true;
        }
    }
    return false;
}

void icebreak() {
    while (waterQ.size()) {
        int cy = waterQ.front().first;
        int cx = waterQ.front().second;
        waterQ.pop();

        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + cy;
            int nx = dx[i] + cx;

            if (ny < 0 || ny >= R || nx < 0 || nx >= C || hosu_visited[ny][nx])
                continue;
            hosu_visited[ny][nx] = 1;
            if (hosu[ny][nx] == 'X') {
                hosu[ny][nx] = '.';
                iceQ.push({ny, nx});
            }
        }
    }
}

void hosu_visit_display() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << hosu_visited[i][j] << " ";
        }
        cout << "\n";
    }
}

void hosu_display() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << hosu[i][j] << " ";
        }
        cout << "\n";
    }
}

void iceQclear() {
    queue<pair<int, int>> tempQ;
    swap(iceQ, tempQ);
}

void swanQclear() {
    queue<pair<int, int>> tempQ;
    swap(swanQ, tempQ);
}


void solve() {
    while (true) {
        if (swanmove())
            break;
        icebreak();
        waterQ = iceQ;
        swan = swanQ;
        iceQclear();
        swanQclear();
        cnt++;
//        hosu_visit_display();
//        cout << "\n";
//        hosu_display();
//        cout << "\n";
    }
    cout << cnt << "\n";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}