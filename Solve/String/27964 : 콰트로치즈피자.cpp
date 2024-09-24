#include <iostream>
#include <set>
#include <string>

using namespace std;
const string CHEESE = "Cheese";

int N;
set<string> s;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    while (N--) {
        string temp;
        cin >> temp;
        if (temp.find(CHEESE, temp.size() - 6) != string::npos)
            s.insert(temp);
    }
    if (s.size() >= 4)
        cout << "yummy";
    else
        cout << "sad";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}