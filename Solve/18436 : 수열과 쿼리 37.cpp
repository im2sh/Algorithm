#include <iostream>

using namespace std;

int N, M;
int arr[100001];
pair<int, int> tree[400001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

void goTree(int node, int start, int end) {
    if (start == end) {
        if (arr[start] % 2 == 0) {
            tree[node].first = 1;
        } else {
            tree[node].second = 1;
        }
        return;
    }
    goTree(node * 2, start, (start + end) / 2);
    goTree(node * 2 + 1, (start + end) / 2 + 1, end);
    tree[node].first = tree[node * 2].first + tree[node * 2 + 1].first;
    tree[node].second = tree[node * 2].second + tree[node * 2 + 1].second;
}

void goUpdate(int node, int start, int end, int idx, int num) {
    if (idx < start or idx > end) {
        return;
    }

    if (start == end) {
        tree[node].first = 0;
        tree[node].second = 0;

        if (num % 2 == 0) {
            tree[node].first = 1;
        } else {
            tree[node].second = 1;
        }
        return;
    }

    goUpdate(node * 2, start, (start + end) / 2, idx, num);
    goUpdate(node * 2 + 1, (start + end) / 2 + 1, end, idx, num);
    tree[node].first = tree[node * 2].first + tree[node * 2 + 1].first;
    tree[node].second = tree[node * 2].second + tree[node * 2 + 1].second;
}

int goSum(int node, int start, int end, int mode, int left, int right) {
    if (left > end or right < start) {
        return 0;
    }

    if (left <= start and right >= end) {
        if (mode == 2) {
            return tree[node].first;
        } else {
            return tree[node].second;
        }
    }

    int tempA = goSum(node * 2, start, (start + end) / 2, mode, left, right);
    int tempB = goSum(node * 2 + 1, (start + end) / 2 + 1, end, mode, left, right);
    return tempA + tempB;
}

void solve() {
    goTree(1, 0, N - 1);
    cin >> M;
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;

        if (A == 1) {
            goUpdate(1, 0, N - 1, B - 1, C);
        } else {
            cout << goSum(1, 0, N - 1, A, B - 1, C - 1) << "\n";
        }
    }
}

int main() {
    FastIO();
    Init();
    solve();

    return 0;
}