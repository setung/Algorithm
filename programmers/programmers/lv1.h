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

#pragma region 12921 소수 찾기
int solution12921(int n) {
    int answer = 0;
    vector<bool> v(n+1, true);

    for (int i = 2; i <= n; i++) 
        if (v[i]) 
            for (int j = i * 2; j <= n; j+=i) 
                v[j] = false;
            
    for (int i = 2; i <= n; i++) 
        if (v[i]) 
            answer++;
    
    return answer;
}
#pragma endregion
#pragma region 12912 두 정수 사이의 합

long long solution12912(int a, int b) {
    long long answer = 0;
    
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    answer = ((long long)(a + b) * (long long)(b - a + 1)) / 2;

    return answer;
}
#pragma endregion
#pragma region 12925 문자열을 정수로 바꾸기
int solution12925(string s) {
    int answer = 0;
    int index;
    bool isMinus = false;
    
    if (s[0] == '-') { 
        index = 1;
        isMinus = true;
    }
    else if (s[0] == '+') {
        index = 1;
    }else 
        index = 0;

    for (index; index < s.size(); index++) {
        answer = answer * 10 + s[index]-'0';
    }

    if (isMinus)
        answer *= -1;

    return answer;
}
#pragma endregion
#pragma region 64061 크레인 인형뽑기 게임
int solution64061(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int n = board.size();
    stack<int> s;

    for (int i = 0; i < moves.size(); i++) {
        int move = moves[i] - 1;

        for (int j = 0; j < n; j++) {
            if (board[j][move] != 0) {
                if (!s.empty() && board[j][move] == s.top()) {
                    s.pop();
                    answer++;
                }
                else {
                    s.push(board[j][move]);
                }
                
                board[j][move] = 0;
                
                break;
            }
        }
    }

    return answer*2;
}
#pragma endregion
#pragma region 42840 모의고사
vector<int> solution42840(vector<int> answers) {
    vector<int> answer;
    vector<vector<int>> supo(3);
    vector<int> counts;
    supo[0] = { 1,2,3,4,5 };
    supo[1] = { 2, 1, 2, 3, 2, 4, 2, 5 };
    supo[2] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    int maxi = 0;
    for (int i = 0; i < 3; i++) {
        int count = 0;
        
        for (int j = 0; j < answers.size(); j++) {
            if (answers[j] == supo[i][j % supo[i].size()])
                count++;
        }

        if (count > maxi)
            maxi = count;

        counts.push_back(count);
    }

    if(maxi !=0 )
        for (int i=0; i<counts.size(); i++)
            if (counts[i] == maxi)
                answer.push_back(i+1);
    
    for (int a : answer)
        cout << a << ' ';
    
    return answer;
}
#pragma endregion
#pragma region MyRegion
void sol() {
}
#pragma endregion

