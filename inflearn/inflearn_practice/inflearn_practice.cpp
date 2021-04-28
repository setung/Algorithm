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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n;
	queue<pair<int,int>> q;

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		q.push({i,x});
	}

	cin >> m;
	while (m--) {
		int index = q.front().first;
		int work = q.front().second -1;
		q.pop();

		if (work != 0)
			q.push({ index,work });

		if (q.empty()) {
			cout << -1;
			return 0;
		}
	}

	cout << q.front().first;


	return 0;
}

