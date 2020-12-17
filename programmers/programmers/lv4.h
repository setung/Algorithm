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

#pragma region 1844 게임 맵 최단거리
int solution1844(vector<vector<int>> maps) {
	int answer = 0;
	int n = maps.size();
	int m = maps[0].size();
	vector<vector<bool>> visit(n, vector<bool>(m, false));
	queue<pair<pair<int, int>, int>> q;
	int dx[] = { 0,0,1,-1 };
	int dy[] = { 1,-1,0,0 };

	q.push({ {0,0},1 });
	visit[0][0] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dist = q.front().second;
		q.pop();

		if (x == n - 1 && y == m - 1) {
			answer = dist;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx > -1 && nx <n && ny > -1 && ny < m &&
				maps[nx][ny] == 1 && visit[nx][ny] == false) {
				visit[nx][ny] = true;
				q.push({ {nx,ny},dist + 1 });
			}
		}
	}

	return answer == 0 ? -1 : answer;
}
#pragma endregion

