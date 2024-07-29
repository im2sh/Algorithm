#include <iostream>

using namespace std;

int N, ret = 1;
int cnt[1004][1004];
int student[1004][10];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 5; j++)
            cin >> student[i][j];
    }
}

void solve() {
    for (int k = 1; k <= 5; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == j)
                    continue;

                if (student[i][k] == student[j][k]) {
                    cnt[i][j] = 1;
                }
            }
        }
    }

    int maxNum = 0;

    for (int i = 1; i <= N; i++) {
        int temp = 0;
        for (int j = 1; j <= N; j++)
            temp += cnt[i][j];

        if (maxNum < temp) {
            maxNum = temp;
            ret = i;
        }
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}