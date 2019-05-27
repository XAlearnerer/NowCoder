#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		if (array.empty()) return 0;
		int res = array[0], cur = 0;
		for (int i = 0; i < array.size(); ++i)
		{
			cur += array[i];
			res = max(res, cur);

			//////-2,-8,-1,-5,-9
			// ×¢Òâ¸ºÊý

			if (cur < 0) cur = 0;
		}
		return res;
	}
};

//int main()
//{
//	vector<int> a = { -2,-8,-1,-5,-9 };
//	Solution n;
//	cout << n.FindGreatestSumOfSubArray(a) << endl;
//
//	return 0;
//}