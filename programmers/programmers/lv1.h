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
#pragma region 12903 가운데 글자 가져오기
string solution12903(string s) {
    string answer = "";
    
    if (s.size() % 2 == 0)
        answer += s[s.size() / 2 - 1];
    
    answer += s[s.size() / 2];

    return answer;
}
#pragma endregion
#pragma region 68935 3진법 뒤집기
int solution68935(int n) {
    int answer = 0;
    long long temp = 0;

    while (n != 0) {
        temp = temp * 10 + n % 3;
        n /= 3;
    }

    int index = 1;
    while (temp != 0) {
        answer += temp % 10 * index ;
        temp /= 10;
        index *= 3;
    }

    return answer;
}
#pragma endregion

#pragma region 12917 문자열 내림차순으로 배치하기
string solution12917(string s) {

    sort(s.rbegin(), s.rend());

    return s;
}
#pragma endregion
#pragma region 42576 완주하지 못한 선수
string solution42576(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;

    for (string s : participant) {
        if (m.find(s) == m.end())
            m.insert({ s,1 });
        else
            m.find(s)->second ++;
    }

    for (string s : completion) {
        m.find(s)->second--;
    }

    for (auto it = m.begin(); it != m.end(); it++)
        if (it->second != 0)
            answer = it->first;
    
    return answer;
}
#pragma endregion
#pragma region 12937 짝수와 홀수
string solution12937(int num) {
    string answer = "";

    if (num % 2 == 0)
        answer == "Even";
    else
        answer == "Odd";

    return answer;
}
#pragma endregion
#pragma region 12969 직사각형 별찍기
int solution12969(void) {
    int a;
    int b;
    cin >> a >> b;
    cout << a + b << endl;

    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a; j++) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}
#pragma endregion
#pragma region 12935 제일 작은 수 제거하기
vector<int> solution12935(vector<int> arr) {
    arr.erase(min_element(arr.begin(), arr.end()));
    
    if (arr.empty())
        arr.push_back(-1);

    return arr;
}
#pragma endregion
#pragma region 67256 키패드 누르기
string solution67256(vector<int> numbers, string hand) {
    string answer = "";
    pair<int, int> left = { 3,0 };
    pair<int, int> right = { 3,2 };
    vector<pair<int, int>> keypad = { {3,1},{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2} };

    for (int n : numbers) {
        if (n == 1 || n == 4 || n == 7) {
            answer += 'L';
            left = keypad[n];
        }
        else if (n == 3 || n == 6 || n == 9) {
            answer += 'R';
            right = keypad[n];
        }
        else {
            int leftdist = abs(left.first - keypad[n].first) + abs(left.second - keypad[n].second);
            int rightdist = abs(right.first - keypad[n].first) + abs(right.second - keypad[n].second);

            if (leftdist > rightdist) {
                answer += 'R';
                right = keypad[n];
            }
            else if(leftdist < rightdist) {
                answer += 'L';
                left = keypad[n];
            }
            else {
                if (hand == "right") {
                    answer += 'R';
                    right = keypad[n];
                }
                else {
                    answer += 'L';
                    left = keypad[n];
                }
            }
        }
    }

    return answer;
}
#pragma endregion
#pragma region 42862 체육복
int solution42862(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> students(n+1, 0);

    for (int a : reserve)
        students[a]++;

    for (int a : lost)
        students[a]--;

    for (int i = 1; i <= n; i++) {
        if (students[i] == -1) {
            if (students[i - 1] == 1) {
                students[i] = students[i - 1] = 0;
            }
            else if (students[i + 1] == 1) {
                students[i] = students[i + 1] = 0;
            }
        }
    }

    for (int a : students)
        if (a >= 0)
            answer++;

    return answer-1;
}
#pragma endregion

#pragma region 12910 나누어 떨어지는 숫자 배열
vector<int> solution12910(vector<int> arr, int divisor) {
    vector<int> answer;

    for (int a : arr)
        if (a % divisor == 0)
            answer.push_back(a);

    sort(answer.begin(), answer.end());

    if (answer.empty())
        answer.push_back(-1);

    return answer;
}
#pragma endregion
#pragma region 12919 서울에서 김서방 찾기
string solution12919(vector<string> seoul) {
    string answer = "";

    for (int i = 0; i < seoul.size(); i++) {
        if (seoul[i] == "Kim") {
            answer += "김서방은 "; 
            answer += to_string(i);
            answer += "에 있다";
            break;
        }
    }

    return answer;
}
#pragma endregion
#pragma region 12915 문자열 내 마음대로 정렬하기
int a12915;
bool comp12915(string s1, string s2) {
    if (s1[a12915] == s2[a12915]) {
        return s1 > s2;
    }
    return s1[a12915] < s2[a12915];
}
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    a12915 = n;
    sort(strings.begin(), strings.end(),comp12915);

    return answer;
}
#pragma endregion
#pragma region 70128 내적
int solution70128(vector<int> a, vector<int> b) {
    int answer = 0;

    for (int i = 0; i < a.size(); i++)
        answer += a[i] * b[i];

    return answer;
}
#pragma endregion
#pragma region 12944 평균 구하기
double solution12944(vector<int> arr) {
    double answer = 0;

    for (int a : arr)
        answer += a;

    return answer/arr.size();
}
#pragma endregion
#pragma region 12928 약수의 합
int solution12928(int n) {
    int answer = 0;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0)
            answer += i;
    }

    return answer;
}
#pragma endregion

#pragma region 12931 자릿수 더하기
int solution12931(int n)
{
    int answer = 0;

    while (n != 0) {
        answer += n % 10;
        n /= 10;
    }

    return answer;
}
#pragma endregion
#pragma region 12933 정수 내림차순으로 배치하기
long long solution12933(long long n) {
    long long answer = 0;
    priority_queue<int> q;

    while (n != 0) {
        q.push(n % 10);
        n /= 10;
    }

    while (!q.empty()) {
        answer = answer * 10 + q.top();
        q.pop();
    }

    return answer;
}
#pragma endregion
#pragma region 12932 자연수 뒤집어 배열로 만들기
vector<int> solution12932(long long n) {
    vector<int> answer;

    while (n != 0) {
        answer.push_back(n % 10);
        n /= 10;
    }

    return answer;
}
#pragma endregion
#pragma region 12930 이상한 문자 만들기
string solution12930(string s) {
    int index = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            index = 0;
            continue;
        }

        if (index % 2 == 0 && s[i] <='z' && s[i] >= 'a')
            s[i] ^= 32;
        else if (index % 2 != 0 && s[i] <= 'Z' && s[i] >= 'A') {
            s[i] ^= 32;
        }
        index++;
    }

    return s;
}
#pragma endregion

#pragma region 12926 시저 암호
string solution12926(string s, int n) {
    string answer = "";

    for (char c : s) {
        if (c == ' ') {
            answer += c;
        }
        else {
            if (c >= 'a' && c <= 'z') {
                c = (c - 'a' + n) % 26 + 'a';
            }
            else {
                c = (c - 'A' + n) % 26 + 'A';
            }
                answer += c;
        }
    }

    return answer;
}
#pragma endregion
#pragma region 12934 정수 제곱근 판별
long long solution12934(long long n) {
    long long answer = -1;

    for (int i = 1; i <= n; i++) {
        if (i * i == n) {
            answer = (i + 1) * (i + 1);
            break;
        }
    }

    return answer;
}
#pragma endregion
#pragma region 12940 최대공약수와 최소공배수
vector<int> solution12940(int n, int m) {
    vector<int> answer;
    int a, b;
    if (n > m) {
        int t = n;
        n = m;
        m = t;
    }

    for (int i = 1; i <= m; i++) {
        if (m % i == 0 && n % i == 0)
            a = i;
    }

    b = n * m / a;

    answer.push_back(a);
    answer.push_back(b);

    return answer;
}
#pragma endregion
#pragma region 12943 콜라츠 추측
int solution12943(int num) {
    int answer = 0;
    long long n = num;
    while (n != 1) {
        answer++;
        if (answer > 500) {
            answer = -1;
            break;
        }
        if (n % 2 == 0)
            n /= 2;
        else
            n = n * 3 + 1;
    }
    return answer;
}
#pragma endregion
#pragma region 12948 핸드폰 번호 가리기
string solution12948(string phone_number) {
    for (int i = 0; i < phone_number.size() - 4; i++)
        phone_number[i] = '*';

    return phone_number;
}
#pragma endregion
#pragma region 12947 하샤드 수
bool solution12947(int x) {
    int n = 0;
    int temp = x;

    while (temp != 0) {
        n += temp % 10;
        temp /= 10;
    }

    return x % n ==0;
}
#pragma endregion
#pragma region 12950 행렬의 덧셈
vector<vector<int>> solution12950(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    for (int i = 0; i < arr1.size(); i++) {
        vector<int> arr;
        for (int j = 0; j < arr1[i].size(); j++) {
            arr.push_back(arr1[i][j] + arr2[i][j]);
        }
        answer.push_back(arr);
    }

    return answer;
}
#pragma endregion

#pragma region 12954 x만큼 간격이 있는 n개의 숫자
vector<long long> solution12954(int x, int n) {
    vector<long long> answer;

    for (int i = 1; i <= n; i++) 
        answer.push_back(x * i);

    return answer;
}
#pragma endregion
#pragma region 12982 예산
int solution12982(vector<int> d, int budget) {
    int answer = 0;

    sort(d.begin(), d.end());

    for (int i = 0; i < d.size(); i++) {
        if (budget >= d[i]) {
            budget -= d[i];
            answer++;
        }
        else
            break;
    }

    return answer;
}
#pragma endregion
#pragma region 17681 [1차] 비밀지도
vector<string> solution17681(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for (int i = 0; i < n; i++) {
        int temp = arr1[i] | arr2[i];
        string str;
        
        while (temp != 0) {
            if (temp % 2 == 1)
                str = '#' + str;
            else
                str = ' ' + str;

            temp /= 2;
        }

        while (str.size() != n) {
            str = ' ' + str;
        }

        answer.push_back(str);
    }

    return answer;
}
#pragma endregion
#pragma region 17682 [1차] 다트 게임
int solution17682(string dartResult) {
    int answer = 0;
    stack<int> s;
    int num = 0;

    for (int i = 0; i < dartResult.size(); i++) {
        if (dartResult[i] == 'S') {
            s.push(num);
            num = 0;
        }
        else if (dartResult[i] == 'D') {
            s.push(num * num);
            num = 0;
        }
        else if (dartResult[i] == 'T') {
            s.push(num * num * num);
            num = 0;
        }
        else if (dartResult[i] == '*') {
            if (s.size() == 1) {
                int temp = s.top() * 2;
                s.pop();
                s.push(temp);
            }
            else {
                int temp = s.top() * 2;
                s.pop();
                int temp2 = s.top() * 2;
                s.pop();
                s.push(temp2);
                s.push(temp);
            }
        }
        else if (dartResult[i] == '#') {
            int temp = -s.top();
            s.pop();
            s.push(temp);
        }
        else {
            num = num * 10 + dartResult[i] - '0';
        }
    }

    while (!s.empty()) {
        answer += s.top();
        s.pop();
    }

    return answer;
}
#pragma endregion
#pragma region 42889 실패율
vector<int> solution42889(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> failed;

    for (int i = 1; i <= N; i++) {

        int reached = 0;
        int noPassed = 0;

        for (int j = 0; j < stages.size(); j++)
            if (stages[j] >= i) {
                if (stages[j] == i)
                    noPassed++;
                reached++;
            }

        if(reached!=0)
            failed.push_back({ (double)noPassed / (double)reached , i });
        else    
            failed.push_back({ 0,i});
    }

    sort(failed.begin(), failed.end(), [](pair<double, int> a, pair<double, int> b) -> bool {
        if (a.first == b.first)
            return (a.second < b.second);

        return a.first > b.first;
    });

    for (auto a : failed)
        answer.push_back(a.second);
    return answer;
}
#pragma endregion

#pragma region sol
void sol1() {
}
#pragma endregion