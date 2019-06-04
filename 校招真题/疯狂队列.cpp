#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>

using namespace std;

//int main()
//{
//	int n;
//	cin >> n;
//	if (n == 1)return 0;
//	vector<int> v(n, 9);
//	for (int i = 0; i < n; ++i)
//		cin >> v[i];
//	if (n == 2) return abs(v[0] - v[1]);
//
//	//vector<int> v = { 5 ,10 ,25 ,40, 25 };
//	//int n = 5;
//
//	sort(v.begin(), v.end());
//	vector<int> res(n + 1, 0);
//	int pos = n / 2;
//	res[pos] = v.back();
//	int i = pos - 1, j = pos + 1;
//	int t = 0;
//	while (i >= 0 && j < n && t < n - 1)
//	{
//		res[i] = v[t];
//		--i; ++t;
//		if (t <= 0) break;
//		res[j] = v[t];
//		++j; ++t;
//	}
//
//	if (t == 0)
//	{
//		if(abs(res[i]-))
//	}
//
//	int fin = 0;
//	for (int i = 0; i < n - 1; ++i)
//	{
//		fin += abs(res[i] - res[i + 1]);
//	}
//
//	cout << fin << endl;
//
//	return 0;
//}


//int main() {
//	int n;
//	while (cin >> n) {
//		vector<int> v(n, 0);
//		for (int i = 0; i < n; i++)
//		{
//			cin >> v[i];
//		}
//		if (n == 1)
//		{
//			cout << 0 << endl;
//		}
//		sort(v.begin(), v.end());
//
//		deque<int> d;
//		int l = 0, r = n - 1;
//		d.push_front(v[r]);
//		r--;
//
//		while (l <= r)
//		{
//			if (l <= r)
//			{
//				d.push_front(v[l++]);
//				if (l <= r)
//					d.push_back(v[l++]);
//			}
//			if (l <= r)
//			{
//				d.push_front(v[r--]);
//				if (l <= r)
//					d.push_back(v[r--]);
//			}
//		}
//
//		if (abs(d[n - 1] - d[n - 2]) < abs(d[n - 1] - d[0]))
//		{
//			d.push_front(d.back());
//			d.pop_back();
//		}
//
//		int res = 0;
//		for (int i = 1; i < n; i++)
//		{
//			res += abs(d[i] - d[i - 1]);
//		}
//		cout << res << endl;
//	}
//
//	return 0;
//}
//



int main_fengkuangduilie()
{
	int n;
	cin >> n;
	if (n == 1)return 0;
	vector<int> v(n, 9);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	if (n == 2) return abs(v[0] - v[1]);

	//vector<int> v = { 2,3,5,7,11,13,17,19};
	//int n = 8;

	sort(v.begin(), v.end());

	deque<int> d;
	d.push_back(v.back());
	int i = 0, j = n - 2;
	while (i < j)
	{
		if (i < j)
		{
			d.push_front(v[i]);
			++i;
			if (i < j)
			{
				d.push_back(v[i]);
				++i;
			}
		}

		if (i < j)
		{
			d.push_front(v[j]);
			--j;
			if (i < j)
			{
				d.push_back(v[j]);
				--j;
			}
		}
	}

	if (abs(d.front() - v[i]) > abs(d.back() - v[i]))
		d.push_front(v[i]);
	else
		d.push_back(v[i]);

	int res = 0;
	for (int i = 0; i < n - 1; i++)
	{
		res += abs(d[i] - d[i + 1]);
	}
	cout << res << endl;


	return 0;
}