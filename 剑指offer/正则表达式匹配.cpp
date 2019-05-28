#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
	bool match(char* str, char* pattern)
	{
		if (*pattern == '\0')
		{
			if (*str == '\0') return true;
			else return false;
		}
		if (*(pattern + 1) == '\0')
		{
			if ((*str != '\0') &&(*(str + 1) == '\0') && (*str == *pattern || *pattern == '.'))
				return true;
			else
				return false;
		}

		if (*(pattern + 1) != '*')
		{
			if (*str == '\0') return false;
			if ((*(pattern) == *(str)) || (*(pattern) == '.'))
				return match(str + 1, pattern + 1);
			else return false;
		}

		while (*str != '\0' && (*str == *pattern || *pattern == '.'))
		{
			if (match(str, pattern + 2)) return true;
			++str;
		}
		return match(str, pattern + 2);

	}
};

//int main()
//{
//	char* a = "";
//	char* b = ".";
//	Solution n;
//	cout << n.match(a, b) << endl;
//}
