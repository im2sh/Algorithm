#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M, ret;
int visited[51];
vector<int> books;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        books.push_back(temp);
    }
    sort(books.begin(), books.end());
}

void solve() {
    for (int i = 0; i < (N / M) + 1; i++) {
        int temp = 0;
        int original = 0;
        int tempabc = 0;
        int idx = 0;
        int absSum = 0;
        int k = 0;

        for (int j = 0; j < books.size(); j++) {
            if (temp < abs(books[j]) && !visited[j]) {
                temp = abs(books[j]);
                original = books[j];
                idx = j;
            }
        }
        int tempIdx = idx;

        while (k < M && i != (N / M)) {
            absSum += abs(books[tempIdx]);
            tempabc += books[tempIdx];
            if (original < 0) {
                visited[tempIdx++] = 1;
            } else {
                visited[tempIdx--] = 1;
            }
            k++;
        }

        if (i == 0)
            ret += abs(original);
        else if (abs(tempabc) < absSum)
            ret += absSum * 2;
        else
            ret += abs(original) * 2;
    }

    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}