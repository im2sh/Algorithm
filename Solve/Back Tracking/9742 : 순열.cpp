#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, idx;
string str;
bool valid;
vector<char> arr;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    arr.clear();
    valid = false;
    for (int i = 0; i < str.size(); i++) {
        arr.push_back(str[i]);
    }
    sort(arr.begin(), arr.end());
    idx = 1;
}

void solve() {
    while (true) {
        cin >> str >> N;
        if (cin.eof())
            break;
        Init();

        do {
            if (idx == N) {
                cout << str << ' ' << N << " = ";
                for (int i = 0; i < str.size(); i++) {
                    cout << arr[i];
                    valid = true;
                }
                cout << '\n';
            }
            idx++;

        } while (next_permutation(arr.begin(), arr.end()));
        if (valid == false) {
            cout << str << ' ' << N << " = ";
            cout << "No permutation" << '\n';
        }
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}