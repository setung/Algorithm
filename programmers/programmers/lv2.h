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

#pragma region 12909 올바른 괄호
bool solution12909(string s)
{
    stack<char> st;

    for (char c : s) {
        if (c == '(')
            st.push(c);
        else {
            if (st.empty())
                return false;
            st.pop();
        }
    }

    if (!st.empty())
        return false;

    return true;
}
#pragma endregion
#pragma region 12945 피보나치 수
int solution12945(int n) {
    vector<int> v(n + 1);
    v[0] = 0;
    v[1] = 1;

    for (int i = 2; i <= n; i++)
        v[i] = (v[i - 2] + v[i - 1]) % 1234567;

    return v[n];
}
#pragma endregion
#pragma region 12911 다음 큰 숫자
int solution12911(int n) {
    int oneCount = 0;
    int temp = n;
   
    while (temp != 0) {
        if (temp % 2 == 1)
            oneCount++;
        temp /= 2;
    }

    while (true) {
        temp = ++n;
        int count = 0;
      
        while (temp != 0) {
            if (temp % 2 == 1)
                count++;
            temp /= 2;
        }

        if ( oneCount == count) {
            break;
        }
    }

    return n;
}
#pragma endregion

#pragma region sol  
void sol2() {
}
#pragma endregion

