#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll A, B;
int ret;
char D;
vector<bool> prime;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> A >> B >> D;
    prime.resize(B + 7, true);
}

void getPrime() {
    prime[1] = false;

    for (long long i = 2; i <= B; i++) {
        if (!prime[i])
            continue;
        for (long long j = 2 * i; j <= B; j += i) {
            prime[j] = false;
        }
    }
}

void solve() {
    for (int i = A; i <= B; i++) {
        if (prime[i] == true) {
            string temp = to_string(i);
            for (int j = 0; j < temp.length(); j++) {
                if (temp[j] == D) {
                    ret++;
                    break;
                }
            }
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


