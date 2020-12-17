#pragma once
#include "header.h"

// 그래프, DFS, BFS 보충

#pragma region 90. 라이언 킹 심바(삼성 SW역량평가 기출 : BFS활용) x

void Q90() {

}
#pragma endregion

#pragma region 89. 토마토(BFS 활용)
void Q89() {
     int m, n; // 가로, 세로
     cin >> m >> n;
     vector<vector<int>> map(n, vector<int>(m));
     vector<vector<bool>> visited(n, vector<bool>(m,false));

     queue<pair<int,int>> q;

     for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
               cin >> map[i][j];

               if (map[i][j] == 1)
                    q.push({ i,j });
          }
     }
 
     while (!q.empty()) {
          int i = q.front().first;
          int j = q.front().second;
          q.pop();
          visited[i][j] = true;

          if (map[i][j] >= 1) {
               if (i + 1 < n && map[i + 1][j] == 0 && visited[i+1][j] ==false) {
                    map[i + 1][j] = map[i][j]+1;
                    q.push({ i + 1,j });
               }
                    if (i - 1 > -1 && map[i - 1][j] == 0 && visited[i-1][j] == false) {
                    map[i - 1][j] = map[i][j] + 1;
                    q.push({ i - 1,j });
               }
                    if (j + 1 < m && map[i][j + 1] == 0 && visited[i][j+1] == false) {
                    map[i][j + 1] = map[i][j] + 1;
                    q.push({ i,j +1 });
               }
                    if (j - 1 > -1 && map[i][j - 1] == 0 && visited[i][j-1] == false) {
                    map[i][j - 1] = map[i][j] + 1;
                    q.push({ i,j -1});
               }
          }
     }

      /*    cout << '\n';
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {

               cout << map[i][j] << "   ";

          }

          cout << '\n';
     }*/


     int max = 0;
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
               
               if (map[i][j] == 0) {
                    max = -1;
                    break;
               }
               
               if (map[i][j] > max)
                    max = map[i][j] - 1;
          }
     }

     cout << max;

}
#pragma endregion

#pragma region 88. 미로의 최단거리 통로(BFS 활용)
void Q88() {
     int n = 7;

     vector<vector<int>> map(n, vector<int>(n));
     vector<vector<int>> dis(n, vector<int>(n));
     int distance = 0;
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
               cin >> map[i][j];
          }
     }

     pair<int, int> start = { 0,0 };
     pair<int, int> end = { 6,6 };
     queue<pair<int, int>> q;
     q.push(start);

     while (!q.empty()) {
          auto  here = q.front();
          
          if (here == end) {
               cout << dis[here.first][here.second]<<'\n';
               break;
          }

          map[here.first][here.second] = 1;
          q.pop();
          if (here.first + 1 < n && map[here.first + 1][here.second] == 0) {
               q.push({ here.first + 1,here.second });
               dis[here.first + 1][here.second] = dis[here.first][here.second]+1;
          }
               if (here.first - 1 > -1 && map[here.first - 1][here.second] == 0) {
               q.push({ here.first - 1,here.second });
               dis[here.first - 1][here.second] = dis[here.first][here.second] + 1;

          }
               if (here.second + 1 < n && map[here.first][here.second + 1] == 0) {
               q.push({ here.first,here.second+1 });
               dis[here.first][here.second + 1] = dis[here.first][here.second] + 1;

          }
               if (here.second - 1 > -1 && map[here.first][here.second - 1] == 0) {
               q.push({ here.first,here.second - 1 });
               dis[here.first][here.second-1] = dis[here.first][here.second] + 1;
          }

     }
      

     for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
               cout << dis[i][j]<<' ';
          }
          cout << '\n';

     }

}
#pragma endregion

#pragma region 87. 섬나라 아일랜드(BFS 활용)
void Q87() {
     int n;
     int count = 2;
     cin >> n;
     vector<vector<int>> map(n, vector<int>(n));

     for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
               cin >> map[i][j];
          }
     }

     queue<pair<int, int>> q;
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
               if (map[i][j] == 1) {

                    q.push({ i,j });

                    while (!q.empty()) {
                         auto pos = q.front();
                         q.pop();

                         map[pos.first][pos.second] = count;
                         if (pos.first + 1 < n && map[pos.first + 1][pos.second] == 1) {
                              q.push({ pos.first + 1,pos.second });
                         }

                         if (pos.first - 1 > -1 && map[pos.first - 1][pos.second] == 1) {
                              q.push({ pos.first - 1,pos.second });
                         }

                         if (pos.second + 1 < n && map[pos.first][pos.second + 1] == 1) {
                              q.push({ pos.first,pos.second + 1 });

                         }
                         if (pos.second - 1 > -1 && map[pos.first][pos.second - 1] == 1) {
                              q.push({ pos.first,pos.second - 1 });
                         }
                         
                         if (pos.first + 1 < n && pos.second - 1 > -1 && map[pos.first+1][pos.second - 1] == 1) {
                              q.push({ pos.first + 1,pos.second - 1 });
                         }

                         if (pos.first + 1 < n && pos.second + 1 < n && map[pos.first+1][pos.second +1] == 1) {
                              q.push({ pos.first + 1,pos.second + 1 });
                         }

                         if (pos.first - 1 > -1 && pos.second + 1 < n && map[pos.first-1][pos.second + 1] == 1) {
                              q.push({ pos.first - 1,pos.second + 1 });
                         }

                         if (pos.first - 1 > -1 && pos.second - 1 > -1 && map[pos.first-1][pos.second - 1] == 1) {
                              q.push({ pos.first - 1,pos.second - 1 });
                         }
                    }

                    count++;
               }
          }

     }

     cout << count-2<<'\n';

}
#pragma endregion

#pragma region 86. 피자 배달 거리(삼성 SW역량평가 기출문제 : DFS활용) x
void Q86() {

}
#pragma endregion

#pragma region 85. 수식만들기(삼성 SW역량평가 기출문제 : DFS활용) x
vector<int> vec85(1);
vector<int> op85;
int n85;
int min85 = 24000000;
int max85 = 0;
void dfs85(int l, int total) {

     if (n85 == l) {
          if (total > max85) max85 = total;
          if (total < min85) min85 = total;
     }
     else {

          if (op85[0] > 0) {
               op85[0]--;
               dfs85(l + 1, total + vec85[l]);
               op85[0]++;
          }
          if (op85[1] > 0) {
               op85[1]--;
               dfs85(l + 1, total - vec85[l]);
               op85[1]++;
          }
          if (op85[2] > 0) {
               op85[2]--;
               dfs85(l + 1, total * vec85[l]);
               op85[2]++;
          }
          if (op85[3] > 0) {
               op85[3]--;
               dfs85(l + 1, total / vec85[l]);
               op85[3]++;
          }
     }


}

void Q85() {

     cin >> n85;


     for (int i = 0; i < n85; i++) {
          int num;
          cin >> num;
          vec85.push_back(num);
     }

     for (int i = 0; i < 4; i++) {
          int num;
          cin >> num;
          op85.push_back(num);
     }

     dfs85(1, vec85[0]);
     cout << max85 << '\n';
     cout << min85 << '\n';
}
#pragma endregion

#pragma region 84. 휴가(삼성 SW역량평가 기출문제 : DFS활용)   x
int max84 = 0;
int n84;
vector<pair<int, int>> vec84(1);
void dfs84(int l, int sum) {

     if (l == n84 + 1) {
          if (sum > max84)
               max84 = sum;
     }
     else {
          if (l + vec84[l].first <= n84 + 1)
               dfs84(l + vec84[l].first, sum + vec84[l].second);
          else
               dfs84(l + 1, sum);
     }
}

void Q84() {
     cin >> n84;

     for (int i = 0; i < n84; i++) {
          int a, b;
          cin >> a >> b;
          vec84.push_back({ a, b });
     }

     dfs84(1, 0);

     cout << max84;
}
#pragma endregion

#pragma region 83. 복면산 SEND+MORE=MONEY (MS인터뷰)   x 머지?
int a83[10], ch83[10];
int send83() {
     return a83[6] * 1000 + a83[1] * 100 + a83[3] * 10 + a83[0];
}
int more83() {
     return a83[2] * 1000 + a83[4] * 100 + a83[5] * 10 + a83[1];
}
int money83() {
     return a83[2] * 10000 + a83[4] * 1000 + a83[3] * 100 + a83[1] * 10 + a83[7];
}

void dfs83(int l) {
     if (l == 8) {
          if (send83() + more83() == money83()) {
               if (a83[2] == 0 || a83[6] == 0) return;
               cout << ' ' << a83[6] << a83[1] << a83[3] << a83[0] << '\n';
               cout << '+' << a83[2] << a83[4] << a83[5] << a83[1] << '\n';
               cout << "----------\n";
               cout << a83[2] << a83[4] << a83[3] << a83[1] << a83[7] << '\n';
          }
     }
     else {
          for (int i = 0; i < 10; i++) {
               if (ch83[i] == 0) {
                    a83[l] = i;
                    ch83[i] = 1;
                    dfs83(l + 1);
                    ch83[i] = 0;
               }
          }
     }
}

void Q83() {
     dfs83(0);

}
#pragma endregion

#pragma region 82. 순열구하기(DFS : Depth First Search)
int cnt82 = 0;
void dfs82(int l, int r, int i, vector<int> vec, vector<int> answer, vector<bool> visited) {
     if (l == r + 1) {

          for (auto v : answer)
               cout << v << ' ';
          cout << '\n';
          cnt82++;
     }
     else {
          if (visited[i] == false) {
               visited[i] = true;

               if (i != 0)
                    answer.push_back(vec[i]);

               for (int ii = 1; ii < vec.size(); ii++) {
                    if (visited[ii] == false)
                         dfs82(l + 1, r, ii, vec, answer, visited);
               }
          }
     }
}

void Q82() {
     int n, r;
     cin >> n >> r;
     vector<int> vec(1);
     vector<int> answer;
     vector<bool> visited(n + 1, false);

     for (int i = 0; i < n; i++) {
          int num;
          cin >> num;
          vec.push_back(num);
     }

     dfs82(0, r, 0, vec, answer, visited);

     cout << cnt82;

}
#pragma endregion

#pragma region 81. 벨만-포드 알고리즘 x
void Q81() {

}
#pragma endregion

#pragma region 80. 다익스트라 알고리즘
struct Edge80 {
     int vex;
     int dis;
     Edge80(int a, int b) {
          vex = a;
          dis = b;
     }

     bool operator<(const Edge80& b)const {
          return dis > b.dis;
     }
};

void Q80() {
     priority_queue<Edge80> Q;
     vector<pair<int, int>> graph[30];
     int i, n, m, a, b, c;
     cin >> n >> m;
     vector<int> dist(n + 1, 2147000000);

     for (i = 1; i <= m; i++) {
          cin >> a >> b >> c;
          graph[a].push_back({ b,c });
     }

     Q.push(Edge80(1, 0));
     dist[1] = 0;

     while (!Q.empty()) {
          int now = Q.top().vex;
          int cost = Q.top().dis;
          Q.pop();

          if (cost > dist[now]) continue;
          for (i = 0; i < graph[now].size(); i++) {
               int next = graph[now][i].first;
               int nextDis = cost + graph[now][i].second;
               if (dist[next] > nextDis) {
                    dist[next] = nextDis;
                    Q.push(Edge80(next, nextDis));
               }
          }
     }

     for (i = 2; i <= n; i++) {
          if (dist[i] != 2147000000)
               cout << i << " : " << dist[i] << endl;
          else
               cout << i << " : impossible" << endl;
     }

}
#pragma endregion

#pragma region 79. 원더랜드 : Prim MST(최소스패닝트리) 알고리즘 : priority_queue 활용
class edge79 {
public:
     int from;
     int to;
     int val;

     edge79(int f, int t, int v) : from(f), to(t), val(v) {}

     bool operator<(const edge79& e)const {
          return val > e.val;
     }
};

void Q79() {
     int v, e;
     cin >> v >> e;
     vector<vector<pair<int, int>>> map(v + 1);
     vector<bool> visited(v + 1, false);
     priority_queue<edge79> q;
     int min = 0;
     for (int i = 0; i < e; i++) {
          int a, b, c;
          cin >> a >> b >> c;

          map[a].push_back({ b,c });
          map[b].push_back({ a,c });
     }

     q.push(edge79(0, 1, 0));

     while (!q.empty()) {
          edge79 e = q.top();
          q.pop();

          if (visited[e.to] == false) {
               min += e.val;
               visited[e.to] = true;

               for (int i = 0; i < map[e.to].size(); i++) {
                    if (visited[map[e.to][i].first] == false) {
                         q.push(edge79(e.to, map[e.to][i].first, map[e.to][i].second));
                    }
               }
          }

     }

     cout << min;

}
#pragma endregion

#pragma region 78. 원더랜드 : Kruskal MST(최소스패닝트리) 알고리즘 : Union & Find 활용

class edge78 {
public:
     int from;
     int to;
     int value;

     edge78(int f, int t, int v) : from(f), to(t), value(v) {}
};

bool edgeCompare78(edge78 e1, edge78 e2) {
     if (e1.value < e2.value)
          return true;
     else
          return false;
}

void Q78() {
     int v, e;
     cin >> v >> e;

     vector<edge78> edgeList;
     vector<int> vertex_union(v + 1);
     int answer = 0;
     for (int i = 1; i < v + 1; i++)
          vertex_union[i] = i;

     for (int i = 1; i <= e; i++) {
          int a, b, c;
          cin >> a >> b >> c;

          edgeList.push_back(edge78(a, b, c));
     }

     sort(edgeList.begin(), edgeList.end(), edgeCompare78);

     for (auto edge : edgeList) {
          if (vertex_union[edge.from] != vertex_union[edge.to]) {
               answer += edge.value;
               int max = vertex_union[edge.from] > vertex_union[edge.to] ? vertex_union[edge.from] : vertex_union[edge.to];
               int min = vertex_union[edge.from] < vertex_union[edge.to] ? vertex_union[edge.from] : vertex_union[edge.to];

               for (int i = 1; i <= v; i++) {
                    if (vertex_union[i] == max)
                         vertex_union[i] = min;
               }
          }
     }

     cout << answer;
}
#pragma endregion

#pragma region 77. 친구인가?(Disjoint-set : Union&Find 알고리즘)  교재

int unf77_2[1001];
int Find77_2(int v) {
     if (v == unf77_2[v]) return v;
     else return unf77_2[v] = Find77_2(unf77_2[v]);
}

void Union77_2(int a, int b) {
     a = Find77_2(a);
     b = Find77_2(b);
     if (a != b) unf77_2[a] = b;
}

void Q77_2() {
     int n, m, a, b;
     cin >> n >> m;

     for (int i = 1; i <= n; i++) {
          unf77_2[i];
     }

     for (int i = 1; i <= m; i++) {
          cin >> a >> b;
          Union77_2(a, b);
     }

     cin >> a >> b;
     a = Find77_2(a);
     b = Find77_2(b);
     if (a == b) cout << "YES";
     else cout << "NO";

}
#pragma endregion
#pragma region 77. 친구인가?(Disjoint-set : Union&Find 알고리즘)  내풀이
void Q77() {
     int n, m;
     int s1, s2;
     cin >> n >> m;
     vector<int> vec(n + 1);

     for (int i = 0; i <= n; i++)
          vec[i] = i;

     for (int i = 0; i < m; i++) {
          int c1, c2;
          cin >> c1 >> c2;

          int min = vec[c1] < vec[c2] ? vec[c1] : vec[c2];
          int max = vec[c1] > vec[c2] ? vec[c1] : vec[c2];
          for (int i = 0; i <= n; i++) {
               if (vec[i] == max)
                    vec[i] = min;
          }
     }

     cin >> s1 >> s2;
     if (vec[s1] == vec[s2])
          cout << "YES";
     else
          cout << "NO";

}
#pragma endregion

#pragma region 76. 이항계수(메모이제이션)    DFS

int DFS76_2(int n, int r) {
     if (n == r || r == 0) return 1;
     else return DFS76_2(n - 1, r - 1) + DFS76_2(n - 1, r);
}
void Q76_2() {
     int n, r;
     cin >> n >> r;

     cout << DFS76_2(n, r);

}

#pragma endregion
#pragma region 76. 이항계수(메모이제이션)   내풀이
void Q76() {
     int n, r;
     int nn = 1, rr = 1;
     cin >> n >> r;

     for (int i = n; i >= r; i--)
          nn *= i;
     for (int i = 1; i <= r; i++)
          rr *= i;

     cout << nn / rr;

}

#pragma endregion


