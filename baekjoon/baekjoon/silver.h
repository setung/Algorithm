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

// 다이나믹 프로그래밍
#pragma region 1463 1로 만들기
void sol1463() {
	int n;
	cin >> n;
	vector<int> dp(1000001, 0);

	if (n < 4) {
		if (n == 1)
			cout << 0;
		else
			cout << n;
	}

	dp[2] = 1;
	dp[3] = 1;


	for (int i = 4; i < n + 1; i++) {
		if (i % 2 == 0 && i % 3 == 0) {
			dp[i] = min(dp[i - 1], min(dp[i / 2], dp[i / 3])) + 1;
		}
		else if (i % 2 == 0) {
			dp[i] = min(dp[i - 1], dp[i / 2]) + 1;;
		}
		else if (i % 3 == 0) {
			dp[i] = min(dp[i - 1], dp[i / 3]) + 1;
		}
		else {
			dp[i] = dp[i - 1] + 1;
		}
	}

	cout << dp[n];
}
#pragma endregion
#pragma region 9095 1, 2, 3 더하기
void sol9095() {
	int tc;
	cin >> tc;

	for (int t = 0; t < tc; t++) {
		int n;
		cin >> n;
		vector<int> dp(12);
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;

		for (int i = 4; i <= n; i++)
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

		cout << dp[n] << '\n';
	}
}
#pragma endregion
#pragma region 2579 계단 오르기
void sol2579() {
	int n;
	cin >> n;
	vector<int> arr(n + 1);
	vector<int> dp(n + 1);

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
	}

	cout << dp[n];
}
#pragma endregion
#pragma region 1003 피보나치 함수
void sol1003() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;

		vector<int> zero;
		vector<int> one;

		zero.push_back(1);
		zero.push_back(0);
		one.push_back(0);
		one.push_back(1);

		if (n < 2) {
			cout << zero[n] << ' ' << one[n] << '\n';
			continue;
		}

		for (int i = 2; i <= n; i++) {
			zero.push_back(zero[i - 1] + zero[i - 2]);
			one.push_back(one[i - 1] + one[i - 2]);
		}
		cout << zero[n] << ' ' << one[n] << '\n';
	}
}
#pragma endregion

//그래프
#pragma region 11724 연결 요소의 개수
int findParent11724(int a, vector<int>& nodes) {
	if (nodes[a] == a) return a;
	else return nodes[a] = findParent11724(nodes[a], nodes);
}

void unionNode11724(int a, int b, vector<int>& nodes) {
	a = findParent11724(a, nodes);
	b = findParent11724(b, nodes);

	if (a > b)
		nodes[a] = b;
	else
		nodes[b] = a;
}

void sol11724() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n + 1);
	vector<int> nodes(n + 1);

	for (int i = 0; i < n + 1; i++)
		nodes[i] = i;


	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			if (findParent11724(i, nodes) != findParent11724(graph[i][j], nodes))
				unionNode11724(findParent11724(i, nodes), findParent11724(graph[i][j], nodes), nodes);
		}
	}

	set<int> s;
	for (int i = 1; i <= n; i++)
		s.insert(findParent11724(i, nodes));

	cout << s.size();
}
#pragma endregion
#pragma region 5567 결혼식
void sol5567() {
	int n, m;
	cin >> n >> m;
	int INF = 99999999;
	vector<vector<pair<int, int>>> graph(n + 1);
	vector<int> dist(n + 1, INF);
	priority_queue<pair<int, int>> q;
	dist[1] = 0;

	q.push({ 0,1 });

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back({ b,1 });
		graph[b].push_back({ a,1 });
	}

	while (!q.empty()) {
		int node = q.top().second;
		int d = -q.top().first;
		q.pop();
		if (dist[node] > d) continue;

		for (int i = 0; i < graph[node].size(); i++) {
			int newNode = graph[node][i].first;
			int newDist = graph[node][i].second + d;

			if (dist[newNode] > newDist) {
				dist[newNode] = newDist;
				q.push({ -newDist,newNode });
			}
		}
	}

	int answer = 0;
	for (int i = 2; i <= n; i++)
		if (dist[i] == 1 || dist[i] == 2)
			answer++;
	cout << answer;

}
#pragma endregion
#pragma region 6118 숨바꼭질
void sol6118() {
	int n, m;
	cin >> n >> m;
	int INF = 99999999;
	vector<vector<pair<int, int>>> graph(n + 1);
	vector<int> dist(n + 1, INF);
	priority_queue<pair<int, int>> q;
	dist[1] = 0;

	q.push({ 0,1 });

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back({ b,1 });
		graph[b].push_back({ a,1 });
	}

	while (!q.empty()) {
		int node = q.top().second;
		int d = -q.top().first;
		q.pop();
		if (dist[node] > d) continue;

		for (int i = 0; i < graph[node].size(); i++) {
			int newNode = graph[node][i].first;
			int newDist = graph[node][i].second + d;

			if (dist[newNode] > newDist) {
				dist[newNode] = newDist;
				q.push({ -newDist,newNode });
			}
		}
	}

	int _max = 0;
	vector<int> answer;

	for (int i = 2; i <= n; i++) {
		if (dist[i] != INF && _max < dist[i])
			_max = dist[i];
	}

	for (int i = 2; i <= n; i++) {
		if (dist[i] == _max)
			answer.push_back(i);
	}

	cout << answer.front() << ' ' << _max << ' ' << answer.size();

}
#pragma endregion

//그리디
#pragma region 11399 ATM
void sol11399() {
	int n;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	int sum = 0;
	int answer = 0;

	for (int i = 0; i < n; i++) {
		sum += arr[i];
		answer += sum;
	}

	cout << answer;
}
#pragma endregion
#pragma region 11047 동전 0
void sol11047() {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end(), [](int a, int b) -> bool {
		return a > b;
	});

	int answer = 0;

	for (int i = 0; i < n; i++) {
		if (k >= arr[i]) {
			answer += k / arr[i];
			k %= arr[i];
		}

		if (k == 0)
			break;
	}

	cout << answer;
}
#pragma endregion
#pragma region 1946 신입 사원
void sol1946() {
	int tc;
	cin >> tc;

	for (int t = 0; t < tc; t++) {
		int n;
		cin >> n;
		vector<pair<int, int>> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i].first >> arr[i].second;

		sort(arr.begin(), arr.end());

		int rank = arr[0].second;
		int answer = 1;
		for (int i = 1; i < n; i++) {
			if (arr[i].second < rank) {
				answer++;
				rank = arr[i].second;
			}
		}

		cout << answer << '\n';
	}
}
#pragma endregion
#pragma region 2217 로프
void sol2217() {
	int n;
	cin >> n;
	vector<int> arr(n);
	int answer = 0;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++) {
		answer = max(answer, (n - i) * arr[i]);
	}

	cout << answer;
}
#pragma endregion
#pragma region 1541 잃어버린 괄호
void sol1541() {
	string str;
	cin >> str;
	vector<int> arr;

	string num;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '+' || str[i] == '-') {
			arr.push_back(stoi(num));
			num = "";
		}

		num += str[i];
	}
	arr.push_back(stoi(num));

	bool isMinus = false;
	int answer = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] < 0 && !isMinus) isMinus = !isMinus;

		if (isMinus && arr[i] >= 0)
			answer -= arr[i];
		else
			answer += arr[i];

	}

	cout << answer;
}
#pragma endregion
/*
	생각 못했음.
*/
#pragma region 1931 회의실 배정
void sol1931() {
	int n;
	cin >> n;
	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].second >> arr[i].first;
	}

	sort(arr.begin(), arr.end());

	int end = 0;
	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i].second >= end) {
			answer++;
			end = arr[i].first;
		}
	}

	cout << answer;
}
#pragma endregion
#pragma region 1436 영화감독 숌
void sol1436() {
	int n;
	cin >> n;
	vector<int> arr(1);

	int i = 666;

	while (true) {
		int tmp = i;
		int cnt = 0;

		if (arr.size() % 10001 == 0) {
			break;
		}

		while (tmp) {
			if (tmp % 10 == 6) {
				cnt++;
				if (cnt == 3) {
					arr.push_back(i);
					break;
				}
			}
			else
				cnt = 0;

			tmp /= 10;
		}

		i++;
	}

	cout << arr[n];
}
#pragma endregion

//우선순위 큐
#pragma region 1927 최소 힙
void sol1927() {
	int n;
	cin >> n;
	priority_queue<int> q;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (x == 0) {
			if (q.empty())
				cout << 0 << '\n';
			else {
				cout << -q.top() << '\n';
				q.pop();
			}
		}
		else
			q.push(-x);

	}
}
#pragma endregion
#pragma region 11279 최대 힙
void sol() {
	int n;
	cin >> n;
	priority_queue<int> q;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (x == 0) {
			if (q.empty())
				cout << 0 << '\n';
			else {
				cout << -q.top() << '\n';
				q.pop();
			}
		}
		else
			q.push(-x);

	}
}
#pragma endregion
#pragma region 11286 최소 절댓값 힙
void sol11286() {
	int n;
	cin >> n;
	priority_queue<int> pq;
	priority_queue<int> mq;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (x == 0) {
			if (pq.empty() && mq.empty())
				cout << 0 << '\n';
			else if (pq.empty()) {
				cout << mq.top() << '\n';
				mq.pop();
			}
			else if (mq.empty()) {
				cout << -pq.top() << '\n';
				pq.pop();
			}
			else {
				if (abs(pq.top()) >= abs(mq.top())) {
					cout << mq.top() << '\n';
					mq.pop();
				}
				else {
					cout << -pq.top() << '\n';
					pq.pop();
				}
			}
		}
		else if (x < 0)
			mq.push(x);
		else
			pq.push(-x);

	}
}
#pragma endregion
#pragma region 11286_2 최소 절댓값 힙
struct compare11286_2
{
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) return a > b;
		else
			return abs(a) > abs(b);
	}
};
void sol11286_2() {
	int n;
	cin >> n;
	priority_queue<int, vector<int>, compare11286_2> q;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (x != 0)
			q.push(x);
		else {
			if (q.empty())
				cout << 0 << '\n';
			else {
				cout << q.top() << '\n';
				q.pop();
			}

		}
	}
}
#pragma endregion

//문자열
#pragma region 1764 듣보잡 
void sol1764() {
	int n, m;
	cin >> n >> m;
	set<string> _set;
	set<string> _set2;

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		_set.insert(str);
	}

	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;

		if (_set.find(str) != _set.end())
			_set2.insert(str);
	}

	cout << _set2.size() << '\n';
	for (auto it = _set2.begin(); it != _set2.end(); it++)
		cout << *it << '\n';

}
#pragma endregion
#pragma region 7785 회사에 있는 사람 
void sol7785() {
	int n;
	cin >> n;
	set<string> _set;

	for (int i = 0; i < n; i++) {
		string name;
		string op;
		cin >> name >> op;

		if (op == "enter") {
			_set.insert(name);
		}
		else {
			_set.erase(name);
		}
	}

	for (auto it = _set.rbegin(); it != _set.rend(); it++)
		cout << *it << '\n';
}
#pragma endregion
#pragma region 1316 그룹 단어 체커
void sol1316() {
	int tc;
	int answer = 0;
	cin >> tc;

	while (tc--) {
		string str;
		bool correct = true;
		cin >> str;
		vector<bool> alpa(26, false);

		char c = str[0];
		alpa[c - 'a'] = true;
		for (int i = 1; i < str.size(); i++) {
			if (str[i] != c)
			{
				if (alpa[str[i] - 'a']) {
					correct = false;
					break;
				}
				alpa[c - 'a'] = true;
				c = str[i];
			}
		}

		if (correct)
			answer++;

	}

	cout << answer;

}
#pragma endregion

//비트마스크
#pragma region 11723 집합 
void sol11723() {
	int n;
	cin >> n;
	set<int> _set;

	for (int i = 0; i < n; i++) {
		string op;
		cin >> op;

		if (op == "add") {
			int x;
			cin >> x;
			_set.insert(x);
		}
		else if (op == "check") {
			int x;
			cin >> x;
			if (_set.find(x) == _set.end())
				cout << 0 << '\n';
			else
				cout << 1 << '\n';
		}
		else if (op == "toggle") {
			int x;
			cin >> x;
			if (_set.find(x) == _set.end())
				_set.insert(x);
			else
				_set.erase(x);
		}
		else if (op == "remove") {
			int x;
			cin >> x;
			_set.erase(x);
		}
		else if (op == "all") {
			_set = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
		}
		else if (op == "empty") {
			_set.clear();
		}
	}
}
#pragma endregion
#pragma region 11723_2 집합 비트연산 사용
void sol11723_2() {
	int m, x;
	cin >> m;
	int bit = 0;
	int allnum = 1;

	for (int i = 1; i < 21; i++)
		allnum += 1 << i;

	while (m--)
	{
		string op;
		cin >> op;

		if (op == "add") {
			cin >> x;
			x = 1 << x;
			bit |= x;
		}
		else if (op == "remove") {
			cin >> x;
			x = 1 << x;
			x = ~x;
			bit &= x;
		}
		else if (op == "check") {
			cin >> x;
			x = 1 << x;

			if (bit & x)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (op == "toggle") {
			cin >> x;
			x = 1 << x;
			bit ^= x;
		}
		else if (op == "all") {
			bit = allnum;
		}
		else if (op == "empty") {
			bit = 0;
		}
	}

}
#pragma endregion
#pragma region 1094 막대기
void sol1094() {
	int x;
	cin >> x;
	int answer = 0;

	while (x != 0) {
		if (x % 2 == 1)
			answer++;
		x /= 2;
	}

	cout << answer;
}
#pragma endregion

// 스택 큐
#pragma region 10799 쇠막대기
void sol() {
	int answer = 0;
	string str;
	cin >> str;
	stack<char> s;

	for (int i = 0; i < str.size(); i++) {
		if (i != str.size() && str[i] == '(' && str[i + 1] == ')') {
			answer += s.size();
			i++;
		}
		else if (str[i] == '(') {
			s.push(str[i]);
		}
		else {
			s.pop();
			answer++;
		}
	}

	cout << answer;
}
#pragma endregion
#pragma region 1874 스택 수열
void sol1874() {
	int n;
	cin >> n;
	stack<int> s;
	vector<char> answer;
	vector<int> arr(n);
	int index = 0;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		s.push(i);
		answer.push_back('+');

		while (!s.empty() && s.top() == arr[index]) {
			s.pop();
			answer.push_back('-');
			index++;
		}

	}

	if (s.empty())
		for (char c : answer)
			cout << c << '\n';
	else
		cout << "NO";

}
#pragma endregion
#pragma region 1021 회전하는 큐
void sol1021() {
	int n, m;
	cin >> n >> m;
	list<int> l;
	int answer = 0;
	for (int i = 1; i <= n; i++)
		l.push_back(i);

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;

		if (l.front() == x) {
			l.pop_front();
			continue;
		}

		int loc = 0;
		for (auto it = l.begin(); it != l.end(); it++) {
			if (*it == x) {
				break;
			}
			else
				loc++;
		}

		if (loc > l.size() / 2) {
			while (l.front() != x) {
				l.push_front(l.back());
				l.pop_back();
				answer++;
			}
		}
		else {
			while (l.front() != x) {
				l.push_back(l.front());
				l.pop_front();
				answer++;
			}
		}

		l.pop_front();
	}

	cout << answer;

}
#pragma endregion

// 정렬
#pragma region 10989 수 정렬하기 3
void sol10989() {
	int n;
	cin >> n;
	vector<int> arr(10001);

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[x]++;
	}

	for (int i = 0; i < 10001; i++) {
		int cnt = arr[i];
		for (int j = 0; j < cnt; j++) {
			cout << i << '\n';
		}
	}

}
#pragma endregion
#pragma region 11651 좌표 정렬하기 2
void sol11651() {
	int n;
	cin >> n;
	vector<pair<int, int>> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i].first;
		cin >> arr[i].second;
	}

	sort(arr.begin(), arr.end(), [](pair<int, int> p1, pair<int, int> p2)->bool {
		if (p1.second == p2.second)
			return p1.first < p2.first;
		else
			return p1.second < p2.second;
	});

	for (auto p : arr) {
		cout << p.first << ' ' << p.second << '\n';
	}
}
#pragma endregion


//bfs dfs
#pragma region 4963 섬의 개수
void sol4963() {
	while (true)
	{
		int n, m;
		cin >> m >> n;
		if (n == 0 && m == 0) return;

		int answer = 0;
		vector<vector<int>> _map(n, vector<int>(m));
		vector<vector<bool>> visit(n, vector<bool>(m, false));
		int dx[] = { 1,-1,0,0,1,1,-1,-1 };
		int dy[] = { 0,0,1,-1,1,-1,1,-1 };

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> _map[i][j];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (_map[i][j] == 1 && visit[i][j] == false) {
					answer++;
					queue<pair<int, int>> q;
					q.push({ i,j });
					visit[i][j] = true;

					while (!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;
						q.pop();

						for (int k = 0; k < 8; k++) {
							int nx = x + dx[k];
							int ny = y + dy[k];

							if (nx > -1 && ny > -1 && nx < n && ny < m && _map[nx][ny] == 1 && visit[nx][ny] == false) {
								visit[nx][ny] = true;
								q.push({ nx,ny });
							}
						}
					}
				}
			}
		}
		cout << answer << '\n';
	}
}
#pragma endregion