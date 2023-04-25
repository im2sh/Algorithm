#include <iostream>

using namespace std;
int socks[101];
int flag[101];
int n;
int cnt = 0;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp = 0;
    fill(&flag[0], &flag[0] + 101, 0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> socks[i];
    }
}

int solve() {
    for (int i = 0; i < n; i++) {
        if (flag[i] == false) {
            for (int j = i + 1; j < n; j++) {
                if (socks[i] == socks[j] && !flag[j]) {
                    cnt++;
                    flag[j] = 1;
                    break;
                }
            }
        }
    }
    return cnt;
}


int main(void) {
    FastIO();
    Init();
    cout << solve() << "\n";
    return 0;
}

