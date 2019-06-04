#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main_jiaocuo01chuan()
{
	string s;
	cin >> s;
	int res = 1;
	for (int i = 0; i<s.size(); ++i)
	{
		int cur = 1;
		int j = i;
		while (i<s.size() - 1 && ((s[i] == '0'&&s[i + 1] == '1') || (s[i] == '1'&& s[i + 1] == '0')))
		{
			++i;
		}
		cur = i - j + 1;
		res = max(res, cur);
	}
	cout << res << endl;

	return 0;
}