#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, D, K, C, ret = 1;
vector<int> sushi;
int visited[3001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> D >> K >> C;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        sushi.push_back(temp);
    }

    for (int i = 0; i < K - 1; i++) {
        sushi.push_back(sushi[i]);
        N++;
    }

    for (int i = 0; i < K; i++) {
        visited[sushi[i]]++;
        if (visited[sushi[i]] == 1 && sushi[i] != C)
            ret++;
    }
}

void solve() {
    int low = 0;
    int high = K;
    int len = ret;
    while (low <= high && high < N) {
        visited[sushi[low]]--;
        if (visited[sushi[low]] == 0 && sushi[low] != C)
            len--;

        visited[sushi[high]]++;
        if (visited[sushi[high]] == 0 && sushi[high] != C)
            len--;
        else if (visited[sushi[high]] == 1 && sushi[high] != C)
            len++;
        low++;
        high++;
        ret = max(ret, len);
    }

    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}