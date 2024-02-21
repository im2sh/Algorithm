#include <iostream>

using namespace std;

int N, M;
int parent[1000001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
}

int findParent(int a) {
    if (parent[a] == a)
        return a;
    return parent[a] = findParent(parent[a]);
}

void union_set(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

bool findUnion(int a, int b) {
    a = findParent(a);
    b = findParent(b);

    if (a == b)
        return true;
    return false;
}

void solve() {
    int command, a, b;
    for (int i = 0; i < M; i++) {
        cin >> command >> a >> b;
        if (command == 0) {
            union_set(a, b);
        } else {
            if (findUnion(a, b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}