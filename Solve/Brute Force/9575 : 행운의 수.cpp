#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int N;
vector<int> ret;
set<int> setA, setB, setC;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void Input() {
    ret.clear();
    setA.clear();
    setB.clear();
    setC.clear();
    int a, b, c;
    cin >> a;
    for (int i = 0; i < a; i++) {
        int temp;
        cin >> temp;
        setA.insert(temp);
    }

    cin >> b;
    for (int i = 0; i < b; i++) {
        int temp;
        cin >> temp;
        setB.insert(temp);
    }

    cin >> c;
    for (int i = 0; i < c; i++) {
        int temp;
        cin >> temp;
        setC.insert(temp);
    }
}

void solve() {
    while (N--) {
        Input();
        for (auto i: setA) {
            for (auto j: setB) {
                for (auto k: setC) {
                    bool flag = true;
                    string temp = to_string(i + j + k);
                    for (char c: temp) {
                        if (c != '5' && c != '8') {
                            flag = false;
                            break;
                        }
                    }
                    if (flag && find(ret.begin(), ret.end(), stoi(temp)) == ret.end()) {
                        ret.push_back(stoi(temp));
                    }
                }
            }
        }
        cout << ret.size() << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}