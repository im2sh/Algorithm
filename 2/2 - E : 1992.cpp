#include <iostream>

using namespace std;

#define MAX_N 100

char arr[MAX_N][MAX_N];

int N;

string quard(int y, int x, int size) {
    if (size == 1)
        return string(1, arr[y][x]);
    char temp = arr[y][x];
    string result = "";

    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (temp != arr[i][j]) {
                result += '(';
                result += quard(y, x, size / 2);
                result += quard(y, x + size / 2, size / 2);
                result += quard(y + size / 2, x, size / 2);
                result += quard(y + size / 2, x + size / 2, size / 2);
                result += ')';
                return result;
            }
        }
    }
    return string(1, arr[y][x]); // 위에 로직에 걸리지 않을 때
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < N; j++) {
            arr[i][j] = s[j];
        }
    }
    cout << quard(0, 0, N) << "\n";
    return 0;
}