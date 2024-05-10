#include <iostream>

using namespace std;

int N, ret;
int M[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string week[7] = {"월", "화", "수", "목", "금", "토", "일"};
long long day = 13;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    for (int i = 2019; i <= N; i++) {
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
            M[1] = 29;
        } else {
            M[1] = 28;
        }

        for (int j = 0; j < 12; j++) {
            if (week[day % 7] == "금")
                ret++;

            day += M[j];
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