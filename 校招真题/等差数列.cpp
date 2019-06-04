#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main_dengchashulie()
{
	int n;
	cin >> n;
	if (n == 0) cout << "Impossible" << endl;
	if (n == 1 || n == 2) cout << "Possible" << endl;
	vector<int> v(n, 0);
	for (int i = 0; i<n; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());
	int dif = v[0] - v[1];
	for (int i = 1; i<v.size() - 1; ++i)
	{
		if (v[i] - v[i + 1] != dif) { cout << "Impossible" << endl; return 0; }
	}

	cout << "Possible" << endl;
	return 0;
}