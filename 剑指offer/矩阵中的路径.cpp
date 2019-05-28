
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (*str == '\0') return true;
		vector<vector<int> > v(rows, vector<int>(cols, 0));
		bool flag = false;
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				flag = helper(matrix, rows, cols, i, j, str, 0, v);
				if (flag) return true;
			}
		}
		return false;
	}

	bool helper(char* matrix, int rows, int cols, int i, int j, char* str, int pos,
		vector<vector<int>> v)
	{
		if (v[i][j] == 1) return false;
		v[i][j] = 1;
		if (*(matrix + i*cols + j) == *(str + pos))
		{
			if (*(str + pos + 1) == '\0') return true;
			else
			{
				if ((i > 0 && helper(matrix, rows, cols, i - 1, j, str, pos + 1, v))
					|| (i < rows - 1 && helper(matrix, rows, cols, i + 1, j, str, pos + 1, v))
					|| (j > 0 && helper(matrix, rows, cols, i, j - 1, str, pos + 1, v))
					|| (j < cols - 1 && helper(matrix, rows, cols, i, j + 1, str, pos + 1, v)))

					return true;
			}
		}
		v[i][j] = 0;
		return false;
	}
};

//
//int main()
//{
//	char* a = "abcesfcsadee";
//	char* s = "scee";
//	Solution n;
//	cout << n.hasPath(a, 3, 4, s) << endl;
//}
