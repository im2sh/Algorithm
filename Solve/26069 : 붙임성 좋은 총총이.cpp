#include <iostream>
#include <map>

using namespace std;
int N, ret;
map<string, bool> m;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    string str1, str2;

    while (N--) {
        cin >> str1 >> str2;

        if (str1 == "ChongChong")
            m.insert({str1, true});

        else if (str2 == "ChongChong")
            m.insert({str2, true});

        if (m[str1])
            m[str2] = true;

        if (m[str2])
            m[str1] = true;
    }

    for (auto &val: m) {
        if (val.second)
            ret++;
    }

    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}