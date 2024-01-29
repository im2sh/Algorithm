#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M, ret;
vector<int> plusBook;
vector<int> minusBook;
vector<int> books;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool cmp(int a, int b) {
    return a > b;
}

void Init() {
    int temp;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (temp > 0)
            plusBook.push_back(temp);
        else
            minusBook.push_back(temp);
    }
    sort(plusBook.begin(), plusBook.end(), cmp);
    sort(minusBook.begin(), minusBook.end());
}

void solve() {
    for (int i = 0; i < plusBook.size(); i += M) {
        books.push_back(plusBook[i]);
    }
    for (int i = 0; i < minusBook.size(); i += M) {
        books.push_back(abs(minusBook[i]));
    }
    sort(books.begin(), books.end(), cmp);
    for (int i = 0; i < books.size(); i++) {
        if (i == 0)
            ret += books[i];
        else
            ret += books[i] * 2;
    }
    cout << ret;
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}