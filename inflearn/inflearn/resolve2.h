#pragma once
#include "header.h"
// 86
// dp 10 11 12

#pragma region sample
void redp2() {
	
}
#pragma endregion

/*
	냅색 알고리즘
	정방향 : 중복 허용하며 값 증가
	역방향 : 중복 없이 값 증가.
*/
#pragma region 12. 최대점수 구하기(냅색 알고리즘)
void redp12() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> arr(n);
	vector<int> answer(m + 1);

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[i] = { a,b };
	}

	for (int i = 0; i < n; i++) {
		for (int j = m; j >= arr[i].second; j--) {
			answer[j] = max(answer[j], answer[j - arr[i].second] + arr[i].first);
		}
	}

	cout << answer[m];

}
#pragma endregion
#pragma region 11. 동전교환
void redp11() {
	int n,m;
	cin >> n;
	vector<int> coins(n);
	for (int i = 0; i < n; i++)
		cin >> coins[i];
	cin >> m;
	vector<int> answer(m+1,1000);
	answer[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m + 1; j++) {
			if (j - coins[i] >= 0) {
				answer[j] = min(answer[j], answer[j - coins[i]] + 1);
			}
		}
	}

	cout << answer[m];
}
#pragma endregion
#pragma region 10. 가방문제(냅색 알고리즘)
void redp10() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> arr(n);
	vector<int> answer(m+1);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[i] = { a,b };
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m+1; j++) {
			if (j - arr[i].first >= 0) {
				answer[j] = max(answer[j], answer[j - arr[i].first] + arr[i].second);
			}
		}
	}

	cout << *max_element(answer.begin(), answer.end());
}
#pragma endregion

#pragma region 15. 위상정렬(그래프 정렬)
void redp15() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n + 1);
	vector<int> arr(n + 1);
	priority_queue<int> q;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		arr[b]++;
	}

	for (int i = 1; i <= n; i++)
		if (arr[i] == 0)
			q.push(-i);

	while (!q.empty()) {
		int node = -q.top();
		q.pop();
		cout << node << ' ';

		for (int i = 0; i < graph[node].size(); i++) {
			if (--arr[graph[node][i]] == 0)
				q.push(-graph[node][i]);
		}
	}
}
#pragma endregion
#pragma region 14. 회장뽑기(플로이드-워샬 응용)
void redp14() {
	int n;
	cin >> n;
	int INF = 9999;
	vector<int> answer(n+1);
	int _min = 987654321;
	vector<vector<int>> arr(n + 1, vector<int>(n + 1,INF));

	while (true) {
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1)
			break;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	for (int i = 1; i <= n; i++)
		arr[i][i] = 0;

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int _max = 0;
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] != INF && _max < arr[i][j])
				_max = arr[i][j];
		}
		answer[i] = _max;
		if (_min > _max)
			_min = _max;
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (answer[i] == _min)
			cnt++;
	}

	cout << _min<< ' ' << cnt << '\n';
	for (int i = 1; i <= n; i++) {
		if (answer[i] == _min)
			cout << i << ' ';
	}
}
#pragma endregion
#pragma region 13 플로이드 워샬 알고리즘
void redp13() {
	int n, m;
	int INF = 9999;
	cin >> n >> m;
	vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = c;
	}

	for (int i = 1; i <= n; i++) {
		graph[i][i] = 0;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {

				if (graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] == INF)
				cout << "M ";
			else
				cout << graph[i][j] << ' ';
		}
		cout << '\n';
	}

}
#pragma endregion
#pragma region 8, 9  알리바바와 40인의 도둑
//(Bottom-Up)
void redp8_1() {
	int n;
	cin >> n;
	vector<vector<int>> _map(n, vector<int>(n));
	vector<vector<int>> dp(n, vector<int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> _map[i][j];

	dp[0][0] = _map[0][0];
	for (int i = 1; i < n; i++) {
		dp[0][i] = dp[0][i - 1] + _map[0][i];
		dp[i][0] = dp[i - 1][0] + _map[i][0];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			dp[i][j] = _map[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[n - 1][n - 1];
}
//(Top-Down)
int func8_2(int x, int y, vector<vector<int>>& _map, vector<vector<int>>& dp) {
	if (dp[x][y] != 0)
		return dp[x][y];

	if (x == 0 && y == 0)
		return dp[x][y] = _map[x][y];

	if (x == 0)
		return dp[x][y] = _map[x][y] + func8_2(x, y - 1, _map, dp);
	else if (y == 0)
		return dp[x][y] = _map[x][y] + func8_2(x - 1, y, _map, dp);
	else
		return dp[x][y] = _map[x][y] + min(func8_2(x, y - 1, _map, dp), func8_2(x - 1, y, _map, dp));

}
void redp8_2() {
	int n;
	cin >> n;
	vector<vector<int>> _map(n, vector<int>(n));
	vector<vector<int>> dp(n, vector<int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> _map[i][j];

	cout << func8_2(n - 1, n - 1, _map, dp);
}
#pragma endregion
#pragma region 7. 가장 높은 탑 쌓기
class brick7 {
public:
	int w;
	int h;
	int g;

	brick7() {}
	brick7(int _w, int _h, int _g) :w(_w), h(_h), g(_g) {}

};
void redp7() {
	int n;
	cin >> n;
	vector<brick7> arr(n);
	vector<int> dp(n);
	for (int i = 0; i < n; i++) {
		int w, h, g;
		cin >> w >> h >> g;
		arr[i] = brick7(w, h, g);
	}

	sort(arr.begin(), arr.end(), [](brick7 a, brick7 b)  -> bool {
		if (a.g > b.g && a.w > b.g)
			return true;
		else return a.g > b.g;
	});

	for (int i = 0; i < n; i++) {
		int _max = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i].g < arr[j].g &&
				arr[i].w < arr[j].w &&
				_max < dp[j]) {
				_max = dp[j];
			}
		}

		dp[i] = _max + arr[i].h;
	}

	cout << *max_element(dp.begin(), dp.end());

}
#pragma endregion
#pragma region 6. 최대 선 연결하기
void redp6() {
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> dp(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		int _max = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && _max < dp[j])
				_max = dp[j];
		}

		dp[i] = _max + 1;
	}

	cout << *max_element(dp.begin(), dp.end());
}
#pragma endregion
#pragma region 5. 최대 부분 증가수열
void redp5() {
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> dp(n, 0);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		int _max = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && _max < dp[j]) {
				_max = dp[j];
			}
		}

		dp[i] = _max + 1;
	}

	cout << *max_element(dp.begin(), dp.end());

}
#pragma endregion
#pragma region 3, 4 계단오르기(Top-Down : 메모이제이션)
int func3(int n, vector<int>& dp) {
	if (n == 1 || n == 2)
		return dp[n] = n;
	else
		return dp[n] = func3(n - 2, dp) + func3(n - 1, dp);
}
void redp3() {
	int n;
	cin >> n;
	vector<int> dp(46);

	func3(n, dp);
	cout << dp[n];
}
#pragma endregion
#pragma region 1, 2 네트워크 선 자르기
void redp1_1() {
	int n;
	cin >> n;
	vector<int> arr(46);
	arr[1] = 1;
	arr[2] = 2;

	for (int i = 3; i < 46; i++)
		arr[i] = arr[i - 1] + arr[i - 2];

	cout << arr[n];
}
int func1_2(int n, vector<int>& arr) {
	if (arr[n] != 0)
		return arr[n];
	if (n == 1 || n == 2)
		return arr[n] = n;
	else {
		return arr[n] = func1_2(n - 1, arr) + func1_2(n - 2, arr);
	}
}
void redp1_2() {
	int n;
	cin >> n;
	vector<int> arr(46);
	func1_2(n, arr);

	cout << arr[n];
}
#pragma endregion

#pragma region 75. 최대 수입 스케쥴(priority_queue 응용문제)
void re275() {
	int n;
	cin >> n;
	priority_queue<pair<int, int>> q;
	priority_queue<pair<int, int>> qv;
	int sum = 0;
	int maxDate;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		q.push({ b,a });
	}

	maxDate = q.top().first;


	for (int i = maxDate; i > 0; i--) {
		while (!q.empty() && q.top().first >= i) {
			qv.push({ q.top().second, q.top().first });
			q.pop();
		}

		if (!qv.empty() && qv.top().second >= i) {
			sum += qv.top().first;
			qv.pop();
		}
	}

	cout << sum;
}
#pragma endregion
#pragma region 71. 송아지 찾기(BFS : 상태트리탐색)
void re271() {
	int s, e;
	cin >> s >> e;
	queue<pair<int, int>> q;
	q.push({ s,0 });
	vector<bool> visit(10001, false);
	visit[s] = true;

	while (!q.empty()) {
		int now = q.front().first;
		int count = q.front().second;
		q.pop();
		if (now == e) {
			cout << count;
			break;
		}

		if (now + 1 <= 10001 && visit[now + 1] == false) {
			q.push({ now + 1,count + 1 });
			visit[now + 1] = true;
		}
		if (now - 1 >= 0 && visit[now - 1] == false) {
			q.push({ now - 1,count + 1 });
			visit[now - 1] = true;
		}
		if (now + 5 <= 10001 && visit[now + 5] == false) {
			q.push({ now + 5,count + 1 });
			visit[now + 5] = true;
		}

	}

}
#pragma endregion
#pragma region 52. Ugly Numbers
void re252() {
	int n;
	cin >> n;
	vector<long long> arr = { 1 };
	int p2 = 0;
	int p3 = 0;
	int p5 = 0;

	for (int i = 0; i < n + 1; i++) {
		int t = min(2 * arr[p2], min(3 * arr[p3], 5 * arr[p5]));
		arr.push_back(t);

		if (2 * arr[p2] == t) p2++;
		if (3 * arr[p3] == t) p3++;
		if (5 * arr[p5] == t) p5++;
	}

	cout << arr[n - 1];
}
#pragma endregion
#pragma region 30. 3의 개수는?(large)    보류
void re30() {
	int n;
	cin >> n;
	int answer = 0;


	cout << answer;
}
#pragma endregion
#pragma region 27. N!의 표현법   O    
void re27() {
	int n;
	cin >> n;
	vector<int> v(n + 1, 0);

	for (int i = 2; i <= n; i++) {
		int temp = i;

		int j = 2;
		while (temp != 1) {
			if (temp % j == 0) {
				v[j]++;
				temp /= j;
			}
			else
				j++;
		}
	}

	cout << n << "! = ";
	for (int i = 2; i < n + 1; i++)
		if (v[i] != 0)
			cout << v[i] << ' ';
}
#pragma endregion

/*
	풀이 방식은 맞았다.
	하지만 vector라서 그런가 마지막 테스트케이스에서 시간초과난다.
	한가지 얻은 팁. 배열은 0부터 시작하면 까다로운 조건문을 넣어야 하지만
	1부터 시작하면서 조건문을 없앨 수 있음.
*/
#pragma region 51. 영지(territory) 선택 : (large)  
void re251() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	int h, w;
	cin >> n >> m;
	int answer = 0;
	vector<vector<int>> arr(n + 1, vector<int>(m + 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int a;
			cin >> a;
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + a;
		}
	}

	cin >> h >> w;

	for (int i = h; i < n; i++) {
		for (int j = w; j < m; j++) {
			answer = max(arr[i][j] - arr[i - h][j] - arr[i][j - w] + arr[i - h][j - w], answer);
		}
	}

	cout << answer;
}
#pragma endregion
/*
	문제에서 내포하는 힌트를 얻어야 되는데..
	무조건 첫번째 말부터 포함하는게 맞음.
*/
#pragma region 44. 마구간 정하기(이분검색 응용) X
void re244() {
	int n, c;
	cin >> n >> c;
	vector<int> arr(n);
	int answer = 0;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	int lt = arr.front();
	int rt = arr.back();

	while (lt <= rt) {
		int mid = (lt + rt) / 2;
		int pos = 0;
		int cnt = 1;

		for (int i = 1; i < n; i++) {
			if (arr[i] - arr[pos] >= mid) {
				cnt++;
				pos = i;
			}
		}

		if (cnt >= c) {
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
/*
	문제에 놓친 부분이 있었음.
	cnt 의 특성도 미숙.
*/
#pragma region 43. 뮤직비디오(이분검색 응용)  아쉽다. 다시 풀긴 했는데 다시 해보자.
void re243() {
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	int lt = 0, rt = 0;
	int _max = 0;
	int answer = 123456578;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		rt += arr[i];
		if (_max < arr[i])
			_max = arr[i];
	}

	while (lt <= rt) {
		int mid = (lt + rt) / 2;
		int cnt = 1;
		int sum = 0;

		for (int i = 0; i < n; i++) {
			if (sum + arr[i] > mid) {
				sum = arr[i];
				cnt++;
			}
			else {
				sum += arr[i];
			}
		}

		if (cnt <= m) {
			rt = mid - 1;
			if (_max <= mid && answer > mid)
				answer = mid;
		}
		else {
			lt = mid + 1;
		}

	}

	cout << answer;
}
#pragma endregion

