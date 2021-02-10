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
// ¾Ë°í½ºÆÌ
#pragma region _LIS
void sol_LIS() {
	int t;
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		int n;
		cin >> n;
		vector<int> arr(n);
		vector<int> dp(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		dp[0] = 1;

		for (int i = 1; i < n; i++) {
			int _max = 0;
			for (int j = 0; j < i; j++) {
				if (arr[i] > arr[j] && _max < dp[j])
					_max = dp[j];
			}

			dp[i] = _max + 1;
		}

		cout << *max_element(dp.begin(), dp.end()) << '\n';
	}
}
#pragma endregion