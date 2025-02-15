#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct people {
    int land;
    int num;
    int score;
} People;

int N;
vector<People> P;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        P.push_back({A, B, C});
    }
}

bool cmp(People A, People B) {
    return A.score > B.score;
}

void solve() {
    sort(P.begin(), P.end(), cmp);

    for (int i = 0; i < 3; i++) {
        if (i == 2 && P[i].land == P[0].land && P[i].land == P[1].land) {
            while (true) {
                i++;
                if (P[i].land != P[0].land) {
                    break;
                }
            }
        }
        cout << P[i].land << " " << P[i].num << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}