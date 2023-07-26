#include <iostream>

#define MAX_SIZE 100002
using namespace std;
typedef long long ll;
int N;
int arr[MAX_SIZE];
int check[MAX_SIZE];
int s, e;
ll ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

void solve() {
    for (int i = 0; i < N; i++) {
        s = i;
        while (e < N) {
            if (check[arr[e]])
                break;
            check[arr[e++]] = 1;
        }
        ret += e - s;
        check[arr[i]] = 0;
    }
    cout << ret << "\n";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
