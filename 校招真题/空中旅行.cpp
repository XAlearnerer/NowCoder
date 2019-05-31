#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
	int flytime(vector<int> v,int s)
	{
		int res = 0; int pos = 0;
		while (pos < v.size())
		{
			if (v[pos] <= s)
			{
				++res;
				s -= v[pos];
			}
			else break;
			++pos;
		}
		return res;
	}

};
//
//int main()
//{
//	int n,s;
//	cin >> n >> s;
//	if (n <= 0) return 0;
//	vector<int> v(n);
//	for (int i = 0; i < n; ++i)
//		cin >> v[i];
//	Solution S;
//	cout << S.flytime(v, s) << endl;
//	return 0;
//
//}