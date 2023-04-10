#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> child;

void init_child() {
    int x;
    for (int i = 0; i < 9; i++) {
        cin >> x;
        child.push_back(x);
    }
    sort(child.begin(), child.end());
}

void print_child() {
    for (int i = 0; i < 7; i++) {
        cout << child[i] << "\n";
    }
}

int main(void) {
    init_child();
    int result;
    do {
        result = 0;
        for (int i = 0; i < 7; i++) {
            result += child[i];
        }
        if (result == 100)
            break;
    } while (next_permutation(child.begin(), child.end()));
    print_child();
    return 0;
}