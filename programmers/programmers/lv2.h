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

#pragma region 12909 올바른 괄호
bool solution12909(string s)
{
	stack<char> st;

	for (char c : s) {
		if (c == '(')
			st.push(c);
		else {
			if (st.empty())
				return false;
			st.pop();
		}
	}

	if (!st.empty())
		return false;

	return true;
}
#pragma endregion
#pragma region 12945 피보나치 수
int solution12945(int n) {
	vector<int> v(n + 1);
	v[0] = 0;
	v[1] = 1;

	for (int i = 2; i <= n; i++)
		v[i] = (v[i - 2] + v[i - 1]) % 1234567;

	return v[n];
}
#pragma endregion
#pragma region 12911 다음 큰 숫자
int solution12911(int n) {
	int oneCount = 0;
	int temp = n;

	while (temp != 0) {
		if (temp % 2 == 1)
			oneCount++;
		temp /= 2;
	}

	while (true) {
		temp = ++n;
		int count = 0;

		while (temp != 0) {
			if (temp % 2 == 1)
				count++;
			temp /= 2;
		}

		if (oneCount == count) {
			break;
		}
	}

	return n;
}
#pragma endregion
#pragma region 42587 프린터
int solution42587(vector<int> priorities, int location) {
	int answer = 0;
	deque<pair<int, int>> dq;
	int count = 0;
	for (int i = 0; i < priorities.size(); i++)
		dq.push_back({ i,priorities[i] });

	while (!dq.empty()) {
		bool isPrint = true;
		for (int i = 1; i < dq.size(); i++) {
			if (dq.front().second < dq[i].second) {
				dq.push_back(dq.front());
				dq.pop_front();
				isPrint = false;
				break;
			}
		}

		if (isPrint) {
			count++;
			if (dq.front().first == location) {
				answer = count;
				break;
			}
			dq.pop_front();
		}
	}

	return answer;
}
#pragma endregion
#pragma region 43165 타켓 넘버  
void dfs43165(int l, vector<int>& numbers, int target, int num, int& answer) {
	if (l == numbers.size()) {
		if (num == target)
			answer++;
	}
	else {
		dfs43165(l + 1, numbers, target, num + numbers[l], answer);
		dfs43165(l + 1, numbers, target, num - numbers[l], answer);
	}
}
int solution43165(vector<int> numbers, int target) {
	int answer = 0;

	dfs43165(0, numbers, target, 0, answer);

	return answer;
}
#pragma endregion
#pragma region 1829 카카오프렌즈 컬러링북
vector<int> solution1829(int m, int n, vector<vector<int>> picture) {
	vector<int> answer;
	int dx[] = { 0,0,1,-1 };
	int dy[] = { 1,-1,0,0 };
	vector<vector<bool>> visit(m, vector<bool>(n, false));
	queue<pair<int, int>> q;
	int max_size_of_one_area = 0;
	int number_of_area = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (picture[i][j] != 0 && !visit[i][j]) {
				q.push({ i,j });
				visit[i][j] = true;
				int size = 0;
				number_of_area++;

				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					size++;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int nx = dx[k] + x;
						int ny = dy[k] + y;

						if (nx > -1 && nx <m && ny > -1 && ny < n &&
							picture[i][j] == picture[nx][ny] && !visit[nx][ny]) {
							visit[nx][ny] = true;
							q.push({ nx,ny });
						}
					}
				}

				if (max_size_of_one_area < size)
					max_size_of_one_area = size;
			}
		}
	}

	answer.push_back(number_of_area);
	answer.push_back(max_size_of_one_area);

	return answer;
}
#pragma endregion
#pragma region 12977 소수 만들기
int solution12977(vector<int> nums) {
	int answer = 0;
	int n = nums.size();
	vector<bool> sosu(50001, true);
	sosu[0] = sosu[1] = false;

	for (int i = 2; i < 50001; i++) {
		if (sosu[i]) {
			for (int j = i * 2; j < 50001; j = j + i)
				sosu[j] = false;
		}
	}

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				if (sosu[nums[i] + nums[j] + nums[k]])
					answer++;
			}
		}
	}

	return answer;
}
#pragma endregion
#pragma region 12939 최댓값과 최솟값
string solution12939(string s) {
	string answer = "";
	vector<int> v;

	int num = 0;
	bool isMinus = false;
	for (char c : s) {
		if (c == '-')
			isMinus = true;
		else if (c == ' ') {
			if (isMinus)
				v.push_back(-num);
			else
				v.push_back(num);

			isMinus = false;
			num = 0;
		}
		else {
			num = num * 10 + (c - '0');
		}
	}
	if (isMinus)
		v.push_back(-num);
	else
		v.push_back(num);

	answer = to_string(*min_element(v.begin(), v.end())) + " " + to_string(*max_element(v.begin(), v.end()));

	return answer;
}
#pragma endregion
#pragma region 12973 짝지어 제거하기
int solution12973(string s) {
	stack<char> _stack;

	for (char c : s) {
		if (!_stack.empty()) {
			if (_stack.top() == c) {
				_stack.pop();
			}
			else
				_stack.push(c);
		}
		else
			_stack.push(c);
	}

	return _stack.empty();
}
#pragma endregion
#pragma region 12981 영어 끝말잇기  
vector<int> solution12981(int n, vector<string> words) {
	vector<int> answer;
	set<string> _set;
	int count = 0;
	char lastChar = words[0][0];

	for (int i = 0; i < words.size(); i++) {
		int p = i % n;
		if (p == 0)
			count++;

		if (_set.find(words[i]) != _set.end()) {
			answer.push_back(p + 1);
			answer.push_back(count);
			break;
		}

		if (lastChar == words[i][0]) {
			lastChar = words[i][words[i].size() - 1];
			_set.insert(words[i]);
		}
		else {
			answer.push_back(p + 1);
			answer.push_back(count);
			break;
		}
	}

	if (answer.empty()) {
		answer.push_back(0);
		answer.push_back(0);
	}

	return answer;
}
#pragma endregion
#pragma region 68645 삼각 달팽이
vector<int> solution68645(int n) {
	vector<int> answer;
	vector<vector<int>> arr(n, vector<int>(n));
	int x = -1, y = 0, v = 1;

	while (n > 0) {
		for (int i = 0; i < n; i++) {
			x++;
			arr[x][y] = v++;
		}
		n--;
		for (int i = 0; i < n; i++) {
			y++;
			arr[x][y] = v++;
		}
		n--;
		for (int i = 0; i < n; i++) {
			x--;
			y--;
			arr[x][y] = v++;
		}
		n--;
	}

	for (auto a : arr) {
		for (int n : a)
			if (n != 0)
				answer.push_back(n);
	}

	return answer;
}
#pragma endregion
#pragma region 42747 H-Index
int solution42747(vector<int> citations) {
	int answer = 0;
	int n = citations.size();

	for (int i = 1; i <= n; i++) {
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (citations[j] >= i) {
				count++;
			}

			if (count >= i && n - count <= i) {
				if (answer < i)
					answer = i;
			}
		}
	}

	return answer;
}
#pragma endregion
#pragma region 12951  JadenCase 문자열 만들기
string solution12951(string s) {
	string answer;
	bool firstWord = true;

	for (char c : s) {
		if (firstWord) {
			if (c >= 'a' && c <= 'z')
				c ^= 32;

			if (c != ' ')
				firstWord = false;
		}
		else {
			if (c == ' ') {
				firstWord = true;
			}
			else if (c >= 'A' && c <= 'Z') {
				c ^= 32;
			}
		}
		answer += c;
	}

	return answer;
}
#pragma endregion
#pragma region 42626 더 맵게
int solution42626(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int> q;

	for (int n : scoville)
		q.push(-n);

	while (-q.top() < K && q.size() != 1) {
		int n1 = -q.top();
		q.pop();
		int n2 = -q.top();
		q.pop();

		q.push(-(n1 + n2 * 2));

		answer++;
	}

	if (q.size() == 1 && -q.top() < K)
		answer = -1;

	return answer;
}
#pragma endregion
#pragma region 1845 폰켓몬
int solution1845(vector<int> nums)
{
	set<int> s;

	for (int n : nums)
		s.insert(n);

	return min(s.size(), nums.size() / 2);
}
#pragma endregion
#pragma region 12949 행렬의 곱셈 x
vector<vector<int>> solution12949(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	vector<vector<int>> answer;

	for (int i = 0; i < arr1.size(); i++) {
		vector <int> x;
		for (int k = 0; k < arr2[0].size(); k++) {
			int sum = 0;
			for (int j = 0; j < arr1[i].size(); j++) {
				sum += arr1[i][j] * arr2[j][k];
			}
			x.push_back(sum);
		}
		answer.push_back(x);
	}

	return answer;
}
#pragma endregion
#pragma region 12924 숫자의 표현
int solution12924(int n) {
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		int sum = 0;

		for (int j = i; j <= n; j++) {
			sum += j;
			if (sum == n) {
				answer++;
				break;
			}
			else if (sum > n) {
				sum = 0;
				break;
			}
		}
	}

	return answer;
}
#pragma endregion
#pragma region 68936 쿼드압축 후 개수 세기
void dfs68936(vector<vector<int>>& arr, int x, int y, int size, vector<int>& answer) {
	if (size == 1) {
		answer[arr[x][y]]++;
	}
	else {
		int v = arr[x][y];
		bool isGood = true;
		for (int i = x; i < x + size; i++) {
			for (int j = y; j < y + size; j++) {
				if (arr[i][j] != v) {
					isGood = false;
					break;
				}
			}

			if (!isGood)
				break;
		}


		if (isGood) {
			answer[v]++;
			return;
		}
		else {
			size /= 2;
			dfs68936(arr, x, y, size, answer);
			dfs68936(arr, x + size, y, size, answer);
			dfs68936(arr, x + size, y + size, size, answer);
			dfs68936(arr, x, y + size, size, answer);
		}

	}
}

vector<int> solution68936(vector<vector<int>> arr) {
	vector<int> answer(2);

	dfs68936(arr, 0, 0, arr.size(), answer);

	return answer;
}
#pragma endregion
#pragma region 1835 단체사진 찍기  
void dfs1835(vector<char>& friends, vector<bool>& visit, string line, int& answer, vector<string>& data, int n) {
	if (line.size() == 8) {

		bool isGood = true;

		for (int i = 0; i < n; i++) {
			char op = data[i][3];
			int num = data[i][4] - '0';
			int gap = (abs((int)(line.find(data[i][0]) - line.find(data[i][2]))) - 1);

			if ((op == '=' && gap != num) || (op == '<' && gap >= num) || (op == '>' && gap <= num)) {
				isGood = false;
				break;
			}
		}

		if (isGood) {
			answer++;
		}
	}
	else {
		for (int i = 0; i < 8; i++) {
			if (!visit[i]) {
				visit[i] = true;
				dfs1835(friends, visit, line + friends[i], answer, data, n);
				visit[i] = false;
			}
		}
	}
}
int solution1835(int n, vector<string> data) {
	int answer = 0;
	vector<char> friends = { 'A','C','F','J','M','N','R','T' };
	vector<bool> visit(8, false);

	dfs1835(friends, visit, "", answer, data, n);
	return answer;
}
#pragma endregion
#pragma region 12985 예상 대진표
int solution12985(int n, int a, int b)
{
	int answer = 0;

	while (a != b) {
		answer++;
		a = (a + 1) / 2;
		b = (b + 1) / 2;
	}

	return answer;
}
#pragma endregion
#pragma region 42578 위장	  
int solution42578(vector<vector<string>> clothes) {
	int answer = 1;
	map<string, int> m;

	for (auto arr : clothes) {
		if (m.find(arr[1]) == m.end()) {
			m.insert({ arr[1], 2 });
		}
		else
			m.find(arr[1])->second++;
	}

	for (auto it : m) {
		answer *= it.second;
	}

	return answer - 1;
}
#pragma endregion
#pragma region 17679 [1차] 프렌즈4블록
int bfs17679(int m, int n, vector<string>& board) {
	int dx[] = { 0,0,-1,1 };
	int dy[] = { -1,1,0,0 };
	int deleteCount = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i + 1 < m && j + 1 < n && board[i][j] != '-' &&
				board[i][j] == board[i + 1][j] && board[i][j] == board[i + 1][j + 1] &&
				board[i][j] == board[i][j + 1]) {
				q.push({ i,j });
				q.push({ i + 1,j });
				q.push({ i,j + 1 });
				q.push({ i + 1,j + 1 });
			}
		}
	}

	while (!q.empty()) {
		if (board[q.front().first][q.front().second] != '-') {
			deleteCount++;
			board[q.front().first][q.front().second] = '-';
		}
		q.pop();
	}

	return deleteCount;
}
void newMap17679(int m, int n, vector<string>& board) {
	for (int i = n - 1; i > -1; i--) {
		for (int j = m - 1; j > -1; j--) {
			int k = j;
			while (k + 1 < m && k > -1 && board[k][i] != '-' && board[k + 1][i] == '-') {
				board[k + 1][i] = board[k][i];
				board[k][i] = '-';
				k++;
			}
		}
	}
}
int solution17679(int m, int n, vector<string> board) {
	int answer = 0;

	while (true) {
		int deletedCount = bfs17679(m, n, board);

		if (deletedCount == 0)
			break;
		else {
			answer += deletedCount;
			newMap17679(m, n, board);
		}
	}
	return answer;
}
#pragma endregion
#pragma region 42888 오픈채팅방
vector<string> solution42888(vector<string> record) {
	vector<string> answer;
	map<string, string> ids;
	vector<pair<string, string>> ops;

	for (string str : record) {
		vector<string> pars;
		string s;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == ' ') {
				pars.push_back(s);
				s = "";
			}
			else {
				s += str[i];
			}
		}
		pars.push_back(s);

		if (pars[0][0] == 'E') {
			if (ids.find(pars[1]) == ids.end())
				ids.insert({ pars[1],pars[2] });
			else
				ids[pars[1]] = pars[2];
		}
		else if (pars[0][0] == 'C') {
			ids[pars[1]] = pars[2];
		}

		ops.push_back({ pars[0], pars[1] });
	}

	for (auto op : ops) {
		if (op.first[0] == 'E') {
			answer.push_back(ids[op.second] + "님이 들어왔습니다.");
		}
		else if (op.first[0] == 'L') {
			answer.push_back(ids[op.second] + "님이 나갔습니다.");
		}
	}

	return answer;
}
#pragma endregion
#pragma region 12953 N개의 최소공배수  
int gcd12953(int x, int y) { return x % y == 0 ? y : gcd12953(y, x % y); }
int lcm12953(int x, int y) { return x * y / gcd12953(x, y); }
int solution12953(vector<int> arr) {
	int answer = arr[0];
	for (int i = 1; i < arr.size(); i++)
		answer = lcm12953(answer, arr[i]);
	return answer;
}
#pragma endregion
#pragma region 12941 최솟값 만들기  
int solution12941(vector<int> A, vector<int> B)
{
	int answer = 0;

	sort(A.begin(), A.end());
	sort(B.rbegin(), B.rend());

	for (int i = 0; i < A.size(); i++) {
		answer += (A[i] * B[i]);
	}

	return answer;
}
#pragma endregion
#pragma region 64065 튜플
vector<int> solution64065(string s) {
	vector<int> answer;
	map<int, int> m;

	string temp;
	for (char c : s) {
		if (c >= '0' && c <= '9')
			temp += c;
		else if (temp != "" && (c == '}' || c == ',')) {
			if ( m.find(stoi(temp)) == m.end())
				m.insert({ stoi(temp),1 });
			else
				m[stoi(temp)]++;
			temp = "";
		}
	}
	vector<pair<int, int>> vec(m.begin(), m.end());

	sort(vec.begin(), vec.end(), [](pair<int, int> p1, pair<int, int> p2) ->bool {
		return p1.second > p2.second;
	});

	for (auto a : vec)
		answer.push_back(a.first);

	return answer;
}
#pragma endregion
#pragma region 17677 [1차] 뉴스 클러스터링
int solution17677(string str1, string str2) {
	int answer = 0;
	map<string, int> m1;
	map<string, int> m2;
	int sum = 0;
	int n = 0;
	for(int i =0; i<str1.size(); i++)
		if (str1[i] >= 'A' && str1[i] <= 'Z')
			str1[i] ^= 32;
	for (int i = 0; i < str2.size(); i++)
		if (str2[i] >= 'A' && str2[i] <= 'Z')
			str2[i] ^= 32;

	for (int i = 0; i < str1.size()-1; i++) {

		if (str1[i] >= 'a' && str1[i] <= 'z' &&
			str1[i + 1] >= 'a' && str1[i + 1] <= 'z') {
			string temp = str1.substr(i, 2);
			
			if (m1.find(temp) == m1.end())
				m1.insert({ temp,1 });
			else
				m1[temp]++;
			sum++;
		}
	}
	for (int i = 0; i < str2.size() - 1; i++) {
		if (str2[i] >= 'a' && str2[i] <= 'z' &&
			str2[i + 1] >= 'a' && str2[i + 1] <= 'z') {
			string temp = str2.substr(i, 2);

			if (m2.find(temp) == m2.end())
				m2.insert({ temp,1 });
			else
				m2[temp]++;

			sum++;
		}
	}

	for (auto it = m1.begin(); it != m1.end(); it++) {
		for (auto it2 = m2.begin(); it2 != m2.end(); it2++) {
			if (it->first == it2->first) {
				n += min(it->second, it2->second);
			}
		}
	}
	sum -= n;

	if (sum == 0 || n == 0)
		answer = 65536;
	else
		answer = int(((double)n / (double)sum) * 65536);


	return answer;
}
#pragma endregion
#pragma region 60057 문자열 압축
int func60057(string s, int size) {
	string str = s.substr(0, size);
	vector<pair<string, int>> v;
	v.push_back({ str,1 });
	int n = 0;
	for (int i = size; i < s.size(); i += size) {
		if (str == s.substr(i, size)) {
			v.back().second++;
		}
		else {
			str = s.substr(i, size);
			v.push_back({ str,1 });
		}
	}

	for (auto a : v) {
		if (a.second != 1)
		{
			int temp = a.second;
			while (temp != 0) {
				n += 1;
				temp /= 10;
			}
		}

		n += a.first.size();
	}

	return n;
}
int solution60057(string s) {
	int n = s.size();
	int answer = n;

	for (int i = 1; i <= n; i++) {
		int minSize = func60057(s, i);
		cout << i << " " << minSize << '\n';
		if (answer > minSize) {
			answer = minSize;
		}
	}

	return answer;
}
#pragma endregion
#pragma region 60058 괄호 변환
void getUV60058(string p, string& u, string& v) {
	u = "";
	v = "";
	int cnt = 0;
	int i = 0;
	for (i = 0; i < p.size(); i++) {
		if (p[i] == '(') cnt++;
		else cnt--;

		u += p[i];

		if (cnt == 0) break;
	}

	for (i = i + 1; i < p.size(); i++) {
		v += p[i];
	}

}

bool isCorrect60058(string str) {
	stack<char> s;

	for (char c : str) {
		if (c == '(')
			s.push(c);
		else {
			if (s.empty())
				return false;
			else
				s.pop();
		}
	}

	if (s.empty()) return true;
	else return false;
}

string solution60058(string p) {
	string answer = "";
	string u, v;

	while (true) {
		getUV60058(p, u, v);

		if (isCorrect60058(u)) {
			answer += u;
			p = v;
		}
		else {
			string newU;
			for (int i = 1; i < u.size() - 1; i++) {
				if (u[i] == '(')
					newU += ')';
				else
					newU += '(';
			}

			p = "(" + solution60058(v) + ")" + newU;
		}

		if (isCorrect60058(p)) {
			answer += p;
			break;
		}
	}

	return answer;
}
#pragma endregion
#pragma region 42842 카펫
vector<int> solution42842(int brown, int yellow) {
	int wh = brown + yellow;

	for (int i = 1; i <= wh; i++) {
		int h = i;
		int w;

		if (wh % h != 0)
			continue;

		w = wh / h;

		if (2 * (w + h - 2) == brown)
			return { w,h };
	}
}
#pragma endregion

/*
	스킬트리
	스킬트리와 스킬트리의 순서는 무조건 같다야 된다는 것을 알았다면 쉽게 풀었음.
	나는 첫번째 스킬의 위치를 따로 저장해 스킬트리에 있는 스킬이 가능한지 검사함.
*/
#pragma region 49993 스킬트리
int solution49993(string skill, vector<string> skill_trees) {
	int answer = 0;

	for (int i = 0; i < skill_trees.size(); i++) {
		bool isGood = true;
		char* lastSkill = &skill[0];

		for (int j = 0; j < skill_trees[i].size(); j++) {
			int s = skill.find(skill_trees[i][j]);
			if (s != -1) {
				if (*lastSkill != skill_trees[i][j]) {
					isGood = false;
					break;
				}
				else
					lastSkill++;
			}
		}

		if (isGood)
			answer++;
	}

	return answer;
}
#pragma endregion
/*
	주식가격
	카테고리는 스택힙인데 정렬로 풀어도 시간이 넘지 않을것같아
	정렬로 풀었는데 괜찮음.

	스택 힙으로는 도저히 풀이가 떠오르지 않음.
*/
#pragma region 42584 주식가격
vector<int> solution42584(vector<int> prices) {
	vector<int> answer;

	for (int i = 0; i < prices.size(); i++) {
		int count = 0;
		for (int j = i + 1; j < prices.size(); j++) {
			if (prices[i] <= prices[j])
				count++;
		}

		answer.push_back(count);
	}

	return answer;
}
vector<int> solution42584_2(vector<int> prices) {
	vector<int> answer(prices.size());
	stack<int> s;
	int size = prices.size();
	for (int i = 0; i < size; i++) {
		while (!s.empty() && prices[s.top()] > prices[i]) {
			answer[s.top()] = i - s.top();
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {
		answer[s.top()] = size - s.top() - 1;
		s.pop();
	}
	return answer;
}
#pragma endregion
/*
*  굳이 큐를 사용안해도 됨.
*  남은 일수중 가장 큰값을 계속 찾아가며 처리하면 됨.
*/
#pragma region 42586 기능개발
vector<int> solution42586(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> q;

	for (int i = 0; i < progresses.size(); i++) {
		int work = ((100 - progresses[i]) / speeds[i]) +
			((100 - progresses[i]) % speeds[i] != 0);

		if (q.empty()) {
			q.push(work);
		}
		else {
			if (q.front() < work) {
				answer.push_back(q.size());

				while (!q.empty()) {
					q.pop();
				}
			}
			q.push(work);
		}

	}

	answer.push_back(q.size());

	return answer;
}
vector<int> solution42586_2(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int max_day = 0;
	for (int i = 0; i < progresses.size(); i++) {
		int day = ((100 - progresses[i]) / speeds[i]) +
			((100 - progresses[i]) % speeds[i] != 0);

		if (answer.empty() || max_day < day) {
			answer.push_back(1);
		}
		else {
			answer.back()++;
		}

		if (max_day < day)
			max_day = day;
	}

	return answer;
}
#pragma endregion
/*
	흠.. 다른 방법이... 풀리긴 했는데.. 넘 오래걸림.
*/
#pragma region 42839 소수 찾기
void dfs42839(int l, vector<int>& v, vector<bool>& visit, int num, set<int>& s) {
	if (l == v.size()) {
		s.insert(num);
	}
	else {

		for (int i = 0; i < v.size(); i++) {
			if (!visit[i]) {
				visit[i] = true;
				dfs42839(l + 1, v, visit, num * 10 + v[i], s);
				visit[i] = false;
			}
			else
				dfs42839(l + 1, v, visit, num, s);
		}
	}
}

int solution42839(string numbers) {
	int answer = 0;
	vector<int> v;
	vector<bool> visit(numbers.size(), false);
	set<int> s;
	vector<bool> sosu(10000000, true);
	sosu[0] = false;
	sosu[1] = false;

	for (int i = 2; i < sosu.size(); i++) {
		if (sosu[i]) {
			for (int j = i * 2; j < sosu.size(); j += i) {
				sosu[j] = false;
			}
		}
	}

	for (char c : numbers)
		v.push_back(c - '0');

	dfs42839(0, v, visit, 0, s);

	for (auto it = s.begin(); it != s.end(); it++)
		if (sosu[*it])
			answer++;

	return answer;
}
#pragma endregion
/*
   erase는 삭제에 성공할시 삭제한 요소의 바로 다음 iterator를 return 하기때문에 it에 그대로 대입시켜주면 되는 것이다.
*/
#pragma region 42583 다리를 지나는 트럭
int solution42583(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	vector<pair<int, int>> in;
	queue<int> trucks;
	int nowWeight = 0;

	for (int t : truck_weights)
		trucks.push(t);

	while (!trucks.empty() || !in.empty()) {

		for (auto it = in.begin(); it != in.end();) {
			if (it->second == bridge_length) {
				nowWeight -= it->first;
				it = in.erase(it);
			}
			else {
				it->second += 1;
				it++;
			}
		}

		if (!trucks.empty() && trucks.front() + nowWeight <= weight) {
			nowWeight += trucks.front();
			in.push_back({ trucks.front(),1 });
			trucks.pop();
		}
		answer++;
	}

	return answer;
}
#pragma endregion
/*
	한번에 못품
	문제를 깊게 이해를 못했음.
	접두어만 확인 하면 되었는데...
*/
#pragma region 42577 전화번호 목록
bool solution42577(vector<string> phone_book) {
	bool answer = true;
	sort(phone_book.begin(), phone_book.end());

	for (int i = 0; i < phone_book.size() - 1; i++) {
		if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))
			return false;
	}

	return answer;
}
#pragma endregion
/*
	dfs로 풀려 했으나 시간초과
	그보다 넘버가 최대 백만자리의 숫자임. 정수로 계산해서 못품.

	두번째로 스택을 사용해서 풀었음.
	다른 사람들 코드랑 다른듯.
*/
#pragma region 42883 큰 수 만들기.  
void dfs42883(int l, string& number, int k, string str, string& answer) {
	if (str.length() == number.length() - k) {
		if (stoll(answer) < stoll(str))
			answer = str;
	}
	else {
		if (l > number.length())
			return;
		dfs42883(l + 1, number, k, str + number[l], answer);
		dfs42883(l + 1, number, k, str, answer);
	}
}
string solution42883(string number, int k) {
	string answer = "";
	stack<char> s;
	//1924
	for (int i = 0; i < number.size(); i++) {
		while (!s.empty() && s.top() < number[i] && k != 0) {
			s.pop();
			k--;
		}
		s.push(number[i]);
	}

	while (!s.empty()) {
		answer = s.top() + answer;
		s.pop();
	}

	answer = answer.substr(0, answer.size() - k);

	return answer;
}
#pragma endregion
/*
	못품. 더한 값을 비교 한다는 생각을 전혀 못함.
*/
#pragma region 42746 가장 큰 수
string solution42746(vector<int> numbers) {
	string answer = "";

	sort(numbers.begin(), numbers.end(), [](int a, int b)->bool {
		return to_string(a) + to_string(b) > to_string(b) + to_string(a);
	});

	for (int n : numbers)
		answer += to_string(n);

	if (*max_element(answer.begin(), answer.end()) == '0')
		answer = "0";

	return answer;
}
#pragma endregion
/*
	그리디 생각을 아주 잘못함.
*/
#pragma region 42885 구명보트  
int solution42885(vector<int> people, int limit) {
	int answer = 0;

	sort(people.begin(), people.end());

	int idx = 0;
	while (people.size() > idx) {
		if (people[idx] + people.back() > limit) {
			people.pop_back();
			answer++;
		}
		else {
			idx++;
			people.pop_back();
			answer++;
		}
	}
	
	return answer;
}
#pragma endregion
/*
	LRU 를 제대로 이해 못했었음.
*/
#pragma region 17680 [1차] 캐시 
int solution17680(int cacheSize, vector<string> cities) {
		int answer = 0;
		deque<string> dq;

		if (cacheSize == 0)
			return cities.size() * 5;

		for (int j = 0; j < cities.size(); j++) {
			for (int i = 0; i < cities[j].size(); i++) {
				if (cities[j][i] >= 'A' && cities[j][i] <= 'Z')
					cities[j][i] ^= 32;
			}
		}

		for (string city : cities) {
			bool isExist = false;
			if(!dq.empty())
				for (auto it = dq.begin(); it != dq.end(); it++) {
					if (*it == city) {
						answer += 1;
						isExist = true;
						dq.erase(it);
						dq.push_back(city);
						break;
					}
				}

			if (!isExist) {
				if (dq.size() == cacheSize && !dq.empty())
					dq.pop_front();	
				dq.push_back(city);
				answer += 5;
			}
		}

		return answer;
}
#pragma endregion
/*
	왜 생각을 못하지.
	풀이를 보면 단순함
*/
#pragma region 12980 점프와 순간 이동 
int solution12980(int n)
{
	int ans = 0;

	while (n != 0) {
		if (n / 2 == 0)
			n /= 2;
		else {
			ans++;
			n--;
		}
	}

	return ans;
}
#pragma endregion
/*
	원리를 전혀 모르곘넹..
*/
#pragma region 12899 124 나라의 숫자
string solution12899(int n) {
	string answer = "";

	while (n != 0) {
		int temp = n % 3;
		n /= 3;

		if (temp == 0) {
			answer = "4" + answer;
			n--;
		}
		else
			answer = to_string(temp) + answer;
	}
	
	return answer;
}
#pragma endregion
/*
	공식이 이해가 안감.
*/
#pragma region 62048 멀쩡한 사각형  
long long gcd62048(int a, int b)
{
	long c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
long long solution62048(int w, int h) {
	long long W = w;
	long long H = h;
	long long tmp = (w + h) - gcd62048(w, h);

	return (W * H) - tmp;
}
#pragma endregion

#pragma region 72411 메뉴 리뉴얼  
void dfs72411(string order, map<string, int> &_map, int course, string str,int l, vector<int> &courseSize, int i) {
	if (l > order.size()) return;

	if (str.size() == course) {
		if (_map.find(str) == _map.end()) {
			_map.insert({ str,1 });
		}
		else {
			_map[str]++;

			if (courseSize[i] < _map[str])
				courseSize[i] = _map[str];
		}
	}
	else {
		dfs72411(order, _map, course, str + order[l], l + 1, courseSize,i);
		dfs72411(order, _map, course, str , l + 1, courseSize,i);

	}
}

vector<string> solution72411(vector<string> orders, vector<int> course) {
	vector<string> answer;
	vector<int> courseSize(course.size(), 0);
	map<string, int> _map;

	for (int i = 0; i < course.size(); i++) {
		for (string order : orders) {
			sort(order.begin(), order.end());
			dfs72411(order, _map, course[i], "",0, courseSize, i );
		}
	}

	for (int i = 0; i < course.size(); i++) {
		for (auto it = _map.begin(); it != _map.end(); it++) {
			if ((*it).first.size() == course[i] && (*it).second == courseSize[i])
				answer.push_back((*it).first);
		}
	}

	sort(answer.begin(), answer.end());
	for (auto s : answer)
		cout << s << ' ';

	return answer;
}
#pragma endregion


#pragma region sol  
void sol2() {
}
#pragma endregion

