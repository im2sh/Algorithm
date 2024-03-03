#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> names;
int BOARD[51][51];
int people[51];

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    for (int i = 0; i < friends.size(); i++) {
        string name = friends[i];
        names[name] = i;
    }

    for (int i = 0; i < gifts.size(); i++) {
        string tg = gifts[i];
        int find_space = tg.find(' ');
        string from_friend = tg.substr(0, find_space);
        string to_friend = tg.substr(find_space + 1);

        int fIdx = names[from_friend];
        int tIdx = names[to_friend];
        BOARD[fIdx][tIdx]++;
        people[fIdx]++;
        people[tIdx]--;
    }


    for (int i = 0; i < friends.size(); i++) {
        int ret = 0;
        int maxGift = -1;
        int y, x;
        for (int j = 0; j < friends.size(); j++) {
            if (i == j)
                continue;
            if (BOARD[i][j] > BOARD[j][i])
                ret++;
            if (BOARD[i][j] == BOARD[j][i]) {
                if (people[i] > people[j])
                    ret++;
            }
        }
        answer = max(answer, ret);
    }
    return answer;
}