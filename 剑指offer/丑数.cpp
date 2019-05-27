#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
	int GetUglyNumber_Solution(int index) {
		if (index == 0) return 0;
		vector<int> v;
		int a2 = 0, b3 = 0, c5 = 0;
		v.push_back(1);
		while (v.size() < index)
		{
			v.push_back(min(min(v[a2] * 2, v[b3] * 3), v[c5] * 5));
			if (v.back() == v[a2] * 2) ++a2;
			if (v.back() == v[b3] * 3) ++b3;
			if (v.back() == v[c5] * 5) ++c5;
		}
		return v.back();
	}
};

