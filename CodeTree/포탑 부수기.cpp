#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct board {
    int hp;
    int attack;
} BOARD;

typedef struct turret {
    int y, x, h, a;
} T;

int N, M, K, ret;
int cnt = 0;
BOARD Board[11][11];
int visited[11][11];
int active[11][11];
pair<int, int> visited_path[11][11];
vector<pair<int, int>> path;
vector<T> Turret;
T Attacker, Target;
const int ly[4] = {0, 1, 0, -1};
const int lx[4] = {1, 0, -1, 0};
const int by[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int bx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M >> K;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> Board[y][x].hp;
            Board[y][x].attack = 0;
        }
    }
}

void InitAttack() {
    Turret.clear();
    path.clear();
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            visited[y][x] = 0;
            active[y][x] = 0;
        }
    }
}

bool cmp(T A, T B) {
    if (A.h != B.h)
        return A.h < B.h;
    if (A.a != B.a)
        return A.a > B.a;
    if (A.y + A.x != B.y + B.x)
        return A.y + A.x > B.y + B.x;
    return A.x > B.x;
}

void chooseAttackerAndTarget() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (Board[y][x].hp != 0) {
                T turret;
                turret.y = y;
                turret.x = x;
                turret.h = Board[y][x].hp;
                turret.a = Board[y][x].attack;
                Turret.push_back(turret);
            }
        }
    }

    sort(Turret.begin(), Turret.end(), cmp);
    Attacker = Turret[0];
    Target = Turret[Turret.size() - 1];
}

bool Laser() {
    queue<pair<int, int>> q;
    q.push({Attacker.y, Attacker.x});
    visited[Attacker.y][Attacker.x] = 1;
    while (q.size()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        if (cy == Target.y && cx == Target.x) {
            return true;
        }

        for (int dir = 0; dir < 4; dir++) {
            int ny = (cy + ly[dir] + N) % N;
            int nx = (cx + lx[dir] + M) % M;

            if (Board[ny][nx].hp == 0 || visited[ny][nx] == 1)
                continue;

            visited_path[ny][nx] = {cy, cx};
            visited[ny][nx] = 1;
            q.push({ny, nx});
        }
    }
    return false;
}

void goLaser() {
    int ay = Attacker.y;
    int ax = Attacker.x;
    int cy = Target.y;
    int cx = Target.x;
    int ny = visited_path[cy][cx].first;
    int nx = visited_path[cy][cx].second;
    Board[cy][cx].hp -= Attacker.h;
    if (Board[cy][cx].hp < 0)
        Board[cy][cx].hp = 0;
    while (1) {
        if (ny == ay && nx == ax)
            break;
        Board[ny][nx].hp -= (Attacker.h / 2);
        if (Board[ny][nx].hp < 0)
            Board[ny][nx].hp = 0;
        active[ny][nx] = 1;
        tie(ny, nx) = visited_path[ny][nx];
    }
}

void Bomb() {
    int cy = Target.y;
    int cx = Target.x;
    Board[cy][cx].hp -= Attacker.h;
    if (Board[cy][cx].hp < 0)
        Board[cy][cx].hp = 0;
    for (int dir = 0; dir < 8; dir++) {
        int ny = (cy + by[dir] + N) % N;
        int nx = (cx + bx[dir] + M) % M;
        if (ny == Attacker.y && nx == Attacker.x)
            continue;
        if (Board[ny][nx].hp != 0) {
            Board[ny][nx].hp -= (Attacker.h / 2);
            active[ny][nx] = 1;
            if (Board[ny][nx].hp < 0)
                Board[ny][nx].hp = 0;
        }
    }
}


void Attack() {
    Board[Attacker.y][Attacker.x].hp += N + M;
    Board[Attacker.y][Attacker.x].attack = cnt;
    Attacker.h += N + M;
    Attacker.a++;
    active[Attacker.y][Attacker.x] = 1;
    active[Target.y][Target.x] = 1;
    if (Laser()) {
        goLaser();
    } else {
        Bomb();
    }
}

void Repair() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (!active[y][x] && Board[y][x].hp != 0)
                Board[y][x].hp++;
        }
    }
}

void cal() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            ret = max(ret, Board[y][x].hp);
        }
    }
}

void displayLaser() {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cout << visited_path[y][x].first << ":" << visited_path[y][x].second << " ";
        }
        cout << '\n';
    }
}


void solve() {
    while (K--) {
        InitAttack();
        chooseAttackerAndTarget();
        if (Turret.size() <= 1)
            break;
        cnt++;
        Attack();
        Repair();
    }
    cal();
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}