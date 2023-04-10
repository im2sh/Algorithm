#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> dogam1;
map<int, string> dogam2;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    string one;
    string findone;
    int num;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> one;
        dogam1[one] = i;
        dogam2[i] = one;
    }

    for (int i = 0; i < M; i++) {
        cin >> findone;
        if (isdigit(findone[0])) {
            cout << dogam2[stoi(findone)] << "\n";
        } else {
            cout << dogam1[findone] << "\n";
        }
    }
    return 0;
}