#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int e[2004];
int temp;
map<int, int> check;

int solution(vector<int> elements) {
    int answer = 0;
    int init_size = elements.size();
    for (int i = 0; i < init_size; i++) {
        elements.push_back(elements[i]);
    }
    int size = elements.size();
    e[0] = 0;
    for (int i = 1; i < size; i++) {
        e[i] = e[i - 1] + elements[i];
    }

    // for(int i = 0; i < size; i++){
    //     cout << e[i] << " ";
    // }

    for (int i = 1; i <= init_size; i++) {
        for (int start = i; start <= init_size + i - 1; start++) {
            int sum = e[start] - e[start - i];
            check[sum] = 1;
            temp = max(temp, sum);
        }
    }

    for (int i = 0; i <= temp; i++) {
        if (check[i]) {
            answer++;
        }
    }

    return answer;
}