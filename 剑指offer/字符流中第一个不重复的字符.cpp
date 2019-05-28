#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_map>
#include<queue>

using namespace std;


class Solution
{
public:
	//Insert one char from stringstream
	void Insert(char ch)
	{
		++m[ch];
		if (m[ch] == 1) q.push_back(ch);
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		while (!q.empty() && m[q.front()] >= 2) q.pop_front();
		if (q.empty()) return '#';
		return q.front();

	}
	unordered_map<char, int> m;
	deque<char> q;

};