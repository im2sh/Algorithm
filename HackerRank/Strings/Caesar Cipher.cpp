#include <iostream>

using namespace std;

string original;
string rotated;

int N, K;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    cin >> original;
    cin >> K;
}

void solve() {
    int temp;
    for (int i = 0; i < original.size(); i++) {
        if (97 <= original[i] && original[i] <= 122)
            temp = original[i] + K % 26;
        else if (65 <= original[i] && original[i] <= 90)
            temp = original[i] + K % 26;
        else
            temp = original[i];
        if (temp > 122 && 97 <= original[i] && original[i] <= 122) {
            temp -= 26;
        }
        if (temp > 90 && 65 <= original[i] && original[i] <= 90)
            temp -= 26;
        rotated += temp;
    }
    cout << rotated;
}


int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}