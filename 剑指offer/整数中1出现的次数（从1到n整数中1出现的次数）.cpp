#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>

using namespace std;


// [LeetCode] Number of Digit One 

// 11 是算两次的


class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		if (n < 0) return 0;
		int round = n, base = 1;
		int res = 0;

		while (round > 0)
		{
			int weight = round % 10;
			round /= 10;
			res += round*base;

			if (weight == 1)
				res += (n%base) + 1;
			else if (weight > 1)
				res += base;

			base *= 10;

		}
		return res;

	}
};


class Solution2 {
public:
	int countDigitOne(int n) {
		int res = 0, a = 1, b = 1;
		while (n > 0) {
			res += (n + 8) / 10 * a + (n % 10 == 1) * b;
			b += n % 10 * a;
			a *= 10;
			n /= 10;
		}
		return res;
	}
};


//int main()
//{
//	int num = 13;
//
//	Solution n;
//	cout << n.NumberOf1Between1AndN_Solution(num) << endl;
//
//	Solution2 n2;
//	cout << n2.countDigitOne(num) << endl;
//	return 0;
//}