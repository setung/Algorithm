#include <stack>
#include <unordered_map>
#include <unordered_set>
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

// 1-2, 1-5




void sol2_1() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string str;
	int answer = 0;
	cin >> str;

	int temp = 0;
	for (char c : str) {
		if (c >= '0' && c <= '9') {
			temp = temp * 10 + c - '0';
		}
		else {
			answer += temp;
			temp = 0;
		}
	}

	cout << answer + temp;
}

void sol1_5() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, r;
	cin >> n >> m >> r;
	vector<pair<pair<int, int>, int>> arr(m);
	vector<int> dp(m);

	for (int i = 0; i < m; i++) {
		cin >> arr[i].first.first;
		cin >> arr[i].first.second;
		cin >> arr[i].second;
	}

	sort(arr.begin(), arr.end(), [](pair<pair<int, int>, int> a, pair<pair<int, int>, int>b) -> bool {
		return a.first.second < b.first.second;
	});

	for (int i = 0; i < m; i++) {
		dp[i] = arr[i].second;
	}

	for (int i = 0; i < m; i++) {
		int tmp = arr[i].second;
		for (int j = i - 1; j > -1; j--) {
			if (arr[i].first.first - arr[j].first.second >= r) {
				if (tmp < dp[j] + dp[i])
					tmp = dp[j] + dp[i];
			}
		}

		dp[i] = tmp;
	}

	cout << *max_element(dp.begin(), dp.end());
}
void dfs1_4(int n, int index, int w, int b, int sumW, int sumB, vector<pair<int, int>>& player, int& answer) {
	if (index == n) {
		if (abs(sumW - sumB) < answer)
			answer = abs(sumW - sumB);
	}
	else {
		if (w < n / 2)
			dfs1_4(n, index + 1, w + 1, b, sumW + player[index].first, sumB, player, answer);
		if (b < n / 2)
			dfs1_4(n, index + 1, w, b + 1, sumW, sumB + player[index].second, player, answer);
	}

}
void sol1_4() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> player(n);
	int answer = 9999999;

	for (int i = 0; i < n; i++) {
		cin >> player[i].first;
		cin >> player[i].second;
	}

	dfs1_4(n, 0, 0, 0, 0, 0, player, answer);

	cout << answer;
}
void sol1_3() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	stack<pair<int, int>> s;

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;

		while (!s.empty() && s.top().first <= x)
			s.pop();
		if (s.empty()) {
			cout << 0 << ' ';
		}
		else {
			cout << s.top().second << ' ';
		}
		s.push({ x, i });
	}
}
void sol1_2() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int w, h, t, s;
	cin >> w >> h >> t >> s;
	vector<pair<int, int>> trees(t);
	int answer = 0;

	for (int i = 0; i < t; i++) {
		cin >> trees[i].first;
		cin >> trees[i].second;
	}

	for (int i = 0; i < t; i++) {
		for (int j = 0; j < t; j++) {
			int cnt = 0;
			for (int k = 0; k < t; k++) {
				if (trees[k].first <= trees[i].first + s && trees[k].first >= trees[i].first)
					if (trees[k].second <= trees[j].second + s && trees[k].second >= trees[j].second)
						cnt++;
			}

			if (answer < cnt)
				answer = cnt;
		}
	}

	cout << answer;
}
void sol1_1() {
	int n;
	cin >> n;
	int minSize = 9999;
	vector<string> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		if (arr[i].size() < minSize)
			minSize = arr[i].size();
	}

	string answer;
	for (int i = 0; i < minSize; i++) {
		char c = arr[0][i];
		bool isCorrect = true;
		for (int j = 0; j < arr.size(); j++) {
			if (c != arr[j][i]) {
				isCorrect = false;
			}
		}

		if (!isCorrect)
			break;

		answer += c;
	}

	cout << answer;
}