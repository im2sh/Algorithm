#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N;
string input;
vector<string> student;
int len = 1;
int result;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> input;
        reverse(input.begin(), input.end());
        student.push_back(input);
    }
}

void solve() {
    while (1) {
        set<string> s;
        for (int i = 0; i < N; i++) {
            s.insert(student[i].substr(0, len));
        }
        if (s.size() == N) {
            break;
        } else {
            len++;
        }

    }

    result = len;
    cout << result;
}

int main() {
    FastIO();
    Init();
    solve();
    return 0;
}