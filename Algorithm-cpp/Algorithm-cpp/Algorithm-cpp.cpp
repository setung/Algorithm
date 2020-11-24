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



int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	n = 1000 - n;
	int answer = 0;
		
	if (n >= 500) {
		answer += n/500;
		n %= 500;
	}

	if (n >= 100) {
		answer += n / 100;
		n %= 100;
	}

	if (n >= 50) {
		answer += n / 50;
		n %= 50;
	}

	if (n >= 10) {
		answer += n / 10;
		n %= 10;
	}

	if (n >= 5) {
		answer += n / 5;
		n %= 5;
	}

	if (n >= 1) {
		answer += n;
	}

	cout << answer;
	return 0;
}