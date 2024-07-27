#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

string parent[4];
vector<string> ret;
map<string, int> bird;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> parent[0] >> parent[1];
    cin >> parent[2] >> parent[3];
}

void solve() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            string temp = parent[i] + " " + parent[j];
            if (bird[temp])
                continue;
            bird[temp]++;
            ret.push_back(temp);
        }
    }
    sort(ret.begin(), ret.end());
    for (string r: ret) {
        cout << r << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}