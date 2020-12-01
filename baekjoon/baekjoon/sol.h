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

