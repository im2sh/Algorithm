#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, D, K, C, ret, sum;
int visited[3001];
vector<int> sushi;

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

    for (int i = 0; i < K; i++) {
        sushi.push_back(sushi[i]);
    }

    for (int i = 0; i < K; i++) {
        if (!visited[sushi[i]])
            sum++;
        visited[sushi[i]]++;
    }
    ret = sum;
}

void solve() {
    int left = 0;
    int right = K - 1;

    while (right < N + K - 1) {
        visited[sushi[left]]--;
        if (!visited[sushi[left]])
            sum--;
        left++;

        right++;
        if (!visited[sushi[right]])
            sum++;
        visited[sushi[right]]++;

        if (!visited[C]) {
            ret = max(ret, sum + 1);
        } else
            ret = max(ret, sum);
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}