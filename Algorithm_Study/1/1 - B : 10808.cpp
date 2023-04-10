#include <iostream>

using namespace std;

int main(void) {
    string alpha;
    int cnt[26] = {0,};
    int result = 0;
    cin >> alpha;

    for (int i = 0; i < alpha.size(); i++) {
        cnt[alpha[i] - 97]++;
    }

    for (int i = 0; i < 26; i++) {
        cout << cnt[i] << " ";
    }
}