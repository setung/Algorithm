#pragma once
#include "header.h"
// 86
// dp는 다시.
#pragma region sample
void re22() {

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

		if (!qv.empty() && qv.top().second >=i) {
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
	vector<bool> visit(10001,false);
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

	for (int i = 0; i < n+1; i++) {
		int t = min(2* arr[p2], min(3 * arr[p3], 5 * arr[p5]));
		arr.push_back(t);

		if (2 * arr[p2] == t) p2++;
		if (3 * arr[p3] == t) p3++;
		if (5 * arr[p5] == t) p5++;
	}

	cout << arr[n-1];
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
	vector<vector<int>> arr(n+1, vector<int>(m+1));
	
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
			answer = max(arr[i][j] - arr[i - h][j] - arr[i][j - w] + arr[i - h][j - w],answer);
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
	int lt=0, rt = 0;
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

		if ( cnt <= m) {
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

