#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, sum;
vector<string> DNA;
string ret;

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
}

void solve() {
    for (int i = 0; i < M; i++) {
        int alphaCnt[26] = {0};
        int maxNum = 0;
        char maxAlpha;
        for (int j = 0; j < N; j++) {
            alphaCnt[DNA[j][i] - 'A']++;
            maxNum = max(maxNum, alphaCnt[DNA[j][i] - 'A']);
        }
        for (int k = 0; k < 26; k++) {
            if (alphaCnt[k] == maxNum) {
                ret += k + 'A';
                maxAlpha = k + 'A';
                break;
            }
        }
        for (int k = 0; k < 26; k++) {
            if (k + 'A' != maxAlpha)
                sum += alphaCnt[k];
        }
    }

    cout << ret << "\n";
    cout << sum;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}