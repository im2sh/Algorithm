#include <iostream>
#include <stack>

using namespace std;

long long N, temp, ret;
stack<pair<long long, long long>> st;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    for (int i = 0; i < N; i++) {
        cin >> temp;
        int cnt = 1;
        while (st.size() && st.top().first <= temp) {
            ret += st.top().second;
            if (st.top().first == temp)
                cnt = st.top().second + 1;
            else
                cnt = 1;

            st.pop();
        }

        if (st.size())
            ret++;
        st.push({temp, cnt});
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    cout << ret << "\n";
    return 0;
}

#include <iostream>
#include <stack>

using namespace std;
typedef long long ll;

ll N, temp;
stack<pair<ll, ll>> st;
ll ret = 0;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N;
}

void solve() {
    for (int i = 0; i < N; i++) {
        cin >> temp;
        int cnt = 1;
        while (st.size() && st.top().first <= temp) {
            ret += st.top().second;
            if (st.top().first == temp) {
                cnt = st.top().second + 1;
            } else {
                cnt = 1;
            }
            st.pop();
        }
        if (st.size()) ret++;
        st.push({temp, cnt});
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    cout << ret << "\n";
    return 0;
}