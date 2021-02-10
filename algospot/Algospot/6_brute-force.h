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

#pragma region _PICNIC
void func_PICNIC(vector<pair<int, int>>& friends, vector<bool> f, int index, int cnt, int n, int& answer) {
	if (cnt == n)
		answer++;
	else {
		for (int i = index; i < friends.size(); i++) {
			if (f[friends[i].first] || f[friends[i].second]) {
				continue;
			}
			else {
				func_PICNIC(friends, f, i, cnt + 2, n, answer);
			}
		}
	}

}

void sol_PICNIC() {
	int tc;
	cin >> tc;

	for (int t = 0; t < tc; t++) {
		int n, m;
		int answer = 0;
		cin >> n >> m;
		vector<pair<int, int>> friends(m);

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			friends[i] = { a,b };
		}

		for (int i = 0; i < m; i++) {
			vector<bool> f(n, false);
			int cnt = 2;
			f[friends[i].first] = true;
			f[friends[i].second] = true;

			func_PICNIC(friends, f, i, cnt, n, answer);

		}

		cout << answer << '\n';
	}
}
#pragma endregion
#pragma region _BOARDCOVER x
void sol_BOARDCOVER() {

}
#pragma endregion
#pragma region _CLOCKSYNC xx
#pragma endregion