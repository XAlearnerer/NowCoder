#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>

using namespace std;

class Solution {
public:
	int Add(int num1, int num2)
	{
		if (num2 == 0) return num1;
		int sum = num1, carry = 0;
		while (num2 != 0)
		{
			sum = (num1&num2) << 1;
			carry = num1^num2;
			num1 = carry;
			num2 = sum;
		}
		return carry;
	}
};
