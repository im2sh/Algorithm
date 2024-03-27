#include <iostream>
#include <vector>
#include <algorithm>

/*
 * 1. 복제
 *     - 물고기 좌표, 방향을 저장해둠
 * 2. 물고기 이동
 *     - 상어 있는 곳, 물고기 냄새, 격자 범위 X
 *     - 갈 수 없으면 (dir + 7) % 8
 *     - 모든 곳이 X면 이동 X
 * 3. 상어 이동
 *     - 백트래킹으로 갈 수 있는 곳 다 넣어둠
 *     - 정렬
 *     - 주의할 점 : 상하상처럼 다시 돌아오는 경우가 있음 (상어가 머물던 곳에 물고기가 많을 수 있기 때문이다.
 *                                             이 때는 갔던 곳의 물고기를 0으로 만들어서 중복으로 못 먹게 해야함.)
 * 4. 상어 냄새 지우기
 */

using namespace std;

const int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

const int shark_dy[4] = {-1, 0, 1, 0};
const int shark_dx[4] = {0, -1, 0, 1};

typedef struct fish {
    int y;
    int x;
    int dir;
    bool isAlive;
} Fish;

typedef struct shark {
    int y;
    int x;
} Shark;

typedef struct board {
    bool smell;
    int time;
    int fishCnt = 0;
} BOARD;

int M, T;
vector<Fish> CopyFishes;
vector<Fish> F;
Shark S;
BOARD B[4][4];
int visited[4][4];
vector<pair<int, int>> path;
vector<pair<int, string>> shark_path;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int y, x, dir;
    cin >> M >> T;
    for (int i = 0; i < M; i++) {
        cin >> y >> x >> dir;
        F.push_back({y - 1, x - 1, dir - 1, true});
    }
    cin >> y >> x;
    S = {y - 1, x - 1};

    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            B[y][x].smell = false;
            B[y][x].time = 0;
            B[y][x].fishCnt = 0;
        }
    }
}

void CopyFish() {
    CopyFishes.clear();
    for (int i = 0; i < F.size(); i++) {
        CopyFishes.push_back(F[i]);
    }
}

void MoveFish() {
    for (int i = 0; i < F.size(); i++) {
        int cy = F[i].y;
        int cx = F[i].x;
        int dir = F[i].dir;

        bool isMoving = false;
        int movingCnt = 0;
        while (!isMoving) {
            if (movingCnt == 8)
                break;
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            movingCnt++;
            if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4 || B[ny][nx].smell) {
                // 격자 밖 or 물고기의 냄새
                dir = (dir + 7) % 8;
                continue;
            }
            if (ny == S.y && nx == S.x) {
                // 상어 있는 곳
                dir = (dir + 7) % 8;
                continue;
            }
            isMoving = true;
            F[i].y = ny;
            F[i].x = nx;
            F[i].dir = dir;
        }
    }

    for (int i = 0; i < F.size(); i++) {
        int fy = F[i].y;
        int fx = F[i].x;

        B[fy][fx].fishCnt++;
    }
}

bool cmp(pair<int, string> a, pair<int, string> b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

void getPath() {
    int cnt = 0;
    string path_string = "";
    for (int i = 0; i < path.size(); i++) {
        cnt += path[i].first;
        path_string += path[i].second + '0';
    }
    shark_path.push_back({cnt, path_string});
}

void SelectMoveShark(int y, int x, int depth) {
    if (depth == 3) {
        getPath();
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        int ny = y + shark_dy[dir];
        int nx = x + shark_dx[dir];
        if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4)
            continue;

        path.push_back({B[ny][nx].fishCnt, dir + 1}); // 나중에 -1 해줘야함, 사전순 정렬을 위해
        int temp = B[ny][nx].fishCnt;
        B[ny][nx].fishCnt = 0;
        SelectMoveShark(ny, nx, depth + 1);
        B[ny][nx].fishCnt = temp;
        path.pop_back();
    }
}

void MoveShark() {
    sort(shark_path.begin(), shark_path.end(), cmp);

    int sy = S.y;
    int sx = S.x;
    for (int i = 0; i < 3; i++) {
        int dir = (shark_path[0].second[i] - '0') - 1;
        int ny = sy + shark_dy[dir];
        int nx = sx + shark_dx[dir];
        sy = ny;
        sx = nx;

        for (int j = 0; j < F.size(); j++) {
            if (F[j].y == ny && F[j].x == nx) {
                F[j].isAlive = false;
                B[ny][nx].smell = true;
                B[ny][nx].time = 3;
            }
        }
    }

    S = {sy, sx};
}

void MajicFish() {
    for (int i = 0; i < F.size(); i++) {
        if (!F[i].isAlive)
            continue;
        CopyFishes.push_back(F[i]);
    }
    F.clear();
    for (int i = 0; i < CopyFishes.size(); i++) {
        F.push_back(CopyFishes[i]);
    }

    int temp[4][4] = {0,};

    for (int i = 0; i < F.size(); i++) {
        int y = F[i].y;
        int x = F[i].x;

        temp[y][x]++;
    }
}

void display() {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            cout << B[y][x].time << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void DeleteSmell() {
    shark_path.clear();
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            B[y][x].fishCnt = 0;
            if (B[y][x].time > 0)
                B[y][x].time--;
            if (B[y][x].time == 0)
                B[y][x].smell = false;
        }
    }
}

void solve() {
    while (T--) {
        CopyFish();
        MoveFish();
        SelectMoveShark(S.y, S.x, 0);
        MoveShark();
        DeleteSmell();
        MajicFish();
    }
    cout << F.size();
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}