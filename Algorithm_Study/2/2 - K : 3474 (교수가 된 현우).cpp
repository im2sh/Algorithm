#include <iostream>

using namespace std;

int N, T;
int num2, num5;


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;
        num2 = 0;
        num5 = 0;
        for (int j = 2; j <= N; j *= 2) {
            num2 += N / j;
        }
        for (int j = 5; j <= N; j *= 5) {
            num5 += N / j;
        }
        cout << min(num2, num5) << "\n";
    }
    return 0;
}