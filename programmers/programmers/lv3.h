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
		v[i] = (v[i - 2] + v[i - 1]) % 1000000007;
	}

	return answer = v[n];
}
#pragma endregion
#pragma region 43162 네트워크  
int findParent43162(int a, vector<int>& nodes) {
	if (nodes[a] == a)
		return a;
	else
		return nodes[a] = findParent43162(nodes[a], nodes);
}

void untionNode43162(int a, int b, vector<int>& nodes) {
	a = findParent43162(a, nodes);
	b = findParent43162(b, nodes);

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
			if (computers[i][j] == 1 && findParent43162(i, nodes) != findParent43162(j, nodes)) {

				untionNode43162(i, j, nodes);
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
int findParent42861(int a, vector<int>& nodes) {
	if (a == nodes[a])
		return a;
	else return nodes[a] = findParent42861(nodes[a], nodes);
}

void unionNodes42861(int a, int b, vector<int>& nodes) {
	a = findParent42861(a, nodes);
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

		if (findParent42861(a, nodes) != findParent42861(b, nodes)) {
			answer += v;
			unionNodes42861(a, b, nodes);
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
	vector<vector<pair<int, int>>> graph(n + 1);
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
		v[p[1] - 1][p[0] - 1] = -1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 && j == 0) continue;

			if (v[i][j] != -1) {
				int u = j - 1 > -1 && v[i][j - 1] != -1 ? v[i][j - 1] : 0;
				int l = i - 1 > -1 && v[i - 1][j] != -1 ? v[i - 1][j] : 0;
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

	return v[n - 1][m - 1];
}
#pragma endregion
#pragma region 12946 하노이의 탑  
void hanoi(int n, int from, int by, int to, vector<vector<int>>& answer) {
	if (n == 1) {
		answer.push_back({ from,to });
	}
	else {
		hanoi(n - 1, from, to, by, answer);
		answer.push_back({ from, to });
		hanoi(n - 1, by, from, to, answer);
	}
}

vector<vector<int>> solution12946(int n) {
	vector<vector<int>> answer;

	hanoi(n, 1, 2, 3, answer);

	return answer;
}
#pragma endregion
#pragma region 43105 정수 삼각형  
int func43105(int x, int y, vector<vector<int>>& triangle, vector<vector<int>>& dp) {

	if (dp[x][y] != -1)
		return dp[x][y];

	if (x == triangle.size() - 1) {
		dp[x][y] = triangle[x][y];
		return dp[x][y];
	}
	else {
		return dp[x][y] = max(func43105(x + 1, y, triangle, dp), func43105(x + 1, y + 1, triangle, dp)) + triangle[x][y];
	}
}

int solution43105(vector<vector<int>> triangle) {
	int answer = 0;
	vector<vector<int>> dp(triangle.size(), vector<int>(triangle.back().size(), -1));
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
#pragma region 43163 단어 변환  
int solution43163(string begin, string target, vector<string> words) {
	int answer = 0;
	queue<pair<string, int>> q;
	vector<bool> visit(words.size(), false);

	q.push({begin, 0});

	while (!q.empty()) {
		string now = q.front().first;
		int v = q.front().second;
		q.pop();

		if (now == target) {
			return v;
		}

		for (int i = 0; i < words.size(); i++) {
			int cnt = 0;
			for (int j = 0; j < words[i].size(); j++) {
				if (words[i][j] != now[j])
					cnt++;
				if (cnt > 1) break;
			}

			if (cnt == 1 && visit[i] == false) {
				q.push({ words[i],v + 1 });
				visit[i] = true;
			}

		}
	}

	return 0;
}
#pragma endregion
#pragma region 42579 베스트앨범
vector<int> solution42579(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, int> m;
	priority_queue<pair<int, string>> q;
	int n = genres.size();

	for (int i = 0; i < n; i++) {
		string s = genres[i];
		int v = plays[i];

		if (m.find(s) == m.end()) {
			m.insert({ s,v });
		}
		else {
			m.find(s)->second += v;
		}
	}

	for (auto it = m.begin(); it != m.end(); it++)
		q.push({ it->second,it->first });

	while (!q.empty()) {
		string g = q.top().second;
		q.pop();

		vector<pair<int, int>> temp;

		for (int i = 0; i < n; i++) {
			if (genres[i] == g)
				temp.push_back({ plays[i],i });
		}

		sort(temp.begin(), temp.end(), [](pair<int, int> a, pair<int, int> b) -> bool {
			if (a.first == b.first) {
				return a.second > b.second;
			}
			return a.first > b.first;
		});

		answer.push_back(temp[0].second);
		if (temp.size() > 1)
			answer.push_back(temp[1].second);

	}

	return answer;
}
#pragma endregion
#pragma region 12927 야근 지수  
long long solution12927(int n, vector<int> works) {
	long long answer = 0;
	priority_queue<int> q;

	for (int w : works)
		q.push(w);

	while (n != 0) {
		q.push(q.top() - 1);
		q.pop();
		n--;
	}

	while (!q.empty()) {
		if (q.top() > 0)
			answer += q.top() * q.top();
		q.pop();
	}

	return answer;
}
#pragma endregion
#pragma region 72413 합승 택시 요금
vector<int> getDist72413(int n, vector<vector<pair<int, int>>>& graph, int start) {
	int INF = 99999;
	vector<int> dist(n + 1, INF);
	dist[start] = 0;
	priority_queue<pair<int, int>> q;
	q.push({ 0,start });
	int ret = INF;

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

	return dist;
}

int solution72413(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = 99999;
	vector<vector<pair<int, int>>> graph(n + 1);

	for (auto fare : fares) {
		graph[fare[0]].push_back({ fare[1],fare[2] });
		graph[fare[1]].push_back({ fare[0],fare[2] });
	}

	auto sToi_Dist = getDist72413(n, graph, s);

	for (int i = 1; i < n + 1; i++) {
		auto iToab_Dist = getDist72413(n, graph, i);
		answer = min(iToab_Dist[a] + iToab_Dist[b] + sToi_Dist[i], answer);
	}

	return answer;
}
#pragma endregion
#pragma region 70129 이진 변환 반복하기  
vector<int> solution70129(string s) {
	int cnt = 0;
	int cntZero = 0;

	while (s != "1") {
		cnt++;
		int zero = 0;
		for (char c : s) {
			if (c == '0') {
				cntZero++;
				zero++;
			}
		}

		int size = s.size() - zero;
		string binary;

		while (size != 0) {
			binary = to_string(size % 2) + binary;
			size /= 2;
		}

		s = binary;
	}

	cout << cnt << ' ' << cntZero << '\n';
	return { cnt,cntZero };
}
#pragma endregion


/*
	2차원 배열로 풀었으나 시간초과
	1차원 배열로 풀어야함. 어려웠음.
*/
#pragma region 12952 N - Queen
void func12952(int n, int x, vector<int>& col, int& answer) {
	if (n == x) {
		answer++;
	}
	else {
		for (int i = 0; i < n; i++) {
			col[x] = i;

			bool canLocate = true;
			for (int j = 0; j < x; j++) {
				if (col[x] == col[j] || abs(col[x] - col[j]) == abs(x - j)) {
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
	vector<int> col(n, 0);
	func12952(n, 0, col, answer);

	return answer;
}
#pragma endregion
/*
	헤깔리는 dfs
	더 간단 명료하게 짤 수 있음.
*/
#pragma region 43164 여행경로  
void dfs43164(vector<vector<string>>& tickets, vector<string> ticket, vector<bool> &visit, vector<string> &temp, vector<string> &answer) {
	
	if (tickets.size() + 1 == answer.size())
		return;
	
	string from = ticket[0];
	string to = ticket[1];
	temp.push_back(to);

	if (tickets.size()+1  == temp.size()) {
		answer = temp;
	}
	else {
		
		for (int i = 0; i < tickets.size(); i++) {
			if (tickets[i][0] == to && !visit[i]) {
				visit[i] = true;
				dfs43164(tickets, tickets[i], visit, temp, answer);
				visit[i] = false;
			}
		}

	}
	temp.pop_back();
}

vector<string> solution43164(vector<vector<string>> tickets) {
	vector<string> answer;
	vector<bool> visit(tickets.size(), false);
	vector<string> temp;

	sort(tickets.begin(), tickets.end());

	for (int i = 0; i < tickets.size(); i++) {
		if (tickets[i][0] == "ICN" && !visit[i]) {
			visit[i] = true;
			temp.push_back("ICN");
			dfs43164(tickets, tickets[i], visit, temp, answer);
			temp.pop_back();
			visit[i] = false;
		}
	}

	for (string a : answer)
		cout << a << ' ';

	return answer;
}
#pragma endregion
/*
	전혀 감을 못잡음
	풀이 : 플로이드 와샬
	각 선수간의 승패를 알면 answer++;
*/
#pragma region 49191 순위 
int solution49191(int n, vector<vector<int>> results) {
	int answer = 0;
	vector<vector<bool>> result(n + 1, vector<bool>(n + 1, false));

	for (auto arr : results)
		result[arr[0]][arr[1]] = true;

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (result[i][k] && result[k][j])
					result[i][j] = true;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (result[i][j] || result[j][i])
				cnt++;
		}
		if (cnt == n - 1) answer++;
	}

	return answer;
}
#pragma endregion
/*
	그리디 & 동적 프로그래밍 문제
	점화식 도출하기 어려없음.
*/
#pragma region 12907 거스름돈
int solution12907(int n, vector<int> money) {
	vector<int> cnt(n+1);
	cnt[0] = 1;

	for (int m : money) {
		for (int i = m; i < n + 1; i++) {
			cnt[i] = (cnt[i] + cnt[i - m]) % 1000000007;
		}
	}
	 
	return cnt[n];
}
#pragma endregion
/*
	 모르겠음.
*/
#pragma region 12987 숫자 게임
int solution12987(vector<int> A, vector<int> B) {
	int answer = 0;
	int n = A.size();
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int a = n - 1;
	int b = n - 1;

	while (a > -1 && b > -1) {
		if (A[a] < B[b]) {
			answer++;
			b--;
		}
		a--;
	}

	return answer;
}
#pragma endregion
/*
	동적프로그래밍 어렵다.
*/
#pragma region 42895 N으로 표현  
int solution42895(int N, int number) {
	int answer = -1;
	auto s = vector<set<int>>(8);

	int temp = N;
	for (int i = 0; i < 8; i++) {
		if (temp == number)
			return i+1;
		
		s[i].insert(temp);
		temp = temp * 10 + N;
	}

	for (int i = 1; i < 8; i++) {
		for (int j = 0; j < i; j++) {
			for (auto op1 : s[j]) {
				for (auto op2 : s[i - j - 1]) {
					s[i].insert(op1 + op2);
					s[i].insert(op1 - op2);
					s[i].insert(op1 * op2);
					if(op2 != 0)
						s[i].insert(op1 / op2);
				}

			}
		}
	}


	for (int i = 0; i < 8; i++) 
		if (s[i].find(number) != s[i].end())
			return i + 1;

	return answer;
}
#pragma endregion
/*
	수학의 특성을 알아야함.
	수열에서 가장 높은 곱을 구하려면 중간이 되는 값을 곱하는게 가장 큼.

*/
#pragma region 12938 최고의 집합  
vector<int> solution12938(int n, int s) {
	vector<int> answer(n);
	
	if (n > s)
		return { -1 };

	int div = s / n;
	int rem = s % n;
	
	for (int i = 0; i < n; i++)
		answer[i] = div;

	for (int i = n - 1; rem > 0; i--) {
		answer[i]++;
		rem--;
	}

	return answer;
}
#pragma endregion
/*
	어렵다.
	이분 탐색으로 동일한 값을 찾는게 아닌 특정 이상의 값을 찾고 답을 찾음.
	특정 시간에 times를 나눈 값이 심사를 받은 사람이라는 점을 어떻게 도출하지.
*/
#pragma region 43238 입국심사  
long long solution43238(int n, vector<int> times) {
	long long answer = 0;
	long long s=1, e;
	e = (long long)*max_element(times.begin(), times.end()) * (long long)n;

	while (s <= e) {
		long long avg = (s + e) / 2;
		long long check = 0;
		for (int t : times) check += avg / t;

		if (check >= n) {
			e = avg - 1;

			answer = avg;

		}
		else {
			s = avg+1;
		}
	}

	return answer;
}
#pragma endregion

#pragma region sol  
void sol3() {
}
#pragma endregion
