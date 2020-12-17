#pragma once
#include <stack>
#include <unordered_map>
#include <sstream>
#include <map>
#include <math.h>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#pragma region 12900 2 x n 타일링  
int solution12900(int n) {
    int answer = 0;
    vector<int> v(n + 1, 0);
    v[1] = 1;
    v[2] = 2;

    for (int i = 3; i < n + 1; i++) {
        v[i] = (v[i - 2] + v[i - 1])% 1000000007;
    }

    return answer = v[n];
}
#pragma endregion
#pragma region 43162 네트워크  
int findParent43162(int a, vector<int> &nodes) {
    if (nodes[a] == a)
        return a;
    else
        return nodes[a] = findParent43162(nodes[a], nodes);
}

void untionNode43162(int a, int b, vector<int>& nodes) {
    a = findParent43162(a,nodes);
    b = findParent43162(b,nodes);

    if (a > b)
        nodes[a] = b;
    else
        nodes[b] = a;
}

int solution43162(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> nodes(n);

    for (int i = 0; i < n; i++)
        nodes[i] = i;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (computers[i][j] == 1 && findParent43162(i,nodes) != findParent43162(j,nodes)) {
                
                untionNode43162(i, j,nodes);
            }
        }
    }

    answer = n;
    for (int i = 0; i < n; i++)
        if (i != findParent43162(i, nodes))
            answer--;

    return answer;
}
#pragma endregion
#pragma region 42861 섬 연결하기  
int findParent42861(int a, vector<int> &nodes) {
    if (a == nodes[a])
        return a;
    else return nodes[a] = findParent42861(nodes[a],nodes);
}

void unionNodes42861(int a, int b, vector<int>& nodes) {
    a = findParent42861(a,nodes);
    b = findParent42861(b, nodes);

    if (a > b)
        nodes[a] = b;
    else
        nodes[b] = a;
}

int solution42861(int n, vector<vector<int>> costs) {
    int answer = 0;
    priority_queue<pair<int, pair<int, int>>> q;
    vector<int> nodes(n);

    for (int i = 0; i < n; i++)
        nodes[i] = i;
    for (auto v : costs) 
        q.push({ -v[2],{v[0],v[1]} });
    
    while (!q.empty()) {
        int a = q.top().second.first;
        int b = q.top().second.second;
        int v = -q.top().first;
        q.pop();

        if (findParent42861(a,nodes) != findParent42861(b,nodes)) {
            answer += v;
            unionNodes42861(a, b,nodes);
        }
    }

    return answer;
}
#pragma endregion

#pragma region 49189 가장 먼 노드
int solution49189(int n, vector<vector<int>> edge) {
    int answer = 0;
    const int INF = 987654321;
    vector<int> dist(n + 1, 987654321);
    vector<vector<pair<int,int>>> graph(n + 1);
    priority_queue < pair<int, int>> q;

    for (auto a : edge) {
        graph[a[0]].push_back({ a[1],1 });
        graph[a[1]].push_back({ a[0],1 });
    }

    q.push({ 0,1 });
    dist[1] = 0;
    while (!q.empty()) {
        int now = q.top().second;
        int d = -q.top().first;
        q.pop();
        if (dist[now] < d) continue;


        for (int i = 0; i < graph[now].size(); i++) {
            int newDist = d + graph[now][i].second;
            int newNode = graph[now][i].first;

            if (dist[newNode] > newDist) {
                q.push({ -newDist,newNode });
                dist[newNode] = newDist;
            }
        }
    }

    int max = 0;
    for (int a : dist)
        if (a != INF && a > max)
            max = a;

    answer = count(dist.begin(), dist.end(), max);

    return answer;
}
#pragma endregion

#pragma region sol  
void sol3() {
}
#pragma endregion

