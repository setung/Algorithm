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