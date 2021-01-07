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
#pragma region 12914 멀리 뛰기
long long solution12914(int n) {
    vector<int> v(n + 1);
    v[1] = 1;
    v[2] = 2;

    for (int i = 3; i < n + 1; i++) {
        v[i] = (v[i - 2] + v[i - 1]) % 1234567;
    }

    return v[n];
}
#pragma endregion
#pragma region 42898 등굣길  
int solution42898(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> v(n, vector<int>(m, 0));

    v[0][0] = 1;

    for (vector<int> p : puddles) 
        v[p[1]-1][p[0]-1] = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) continue;

            if (v[i][j] != -1) {
                int u =  j - 1 > -1 && v[i][j-1] != -1  ? v[i][j-1] : 0;
                int l =  i - 1 > -1 && v[i-1][j] != -1  ? v[i-1][j] : 0;
                v[i][j] = (u + l) % 1000000007;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }

    return v[n-1][m-1];
}
#pragma endregion
#pragma region 12946 하노이의 탑  
void hanoi(int n,int from,int by, int to, vector<vector<int>> &answer) {
    if (n == 1) {
        answer.push_back({ from,to });
    }
    else {
        hanoi(n - 1, from, to, by,answer);
        answer.push_back({ from, to });
        hanoi(n - 1, by, from, to,answer);
    }
}

vector<vector<int>> solution12946(int n) {
    vector<vector<int>> answer;

    hanoi(n, 1, 2, 3, answer);

    return answer;
}
#pragma endregion
#pragma region 43105 정수 삼각형  
int func43105(int x,int y, vector<vector<int>> &triangle, vector<vector<int>> &dp) {
    
    if (dp[x][y] != -1)
        return dp[x][y];
    
    if (x == triangle.size()-1) {
        dp[x][y] = triangle[x][y];
        return dp[x][y];
    }
    else {
        return dp[x][y] = max(func43105(x+1, y, triangle, dp), func43105(x+1, y + 1, triangle, dp)) + triangle[x][y];
    }
}

int solution43105(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> dp(triangle.size(),vector<int>(triangle.back().size(),-1));
    func43105(0, 0, triangle, dp);

    answer = dp[0][0];

    return answer;
}
#pragma endregion
#pragma region 42628 이중우선순위큐  
vector<int> solution42628(vector<string> operations) {
    vector<int> answer;
    deque<int> d;

    for (string op : operations) {
        char c;
        bool neg = false;
        int num = 0;

        for (int i = 0; i < op.size(); i++) {
            if (i == 0) c = op[i];
            else if (op[i] == '-')
                neg = true;
            else if (op[i] >= '0' && op[i] <= '9')
                num = num * 10 + op[i] - '0';
        }

        if (neg)
            num *= -1;

        if (c == 'I') {
            d.push_back(num);
            sort(d.begin(), d.end());
        }
        else {
            if (!d.empty()) {
                if (num > 0) {
                    d.pop_back();
                }
                else {
                    d.pop_front();
                }
            }
        }
    }

    if (d.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(d.back());
        answer.push_back(d.front());
    }

    return answer;
}
#pragma endregion
#pragma region 12978 배달  
int solution12978(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    int INF = 9999;
    vector<vector<pair<int, int>>> _map(N + 1);
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>> q;
    dist[1] = 0;
    q.push({ 0,1 });

    for (auto arr : road) {
        _map[arr[0]].push_back({ arr[1],arr[2] });
        _map[arr[1]].push_back({ arr[0],arr[2] });
    }

    while (!q.empty()) {
        int node = q.top().second;
        int d = -q.top().first;
        q.pop();

        if (d > dist[node]) continue;

        for (int i = 0; i < _map[node].size(); i++) {
            int newNode = _map[node][i].first;
            int newDist = _map[node][i].second + d;
            
            if (dist[newNode] > newDist) {
                dist[newNode] = newDist;
                q.push({ -newDist,newNode });
            }
        }
    }

    for (int d : dist) {
        if (d <= K)
            answer++;
    }

    return answer;
}
#pragma endregion

/*
    2차원 배열로 풀었으나 시간초과
    1차원 배열로 풀어야함. 어려웠음.
*/
#pragma region 12952 N - Queen
void func12952(int n, int x, vector<int> &col,int &answer) {
    if (n == x) {
        answer++;
    }
    else {
        for (int i = 0; i < n; i++) {
            col[x] = i;

            bool canLocate = true;
            for (int j = 0; j < x; j++) {
                if (col[x] == col[j] || abs(col[x]-col[j]) ==abs(x-j)) {
                    canLocate = false;
                    break;
                }
            }

            if (canLocate)
                func12952(n, x + 1, col, answer);

        }
    }
}

int solution12952(int n) {
    int answer = 0;
    vector<int> col(n,0);
    func12952(n, 0, col, answer);

    return answer;
}
#pragma endregion



#pragma region sol  
void sol3() {
}
#pragma endregion

