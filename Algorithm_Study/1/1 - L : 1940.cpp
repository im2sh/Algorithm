#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int N, M;
    cin >> N;
    cin >> M;
    int cnt = 0;
    int ing[15001] = {0,};
    for (int i = 0; i < N; i++) {
        cin >> ing[i];
    }

    sort(ing, ing + N);

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++)
            if ((ing[i] + ing[j]) == M) {
                cnt++;
                break;
            }
    }
    cout << cnt << "\n";
}