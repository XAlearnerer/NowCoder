#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		if (k > input.size()) return {};
		vector<int> res;
		sort(input.begin(), input.end());
		res.insert(res.end(), input.begin(), input.begin() + k);
		return res;
	}
};