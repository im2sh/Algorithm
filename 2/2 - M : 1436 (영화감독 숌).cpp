#include <iostream>
#include <string>

using namespace std;

int N;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int i = 666;
    for (;; i++) {
        if (to_string(i).find("666") != string::npos)
            N--;
        if (!N)
            break;
    }
    cout << i << "\n";
    return 0;
}