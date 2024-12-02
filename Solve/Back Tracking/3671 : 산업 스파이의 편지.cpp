#include <iostream>
#include <vector>
#include <map>

using namespace std;

int TC, ret;
string S;
map<int, bool> dict;
vector<int> arr;
bool visited[9];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> TC;
}

void Input() {
    fill(&visited[0], &visited[0] + 9, false);
    dict.clear();
    arr.clear();
    ret = 0;
    cin >> S;
}

bool isPrime(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

void go(int depth, int sum) {
    if (depth > S.length())
        return;
    if (depth > 0 && sum > 1) {
        if (!dict[sum]) {
            dict[sum] = true;
            if (isPrime(sum)) {
                ret++;
            }
        }
    }

    for (int i = 0; i < S.length(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            go(depth + 1, (sum * 10) + S[i] - '0');
            visited[i] = false;
        }
    }
}

void solve() {
    while (TC--) {
        Input();
        go(0, 0);
        cout << ret << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}