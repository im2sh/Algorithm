#include <iostream>
#include <map>

using namespace std;

int N;
string A, B;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
    cin >> A;
    cin >> B;
}

bool checkRearrangement() {
    int AC[26];
    int BC[26];
    fill(&AC[0], &AC[0] + 26, 0);
    fill(&BC[0], &BC[0] + 26, 0);

    for (int i = 0; i < N; i++) {
        AC[A[i] - 97]++;
        BC[B[i] - 97]++;
    }

    for (int i = 0; i < 26; i++) {
        if (AC[i] != BC[i])
            return false;
    }
    return true;
}

bool checkFirstLast() {
    if (A[0] != B[0] || A[N - 1] != B[N - 1])
        return false;
    return true;
}

bool checkVowel() {
    string removedA = "";
    string removedB = "";
    map<char, bool> dict;
    dict['a'] = true, dict['e'] = true, dict['i'] = true, dict['o'] = true, dict['u'] = true;
    for (int i = 0; i < N; i++) {
        if (dict[A[i]])
            continue;
        removedA += A[i];
    }

    for (int i = 0; i < N; i++) {
        if (dict[B[i]])
            continue;
        removedB += B[i];
    }

    if (removedA != removedB)
        return false;
    return true;
}


void solve() {
    if (checkRearrangement() && checkFirstLast() && checkVowel())
        cout << "YES";
    else
        cout << "NO";
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}