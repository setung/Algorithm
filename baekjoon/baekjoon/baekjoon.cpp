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
// 2504


#pragma region 2504 괄호의 값 
void sol() {
	int n, m;
	cin >> n >> m;
	vector<int> nodeUnion(n+1);
	vector<vector<int>> graph(n+1);

	for (int i = 1; i < n + 1; i++)
		nodeUnion[i] = i;
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}

}

#pragma endregion
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	sol();
}