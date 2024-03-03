#include <iostream>
#include <string>
#include <vector>

using namespace std;
int N = -1;
int centerNode;
vector<int> graph[1000001];
int indegree[1000001];
int outdegree[1000001];

void init(vector<vector<int>> edges) {
    for (int i = 0; i < edges.size(); i++) {
        outdegree[edges[i][0]]++;
        indegree[edges[i][1]]++;

        N = max(N, max(edges[i][0], edges[i][1]));
    }
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0 && outdegree[i] >= 2)
            centerNode = i;
    }

    for (int i = 0; i < edges.size(); i++) {
        if (centerNode == edges[i][0])
            indegree[edges[i][1]]--;
    }
}

bool isLine(int node) {
    if (indegree[node] == 1 && outdegree[node] == 0)
        return true;
    else if (indegree[node] == 0 && outdegree[node] == 0)
        return true;
    return false;
}

bool isDonut(int node) {
    if (indegree[node] == 2 && outdegree[node] == 2)
        return true;
    return false;
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    answer.assign(4, 0);

    init(edges);
    answer[0] = centerNode;

    for (int i = 1; i <= N; i++) {
        if (isLine(i))
            answer[2]++;
        else if (isDonut(i))
            answer[3]++;
    }
    answer[1] = outdegree[answer[0]] - (answer[2] + answer[3]);

    return answer;
}