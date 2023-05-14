#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
struct Food {
    int p;
    int f;
    int s;
    int v;
    int c;
};

Food food[16];
map<int, vector<vector<int>>> ret_v;
int P, F, S, V;
int N;
int ret = 987654321;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    cin >> P >> F >> S >> V;
    for (int i = 0; i < N; i++) {
        cin >> food[i].p >> food[i].f >> food[i].s >> food[i].v >> food[i].c;
    }
}

void solve() {
    int a, b, c, d;
    for (int i = 1; i < (1 << N); i++) {
        a = b = c = d = 0;
        int sum = 0;
        vector<int> temp;
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                temp.push_back(j + 1);
                a += food[j].p;
                b += food[j].f;
                c += food[j].s;
                d += food[j].v;
                sum += food[j].c;
            }
        }

        if (a >= P && b >= F && c >= S && d >= V) {
            ret_v[sum].push_back(temp);
            ret = min(ret, sum);
        }
    }
    if (ret == 987654321) {
        cout << "-1";
        return;
    }
    sort(ret_v[ret].begin(), ret_v[ret].end());
    cout << ret << "\n";
    for (auto &it: ret_v[ret][0])
        cout << it << " ";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}