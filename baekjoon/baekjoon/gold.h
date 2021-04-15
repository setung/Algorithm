#pragma once
#include <stack>
#include <unordered_map>
#include <sstream>
#include <map>
#include <math.h>
#include <cmath>;
#include <list>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 다이스트라
#pragma region 1753 최단경로
void sol1753() {
	int INF = 999999;
	int v, e, k;
	cin >> v >> e >> k;
	vector<int> dist(v + 1, INF);
	vector<vector<pair<int, int>>> edges(v + 1);
	priority_queue<pair<int, int>> q;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({ b,c });
	}

	dist[k] = 0;
	q.push({ dist[k],k });

	while (!q.empty()) {
		int vertex = q.top().second;
		int d = -q.top().first;
		q.pop();

		if (d > dist[vertex]) continue;

		for (int i = 0; i < edges[vertex].size(); i++) {
			int newVertex = edges[vertex][i].first;
			int newDist = edges[vertex][i].second + d;

			if (newDist < dist[newVertex]) {
				dist[newVertex] = newDist;
				q.push({ -newDist,newVertex });
			}

		}

	}

	for (int i = 1; i <= v; i++)
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << '\n';

}
#pragma endregion
#pragma region 1504 특정한 최단 경로
vector<int> getDist1504(int v, int n, vector<vector<pair<int, int>>>& edges) {
	int INF = 99999999;

	vector<int> vertexs(n + 1, INF);
	priority_queue<pair<int, int>> q;

	vertexs[v] = 0;
	q.push({ vertexs[v],v });

	while (!q.empty()) {
		int node = q.top().second;
		int d = -q.top().first;
		q.pop();

		if (d > vertexs[node]) continue;

		for (int i = 0; i < edges[node].size(); i++) {
			int newnode = edges[node][i].first;
			int newD = edges[node][i].second + d;

			if (newD < vertexs[newnode]) {
				vertexs[newnode] = newD;
				q.push({ -newD, newnode });
			}

		}
	}

	return vertexs;
}

void sol1504() {
	int INF = 99999999;
	int n, m, v1, v2;
	cin >> n >> m;
	vector<vector<pair<int, int>>> edges(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({ b,c });
		edges[b].push_back({ a,c });
	}

	cin >> v1 >> v2;

	vector<int> startDist = getDist1504(1, n, edges);
	vector<int> v1Dist = getDist1504(v1, n, edges);
	vector<int> v2Dist = getDist1504(v2, n, edges);

	int answer1 = startDist[v1] + v1Dist[v2] + v2Dist[n];
	int answer2 = startDist[v2] + v2Dist[v1] + v1Dist[n];

	if (answer1 >= INF && answer2 >= INF)
		cout << -1;
	else
		cout << ((answer1 < answer2) ? answer1 : answer2);
}
#pragma endregion
#pragma region 1238 파티
vector<int> getDist1238(int n, int from, vector<vector<pair<int, int>>>& edges) {
	int INF = 99999999;
	vector<int> dists(n + 1, INF);
	priority_queue<pair<int, int>> q;

	dists[from] = 0;
	q.push({ dists[from],from });

	while (!q.empty()) {
		int node = q.top().second;
		int dist = -q.top().first;
		q.pop();
		if (dist > dists[node]) continue;

		for (int i = 0; i < edges[node].size(); i++) {
			int newNode = edges[node][i].first;
			int newDist = edges[node][i].second + dist;

			if (newDist < dists[newNode]) {
				dists[newNode] = newDist;
				q.push({ -newDist, newNode });
			}
		}
	}

	return dists;
}

void sol1238() {
	int n, m, x;
	cin >> n >> m >> x;
	vector<vector<pair<int, int>>> edges(n + 1);
	int answer = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({ b,c });
	}

	vector<int> distX = getDist1238(n, x, edges);

	for (int i = 1; i <= n; i++) {
		if (i == x) continue;
		vector<int> disti = getDist1238(n, i, edges);

		answer = (answer > disti[x] + distX[i]) ? answer : disti[x] + distX[i];
	}

	cout << answer;
}
#pragma endregion
#pragma region 4485 녹색 옷 입은 애가 젤다지?
void sol4485() {
	int cnt = 1;
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		vector<vector<int>> _map(n, vector<int>(n));

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> _map[i][j];

		vector<vector<pair<int, int>>> graph((n * n) + 1);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int dx[] = { 0,0,1,-1 };
				int dy[] = { 1,-1,0,0 };

				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx > -1 && ny > -1 && nx < n && ny < n) {
						graph[i * n + 1 + j].push_back({ nx * n + 1 + ny, _map[nx][ny] });
					}

				}
			}
		}

		priority_queue<pair<int, int>> q;
		vector<int> dist((n * n) + 1, 999999999);
		dist[1] = 0;
		q.push({ 0,1 });

		while (!q.empty()) {
			int node = q.top().second;
			int d = -q.top().first;
			q.pop();
			if (d > dist[node]) continue;

			for (int i = 0; i < graph[node].size(); i++) {
				int newNode = graph[node][i].first;
				int newDist = graph[node][i].second + d;

				if (dist[newNode] > newDist) {
					dist[newNode] = newDist;
					q.push({ -newDist,newNode });
				}
			}

		}

		cout << "Problem " << cnt++ << ": " << dist[n * n] + _map[0][0] << '\n';
	}
}
#pragma endregion
#pragma region 4485_2 녹색 옷 입은 애가 젤다지?
void sol4485_2() {
	int cnt = 1;

	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		vector<vector<int>> _map(n, vector<int>(n));


		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> _map[i][j];

		priority_queue<pair<int, pair<int, int>>> q;
		vector<vector<int>> dist(n, vector<int>(n, 99999999));
		dist[0][0] = _map[0][0];
		q.push({ -_map[0][0],{0,0} });

		while (!q.empty()) {
			int dx[] = { 0,0,-1,1 };
			int dy[] = { -1,1,0,0 };
			int x = q.top().second.first;
			int y = q.top().second.second;
			int d = -q.top().first;
			q.pop();

			if (d > dist[x][y]) continue;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx > -1 && ny > -1 && nx < n && ny < n && _map[nx][ny] + d < dist[nx][ny]) {
					dist[nx][ny] = d + _map[nx][ny];
					q.push({ -(d + _map[nx][ny]),{nx,ny} });
				}
			}

		}

		cout << "Problem " << cnt++ << ": " << dist[n - 1][n - 1] << '\n';
	}
}
#pragma endregion

//그래프
/*
	구현 방법이 까다로웠음.
	그냥 구현하면 됨.
*/
#pragma region 1043 거짓말
int findParent1043(int a, vector<int>& nodes) {
	if (a == nodes[a]) return a;
	else return nodes[a] = findParent1043(nodes[a], nodes);
}

void unionNode1043(int a, int b, vector<int>& nodes) {
	a = findParent1043(a, nodes);
	b = findParent1043(b, nodes);

	if (a > b)
		nodes[a] = b;
	else nodes[b] = a;
}

void sol() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> trues(k);
	vector<int> nodes(n + 1);
	vector<vector<int>> party(m);

	for (int i = 1; i <= n; i++)
		nodes[i] = i;

	for (int i = 0; i < k; i++)
		cin >> trues[i];

	for (int i = 0; i < m; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			int a;
			cin >> a;
			party[i].push_back(a);
		}

		for (int j = 0; j < party[i].size() - 1; j++) {
			unionNode1043(party[i][j], party[i][j + 1], nodes);
		}
	}

	int answer = m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < party[i].size(); j++) {
			bool isBreak = false;
			for (int k = 0; k < trues.size(); k++) {
				if (findParent1043(party[i][j], nodes) == findParent1043(trues[k], nodes)) {
					answer--;
					isBreak = true;
					break;
				}

				if (isBreak) break;
			}
			if (isBreak) break;
		}
	}

	cout << (answer > 0 ? answer : 0);

}
#pragma endregion

//우선순위 큐
/*
	위상정렬 전혀 생각치 못함.
*/
#pragma region 1766 문제집
void sol1766() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> node(n + 1);
	vector<int> level(n + 1, 0);
	priority_queue<int, vector<int>, greater<int>> q;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
		level[b] ++;
	}

	for (int i = 1; i <= n; i++) {
		if (level[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int n = q.top();
		q.pop();
		cout << n << ' ';

		for (int i = 0; i < node[n].size(); i++) {
			level[node[n][i]]--;

			if (level[node[n][i]] == 0)
				q.push(node[n][i]);
		}
	}
}
#pragma endregion


//dfs
/* 
	최단거리 구하기 문제는 dfs
	visit를 사용하면 메모리 문제가 해결되는데 이상하게 풀었었음.
*/
#pragma region 6593 상범 빌딩
class pos6593 {
public:
	int z, x, y;
	pos6593() {}
	pos6593(int _z, int _x, int _y) :z(_z), x(_x), y(_y) {}

	bool operator==(pos6593 p) {
		if (z == p.z && x == p.x && p.y == y) return true;
		else false;
	}
};

void sol6593() {
	int l, r, c;
	int dz[6] = { 1,-1,0,0,0,0 };
	int dx[6] = { 0,0,1,-1,0,0 };
	int dy[6] = { 0,0,0,0,1,-1 };

	while (true) {
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0) break;

		vector<vector<vector<char>>> _map(l, vector <vector<char>>(r, vector<char>(c)));
		vector < vector < vector<bool>> > visit(l, vector <vector<bool>>(r, vector<bool>(c, false)));
		int answer = 0;

		queue <pair<pos6593, int>> q;
		pos6593 start, end;

		for (int i = 0; i < l; i++)
			for (int j = 0; j < r; j++)
				for (int k = 0; k < c; k++) {
					cin >> _map[i][j][k];

					if (_map[i][j][k] == 'S') {
						start = pos6593(i, j, k);
					}
					if (_map[i][j][k] == 'E') {
						end = pos6593(i, j, k);
					}
				}

		q.push({ start,0 });

		while (!q.empty()) {
			pos6593 here = q.front().first;
			int cnt = q.front().second;
			q.pop();


			if (here.z == end.z && here.x == end.x && here.y == end.y) {
				answer = cnt;
				break;
			}

			for (int i = 0; i < 6; i++) {
				int nz = here.z + dz[i];
				int nx = here.x + dx[i];
				int ny = here.y + dy[i];

				if (nz > -1 && nx > -1 && ny > -1 &&
					nz < l && nx < r && ny < c &&
					_map[nz][nx][ny] != '#' && !visit[nz][nx][ny]) {

					visit[nz][nx][ny] = true;
					q.push({ pos6593(nz,nx,ny), cnt + 1 });
				}
			}
		}

		if (answer == 0)
			cout << "Trapped!\n";
		else
			cout << "Escaped in " << answer << " minute(s).\n";
	}

}
#pragma endregion
#pragma region 2146 다리 만들기
void sol2146() {
	int n;
	cin >> n;
	vector<vector<int>> _map(n, vector<int>(n));
	vector<vector<int>> dist(n, vector<int>(n, 0));
	vector<vector<bool>> visit(n, vector<bool>(n, false));
	int dx[] = { 0,0,1,-1 };
	int dy[] = { 1,-1,0,0 };
	queue<pair<pair<int, int>, int>> q;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> _map[i][j];

	int land = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (_map[i][j] == 1 && !visit[i][j]) {
				visit[i][j] = true;
				_map[i][j] = land;
				queue<pair<int, int>> tempq;
				tempq.push({ i,j });
				q.push({ {i,j},land });

				while (!tempq.empty()) {
					int x = tempq.front().first;
					int y = tempq.front().second;
					tempq.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (nx > -1 && ny > -1 && nx < n && ny < n && _map[nx][ny] == 1 && !visit[nx][ny]) {
							visit[nx][ny] = true;
							tempq.push({ nx,ny });
							_map[nx][ny] = land;
							q.push({ {nx,ny},land });
						}
					}
				}

				land++;
			}
		}
	}
	int mini = 98765421;
	while (!q.empty()) {

		int x = q.front().first.first;
		int y = q.front().first.second;
		int l = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx > -1 && ny > -1 && nx < n && ny < n) {
				if (_map[nx][ny] == 0) {
					_map[nx][ny] = l;
					dist[nx][ny] = dist[x][y] + 1;
					q.push({ {nx,ny},l });

				}
				else if (_map[nx][ny] != l) {
					if (mini > dist[nx][ny] + dist[x][y])
						mini = dist[nx][ny] + dist[x][y];
				}
			}
		}
	}

	cout << mini;
}
#pragma endregion
/*
	경로를 누적 하는 방법
	1차원 배열로 가능.
*/
#pragma region 11779 최소비용 구하기 2
void sol11779() {
	int n, m, s, e;
	cin >> n >> m;
	vector<vector<pair<int, int>>> graph(n + 1);
	priority_queue<pair<int, int>> q;
	vector<int> path(n + 1, 0);
	int INF = 987654321;
	vector<int> dist(n + 1, INF);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}
	cin >> s >> e;
	dist[s] = 0;
	q.push({ 0,s });

	while (!q.empty()) {
		int node = q.top().second;
		int d = -q.top().first;
		q.pop();

		if (d > dist[node]) continue;

		for (int i = 0; i < graph[node].size(); i++) {
			int newNode = graph[node][i].first;
			int newDist = graph[node][i].second + d;

			if (dist[newNode] > newDist) {
				dist[newNode] = newDist;
				path[newNode] = node;
				q.push({ -newDist, newNode });
			}
		}
	}

	vector<int> temp;
	int t = e;

	while (t) {
		temp.push_back(t);
		t = path[t];
	}

	cout << dist[e] << '\n';
	cout << temp.size() << '\n';
	for (int i = temp.size() - 1; i > -1; i--)
		cout << temp[i] << ' ';
}
#pragma endregion
#pragma region 4179 불!
void sol4179() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> _map(n, vector<char>(m));
	queue<pair<pair<int, int>, int>> fireQ;
	queue<pair<pair<int, int>, int>> manQ;
	int dx[] = { 0,0,-1,1 };
	int dy[] = { -1,1,0,0 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> _map[i][j];

			if (_map[i][j] == 'J')
				manQ.push({ {i,j},0 });
			else if (_map[i][j] == 'F')
				fireQ.push({ {i,j},0 });

		}
	}

	while (!manQ.empty()) {
		int x = manQ.front().first.first;
		int y = manQ.front().first.second;
		int move = manQ.front().second;
		manQ.pop();

		if (x == 0 || y == 0 || x == n - 1 || y == m - 1) {
			cout << move + 1;
			return;
		}

		while (!fireQ.empty()) {
			int fx = fireQ.front().first.first;
			int fy = fireQ.front().first.second;
			int fmove = fireQ.front().second;
			if (move != fmove) break;
			fireQ.pop();

			for (int i = 0; i < 4; i++) {
				int nfx = fx + dx[i];
				int nfy = fy + dy[i];

				if (nfx > -1 && nfy > -1 && nfx < n && nfy < m && (_map[nfx][nfy] == '.' || _map[nfx][nfy] == 'J')) {
					_map[nfx][nfy] = 'F';
					fireQ.push({ {nfx,nfy},fmove + 1 });
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx > -1 && ny > -1 && nx < n && ny < m && _map[nx][ny] == '.') {
				_map[nx][ny] = 'J';
				manQ.push({ {nx,ny},move + 1 });
			}
		}

	}

	cout << "IMPOSSIBLE";
}
#pragma endregion
/*
	상하좌우 외에 말처럼 움직이는 경우를 담아줘야 함.
	visit를 3차원 배열로 만듬 visit[x][y][k] 말의 움직임 k번으로 x y 방문
*/
#pragma region 1600 말이 되고픈 원숭이
void sol1600() {
	int k, n, m;
	cin >> k >> m >> n;
	vector<vector<int>> _map(n, vector<int>(m));
	vector<vector<vector<bool>>> visit(n, vector<vector<bool>>(m, vector<bool>(k + 1, false)));
	queue<pair<pair<int, int>, pair<int, int>>> q;
	int dx[] = { 0,0,1,-1 };
	int dy[] = { 1,-1,0,0 };
	int hdx[] = { 1,1,2,2,-1,-1,-2,-2 };
	int hdy[] = { 2,-2,1,-1,2,-2,1,-1 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> _map[i][j];
		}
	}

	q.push({ {0,0},{0,0} });
	visit[0][0][0] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second.first;
		int kcnt = q.front().second.second;
		q.pop();
		if (x == n - 1 && y == m - 1) {
			cout << cnt;
			return;
		}

		if (kcnt < k) {
			for (int i = 0; i < 8; i++) {
				int nx = x + hdx[i];
				int ny = y + hdy[i];
				if (nx > -1 && ny > -1 && nx < n && ny < m && _map[nx][ny] == 0 && !visit[nx][ny][kcnt + 1]) {
					visit[nx][ny][kcnt + 1] = true;
					q.push({ {nx,ny},{cnt + 1,kcnt + 1} });
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx > -1 && ny > -1 && nx < n && ny < m && _map[nx][ny] == 0 && !visit[nx][ny][kcnt]) {
				visit[nx][ny][kcnt] = true;
				q.push({ {nx,ny},{cnt + 1,kcnt} });
			}
		}
	}

	cout << -1;
}
#pragma endregion
#pragma region 2206 벽 부수고 이동하기
void sol2206() {
	int n, m;
	cin >> n >> m;
	vector < vector<char>> _map(n, vector<char>(m));
	vector < vector<vector<bool>>> visit(n, vector<vector<bool>>(m, vector<bool>(2, false)));
	queue<pair<pair<int, int>, pair<int, int>>> q;
	int dx[] = { 0,0,-1,1 };
	int dy[] = { -1,1,0,0 };
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> _map[i][j];

	q.push({ {0,0},{1,0} });
	visit[0][0][0] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second.first;
		int breakWall = q.front().second.second;
		if (x == 19 && y == 0) {
			cout << "break";
		}
		q.pop();

		if (x == n - 1 && y == m - 1) {
			cout << cnt;
			return;
		}

		if (breakWall == 0) {
			for (int i = 0; i < 4; i++) {
				int nx = dx[i] + x;
				int ny = dy[i] + y;

				if (nx > -1 && ny > -1 && nx < n && ny < m && _map[nx][ny] == '1' && !visit[nx][ny][breakWall + 1]) {
					visit[nx][ny][breakWall + 1] = true;
					q.push({ {nx,ny},{cnt + 1,breakWall + 1} });
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;

			if (nx > -1 && ny > -1 && nx < n && ny < m && _map[nx][ny] == '0' && !visit[nx][ny][breakWall]) {
				visit[nx][ny][breakWall] = true;
				q.push({ {nx,ny},{cnt + 1,breakWall} });
			}
		}
	}

	cout << -1;
}
#pragma endregion
#pragma region 1162 도로포장
void sol1162() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> _map(n, vector<char>(m));
	vector<vector<bool>> visit(n, vector<bool>(m, false));
	queue<pair<pair<int, int>, int>> q;
	queue<pair<pair<int, int>, int>> water;
	int dx[] = { 0,0,-1,1 };
	int dy[] = { -1,1,0,0 };


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> _map[i][j];
			if (_map[i][j] == 'S') {
				q.push({ {i,j},0 });
				_map[i][j] = '.';
				visit[i][j] = true;
			}
			else if (_map[i][j] == '*')
				water.push({ {i,j},0 });
		}
	}

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (_map[x][y] == 'D') {
			cout << cnt;
			return;
		}

		while (!water.empty() && water.front().second == cnt) {
			int wx = water.front().first.first;
			int wy = water.front().first.second;
			int wcnt = water.front().second;
			water.pop();

			for (int i = 0; i < 4; i++) {
				int nwx = wx + dx[i];
				int nwy = wy + dy[i];
				if (nwx > -1 && nwy > -1 && nwx < n && nwy < m && _map[nwx][nwy] == '.') {
					_map[nwx][nwy] = '*';
					water.push({ {nwx,nwy},wcnt + 1 });
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx > -1 && ny > -1 && nx < n && ny < m && _map[nx][ny] != '*' && _map[nx][ny] != 'X' && visit[nx][ny] == false) {
				visit[nx][ny] = true;
				q.push({ {nx,ny},cnt + 1 });
			}
		}
	}

	cout << "KAKTUS";
}
#pragma endregion
#pragma region 5427 불
void sol5427() {
	int n, m;
	cin >> m >> n;
	vector<vector<char>> _map(n, vector<char>(m));
	vector<vector<bool>> visit(n, vector<bool>(m, false));
	queue<pair<pair<int, int>, int>> q;
	queue<pair<pair<int, int>, int>> water;
	int dx[] = { 0,0,-1,1 };
	int dy[] = { -1,1,0,0 };


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> _map[i][j];
			if (_map[i][j] == '@') {
				q.push({ {i,j},0 });
				_map[i][j] = '.';
				visit[i][j] = true;
			}
			else if (_map[i][j] == '*')
				water.push({ {i,j},0 });
		}
	}

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
			cout << cnt + 1 << '\n';
			return;
		}

		while (!water.empty() && water.front().second == cnt) {
			int wx = water.front().first.first;
			int wy = water.front().first.second;
			int wcnt = water.front().second;
			water.pop();

			for (int i = 0; i < 4; i++) {
				int nwx = wx + dx[i];
				int nwy = wy + dy[i];
				if (nwx > -1 && nwy > -1 && nwx < n && nwy < m && _map[nwx][nwy] == '.') {
					_map[nwx][nwy] = '*';
					water.push({ {nwx,nwy},wcnt + 1 });
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx > -1 && ny > -1 && nx < n && ny < m && _map[nx][ny] != '*' && _map[nx][ny] != '#' && visit[nx][ny] == false) {
				visit[nx][ny] = true;
				q.push({ {nx,ny},cnt + 1 });
			}
		}
	}

	cout << "IMPOSSIBLE\n";
}
#pragma endregion