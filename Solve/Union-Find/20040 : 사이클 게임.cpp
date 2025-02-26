#include <iostream>

using namespace std;

int N, M;
int parent[500001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }
}

int getParent(int x) {
    if (parent[x] == x)
        return x;
    return getParent(parent[x]);
}

void setParent(int a, int b) {
    int A = getParent(a);
    int B = getParent(b);

    if (A < B)
        parent[B] = A;
    else
        parent[A] = B;
}

bool isSame(int a, int b) {
    if (getParent(a) == getParent(b))
        return true;
    return false;
}

void solve() {
    int A, B;
    for (int i = 1; i <= M; i++) {
        cin >> A >> B;
        if (isSame(A, B)) {
            cout << i;
            return;
        }
        setParent(A, B);
    }
    cout << 0;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}