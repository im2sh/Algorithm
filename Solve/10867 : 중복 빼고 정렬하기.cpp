#include <iostream>
#include <set>

using namespace std;

set<int> arr;
int N;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    while (N--) {
        int temp;
        cin >> temp;
        arr.insert(temp);
    }

    for (set<int>::iterator it = arr.begin(); it != arr.end(); it++) {
        cout << *it << ' ';
    }
    cout << '\n';
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}