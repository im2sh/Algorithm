#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int paper[4][4];
int ret = 0;

void Init() {
    scanf("%d %d", &N, &M);
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            scanf("%1d", &paper[y][x]);
        }
    }
}

void solve() {
    for (int i = 0; i < (1 << N * M); i++) {
        //cout << i << "\n";
        int sum = 0;
        for (int j = 0; j < N; j++) {
            int temp = 0;
            for (int k = 0; k < M; k++) {
                //cout << j << ":" << k << "\n";
                int t = j * M + k;
                if (i & (1 << t)) {
                    temp = temp * 10 + paper[j][k];
                } else {
                    sum += temp;
                    temp = 0;
                }
            }
            sum += temp;
        }
        for (int j = 0; j < M; j++) {
            int temp = 0;
            for (int k = 0; k < N; k++) {
                //cout << j << ":" << k << "\n";
                int t = k * M + j;
                if (!(i & (1 << t))) {
                    temp = temp * 10 + paper[k][j];
                } else {
                    sum += temp;
                    temp = 0;
                }
            }
            sum += temp;
        }

        ret = max(ret, sum);
    }
}

int main(void) {
    Init();
    solve();
    printf("%d\n", ret);
    return 0;
}