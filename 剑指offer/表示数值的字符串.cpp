#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>

using namespace std;

class Solution {
public:
	bool isNumeric(char* string)
	{
		bool sym = false, dot = false, e = false;
		for (int i = 0; i < strlen(string); ++i)
		{
			if (string[i] == '+' || string[i] == '-')
			{
				if (!sym && (i != 0 && string[i - 1] != 'e' && string[i - 1] != 'E'))  return false;
				if (sym && i > 0 && string[i - 1] != 'e' && string[i - 1] != 'E') return false;
				sym = true;
			}
			else if (string[i] == '.')
			{
				if (e || dot) return false;
				dot = true;
			}
			else if (string[i] == 'e' || string[i] == 'E')
			{
				if (i == 0) return false;
				if (i == strlen(string) - 1) return false;
				if (e) return false;
				e = true;
			}
			else
			{
				if (string[i] > '9' || string[i] < '0') return false;
			}
		}
		return true;

	}

};












