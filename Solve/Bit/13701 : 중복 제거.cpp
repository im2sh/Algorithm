#include <iostream>
#include <bitset>

using namespace std;
int N;
bitset<33554432> bit_arr;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {

}

void solve() {
    while (1) {
        cin >> N;
        if (cin.eof() == 1) {
            break;
        }
        if (bit_arr[N])
            continue;
        cout << N << " ";
        bit_arr[N] = 1;
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}