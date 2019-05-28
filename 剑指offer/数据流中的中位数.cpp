#include <iostream>
#include <vector>
#include<queue>
#include<set>

using namespace std;

class Solution {
public:
	void Insert(int num)
	{
		if (small.size() <= large.size())
		{
			if (large.empty() || num <= *large.begin())
			{
				small.insert(num);
			}
			else
			{
				small.insert(*large.begin());
				large.erase(large.begin());
				large.insert(num);
			}
		}
		else
		{
			if (num >= *small.rbegin()) large.insert(num);
			else
			{
				large.insert(*small.rbegin());
				small.erase(--small.end());
				small.insert(num);
			}
		}
	}

	double GetMedian()
	{
		if ((large.size() + small.size()) % 2 == 1)
		{
			return *small.rbegin();
		}
		else
			return ((double)*small.rbegin() + *large.begin()) / 2;
	}

	multiset<int> large, small;
};











