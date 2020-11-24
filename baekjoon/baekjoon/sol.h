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

#pragma region 10872 ÆÑÅä¸®¾ó
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

#pragma region 10870 ÇÇº¸³ªÄ¡ ¼ö 5

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

#pragma region 2798 ºí·¢Àè
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

#pragma region 10828 ½ºÅÃ 
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

#pragma region 10773 Á¦·Î 
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

#pragma region 9012 °ýÈ£  
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

#pragma region 4949 ±ÕÇüÀâÈù ¼¼»ó 
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