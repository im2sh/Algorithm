#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef struct edge {
    int s;
    int e;
    int w;
} Edge;
typedef long long ll;

int N, M;
ll ret;
vector<Edge> edges;
int parent[100004];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a - 1, b - 1, c});
    }
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }
    sort(edges.begin(), edges.end(), cmp);
}

int getParent(int x) {
    if (parent[x] == x)
        return x;
    else
        return parent[x] = getParent(parent[x]);
}

void unionParent(int s, int e) {
    s = getParent(s);
    e = getParent(e);

    if (e < s)
        parent[s] = e;
    else
        parent[e] = s;
}

bool isSameParent(int s, int e) {
    s = getParent(s);
    e = getParent(e);

    if (s == e)
        return true;
    else
        return false;
}

void solve() {
    int cnt = 0;
    if (N == 2) {
        cout << "0";
        return;
    }

    for (int i = 0; i < M; i++) {
        int s = edges[i].s;
        int e = edges[i].e;
        int w = edges[i].w;

        if (!isSameParent(s, e)) {
            unionParent(s, e);
            ret += w;
            cnt++;
        }
        if (cnt == N - 2) {
            cout << ret;
            return;
        }

    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}