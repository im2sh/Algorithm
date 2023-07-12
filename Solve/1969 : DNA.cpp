#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N, M;
vector<string> DNA;
int d[51][26];
string ret;
int hamming;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    string temp;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        DNA.push_back(temp);
    }
    for (int i = 0; i < M; i++) {
        ret.push_back(' ');
    }
}

void solve() {
    int k = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            d[j][DNA[j][i] - 65]++;
        }
    }

    for (int i = 0; i < M; i++) {
        map<char, int> temp;
        int cnt = 0;
        int maxN = 0;
        for (int j = 0; j < 26; j++) {
            temp[d[i][j] + 65]++;
        }

        for (auto &a: temp) {
            if (a.second > maxN) {
                maxN = a.second;
                ret[k++] = a.first;
            }
            cnt++;
        }
        if (cnt != 0)
            hamming++;
    }

    cout << ret << "\n";
    cout << hamming;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}