#include <iostream>

using namespace std;

int N;
string s;
int check[27];
int visited[27];
int maxN = -987654321;


void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        check[s[i] - 97] = 1;
    }
}

void calcu(int depth) {

    if (depth == 2) {

        int cntT = 0;
        char prev = '!';

        for (int i = 0; i < N; i++) {
            if (visited[s[i] - 97]) {
                if (prev == '!') {
                    prev = s[i];
                } else {
                    if (prev == s[i]) {
                        return;
                    } else {
                        prev = s[i];
                    }
                }
                cntT += 1;
            }
        }

        if (maxN < cntT) {
            maxN = cntT;
        }
        return;
    }

    for (int i = 0; i < 27; i++) {
        if (check[i] == 1 && visited[i] == 0) {
            visited[i] = 1;
            calcu(depth + 1);
            visited[i] = 0;
        }
    }
}


void solve() {
    calcu(0);

    if (maxN == -987654321) {
        cout << 0 << "\n";
    } else {
        cout << maxN << "\n";
    }
}

int main() {
    FastIO();
    Init();
    solve();
    return 0;
}
