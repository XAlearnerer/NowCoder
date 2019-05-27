#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int Sum_Solution(int n) {
		int res = 0;
		n > 0 && (res = (n + Sum_Solution(n - 1)));
		return res;
	}

};
