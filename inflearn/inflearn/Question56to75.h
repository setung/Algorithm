#pragma once
#include "header.h"

//재귀 & 깊이/넓이 우선탐색(DFS, BFS)


#pragma region 75. 최대 수입 스케쥴(priority queue greedy: 구조체와 Vector를 이용한 정렬)
struct Data75 {
     int money;
     int when;
     Data75(int a, int b) {
          money = a;
          when = b;
     }

     bool operator<(Data75& b) {
          return when > b.when;
     }
};

void Q75() {
     int n, d, m, max = -99999, res = 0;;
     cin >> n ;
     vector<Data75> v;
     priority_queue<int> q;

     for (int i = 0; i < n; i++) {
          cin >> d >> m;
          v.push_back(Data75(d, m));
          
          if (m > max)
               max = m;
     }

     sort(v.begin(), v.end());

     for (int i = max; i >= 1; i--) {
          for (int j = 0; j < n; j++) {
               if (v[j].when < i) break;
               q.push(v[j].money);
          }
          if (!q.empty()) {
               res += q.top();
               q.pop();
          }
     }
     
     cout << res;

}
#pragma endregion

#pragma region 74. 최소힙(STL priority_queue : 우선순위큐)
void Q74() {
     priority_queue<int> q;

     while (1) {
          int n;
          cin >> n;

          if (n == -1) {
               break;
          }
          else if (n == 0) {
               if (q.empty()) continue;

               cout << -q.top();
               q.pop();
          }
          else {
               q.push(-n);
          }
     }
}
#pragma endregion

#pragma region 73. 최대힙(priority_queue : 우선순위 큐)
void Q73() {
     priority_queue<int> q;

     while (1) {
          int n;
          cin >> n;

          if (n == -1) {
               break;
          }
          else if (n == 0) {
               if (q.empty()) continue;

               cout << q.top();
               q.pop();
          }
          else {
               q.push(n);
          }
     }
}
#pragma endregion

#pragma region 72. 공주 구하기(큐 자료구조로 해결)
void Q72() {
     int n, k;
     cin >> n >> k;
     queue<int> q;

     for (int i = 0; i < n; i++) {
          q.push(i + 1);
     }

     int count = 1;
     while (q.size()!=1) {
          int v = q.front();
          q.pop();

          if (count != k) {
               q.push(v);
               count++;
          }
          else
               count = 1;

     }

     cout << q.front();

     
}
#pragma endregion

#pragma region 71. 송아지 찾기 (BFS : 상태트리탐색) 
void Q71() {

     int s, e;
     cin >> s >> e;
     vector<int> v = { 5,-1,1 };
     queue<pair<int,int>> q;
     vector<bool> visited(10001, false);

     visited[s] = true;

     q.push({ s,0 });

     while (!q.empty()) {
          
          pair<int,int> val = q.front();

          if (val.first == e) {
               cout << val.second;
               break;
          }

          q.pop();

          for (int i = 0; i < 3; i++) {
               if (val.first + v[i] < 10001 && val.first + v[i] > -1 && !visited[val.first + v[i]]) {
                    q.push({val.first + v[i],val.second +1});
                    visited[val.first + v[i]] = true;
               }
          }
     }
}
#pragma endregion

#pragma region 70. 그래프 최단거리 (BFS : Breadth First Search )
void Q70() {
     int n, m;
     cin >> n >> m;
     vector<vector<int>> mat(n);
     vector<int> visited(n, -1);
     queue<int> q;

     for (int i = 0; i < m; i++) {
          int x, y;
          cin >> x >> y;
          mat[x - 1].push_back(y - 1);
     }

     q.push(0);
     visited[0] = 0;
     while (!q.empty()) {

          int v = q.front();
          q.pop();

          for (int i = 0; i < mat[v].size(); i++) {
               if (visited[mat[v][i]] == -1) {

                    visited[mat[v][i]] = visited[v] + 1;
                    q.push(mat[v][i]);
               }
          }

     }

     for (int i = 1; i < visited.size(); i++)
          cout << i + 1 << " : " << visited[i] << '\n';
}
#pragma endregion

#pragma region 68. 최소비용(DFS : 가중치 방향그래프 인접리스트)
vector<vector<pair<int, int>>> mat68;
vector<bool> visited68;
int min68 = 99999;

void dfs68(int v, int n, vector<bool> visited, int sum) {
     if (v == n - 1) {
          if (min68 > sum)
               min68 = sum;
     }
     else {

          visited[v] = true;

          for (int i = 0; i < mat68[v].size(); i++) {
               if (visited[mat68[v][i].first] == false) {
                    dfs68(mat68[v][i].first, n, visited, sum + mat68[v][i].second);
               }
          }
     }
}

void Q68() {
     int n, m;
     cin >> n >> m;
     mat68 = vector<vector<pair<int, int>>>(n);
     visited68 = vector<bool>(n, false);
     for (int i = 0; i < m; i++) {
          int x, y, val;
          cin >> x >> y >> val;

          mat68[x - 1].push_back({ y - 1,val });
     }

     dfs68(0, n, visited68, 0);

     cout << min68;
}
#pragma endregion

#pragma region 67. 최소 비용 (그래프 DFS 인접행렬)
vector<vector<int>> mat67;
vector<bool> visited67;
int min67 = 99999;
void dfs67(int v, int n, vector<bool> visited, int sum) {

     if (v == n - 1) {
          if (sum < min67)
               min67 = sum;
     }
     else {
          visited[v] = true;
          for (int j = 0; j < n; j++) {
               if (mat67[v][j] != -1 && visited[j] == false) {
                    dfs67(j, n, visited, sum + mat67[v][j]);
               }
          }
     }

}

void Q67() {
     int n, m;
     cin >> n;
     cin >> m;

     mat67 = vector<vector<int>>(n, vector<int>(n, -1));
     visited67 = vector<bool>(n, false);

     for (int i = 0; i < m; i++) {
          int x, y, val;
          cin >> x >> y >> val;
          mat67[x - 1][y - 1] = val;
     }

     dfs67(0, n, visited67, 0);

     cout << min67;

}
#pragma endregion

#pragma region 66. 경로탐색 (방향그래프 인접 리스트: used Vector)
vector<vector<int>> mat66;
vector<bool> visited66;
int count66 = 0;

void dfs66(int v, int n, vector<bool> visited) {
     if (v == n) {
          count66++;
     }
     else {

          visited[v] = true;

          for (int i = 0; i < mat66[v].size(); i++) {
               if (!visited[mat66[v][i]]) {
                    dfs66(mat66[v][i], n, visited);
               }
          }
     }
}

void Q66() {
     int n, m;
     cin >> n >> m;

     mat66 = vector<vector<int>>(n + 1);
     visited66 = vector<bool>(n + 1, false);

     for (int i = 0; i < m; i++) {
          int x, y;
          cin >> x >> y;

          mat66[x].push_back(y);
     }

     dfs66(1, n, visited66);

     cout << count66;
}
#pragma endregion

#pragma region 65. 미로탐색(DFS)
vector<vector<int>> mat65(7, vector<int>(7));
pair<int, int> start65 = { 0,0 };
pair<int, int> end65 = { 6,6 };
int count65 = 0;

bool isRoot65(vector<vector<int>> mat, int x, int y) {
     if ((x > -1 && x < 7) && (y > -1 && y < 7) && mat[y][x] == 0)
          return true;
     else
          return false;
}

void dfs65(pair<int, int> here, vector<vector<int>> mat) {
     if (here == end65) {
          count65++;
          return;
     }
     else {

          mat[here.second][here.first] = 1;

          if (isRoot65(mat, here.first + 1, here.second))  dfs65({ here.first + 1, here.second }, mat);
          if (isRoot65(mat, here.first - 1, here.second))  dfs65({ here.first - 1, here.second }, mat);
          if (isRoot65(mat, here.first, here.second + 1))  dfs65({ here.first, here.second + 1 }, mat);
          if (isRoot65(mat, here.first, here.second - 1))  dfs65({ here.first , here.second - 1 }, mat);
     }
}

void Q65() {

     for (int i = 0; i < 7; i++)
          for (int j = 0; j < 7; j++) {
               int n;
               cin >> n;
               mat65[i][j] = n;
          }

     dfs65(start65, mat65);

     cout << count65;

}
#pragma endregion

#pragma region 64. 경로탐색 (그래프 DFS : Depth First Search)
int count64 = 0, n64;
vector<vector<int>> mat64;
vector<bool> bMat64;
void dfs64(int v) {

     bMat64[v] = true;

     if (v == n64 - 1) {
          count64++;
     }
     else {
          for (int i = 0; i < n64; i++) {
               if (mat64[v][i] == 1 && bMat64[i] == false) {
                    bMat64[i] = true;
                    dfs64(i);
                    bMat64[i] = false;
               }
          }
     }
}

void Q64() {
     int m;
     cin >> n64 >> m;
     mat64 = vector<vector<int>>(n64, vector<int>(n64, 0));
     bMat64 = vector<bool>(n64, false);

     for (int i = 0; i < m; i++) {
          int x, y;
          cin >> x >> y;
          mat64[x - 1][y - 1] = 1;
     }


     dfs64(0);

     cout << count64;
}
#pragma endregion

#pragma region 63. 인접행렬(가중치 방향그래프)
void Q63() {
     int n, m;
     cin >> n >> m;
     vector<vector<int>> mat(n, vector<int>(n, 0));

     for (int i = 0; i < m; i++) {
          int x;
          int y;
          int val;

          cin >> x >> y >> val;

          mat[x - 1][y - 1] = val;
     }

     for (auto v : mat) {
          for (auto a : v) {
               cout << a << ' ';
          }
          cout << '\n';
     }
}
#pragma endregion 

#pragma region 62. 병합정렬 (분할 정복)    버그있음.
vector<int> temp62;
vector<int> data62;
void divide62(int lt, int rt) {
     int mid;
     int p1, p2, p3;

     if (lt < rt) {
          mid = (lt + rt) / 2;
          divide62(lt, mid);
          divide62(mid + 1, rt);

          p1 = lt;
          p2 = mid + 1;
          p3 = lt;

          while (p1 <= mid && p2 <= rt) {
               if (data62[p1] < data62[p2])
                    temp62[p3++] = data62[p1++];
               else
                    temp62[p3++] = data62[p2++];
          }

          while (p1 <= mid)
               temp62[p3++] = data62[p1++];
          while (p2 <= rt)
               temp62[p3++] = data62[p2++];


          for (int i = lt; i < rt; i++) {
               data62[i] = temp62[i];
          }

     }
}

void Q62() {
     int n;
     cin >> n;

     for (int i = 0; i < n; i++) {
          int num;
          cin >> num;
          data62.push_back(num);
     }
     temp62.resize(n);

     divide62(0, n - 1);

     for (int i = 0; i < data62.size(); i++) {
          cout << data62[i] << ' ';
     }

}
#pragma endregion

#pragma region 61. 특정 수 만들기(DFS : MS 인터뷰)    내풀이
int n61_2;
int m61_2;
int count61_2 = 0;
vector<int> v61_2(1, 0);
vector<int> path(30);
void dfs61_2(int l, int sum) {

     if (l == n61_2) {
          if (sum == m61_2) {
               count61_2++;
               for (int i = 0; i < l; i++)
                    cout << path[i] << ' ';
               cout << '\n';
          }

          return;
     }
     else {
          path[l] = v61_2[l + 1];
          dfs61_2(l + 1, sum + v61_2[l + 1]);
          path[l] = -v61_2[l + 1];
          dfs61_2(l + 1, sum - v61_2[l + 1]);
          path[l] = 0;
          dfs61_2(l + 1, sum);
     }
}

void Q61_2() {
     cin >> n61_2 >> m61_2;

     for (int i = 0; i < n61_2; i++) {
          int num;
          cin >> num;
          v61_2.push_back(num);
     }

     dfs61_2(0, 0);

     if (count61_2 == 0)
          count61_2--;
     cout << count61_2;

}
#pragma endregion
#pragma region 61. 특정 수 만들기(DFS : MS 인터뷰)
int count61 = 0;
int totalSum61;
vector<int> v61;
void dfs61(int d, int sum) {

     if (d == v61.size()) {
          if (sum == totalSum61)
               count61++;
          return;
     }

     dfs61(d + 1, sum + v61[d]);
     dfs61(d + 1, sum - v61[d]);
     dfs61(d + 1, sum);

}
void Q61() {
     int n;

     cin >> n >> totalSum61;
     v61.resize(n);

     for (int i = 0; i < n; i++) {
          int in;
          cin >> in;
          v61[i] = in;
     }


     dfs61(0, 0);

     if (count61 == 0)
          cout << -1;
     else
          cout << count61;

}
#pragma endregion

#pragma region  60. 합이 같은 부분집합(DFS : 아마존 인터뷰)    내풀이
int n60_2;
vector<int> vi60_2(1, 0);
vector<bool> vb60_2(1, false);
bool isYes60_2 = false;
int total = 0;
void dfs60_2(int l, vector<int> vi, vector<bool> vb, bool b) {

     if (isYes60_2)
          return;

     // 마지막
     if (l == n60_2 + 1) {
          int sum = 0;
          for (int i = 1; i < vi.size(); i++) {
               if (vb[i])
                    sum += vi[i];
          }
          if (total == sum * 2) {
               isYes60_2 = true;
               return;
          }
     }
     else {
          vb[l] = b;

          dfs60_2(l + 1, vi, vb, true);
          dfs60_2(l + 1, vi, vb, false);
     }


}

void Q60_2() {
     cin >> n60_2;

     for (int i = 0; i < n60_2; i++) {
          int num;
          cin >> num;
          vi60_2.push_back(num);
          vb60_2.push_back(false);
          total += num;
     }

     dfs60_2(0, vi60_2, vb60_2, false);

     if (isYes60_2)
          cout << "YES";
     else
          cout << "NO";
}
#pragma endregion
#pragma region 60. 합이 같은 부분집합(DFS : 아마존 인터뷰)   해답 참신
vector<int> v60;
bool isYes60 = false;
int totalSum60 = 0;
void dfs60(int depth, int sum) {

     if (isYes60 == true || depth == v60.size()) {
          return;
     }

     if (totalSum60 == sum + sum) {
          isYes60 = true;
          return;
     }

     dfs60(depth + 1, sum + v60[depth]);
     dfs60(depth + 1, sum);
}

void Q60() {
     int n;
     cin >> n;
     v60.resize(n + 1);

     for (int i = 1; i <= n; i++) {
          int in;
          cin >> in;

          v60[i] = in;
          totalSum60 += in;
     }

     dfs60(0, 0);

     if (isYes60)
          cout << "YES";
     else
          cout << "NO";
}
#pragma endregion

#pragma region 59. 부분집합(DFS)         내풀이
void recur59_2(int n, int i, vector<bool> v, bool b) {
     if (i > n) return;

     v[i] = b;

     recur59_2(n, i + 1, v, true);
     recur59_2(n, i + 1, v, false);

     if (i == n) {
          for (int i = 1; i < v.size(); i++)
               if (v[i])
                    cout << i << ' ';
          cout << '\n';
     }
}

void Q59_2() {
     int n;
     cin >> n;
     vector<bool> v(n + 1, false);

     recur59_2(n, 0, v, false);

}
#pragma endregion
#pragma region 59. 부분집합(DFS) MS
void dfs59(int d, vector<bool> v, int n, bool b) {
     if (d == n) {

          v[d] = b;

          for (int i = 1; i < v.size(); i++)
               if (v[i] == true)
                    cout << i << ' ';
          cout << endl;
          return;
     }
     else {
          v[d] = b;
     }


     dfs59(d + 1, v, n, true);
     dfs59(d + 1, v, n, false);
}

void Q59() {
     int n;
     cin >> n;
     vector<bool> v(n + 1, false);

     dfs59(0, v, n, false);


}
#pragma endregion

#pragma region 58.  이진트리 깊이우선탐색(DFS)

void preOder58(int v) {
     if (v > 7) return;
     else {
          cout << v << ' ';
          preOder58(v * 2);
          preOder58(v * 2 + 1);
     }
}

void postOder58(int v) {
     if (v > 7) return;
     else {
          postOder58(v * 2);
          postOder58(v * 2 + 1);
          cout << v << ' ';
     }
}

void inOder58(int v) {
     if (v > 7) return;
     else {
          inOder58(v * 2);
          cout << v << ' ';
          inOder58(v * 2 + 1);
     }
}
void Q58() {
     cout << "in "; inOder58(1);   cout << endl;
     cout << "post "; postOder58(1); cout << endl;
     cout << "pre "; preOder58(1); cout << endl;
}
#pragma endregion

#pragma region 57. 재귀함수(스택)를 이용한 2진수 출력
void recur57_2(int n, stack<int> s) {

     if (n == 0) {
          while (!s.empty()) {
               cout << s.top();
               s.pop();
          }
          return;
     }

     s.push(n % 2);

     return recur57_2(n / 2, s);
}

void Q57_2() {
     int n;
     stack<int> s;
     cin >> n;

     recur57_2(n, s);
}
#pragma endregion
#pragma region 57. 재귀함수 이진수 출력
int recusionQ57(int n, int i) {
     if (n == 0)
          return 0;

     return n % 2 * i + recusionQ57(n / 2, i * 10);

}
void Q57() {
     int n;
     cin >> n;
     cout << recusionQ57(n, 1);
}
#pragma endregion

#pragma region 56. 재귀함수 분석
void recursionQ56(int n) {

     if (n < 1)
          return;

     recursionQ56(n - 1);
     cout << n << ' ';
}
void Q56() {
     int n;
     cin >> n;

     recursionQ56(n);
}
#pragma endregion

