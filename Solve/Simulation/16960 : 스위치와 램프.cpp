#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> V;
int lamp[2004];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int a, b;
    vector<int> temp;
    cin >> N >> M;
    V.push_back(temp);
    for (int i = 1; i < N + 1; i++) {
        temp.clear();
        cin >> a;
        for (int j = 0; j < a; j++) {
            cin >> b;
            lamp[b]++;
            temp.push_back(b);
        }
        V.push_back(temp);
    }
}

void solve() {
    for (int i = 1; i < N + 1; i++) {
        bool flag = 1;
        for (int j = 0; j < V[i].size(); j++) {
            if (lamp[V[i][j]] - 1 <= 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout << 1;
            return;
        }
    }
    cout << 0;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}