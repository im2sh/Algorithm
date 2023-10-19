#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_SIZE 500004

using namespace std;

struct Node {
    long long x, y, w;
};

struct cmp {
    bool operator()(Node &a, Node &b) {
        if (a.y == b.y) {
            return a.x < b.x;
        }
        return a.y < b.y;
    }
};

long long N, C, ret;
vector<Node> v;
pair<long long, long long> tree[MAX_SIZE * 4];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> C;
    for (long long i = 0; i < N; i++) {
        long long x, y, w;
        cin >> x >> y >> w;
        v.push_back({x, y, w});
    }

    sort(v.begin(), v.end(), cmp());
}

void updateTree(long long node, long long start, long long end, long long idx, long long num) {
    if (idx < start or idx > end) {
        return;
    }

    if (start == end) {
        tree[node].first += num;
        tree[node].second += 1;
        return;
    }

    updateTree(node * 2, start, (start + end) / 2, idx, num);
    updateTree(node * 2 + 1, (start + end) / 2 + 1, end, idx, num);
    tree[node].first = tree[node * 2].first + tree[node * 2 + 1].first;
    tree[node].second = tree[node * 2].second + tree[node * 2 + 1].second;
}

long long countTree(long long node, long long start, long long end, long long cnt) {
    if (start == end) {
        return start;
    }

    if (tree[node * 2].second >= cnt) {
        return countTree(node * 2, start, (start + end) / 2, cnt);
    } else {
        return countTree(node * 2 + 1, (start + end) / 2 + 1, end, cnt - tree[node * 2].second);
    }
}

long long sumTree(long long node, long long start, long long end, long long left, long long right) {
    if (left > end or right < start) {
        return 0;
    }

    if (left <= start and right >= end) {
        return tree[node].first;
    }

    long long tempA = sumTree(node * 2, start, (start + end) / 2, left, right);
    long long tempB = sumTree(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
    return tempA + tempB;
}

void solve() {
    for (long long i = 0; i < N; i++) {
        updateTree(1, 0, MAX_SIZE, v[i].x, v[i].w);

        if (i != N - 1 and v[i].y == v[i + 1].y) {
            continue;
        }
        long long temp_Idx = countTree(1, 0, MAX_SIZE, C);
        if (temp_Idx != MAX_SIZE) {
            ret = max(ret, sumTree(1, 0, MAX_SIZE, 0, temp_Idx));
        }
    }
}

int main() {
    FastIO();
    Init();
    solve();
    cout << ret;
    return 0;
}
