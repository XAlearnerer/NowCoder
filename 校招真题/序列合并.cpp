
//1623

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int getfin(vector<int> v, int n)
{
	int res = 0, nq = 1;
	for (int i = 7; i >= 0; --i)
	{
		res = res + v[i] * nq;
		nq *= n;
	}
	return res;
}


int findmin(vector<vector<int> >& v, vector<int>& num)
{
	int m = getfin(v[0], num[0]);
	int mi = 0;
	for (int i = 1; i < num.size(); ++i)
	{
		if (getfin(v[i], num[i]) < m)
		{
			m = getfin(v[i], num[i]);
			mi = i;
		}
	}
	++num[mi];

	return m;
}

//? //////////////// ³¬Ê± //////////////////////////
int main_hebing()
{
	int k;
	cin >> k;
	vector<vector<int> > v;
	for (int i = 0; i < k; ++i)
	{
		vector<int> v1(8, 0);
		for (int i = 0; i < 8; ++i)
		{
			cin >> v1[i];
		}
		v.push_back(v1);
	}
	int n;
	cin >> n;

	vector<int> num(k, 1);
	//vector<int> res;
	int cur = 0;
	for (int i = 0; i < n; ++i)
	{
		cur = findmin(v, num);
		//res.push_back(cur);
	}
	cout << cur << endl;
	//cout<<res.back()<<endl;

	return 0;
}

//////////////////////////////////////////////////////////////////////////////


long long cal(vector<int>& v, int n)
{
	long long res = 0;

	for (int i = 0; i < 8; ++i)
	{
		res = res + (long long)v[i] * (long long)pow(n, i);
	}

	return res;
}

int main_xuliehebing()
{
	int k;
	cin >> k;
	vector<vector<int> > v;
	for (int i = 0; i < k; ++i)
	{
		vector<int> v1(8, 0);
		for (int i = 7; i >= 0; --i)
		{
			cin >> v1[i];
		}
		v.push_back(v1);
	}
	int n;
	cin >> n;


	priority_queue<long long> q;
	for (int i = 1; i <= n; ++i)
	{
		q.push(cal(v[0], i));
	}

	for (int i = 1; i < k; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			long long cur = cal(v[i], j);
			if (cur > q.top()) break;
			else
			{
				q.pop();
				q.push(cur);
			}
		}
	}

	cout << q.top() << endl;
	return 0;
}