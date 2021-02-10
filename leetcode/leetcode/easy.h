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

#pragma region 1436. Destination City
string destCity(vector<vector<string>> paths) {

	string answer;

	for (int i = 0; i < paths.size(); i++) {
		bool isLast = true;
		string last = paths[i][1];

		for (int j = 0; j < paths.size(); j++) {

			if (paths[j][0] == last) {
				isLast = false;
				break;
			}
		}

		if (isLast)
			answer = last;
	}

	return answer;
}

#pragma endregion
#pragma region 1614. Maximum Nesting Depth of the Parentheses
int maxDepth(string s) {
	int answer = 0;
	int v = 0;
	for (char c : s) {
		if (c == '(') {
			v++;
		}
		else if (c == ')') {
			v--;
		}

		if (answer < v)
			answer = v;
	}

	return answer;
}

#pragma endregion
#pragma region 1662. Check If Two String Arrays are Equivalent
bool arrayStringsAreEqual(vector<string> word1, vector<string> word2) {
	string str1;
	string str2;

	for (string c : word1)
		str1 += c;
	for (string c : word2)
		str2 += c;

	return str1 == str2;
}

#pragma endregion
#pragma region 1672	Richest Customer Wealth
int maximumWealth(vector<vector<int>>& accounts) {
	int answer = 0;
	for (auto arr : accounts) {
		int sum = 0;
		for (int a : arr)
			sum += a;

		answer = max(sum, answer);
	}

	return answer;
}
#pragma endregion


#pragma region sample
void func() {

}
#pragma endregion

void solution() {

}