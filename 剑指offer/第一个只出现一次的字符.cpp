#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<unordered_map>

using namespace std;

class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		vector<int> v(100, 0);
		for (auto i : str)
		{
			++v[i - 'A'];
		}
		int res = -1;
		for (int i = 0; i < str.size(); ++i)
		{
			if (v[str[i] - 'A'] == 1) { res = i; break; }
		}

		return res;
	}
};


