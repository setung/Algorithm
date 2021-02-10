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