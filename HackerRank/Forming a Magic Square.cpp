#include <iostream>
#include <algorithm>

using namespace std;

struct pos {
    int a, b, c;
};
int MIN_VAL = 987654321;
int arr[3][3];

pos mat[8][3] = {
        {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
        {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
        {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
        {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
        {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
        {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
        {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
        {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}
};

void solve() {
    for (int i = 0; i < 8; i++) {
        int diff = 0;
        for (int j = 0; j < 3; j++) {
            int a = mat[i][j].a;
            int b = mat[i][j].b;
            int c = mat[i][j].c;

            int x = arr[j][0];
            int y = arr[j][1];
            int z = arr[j][2];
            diff += abs(a - x) + abs(b - y) + abs(c - z);
        }
        MIN_VAL = min(MIN_VAL, diff);
    }

    cout << MIN_VAL;
}

void Init() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Init();
    solve();
    return 0;
}