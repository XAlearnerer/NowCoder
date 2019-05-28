#include<vector>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

//“student.a am I” -> “I am a student.”

class Solution_2 { // 完全不知道为什么 无法通过
public:
	string ReverseSentence(string str) {
		if (str.empty()) return str;
		vector<string> v;
		int pos = 0;
		while (pos < str.size())
		{
			string cur;
			while ((str[pos] >= 'a' && str[pos] <= 'z')
				|| (str[pos] >= 'A' && str[pos] <= 'Z')
				) {
				cur += str[pos]; ++pos;
			}
			if (pos < str.size()) {
				if (str[pos] == ' ') ++pos;
				else { cur += str[pos]; pos += 2; }
			}
			v.push_back(cur);
		}
		reverse(v.begin(), v.end());
		string res;
		for (int i = 0; i < v.size(); ++i)
		{
			res += v[i];
			//if (i.back() < 'a' || i.back() > 'z') continue;
			//else res += ' ';
			if (i < v.size() - 1)
				res += ' ';
		}
		return res;
	}
};

class Solution {
public:
	string ReverseSentence(string str) {
		if (str.empty()) return str;
		int pos = 0;
		ReverseWord(str, 0, str.size() - 1);
		while (pos < str.size())
		{
			if (pos < str.size() && str[pos] == ' ')
				++pos;

			int left = pos, right = pos;
			while (pos < str.size() && str[pos] != ' ')
			{
				++pos; ++right;
			}
			ReverseWord(str, left, right - 1);
		}

		return str;
	}

	void ReverseWord(string &str, int s, int e)
	{
		while (s < e)
			swap(str[s++], str[e--]);
	}
};


//int main()
//{
//	Solution n;
//	cout << n.ReverseSentence("student. a am I") << "*" << endl;
//	cout << "I am a student.*" << endl;
//	return 0;
//}