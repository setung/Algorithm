#pragma once
#include "header.h"

#pragma region 14. ��������(�׷���)  x
void QD14() {

}
#pragma endregion

#pragma region 13. ȸ��̱�(�÷��̵�-�ͼ� ����) x
void QD13() {

}
#pragma endregion

#pragma region 12. �÷��̵�-�ͼ�(�׷��� �ִܰŸ�) x
void QD12() {

}
#pragma endregion

#pragma region 11. �ִ����� ���ϱ�(���� �˰���)  x
void QD() {
	int n, m;
	cin >> n >> m ;
	vector<int> dy(m+1);
	
	for (int i = 0; i < n; i++) {
		int ps, pt;
		cin >> ps >> pt;

		for (int j = m; j >= pt; j--) {
			dy[j] = max(dy[j], dy[j - pt]+ps);
		}

	}

	cout << dy[m];
}
#pragma endregion

#pragma region 10. ������ȯ(���� �˰���)  �� �����ϰ� ������, �� ���� ������ �� �� �־���.
void QD10() {
	int n,m;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cin >> m;
	vector<int> dy(m+1,100);

	dy[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j / v[i] + dy[j%v[i]] < dy[j])
				dy[j] = j / v[i] + dy[j%v[i]];
		}
	}

	cout << dy[m];
}
#pragma endregion

#pragma region 9. ���湮��(���� �˰��� : Knapsack algorithm)   
void QD9_2() {
	int n, m;
	cin >> n >> m;
	vector<int> dy(m+1,0);
	int max = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		for (int j = a; j <= m; j++) {
			if (dy[j - a] + b > dy[j]) {
				dy[j] = dy[j - a] + b;

				if (max < dy[j])
					max = dy[j];
			}
		}
	}
	cout << max;
}
#pragma endregion
#pragma region 9. ���湮��(���� �˰��� : Knapsack algorithm)   �� Ǯ��, �ð��ʰ�
int n9, m9;
vector<pair<int, int>> vec9;
int max9 = 0;

void dfs9(int weight, int value) {
	if (weight > m9) return;

	if (max9 < value)
		max9 = value;

	for (int i = 0; i < n9; i++) {
		dfs9(weight + vec9[i].first, value + vec9[i].second);
	}

}
void QD9() {
	
	cin >> n9 >> m9;
	vec9 = vector<pair<int, int>>(n9);

	for (int i = 0; i < n9; i++) {
		int a, b;
		cin >> a >> b;
		vec9[i] = { a,b };
	}

	dfs9(0, 0);

	cout << max9;
}
#pragma endregion   

#pragma region 8. �˸��ٹٿ� 40���� ����(Top-Down)
vector<vector<int>> map8;
vector<vector<int>> dy8;
int dfs8(int x,int y) {
	if (x == 0) return dy8[x][y];
	if (y == 0) return dy8[x][y];
	if (dy8[x][y] != 0) return dy8[x][y];

	return dy8[x][y] = min(dfs8(x - 1, y), dfs8(x, y - 1)) + map8[x][y];
}

void QD8() {
	int n;
	cin >> n;
	map8= vector<vector<int>>(n, vector<int>(n));
	dy8 = vector<vector<int>>(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map8[i][j];
	
	dy8[0][0] = map8[0][0];
	for (int i = 1; i < n; i++) {
		dy8[0][i] = dy8[0][i - 1] + map8[0][i];
		dy8[i][0] = dy8[i - 1][0] + map8[i][0];
	}

	cout << dfs8(n - 1, n - 1);
}
#pragma endregion

#pragma region 7. �˸��ٹٿ� 40���� ����(Bottom-Up)
void QD7() {
	int n;
	cin >> n;
	vector<vector<int>> map(n,vector<int>(n));
	vector<vector<int>> dy(n, vector<int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];


	dy[0][0] = map[0][0];
	for (int i = 1; i < n; i++) {
		dy[0][i] = dy[0][i - 1] + map[0][i];
		dy[i][0] = dy[i - 1][0] + map[i][0];
	}


	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			int left=0, top=0;
			top = dy[i - 1][j];
			left = dy[i][j - 1];

			dy[i][j] = left > top ? top+map[i][j] : left+ map[i][j];
		}
	}

	cout << dy[n - 1][n - 1];

}
#pragma endregion

#pragma region 6. ���� ���� ž �ױ�(LIS����)
class brick6 {
public : 
	int width;
	int height;
	int weight;
	
	brick6() {}
	brick6(int a,int b, int c) : width(a),height(b),weight(c){}

	bool operator<(const brick6 &b)const {
		return width > b.width;
	}
};

void QD6() {
	int n;
	cin >> n;
	int answer = 0;
	vector<brick6> v(n);
	vector<int> dy(n);

	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[i] = brick6(a, b, c);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (v[i].width < v[j].width && v[i].weight < v[j].weight && max < dy[j])
				max = dy[j];
		}

		dy[i] = max +v[i].height;
		if (dy[i] > answer)
			answer = dy[i];
	}



	cout << answer;

}
#pragma endregion

#pragma region 5. �ִ� �� �����ϱ�(LIS����)
void QD5() {
	int n;
	cin >> n;
	vector<int> v(n+1);
	vector<pair<int,int>> dy(n+1);
	int answer = 0;
	
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	for (int i = 1; i <= n; i++) {
		
		for (int j= 1; j <= n; j++) {
			if (i == v[j]) {
				
				int max = 0;
				for (int k = 1; k < i; k++) {
					if (j > dy[k].first && max < dy[k].second)
						max = dy[k].second;
				}
				
				dy[i] = { j,max+1 };
				if (answer < dy[i].second)
					answer = dy[i].second;
				break;
			}

		}
	}

	cout << answer;

}
#pragma endregion

#pragma region 4. �ִ� �κ� ��������(LIS : Longest Increasing Subsequence)
void QD4() {
	int n;
	cin >> n;
	vector<int> vec(n);
	vector<int> dy(n);
	int answer = 0;

	for (int i = 0; i < n; i++)
		cin >> vec[i];

	for (int i = 0; i < n; i++) {
		
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (vec[i] > vec[j] && dy[j] > max)
				max = dy[j];
		}

		dy[i] = max+1;
		if (dy[i] > answer)
			answer = dy[i];
	}
 

	cout << answer;

}
#pragma endregion

#pragma region 3. �������� : ��ܿ�����(Top-Down : �޸������̼�)
vector<int> dy3(100);

int dfs3(int n) {
	if (dy3[n] != 0)
		return dy3[n];

	if (n == 1 || n == 2) 
		return n;
	else 
		return dy3[n] = dfs3(n-1) + dfs3(n-2);
}

void QD3() {
	int n;
	cin >> n;

	cout << dfs3(n);
}
#pragma endregion

#pragma region 2. ��Ʈ��ũ �� �ڸ���(Top - Down : ���, �޸������̼�)
vector<int> dy2(101);
int dfs2(int n) {

	if (dy2[n] != 0)
		return dy2[n];

	if (n == 1 || n == 2) return n;
	else {
		return dy2[n] = dfs2(n - 1) + dfs2(n - 2);
	}

}

void QD2() {
	int n;
	cin >> n;

	cout << dfs2(n);
}
#pragma endregion

#pragma region 1. ������ȹ���̶�? ��Ʈ��ũ �� �ڸ���(Bottom-Up)
void QD01() {
	int n;
	cin>>n;
	vector<int> vec(50);

	vec[1] = 1;
	vec[2] = 2;
	vec[3] = 3;

	for (int i = 4; i <= n; i++)
		vec[i] = vec[i - 1] + vec[i - 2];

	cout << vec[n];
	
}
#pragma endregion