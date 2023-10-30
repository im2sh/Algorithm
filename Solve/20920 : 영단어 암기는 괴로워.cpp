#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int N, M;
map<string, int> check;
vector<pair<int, string>> word;

void FastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    while (N--) {
        string temp;
        cin >> temp;
        if (temp.length() < M)
            continue;
        check[temp]++;
    }
}

bool cmp(pair<int, string> a, pair<int, string> b) {
    if (a.first == b.first) {
        if (a.second.length() == b.second.length())
            return a.second < b.second;
        else return a.second.length() > b.second.length();
    } else return a.first > b.first;
}

void solve() {
    for (auto c: check)
        word.push_back({c.second, c.first});
    sort(word.begin(), word.end(), cmp);
    for (auto w: word)
        cout << w.second << '\n';
}

int main() {
    FastIO();
    Init();
    solve();
    return 0;
}