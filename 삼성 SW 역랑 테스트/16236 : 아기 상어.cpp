#include <iostream>
#include <queue>

using namespace std;
#define SIZE 21

typedef struct shark {
    int y;
    int x;
    int time;
} Shark;

struct Fish {
    int y;
    int x;
    int time;
};

int N;
int sea[SIZE][SIZE];
int sharkbody = 0;
int sharksize = 2;
const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, -1, 0, 1};
int visited[SIZE][SIZE];
vector<Fish> fish;
Shark shark;
int ret = 0;
int t;

void go_shark(Shark shark) {
    queue<Shark> q;
    q.push(shark);
    Shark cur;
    visited[shark.y][shark.x] = 1;
    while (q.size()) {
        cur = q.front();
        q.pop();

        if (sea[cur.y][cur.x] < sharksize && sea[cur.y][cur.x] != 0 && cur.time != 0) {
            fish.push_back({cur.y, cur.x, cur.time});
        }
        for (int i = 0; i < 4; i++) {
            Shark next;
            next.y = dy[i] + cur.y;
            next.x = dx[i] + cur.x;

            if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= N) {
                continue;
            } else if (!visited[next.y][next.x] && sea[next.y][next.x] <= sharksize) {
                next.time = cur.time + 1;
                visited[next.y][next.x] = 1;
                q.push(next);
            }
        }

    }
}

void init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> sea[i][j];
            if (sea[i][j] == 9) {
                shark.y = i;
                shark.x = j;
                shark.time = 0;
                sea[i][j] = 0;
            }
        }
    }
}

bool cmp(Fish a, Fish b) {
    if (a.time == b.time) {
        if (a.y == b.y)
            return a.x < b.x;
        else
            return a.y < b.y;
    } else {
        return a.time < b.time;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    while (1) {
        fill(&visited[0][0], &visited[0][0] + SIZE * SIZE, 0);
        fish.clear();
        go_shark(shark);
        sort(fish.begin(), fish.end(), cmp);

        if (fish.size() == 0) {
            cout << ret << "\n";
            break;
        }

        sea[shark.y][shark.x] = 0;
        shark.y = fish[0].y;
        shark.x = fish[0].x;
        ret += fish[0].time;

        sharkbody++;

        if (sharkbody == sharksize) {
            sharkbody = 0;
            sharksize++;
        }
    }
    return 0;
}


