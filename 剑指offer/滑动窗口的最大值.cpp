#include <iostream>
#include <vector>
#include<queue>

using namespace std;

class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int> res;
		deque<int> dq;

		for (int i = 0; i < num.size(); ++i)
		{
			if (!dq.empty() && dq.front() == i - size) dq.pop_front();
			while (!dq.empty() && num[i] > num[dq.back()]) dq.pop_back();
			dq.push_back(i);
			if (i >= size - 1) res.push_back(num[dq.front()]);
		}

		return res;
	}
};