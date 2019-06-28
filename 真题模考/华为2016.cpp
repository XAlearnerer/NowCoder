#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
#include<string>

using namespace std;


int main_01()
{
	int N, M;
	while (cin >> N >> M) {
		vector<int> stu(N);
		int a, b; char c;
		for (int i = 0; i<N; ++i)cin >> stu[i];
		for (int j = 0; j<M; ++j) {
			cin >> c >> a >> b;
			if (c == 'Q') {
				if (a>b)swap(a, b);
				cout << *max_element(stu.begin() + a - 1, stu.begin() + b) << endl;
			}
			if (c == 'U')stu[a - 1] = b;
		}
	}
	return 0;
}