#include<vector>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		if (numbers.size() != 5) return false;
		int zero = 0;
		int bre = 0;
		sort(numbers.begin(), numbers.end());
		for (int i = 0; i < numbers.size()-1; ++i)
		{
			if (numbers[i] == 0) { ++zero; continue; }
			if (numbers[i] == numbers[i + 1]) return false;
			bre += numbers[i + 1] - numbers[i] - 1;
		}

		if (zero >= bre) return true;
		else return false;
	}
};
