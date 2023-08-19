#include <iostream>
#include <cstring>

using namespace std;

typedef struct shark {
    char name;
    int s;
    int d;
    int z;
    bool alive;
} SHARK;

SHARK shark[104][104];
SHARK temp_shark[104][104];
pair<int, int> target;
int R, C, M, ret;
const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    char alpha = 'a';
    int a, b, c, d, e;
    cin >> R >> C >> M;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c >> d >> e;
        shark[a][b].name = alpha;
        alpha++;
        if (d - 1 <= 1)
            c %= (2 * (R - 1));
        else
            c %= (2 * (C - 1));
        shark[a][b].s = c;
        shark[a][b].d = d - 1;
        shark[a][b].z = e;
        shark[a][b].alive = true;
    }
}

void findAndCatchTarget(int x) {
    for (int y = 1; y <= R; y++) {
        if (shark[y][x].alive) {
            target = {y, x};
            break;
        }
    }
    ret += shark[target.first][target.second].z;
    shark[target.first][target.second].alive = false;
}

int changeDir(int d) {
    switch (d) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 3;
        case 3:
            return 2;
    }
}

void move(int y, int x) {
    int cy = y;
    int cx = x;
    shark[y][x].alive = false;
    SHARK temp = shark[y][x];
    while (temp.s) {
        int ny = cy + dy[temp.d];
        int nx = cx + dx[temp.d];

        if (ny == 0 || ny == R + 1) {
            ny = cy;
            temp.s++;
            temp.d = changeDir(temp.d);
        } else if (nx == 0 || nx == C + 1) {
            nx = cx;
            temp.s++;
            temp.d = changeDir(temp.d);
        }
        temp.s--;
        cy = ny;
        cx = nx;
    }

    if (temp.z > temp_shark[cy][cx].z) {
        temp_shark[cy][cx].name = temp.name;
        temp_shark[cy][cx].d = temp.d;
        temp_shark[cy][cx].s = shark[y][x].s;
        temp_shark[cy][cx].z = shark[y][x].z;
        temp_shark[cy][cx].alive = true;
    }
}

void display() {
    for (int y = 1; y <= R; y++) {
        for (int x = 1; x <= C; x++) {
            if (shark[y][x].alive)
                cout << shark[y][x].name << " ";
            else
                cout << "x" << " ";
        }
        cout << "\n";
    }
}

void displayDir() {
    for (int y = 1; y <= R; y++) {
        for (int x = 1; x <= C; x++) {
            if (shark[y][x].alive)
                cout << shark[y][x].d << " ";
            else
                cout << "x" << " ";
        }
        cout << "\n";
    }
}


void solve() {
    SHARK temp;
    temp.name = 'x';
    temp.d = 0;
    temp.z = 0;
    temp.s = 0;
    temp.alive = false;
    for (int i = 1; i <= C; i++) {
        cout << i << '\n';
        cout << "==================================" << '\n';
        fill(&temp_shark[0][0], &temp_shark[0][0] + 104 * 104, temp);
        display();
        cout << "\n";
        displayDir();
        cout << "\n";
        findAndCatchTarget(i);
        for (int y = 1; y <= R; y++) {
            for (int x = 1; x <= C; x++) {
                if (shark[y][x].alive)
                    move(y, x);
            }
        }
        cout << '\n';
        memcpy(shark, temp_shark, sizeof(shark));
        display();
        cout << '\n';
        displayDir();
        cout << "\n";
        cout << ret << "\n";
        cout << "==================================" << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    cout << ret << "\n";
    return 0;
}