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




#pragma region sol  
void sol2() {


}
#pragma endregion

