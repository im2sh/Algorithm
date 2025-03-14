#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N;
map<string, string> result;
map<string, string>::iterator iter;
map<string, string> alpha =
        {{"a",  "a"},
         {"b",  "b"},
         {"k",  "c"},
         {"d",  "d"},
         {"e",  "e"},
         {"g",  "f"},
         {"h",  "g"},
         {"i",  "h"},
         {"l",  "i"},
         {"m",  "j"},
         {"n",  "k"},
         {"ng", "l"},
         {"o",  "m"},
         {"p",  "n"},
         {"r",  "o"},
         {"s",  "p"},
         {"t",  "q"},
         {"u",  "r"},
         {"w",  "s"},
         {"y",  "t"}};


void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}


void solve() {
    vector<string> seq;
    for (int i = 0; i < N; i++) {
        string S;
        string transfer = "";
        cin >> S;
        string temp = "";
        string t = "";
        t += S[0];
        temp += alpha[t];
        for (int j = 1; j < S.length(); j++) {
            if (S[j] == 'g' && S[j - 1] == 'n') {
                temp.pop_back();
                temp += alpha["ng"];
            } else {
                t = "";
                t += S[j];
                temp += alpha[t];
            }
        }
        transfer += temp;
        result[transfer] = S;
        seq.push_back(transfer);
    }
    sort(seq.begin(), seq.end());

    for (int i = 0; i < N; i++) {
        cout << result[seq[i]] << '\n';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}