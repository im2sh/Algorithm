#include <iostream>

using namespace std;

int N, M, K, j;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int result = 0;
    int temp;
    int L = 1;
    int R;
    cin >> N >> M >> K;

    while (K--) {
        R = L + M - 1;
        cin >> temp;

        if (L <= temp && temp <= R)
            continue;
        else {
            if (R < temp) {
                result += (temp - R);
                L += (temp - R);
            } else {
                result += (L - temp);
                L = temp;
            }
        }
    }
    cout << result;
    return 0;
}