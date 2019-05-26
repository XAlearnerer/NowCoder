#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;


class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		//如果不存在则输出0。
		/*sort(numbers.begin(), numbers.end());
		return numbers[numbers.size() / 2];*/

		unordered_map<int, int> m;
		for (auto i : numbers)
		{
			++m[i];
			if (m[i] > numbers.size() / 2) return i;
		}
		return 0;
	}
};