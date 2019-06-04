#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main_dulidexiaoyi()
{
	int x, f, d, p;
	cin >> x >> f >> d >> p;

	int res = 0;
	if (d - f*x >= 0)
	{
		res += f;
		d -= f*x;
	}
	else
	{
		cout << d / x << endl;
		return 0;
	}

	res += d / (p + x);
	cout << res << endl;

	return 0;
}
