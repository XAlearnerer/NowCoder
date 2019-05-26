#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<string> Permutation(string str) {
		if (str.empty()) return {};
		vector<string> res;
		helper(str, res, 0);
		sort(res.begin(), res.end());
		return res;
	}

	void helper(string str, vector<string>& res,int pos)
	{
		if (pos == str.size()) res.push_back(str);
		else
		{
			for (int i = pos; i < str.size(); ++i)
			{
				using std::swap;

				if (i!=pos && str[pos] == str[i]) continue;

				swap(str[pos], str[i]);
				helper(str, res, pos + 1);
				swap(str[pos], str[i]);
			}
		}
	}
};
