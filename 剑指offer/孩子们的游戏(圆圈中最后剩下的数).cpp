#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<list>

using namespace std;

class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n <= 0 || m <= 0) return -1;
		if (n == 1) return n;
		vector<int> v;
		for (int i = 0; i < n; ++i)
			v.push_back(i);
		int pos = 0;
		int rm = m - 1;
		while (v.size() > 1)
		{
			if (pos == v.size() - 1) { pos = 0; --rm; }
			else { ++pos; --rm; }

			if (rm == 0)
			{
				v.erase(pos + v.begin());
//? 这里需要注意 v.erase之后 v.size()减小 ，若之前 pos==v.size()-1  现在 可就 pos=v.size()
//? 若不修改则出错
				if (pos == v.size()) pos = 0; 
				 
				rm = m - 1;
			}
		}

		if (v.size() == 1)
			return v[0];
		else return -1;
	}

	int LastRemaining_Solution2(int n, int m)
	{
		if (n < 1 || m < 1)
			return -1;
		list<int> nums;
		for (int i = 0; i < n; ++i)
			nums.push_back(i);
		list<int>::iterator cur = nums.begin();
		while (nums.size() > 1)
		{
			for (int i = 1; i < m; ++i)
			{
				++cur;
				if (cur == nums.end())
					cur = nums.begin();
			}
			list<int>::iterator next = ++cur;
			if (next == nums.end())
			{
				next = nums.begin();
			}
			nums.erase(--cur);
			cur = next;
		}
		return *cur;

	}




};

int main()
{
	Solution a;
	int n = 10, m = 10;
	cout << a.LastRemaining_Solution(n, m) << endl;
	cout << a.LastRemaining_Solution2(n, m) << endl;
	return 0;
}