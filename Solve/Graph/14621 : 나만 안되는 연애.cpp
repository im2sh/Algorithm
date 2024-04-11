#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct node {
    int start, end, weight;
} Node;
int parent[1001];
int N, M, ret;
char school[1001];
vector<Node> edges;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool cmp(Node a, Node b) {
    return a.weight < b.weight;
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < N; i++) {
        cin >> school[i];
    }

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a - 1, b - 1, c});
    }
    sort(edges.begin(), edges.end(), cmp);
}

int getParent(int node) {
    if (parent[node] == node)
        return node;
    else
        return parent[node] = getParent(parent[node]);
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
        int s = edges[i].start;
        int e = edges[i].end;
        int w = edges[i].weight;

        if (school[s] == school[e])
            continue;
        if (!isSameParent(s, e)) {
            unionParent(s, e);
            cnt++;
            ret += w;
            if (cnt == N - 1) {
                cout << ret;
                return;
            }
        }
    }
    cout << "-1";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
