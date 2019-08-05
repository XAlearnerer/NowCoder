#include <iostream>
#include <vector>

using namespace std;

class Solution2 {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		vector<vector<int>> v(rows, vector<int>(cols, 0));
		int res = 0;
		helper(threshold, rows, cols, 0, 0, v, res);
		return res;
	}

	void helper(int threshold, int rows, int cols, int i, int j, vector<vector<int>>& v, int& res)
	{
		if (v[i][j] == 1) return;
		v[i][j] = 1;
		if (numberS(i) + numberS(j) > threshold) return;
		else
		{
			cout << i << " " << j << " " << res << endl;
			++res;
			if (i > 0) helper(threshold, rows, cols, i - 1, j, v, res);
			if (i < rows - 1) helper(threshold, rows, cols, i + 1, j, v, res);
			if (j > 0) helper(threshold, rows, cols, i, j - 1, v, res);
			if (j < cols - 1)helper(threshold, rows, cols, i, j + 1, v, res);
		}
		//v[i][j] = 0;
	}

	int numberS(int a)
	{
		int usm = 0;
		while (a > 0)
		{
			usm += a % 10;
			a /= 10;
		}
		return usm;
	}
};

class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		if (rows == 0 || cols == 0) return 0;
		vector<vector<int>> vis(rows, vector<int>(cols, 0));
		int res = 0;
		helper(threshold, rows, cols, res, 0, 0, vis);
		return res;
	}

	void helper(int threshold, int rows, int cols, int& res, int i, int j,
		vector<vector<int>>& vis)
	{
		if (i<0 || j<0 || i >= rows || j >= cols || vis[i][j] == 1) return;
		vis[i][j] = 1;
		if (check(i, j)<=threshold)
		{
			++res;
			helper(threshold, rows, cols, res, i + 1, j, vis);
			helper(threshold, rows, cols, res, i - 1, j, vis);
			helper(threshold, rows, cols, res, i, j + 1, vis);
			helper(threshold, rows, cols, res, i, j - 1, vis);
		}
		//vis[i][j] = 0;

	}

	int check(int i, int j)
	{
		int res = 0;
		while (i != 0)
		{
			res += i % 10;
			i /= 10;
		}
		while (j != 0)
		{
			res += j % 10;
			j /= 10;
		}
		return res;
	}

};

