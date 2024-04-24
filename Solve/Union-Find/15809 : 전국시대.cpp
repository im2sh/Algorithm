#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct country {
    int parent;
    int people;
} Country;
int N, M;
Country country[100004];
vector<int> ret;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int temp = 0;
        cin >> temp;
        country[i] = {i, temp};
    }
}

int getParent(int x) {
    if (country[x].parent == x)
        return x;
    return country[x].parent = getParent(country[x].parent);
}

void union_parent(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    int people = country[a].people + country[b].people;
    if (a < b) {
        country[b] = {a, 0};
        country[a] = {a, people};
    } else {
        country[a] = {b, 0};
        country[b] = {b, people};
    }
}

void loseCountry(int win, int lose) {
    country[win].people = country[win].people - country[lose].people;
    country[lose].parent = country[win].parent;
    country[lose].people = 0;
}


void solve() {
    int command, a, b;
    for (int i = 0; i < M; i++) {
        cin >> command >> a >> b;
        if (command == 1) {
            if (country[getParent(a)].people == 0 || country[getParent(b)].people == 0)
                continue;
            union_parent(a, b);
        } else {
            int ap = getParent(a);
            int bp = getParent(b);
            if (country[ap].people > country[bp].people) {
                loseCountry(ap, bp);
            } else if (country[ap].people < country[bp].people) {
                loseCountry(bp, ap);
            } else {
                country[ap].people = 0;
                country[bp].people = 0;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        if (country[i].people != 0)
            ret.push_back(country[i].people);
    }
    sort(ret.begin(), ret.end());
    cout << ret.size() << '\n';
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << ' ';
    }
}

int main(void) {
    FastIO();
    Init();
    solve();
    return 0;
}