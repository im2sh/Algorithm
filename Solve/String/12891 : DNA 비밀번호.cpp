#include <iostream>
#include <vector>

using namespace std;

int S, P;
string str;
int x, y, ret = 0;
int key[101];
int ACGT[101];

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> S >> P;
    cin >> str;

    cin >> key['A'];
    cin >> key['C'];
    cin >> key['G'];
    cin >> key['T'];
}

void solve() {
    y = x + P - 1;

    for (int j = x; j <= y; j++) {
        ACGT[str[j]]++;
    }
    while (y < str.size()) {
        if (key['A'] <= ACGT['A'] && key['C'] <= ACGT['C'] && key['G'] <= ACGT['G'] && key['T'] <= ACGT['T'])
            ret++;
        ACGT[str[x++]]--;
        ACGT[str[++y]]++;
    }

    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
