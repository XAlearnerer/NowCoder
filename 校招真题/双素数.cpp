#include<iostream>
#include<vector>
using namespace std;

const int NUM = 1000000;
int vis[NUM];
int prim[NUM];
int mark[NUM];

void primf()
{
	int num = 0;

	for (int i = 2; i < NUM; ++i)
	{
		if (vis[i] == 0)
		{
			prim[num] = i;
			mark[i] = 1;
			++num;
		}

		for (int j = 0; j < num; ++j)
		{
			if (prim[j] * i > NUM) break;
			vis[i*prim[j]] = 1;
			if (i%prim[j] == 0) break;
		}
	}

}

int rever(int a)
{
	int b = 0;
	while (a > 0)
	{
		int t = a % 10;
		a = a / 10;
		b = b * 10 + t;
	}
	return b;
}

//bool fin(int tes)
//{
//	for (int i = 0; i < NUM; ++i)
//	{
//		if (prim[i] == tes)
//		{
//			return true;
//		}
//	}
//	return false;
//}

int main_shuangsushu()
{
	int n;
	cin >> n;

	primf();
	vector<int> v;
	for (int cur = 0; cur < NUM; ++cur)
	{
		int pre = prim[cur];
		int rev = rever(pre);
		if (pre != rev && mark[rev]==1)
		{
			v.push_back(pre);
			if (v.size() == n) {
				cout << v.back() << endl;
				return 0;
			}
		}
	}

	cout << -1 << endl;

	return 0;
}





