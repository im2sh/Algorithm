#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


int main(void) {
    int n;
    int t;
    string name;
    string category;
    cin >> n;

    for (int i = 0; i < n; i++) {
        map<string, int> haebin;
        cin >> t;
        for (int j = 0; j < t; j++) {
            cin >> name >> category;
            haebin[category]++;
        }
        int result = 1;

        for (auto temp: haebin) {
            result *= ((temp.second) + 1);
        }
        result--;
        cout << result << "\n";
    }
    return 0;
}
