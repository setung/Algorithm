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
// 2504

#pragma region 2206 벽 부수고 이동하기
int bfs2206(int n, int m, vector<vector<int>> &_map, int &min) {
	vector<vector<bool>> visit(n, vector<bool>(m,false));
	int dx[] = { 0,0,-1,1 };
	int dy[] = { -1,1,0,0 };
	queue<pair<pair<int,int>, int>> q;
	
	q.push({ {0,0},1 });
	visit[0][0] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dist = q.front().second;
		q.pop();

		if (min < dist)
			return 987654321;

		if (x == n - 1 && y == m - 1) {
			return dist;
		}

		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;

			if (nx > -1 && ny > -1 && nx < n && ny < m &&
				_map[nx][ny] == 0 && !visit[nx][ny]) {
				visit[nx][ny] = true;
				q.push({ {nx,ny},dist + 1 });
			}
		}
	}

	return -1;
}
void sol() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> _map(n, vector<int>(m));
	int min = 987654321;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
			_map[i][j] = str[j] - '0';
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (_map[i][j] == 1) {
				_map[i][j] = 0;
				int dist = bfs2206(n, m, _map,min);
				_map[i][j] = 1;

				if (dist != -1 && dist < min)
					min = dist;
			}
		}
	}
	cout << (min == 987654321 ? -1 : min);
}
#pragma endregion

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	sol();
}