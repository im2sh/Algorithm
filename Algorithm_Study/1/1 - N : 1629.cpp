#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
ll A, B, C;
ll result = 0;

ll multi(ll a, ll b) {
    if (b == 1)
        return a % C;
    result = multi(a, b / 2);
    result = (result * result) % C;
    if (b % 2 == 1)
        result = (result * a) % C;
    return result;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> C;
    cout << multi(A, B) << "\n";
    return 0;
}