#pragma once
#include "header.h"
//코드구현력 기르기


#pragma region 31. 탄화수소 질량
void Q31() {
	string str;
	cin >> str;
	int sum;
	int num = 0;
	bool isC;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'C') {
			isC = true;

		}
		else if (str[i] == 'H') {

			if (num == 0)
				sum = 12;
			else
				sum = num * 12;

			isC = false;
			num = 0;
		}
		else {
			num = num * 10 + (str[i] - '0');
		}
	}

	if (num == 0)
		sum += 1;
	else
		sum += num;


	cout << sum;

}
#pragma endregion

#pragma region  30. 3의 개수는? (large : 제한시간 1초) x
void Q30() {
	int n;
	cin >> n;
	

}
#pragma endregion

#pragma region 29. 3의 개수는?(small) 구글 인터뷰
void Q29() {
	int n;
	cin >> n;
	int count = 0;

	for (int i = 1; i <= n; i++) {
		int temp = i;
		while (temp != 0) {
			int temp2 = temp % 10;
			if (temp2 == 3) count++;
			temp /= 10;
		}

	}

	cout << count;
}
#pragma endregion

#pragma region 28. N!에서 0의 개수
void Q28() {

	int n;
	cin >> n;
	int count = 0;
	for (int i = 1; i <= n; i++) {
		int temp = i;

		while (temp != 0) {
			if (temp % 5 == 0)
				count++;
			else
				break;

			temp /= 5;
		}
	}

	cout << count;
}
#pragma endregion

#pragma region 27. N!의 표현법(소인수 분해 응용)
void Q27() {

	int n;
	cin >> n;
	vector<int> ch(n + 1, 0);

	for (int i = 2; i <= n; i++) {
		int tmp = i;
		int j = 2;
		while (1) {
			if (tmp %j == 0) {
				tmp /= j;
				ch[j]++;
			}
			else
				j++;

			if (tmp == 1)
				break;
		}
	}

	cout << n << "! = ";
	for (int i = 2; i <= n; i++)
		if (ch[i] != 0)
			cout << ch[i] << ' ';

}
#pragma endregion

#pragma region 26. 마라톤
void Q26() {
	//풀이
	int n;
	int cnt;
	cin >> n;
	vector<int> v(n + 1);

	for (int i = 1; i <= n; i++) {
		int r;
		cin >> r;
		v[i] = r;
	}

	cout << "1 ";
	for (int i = 2; i <= n; i++) {
		cnt = 0;
		for (int j = i - 1; j >= 1; j--) {
			if (v[j] >= v[i]) cnt++;
		}

		cout << cnt + 1 << ' ';
	}

	// 내소스         // 풀이랑 속도 점수 같음..60점
   /* int n;
	cin >> n;
	vector<int> player;
	vector<int> rank(n,0);

	for (int i = 0; i < n; i++) {
		 int r;
		 cin >> r;
		 player.push_back(r);


		 int temp = i + 1;
		 for (int j = i; j >= 0; j--) {
			  if (temp == 1)
				   break;
			  if (player[i] > player[j])
				   temp--;
		 }

		 rank[i] = temp;
	}

	for (auto r : rank)
		 cout << r << ' ';*/

}
#pragma endregion

#pragma region 25. 석차 구하기
void Q25() {
	int n;
	cin >> n;
	vector<int> v(n, 0);
	vector<int> v2(n, 1);

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v[i] = (num);
	}

	for (int i = 0; i < n; i++) {
		int temp = v[i];
		for (int j = 0; j < n; j++) {
			if (v[i] < v[j])
				v2[i]++;
		}
	}

	for (auto v : v2)
		cout << v << ' ';
}
#pragma endregion

#pragma region 24. Jolly Jumpers
void Q24() {
	int n;
	cin >> n;
	vector<int> vec(10000);
	string answer = "YES";

	int temp = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		if (i != 0)
			vec[abs(temp - a)]++;

		temp = a;
	}

	for (int i = 1; i < n; i++) {
		if (vec[i] != 1)
			answer = "NO";
	}

	cout << answer;
}
#pragma endregion

#pragma region 23. 연속 부분 증가수열
void Q23() {
	int n;
	cin >> n;
	int count = 0;
	int max = 0;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}


	for (int i = 0; i < n - 1; i++) {
		if (v[i] <= v[i + 1]) {
			count++;
			if (max < count)
				max = count;
		}
		else
			count = 0;
	}


	cout << max + 1;

}
#pragma endregion

#pragma region 22. 온도의 최대값
void Q22() {
	int n, k;
	cin >> n >> k;
	vector<int> vec(n);
	int max = -999999;

	int count = 0;
	int temp = 0;
	for (int i = 0; i < n; i++) {
		cin >> vec[i];

		count += vec[i];
		temp++;

		if (k == temp)
		{
			if (count > max)
				max = count;

			count -= vec[i - temp+1];
			temp--;
		}

	}

	cout << max;
}
#pragma endregion

#pragma region 21. 카드게임(기본코딩설계)
void Q21() {
	vector<int> a(10);
	vector<int> b(10);
	char lastwin = 'D';
	int ascore = 0;
	int bscore = 0;

	for (int i = 0; i < 10; i++)
		cin >> a[i];
	for (int i = 0; i < 10; i++)
		cin >> b[i];

	for (int i = 0; i < 10; i++) {
		if (a[i] > b[i]) {
			ascore += 3;
			lastwin = 'A';
		}
		else if (a[i] < b[i]) {
			bscore += 3;
			lastwin = 'B';
		}
		else {
			ascore++;
			bscore++;
		}
	}

	cout << ascore << ' ' << bscore << '\n';
	if (ascore > bscore)
		cout << 'A';
	else if (ascore < bscore)
		cout << 'B';
	else
		cout << lastwin;

}
#pragma endregion

#pragma region 20. 가위 바위 보
void Q20() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);

	for (int i = 0; i < n * 2; i++) {
		int aa;
		cin >> aa;

		if (i < n)
			a[i] = aa;
		else
			b[i%n] = aa;

	}

	for (int i = 0; i < n; i++) {

		int result = (a[i] - b[i]);
		if (result == 0)
			cout << "D\n";
		else if (result == 1 || result == -2)
			cout << "A\n";
		else
			cout << "B\n";
	}
}
#pragma endregion

#pragma region 19. 분노 유발자
void Q19() {
	int n;
	cin >> n;
	int count = 0;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v[i] = t;
	}

	for (int i = 0; i < v.size() - 1; i++) {
		bool isBad = true;
		for (int j = i + 1; j < v.size(); j++) {
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

#pragma region 18. 층간소음
void Q18() {
	int n, m;
	int max = 0;
	int count = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;

		if (v > m) {
			count++;
			if (max < count)
				max = count;
		}
		else {
			count = 0;
		}
	}

	cout << max;

}
#pragma endregion

#pragma region 17. 선생님 퀴즈
void Q17() {
	vector<int> v(1001, 0);
	int n = 0;
	cin >> n;

	for (int i = 1; i < 1001; i++) {
		v[i] = v[i - 1] + i;
	}

	for (int i = 0; i < n; i++) {
		int n1, n2;
		cin >> n1 >> n2;

		if (v[n1] == n2)
			cout << "YES\n";
		else cout << "NO\n";
	}

}
#pragma endregion

#pragma region 16. Anagram(아나그램 : 구글 인터뷰 문제)
void Q16() {
	string str1;
	string str2;
	string answer = "YES";;
	unordered_map<char, int> m;

	cin >> str1 >> str2;

	for (char c : str1) {
		if (m.find(c) == m.end()) {
			m.insert(pair<char, int>(c, 1));
		}
		else {
			m.at(c)++;
		}
	}
	for (char c : str2) {
		if (m.find(c) == m.end()) {
			answer = "NO";
			break;
		}
		else {
			m.at(c)--;
		}
	}

	for (auto a : m) {
		if (a.second != 0)
			answer = "NO";
	}

	cout << answer;
}
#pragma endregion

#pragma region 15. 소수의 개수          참신
void Q15() {
	int n;
	int answer = 0;
	cin >> n;
	/* vector<bool> arr(n+1,true);

	 arr[0] = false;
	 arr[1] = false;

	 for (int i = 2; i < arr.size(); i++) {
		  if (arr[i] == true) {
			   for (int j = i * 2; j < arr.size(); j +=i)
					arr[j] = false;
		  }
	 }

	 for (int i = 2; i <= n; i++) {
		  if (arr[i] == true)
			   answer++;
	 }

	 cout << answer;*/

	for (int i = 2; i <= n; i++) {
		bool flag = true;
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				flag = false;
				break;
			}
		}

		if (flag) answer++;
	}
	cout << answer;

}
#pragma endregion    

#pragma region 14. 뒤집은 소수   참신
vector<bool> v14(100001, true);
int reverse14(int x) {

	int reversedNum = 0;

	while (x != 0) {
		reversedNum = (reversedNum * 10) + (x % 10);
		x /= 10;
	}

	return reversedNum;

}
bool isPrime14(int x) {
	return v14[x];
}
void Q14() {

	int n;
	cin >> n;
	vector<int> answer;

	v14[0] = false;
	v14[1] = false;
	for (int i = 2; i < v14.size(); i++) {
		if (v14[i] == true)
			for (int j = i + i; j < v14.size(); j += i)
				v14[j] = false;
	}


	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		x = reverse14(x);

		if (isPrime14(x))
			answer.push_back(x);
	}

	for (auto n : answer)
		cout << n << ' ';


}
#pragma endregion

#pragma region 13. 가장 많이 사용된 자릿수
void Q13() {
	string n;
	vector<int> v(10, 0);
	int max = 0;
	int maxIndex;
	cin >> n;

	for (auto c : n) {
		int temp = c - '0';
		v[temp] ++;
	}

	for (int i = 0; i < v.size(); i++) {
		if (max <= v[i]) {
			max = v[i];
			maxIndex = i;
		}
	}

	cout << maxIndex;

}
#pragma endregion

#pragma region 12. 숫자의 총 개수(Large)   x
void Q12() {
	int n;
	cin >> n;
	int sum = 0;
	int c = 1, d = 9, res = 0;

	while (sum + d < n) {
		res = res + (c*d);
		sum = sum + d;
		c++;
		d = d * 10;
	}

	res = res + ((n - sum)*c);
	cout << res;
}
#pragma endregion

#pragma region 11. 숫자의 총 개수(small)
void Q11() {
	int n;
	int count = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int num = i;

		do {
			count++;
			num /= 10;
		} while (num != 0);

	}

	cout << count;

}
#pragma endregion

#pragma region 10. 자릿수의 합
int digit_sum10(int n) {
	int sum = 0;

	while (n != 0) {
		sum += n % 10;
		n /= 10;
	}

	return sum;
}
void Q10() {
	int max = 0;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (digit_sum10(num) == digit_sum10(max))
			max = num > max ? num : max;

		else if (digit_sum10(num) > digit_sum10(max))
			max = num;
	}


	cout << max;


}
#pragma endregion

#pragma region 9. 모두의 약수
void Q9() {
	int n;
	int dp[50001] = { 0 };
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			dp[j]++;
		}
	}

	for (int i = 1; i <= n; i++)
		cout << dp[i] << ' ';



	/*for (int i = 1; i <= n; i++) {
		 int cnt = 1;
		 for (int j = 1; j < i; j++) {
			  if (i % j == 0)
				   cnt++;
		 }
		 dp[i] = cnt;
	}

	for (int i = 1; i <= n; i++)
		 cout << dp[i] << ' ';*/


}
#pragma endregion

#pragma region 8. 올바른 괄호
string Q8() {
	string str;
	cin >> str;
	stack<char> s;

	/*for (auto c : str) {
		 if (c == '(')
			  s.push(c);
		 else {
			  if (s.empty())
				   return "NO";
			  s.pop();
		 }
	}

	if (s.empty())
		 return "YES";
	else
		 return "NO";*/

		 //풀이
	int cnt = 0;
	for (auto c : str) {
		if (c == '(')
			cnt++;
		else {
			cnt--;
		}

		if (cnt < 0) break;

	}

	if (cnt == 0)
		return "YES";
	else return "NO";

}
#pragma endregion

#pragma region 7. 영어단어 복구
void Q7() {
	string str;
	string answer = "";

	getline(cin, str);

	for (auto c : str) {
		if (c >= 97 && c <= 123)
			answer += c;
		else if (c == ' ')
			continue;
		else
			answer += c ^ 32;
	}

	cout << answer;

}
#pragma endregion

#pragma region 6. 숫자만 추출
int Q6() {
	string str;
	int num = 0;
	int count = 0;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if ((str[i] - '0') >= 0 && (str[i] - '0') <= 9) {
			num = num * 10 + str[i] - '0';
		}
	}

	for (int i = 1; i <= num; i++) {
		if (num % i == 0)
			count++;
	}

	cout << num << '\n' << count;

	return 0;
}
#pragma endregion

#pragma region 5. 나이계산 
int Q5() {
	string str;
	char sex;
	int year = 0;

	cin >> str;

	sex = str[7];

	year += (str[0] - '0') * 10;
	year += (str[1] - '0');

	if (sex == '1') {
		year += 1900;
		sex = 'M';
	}
	else if (sex == '2') {
		year += 1900;
		sex = 'W';
	}
	else if (sex == '3') {
		year += 2000;
		sex = 'M';
	}
	else {
		year += 2000;
		sex = 'W';
	}

	cout << 2020 - year << " " << sex;

	return 0;
}
#pragma endregion

#pragma region 4. 나이 차이
int Q4() {
	int n;
	int min = 0;
	int max = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int age;
		cin >> age;

		if (i == 0) {
			max = age;
			min = age;
		}

		if (max < age)
			max = age;
		else if (min > age)
			min = age;
	}

	cout << max - min;

	return max - min;
}
#pragma endregion

#pragma region 3. 진약수의 합
int Q3() {
	int n;
	int sum = 0;
	cin >> n;

	/*for (int i = 1; i < n; i++) {
		 if (n % i == 0) {

			  cout << i;
			  if(sum!=0)
				   cout << " + ";

			  sum += i;
		 }
	}
	cout << " = " << sum;*/

	// 풀이
	sum = 1;
	cout << "1";
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			cout << " + " << i;
			sum += i;
		}
	}
	cout << " = " << sum;

	return sum;
}
#pragma endregion

#pragma region 2번 <자연수의 합>
int Q2() {
	int a;
	int b;
	int sum = 0;
	cin >> a >> b;

	/*  for (int i = a; i <= b; i++) {
		   sum += i;
		   cout << i;

		   if (i != b)
				cout << " + ";
	  }
	  cout << " = " << sum;*/

	  // 풀이

	for (int i = a; i < b; i++) {
		cout << i << " + ";
		sum = sum + i;
	}

	cout << b << " = " << sum + b;

	return sum;
}
#pragma endregion

#pragma region 1번 <1 부터 N까지 M의 배수 합>
int Q1() {
	int n;
	int m;
	cin >> n >> m;
	int sum = 0;

	for (int i = 1; i <= n / m; i++) {
		sum += i * m;
	}

	//해설
   /* for (int i = 1; i <= n; i++) {
		 if (i % m == 0)
			  sum += i;
	}*/

	cout << sum;
	return sum;
}
#pragma endregion


