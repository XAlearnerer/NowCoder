#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_set>

using namespace std;
//
//class Solution {
//public:
//	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
//		unordered_set<int> s(array.begin(), array.end());
//		vector<int> res;
//		for (int i = 0; i < array.size(); ++i)
//		{
//			if (s.count(sum - array[i]) > 0)
//			{
//				if (res.empty()) res = { array[i],sum - array[i] };
//				else
//				{
//					if (array[i] * sum - array[i] < res[0] * res[1])
//					{
//						array.clear; array = { array[i],sum - array[i] };
//					}
//				}
//				s.erase(array[i]);
//				s.erase(sum - array[i]);
//
//			}
//		}
//		sort(res.begin(), res.end());
//		return res;
//	}
//};
//


class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		if (array.empty() || array.size() == 1) return {};
		int left = 0, right = array.size() - 1;
		vector<int> res;
		while (left < right)
		{
			if (array[left] + array[right] == sum)
			{
				res = { array[left],array[right] };
				break;
			}
			else if (array[left] + array[right] < sum)
				++left;
			else --right;
		}
		return res;
	}
};

