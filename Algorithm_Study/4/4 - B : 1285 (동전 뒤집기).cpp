#include <iostream>
#include <string>

using namespace std;

int N;
int coin[21];
int ret = 987654321;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    string temp;
    int temp_n;
    for (int i = 1; i <= N; i++) {
        cin >> temp;
        temp_n = 1;
        for (int j = 0; j < temp.size(); j++) {
            if (temp[j] == 'T')
                coin[i] += temp_n;
            temp_n *= 2;
        }
    }
}

void solve(int here) {
    if (here == N + 1) {
        int sum = 0;
        for (int i = 1; i <= (1 << N - 1); i *= 2) {
            int cnt = 0;
            for (int j = 1; j <= N; j++) {
                if (coin[j] & i)
                    cnt++;
            }
            sum += min(cnt, N - cnt);
        }
        ret = min(ret, sum);
        return;
    }
    solve(here + 1);
    coin[here] = ~coin[here];
    solve(here + 1);
}

int main(void) {
    FastIO();
    Init();
    solve(1);
    cout << ret << "\n";
    return 0;
}
