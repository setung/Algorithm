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

#pragma region 5597 과제 안 내신 분..?
void sol5597() {
	vector<bool> arr(30, false);
	for (int i = 0; i < 28; i++) {
		int x;
		cin >> x;
		arr[x - 1] = true;
	}

	for (int i = 0; i < 30; i++) {
		if (!arr[i])
			cout << i + 1 << '\n';
	}
}
#pragma endregion
#pragma region 6996 애너그램
void sol6996() {
	int tc;
	cin >> tc;
	while (tc--) {
		string str1, str2;
		cin >> str1 >> str2;

		cout << str1 << " & " << str2 << ' ';
		sort(str1.begin(), str1.end());
		sort(str2.begin(), str2.end());

		if (str1 == str2)
			cout << "are anagrams.\n";
		else
			cout << "are NOT anagrams.\n";
	}
}
#pragma endregion
#pragma region 2750 수 정렬하기
void sol2750() {
	int n;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	for (int a : arr)
		cout << a << '\n';

}
#pragma endregion