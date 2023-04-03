#include <iostream>
#include <vector>
#include <algorithm>

#define SIZE 104

using namespace std;

vector<vector<int>> mul;

const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, -1, 0, 1};
int N, K;
int cnt = 0;

bool check() {
    int maxN = *max_element(mul[0].begin(), mul[0].end());
    int minN = *min_element(mul[0].begin(), mul[0].end());

    return (maxN - minN) <= K;
}

void addMul() {
    int minN = *min_element(mul[0].begin(), mul[0].end());
    for (int i = 0; i < N; i++) {
        if (mul[0][i] == minN)
            mul[0][i]++;
    }
}

void moveFish() {
    vector<vector<int>> temp = vector<vector<int>>(N, vector<int>(N, 0));
    vector<int> temp_map;
    temp = mul;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mul[i][j] != -1) {
                for (int k = 0; k < 4; k++) {
                    int ny = dy[k] + i;
                    int nx = dx[k] + j;

                    if (ny < 0 || ny >= N || nx < 0 || nx >= N || mul[ny][nx] == -1)
                        continue;
                    temp[i][j] += (mul[ny][nx] - mul[i][j]) / 5;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (temp[j][i] != -1) {
                temp_map.push_back(temp[j][i]);
            }
        }
    }
    mul = vector<vector<int>>(N, vector<int>(N, -1));
    mul[0] = temp_map;
}

void moveMap() {
    addMul();
    int hx = 0;
    int lx = 1;
    int ly = 1;

    while (hx + lx + ly <= N) {
        for (int y = 0; y < ly; y++) {
            for (int x = 0; x < lx; x++) {
                int ny = lx - x;
                int nx = lx + hx + y;
                mul[ny][nx] = mul[y][hx + x];
                mul[y][hx + x] = -1;
            }
        }

        hx = hx + lx;
        if (lx == ly)
            ly++;
        else
            lx++;
    }

    moveFish();

    hx = 0;
    lx = N / 2;
    ly = 1;

    for (int i = 0; i < 2; i++) {
        for (int y = 0; y < ly; y++) {
            for (int x = 0; x < lx; x++) {
                int ny = (ly * 2) - 1 - y;
                int nx = (lx * ly) * 2 - 1 - x;
                mul[ny][nx] = mul[y][hx + x];
                mul[y][hx + x] = -1;
            }
        }
        hx = N / 2;
        ly++;
        lx = lx / 2;
    }
    moveFish();

}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    mul = vector<vector<int>>(N, vector<int>(N, -1));

    for (int i = 0; i < N; i++) {
        cin >> mul[0][i];
    }

    while (!check()) {
        cnt++;
        moveMap();
//        for (int i = 0; i < mul[0].size(); i++) {
//            cout << mul[0][i] << " ";
//        }
    }
    cout << cnt << "\n";
    return 0;
}