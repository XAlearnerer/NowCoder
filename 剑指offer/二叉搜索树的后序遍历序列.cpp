#include<iostream>
#include<vector>
using namespace std;

class Solution_worng {  ///// 内存超限:您的程序使用了超过限制的内存
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.empty()) return false;
		if (sequence.size() == 1) return true;
		return helper(sequence, 0, sequence.size() - 1);
	}

	bool helper(vector<int> sequence, int left, int right)
	{
		if (right == left) return true;
		int root = sequence.back();
		--right;
		int pos = left;
		for (pos; pos <= right; ++pos)
		{
			if (sequence[pos] > root) break;
		}
		for (int i = pos; i <= right; ++i)
		{
			if (sequence[i] < root) return false;
		}
		return helper(sequence, left, pos - 1) && helper(sequence, pos, right);
	}
};


class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.empty()) return false;
		if (sequence.size() == 1) return true;
		int len = sequence.size() - 1;
		int pos = 0;
		while (len > 0)
		{
			while (sequence[pos] < sequence[len]) ++pos;
			while (sequence[pos] > sequence[len]) ++pos;
			if (pos != len) return false;
			--len;
			pos = 0;
		}
		return true;
	}
};

