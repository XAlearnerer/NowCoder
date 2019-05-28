#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>

using namespace std;

class Solution {
public:
	int  NumberOf1(int n) {
		int res = 0;
		unsigned int t = 1;
		while (t)
		{
			if (t & n) ++res;
			t = t << 1;
		}

		return res;
	}
};






