#include <iostream>
#include <vector>

using namespace std;

int N, ret;
vector<int> prime;
int check[10001];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void makePrime() {
    for (int i = 2; i * i <= 10000; i++) {
        if (check[i])
            continue;
        for (int j = i + i; j <= 10000; j += i)
            check[j] = 1;
    }

    for (int i = 2; i <= 10000; i++) {
        if (!check[i])
            prime.push_back(i);
    }
}

void solve() {
    makePrime();
    for (int i = 0; i < prime.size() - 1; i++) {
        int mul = prime[i] * prime[i + 1];
        if (mul > N) {
            ret = mul;
            break;
        }
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}