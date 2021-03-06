#include <iostream>
#include <vector>

using namespace std;

class Solution2 {
public:
	int InversePairs(vector<int> data) {
		if (data.empty()) return 0;
		vector<int> copy(data.begin(), data.end());
		long long res = helper(data, copy, 0, data.size() - 1);
		return res % 1000000007;
	}

	long long helper(vector<int>& data, vector<int>& copy, int low, int high)
	{
		if (low == high) { copy[low] = data[low]; return 0; }
		int mid = (high - low) / 2;
		long long left = helper(copy, data, low, low + mid);
		long long right = helper(copy, data, low + mid + 1, high);
		int i = low + mid, j = high;
		int pos = high;
		long long res = 0;

		while (i >= low && j >= (low + mid + 1))
		{
			if (data[i] > data[j])
			{
				res += j - (low + mid);
				copy[pos] = data[i];
				--pos; --i;
			}
			else
			{
				copy[pos] = data[j];
				--pos; --j;
			}
		}

		while (i >= low)
		{
			copy[pos] = data[i];
			--pos; --i;
		}

		while (j >= low + mid + 1)
		{
			copy[pos] = data[j];
			--pos; --j;
		}


		return left + right + res;
	}
};


//int main()
//{
//	vector<int> v = { 1,2,3,4,5,6,7,0 };
//	Solution n;
//	cout << n.InversePairs(v) << endl;
//	return 0;
//}



class Solution {
public:
	int InversePairs(vector<int> data) {
		if (data.empty()) return 0;
		int res = 0;
		helper(data, 0, data.size() - 1, res);
		return res;
	}

	void helper(vector<int>& data, int l, int r, int& res)
	{
		if (l == r) return;
		int m = l + (r - l) / 2;
		helper(data, l, m, res);
		helper(data, m + 1, r, res);
		merge(data, l, m, r, res);

	}

	void merge(vector<int>& data, int l, int m, int r, int& res)
	{
		vector<int> tmp(r - l + 1, 0);
		int k = 0;
		int i = l, j = m + 1;
		while (i <= m && j <= r)
		{
			if (data[i] < data[j]) {
				tmp[k] = data[i];
				++i; ++k;
			}
			else {
				res += m - i + 1;
				tmp[k] = data[j];
				++j; ++k;
			}
		}

		while (i <= m)
		{
			tmp[k] = data[i];
			++i; ++k;
		}
		while (j <= r)
		{
			tmp[k] = data[j];
			++j; ++k;
		}
		for (int p = 0; p < tmp.size(); ++p)
		{
			data[p + l] = tmp[p];
		}
	}

};

