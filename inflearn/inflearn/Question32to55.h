#pragma once
#include "header.h"

//정렬 & 이분탐색(결정알고리즘) & 투포인트 알고리즘 & 스택


#pragma region 55. 기차운행 (스택 자료구조 응용)
void Q55() {
     int n;
     stack<int> s;
     cin >> n;
     vector<int> v;
     int index = 1;

     for (int i = 0; i < n; i++) {
          int num;
          cin >> num;
          v.push_back(num);
     }

     int i = 0;
     string answer="";
     while (1) {
          
          if (!s.empty() && s.top() == index) {
               answer += "O";
               s.pop();
               index++;
          }
          else {

               if(i>=n) {
                    answer = "impossible";
                    break;
               }

               s.push(v[i]);
               answer += "P";
               i++;
          }
          if (s.empty() && i >= n)
               break;
     }

     cout << answer;

}
#pragma endregion

#pragma region 54. 올바른 괄호(stack)
void Q54() {
     string str;
     cin >> str;
     stack<char> s;

     for (auto c : str) {
          if (c == '(') {
               s.push(c);
          }
          else {
               if (s.empty()) {
                    cout << "NO";
                    return;
               }
               else
                    s.pop();
          }
     }


     if (s.empty()) cout << "YES";
     else cout << "NO";


}
#pragma endregion

#pragma region 53. K진수 출력
void Q53() {
     stack<int> s;
     int n, k;
     cin >> n >> k;

     while (n != 0) {
          s.push(n % k);
          n /= k;
     }

     string answer = "";
     while (!s.empty())
     {
          int top = s.top();
          if(top==10) answer += "A";
          else if(top==11) answer += "B";
          else if(top==12) answer += "C";
          else if(top==13) answer += "D";
          else if(top==14) answer += "E";
          else if(top==15) answer += "F";
          else answer += top + '0';

          s.pop();
     }

     cout << answer;

}
#pragma endregion

#pragma region 52. Ugly Numbers (투포인트 알고리즘 응용)   x 혼자 풀때 시간 초과
int a52[1501];
void Q52() {
     int n, i, p2, p3, p5, min = 214700000;
     cin >> n;
     
     a52[1] = 1;
 
     p2 = p3 = p5 = 1;

     for (i = 2; i <= n; i++) {
          if (a52[p2] * 2 < a52[p3] * 3)
               min = a52[p2] * 2;
          else 
               min = a52[p3] * 3;
          if (a52[p5] * 5 < min) 
               min = a52[p5] * 5;

          if (a52[p2] * 2 == min) p2++;
          if (a52[p3] * 3 == min) p3++;
          if (a52[p5] * 5 == min) p5++;
          
          a52[i] = min;
     }
     
     cout << a52[n];

}
#pragma endregion

#pragma region 51. 영지 (territory) 선택 (large : 2차원 배열 구간합 : 제한시간 1초 : DP)     x
void Q51() {

}
#pragma endregion

#pragma region 50. 영지 (territory) 선택 (small : 2차원 배열 브루트포스)
void Q50() {
     int h, w;
     int hh, ww;
     int max = 0;
     cin >> h >> w;
     vector<vector<int>> v(h, vector<int>(w, 0));

     for (int i = 0; i < h; i++) {
          for (int j = 0; j < w; j++) {
               int num;
               cin >> num;
               v[i][j] = num;
          }
     }

     cin >> hh >> ww;

     for (int i = 0; i < h; i++) {
          for (int j = 0; j < w; j++) {

               if (i + hh <= h && j + ww <= w) {
                    int sum = 0;
                    
                    for (int ii = i; ii <i+ hh; ii++) {
                         for (int jj = j; jj <j+ ww; jj++) {
                              sum += v[ii][jj];
                         }
                    }

                    if (sum > max)
                         max = sum;
               }
               else
                    continue;

          }
     }

     cout << max;
}
#pragma endregion

#pragma region 49. 블록의 최댓값
void Q49() {
     int n;
     cin >> n;
     int count = 0;
     vector<vector<int>> v(n, vector<int>(n, 0));

     for (int i = 0; i < n; i++) {
          int num;
          cin >> num;

          for (int j = 0; j < n; j++) {
               v[j][i] = num;
          }
     }

     for (int i = n - 1; i >=0; i--) {
          int num;
          cin >> num;

          for (int j = 0; j < n; j++) {
               if(v[i][j] > num)
                    v[i][j] = num;
          }
     }

     for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
              count +=v[j][i];
          }
     }

     cout<<  count;

}
#pragma endregion

#pragma region 48. 각 행의 평균과 가장 가까운 값(2차원 배열 탐색)
void Q48() {
     vector<vector<int>> v(9, vector<int>(9));
     vector<int>  avg;

     for (int i = 0; i < 9; i++) {
          double sum = 0;
          for (int j = 0; j < 9; j++) {
               int num;
               cin >> num;
               v[i][j] = num;
               sum += num;
          }

          avg.push_back((sum/9+ 0.5));
     }

     for (int i = 0; i < 9; i++) {
          cout << avg[i] << ' ';
          int gap = 99999;
          int index = 0;
          for (int j = 0; j < 9; j++) {
               if (abs(avg[i] - v[i][j]) < gap) {
                    gap = abs(avg[i] - v[i][j]);
                    index = j;
               }
          }
          cout << v[i][index] << '\n';
     }

}
#pragma endregion

#pragma region 47. 봉우리 
void Q47() {
     int n;
     cin >> n;
     vector<vector<int>> v(n+2,vector<int>(n+2,0));
     int count = 0;

     for (int i = 1; i < n+1; i++) {
          for (int j = 1; j < n+1; j++) {
               int num;
               cin >> num;
               v[i][j]=(num);
          }
     }

     for (int i = 1; i < n+1; i++) {
          for (int j = 1; j < n+1; j++) {
               if ( v[i][j] > v[i - 1][j] && 
                    v[i][j] > v[i][j-1] && 
                    v[i][j] > v[i+1][j] && 
                    v[i][j] > v[i][j+1])
                    count++;
          }
     }

     cout << count;

}
#pragma endregion

#pragma region 46. 멀티 태스킹 (카카오 "먹방" 문제 변형)
void Q46() {
     int n, k;
     cin >> n;
     vector<int> v;
     int sum = 0;

     for (int i = 0; i < n; i++) {
          int num;
          cin >> num;
          v.push_back(num);
          sum += num;
     }
     cin >> k;

     if (sum <= k) {
          cout << -1;
          return;
     }

     int time = 0;
     int pos = 0;
     while (time != k) {

          if (v[pos] != 0) {
               v[pos]--;
               time++;
          }

          pos = (pos+1) % n;

     }

     for (int i = 0; i < n; i++) {
          if (v[pos] == 0)
               pos = (pos + 1) % n;
          else
               break;
     }

     cout << pos+1 ;
}
#pragma endregion
 
#pragma region 45. 공주 구하기(조세퍼스)    시뮬레이션
void Q45() {
     int n, k;
     cin >> n >> k;
     int index = 1;
     int pos = 1;
     vector<bool> v(n+1,true);
     
     v[0] = false;
     while (n != 1) {
          if (index == k && v[pos]) {
               v[pos] = false;
               index = 1;
               n--;
               pos = (pos + 1) % v.size();
          }
          else if(!v[pos]){
               pos = (pos + 1) % v.size();
          }
          else {
                 index++;
                 pos = (pos + 1) % v.size();
          }
          
        
     }
 
     for (int i = 0; i < v.size(); i++) {
          if (v[i])
               cout << i;
     }

}
#pragma endregion

#pragma region 44. 마구간 정하기(이분검색 응용)   혼자 못품 
int count44(int len, vector<int> v) {
     int i, cnt = 1, pos = v[0];

     for (i = 1; i < v.size(); i++) {
          if (v[i] - pos >= len) {
               cnt++;
               pos = v[i];
          }
     }

     return cnt;
}

void Q44() {
     int n, c;
     int lt = 1, rt, mid, res=0;
     cin >> n >> c;
     vector<int> v(n);

     for (int i = 0; i < n; i++) {
          int num;
          cin >> num;
          v[i]=(num);
     }

     sort(v.begin(), v.end());
     rt = v[n - 1];

     while (lt <= rt) {
          mid = (lt + rt) / 2;

          if (count44(mid, v) >= c) {
               res = mid;
               lt = mid + 1;
          }
          else
               rt = mid - 1;
     }

     cout << res;

}
#pragma endregion

#pragma region 43. 뮤직비디오(이분검색 응용)   혼자 못품. x

vector<int> a43(1001);
int n43;
int count43(int s) {
     int i, cnt = 1, sum = 0;

     for (i = 1; i <= n43; i++) {
          if (sum + a43[i] > s) {
               cnt++;
               sum = a43[i];
          }
          else {
               sum += a43[i];
          }
     }

     return cnt;
}

void Q43() {
     int  m;
     cin >> n43 >> m;

     int rt = 0, lt = 1, mid, res,max=21470000;

     for (int i = 1; i <= n43; i++) {
          int num;
          cin >> num;

          a43[i]=(num);
          rt += num;
          if (a43[i] > max) max = a43[i];
     }

     while (lt <= rt) {
          mid = (lt + rt) / 2;
          if (count43(mid) <= m) {
               res = mid;
               rt = mid - 1;
          }
          else {
               lt = mid + 1;
          }
     }

     cout << res;

}
#pragma endregion

#pragma region 42. 이분검색 
void Q42() {
     // 내풀이
     /*int n, m;
     cin >> n >> m;
     vector<int> v;
     for (int i = 0; i < n; i++) {
          int num;
          cin >> num;
          v.push_back(num);
     }
     sort(v.begin(), v.end());

     int min = 0;
     int max = v.size() - 1;
     int mid = v.size() / 2;

     while (mid >-1) {
          if (v[mid] == m)
               break;
          else if (v[mid] > m) {
               max = mid;
               mid = (mid + min) / 2;
          }
          else {
               min = mid;
               mid = (mid + max + 1) / 2;
          }

     }

     cout << mid+1;*/

     int n, m;
     cin >> n >> m;
     vector<int> v;
     for (int i = 0; i < n; i++) {
          int num;
          cin >> num;
          v.push_back(num);
     }
     sort(v.begin(), v.end());

     int lt = 0, rt = n - 1, mid;
     while (lt <= rt) {
          mid = (lt + rt) / 2;

          if (v[mid] == m) {
               cout << mid + 1;
               break;
          }
          else if (v[mid] > m)
               rt = mid - 1;
          else
               lt = mid + 1;
     }

}
#pragma endregion

#pragma region 41. 연속된 자연수의 합                        참신
void Q41() {
     //내 풀이
     /*int n;
     cin >> n;
     int count = 0;
     for (int i = n-1; i > 0; i--) {
          int temp = 0;
          int index = i;
          while (temp < n) {

               temp += index++;

               if (temp == n) {
                    for (int j = i; j < index; j++) {
                         if (j + 1 != index)
                              cout << j << " + ";
                         else
                              cout << j;
                    }

                    cout << " = " << n<<"\n";
                    count++;
               }
          }

     }
     cout << count;*/

     int n;
     cin >> n;
     int tmp = n;
     int b = 1;
     int count = 0;

     n--;
     while (n > 0) {
          b++;
          n = n - b;
          if (n % b == 0) {
               int i;
               for (i = 1; i < b; i++)
                    cout << n / b + 1 << " + ";
               cout << (n / b) + i << " = " << tmp << '\n';
               count++;

          }
     }

     cout << count;



}
#pragma endregion

#pragma region 40. 교집합(투포인트 알고리즘) MS 인터뷰 1초      참신
void Q40() {
     int n, m;
     vector<int> v1;
     vector<int> v2;
     vector<int> v3;

     cin >> n;
     for (int i = 0; i < n; i++) {
          int num;
          cin >> num;
          v1.push_back(num);
     }
     sort(v1.begin(), v1.end());

     cin >> m;
     for (int i = 0; i < m; i++) {
          int num;
          cin >> num;
          v2.push_back(num);
     }
     sort(v2.begin(), v2.end());

     int p1 = 0;
     int p2 = 0;

     while (p1 < v1.size() && p2 < v2.size()) {
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

     for (auto n : v3)
          cout << n << ' ';

}
#pragma endregion         

#pragma region 39. 두 배열 합치기
void Q39() {
     int n;
     vector<int> v1, v2, v3;
     cin >> n;
     for (int i = 0; i < n; i++) {
          int num;
          cin >> num;
          v1.push_back(num);
     }
     cin >> n;
     for (int i = 0; i < n; i++) {
          int num;
          cin >> num;

          v2.push_back(num);
     }

     int p1 = 0;
     int p2 = 0;

     for (int i = 0; i < v1.size() + v2.size(); i++) {
          if (p1 > v1.size() - 1 || p2 > v2.size() - 1) {
               break;
          }

          if (v1[p1] > v2[p2]) {
               v3.push_back(v2[p2]);
               p2++;
          }
          else {
               v3.push_back(v1[p1]);
               p1++;
          }
     }

     int size = p1 == v1.size() ? v2.size() - p2 : v1.size() - p1;

     for (int i = 0; i < size; i++) {
          if (p1 == v1.size()) {
               v3.push_back(v2[p2]);
               p2++;
          }
          else {
               v3.push_back(v1[p1]);
               p1++;
          }
     }

     for (auto a : v3)
          cout << a << ' ';


}
#pragma endregion

#pragma region 38. Inversion Sequence
void Q38() {
     int n;
     cin >> n;
     vector<int> v(n);

     for (int i = 0; i < n; i++) {
          int num;
          cin >> num;
          v[i] = num;
     }


     for (int i = n - 1; i >= 0; i--) {
          int index = i;
          int temp = v[i];
          for (int j = 0; j < temp; j++) {
               v[i + j] = v[i + 1 + j];
               index = i + 1 + j;
          }

          v[index] = i + 1;

     }


     for (int a : v)
          cout << a << ' ';

}
#pragma endregion

#pragma region 37 Least Recently Used(카카오 캐시 문제 변형)
void Q37() {
     int s, n;
     vector<int> v;
     int idx = 0;

     cin >> s >> n;

     for (int i = 0; i < n; i++) {
          int task;
          cin >> task;

          int idx = 0;
          for (int j = 0; j < v.size(); j++) {
               if (v[j] == task) {
                    idx = j;
                    break;
               }
          }

          if (idx != 0) {
               for (idx; idx < v.size() - 1; idx++) {
                    v[idx] = v[idx + 1];
               }
               v[idx] = task;
          }
          else
               v.push_back(task);

     }


     idx = v.size() - 1;
     for (int i = 0; i < s; i++) {
          cout << v[idx--] << ' ';
     }

}
#pragma endregion

#pragma region 35. Special Sort(구글 인터뷰)
void Q35() {
     int n;
     vector<int> v;
     cin >> n;

     for (int i = 0; i < n; i++) {
          int num;
          cin >> num;
          v.push_back(num);
     }

     // 내 풀이
    /* for (int i = 0; i < v.size(); i++) {
          if (v[i] < 0)
               cout << v[i] << ' ';
     }
     for (int i = 0; i < v.size(); i++) {
          if (v[i] >= 0)
               cout << v[i] << ' ';
     }*/


     //풀이 버블소트
     for (int i = 0; i < n; i++)
          for (int j = 0; j < n - 1; j++) {
               if (v[j] >= 0 && v[j + 1] < 0) {
                    int temp = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = temp;
               }
          }

     for (int i = 0; i < v.size(); i++) {
          cout << v[i] << ' ';
     }
}
#pragma endregion

#pragma region 34. 삽입정렬
void Q34() {
     int n;
     cin >> n;
     vector<int> v;

     for (int i = 0; i < n; i++) {
          int num;
          cin >> num;
          v.push_back(num);
     }

     for (int i = 1; i < n; i++) {
          int temp = v[i];
          int j = i;

          for (j; j > 0; j--) {
               if (v[j - 1] > temp)
                    v[j] = v[j - 1];
               else
                    break;
          }

          v[j] = temp;

     }

     for (int i = 0; i < n; i++)
          cout << v[i] << ' ';


}
#pragma endregion

#pragma region 33. 3등의 성적은?
bool compareQ33(int n1, int n2) {
     if (n1 > n2)
          return true;
     else
          return false;
}

void Q33() {
     int n;
     vector<int> v;
     cin >> n;

     for (int i = 0; i < n; i++) {
          int score;
          cin >> score;
          v.push_back(score);
     }

     sort(v.begin(), v.end(), compareQ33);

     int idx = 0;

     for (int i = 0; i < v.size() - 1; i++) {
          if (idx == 2) {
               cout << v[i];
               break;
          }

          if (v[i] != v[i + 1])
               idx++;
     }


}
#pragma endregion

#pragma region 32. 선택정렬
void Q32() {
     int n;
     vector<int> v;
     cin >> n;

     for (int i = 0; i < n; i++) {
          int num;
          cin >> num;
          v.push_back(num);
     }

     for (int i = 0; i < v.size() - 1; i++) {
          int min = 9999;
          int minIndex = 0;
          int j = i;
          for (j = i; j < v.size(); j++) {
               if (v[j] < min) {
                    min = v[j];
                    minIndex = j;
               }
          }

          int temp = v[i];
          v[i] = v[minIndex];
          v[minIndex] = temp;

     }

     for (auto n : v)
          cout << n << ' ';

}
#pragma endregion