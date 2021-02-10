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
// 백준

#pragma region 2557 Hello World
void sol2557() {
	cout << "Hello World!";
}
#pragma endregion
#pragma region 10872 팩토리얼
int factorial10872(int n) {
	if (n == 1)
		return 1;
	else
		return factorial10872(n - 1) * n;
}

void sol10872() {
	int n;
	cin >> n;

	cout << factorial10872(n);
}
#pragma endregion
#pragma region 10870 피보나치 수 5

int fibo10870(int n) {
	if (n == 0 || n == 1) return n;
	return fibo10870(n - 2) + fibo10870(n - 1);
}

void sol10870() {
	int n;
	cin >> n;
	cout << fibo10870(n);
}
#pragma endregion
#pragma region 1000 A+B
void sol1000() {
	int a, b;
	cin >> a >> b;
	cout << a + b;
}
#pragma endregion
#pragma region 2798 블랙잭
void sol2798() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	vector<bool> used(n, false);
	int num = 0;
	int answer = 0;
	for (int i = 0; i < n; i++)
		cin >> v[i];

	for (int i = 0; i < n - 2; i++) {
		num += v[i];
		for (int j = i + 1; j < n - 1; j++) {
			num += v[j];
			for (int k = j + 1; k < n; k++) {
				num += v[k];

				if (num <= m && answer < num)
					answer = num;

				num -= v[k];
			}
			num -= v[j];
		}
		num -= v[i];
	}

	cout << answer;
}
#pragma endregion
#pragma region 10828 스택 
void sol10828() {
	stack<int> s;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string op;
		cin >> op;

		if (op == "push") {
			int a;
			cin >> a;
			s.push(a);
		}
		else if (op == "top") {
			if (!s.empty()) {
				cout << s.top() << '\n';
			}
			else
				cout << -1 << '\n';
		}
		else if (op == "size") {
			cout << s.size() << '\n';
		}
		else if (op == "empty") {
			cout << s.empty() << '\n';
		}
		else if (op == "pop") {
			if (!s.empty()) {
				cout << s.top() << '\n';
				s.pop();
			}
			else
				cout << -1 << '\n';
		}
	}
}
#pragma endregion
#pragma region 10773 제로 
void sol10773() {
	stack<int> s;
	int n;
	int answer = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		if (a == 0)
			s.pop();
		else
			s.push(a);
	}

	while (!s.empty()) {
		answer += s.top();
		s.pop();
	}

	cout << answer;
}
#pragma endregion
#pragma region 9012 괄호  
void sol9012() {
	int t;
	cin >> t;

	for (int tc = 0; tc < t; tc++) {
		string str;
		stack<int> s;
		bool isVPS = true;
		cin >> str;

		for (char c : str) {
			if (c == '(')
				s.push(c);
			else {
				if (s.empty()) {
					isVPS = false;
					break;
				}
				else
					s.pop();
			}
		}

		if (s.empty() && isVPS)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
#pragma endregion
#pragma region 4949 균형잡힌 세상 
void sol4949() {
	while (true) {
		string str;
		stack<char> s;
		bool isBalance = true;
		getline(cin, str);

		if (str == ".") break;

		for (char c : str) {
			if (c == '(' || c == '[')
				s.push(c);
			else if (c == ')' || c == ']') {
				if (s.empty()) {
					isBalance = false;
					break;
				}
				else {
					char top = s.top();
					if ((c == ')' && top == '(') || (c == ']' && top == '[')) {
						s.pop();
					}
					else {
						isBalance = false;
						break;
					}
				}

			}
		}

		if (s.empty() && isBalance)
			cout << "yes\n";
		else
			cout << "no\n";

	}
}
#pragma endregion
#pragma region 10808 알파벳 개수
void sol10808() {
	vector<int> v(26, 0);
	string str;
	cin >> str;

	for (char c : str) {
		v[c - 'a']++;
	}

	for (int i : v)
		cout << i << ' ';
}
#pragma endregion
#pragma region 10807 개수 세기
void sol10807() {
	int n, m;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	cin >> m;

	cout << count(v.begin(), v.end(), m);
}
#pragma endregion
#pragma region 2577 숫자의 개수
void sol2577() {
	int n = 1;
	vector<int> v(10, 0);

	for (int i = 0; i < 3; i++) {
		int a;
		cin >> a;
		n *= a;
	}

	while (n != 0) {
		v[n % 10]++;
		n /= 10;
	}

	for (int a : v)
		cout << a << '\n';

}
#pragma endregion
#pragma region 11328 Strfry
void sol11328() {
	int t;
	cin >> t;

	for (int tc = 0; tc < t; tc++) {
		string str1, str2;
		cin >> str1 >> str2;
		vector<int> v(26, 0);

		for (char c : str1)
			v[c - 'a']++;

		for (char c : str2)
			v[c - 'a']--;

		if (count(v.begin(), v.end(), 0) == 26)
			cout << "Possible\n";
		else
			cout << "Impossible\n";

	}
}
#pragma endregion
#pragma region 13300 방 배정
void sol13300() {
	int n, k;
	cin >> n >> k;
	int answer = 0;
	vector<vector<int>> room(7, vector<int>(2, 0));

	for (int i = 0; i < n; i++) {
		int s, y;
		cin >> s >> y;
		room[y][s]++;
	}

	for (int i = 1; i < 7; i++)
		for (int j = 0; j < 2; j++)
			answer += room[i][j] / k + (room[i][j] % k != 0);

	cout << answer;
}
#pragma endregion
#pragma region 1475 방 번호
void sol1475() {
	int n;
	cin >> n;
	vector<int> v(10, 0);

	if (n == 0) {
		cout << 1;
		return;
	}


	while (n != 0) {
		int index = n % 10;

		if (index == 9)
			index = 6;

		v[index] ++;

		n /= 10;
	}

	v[6] = v[6] / 2 + (v[6] % 2 == 1);

	int maxi = 0;
	for (int i = 0; i < 10; i++)
		if (v[i] > maxi)
			maxi = v[i];

	cout << maxi;

}
#pragma endregion
#pragma region 1919 애너그램 만들기
void sol1919() {
	string str1;
	string str2;
	cin >> str1 >> str2;
	vector<int> v(26, 0);

	for (char c : str1)
		v[c - 'a']++;
	for (char c : str2)
		v[c - 'a']--;

	int answer = 0;
	for (int i : v)
		answer += abs(i);

	cout << answer;


}
#pragma endregion
#pragma region 1926 그림
void sol1926() {
	int n, m;
	cin >> n >> m;
	int dx[] = { 0,0,1,-1 };
	int dy[] = { -1,1,0,0 };
	vector<vector<int>> pic(n, vector<int>(m));
	vector<vector<bool>> visit(n, vector<bool>(m, false));
	vector<int> picCount;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> pic[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (pic[i][j] == 1 && visit[i][j] == false) {
				queue<pair<int, int>> q;
				q.push({ i,j });
				int count = 0;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					count++;
					visit[x][y] = true;

					for (int k = 0; k < 4; k++) {
						int nx = dx[k] + x;
						int ny = dy[k] + y;

						if (nx > -1 && nx < n && ny > -1 && ny < m
							&& pic[nx][ny] == 1 && visit[nx][ny] == false) {
							q.push({ nx, ny });
							visit[nx][ny] = true;
						}
					}
				}
				picCount.push_back(count);
			}
		}
	}
	cout << picCount.size() << '\n';
	cout << (picCount.empty() ? 0 : *max_element(picCount.begin(), picCount.end()));
}
#pragma endregion
#pragma region 2178 미로 탐색
void sol2178() {
	int n, m;
	cin >> n >> m;
	int dx[] = { 0,0,1,-1 };
	int dy[] = { 1,-1,0,0 };
	vector<vector<int>> _map(n, vector<int>(m));
	vector<vector<bool>> visit(n, vector<bool>(m, false));
	queue<pair<pair<int, int>, int>> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			_map[i][j] = c - '0';
		}

	q.push({ {0,0},1 });
	visit[0][0] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int count = q.front().second;
		q.pop();

		if (x == n - 1 && y == m - 1) {
			cout << count;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;

			if (nx > -1 && ny > -1 && nx < n && ny < m &&
				_map[nx][ny] == 1 && visit[nx][ny] == false) {
				q.push({ {nx,ny},count + 1 });
				visit[nx][ny] = true;
			}
		}
	}
}
#pragma endregion
#pragma region 7576 토마토 
void sol7576() {
	int dx[] = { 0,0,-1,1 };
	int dy[] = { 1,-1,0,0 };
	int n, m;
	cin >> n >> m;
	int count = 0;
	vector<vector<int>> _map(m, vector<int>(n));
	queue<pair<pair<int, int>, int>> q;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			cin >> _map[i][j];

			if (_map[i][j] == 1)
				q.push({ {i,j},0 });
		}

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		count = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;

			if (nx > -1 && ny > -1 && nx < m && ny < n &&
				_map[nx][ny] == 0) {
				q.push({ {nx,ny},count + 1 });
				_map[nx][ny] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (_map[i][j] == 0) {
				cout << -1;
				return;
			}
		}
	}
	cout << count;
}
#pragma endregion
#pragma region 1697 숨바꼭질 
void sol1697() {
	int n, k;
	cin >> n >> k;

	queue<pair<int, int>> q;
	vector<bool> visit(100001, false);
	q.push({ n,0 });
	visit[n] = true;

	while (!q.empty()) {
		int now = q.front().first;
		int time = q.front().second;
		q.pop();
		if (now == k) {
			cout << time;
			return;
		}

		if (now + 1 < 100001 && visit[now + 1] == false) {
			q.push({ now + 1,time + 1 });
			visit[now + 1] = true;
		}
		if (now - 1 > -1 && visit[now - 1] == false) {
			q.push({ now - 1,time + 1 });
			visit[now - 1] = true;
		}
		if (now * 2 < 100001 && visit[now * 2] == false) {
			q.push({ now * 2,time + 1 });
			visit[now * 2] = true;
		}
	}
}
#pragma endregion
#pragma region 1012 유기농 배추
void sol1012() {
	int t;
	cin >> t;

	int dx[] = { 0,0,1,-1 };
	int dy[] = { 1,-1,0,0 };
	for (int tc = 0; tc < t; tc++) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>> _map(n, vector<int>(m, 0));
		vector<vector<bool>> visit(n, vector<bool>(m, false));
		queue<pair<int, int>> q;
		int answer = 0;

		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			_map[a][b] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (_map[i][j] == 1 && visit[i][j] == false) {
					q.push({ i,j });
					visit[i][j] = true;

					while (!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;
						q.pop();

						for (int k = 0; k < 4; k++) {
							int nx = x + dx[k];
							int ny = y + dy[k];

							if (nx > -1 && nx<n && ny >-1 && ny < m &&
								_map[nx][ny] == 1 && visit[nx][ny] == false) {
								q.push({ nx,ny });
								visit[nx][ny] = true;
							}
						}
					}
					answer++;
				}
			}
		}
		cout << answer << '\n';
	}
}
#pragma endregion
#pragma region 2583 영역 구하기
void sol2583() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> _map(n, vector<int>(m));
	vector<vector<bool>> visit(n, vector<bool>(m, false));
	int dx[] = { 0,0,1,-1 };
	int dy[] = { 1,-1,0,0 };
	queue<pair<int, int>> q;
	vector<int> answer;
	for (int i = 0; i < k; i++) {
		int lx, ly, rx, ry;
		cin >> lx >> ly >> rx >> ry;

		for (int x = lx; x < rx; x++)
			for (int y = ly; y < ry; y++)
				_map[y][x] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (_map[i][j] == 0 && visit[i][j] == false) {
				q.push({ i,j });
				visit[i][j] = true;
				int size = 1;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int nx = dx[k] + x;
						int ny = dy[k] + y;

						if (nx > -1 && nx < n && ny > -1 && ny < m &&
							_map[nx][ny] == 0 && visit[nx][ny] == false) {
							visit[nx][ny] = true;
							q.push({ nx,ny });
							size++;
						}
					}
				}
				answer.push_back(size);
			}
		}
	}

	sort(answer.begin(), answer.end());
	cout << answer.size() << '\n';
	for (int i : answer)
		cout << i << ' ';
}
#pragma endregion
#pragma region 1026 보물
void sol1026() {
	int n;
	cin >> n;
	vector<int> v1(n);
	vector<int> v2(n);
	int answer = 0;
	for (int i = 0; i < n; i++)
		cin >> v1[i];
	for (int i = 0; i < n; i++)
		cin >> v2[i];

	sort(v1.begin(), v1.end());
	sort(v2.rbegin(), v2.rend());

	for (int i = 0; i < n; i++) {
		answer += v1[i] * v2[i];
	}

	cout << answer;
}
#pragma endregion
#pragma region 1260 DFS와 BFS
void bfs1260(int n, vector<vector<int>>& graph, int start) {
	queue<int> q;
	vector<bool> visit(n + 1, false);

	q.push(start);
	visit[start] = true;

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		cout << node << ' ';

		for (int i = 0; i < graph[node].size(); i++) {
			if (visit[graph[node][i]] == false) {
				visit[graph[node][i]] = true;
				q.push(graph[node][i]);
			}
		}
	}
}
void dfs1260(vector<vector<int>>& graph, int start, vector<bool>& visit) {
	cout << start << ' ';
	visit[start] = true;

	for (int i = 0; i < graph[start].size(); i++) {
		if (visit[graph[start][i]] == false) {
			visit[graph[start][i]] = true;
			dfs1260(graph, graph[start][i], visit);
		}
	}
}
void sol1260() {
	int n, m, start;
	cin >> n >> m >> start;
	vector<vector<int>> graph(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 0; i <= n; i++)
		sort(graph[i].begin(), graph[i].end());

	vector<bool> visit(n + 1, false);
	dfs1260(graph, start, visit);
	cout << '\n';
	bfs1260(n, graph, start);
}
#pragma endregion
#pragma region 2667 단지번호붙이기
void sol2667() {
	int n;
	cin >> n;
	vector<vector<int>> _map(n, vector<int>(n));
	vector<vector<bool>> visit(n, vector<bool>(n, false));
	queue<pair<int, int>> q;
	vector<int> answer;
	int dx[] = { 0,0,-1,1 };
	int dy[] = { -1,1,0,0 };

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++)
			_map[i][j] = s[j] - '0';
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (_map[i][j] == 1 && !visit[i][j]) {
				q.push({ i,j });
				visit[i][j] = true;
				int count = 0;

				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					count++;
					for (int k = 0; k < 4; k++) {
						int nx = dx[k] + x;
						int ny = dy[k] + y;

						if (nx > -1 && ny > -1 && nx < n && ny < n &&
							_map[nx][ny] == 1 && !visit[nx][ny]) {
							visit[nx][ny] = true;
							q.push({ nx,ny });
						}
					}
				}
				answer.push_back(count);
			}
		}
	}

	sort(answer.begin(), answer.end());
	cout << answer.size() << '\n';
	for (int a : answer)
		cout << a << '\n';

}
#pragma endregion
#pragma region 15649 N과 M (1)
void dfs15649(int n, int m, vector<int> v, vector<bool> visit) {
	if (v.size() == m) {
		for (int a : v)
			cout << a << ' ';
		cout << '\n';
	}
	else {
		for (int i = 1; i < n + 1; i++) {
			if (!visit[i]) {
				v.push_back(i);
				visit[i] = true;
				dfs15649(n, m, v, visit);
				v.pop_back();
				visit[i] = false;
			}

		}
	}
}

void sol15649() {
	int n, m;
	cin >> n >> m;

	vector<int> v;
	vector<bool> visit(n + 1, false);
	dfs15649(n, m, v, visit);
}
#pragma endregion
#pragma region 11729 하노이 탑 이동 순서
void hanoi11729(int n, char a, char b, char c, vector<pair<char, char>>& v) {
	if (n == 1) {
		v.push_back({ a,c });
	}
	else {
		hanoi11729(n - 1, a, c, b, v);
		v.push_back({ a,c });
		hanoi11729(n - 1, b, a, c, v);
	}
}

void sol11729() {
	int n;
	cin >> n;
	vector<pair<char, char>> v;

	hanoi11729(n, '1', '2', '3', v);

	cout << v.size() << '\n';
	for (auto a : v)
		cout << a.first << ' ' << a.second << '\n';
}
#pragma endregion
#pragma region 17478 재귀함수가 뭔가요?
void recur17478(int n, int l) {
	string bar = "";
	for (int i = 0; i < l; i++)
		bar += "____";

	if (n == l) {
		cout << bar << "\"재귀함수가 뭔가요?\"\n";
		cout << bar << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
		cout << bar << "라고 답변하였지.\n";
	}
	else if (n > l) {

		cout << bar << "\"재귀함수가 뭔가요?\"\n";
		cout << bar << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
		cout << bar << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
		cout << bar << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
		recur17478(n, l + 1);
		cout << bar << "라고 답변하였지.";
		if (l != 0)
			cout << '\n';
	}
}
void sol17478() {
	int n;
	cin >> n;

	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
	recur17478(n, 0);
}
#pragma endregion
#pragma region 1992 쿼드트리
void recur1992(int n, int x, int y, vector<vector<int>>& _map, string& answer) {

	int v = _map[x][y];
	int cnt = 0;
	bool isOne = true;

	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (v != _map[i][j]) {
				isOne = false;
				break;
			}
		}

		if (!isOne)
			break;
	}

	if (!isOne) {
		answer += "(";

		recur1992(n / 2, x, y, _map, answer);
		recur1992(n / 2, x, y + n / 2, _map, answer);
		recur1992(n / 2, x + n / 2, y, _map, answer);
		recur1992(n / 2, x + n / 2, y + n / 2, _map, answer);

		answer += ")";
	}
	else {
		answer += v + '0';
	}

}
void sol1992() {
	int n;
	cin >> n;
	vector<vector<int>> _map(n, vector<int>(n));
	string answer;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			_map[i][j] = c - '0';
		}

	recur1992(n, 0, 0, _map, answer);
	cout << answer;
}
#pragma endregion
#pragma region 15651 N과 M (3)
void func15651(int n, int m, vector<int> num) {
	if (num.size() == m) {
		for (int i = 0; i < m; i++)
			cout << num[i] << ' ';
		cout << '\n';
	}
	else {
		for (int i = 1; i <= n; i++) {
			num.push_back(i);
			func15651(n, m, num);
			num.pop_back();
		}
	}
}

void sol15651() {
	int n, m;
	cin >> n >> m;

	func15651(n, m, {});

}
#pragma endregion
#pragma region 15652 N과 M (4)
void func15652(int n, int m, int index, vector<int> num) {
	if (num.size() == m) {
		for (int i = 0; i < m; i++)
			cout << num[i] << ' ';
		cout << '\n';
	}
	else {
		for (int i = index; i <= n; i++) {
			num.push_back(i);
			func15652(n, m, i, num);
			num.pop_back();
		}
	}
}

void sol15652() {
	int n, m;
	cin >> n >> m;

	func15652(n, m, 1, {});
}
#pragma endregion
#pragma region 15654 N과 M (5)
void func15654(int n, int m, vector<pair<int, bool>>& v, vector<int> num) {
	if (num.size() == m) {
		for (int i = 0; i < m; i++)
			cout << num[i] << ' ';
		cout << '\n';
	}
	else {
		for (int i = 0; i < n; i++) {
			if (v[i].second == false) {
				v[i].second = true;
				num.push_back(v[i].first);
				func15654(n, m, v, num);
				v[i].second = false;
				num.pop_back();
			}
		}
	}
}

void sol15654() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, bool>> v(n);

	for (int i = 0; i < n; i++) {
		int nn;
		cin >> nn;
		v[i] = { nn,false };
	}

	sort(v.begin(), v.end());

	func15654(n, m, v, {});
}
#pragma endregion
#pragma region 15655 N과 M (6)
void func15655(int n, int m, int index, vector<pair<int, bool>>& v, vector<int> num) {
	if (num.size() == m) {
		for (int i = 0; i < m; i++)
			cout << num[i] << ' ';
		cout << '\n';
	}
	else {
		for (int i = index; i < n; i++) {
			if (v[i].second == false) {
				v[i].second = true;
				num.push_back(v[i].first);
				func15655(n, m, i, v, num);
				v[i].second = false;
				num.pop_back();
			}
		}
	}
}

void sol15655() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, bool>> v(n);

	for (int i = 0; i < n; i++) {
		int nn;
		cin >> nn;
		v[i] = { nn,false };
	}

	sort(v.begin(), v.end());

	func15655(n, m, 0, v, {});
}
#pragma endregion
#pragma region 15656 N과 M (7)
void func15656(int n, int m, vector<int>& v, vector<int> num) {
	if (num.size() == m) {
		for (int i = 0; i < m; i++)
			cout << num[i] << ' ';
		cout << '\n';
	}
	else {
		for (int i = 0; i < n; i++) {
			num.push_back(v[i]);
			func15656(n, m, v, num);
			num.pop_back();
		}
	}
}

void sol15656() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	func15656(n, m, v, {});
}
#pragma endregion
#pragma region 15663 N과 M (9)
void func15663(int n, int m, vector<int>& v, vector<bool>& visit, vector<int> num, set<vector<int>>& _set) {
	if (num.size() == m) {
		_set.insert(num);
	}
	else {
		for (int i = 0; i < n; i++) {
			if (!visit[i]) {
				visit[i] = true;
				num.push_back(v[i]);
				func15663(n, m, v, visit, num, _set);
				num.pop_back();
				visit[i] = false;
			}
		}
	}
}

void sol15663() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	vector<bool> visit(n, false);
	set<vector<int>> _set;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	func15663(n, m, v, visit, {}, _set);

	for (auto it : _set) {
		for (int a : it) {
			cout << a << ' ';
		}
		cout << '\n';
	}
}
#pragma endregion
#pragma region 15664 N과 M (10)
void func15664(int n, int m, int index, vector<int>& v, vector<bool>& visit, vector<int> num, set<vector<int>>& _set) {
	if (num.size() == m) {
		_set.insert(num);
	}
	else {
		for (int i = index; i < n; i++) {
			if (!visit[i]) {
				visit[i] = true;
				num.push_back(v[i]);
				func15664(n, m, i, v, visit, num, _set);
				num.pop_back();
				visit[i] = false;
			}
		}
	}
}

void sol15664() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	vector<bool> visit(n, false);
	set<vector<int>> _set;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	func15664(n, m, 0, v, visit, {}, _set);

	for (auto it : _set) {
		for (int a : it) {
			cout << a << ' ';
		}
		cout << '\n';
	}
}
#pragma endregion
#pragma region 15665 N과 M (11)
void func15665(int n, int m, vector<int>& v, vector<int> num, set<vector<int>>& _set) {
	if (num.size() == m) {
		_set.insert(num);
	}
	else {
		for (int i = 0; i < n; i++) {
			num.push_back(v[i]);
			func15665(n, m, v, num, _set);
			num.pop_back();
		}
	}
}

void sol15665() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	set<vector<int>> _set;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	func15665(n, m, v, {}, _set);

	for (auto it : _set) {
		for (int a : it) {
			cout << a << ' ';
		}
		cout << '\n';
	}
}
#pragma endregion
#pragma region 15666 N과 M (12)
void func15666(int n, int m, int index, vector<int>& v, vector<int> num, set<vector<int>>& _set) {
	if (num.size() == m) {
		_set.insert(num);
	}
	else {
		for (int i = index; i < n; i++) {
			num.push_back(v[i]);
			func15666(n, m, i, v, num, _set);
			num.pop_back();
		}
	}
}

void sol15666() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	set<vector<int>> _set;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	func15666(n, m, 0, v, {}, _set);

	for (auto it : _set) {
		for (int a : it) {
			cout << a << ' ';
		}
		cout << '\n';
	}
}
#pragma endregion
#pragma region 9663 N-Queen 
void func9663(int n, int x, vector<int>& col, int& answer) {
	if (n == x) {
		answer++;
	}
	else {
		for (int i = 0; i < n; i++) {
			col[x] = i;

			bool canLocate = true;

			for (int j = 0; j < x; j++) {
				if (col[x] == col[j] ||
					abs(col[x] - col[j]) == abs(x - j)) {
					canLocate = false;
					break;
				}
			}

			if (canLocate)
				func9663(n, x + 1, col, answer);
		}
	}
}

void sol9663() {
	int n;
	int answer = 0;
	cin >> n;
	vector<int> col(n, 0);
	func9663(n, 0, col, answer);
	cout << answer;
}
#pragma endregion
#pragma region 11650 좌표 정렬하기 
void sol11650() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[i] = { a,b };
	}

	sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) ->bool {
		if (a.first == b.first)
			return a.second < b.second;
		else
			return a.first < b.first;
	});

	for (int i = 0; i < n; i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
}
#pragma endregion
#pragma region 11726 2×n 타일링 1
void sol11726() {
	int n;
	cin >> n;
	vector<int> dp(1001);
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i < n + 1; i++)
		dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;

	cout << dp[n];
}
#pragma endregion
#pragma region 11727 2×n 타일링 2
void sol11727() {
	int n;
	cin >> n;
	vector<int> dp(1001);
	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i < n + 1; i++)
		dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % 10007;

	cout << dp[n];
}
#pragma endregion
#pragma region 2193 이친수 
void sol2193() {
	int n;
	cin >> n;
	vector<long long> dp(91);
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i < 91; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	cout << dp[n];
}
#pragma endregion
#pragma region 1918 후위 표기식   
int getPrio1918(char c) {
	if (c == '*' || c == '/')
		return 3;
	else if (c == '+' || c == '-')
		return 2;
	else
		return 1;
}

int getOpGap1918(char c1, char c2) {
	return getPrio1918(c1) - getPrio1918(c2);
}

void sol1918() {
	string s;
	cin >> s;
	stack<char> _stack;
	string answer;

	for (char c : s) {
		if (c >= 'A' && c <= 'Z')
			answer += c;
		else {
			if (c == '(')
				_stack.push(c);
			else if (c == ')') {
				while (!_stack.empty()) {
					if (_stack.top() == '(') {
						_stack.pop();
						break;
					}
					else {
						answer += _stack.top();
						_stack.pop();
					}
				}
			}
			else {
				while (!_stack.empty() && getOpGap1918(_stack.top(), c) >= 0) {
					answer += _stack.top();
					_stack.pop();
				}

				_stack.push(c);
			}
		}
	}

	while (!_stack.empty()) {
		if (_stack.top() != '(')
			answer += _stack.top();
		_stack.pop();
	}

	cout << answer;
}
#pragma endregion
#pragma region 1535 안녕    
void sol1535() {
	int n;
	cin >> n;
	vector<pair<int, int>> arr(n);
	vector<int> answer(101);

	for (int i = 0; i < n; i++) cin >> arr[i].first;
	for (int i = 0; i < n; i++) cin >> arr[i].second;

	for (int i = 0; i < n; i++) {
		for (int j = 100; j > 0; j--) {
			if (j - arr[i].first > 0) {
				answer[j] = max(answer[j - arr[i].first] + arr[i].second, answer[j]);
			}
		}
	}

	cout << answer[100];

}
#pragma endregion
#pragma region 12865 평범한 배낭    
void sol12865() {
	int n, m;
	cin >> n >> m;
	vector<int> answer(m + 1);

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		for (int j = m; j >= a; j--) {
			answer[j] = max(answer[j], b + answer[j - a]);
		}
	}

	cout << answer[m];
}
#pragma endregion
#pragma region 7562 나이트의 이동   
void sol7562() {
	int tc;
	cin >> tc;
	int dx[] = { 1,1,2,2,-1,-1,-2,-2 };
	int dy[] = { 2,-2,1,-1,2,-2,1,-1 };

	for (int t = 0; t < tc; t++) {
		int n;
		cin >> n;
		int answer = 99999;
		queue<pair<pair<int, int>, int>> q;
		vector<vector<bool>> board(n, vector<bool>(n, false));
		pair<int, int> start;
		pair<int, int> end;

		int a, b, c, d;
		cin >> a >> b >> c >> d;
		start = { a,b };
		end = { c,d };

		board[a][b] = true;
		q.push({ start,0 });

		while (!q.empty())
		{
			pair<int, int> now = q.front().first;
			int cnt = q.front().second;
			q.pop();

			//	cout << now.first << ' ' << now.second << '\n';

			if (now.first == end.first && now.second == end.second) {
				if (answer > cnt)
					answer = cnt;
			}

			for (int i = 0; i < 8; i++) {
				int nx = dx[i] + now.first;
				int ny = dy[i] + now.second;

				if (nx > -1 && ny > -1 && nx < n && ny < n && board[nx][ny] == false) {
					board[nx][ny] = true;
					q.push({ { nx,ny }, cnt + 1 });
				}
			}
		}
		cout << answer << '\n';
	}
}
#pragma endregion
#pragma region 2468 안전 영역  
void sol2468() {
	int n;
	cin >> n;
	vector<vector<int>> _map(n, vector<int>(n));
	int answer = 0;
	int M = 0;
	int dx[] = { 0,0,1,-1 };
	int dy[] = { 1,-1,0,0 };
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> _map[i][j];
			if (M < _map[i][j]) M = _map[i][j];
		}

	for (int k = 0; k <= M; k++) {
		int cnt = 0;
		vector<vector<bool>> visit(n, vector<bool>(n, false));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (_map[i][j] > k && visit[i][j] == false) {
					cnt++;
					visit[i][j] = true;
					queue<pair<int, int>> q;
					q.push({ i,j });

					while (!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;
						q.pop();

						for (int i = 0; i < 4; i++) {
							int nx = x + dx[i];
							int ny = y + dy[i];

							if (nx > -1 && ny > -1 && nx < n && ny < n && visit[nx][ny] == false && _map[nx][ny] > k) {
								visit[nx][ny] = true;
								q.push({ nx,ny });
							}
						}
					}
				}
			}
		}

		if (answer < cnt)
			answer = cnt;
	}

	cout << answer;
}
#pragma endregion
#pragma region 7569 토마토  
class Pos7569 {
public:
	int h = 0;
	int x = 0;
	int y = 0;

	Pos7569() {}
	Pos7569(int _h, int _x, int _y) : x(_x), y(_y), h(_h) {}
};
void sol7569() {
	int m, n, h;
	cin >> m >> n >> h;
	int answer = 0;
	vector<vector<vector<int>>> tomato(h, vector<vector<int>>(n, vector<int>(m)));
	queue<pair<Pos7569, int>> q;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++) {
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1) {
					q.push({ Pos7569(i,j,k) ,0 });
				}
			}

	int dx[] = { 0,0,1,-1,0,0 };
	int dy[] = { 1,-1,0,0,0,0 };
	int dh[] = { 0,0,0,0,1,-1 };


	while (!q.empty()) {
		Pos7569 pos = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (answer < cnt)
			answer = cnt;

		for (int i = 0; i < 6; i++) {
			int nx = pos.x + dx[i];
			int ny = pos.y + dy[i];
			int nh = pos.h + dh[i];

			if (nx > -1 && ny > -1 && nh > -1 && nx < n && ny < m && nh < h &&
				tomato[nh][nx][ny] == 0) {
				tomato[nh][nx][ny] = 1;
				q.push({ Pos7569(nh,nx,ny),cnt + 1 });
			}
		}
	}

	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
				if (tomato[i][j][k] == 0) {
					cout << -1;
					return;
				}

	cout << answer;
}
#pragma endregion
#pragma region 10026 적록색약   
int bfs10026(int n, vector<vector<char>>& _map) {
	vector<vector<bool>> visit(n, vector<bool>(n, false));
	queue<pair<int, int>> q;
	int cnt = 0;
	int dx[] = { 0,0,1,-1 };
	int dy[] = { 1,-1,0,0 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == false) {
				visit[i][j] = true;
				q.push({ i,j });
				cnt++;

				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int i = 0; i < 4; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];

						if (nx > -1 && ny > -1 && nx < n && ny < n && visit[nx][ny] == false && _map[nx][ny] == _map[x][y]) {
							visit[nx][ny] = true;
							q.push({ nx,ny });
						}
					}
				}
			}
		}
	}
	return cnt;
}

void sol10026() {
	int n;
	cin >> n;
	vector<vector<char>> _map(n, vector<char>(n));
	vector<vector<char>> _map2(n, vector<char>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			_map[i][j] = c;

			if (c == 'R')
				c = 'G';
			_map2[i][j] = c;
		}

	cout << bfs10026(n, _map) << ' ' << bfs10026(n, _map2);

}
#pragma endregion
#pragma region 5014 스타트링크    
void sol5014() {
	int n, start, end, u, d;
	cin >> n >> start >> end >> u >> d;
	queue<pair<int, int>> q;
	vector<bool> visit(n + 1, false);
	visit[start] = true;
	q.push({ start,0 });

	while (!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (now == end) {
			cout << cnt;
			return;
		}

		if (now + u <= n && now + u > 0 && visit[now + u] == false) {
			visit[now + u] = true;
			q.push({ now + u,cnt + 1 });
		}
		if (now - d <= n && now - d > 0 && visit[now - d] == false) {
			visit[now - d] = true;
			q.push({ now - d, cnt + 1 });
		}
	}

	cout << "use the stairs";

}
#pragma endregion
#pragma region 2573 빙산     
int check2573(int n, int m, vector<vector<int>>& _map) {
	queue<pair<int, int>> q;
	vector<vector<bool>> visit(n, vector<bool>(m, false));
	int dx[] = { 0,0,-1,1 };
	int dy[] = { -1,1,0,0 };
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (_map[i][j] != 0 && !visit[i][j]) {
				q.push({ i,j });
				visit[i][j] = true;
				cnt++;

				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int nx = dx[k] + x;
						int ny = dy[k] + y;

						if (nx <n && ny <m && nx>-1 && ny >-1 && !visit[nx][ny] &&
							_map[nx][ny] != 0) {
							visit[nx][ny] = true;
							q.push({ nx,ny });
						}
					}
				}

			}
		}
	}
	return cnt;
}

void sol2573() {
	int n, m;
	cin >> n >> m;
	int answer = 0;
	vector<vector<int>> _map(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> _map[i][j];

	while (true) {
		int cnt = check2573(n, m, _map);
		vector<vector<int>> melt(n, vector<int>(m));

		if (cnt == 0) {
			cout << 0;
			break;
		}
		else if (cnt > 1) {
			cout << answer;
			break;
		}
		answer++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (_map[i][j] != 0) {
					int dx[] = { 0,0,-1,1 };
					int dy[] = { -1,1,0,0 };

					for (int k = 0; k < 4; k++) {
						int nx = dx[k] + i;
						int ny = dy[k] + j;

						if (nx > -1 && ny > -1 && nx < n && ny < m && _map[nx][ny] == 0 && _map[i][j] != 0)
							melt[i][j]--;
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				_map[i][j] = _map[i][j] + melt[i][j] >= 0 ? _map[i][j] + melt[i][j] : 0;
			}
		}
	}
}
#pragma endregion
#pragma region 2805 나무 자르기     
void sol2805() {
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	long long answer = 0;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	long long lt = 0;
	long long rt = *max_element(arr.begin(), arr.end());

	while (lt <= rt) {
		int mid = (lt + rt) / 2;
		long long v = 0;

		for (int i = 0; i < n; i++) {
			v += arr[i] - mid >= 0 ? arr[i] - mid : 0;
		}

		if (v >= m) {
			lt = mid + 1;

			if (answer < mid)
				answer = mid;
		}
		else {
			rt = mid - 1;
		}

	}

	cout << answer;
}
#pragma endregion
#pragma region 1978 소수 찾기    
void sol1978() {
	int n;
	cin >> n;
	vector<bool> sosu(1001, true);
	int answer = 0;

	sosu[1] = false;
	for (int i = 2; i < 1001; i++) {
		if (sosu[i])
			for (int j = i * 2; j < 1001; j += i)
				sosu[j] = false;
	}

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		if (sosu[a])
			answer++;
	}

	cout << answer;
}
#pragma endregion
#pragma region 2231 분해합      
void sol2231() {
	int n;
	cin >> n;

	for (int i = 0; i < 1000001; i++) {
		int sum = i;
		int temp = i;

		while (temp != 0) {
			sum += temp % 10;
			temp /= 10;
		}

		if (sum == n) {
			cout << i;
			return;
		}
	}

	cout << 0;
}
#pragma endregion
#pragma region 7568 덩치       
void sol7568() {
	int n;
	cin >> n;
	vector<int> rank(n, 1);
	vector<pair<int, int>> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].first;
		cin >> p[i].second;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (p[i].first < p[j].first && p[i].second < p[j].second)
				rank[i]++;
		}
	}

	for (auto r : rank)
		cout << r << ' ';

}
#pragma endregion
#pragma region 1018 체스판 다시 칠하기       
void sol1018() {
	int n, m;
	cin >> n >> m;
	int mini = 999999999;
	vector<vector<char>> board(n, vector<char>(m));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (8 + i <= n && 8 + j <= m) {

				for (int t = 0; t < 2; t++) {
					char first = t == 0 ? 'W' : 'B';
					int cnt = 0;

					for (int k = i; k < 8 + i; k++) {
						first = first == 'W' ? 'B' : 'W';
						for (int l = j; l < 8 + j; l++) {
							if (board[k][l] != first)
								cnt++;
							first = first == 'W' ? 'B' : 'W';
						}
					}
					if (mini > cnt)
						mini = cnt;
				}
			}
		}
	}

	cout << mini;
}
#pragma endregion
#pragma region 1065 한수    
void sol1065() {
	int n;
	cin >> n;
	int answer = 0;

	for (int i = 1; i <= n; i++) {
		if (i < 10)
			answer++;
		else {
			int num = i;
			vector<int> arr;
			while (num != 0) {
				arr.push_back(num % 10);
				num /= 10;
			}
			int gap = arr[0] - arr[1];
			bool isHansu = true;
			for (int j = 0; j < arr.size() - 1; j++) {
				if (arr[j] - arr[j + 1] != gap) {
					isHansu = false;
					break;
				}
			}

			if (isHansu)
				answer++;
		}
	}
	cout << answer;
}
#pragma endregion
#pragma region 2309 일곱 난쟁이    
void func2309(int i, vector<int>& arr, vector<int>& visit, int sum, bool& isEnd) {

	if (isEnd) return;

	if (sum == 100 && visit.size() == 7) {
		sort(visit.begin(), visit.end());
		for (int v : visit)
			cout << v << '\n';
		isEnd = true;
	}
	else if (i >= 9 || visit.size() > 7) return;
	else {
		visit.push_back(arr[i]);
		func2309(i + 1, arr, visit, sum + arr[i], isEnd);
		visit.pop_back();
		func2309(i + 1, arr, visit, sum, isEnd);
	}
}
void sol2309() {
	vector<int> arr(9);
	vector<int> visit;
	bool isEnd = false;
	for (int i = 0; i < 9; i++)
		cin >> arr[i];
	func2309(0, arr, visit, 0, isEnd);
}
#pragma endregion
#pragma region 14501 퇴사
void func14501(vector<pair<int, int>>& arr, int n, int d, int sum, int& _max) {
	if (d >= n) {
		if (sum > _max)
			_max = sum;
	}
	else {
		if (d + arr[d].first <= n)
			func14501(arr, n, arr[d].first + d, sum + arr[d].second, _max);
		func14501(arr, n, 1 + d, sum, _max);
	}
}

void sol14501() {
	int n;
	cin >> n;
	int _max = 0;
	vector<pair<int, int>> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i].first;
		cin >> arr[i].second;
	}

	func14501(arr, n, 0, 0, _max);

	cout << _max;
}
#pragma endregion
#pragma region 14501 퇴사 더 간단.
void sol14501_2() {
	int n;	cin >> n;
	vector<int> arr(n + 1);

	for (int i = 0; i < n; i++) {
		int date, value;
		cin >> date >> value;

		if (date + i <= n)
			arr[i + date] = max(arr[i + date], arr[i] + value);
		arr[i + 1] = max(arr[i], arr[i + 1]);
	}
	cout << arr[n];
}
#pragma endregion
#pragma region 14502 연구소
vector<vector<int>> spreadVirus14502(int n, int m, vector<vector<int>> _map) {
	int dx[] = { 0,0,-1,1 };
	int dy[] = { -1,1,0,0 };
	vector<vector<bool>> visit(n, vector<bool>(m, false));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (_map[i][j] == 2 && !visit[i][j]) {
				queue<pair<int, int>> q;
				q.push({ i,j });
				visit[i][j] = true;

				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int i = 0; i < 4; i++) {
						int nx = dx[i] + x;
						int ny = dy[i] + y;

						if (nx > -1 && ny > -1 && nx < n && ny < m &&
							_map[nx][ny] == 0 && !visit[nx][ny]) {
							_map[nx][ny] = 2;
							visit[nx][ny] = true;
							q.push({ nx,ny });
						}
					}
				}
			}
		}
	}

	return _map;
}
int countSafeArea14502(int n, int m, vector<vector<int>> _map) {
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (_map[i][j] == 0)
				cnt++;

	return cnt;
}
void func14502(int n, int m, vector<vector<int>> _map, int wall, int& answer) {
	if (wall == 3) {
		int area = countSafeArea14502(n, m, spreadVirus14502(n, m, _map));
		if (area > answer)
			answer = area;
	}
	else {

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (_map[i][j] == 0) {
					_map[i][j] = 1;
					func14502(n, m, _map, wall + 1, answer);
					_map[i][j] = 0;
				}
			}
		}

	}
}
void sol14502() {
	int n, m;
	cin >> n >> m;
	int answer = 0;
	vector<vector<int>> _map(n, vector<int>(m));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> _map[i][j];

	func14502(n, m, _map, 0, answer);
	cout << answer;
}
#pragma endregion
#pragma region 14888 연산자 끼워넣기
void func14888(int l, int n, vector<int>& nums, vector<int>& op, int& _max, int& _min, long long sum) {
	if (l == n) {
		if (sum > _max) _max = sum;
		if (sum < _min) _min = sum;
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (op[i] > 0) {
				op[i]--;
				if (i == 0) func14888(l + 1, n, nums, op, _max, _min, sum + nums[l]);
				else if (i == 1) func14888(l + 1, n, nums, op, _max, _min, sum - nums[l]);
				else if (i == 2) func14888(l + 1, n, nums, op, _max, _min, sum * nums[l]);
				else if (i == 3) func14888(l + 1, n, nums, op, _max, _min, sum / nums[l]);
				op[i]++;
			}
		}
	}
}

void sol14888() {
	int n;
	cin >> n;
	int _max = -2000000000;
	int _min = 2000000000;
	vector<int> nums(n);
	vector<int> op(4);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	for (int i = 0; i < 4; i++)
		cin >> op[i];

	func14888(1, n, nums, op, _max, _min, nums[0]);

	cout << _max << '\n' << _min;
}
#pragma endregion
#pragma region 14889 스타트와 링크
void func14889(int n, vector<vector<int>>& arr, vector<bool>& visit, int l, int cnt, int& answer) {
	if (l == n) {
		if (cnt == n / 2) {
			int start = 0;
			int link = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (visit[i] == visit[j]) {
						if (visit[i])
							start += (arr[i][j]);
						else
							link += (arr[i][j]);
					}
				}
			}

			int gap = abs(start - link);
			if (answer > gap)
				answer = gap;
		}

	}
	else {
		visit[l] = true;
		func14889(n, arr, visit, l + 1, cnt + 1, answer);
		visit[l] = false;
		func14889(n, arr, visit, l + 1, cnt, answer);

	}
}
void sol14889() {
	int n;
	cin >> n;
	int answer = 2000000000;
	vector<vector<int>> arr(n, vector<int>(n));
	vector<bool> visit(n, false);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	func14889(n, arr, visit, 0, 0, answer);

	cout << answer;
}
#pragma endregion
#pragma region 1182 부분수열의 합
void func1182(int n, int m, int l, vector<int>& arr, int sum, int& answer) {
	if (n == l) {
		if (sum == m)
			answer++;
	}
	else {
		func1182(n, m, l + 1, arr, sum + arr[l], answer);
		func1182(n, m, l + 1, arr, sum, answer);
	}
}

void sol1182() {
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	int answer = 0;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	func1182(n, m, 0, arr, 0, answer);

	if (m == 0) answer = -1;
	cout << answer;
}
#pragma endregion
#pragma region 1759 암호 만들기
void func1759(int l, int c, int d, vector<char>& v, string str) {
	if (str.size() == l) {
		int m = 0, j = 0;
		for (char s : str) {
			if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u')
				m++;
			else
				j++;
		}

		if (m > 0 && j > 1)
			cout << str << '\n';
	}
	else {
		if (d == c) return;
		func1759(l, c, d + 1, v, str + v[d]);
		func1759(l, c, d + 1, v, str);
	}
}

void sol1759() {
	int l, c;
	cin >> l >> c;
	vector<char> v(c);
	for (int i = 0; i < c; i++)
		cin >> v[i];

	sort(v.begin(), v.end());
	func1759(l, c, 0, v, "");

}
#pragma endregion
#pragma region 10819 차이를 최대로
void sol10819() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int answer = -99999999;
	sort(arr.begin(), arr.end());
	do {
		int sum = 0;
		for (int i = 0; i < n - 1; i++) 
			sum += abs(arr[i] - arr[i + 1]);

		if (sum > answer)
			answer = sum;
	} while (next_permutation(arr.begin(), arr.end()));

	cout << answer;
}
#pragma endregion
#pragma region 10974 모든 순열
void sol10974() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		arr[i] = i + 1;

	do {
		for (int i = 0; i < n; i++)
			cout << arr[i] << ' ';
		cout << '\n';

	} while (next_permutation(arr.begin(), arr.end()));

}
#pragma endregion
#pragma region 10430 나머지
void sol10430() {
	int A, B, C;
	cin >> A >> B >> C;

	cout << (A + B) % C << '\n';
	cout << ((A % C) + (B % C)) % C << '\n';
	cout << (A * B) % C << '\n';
	cout << ((A % C) * (B % C)) % C << '\n';
}
#pragma endregion
#pragma region 1037 약수
void sol1037() {
	int n;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	cout << arr.front() * arr.back();
}
#pragma endregion
#pragma region 2609 최대공약수와 최소공배수
void sol2609() {
	int a, b;
	cin >> a >> b;

	if (a < b) {
		int temp = a;
		a = b;
		b = temp;
	}

	int M, m;

	for (int i = 1; i <= a; i++) {
		if (a % i == 0 && b % i == 0)
			m = i;
	}

	M = m * a / m * b / m;
	cout << m << '\n' << M;
}
#pragma endregion
#pragma region 6588 골드바흐의 추측
void sol6588() {
	vector<bool> arr(1000001, true);
	arr[1] = false;

	for (int i = 2; i < 1000001; i++) {
		if (arr[i]) {
			for (int j = i * 2; j < 1000001; j += i) {
				arr[j] = false;
			}
		}
	}
	for (int i = 2; i < 1000001; i++) {
		if (i % 2 == 0)
			arr[i] = false;
	}

	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;

		bool isFind = false;
		for (int i = 3; i < 1000001; i++) {
			if (n - i > -1 && arr[i] && arr[n - i]) {
				cout << n << " = " << i << " + " << n - i << '\n';
				isFind = true;
				break;
			}
		}

		if (!isFind)
			cout << "Goldbach's conjecture is wrong.\n";

	}

}
#pragma endregion
#pragma region 1476 날짜 계산
void sol1476() {
	int e, s, m;
	cin >> e >> s >> m;
	int ee = 0, ss = 0, mm = 0;
	int year = 0;

	while (!(ee == e && ss == s && mm == m)) {
		ee = (ee + 1) % 16 == 0 ? 1 : (ee + 1) % 16;
		ss = (ss + 1) % 29 == 0 ? 1 : (ss + 1) % 29;
		mm = (mm + 1) % 20 == 0 ? 1 : (mm + 1) % 20;
		year++;
	}

	cout << year;
}
#pragma endregion
#pragma region 1748 수 이어 쓰기 1
void sol1748() {
	int n;
	cin >> n;
	long long answer = 0;

	int idx = 1;
	int nine = 9;

	while (1) {
		if (nine <= n) {
			n -= nine;
			answer += nine * idx;

			nine *= 10;
			idx++;
		}
		else {
			answer += (idx * n);
			break;
		}
	}
	cout << answer;
}
#pragma endregion
#pragma region 3273 두 수의 합
void sol3273() {
	int n;
	cin >> n;
	vector<bool> arr(2000001, false);
	int answer = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[a] = true;
	}
	int x;
	cin >> x;

	for (int i = 1; x - i >= 0; i++) {
		if (i != x - i && arr[i] && arr[x - i])
			answer++;
	}

	cout << answer / 2;
}
#pragma endregion
#pragma region 1158 요세푸스 문제
void sol1158() {
	int n, k;
	cin >> n >> k;
	queue<int> q;
	vector<int> answer;

	for (int i = 1; i <= n; i++)
		q.push(i);

	int index = 0;
	while (!q.empty()) {
		index = (index + 1) % k;

		if (index == 0) answer.push_back(q.front());
		else q.push(q.front());

		q.pop();
	}

	cout << '<';
	for (int i = 0; i < answer.size() - 1; i++)
		cout << answer[i] << ", ";

	cout << answer.back() << ">";
}
#pragma endregion
#pragma region 5397 키로거
void sol5397() {
	int tc;
	cin >> tc;

	for (int t = 0; t < tc; t++) {
		string str;
		cin >> str;
		list<char> l;

		auto it = l.begin();

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '<') {
				if (!l.empty() && it != l.begin())
					it--;
			}
			else if (str[i] == '>') {
				if (!l.empty() && it != l.end())
					it++;
			}
			else if (str[i] == '-') {
				if (!l.empty() && it != l.begin())
					it = l.erase(--it);
			}
			else {
				it = l.insert(it, str[i]);
				it++;
			}
		}

		for (auto c : l)
			cout << c;
		cout << '\n';

		/*string newStr="";
		auto it = newStr.begin();
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '<') {
				if (!newStr.empty() && it != newStr.begin() )
					it--;
			}
			else if (str[i] == '>') {
				if (!newStr.empty() && it != newStr.end())
					it++;
			}
			else if (str[i] == '-') {
				if(!newStr.empty() && it != newStr.begin())
					it = newStr.erase(--it);
			}
			else {
				it = newStr.insert(it, str[i]);
				it++;
			}
		}

		cout << newStr <<'\n';*/
	}
}
#pragma endregion
#pragma region 10845 큐 
void sol10845() {
	int n;
	cin >> n;
	list<int> q;

	for (int i = 0; i < n; i++) {
		string op;
		cin >> op;

		if (op == "push") {
			int x;
			cin >> x;
			q.push_back(x);
		}
		else if (op == "pop") {
			if (q.empty())
				cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
				q.pop_front();
			}
		}
		else if (op == "size") {
			cout << q.size() << '\n';
		}
		else if (op == "empty") {
			cout << q.empty() << '\n';
		}
		else if (op == "front") {
			cout << ((q.empty()) ? -1 : q.front()) << '\n';
		}
		else if (op == "back") {
			cout << ((q.empty()) ? -1 : q.back()) << '\n';
		}
	}
}
#pragma endregion
#pragma region 2164 카드2 
void sol2164() {
	int n;
	cin >> n;
	queue<int> q;

	for (int i = 1; i <= n; i++)
		q.push(i);

	while (q.size() != 1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}

	cout << q.front();
}
#pragma endregion
#pragma region 6198 옥상 정원 꾸미기 
void sol6198() {
	stack<long long> s;
	long long answer = 0;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;

		while (!s.empty() && s.top() <= x)
			s.pop();

		answer += s.size();
		s.push(x);

	}

	cout << answer;
}
#pragma endregion
#pragma region 2493 탑  
void sol2493() {
	stack<pair<int, int>> s;
	int n;
	cin >> n;
	vector<pair<int, int>> arr(n);
	vector<int> answer(n);

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[i] = { a,i + 1 };
	}

	for (int i = 0; i < n; i++) {

		while (!s.empty() && s.top().first <= arr[i].first) {
			s.pop();
		}

		if (!s.empty() && s.top().first > arr[i].first)
			answer[i] = s.top().second;

		s.push(arr[i]);
	}

	for (int a : answer)
		cout << a << ' ';

}
#pragma endregion
#pragma region 10866 덱  
void sol10866() {
	int n;
	cin >> n;
	list<int> l;

	for (int i = 0; i < n; i++) {
		string op;
		cin >> op;

		if (op == "push_front") {
			int x;
			cin >> x;
			l.push_front(x);
		}
		else if (op == "push_back") {
			int x;
			cin >> x;
			l.push_back(x);
		}
		else if (op == "pop_front") {
			if (l.empty())
				cout << -1 << '\n';
			else {
				cout << l.front() << '\n';
				l.pop_front();
			}
		}
		else if (op == "pop_back") {
			if (l.empty())
				cout << -1 << '\n';
			else {
				cout << l.back() << '\n';
				l.pop_back();
			}
		}
		else if (op == "size") {
			cout << l.size() << '\n';
		}
		else if (op == "empty") {
			cout << l.empty() << '\n';
		}
		else if (op == "front") {
			cout << (l.empty() ? -1 : l.front()) << '\n';
		}
		else if (op == "back") {
			cout << (l.empty() ? -1 : l.back()) << '\n';
		}
	}
}
#pragma endregion
#pragma region 5430 AC  
void sol5430() {
	int tc;
	cin >> tc;

	for (int t = 0; t < tc; t++) {
		string op;
		string numStr;
		int n;
		cin >> op >> n >> numStr;
		list<int> num;
		bool isRevere = false;
		bool isError = false;

		string temp;
		for (int i = 0; i < numStr.size(); i++) {
			if (numStr[i] != '[' && numStr[i] != ']' && numStr[i] != ',') {
				temp += numStr[i];
			}
			else if (numStr[i] == ',') {
				num.push_back(stoi(temp));
				temp = "";
			}
		}

		if (!temp.empty())
			num.push_back(stoi(temp));

		for (int i = 0; i < op.size(); i++) {
			if (op[i] == 'D') {
				if (num.empty()) {
					cout << "error\n";
					isError = true;
					break;
				}
				else {
					if (!isRevere)
						num.pop_front();
					else
						num.pop_back();
				}
			}
			else {
				isRevere = !isRevere;
			}
		}

		if (!isError) {
			cout << '[';
			int size = num.size();
			if (!isRevere) {
				for (auto it = num.begin(); it != num.end(); it++) {
					cout << *it;
					if (size-- != 1)
						cout << ',';
				}

			}
			else {
				for (auto it = num.rbegin(); it != num.rend(); it++) {
					cout << *it;
					if (size-- != 1)
						cout << ',';
				}
			}
			cout << "]\n";
		}
	}
}
#pragma endregion
#pragma region 1920 수 찾기  
void sol1920() {
	int n;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;

		int lt = 0;
		int rt = n - 1;
		bool isExist = false;
		while (lt <= rt) {
			int mid = (lt + rt) / 2;

			if (arr[mid] == x) {
				isExist = true;
				break;
			}
			else if (arr[mid] > x) {
				rt = mid - 1;
			}
			else {
				lt = mid + 1;
			}
		}

		if (isExist)
			cout << "1\n";
		else
			cout << "0\n";
	}
}
#pragma endregion
#pragma region 10816 숫자 카드 2  
void sol10816() {
	int n;
	cin >> n;
	vector<int> arr(20000001);

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x < 0) {
			x = abs(x) + 10000000;
		}
		arr[x]++;
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		if (x < 0) {
			x = abs(x) + 10000000;
		}
		cout << arr[x] << ' ';
	}
}
#pragma endregion
#pragma region 2003 수들의 합 2 
void sol2003() {
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	int answer = 0;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		int sum = arr[i];

		if (sum == m) {
			answer++;
			continue;
		}

		if (sum > m)
			continue;

		for (int j = i + 1; j < n; j++) {
			sum += arr[j];

			if (sum == m) {
				answer++;
				break;
			}
			if (sum > m)
				break;
		}
	}
	cout << answer;
}
#pragma endregion
#pragma region 1197 최소 스패닝 트리
int findParent1197(int a, vector<int>& nodeUnion) {
	if (nodeUnion[a] == a) return a;
	else return nodeUnion[a] = findParent1197(nodeUnion[a], nodeUnion);
}

void unionNodes1197(int a, int b, vector<int>& nodeUnion) {
	a = findParent1197(a, nodeUnion);
	b = findParent1197(b, nodeUnion);

	if (a > b)
		nodeUnion[a] = b;
	else
		nodeUnion[b] = a;
}
void sol1197() {
	int v, e;
	cin >> v >> e;
	vector<int> nodeUnion(v + 1);
	priority_queue<pair<int, pair<int, int>>> q;
	int answer = 0;
	for (int i = 1; i <= v; i++)
		nodeUnion[i] = i;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		q.push({ -c,{a,b} });
	}

	while (!q.empty())
	{
		int from = q.top().second.first;
		int to = q.top().second.second;
		int dist = -q.top().first;
		q.pop();

		if (findParent1197(from, nodeUnion) != findParent1197(to, nodeUnion)) {
			unionNodes1197(from, to, nodeUnion);
			answer += dist;
		}
	}

	cout << answer;
}
#pragma endregion
#pragma region 4386 별자리 만들기
int findParent4386(int a, vector<int>& nodeUnion) {
	if (nodeUnion[a] == a) return a;
	else return nodeUnion[a] = findParent4386(nodeUnion[a], nodeUnion);
}

void unionNodes4386(int a, int b, vector<int>& nodeUnion) {
	a = findParent4386(a, nodeUnion);
	b = findParent4386(b, nodeUnion);

	if (a > b)
		nodeUnion[a] = b;
	else
		nodeUnion[b] = a;
}
void sol4386() {
	int n;
	cin >> n;
	double answer = 0;
	vector<pair<int, int>> vertex(n + 1);
	vector<int> nodeUnion(n + 1);
	priority_queue<pair<int, pair<int, int>>> q;
	for (int i = 1; i <= n; i++) {
		double a, b;
		cin >> a >> b;
		vertex[i] = { a * 100, b * 100 };

		nodeUnion[i] = i;
	}

	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int dist = sqrt(pow(vertex[i].first - vertex[j].first, 2) +
				pow(vertex[i].second - vertex[j].second, 2));

			q.push({ -dist,{i,j} });
		}
	}

	while (!q.empty()) {
		int from = q.top().second.first;
		int to = q.top().second.second;
		int dist = -q.top().first;
		q.pop();

		if (findParent4386(from, nodeUnion) != findParent4386(to, nodeUnion)) {
			unionNodes4386(from, to, nodeUnion);
			answer += dist;
		}
	}

	cout << answer / 100;

}
#pragma endregion
#pragma region 1922 네트워크 연결
int findParent1922(int a, vector<int>& nodeUnion) {
	if (nodeUnion[a] == a) return a;
	else return nodeUnion[a] = findParent1922(nodeUnion[a], nodeUnion);
}

void unionNodes1922(int a, int b, vector<int>& nodeUnion) {
	a = findParent1922(a, nodeUnion);
	b = findParent1922(b, nodeUnion);

	if (a > b)
		nodeUnion[a] = b;
	else
		nodeUnion[b] = a;
}
void sol1922() {
	int n, m;
	cin >> n >> m;
	priority_queue<pair<int, pair<int, int>>> q;
	vector<int> nodeUnion(n + 1);
	int answer = 0;

	for (int i = 1; i <= n; i++)
		nodeUnion[i] = i;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		q.push({ -c,{a,b} });
	}

	while (!q.empty()) {
		int from = q.top().second.first;
		int to = q.top().second.second;
		int dist = -q.top().first;
		q.pop();

		if (findParent1922(from, nodeUnion) != findParent1922(to, nodeUnion)) {
			unionNodes1922(from, to, nodeUnion);
			answer += dist;
		}
	}

	cout << answer;

}
#pragma endregion
#pragma region 6497 전력난
int findParent6497(int a, vector<int>& nodeUnion) {
	if (nodeUnion[a] == a) return a;
	else return nodeUnion[a] = findParent6497(nodeUnion[a], nodeUnion);
}

void unionNodes6497(int a, int b, vector<int>& nodeUnion) {
	a = findParent6497(a, nodeUnion);
	b = findParent6497(b, nodeUnion);

	if (a > b)
		nodeUnion[a] = b;
	else
		nodeUnion[b] = a;
}
void sol6497() {

	while (true) {
		int n, m;
		cin >> n >> m;

		if (n == 0 && m == 0)
			break;

		priority_queue<pair<int, pair<int, int>>> q;
		vector<int> nodeUnion(n);
		int answer = 0;
		int sum = 0;
		for (int i = 0; i < n; i++)
			nodeUnion[i] = i;

		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			q.push({ -c,{a,b} });
			sum += c;
		}

		while (!q.empty()) {
			int from = q.top().second.first;
			int to = q.top().second.second;
			int dist = -q.top().first;
			q.pop();

			if (findParent6497(from, nodeUnion) != findParent6497(to, nodeUnion)) {
				unionNodes6497(from, to, nodeUnion);
				answer += dist;
			}
		}

		cout << sum - answer;
	}
}
#pragma endregion
#pragma region 11404 플로이드
void sol11404() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n + 1, vector<int>(n + 1, 999999999));

	for (int i = 0; i <= n; i++)
		graph[i][i] = 0;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = min(c, graph[a][b]);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] == 999999999)
				cout << 0 << ' ';
			else
				cout << graph[i][j] << ' ';
		}
		cout << '\n';
	}
}
#pragma endregion
#pragma region 11403 경로 찾기
void sol11403() {
	int n;
	cin >> n;
	vector<vector<int>> graph(n + 1, vector<int>(n + 1, 999999999));

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int a;
			cin >> a;
			if (a == 0)
				graph[i][j] = 999999999;
			else
				graph[i][j] = a;
		}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] == 999999999)
				cout << 0 << ' ';
			else
				cout << '1' << ' ';
		}
		cout << '\n';
	}
}
#pragma endregion
#pragma region 14588 Line Friends (Small)
void sol14588() {
	int n;
	cin >> n;
	int DEF = 999999999;
	vector<vector<int>> graph(n + 1, vector<int>(n + 1, DEF));
	vector<pair<int, int>> v(1);

	for (int i = 1; i <= n; i++) {
		int from, to;
		cin >> from >> to;

		for (int j = 1; j < v.size(); j++) {
			if (i != j && (from >= v[j].first && from <= v[j].second) ||
				(to >= v[j].first && to <= v[j].second) ||
				(from <= v[j].first && to >= v[j].second) ||
				(from >= v[j].first && to <= v[j].second)) {
				graph[i][j] = 1;
				graph[j][i] = 1;
			}
		}
		v.push_back({ from,to });
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		if (graph[v1][v2] == DEF)
			cout << "-1\n";
		else
			cout << graph[v1][v2] << '\n';
	}

}
#pragma endregion
#pragma region 5052 전화번호 목록
class tri_node5052 {
public:
	vector<tri_node5052*> arr;
	bool isFinish = false;

	tri_node5052() {
		arr = vector<tri_node5052*>(10, nullptr);
	}

	bool addNum(string& num, int index, tri_node5052& tri) {
		if (index == num.size()) {
			tri.isFinish = true;
			return true;
		}

		if (tri.isFinish)
			return false;

		int n = num[index] - '0';

		if (tri.arr[n] == nullptr)
			tri.arr[n] = new tri_node5052();

		return addNum(num, index + 1, *tri.arr[n]);
	}
};

void sol5052() {
	int tc;
	cin >> tc;

	for (int t = 0; t < tc; t++) {
		int n;
		cin >> n;
		bool isGood = true;
		tri_node5052 tri;
		vector<string> nums(n);
		for (int i = 0; i < n; i++) {
			cin >> nums[i];
		}

		sort(nums.begin(), nums.end());

		for (int i = 0; i < n; i++) {
			if (!tri.addNum(nums[i], 0, tri)) {
				isGood = false;
				break;
			}
		}

		if (isGood)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
#pragma endregion

/*
	double을 int로 변환시 0.5를 더해줘야함.
*/
#pragma region 4781 사탕 가게    
void sol4781() {

	while (true) {
		int n, m;
		double mm;
		cin >> n >> mm;
		vector<pair<int, int>> arr(n);
		m = mm * 100.0 + 0.5;
		vector<int> answer(m + 1);

		if (n == 0 && m == 0.0) break;

		for (int i = 0; i < n; i++) {
			int a;
			double b;
			cin >> a >> b;
			arr[i] = { a,b * 100.0 + 0.5 };
		}

		for (int i = 0; i < n; i++) {
			for (int j = arr[i].second; j < m + 1; j++) {
				answer[j] = max(answer[j], arr[i].first + answer[j - arr[i].second]);
			}
		}

		cout << *max_element(answer.begin(), answer.end()) << '\n';
	}
}
#pragma endregion
/*
	도저히 생각해내지 못했다..
	지수 공식을 사용해서 시간복잡도를 n-> logN으로 할 수 있다니.
*/
#pragma region 1629 곱셉
int power1629(int a, int b, int c) {
	if (b == 0) return 1;

	int temp = power1629(a, b / 2, c);
	int result = (1LL * temp * temp) % c;

	if (b % 2) result = 1LL * result * a % c;

	return result;
}
void sol1629() {
	int a, b, c;
	cin >> a >> b >> c;

	cout << power1629(a, b, c);
}
#pragma endregion
/*
	풀긴 했으니 다른 풀이가 참신함
	index 값을 매개변수로 넣어 숫자들을 오름차순으로 만듬.
*/
#pragma region 15650 N과 M (2)
void func15650(int n, int m, int index, vector<int> num) {
	if (num.size() == m) {
		for (int i = 0; i < m; i++)
			cout << num[i] << ' ';
		cout << '\n';
	}
	else {
		for (int i = index; i <= n; i++) {
			num.push_back(i);
			func15650(n, m, i + 1, num);
			num.pop_back();
		}
	}
}

void sol15650() {
	int n, m;
	cin >> n >> m;

	func15650(n, m, 1, {});
}
#pragma endregion
/*
	문제 자체는 어렵지 않았음.
	union 배열에 1과 연결된 노드들은 모두 1로 저장될 줄 알았으나
	그게 아님. 한버더 findParent 함수로 1과 연결 되어있는지 확인해야함.
*/
#pragma region 2606 바이러스 
int findParent2606(vector<int>& _union, int a) {
	if (_union[a] == a) return a;
	else
		return _union[a] = findParent2606(_union, _union[a]);
}

void unionNode2606(vector<int>& _union, int a, int b) {
	a = findParent2606(_union, a);
	b = findParent2606(_union, b);

	if (a > b)
		_union[a] = b;
	else
		_union[b] = a;
}

void sol2606() {
	int n, m;
	cin >> n >> m;
	vector<int> _union(n + 1);

	for (int i = 1; i < n + 1; i++)
		_union[i] = i;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		unionNode2606(_union, a, b);
	}

	int answer = 0;
	for (int i = 2; i < n + 1; i++) {
		if (findParent2606(_union, _union[i]) == 1)
			answer++;
	}

	cout << answer;
}
#pragma endregion
/*
	이런 점화식은 좀.. 바로 알아내기 힘들었음.
*/
#pragma region 9465 스티커  
void sol9465() {
	int tc;
	cin >> tc;

	for (int t = 0; t < tc; t++) {
		int n;
		cin >> n;
		vector<vector<int>> arr(2, vector<int>(n + 1));
		vector<vector<int>> dp(2, vector<int>(n + 1));

		for (int i = 0; i < 2; i++)
			for (int j = 1; j <= n; j++)
				cin >> arr[i][j];

		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];

		for (int j = 2; j <= n; j++) {
			dp[0][j] = max(dp[1][j - 2], dp[1][j - 1]) + arr[0][j];
			dp[1][j] = max(dp[0][j - 2], dp[0][j - 1]) + arr[1][j];
		}

		cout << max(dp[0][n], dp[1][n]) << '\n';
	}
}
#pragma endregion
/*
	vector, list 삽입,삭제시 시간 복잡도를 생각했어야함.
	그리고 list의 it는 it+1 연산은 안되지만 it++ 은 됨.
*/
#pragma region 1406 에디터   
void sol1406() {
	string s;
	int n;
	cin >> s >> n;

	list<char> str;

	for (char c : s)
		str.push_back(c);

	auto cursor = str.end();

	for (int i = 0; i < n; i++) {
		char op;
		cin >> op;

		if (op == 'L') {
			if (cursor != str.begin())
				cursor--;
		}
		else if (op == 'D') {
			if (cursor != str.end())
				cursor++;
		}
		else if (op == 'B') {
			if (cursor != str.begin()) {
				cursor--;
				cursor = str.erase(cursor);
			}
		}
		else if (op == 'P') {
			char newC;
			cin >> newC;
			cursor = str.insert(cursor, newC);
			cursor++;
		}
	}

	for (auto it = str.begin(); it != str.end(); it++)
		cout << *it;
}
#pragma endregion
/*
	나누기 연산하는데 나머지 연산으로 시간 속도를 개선
*/
#pragma region 10430 나머지
void sol10430() {
	while (true) {
		long long n;
		long long answer = 1;
		int cnt = 1;
		cin >> n;

		while (true) {
			if (answer % n == 0) {
				cout << cnt << '\n';
				break;
			}
			else {
				cnt++;
				answer %= n;
				answer = answer * 10 + 1;
			}

		}
	}
}
#pragma endregion
/*
* 약수의 특성
*  1 ~ n번째 까지의  k의 갯수 = n/k
*/
#pragma region 17425 약수의 합
void sol17425() {
	int n;
	cin >> n;
	long long ans = 0;

	for (int i = 1; i < n + 1; i++) {
		ans += (n / i) * i;
	}

	cout << ans;
}
#pragma endregion
/*
	단순 구현하는 문제. 
	생각지 못한 예외가 많고 2차원 배열을 너무 어렵게 생각함.
	swap 함수 배움.
*/
#pragma region 3085 사탕 게임
void count13085(vector<vector<char>>& arr, int& answer) {
	int n = arr.size();

	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 0; j < n - 1; j++) {
			if (arr[i][j] == arr[i][j + 1])
				cnt++;
			else {
				if (cnt > answer)
					answer = cnt;
				cnt = 1;
			}
		}
		if (cnt > answer)
			answer = cnt;
	}
}
void count23085(vector<vector<char>>& arr, int& answer) {
	int n = arr.size();

	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 0; j < n - 1; j++) {
			if (arr[j][i] == arr[j + 1][i])
				cnt++;
			else {
				if (cnt > answer)
					answer = cnt;
				cnt = 1;
			}
		}
		if (cnt > answer)
			answer = cnt;
	}
}
void sol3085() {
	int n;
	cin >> n;
	vector<vector<char>> arr(n, vector<char>(n));
	int answer = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	count13085(arr, answer);
	count23085(arr, answer);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			swap(arr[i][j], arr[i][j + 1]);
			count13085(arr, answer);
			count23085(arr, answer);
			swap(arr[i][j + 1], arr[i][j]);

			swap(arr[j][i], arr[j + 1][i]);
			count13085(arr, answer);
			count23085(arr, answer);
			swap(arr[j + 1][i], arr[j][i]);
		}
	}

	cout << answer;
}
#pragma endregion
/*
	이진탐색시 조건이 항상 s<=e 가 되지 않는다.
	0과 가까운수를 구한다면 절대값으로 최대한 작은 값을 구하면 된다.
*/
#pragma region 14921 용액 합성하기 
void sol14921() {
	int n;
	cin >> n;
	vector<long long> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	long long answer = 1e9 + 1;

	int s = 0;
	int e = n - 1;

	while (s != e) {
		long long sum = arr[s] + arr[e];
		if (abs(sum) < abs(answer))
			answer = sum;

		if (sum > 0) e--;
		else if (sum < 0) s++;
		else break;
	}

	cout << answer;
}
#pragma endregion