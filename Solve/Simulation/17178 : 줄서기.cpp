#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct people {
    string alpha;
    int number;
} People;

int N, idx = 0;
vector<People> ret;
queue<People> line;
stack<People> st;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            string temp;
            cin >> temp;
            string t = temp.substr(0, 1);
            string n = temp.substr(2, temp.length() - 2);
            ret.push_back({t, stoi(n)});
            line.push({t, stoi(n)});
        }
    }
}

bool cmp(People a, People b) {
    if (a.alpha == b.alpha) {
        return a.number < b.number;
    }
    return a.alpha < b.alpha;
}

void solve() {
    sort(ret.begin(), ret.end(), cmp);

    while (line.size()) {
        int past = idx;
        if (st.size() && st.top().alpha == ret[idx].alpha && st.top().number == ret[idx].number) {
            st.pop();
            idx++;
        } else if (line.size() && line.front().alpha == ret[idx].alpha && line.front().number == ret[idx].number) {
            line.pop();
            idx++;
        }
        if (past == idx && line.size()) {
            st.push(line.front());
            line.pop();
        }
    }
    while (st.size()) {
        if (st.top().alpha == ret[idx].alpha && st.top().number == ret[idx].number) {
            st.pop();
            idx++;
        } else {
            break;
        }
    }

    if (st.size())
        cout << "BAD";
    else
        cout << "GOOD";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
