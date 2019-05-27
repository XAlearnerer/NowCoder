#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		if (data.empty()) return 0;
		if (data.size() == 1)
		{
			if(data[0] == k) return 1;
			else return 0;
		}
		int left = 0, right = data.size() - 1;
		int mid = 0;
		bool flag = false;
		while (left < right)
		{
			mid = left + (right - left) / 2;
			if (data[mid] == k) { flag = true; break; }
			else if (data[mid] < k) left = mid + 1;
			else right = mid;
		}

		if (!flag) return 0;

		int res = 1;
		int mid2 = mid;
		while (mid >= 1 && data[--mid] == k) ++res;
		while (mid2 < data.size() - 1 && data[++mid2] == k) ++res;

		return res;
	}
};
