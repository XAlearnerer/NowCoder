#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>

using namespace std;

class Solution {
public:
	string PrintMinNumber(vector<int> numbers) {
		if (numbers.empty()) return "";
		sort(numbers.begin(), numbers.end(), [](int a, int b)
		{string p = to_string(a) + to_string(b); string q = to_string(b) + to_string(a); return p < q; });
		string res;
		for (auto i : numbers)
			res += to_string(i);
		return res;
	}
};