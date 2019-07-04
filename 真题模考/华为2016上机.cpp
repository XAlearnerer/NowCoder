#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<set>
#include<string>
#include<map>

using namespace std;


int main_2016_01()
{
	int n, m;
	//cin>>n>>m;
	while (cin >> n >> m)
	{
		vector<int> v(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
		}
		for (int i = 0; i < m; ++i)
		{
			char c;
			int a, b;
			cin >> c >> a >> b;
			if (c == 'Q')
			{
				if (a > b) swap(a, b);  //?  看这里

				int x = v[a - 1];
				for (int j = a; j < b; ++j)
				{
					if (x < v[j]) x = v[j];
				}
				cout << x << endl;

				//cout<<*max_element(v.begin()+a-1,v.begin()+b)<<endl;

			}
			if (c == 'U') v[a - 1] = b;
		}
	}
	return 0;
}


int main_16_02_1()
{
	//unordered_map<string, int> m;
	//while (cin >> s)
	//{

/////////////////////////////////////////////////////////////////////////////////
							//? worng
	string s = "E:\V1R2\product\fpgadrive.c 1325";
	string p = "\\";   
	//? 反斜杠 的写法 ？？

	auto it = find_end(s.begin(), s.end(), p.begin(), p.end());  //?  报错
	string cur = s.substr(it - s.begin() + 1);
	cout << cur << endl;



/////////////////////////////////////////////////////////////////////////////////
							//? right
	string input = "E:\V1R2\product\fpgadrive.c 1325";
	unsigned int f = input.rfind('\\');
	string file = input.substr(f + 1);
	cout << file << endl;



		//++m[cur];
	//}

	/*for (auto i : m)
	{
		string cur = i.first;
		if (cur.size() > 16)
			cout << cur.substr(cur.size() - 16) << " ";
		else
			cout << cur << " ";
		cout << i.second << endl;

	}*/
	return 0;
}


int main_16_02_2()
{
	string s, row;
	map<pair<string, string>, int> m;    //?  不能使用 unorderedmap 的  场景 ？？？
	while (cin >> s >> row)
	{
		//string p="\\";
		//auto it=find_end(s.begin(),s.end(),p.begin(),p.end());
		//string cur=s.substr(it-s.begin()+1);
		int i = s.size() - 1;
		for (; i >= 0; --i)
		{
			if (s[i] == '\\') break;
		}
		string cur = s.substr(i + 1);
		++m[{cur, row}];
		cout << m.size() << " --> " << cur << " " << row << endl;
	}

	for (auto i : m)
	{
		string cur = i.first.first;
		if (cur.size() > 16)
			cout << cur.substr(cur.size() - 16) << " ";
		else
			cout << cur << " ";
		cout << i.first.second << " " << i.second << endl;

	}


	return 0;
}



