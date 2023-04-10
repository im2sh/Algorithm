#include <iostream>

using namespace std;

int truck[101] = {0,};

int main(void) {
    int a, b, c;
    cin >> a >> b >> c;
    int start, end;
    int result = 0;

    for (int i = 0; i < 3; i++) {
        cin >> start >> end;
        for (int j = start; j < end; j++) { // 이상, 미만
            truck[j]++;
        }
    }

    for (int i = 1; i <= 100; i++) {
        if (truck[i] == 1)
            result += a;
        else if (truck[i] == 2)
            result += b * 2;
        else if (truck[i] == 3)
            result += c * 3;
        else
            continue;
    }
    cout << result << "\n";
}

