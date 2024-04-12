#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct edge {
    int s, e, weight;
} Edge;

int N, M, ret;
int parent[1001];
vector<Edge> edges;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool cmp(Edge a, Edge b) {
    return a.weight < b.weight;
}

void Init() {
    cin >> N;
    cin >> M;
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a - 1, b - 1, c});
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

    if (s < e)
        parent[e] = s;
    else
        parent[s] = e;
}

bool isSameParent(int s, int e) {
    s = getParent(s);
    e = getParent(e);

    if (s == e)
        return true;
    return false;
}


void solve() {
    int cnt = 0;
    for (int i = 0; i < edges.size(); i++) {
        int s = edges[i].s;
        int e = edges[i].e;
        int w = edges[i].weight;

        if (!isSameParent(s, e)) {
            unionParent(s, e);
            ret += w;
            cnt++;
        }
        if (cnt == N - 1)
            break;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}