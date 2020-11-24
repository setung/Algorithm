#pragma once
#include <stack>
#include <unordered_map>
#include <sstream>
#include <map>
#include <math.h>
#include <string>
#include <queue>
#include <set>
#include <unordered_set>
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
#pragma region 68644 두 개 뽑아서 더하기
vector<int> solution68644(vector<int> numbers) {
    vector<int> answer;
    set<int> s;

    for (int i = 0; i < numbers.size() - 1; i++) {
        for (int j = i+1; j < numbers.size(); j++) {
            s.insert(numbers[i] + numbers[j]);
        }
    }

    for (auto it = s.begin(); it != s.end(); it++)
        answer.push_back(*it);

    for (int a : answer)
        cout << a << ' ';

    return answer;
}

#pragma endregion
#pragma region 12901 2016년
string solution12901(int a, int b) {
    string answer = "";
    vector<string> days = { "THU","FRI","SAT","SUN","MON","TUE","WED" };
    vector<int> months = { 31,29,31,30,31,30,31,31,30,31,30,31 };

    int month = b;
    for (int i = 0; i < a-1; i++) {
        month += months[i];
    }

    answer = days[month % 7];


    return answer;
}
#pragma endregion
#pragma region 12918 문자열 다루기 기본
bool solution12918(string s) {
    bool answer = true;

    if (s.size() != 4 && s.size() != 6)
        return false;

    for (char c : s) {
        if (c < '0' || c >'9')
            return false;
    }


    return answer;
}
#pragma endregion
#pragma region 12906 같은 숫자는 싫어
vector<int> solution12906(vector<int> arr)
{
    vector<int> answer;
   
    for (int a : arr) {
        if (answer.empty() || answer.back() != a)
            answer.push_back(a);
    }

    return answer;
}
#pragma endregion
#pragma region 12922 수박수박수박수박수박수?
string solution12922(int n) {
    string answer = "";
    
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            answer += "수";
        else
            answer += "박";
    }

    return answer;
}
#pragma endregion
#pragma region 12916 문자열 내 p와 y의 개수
bool solution12916(string s)
{
    int count = 0;

    for (char c : s) {
        if (c == 'p' || c == 'P')
            count++;
        else if (c == 'y' || c == 'Y')
            count--;
    }

    return count==0;
}
#pragma endregion
#pragma region 42748 K번째수
vector<int> solution42748(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++) {
        vector<int> temp;
        for (int j = commands[i][0]-1; j < commands[i][1]; j++) {
            temp.push_back(array[j]);
        }

        sort(temp.begin(), temp.end());
        answer.push_back(temp[commands[i][2]-1]);
    }
        
    return answer;
}
#pragma endregion
#pragma region MyRegion
void sol() {

}
#pragma endregion