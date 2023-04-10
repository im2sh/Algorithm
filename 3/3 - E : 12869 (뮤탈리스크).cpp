#include <iostream>
#include <queue>
#include <algorithm>

#define SIZE 64

using namespace std;
int N;

int visited[SIZE][SIZE][SIZE];
int temp[3] = {0,};

struct scv {
    int a, b, c;
};

int attack[6][3]{
        {9, 3, 1},
        {9, 1, 3},
        {3, 9, 1},
        {3, 1, 9},
        {1, 9, 3},
        {1, 3, 9}
};

int solve(int a, int b, int c) {
    queue<scv> q;
    q.push({a, b, c});
    visited[a][b][c] = 1;
    while (q.size()) {
        int x = q.front().a;
        int y = q.front().b;
        int z = q.front().c;
        q.pop();
        if (visited[0][0][0])
            break;
        for (int i = 0; i < 6; i++) {
            int na = x - attack[i][0];
            int nb = y - attack[i][1];
            int nc = z - attack[i][2];

            if (na < 0)
                na = 0;
            if (nb < 0)
                nb = 0;
            if (nc < 0)
                nc = 0;
//            int na = max(0, x - attack[i][0]);
//            int nb = max(0, y - attack[i][1]);
//            int nc = max(0, z - attack[i][2]);

            if (visited[na][nb][nc])
                continue;
            visited[na][nb][nc] = visited[x][y][z] + 1;
            q.push({na, nb, nc});
        }
    }
    return visited[0][0][0] - 1;
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp[i];
    }
    fill(&visited[0][0][0], &visited[0][0][0] + SIZE * SIZE * SIZE, 0);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Init();
    cout << solve(temp[0], temp[1], temp[2]) << "\n";
    return 0;
}
