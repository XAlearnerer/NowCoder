#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<unordered_map>
#include<map>

using namespace std;



class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		unordered_map<int, int> m;
		for (auto i : data)  ++m[i];
		bool flag = false;

		for (auto i = m.begin(); i != m.end(); ++i)
		{
			if (i->second == 1)
			{
				if (!flag)
				{
					*num1 = i->first;
					flag = true;
				}
				else
				{
					*num2 = i->first;
					break;
				}
			}
		}
	}
};











//我们还是从头到尾依次异或数组中的每一个数字，
//那么最终得到的结果就是两个只出现一次的数字的异或结果。
//因为其它数字都出现了两次，在异或中全部抵消掉了。
//由于这两个数字肯定不一样，那么这个异或结果肯定不为0 ，
//也就是说在这个结果数字的二进制表示中至少就有一位为1 。
//我们在结果数字中找到第一个为1 的位的位置，记为第N 位。
//现在我们以第N 位是不是1 为标准把原数组中的数字分成两个子数组，
//第一个子数组中每个数字的第N 位都为1 ，而第二个子数组的每个数字的第N 位都为0 。
//
//现在我们已经把原数组分成了两个子数组，
//每个子数组都包含一个只出现一次的数字，
//而其它数字都出现了两次。因此到此为止，所有的问题我们都已经解决。

