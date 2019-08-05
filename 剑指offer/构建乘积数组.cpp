#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution2 {
public:
	vector<int> multiply(const vector<int>& A) {
		if (A.empty()) return {};
		int len = A.size();
		if (len == 1) return {};
		vector<int> m1, m2;
		m1.push_back(A[0]);
		m2.push_back(A[len - 1]);
		for (int i = 1; i < len; ++i)
		{
			m1.push_back(m1.back()*A[i]);
		}
		for (int i = len - 2; i >= 0; --i)
		{
			m2.push_back(m2.back()*A[i]);
		}
		reverse(m2.begin(), m2.end());
		vector<int> res(len, 1);
		for (int i = 0; i < len; ++i)
		{
			if (i == 0) res[i] = m2[i + 1];
			else if (i == len - 1) res[i] = m1[i - 1];
			else
			{
				res[i] = m1[i - 1] * m2[i + 1];
			}
		}
		return res;
	}
};


class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		if (A.empty()) return {};
		int len = A.size();
		vector<int> l(len, 1), r(len, 1);
		for (int i = 1; i < len; ++i)
		{
			l[i] = l[i - 1] * A[i - 1];
		}
		for (int i = len - 2; i >= 0; --i)
		{
			r[i] = r[i + 1] * A[i + 1];
		}
		vector<int> res;
		for (int i = 0; i < len; ++i)
			res.push_back(l[i] * r[i]);

		return res;
	}
};
