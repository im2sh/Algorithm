#include <iostream>
#include <algorithm>

using namespace std;

int A, B, C, D, ret;
bool visited[10001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> A >> B >> C >> D;
}

int getNum(int a, int b, int c, int d) {
    int num1 = a * 1000 + b * 100 + c * 10 + d;
    int num2 = b * 1000 + c * 100 + d * 10 + a;
    int num3 = c * 1000 + d * 100 + a * 10 + b;
    int num4 = d * 1000 + a * 100 + b * 10 + c;

    return min({num1, num2, num3, num4});
}

void solve() {
    for (int i = 1111; i < 10000; i++) {
        int temp = getNum((i / 1000) % 10, (i / 100) % 10, (i / 10) % 10, i % 10);
        if (visited[temp])
            continue;
        visited[temp] = true;
    }


    for (int i = 1111; i <= getNum(A, B, C, D); i++) {
        if (visited[i])
            ret++;
    }

    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}