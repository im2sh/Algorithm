#include <iostream>

using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x;
    while (scanf("%d", &x) != EOF) {
        ll one = 1;
        int cnt = 0;
        while (1) {
            if (one % x == 0) {
                cout << ++cnt << "\n";
                break;
            } else {
                one = ((one * 10) + 1);
                one %= x;
                cnt++;
            }
        }
    }
    return 0;
}