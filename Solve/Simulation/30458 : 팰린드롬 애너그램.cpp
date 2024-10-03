#include <iostream>

using namespace std;
int N;
int visited[26];
string S;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    cin >> S;
}

void solve() {
    for (int i = 0; i < N; i++)
        visited[S[i] - 'a']++;
    if (N % 2 == 1)
        visited[S[N / 2] - 'a']--;

    for (int i = 0; i < 26; i++) {
        if (visited[i] % 2 == 1) {
            cout << "No";
            return;
        }
    }
    cout << "Yes";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}