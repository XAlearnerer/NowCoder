#include<vector>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;


//  ¡±abcXYZdef¡±->¡°XYZdefabc¡± ×óÒÆÈıÎ»

class Solution {
public:
	string LeftRotateString(string str, int n) {
		if (str.empty()) return str;
		int len = str.length();
		if (len == n)
			return str;
		if (len < n) n = n - len;
		string cur = str.substr(0, n);
		str.erase(0, n);
		return str + cur;
	}
};

