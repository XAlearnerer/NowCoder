#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		vector<int> v(10, 0);
		int count = 0;
		for (int i = 0; i < length; ++i)
		{
			++v[numbers[i]];
			if (v[numbers[i]] > 1) {
				duplication[count] = numbers[i];
				return true;
			}
		}
		return false;
	}
};