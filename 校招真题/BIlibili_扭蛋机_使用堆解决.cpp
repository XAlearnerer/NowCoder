#include<iostream>
#include<stack>

using namespace std;

int main_niudanji()
{
	int n;
	cin >> n;
	stack<int> t;
	while (n > 0)
	{
		t.push(n);
		n = (n - 1) / 2;
	}
	while (!t.empty())
	{
		int p = t.top();
		t.pop();
		if (p % 2 == 0) cout << 3;
		else cout << 2;
	}

	return 0;
}
