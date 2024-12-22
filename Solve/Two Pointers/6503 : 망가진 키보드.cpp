#include <iostream>
#include <algorithm>

using namespace std;

int M, ret;
string S;
int visited[129];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    ret = 0;
    fill(&visited[0], &visited[0] + 129, false);
    cin >> M;
    cin.ignore();
    getline(cin, S);
}

void go() {
    int left = 0;
    int right = 0;
    int cnt = 1;
    int len = 1;
    visited[S[left]] = 1;
    while (left <= right && right <= S.length()) {
        right++;
        if (right == S.length())
            break;

        if (!visited[S[right]]) {
            cnt++;
            len++;
            visited[S[right]]++;
            if (cnt > M) {
                while (true) {
                    visited[S[left]]--;
                    if (visited[S[left]] == 0)
                        break;
                    left++;
                    len--;
                }
                left++;
                len--;
                cnt--;
            }
        } else {
            visited[S[right]]++;
            len++;
        }


        ret = max(ret, len);
    }
}

void solve() {
    while (true) {
        Init();
        if (M == 0)
            break;
        go();
        cout << ret << '\n';
    }
}

int main(void) {
    FastIO();
    solve();
    return 0;
}