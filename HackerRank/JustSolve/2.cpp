#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

vector<string> name;
vector<int> price;
vector<int> weight;
int N;
int ret = 0;

struct Element {
    string name;
    int p, w;
};

struct cmp {
    bool operator()(const Element &x1, const Element &x2) const {
        if (x1.name == x2.name)
            return x1.p < x2.p;
        return x1.w < x2.w;
    }
};

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Init() {
    string temp_s;
    int temp_price;
    int temp_weight;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp_s;
        name.push_back(temp_s);
    }

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp_price;
        price.push_back(temp_price);
    }

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp_weight;
        weight.push_back(temp_weight);
    }
}

//int solve() {
//    map<Element, int, cmp> products;
//    Element temp;
//    for (int i = 0; i < name.size(); i++) {
//        temp.name = name[i];
//        temp.p = price[i];
//        temp.w = weight[i];
//        products[temp]++;
//    }
//
//    for (auto &it: products) {
//        if (it.second > 2)
//            ret++;
//    }
//    return ret;
//
//}

int solve() {
    map<tuple<string, int, int>, int> products;
    for (int i = 0; i < name.size(); i++) {
        products[make_tuple(name[i], price[i], weight[i])]++;
    }

    for (auto &it: products) {
        if (it.second >= 2)
            ret += it.second - 1;
    }
    return ret;
}

int main(void) {
    FastIO();
    Init();
    cout << solve();
    return 0;
}

//int numDuplicates(vector<string> name, vector<int> price, vector<int> weight) {
//    int size = name.size();
//    int flag[size];
//    int ret = 0;
//    fill(&flag[0],&flag[0]+size,0);
//
//    for(int i = 0; i < size;i++){
//        for(int j = i+1; j < size; j++){
//            if(flag[i])
//                continue;
//            if(name[i] == name[j] && price[i] == price[j] && weight[i] == weight[j]){
//                flag[i] = 1;
//                ret++;
//            }
//        }
//    }
//
//    return ret;
//}