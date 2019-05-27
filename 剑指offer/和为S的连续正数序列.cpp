#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		if (sum == 1) return{};
		int left = 1, right = 2;
		vector<vector<int> > res;
		while (left < right)
		{
			int cur = (right + 1)*right / 2 - (left - 1)*left / 2;
			if (cur == sum)
			{
				vector<int> v;
				for (int i = left; i <= right; ++i) v.push_back(i);
				res.push_back(v);
				++left;

			}
			else if (cur > sum)
				++left;
			else
				++right;
		}
		return res;
	}
};

