#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string>

#define SIZE 1004000

using namespace std;

bool prime[SIZE];
int N;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void go() {
    memset(prime, true, sizeof(prime));
    prime[1] = false;

    for (int i = 2; i * i < SIZE; i++) {
        if (prime[i] == false)
            continue;
        for (int j = i + i; j < SIZE; j += i) {
            prime[j] = false;
        }
    }
}


bool isPalindrome(int n) {
    string str = to_string(n);
    for (int i = 0; i < str.size() / 2; i++) {
        if (str[i] != str[str.size() - i - 1])
            return false;
    }
    return true;
}

void solve() {
    go();

    for (int i = N;; i++) {
        if (prime[i] == false)
            continue;
        if (isPalindrome(i)) {
            cout << i;
            break;
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
