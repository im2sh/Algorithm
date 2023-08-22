#include <iostream>
#include <map>

using namespace std;

int pizza_size, N, M, ret;
int a[1001], b[1001];
int a_sum[2002], b_sum[2002];
map<int, int> aCnt, bCnt;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    int temp;
    cin >> pizza_size;
    cin >> M >> N;

    for (int i = 1; i <= M; i++) {
        cin >> temp;
        a[i] = temp;
    }
    for (int i = 1; i <= M; i++) {
        a_sum[i] = a_sum[i - 1] + a[i];
        //cout << a_sum[i] << " ";
    }
    for (int i = M + 1; i <= 2 * M; i++) {
        a_sum[i] = a_sum[i - 1] + a[i - M];
    }

    for (int i = 1; i <= N; i++) {
        cin >> temp;
        b[i] = temp;
    }

    for (int i = 1; i <= N; i++) {
        b_sum[i] = b_sum[i - 1] + b[i];
    }
    for (int i = N + 1; i <= 2 * N; i++) {
        b_sum[i] = b_sum[i - 1] + b[i - N];
    }
}

void create(int n, int arr[], map<int, int> &_map) {
    for (int i = 1; i <= n; i++) {
        cout << "===" << i << "===" << "\n";
        for (int start = i; start <= n + i - 1; start++) {
            int sum = arr[start] - arr[start - i];
            cout << sum << " ";
            _map[sum]++;
            if (i == n)
                break;
        }
        cout << "\n";
    }

}

void solve() {
    for (int i = 0; i <= M * 2; i++) {
        cout << a_sum[i] << " ";
    }
    cout << "\n";
    create(M, a_sum, aCnt);
    create(N, b_sum, bCnt);

    int sum = 0;
    for (int i = 1; i < pizza_size; i++) {
        sum += aCnt[pizza_size - i] * bCnt[i];
    }
    sum += aCnt[pizza_size];
    sum += bCnt[pizza_size];

    cout << sum << "\n";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}
