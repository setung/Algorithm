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