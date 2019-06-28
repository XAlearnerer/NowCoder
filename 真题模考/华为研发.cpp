#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
#include<string>

using namespace std;


int main_01()
{
	vector<int> v;
	int in = 0;
	while (cin >> in)
	{
		if (in == 0) break;
		else v.push_back(in);
	}

	for (int i = 0; i < v.size(); ++i)
	{
		int n = v[i];
		int res = 0, a = 0, b = 0;
		while (n > 0)
		{
			a = n / 3;
			b = n % 3;
			res += a;
			if (a <= 0) break;
			n = a + b;
		}
		n = a + b;
		if (n == 2) res += 1;
		cout << res << endl;
	}

	return 0;
}




int main_02()
{
	//int n = 0;
	//cin >> n;
	//set<int> v;
	//for (int i = 0; i < n; ++i)
	//{
	//	int a = 0;
	//	cin >> a;
	//	v.insert(a);
	//}
	//for (auto i : v) cout << i << endl;

	int n = 0;
	while (cin >> n)	//?   md 多组测试用例的意思。。。。。。。。。。。
	{
		set<int> v;
		for (int i = 0; i < n; ++i)
		{
			int a = 0;
			cin >> a;
			v.insert(a);
		}
		for (auto i : v) cout << i << endl;
	}


	return 0;
}




int main_03()
{
	string s;
	while (cin >> s)           //?   这个也是。。。。。。。。
	{
		string c = s.substr(2);
		reverse(c.begin(), c.end());
		long long res = 0;
		for (int i = 0; i < c.size(); ++i)
		{
			long long a = 1;
			for (int j = 0; j < i; ++j)
			{
				a *= 16;
			}
			int b = 0;
			if (c[i] >= 'A' && c[i] <= 'Z') b = c[i] - 'A' + 10;
			else b = c[i] - '0';
			res += a*b;
		}
		cout << to_string(res) << endl;
	}
	return 0;
}