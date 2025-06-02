#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int alpha[26] = {3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
int len1, len2;
string name1, name2;
int maxLen;
vector<int> v;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> len1 >> len2;
    cin >> name1 >> name2;
    maxLen = max(len1, len2);

    for (int i = 0; i < maxLen; i++) {
        if (len1 > i)
            v.push_back(alpha[int(name1[i]) - 65]);
        if (len2 > i)
            v.push_back(alpha[int(name2[i]) - 65]);
    }
}

void go(vector<int> vec) {
    if (vec.size() == 2) {
        int score = 10 * vec[0] + vec[1];
        cout << score << "%";
        return;
    }
    vector<int> v2;
    for (int i = 1; i < vec.size(); i++) {
        v2.push_back((vec[i] + vec[i - 1]) % 10);
    }
    go(v2);
}

void solve() {
    go(v);
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}