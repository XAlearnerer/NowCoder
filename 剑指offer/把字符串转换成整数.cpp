#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>

using namespace std;

class Solution {
public:
	int StrToInt(string str) {
		//reverse(str.begin(), str.end());
		bool sym = true;
		if (*str.begin() == '+' || *str.begin() == '-')
		{
			if (*str.begin() == '-') sym = false;
			str.erase(str.begin());
		}
		int res = 0;
		if (!helper(str, res)) return 0;
		if(sym)
			return res;
		else return -1 * res;

	}

	bool helper(string s,int& res)
	{
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] > '9' || s[i] < '0') return false;
			res = 10 * res + (s[i] - '0');
		}
		return true;
	}
};

