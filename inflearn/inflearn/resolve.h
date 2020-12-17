#pragma once
#include "header.h"
//  27(v) 30(x) 43(v) 44(x) 51(?) 52(v) 71(v) 75(?)  86
// dp 2 5 8(v) 9 11

// 1 ~ 31�ڵ屸���� �⸣��
// 32 ~ 55 ���� & �̺�Ž��(�����˰���) & ������Ʈ �˰��� & ����
// 56 ~ 57��� & ����/���� �켱Ž��(DFS, BFS)
// 76 ~ 90 �׷���, DFS, BFS ����
#pragma region sample
void DQQ() {

}
#pragma endregion

#pragma region 14. ��������(�׷��� ����)
void DQ14() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n+1);
	vector<int> count(n + 1,0);
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		count[b]++;
	}

	queue<int> q;

	for (int i = 1; i <= n; i++)
		if (count[i] == 0)
			q.push(i);


	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int i = 0; i < graph[node].size(); i++) {
			count[graph[node][i]]--;

			if (count[graph[node][i]] == 0)
				q.push(graph[node][i]);
		}

		cout << node << ' ';
	}


}
#pragma endregion

#pragma region 13. ȸ��̱�(�÷��̵�-���� ����)
void DQ13() {
	int n;
	cin >> n;
	vector<vector<int>> graph(n + 1, vector<int>(n + 1,9999));

	for (int i = 1; i <= n; i++)
		graph[i][i] = 0;

	while (true) {
		int a, b;
		cin >> a >> b;
		
		if (a == -1 && b == -1)
			break;

		graph[a][b] = 1;
		graph[b][a] = 1;

	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
			}
		}
	}

	vector<int> score;
	int mins = 9999;
	for (int i = 1; i <= n; i++) {
		int s=0;
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] != 9999 &&s < graph[i][j])
				s = graph[i][j];
		}
		score.push_back(s);
		if (mins > s)
			mins = s;
	}
	
	vector<int> answer;
	for (int i = 0; i < n; i++) {
		if (score[i] == mins)
			answer.push_back(i+1);
	}


	cout << mins << ' ' << answer.size()<<'\n';
	for (int a : answer)
		cout << a << ' ';


}
#pragma endregion

#pragma region 12. �÷��̵� ���� �˰���
void DQ12() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n+1,vector<int>(n+1,9999));

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = c;

	}
	for (int i = 1; i <= n; i++) 
		graph[i][i] = 0;



	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (graph[j][k] > graph[j][i] + graph[i][k])
					graph[j][k] = graph[j][i] + graph[i][k];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] == 9999)
				cout << "M ";
			else
				cout << graph[i][j] << ' ';
		}
		cout << '\n';
	}


}
#pragma endregion

#pragma region 11. �ִ����� ���ϱ�(���� �˰���)
void DQ11() {
	int n, m;
	cin >> n >> m;
	vector<int> dy(m + 1, 0);

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		for (int j = b; j <= m; j++) {
			
			for (int k = 0; k <= m; k++) {
				if (j + k <= m) {
					dy[j+k] = max(dy[j+k], a + dy[j+k - b]);
				}
				else
					break;
			}

		}
	}

	cout << dy[m];

}
#pragma endregion

#pragma region 10. ������ȯ
void DQ10() {
	int n,m;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> m;
	vector<int> dy(m + 1, 9999);

	dy[0] = 0;
	for (int i = 0; i <n; i++) {
		dy[arr[i]] = 1;

		for (int j = arr[i]+1; j <= m; j++) {
			if (dy[j-arr[i]] + 1 < dy[j])
				dy[j] = dy[j - arr[i]] + 1;
		}
	}

	cout << dy[m];


}
#pragma endregion

#pragma region 9. ���湮��(���� �˰���)
void DQ9() {
	int n, k;
	cin >> n >> k;
	vector<int> dy(k+1, 0);

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		for (int j = a; j <= k; j++) {
			if (dy[j] < dy[j - a] + b)
				dy[j] = dy[j - a] + b;
		}
	}

	cout << dy[k];
}
#pragma endregion

#pragma region 8. �˸��ٹٿ� 40���� ����(Top-Down)
vector<vector<int>> dy8;
vector<vector<int>> map8;
int dfs8(int x, int y) {
	
	if (x == 0 && y == 0)
		return map8[x][y];
	else if (x == 0)
		return dy8[x][y]=dfs8(x, y - 1) + map8[x][y];
	else if (y==0)
		return dy8[x][y] = dfs8(x-1, y ) + map8[x][y];
	else
		return dy8[x][y] = min(dfs8(x-1,y),dfs8(x,y-1)) + map8[x][y];

}

void DQ8() {
	int n;
	cin >> n;
	map8 = vector<vector<int>>(n, vector<int>(n));
	dy8 = vector<vector<int>>(n, vector<int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map8[i][j];

	cout << dfs8(n - 1, n - 1);
}
#pragma endregion

#pragma region 7. �˸��ٹٿ� 40���� ����(Bottom-Up)
void DQ7() {
	int n;
	cin >> n;
	vector<vector<int>> map(n, vector<int>(n));
	vector<vector<int>> dp(n, vector<int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	dp[0][0] = map[0][0];
	for (int i = 1; i < n; i++) {
		dp[0][i] = dp[0][i - 1] + map[0][i];
		dp[i][0] = dp[i-1][0] + map[i][0];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (dp[i][j - 1] < dp[i - 1][j]) {
				dp[i][j] = dp[i][j - 1] + map[i][j];
			}
			else {
				dp[i][j] = dp[i - 1][j] + map[i][j];
			}
		}
	}

	cout << dp[n - 1][n - 1];

}
#pragma endregion

#pragma region 6. ���� ���� ž �ױ�
class brick {
public :
	int width;
	int height;
	int weight;

	brick() {};
};
void DQ6() {
	int n;
	cin >> n;
	int answer = 0;
	vector<brick> bricks = vector<brick>(n);
	vector<int> arr = vector<int>(n);

	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		bricks[i].width = a;
		bricks[i].height = b;
		bricks[i].weight = c;
	}


	sort(bricks.begin(), bricks.end(), [](brick b1, brick b2) -> bool {
		return b1.width > b2.width;
	});


	for (int i = 0; i < n; i++) {
		int max = 0;

		for (int j = 0; j < i; j++) {
			if (
				bricks[j].weight > bricks[i].weight &&
				max < arr[j])
				max = arr[j];
		}

		arr[i] = bricks[i].height + max;

		if (answer < arr[i])
			answer = arr[i];
	}

	
	cout << answer;
}
#pragma endregion

#pragma region 5. �ִ� �� �����ϱ�
void DQ5() {
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> dp(n,0);
	
	for (int i = 0; i < n; i++)
		cin >> v[i];

	for (int i = 0; i < n; i++) {

	}

	
}
#pragma endregion

#pragma region 4. �ִ� �κ� ��������
void DQ4() {
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> dp(n,0);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	dp[0] = 1;

	for (int i = 1; i < n; i++) {
		int max = 0;

		for (int j = 0; j < i; j++) {
			if (v[i] > v[j] && max < dp[j]) {
				max = dp[j];
			}
		}

		dp[i] = max + 1;

	}

	int max = 0;
	for (auto i : dp) {
		if (i > max)
			max = i;
	}
	cout << max << ' ';

}
#pragma endregion

#pragma region 2. ��Ʈ��ũ �� �ڸ���(Top-Down : ���, �޸������̼�)

void dfsd2(int n, int &count, vector<int> &vd2) {
	
	if (n == 0) {
		count++;
	}
	else if (n < 0) {
		return;
	}
	else {
		dfsd2(n - 2, count,vd2);
		dfsd2(n - 1, count, vd2);
	}

}

void DQ2() {
	int n;
	cin >> n;
	int count = 0;
	vector<int> vd2(n+1,-1);
	
	vd2[1] = 1;
	vd2[2] = 2;

	dfsd2(n,count,vd2);

	cout << count;
}
#pragma endregion

#pragma region 1. ������ȹ���̶�? ��Ʈ��ũ �� �ڸ���(Bottom-Up)
void DQ1() {
	int n;
	cin >> n;
	vector<int> v(n + 1);
	
	v[1] = 1;
	v[2] = 2;
	
	for (int i = 3; i <= n; i++) {
		v[i] = v[i - 2] + v[i - 1];
	}

	cout << v[n];

}
#pragma endregion

#pragma region 89. �丶��(BFS Ȱ��)
void Q89() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int m, n;
	cin >> m >> n;
	vector<vector<int>> map(n, vector<int>(m));

	vector<int> dx = { 0,0,1,-1 };
	vector<int> dy = { 1,-1,0,0 };
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			
			if (map[i][j] == 1) 
				q.push({ i,j });
		}



	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx > -1 && nx < n &&
				ny > -1 && ny < m &&
				map[nx][ny] == 0) {
				q.push({nx,ny });
				map[nx][ny] =map[x][y]+1;
			}
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
		
			if (map[i][j] == 0) {
				cout << -1;
				return;
			}
		
			if (map[i][j] > max)
				max = map[i][j];

		}
	}

	cout << max-1;

}
#pragma endregion

#pragma region 88. �̷��� �ִܰŸ� ���(BFS Ȱ��)
void Q88() {
	int n = 7;
	vector<vector<int>> map(n, vector<int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	queue<pair<int,int>> q;
	q.push({ 0,0 });
	map[0][0] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int dist = map[x][y];
		
		if (x == y == 6)
			return;
		
		q.pop();

		if (x + 1 < n && x + 1 > -1 && map[x + 1][y] == 0) {
			q.push({ x + 1,y });
			map[x + 1][y] = dist + 1;
		}
		if (x - 1 < n && x - 1 > -1 && map[x - 1][y] == 0) {
			q.push({ x - 1,y });
			map[x - 1][y] = dist + 1;
		}
		if (y + 1 < n && y + 1 > -1 && map[x ][y + 1] == 0) {
			q.push({ x ,y + 1 });
			map[x ][y + 1] = dist + 1;
		}
		if (y - 1 < n && y - 1 > -1 && map[x][y - 1] == 0) {
			q.push({ x ,y - 1 });
			map[x][y - 1] = dist + 1;
		}
	}

	cout << map[6][6]-1;

}
#pragma endregion

#pragma region 87. ������ ���Ϸ���(BFS Ȱ��)
vector<int> dx87 = { 0,0,1,-1,-1,-1,1,1 };
vector<int> dy87 = { 1,-1,0,0,1,-1,1,-1 };
void Q87() {

	int n;
	cin >> n;
	vector<vector<int>> map(n, vector<int>(n));
	int count = 0;
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				q.push({ i,j });

				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					map[x][y] = 0;

					for (int k = 0; k < 8; k++) {
						if (x + dx87[k] > -1 && x + dx87[k] <n &&
							y + dy87[k] >-1 && y + dy87[k] < n &&
							map[x + dx87[k]][y + dy87[k]]==1) {
							q.push({ x + dx87[k] ,y + dy87[k] });
						}
					}

				}

				count++;
			}
		}
	}

	cout << count;
}
#pragma endregion

#pragma region 86. ���� ��� �Ÿ�(�Ｚ SW������ ���⹮�� : DFSȰ��) x ������ ���� �Ȱ�
void Q355() {

}
#pragma endregion

#pragma region 85. ���ĸ����(�Ｚ SW������ ���⹮�� : DFSȰ��)
int max85 = 0;
int min85 = 999999;
void dfs85(int l, vector<int> &nums, 
	vector<int> &op,int num) {
	
	if (l == nums.size()) {
		if (num > max85)
			max85 = num;
		if (num < min85)
			min85 = num;
	}
	else {
		
		if (op[0] != 0) {
			op[0] --;
			dfs85(l + 1, nums, op, num + nums[l]);
			op[0] ++;
		}
		if (op[1] != 0) {
			op[1] --;
			dfs85(l + 1, nums, op, num - nums[l]);
			op[1] ++;
		}
		if (op[2] != 0) {
			op[2] --;
			dfs85(l + 1, nums, op, num * nums[l]);
			op[2] ++;
		}
		if (op[3] != 0) {
			op[3] --;
			dfs85(l + 1, nums, op, num / nums[l]);
			op[3] ++;
		}
	}
}

void Q85() {
	int n;
	cin >> n;
	vector<int> nums(n);
	vector<int> op(4);
	

	for (int i = 0; i < n; i++)
		cin >> nums[i];
	for (int i = 0; i < 4; i++)
		cin >> op[i];

	dfs85(1, nums, op, nums[0]);

	cout << max85 << '\n' << min85;
}
#pragma endregion

#pragma region 84. �ް�(�Ｚ SW������ ���⹮�� : DFSȰ��)
int max84 = 0;
void dfs84(int l, vector<pair<int, int>> v,int sum) {

	if (l == v.size()) {
		if (sum > max84)
			max84 = sum;
	}
	else {

		if(l+v[l].first <= v.size())
			dfs84(l + v[l].first, v, sum + v[l].second);
		dfs84(l +1, v, sum);

	}

}

void Q84() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[i] = { a,b };
	}

	dfs84(0, v, 0);

	cout << max84;
}
#pragma endregion

#pragma region 79. ��������(Prim MST �˰��� : priority_queue Ȱ��) ������ ��
void Q79() {

}
#pragma endregion

#pragma region 78. ��������(Kruskal MST �˰��� : Union&Find Ȱ��)

int findParent78(int n, vector<int> &circle) {
	if (n == circle[n])
		return n;
	else
		return circle[n] = findParent78(circle[n],circle);
}

void unionWays78(int a, int b, vector<int>& circle) {
	a = findParent78(a, circle);
	b = findParent78(b, circle);

	if (a > b)
		circle[a] = b;
	else
		circle[b] = a;
}

void Q78() {
	int v, e;
	cin >> v >> e;
	priority_queue<pair<int, pair<int, int>>> edges;
	vector<int> circle(v + 1);
	int sum = 0;

	for (int i = 1; i <= v; i++)
		circle[i] = i;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		edges.push({ -c,{a,b} });
	}


	while (!edges.empty()) {
		int dist = -edges.top().first;
		auto ways = edges.top().second;
		edges.pop();

		if (findParent78(ways.first, circle) != findParent78(ways.second, circle)) {
			unionWays78(ways.first, ways.second, circle);
			sum += dist;
		}
	}

	cout << sum;

}
#pragma endregion

#pragma region 77. ģ���ΰ�? (Union&Find �ڷᱸ��)
vector<int> friends77;

int findFriend77(int n) {
	if (n == friends77[n])
		return n;
	else
		return friends77[n] = findFriend77(friends77[n]);
}

void unionFriend77(int a, int b) {
	a = findFriend77(a);
	b = findFriend77(b);

	if (a > b)
		friends77[a] = b;
	else
		friends77[b] = a;
}

void Q77() {
	int n, m;
	cin >> n >> m;
	friends77 = vector<int>(n + 1);

	for (int i = 1; i <= n; i++)
		friends77[i] = i;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		unionFriend77(a, b);
	}

	int a, b;
	cin >> a >> b;

	if (findFriend77(a) == findFriend77(b))
		cout << "YES";
	else
		cout << "NO";
}
#pragma endregion

#pragma region 75. �ִ� ���� ������(priority_queue ���빮��)

class schedule75 {
public :
	int m;
	int d;

	schedule75() {}
	schedule75(int _m,int _d):m(_m),d(_d) {}

	bool operator<(const schedule75 &s)const {

		if (s.d > d) {
			return true;
		}
		else if (s.d == d) {
			if (s.m > m)
				return true;
			else
				return false;
		}
		else
			return false;

	}
};

void Q75() {
	int n;
	cin >> n;
	priority_queue<schedule75> q;
	for (int i = 0; i < n; i++) {
		int m, d;
		cin >> m >> d;
		q.push(schedule75(m, d));
	}

	while (!q.empty()) {
		cout << q.top().d << ',' << q.top().m << '\n';
		q.pop();
	}

}
#pragma endregion

#pragma region 71. �۾��� ã��(BFS : ����Ʈ��Ž��)  Ÿ�� �̽�..
void Q71() {
	int s, e;
	cin >> s >> e;
	vector<int> visited(10001,false);

	visited[s] = true;
	queue<pair<int,int>> q;
	q.push({ 0,s });

	while (!q.empty()) {
		int count =q.front().first;
		int now = q.front().second;
		q.pop();


		if (now == e) {
			cout << count;
			break;
		}

		if (now + 1 > -1 && now + 1 < 10001 && !visited[now + 1]) {
			q.push({ (count + 1), now + 1 });
			visited[now+1] = true;

		}
		if (now - 1 > -1 && now - 1 < 10001 && !visited[now - 1]) {
			q.push({ (count + 1), now - 1 });
			visited[now-1] = true;

		}
		if (now + 5 > -1 && now + 5 < 10001 && !visited[now + 5]) {
			q.push({ (count + 1), now + 5 });
			visited[now+5] = true;

		}
	}

}
#pragma endregion

#pragma region 68. �ּҺ��(DFS : ����ġ ����׷��� ��������Ʈ)
void Q68() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n + 1,vector<int>(n+1,99999));

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = c;
	}

	//for (int i = 1; i <= n; i++)
	//	graph[i][i] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (graph[j][k] > graph[j][i] + graph[i][k])
					graph[j][k] = graph[j][i] + graph[i][k];
			}
		}
	}

	cout << graph[1][n];
}
#pragma endregion

#pragma region 67. �ּҺ��(DFS : �������)
void Q67() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int,int>>> graph(n+1);
	priority_queue<pair<int, int>> q;
	vector<int> dp(n + 1,999999);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}

	dp[1] = 0;
	q.push({ 0,1 });

	while (!q.empty()) {
		int dist = -q.top().first;
		int node = q.top().second;
		q.pop();

		if (dist > dp[node])
			continue;

		for (int i = 0; i < graph[node].size(); i++) {
			int newNode = graph[node][i].first;
			int newDist = graph[node][i].second + dist;

			if (dp[newNode] > newDist) {
				dp[newNode] = newDist;
				q.push({ -newDist,newNode });
			}
		}
	}

	cout << dp[n];

}
#pragma endregion

#pragma region 65. �̷�Ž��(DFS)
int count65 = 0;
vector<int> px65 = { 0,0,-1,+1 };
vector<int> py65 = { -1,1,0,0 };
void dfs65(int x, int y, vector<vector<int>> map) {
	if (x == 6 && y == 6) {
		count65++;
		return;
	}

	for (int i = 0; i < 4; i++) {

		if(px65[i]+x <7 && px65[i] + x > -1 &&
			py65[i] + y <7 && py65[i] + y > -1)
			if (map[px65[i]+x][py65[i]+y]==0) {
				map[px65[i] + x][py65[i] + y] = 1;
				dfs65(x+ px65[i], y+ py65[i], map);
				map[px65[i] + x][py65[i] + y] = 0;
			}
	}
}

void Q65() {
	vector<vector<int>> map(7,vector<int>(7));

	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			cin >> map[i][j];

	map[0][0] = 1;
	dfs65(0,0, map);

	cout << count65;
}
#pragma endregion

#pragma region 64. ��� Ž��(DFS)
int count64 = 0;
void bfs64(int n,int node,vector<vector<int>> graph,vector<bool> visited) {
	if (n == node) {
		count64++;
	}else 
	
	{
		for (int i = 0; i < graph[node].size(); i++) {
			if (visited[graph[node][i]] == false) {
				visited[graph[node][i]] = true;
				bfs64(n, graph[node][i],graph, visited);
				visited[graph[node][i]] = false;

			}
		}
	}
}

void Q64() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n + 1);
	vector<bool> visited(n+1, false);
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}

	visited[1] = true;
	bfs64(n,1,graph, visited);

	cout << count64;
}
#pragma endregion

#pragma region 61. Ư�� �� �����(DFS : MS ���ͺ�)
int count61 = 0;
void dfs61(int n,int m, int l, vector<int> v, int sum) {
	
	if (n == l) {
		if (sum == m)
			count61++;
	}
	else {
		dfs61(n, m, l+1, v, sum+v[l]); 
		dfs61(n, m, l+1, v, sum-v[l]); 
		dfs61(n, m, l+1, v, sum); 
	}
}

void Q61() {
	int n,m;
	cin >> n >> m;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	dfs61(n, m, 0, v, 0);

	if (count61 == 0)
		cout << -1;
	else
		cout << count61;
}
#pragma endregion

#pragma region 60. ���� ���� �κ�����(DFS : �Ƹ��� ���ͺ�)
vector<int> v60;
int n60;
int total60 = 0;
bool isYes60 = false;
void dfs60(int l,int sum) {
	if (isYes60)
		return;
	
	if (l == n60) {
		if (sum*2 == total60) {
			isYes60 = true;
		}
	}
	else {
		dfs60(l + 1, sum + v60[l]);
		dfs60(l + 1, sum );
	}
}

void Q60() {
	cin >> n60;
	v60 = vector<int>(n60);
	
	for (int i = 0; i < n60; i++)
	{
		cin >> v60[i];
		total60 += v60[i];
	}
	dfs60(0, 0);

	if (isYes60)
		cout << "YES";
	else
		cout << "NO";
}
#pragma endregion

#pragma region 59. �κ�����(DFS)
vector<int> v59;
int n59;
void dfs59(int l) {
	if (n59+1 == l) {
		for (int i : v59)
			cout << i << ' ';
		cout << '\n';
	}
	else {
		v59.push_back(l);
		dfs59(l + 1);
		v59.pop_back();
		dfs59(l + 1);
	}
}

void Q59() {
	cin >> n59;

	dfs59(1);
}
#pragma endregion

#pragma region 57. ����Լ� ������ ���
void recursion57(int n, stack<int> s) {
	if (n == 0) {
		while(!s.empty()) {
			cout << s.top();
			s.pop();
		}
		return;
	}
	else {
		s.push(n % 2);
		recursion57(n / 2,s);
	}
	
}

void Q57() {
	int n;
	cin >> n;
	stack<int> s;
	recursion57(n,s);
}
#pragma endregion

#pragma region 55. ��������(stack ����)
void Q55() {
	int n;
	cin >> n;
	vector<int> v(n);
	stack<int> s;
	string answer = "";
	int index = 1;
	
	for (int i = 0; i < n; i++) {
		cin >> v[i];

		s.push(v[i]);
		answer += "P";

		while (s.top() == index) {
			s.pop();
			answer += "O";

			index++;
			if (s.empty())
				break;
		}

	}
	

 	if (!s.empty())
		cout << "impossible";
	else
		cout << answer;
}
#pragma endregion

#pragma region 54. �ùٸ� ��ȣ(stack)
void Q54() {
	string str;
	cin >> str;
	stack<char> s;

	for (char c : str)
	{
		if (c == '(')
			s.push(c);
		else {
			if (s.empty()) {
				cout << "NO";
				return;
			}
			else
				s.pop();
		}
	}

	if (s.empty())
		cout << "YES";
	else
		cout << "NO";

}
#pragma endregion

#pragma region 53. K���� ���
void Q53() {

	stack<int> s;
	int n,k;
	cin >> n >>k;

	while (n != 0) {
		s.push(n % k);
		n /= k;
	}

	while (!s.empty()) {
		int x = s.top();
		
		if (x >= 10) {
			cout << (char)(x + 55);
		}else
			cout << x;

		s.pop();
	}

}
#pragma endregion

#pragma region 52. Ugly Numbers  x
void Q52() {
	int n;
	cin >> n;
	vector<int> v;
	int p2=1, p3=1, p5=1;
	v.push_back(0);
	v.push_back(1);

	while (n+1 > v.size()) {
		int n2 = v[p2] * 2;
		int n3 = v[p3] * 3;
		int n5 = v[p5] * 5;

		int min = n2 > n3 ? (n3 > n5 ? n5 : n3) : (n2 > n5 ? n5 : n2);

		if (n2 == min)
			p2++;
		if (n3 == min)
			p3++;
		if (n5 == min)
			p5++;

		v.push_back(min);
	}

	cout << v[n];
}
#pragma endregion

#pragma region 51. ����(territory) ���� : (large)   ������ ���� �´µ� �ð� �ʰ�.
void Q51() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int h, w;
	cin >> h >> w;
	vector<vector<int>> dp(h+1, vector<int>(w+1,0));
	int n, m;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++) {
		
			int x;
			cin >> x;
			
			if (i != 1 && j != 1) {
				dp[i][j] = x+  dp[i - 1][j] + dp[i][j-1]-dp[i-1][j-1];
			}else if (i == 1) {
				if (j == 1)
					dp[i][j] = x;
				else {
					dp[i][j] = x + dp[i][j - 1];
				}
			}
			else if (j == 1) {
				dp[i][j] = x + dp[i - 1][j];
			}
		}

	cin >> n >> m;

	int max = 0;
	for (int i = n; i <=h; i++) {
		for (int j = m; j <=w; j++) {
			int a, b, c, d;
			
			if (i - n > -1)
				a = dp[i - n][j];
			else
				a = 0;
			if (j - m > -1) {
				b = dp[i][j - m];
				c = dp[i - n][j - m];
			}
			else {
				b = 0;
				c = 0;
			}

			 d = dp[i][j];

			if (max < d - a - b + c)
				max = d - a - b + c;

		}
	}

	cout << max;

	
}
#pragma endregion

#pragma region 50. ����(territory) ���� : (small)
void Q50() {
	int h, w;
	cin >> h >> w;
	vector<vector<int>> v(h, vector<int>(w));
	int n, m;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> v[i][j];
	cin >> n >> m;

	int max = 0;
	for (int i = 0; i <= h - n; i++) {
		for (int j = 0; j <= w - m; j++) {
			int sum = 0;

			for (int k = 0; k < n; k++) {
				for (int l = 0; l < m; l++) {
					sum += v[i+k][j+l];
				}
			}

			//cout << i << ' ' << j << " -> " << sum << '\n';

			if (sum > max)
				max = sum;
		}
	}


	cout << max;
}
#pragma endregion

#pragma region 49. ����� �ִ�
void Q49() {
	int n;
	cin >> n;
	vector<vector<int>> v(n, vector<int>(n));
	
	for (int i = 0; i < n; i++) {
		int x; 
		cin >> x;

		for (int j = 0; j < n; j++) {
			v[j][i] = x;
		}
	}

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		for (int j = 0; j < n; j++) {
			if(v[i][j] > x)
				v[i][j] = x;
		}
	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += v[i][j];
		}
	}

	cout << sum;
}
#pragma endregion

#pragma region 48. �� ���� ��հ� ���� ����� ��
void Q48() {
	vector<vector<int>> v(9, vector<int>(9));
	for (int i = 0; i < 9; i++) {
		double sum = 0;
		for (int j = 0; j < 9; j++) {
			cin >> v[i][j];
			sum += v[i][j];
		}

		int avg = (sum / 9) +0.5;

		int gap = 9999;
		int temp;
		for (int j = 0; j < 9; j++) {
			if (abs(avg - v[i][j]) < gap) {
				gap = abs(avg - v[i][j]);
				temp = v[i][j];
			}
			else if (abs(avg - v[i][j]) == gap) {
				if (v[i][j] > temp)
					temp = v[i][j];
			}
		
		}

		cout << avg << ' ' << temp << '\n';

	}
}
#pragma endregion

#pragma region 47. ���츮
void Q47() {
	int n;
	cin >> n;
	vector<vector<int>> v(n + 2,vector<int>(n+2,0));

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> v[i][j];

	int count = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (v[i - 1][j] < v[i][j] && v[i + 1][j] < v[i][j] &&
				v[i][j + 1] < v[i][j] && v[i][j - 1] < v[i][j])
				count++;
		}

	cout << count;

}
#pragma endregion

#pragma region 46. ��Ƽ�½�ŷ(īī�� �Թ� ���� ����) 
void Q46() {
	// queue�� Ǯ������ Ÿ�� �ƿ�.

	int n, k;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];
	cin >> k;

	
	int index = -1;
	for (int i = 0; i < k; i++) {
		index = (index + 1) % n;

		if (v[index] == 0) {
			i--;
			continue;
		}
			
		v[index]--;

	}

	index = (index + 1) % n;

	if(v[index] !=0)
		cout << index+1;
	else {

		for (int i = 0; i < n; i++) {
			index = (index + 1) % n;
			if (v[index] != 0) {
				cout << index+1;
				return;
			}
		}

		cout << -1;
	}


}
#pragma endregion

#pragma region 45. ���� ���ϱ�
void Q45() {
	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	queue<int> q;

	for (int i = 0; i < n; i++)
		q.push(i + 1);

	int count = 0;
	while (q.size() != 1) {
		count++;

		if (count == k) {
			q.pop();
			count = 0;
		}
		else {
			q.push(q.front());
			q.pop();
		}

	}

	cout << q.front();

}	
#pragma endregion

#pragma region 44. ������ ���ϱ�(�̺а˻� ����)   ���� ��ü ���ذ� �Ȱ�.
void Q44() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	int s = v[1] - v[0];
	int e = v[n - 1] - v[0];
	int mid;

	int answer = 0;

	while (s <= e) {
		mid = (s + e) / 2;
		int count = 0;

		int pos = v[0];
		for (int i = 1; i < n; i++) {
			if (v[i] - pos >= mid) {
				count++;
				pos = v[i];
			}
		}

		if (count >= m) {
			answer = mid;
			s = mid + 1;
		}
		else
			e = mid - 1;
	}
	std::cout << answer;

}
#pragma endregion

#pragma region 43. ��������(�̺а˻� ����) ��.. ��ȥ�� ��ǰ. --> ȥ�� Ǯ��
void Q43() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	int sum = 0;
	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}

	int answer = sum;
	int s = 0;
	int e = sum;
	int mid;

	while (s <= e) {
		mid = (s + e) / 2;

		int tempSum = 0;
		int tempCount = 0;
		for (int i = 0; i < n; i++) {
			tempSum += v[i];

			if (tempSum == mid) {
				tempSum = 0;
				tempCount++;
			}else if (tempSum > mid) {
				tempCount++;
				tempSum = v[i];
			}
		}

		if (tempSum != 0)
			tempCount++;

		if (tempCount <= m) {
			e = mid - 1;
			if (answer > mid)
				answer = mid;
		}
		else {
			s = mid + 1;
		}

	}

	cout << answer;
}
#pragma endregion

#pragma region 41. ���ӵ� �ڿ����� ��
void Q41() {
	int n;
	cin >> n;
	int p1 = n / 2;
	int p2 = n / 2 + 1;
	int count = 0;


	while ( p2 > -1) {
		int sum = 0;
		for (int i = p1; i <= p2; i++) {
			sum += i;
		}


		if (n == sum) {
			count++;

			for (int i = p1; i <p2; i++) {
				cout << i << " + ";
			}
			cout<<p2 << " = "<<n<<"\n";

			p2--;
			p1 = p2 - 1;
		}
		else {
			p1--;

			if (p1 < 0) {
				p2--;
				p1 = p2 - 1;
			}
		}
	}


	cout << count;

}
#pragma endregion

#pragma region 40. ������(������Ʈ �˰���)
void Q40() {
	int n;
	cin >> n;
	vector<int> v1(n);
	for (int i = 0; i < n; i++)
		cin >> v1[i];
	int m;
	cin >> m;
	vector<int> v2(m);
	for (int i = 0; i < m; i++)
		cin >> v2[i];
	int p1 = 0, p2 = 0;


	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	vector<int> v3;
	while (p1 < n && p2 < m) {
		if (v1[p1] == v2[p2]) {
			v3.push_back(v1[p1]);
			p1++;
			p2++;
		}
		else if (v1[p1] > v2[p2]) {
			p2++;
		}
		else {
			p1++;
		}
	}


	for (auto x : v3)
		cout << x << ' ';


}
#pragma endregion

#pragma region 39. �� �迭 ��ġ��
void Q39() {
	int n;
	cin >> n;
	vector<int> v1(n);
	for (int i = 0; i < n; i++)
		cin >> v1[i];
	int m;
	cin >> m;
	vector<int> v2(m);
	for (int i = 0; i < m; i++)
		cin >> v2[i];

	int p1 = 0, p2 = 0;
	vector<int> v3;
	while (p1 < n && p2 < m) {
		if (v1[p1] < v2[p2]) {
			v3.push_back(v1[p1++]);
		}
		else if (v1[p1] > v2[p2]) {
			v3.push_back(v2[p2++]);
		}
		else {
			v3.push_back(v1[p1++]);
			v3.push_back(v2[p2++]);
		}
	}

	for (p1; p1 < n; p1++)
		v3.push_back(v1[p1]);

	for (p2; p2 < m; p2++)
		v3.push_back(v2[p2]);

	
	for (auto i : v3)
		cout << i << ' ';

}
#pragma endregion

#pragma region 38. Inversion Sequence
void Q38() {
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> is(n);

	for (int i = 0; i < n; i++) {
		cin >> is[i];
		v[i] = i + 1;
	}

	for (int i = n - 1; i > -1; i--) {
		for (int j = 0; j < is[i]; j++) {
			int tmep = v[i+j];
			v[i +j] = v[i + j +1];
			v[i + j +1] = tmep;
		}
	}

	for (int i : v)
		cout << i << ' ';

}
#pragma endregion

#pragma region 37. Least Recently Used(īī�� ĳ�� ���� ����)
void Q37() {
	int s, n;
	cin >> s >> n;
	deque<int> deq;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;


		auto it = deq.begin();
		for (it; it != deq.end(); it++)
			if (*it == x)
				break;

		if (it == deq.end()) {
			deq.push_front(x);
			
			if(deq.size() > s)
				deq.pop_back();
		}
		else {
			deq.erase(it);
			deq.push_front(x);
		}

	}

	for (auto it : deq)
		cout << it << ' ';

}
#pragma endregion

#pragma region 35. Special Sort(���� ���ͺ�)
void Q35() {
	int n;
	cin >> n;
	vector<int> vec1;
	vector<int> vec2;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		if (x > 0)
			vec1.push_back(x);
		else
			vec2.push_back(x);
	}

	for (int n : vec1)
		vec2.push_back(n);

	for (int n : vec2)
		cout << n << ' ';


}
#pragma endregion

#pragma region 33. 3���� ������?
void Q33() {
	int n;
	cin >> n;
	vector<int> vec(n);

	for (int i = 0; i < n; i++)
		cin >> vec[i];

	sort(vec.begin(), vec.end());

	int last = vec[n - 1];
	int rank = 1;
	for (int i = n - 2; i > 0; i--) {
		if (last != vec[i]) {
			rank++;
			last = vec[i];
		}

		if (rank == 3) {
			cout << vec[i];
			return;
		}
	}
}
#pragma endregion

#pragma region 31. źȭ���� ����
void Q31() {
	string str;
	cin >> str;
	int num = 0;
	int answer = 0;
	for (char c : str) {
		if (c >= '0' && c <= '9') {
			num = num * 10 + c - '0';
		}
		else if (c == 'H') {

			if (num == 0)
				answer = 12;
			answer += num * 12;

			num = 0;
		}
	}

	if (num == 0)
		answer += 1;
	else
		answer += num;

	cout << answer;

}
#pragma endregion

#pragma region 30. 3�� ������?(large) xx
void Q30() {
	int n;
	cin >> n;

}
#pragma endregion

#pragma region 29. 3�� ������?(small)
void Q29() {
	int n;
	cin >> n;
	int count = 0;
	for (int i = 3; i <= n; i++) {
		int tmp = i;

		while (tmp != 0) {
			if (tmp % 10 == 3)
				count++;
			tmp /= 10;
		}
	}

	cout << count;
}
#pragma endregion

#pragma region 28. N!���� 0�� ����
void Q28() {
	int n;
	cin >> n;
	int count = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = i;
		while (tmp != 0) {
			if (tmp % 5 == 0) {
				count++;
				tmp /= 5;
			}
			else break;
		}
	}

	cout << count;
}
#pragma endregion

#pragma region 27. N!�� ǥ���� 
void Q27() {
	int n;
	cin >> n;
	vector<int> v(n+1,0);

	for (int i = 2; i <= n; i++) {
		int temp = i;

		int j = 2;

		while (true) {
			if (temp % j == 0) {
				temp /= j;
				v[j]++;
			}
			else j++;

			if (temp == 1) break;
		}

	}

	for (int i = 2; i <= n; i++) {
		if(v[i] != 0)
		cout << v[i] << ' ';
	}

}
#pragma endregion

#pragma region 26. ������
void Q26() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
	vector<int> player(n);
	vector<int> rank(n);

	for (int i = 0; i < n; i++) {
		cin >> player[i];
		rank[i] = i + 1;

		for (int j = 0; j < i; j++) {
			if (player[i] > player[j])
				rank[i]--;
		}
	}


	for (int i : rank)
		cout << i << ' ';

}
#pragma endregion

#pragma region 25. ���� ���ϱ�
void Q25() {
	int n;
	cin >> n;
	vector<int> score(n);
	vector<int> rank(n, n + 1);

	for (int i = 0; i < n; i++)
		cin >> score[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (score[i] >= score[j])
				rank[i]--;
		}
	}

	for (auto i : rank)
		cout << i << ' ';

}
#pragma endregion

#pragma region 24. Jolly Jumpers
void Q24() {
	int n;
	cin >> n;
	vector<int> vec;
	vector<int> vec2(n, 0);

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		vec.push_back(x);
	}

	for (int i = 0; i < n - 1; i++) {
		int a = abs(vec[i] - vec[i + 1]);
		if (a > -1 && a < n)
			vec2[a]++;
	}

	for (int i = 1; i < n; i++)
		if (vec2[i] != 1) {
			cout << "NO";
			return;
		}

	cout << "YES";


}
#pragma endregion

#pragma region 23. ���� �κ� ��������
void Q23() {
	int n;
	cin >> n;
	vector<int> v;
	int max = 0;
	int count = 1;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	for (int i = 0; i < n - 1; i++) {
		if (v[i] <= v[i + 1]) {
			count++;
		}
		else
			count = 1;

		if (count > max)
			max = count;

	}


	cout << max;
}
#pragma endregion

#pragma region 22. �µ��� �ִ밪   ����
void Q22() {
	int n, k;
	cin >> n >> k;
	vector<int> vec(n);
	int max;

	for (int i = 0; i < n; i++)
		cin >> vec[i];

	int temp = 0;
	for (int i = 0; i < k; i++) {
		temp += vec[i];
	}

	max = temp;
	for (int i = 0; i < n - k; i++)
	{
		temp = temp - vec[i] + vec[i + k];
		if (temp > max)
			max = temp;
	}

	cout << max;
}
#pragma endregion

#pragma region 21. ī�����
void Q21() {
	vector<int> a(10);
	vector<int> b(10);
	char lastWin = 'D';
	int ascore = 0;
	int bscore = 0;

	for (int i = 0; i < 10; i++)
		cin >> a[i];
	for (int i = 0; i < 10; i++)
		cin >> b[i];

	for (int i = 0; i < 10; i++) {
		if (a[i] > b[i]) {
			lastWin = 'A';
			ascore += 3;
		}
		else if (a[i] < b[i]) {
			lastWin = 'B';
			bscore += 3;
		}
		else
		{
			ascore++;
			bscore++;
		}
	}

	cout << ascore << ' ' << bscore << '\n';
	if (ascore == bscore)
		cout << lastWin;
	else if (ascore > bscore)
		cout << 'A';
	else
		cout << 'B';
}
#pragma endregion

#pragma region 20. ���� ���� ��
void Q20() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i])
			cout << "D\n";
		else if (a[i] == 1 && b[i] == 3)
			cout << "A\n";
		else if (b[i] == 1 && a[i] == 3)
			cout << "B\n";
		else if (b[i] > a[i])
			cout << "B\n";
		else
			cout << "A\n";
	}


}
#pragma endregion

#pragma region 19. �г� ������
void Q19() {
	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	int count = 0;
	for (int i = 0; i < n - 1; i++) {
		bool isBad = true;
		for (int j = i + 1; j < n; j++) {
			if (v[i] <= v[j]) {
				isBad = false;
				break;
			}
		}

		if (isBad)
			count++;
	}

	cout << count;
}
#pragma endregion

#pragma region 18. ��������
void Q18() {
	int n, m;
	cin >> n >> m;
	int count = 0;
	int max = 0;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (x > m) {
			count++;
			if (max < count)
				max = count;
		}
		else
			count = 0;
	}

	cout << max;
}
#pragma endregion

#pragma region 17. ������ ����
void Q17() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		int sum = 0;
		for (int j = 1; j <= x; j++) {
			sum += j;
		}

		if (sum == y)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
#pragma endregion

#pragma region 16. Anagram(�Ƴ��׷� : ���� ���ͺ� ����)
void Q16() {
	string str;
	string str2;
	cin >> str >> str2;
	vector<int> vec(100, 0);

	for (char c : str) {
		vec[c - 'A']++;
	}

	for (char c : str2) {
		vec[c - 'A']--;
	}

	for (int i : vec)
		if (i != 0) {
			cout << "NO";
			return;
		}

	cout << "YES";
}
#pragma endregion

#pragma region 15. �Ҽ��� ����
void Q15() {
	int n = 0;
	cin >> n;
	vector<bool> vec(200001, true);

	for (int i = 2; i < vec.size(); i++) {
		if (vec[i]) {
			for (int j = i * 2; j < vec.size(); j = j + i)
				vec[j] = false;
		}
	}

	int count = 0;
	for (int i = 2; i <= n; i++)
		if (vec[i])
			count++;

	cout << count;

}
#pragma endregion

#pragma region 14. ������ �Ҽ�
int reverse14(int x) {
	int rev = 0;
	while (x != 0) {
		rev = rev * 10 + x % 10;
		x /= 10;
	}

	return rev;
}

bool isPrime14(int x) {
	if (x == 1 || x == 0)
		return false;

	for (int i = 2; i < x; i++)
		if (x % i == 0)
			return false;

	return true;
}
void Q14() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (isPrime14(reverse14(x)))
			cout << reverse14(x) << ' ';
	}
}
#pragma endregion

#pragma region 13. ���� ���� ���� �ڸ���
void Q13() {
	string n;
	cin >> n;
	vector<int> v(10);

	for (int i = 0; i < n.size(); i++) {
		v[n[i] - '0']++;
	}

	int max = 0;
	int index;
	for (int i = 0; i < 10; i++) {
		if (max <= v[i]) {
			max = v[i];
			index = i;
		}
	}

	cout << index;
}
#pragma endregion

#pragma region ������ �� ����(large)
void Q12() {
	int n;
	cin >> n;

	int nine = 9;
	int size = 1;
	int sum = 0;
	while (n != 0) {
		if (nine <= n) {
			sum += nine * size;
			n -= nine;
			size++;
			nine *= 10;
		}
		else {
			sum += n * size;
			break;
		}
	}

	cout << sum;
}
#pragma endregion

#pragma region 11. ������ �� ����(small)
void Q11() {
	int n;
	cin >> n;
	int count = 0;
	for (int i = 1; i <= n; i++) {
		int temp = i;

		while (temp != 0) {
			count++;
			temp /= 10;
		}
	}

	cout << count;
}
#pragma endregion

#pragma region 10. �ڸ����� ��
void Q10() {
	int n;
	cin >> n;
	int max = 0;
	int maxSum = 0;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		int tempSum = 0;
		int temp = x;
		while (temp != 0) {
			tempSum += temp % 10;
			temp /= 10;
		}

		if (maxSum < tempSum) {
			maxSum = tempSum;
			max = x;
		}
		else if (maxSum == tempSum) {
			if (x > max)
				max = x;
		}
	}

	cout << max;
}
#pragma endregion

#pragma region 9. ����� ���
void Q09() {
	int n;
	cin >> n;
	vector<int> v(n + 1, 1);

	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			v[j]++;
		}
	}

	for (int i = 1; i <= n; i++)
		cout << v[i] << ' ';
}
#pragma endregion

#pragma region 8. �ùٸ� ��ȣ
void Q08() {
	string str;
	cin >> str;
	stack<char> s;

	for (auto c : str) {
		if (c == '(')
			s.push(c);
		else {
			if (s.empty())
			{
				cout << "NO";
				return;
			}
			else
				s.pop();
		}
	}

	if (s.empty())
		cout << "YES";
	else
		cout << "NO";


}
#pragma endregion

#pragma region 7. ����ܾ� ����
void Q07() {
	string str;
	getline(cin, str);
	string newStr = "";

	for (int i = 0; i < str.size(); i++) {
		if (str[i] != ' ') {
			if (str[i] >= 'A' && str[i] <= 'Z')
				newStr += str[i] ^ 32;
			else
				newStr += str[i];
		}
	}

	cout << newStr;
}
#pragma endregion

#pragma region 6. ���ڸ� ����
void Q06() {
	string str;
	cin >> str;

	int num = 0;
	for (int i = 0; i < str.size(); i++) {
		if (num == 0 && str[i] == '0')
			continue;
		else if (str[i] >= '0' && str[i] <= '9') {
			num = 10 * num + (str[i] - '0');
		}
	}

	int count = 0;
	for (int i = 1; i <= num; i++) {
		if (num % i == 0)
			count++;
	}

	cout << num << '\n' << count;
}
#pragma endregion

#pragma region 5. ���̰��
void Q05() {
	string str;
	cin >> str;

	char gender;
	int age;

	if (str[7] == '1') {
		gender = 'M';
		int t1 = (str[0] - '0') * 10;
		int t2 = str[1] - '0';
		age = 2020 - 1900 - t1 - t2;
	}
	else if (str[7] == '2') {
		int t1 = (str[0] - '0') * 10;
		int t2 = str[1] - '0';
		age = 2020 - 1900 - t1 - t2;
		gender = 'W';

	}
	else if (str[7] == '3') {
		gender = 'M';
		int t1 = (str[0] - '0') * 10;
		int t2 = str[1] - '0';
		age = 2020 - 2000 - t1 - t2;

	}
	else if (str[7] == '4') {
		gender = 'W';
		int t1 = (str[0] - '0') * 10;
		int t2 = str[1] - '0';
		age = 2020 - 2000 - t1 - t2;
	}

	cout << age << ' ' << gender;

}
#pragma endregion

#pragma region 4. ���� ����
void Q04() {
	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	cout << *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());

}
#pragma endregion

#pragma region 3. ������� �� 
void Q03() {
	int n, sum = 1;
	cin >> n;

	cout << "1";
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			cout << " + " << i;
			sum += i;
		}
	}
	cout << " = " << sum;

}
#pragma endregion

#pragma region 2. �ڿ����� �� 
void Q02() {
	int n, m, sum = 0;
	cin >> n >> m;

	for (int i = n; i < m; i++) {
		cout << i << " + ";
		sum += i;
	}

	cout << m << " = " << sum + m;
}
#pragma endregion

#pragma region 1. 1���� N���� M�� ����� 
void Q01() {
	int n, m, sum = 0;
	cin >> n >> m;

	for (int i = m; i <= n; i++) {
		if (i % m == 0) {
			sum += i;
		}
	}

	cout << sum;
}
#pragma endregion

