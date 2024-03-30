#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, int> name;
int BOARD[1001][1001];
map<int, int> score;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    int N = id_list.size();

    for (int i = 0; i < id_list.size(); i++) {
        name[id_list[i]] = i;
    }

    for (int i = 0; i < report.size(); i++) {
        int idx = report[i].find(" ");
        string first = report[i].substr(0, idx);
        string second = report[i].substr(idx + 1, report[i].size());

        BOARD[name[first]][name[second]] = 1;
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (BOARD[x][y] == 1) {
                score[y]++;
            }
        }
    }

    for (int y = 0; y < N; y++) {
        int cnt = 0;
        for (int x = 0; x < N; x++) {
            if (BOARD[y][x] == 1 && score[x] >= k)
                cnt++;
        }
        answer.push_back(cnt);
    }
    return answer;
}