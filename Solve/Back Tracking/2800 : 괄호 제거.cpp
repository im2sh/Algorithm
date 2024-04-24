#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string sen;
vector<pair<int, int>> bracket;
bool visited[11];
bool delete_bracket[204];
vector<string> ret;
map<string, int> store;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    stack<int> s;
    cin >> sen;
    for (int i = 0; i < sen.length(); i++) {
        if (sen[i] == '(') {
            s.push(i);
        } else if (sen[i] == ')') {
            int idx = s.top();
            s.pop();
            bracket.push_back({idx, i});
        }
    }
}

void go(int idx, int depth) {
    if (depth >= 1) {
        string temp = "";
        for (int i = 0; i < sen.length(); i++) {
            if (delete_bracket[i])
                continue;
            temp += sen[i];
        }
        if (!store[temp]) {
            ret.push_back(temp);
            store[temp] = 1;
        }
    }
    for (int i = idx; i < bracket.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            delete_bracket[bracket[i].first] = true;
            delete_bracket[bracket[i].second] = true;
            go(i + 1, depth + 1);
            delete_bracket[bracket[i].first] = false;
            delete_bracket[bracket[i].second] = false;
            visited[i] = false;
        }
    }
}

void solve() {
    go(0, 0);
    sort(ret.begin(), ret.end());
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}