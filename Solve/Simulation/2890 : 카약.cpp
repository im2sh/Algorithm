#include <iostream>
#include <vector>

using namespace std;

int R, C, cnt = 1;
int ranking[10];
bool flag = false;
vector<string> arr;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        string S;
        cin >> S;
        arr.push_back(S);
    }
}

void solve() {
    for (int i = C - 2; i >= 1; i--) {
        for (int j = 0; j < R; j++) {
            int temp = arr[j][i] - '0';
            if (!ranking[temp] && temp > 0 && temp <= 9) {
                ranking[temp] = cnt;
                flag = true;
            }
        }
        if (flag)
            cnt++;
        flag = false;
    }

    for (int i = 1; i <= 9; i++)
        cout << ranking[i] << '\n';
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}