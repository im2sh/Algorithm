#include <iostream>
#include <cmath>

using namespace std;

int N;


void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

bool isPrime(int num) {
    if (num == 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void go(int depth, int temp) {
    if (depth == N) {
        cout << temp << '\n';
        return;
    }

    for (int i = 1; i <= 9; i++) {
        int next = temp * 10 + i;
        if (isPrime(next)) {
            go(depth + 1, next);
        }
    }
}

void solve() {
    go(0, 0);
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}

