#include <iostream>

using namespace std;

int N, num, strike, ball, ret, s_cnt, b_cnt;
bool visited[1001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    fill(&visited[0], &visited[0] + 1001, true);
    for (int i = 123; i <= 987; i++) {
        string temp = to_string(i);

        if (temp[0] == temp[1] || temp[1] == temp[2] || temp[0] == temp[2])
            visited[i] = false;
        if (temp[0] - '0' == 0 || temp[1] - '0' == 0 || temp[2] - '0' == 0)
            visited[i] = false;
    }

    for (int i = 1; i <= N; i++) {
        cin >> num >> strike >> ball;

        for (int i = 123; i <= 987; i++) {
            s_cnt = 0;
            b_cnt = 0;

            if (visited[i]) {
                string one = to_string(num);
                string two = to_string(i);

                for (int a = 0; a < 3; a++) {
                    for (int b = 0; b < 3; b++) {
                        if (a == b && one[a] == two[b])
                            s_cnt++;
                        if (a != b && one[a] == two[b])
                            b_cnt++;
                    }
                }

                if (s_cnt != strike || b_cnt != ball)
                    visited[i] = false;
            }
        }
    }

    for (int i = 123; i <= 987; i++) {
        if (visited[i])
            ret++;
    }

    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}